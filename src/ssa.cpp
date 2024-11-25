#include "ssa.h"
#include <cassert>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "bg_llvm.h"
#include "graph.hpp"
#include "liveness.h"
#include "printLLVM.h"

using namespace std;
using namespace LLVMIR;
using namespace GRAPH;
struct imm_Dominator
{                                           // 表示一个基本块（L_block）
    LLVMIR::L_block *pred;                  // 支配该块的前驱块
    unordered_set<LLVMIR::L_block *> succs; // 该块的后继块
};
// 存储每个基本块的支配集
unordered_map<L_block *, unordered_set<L_block *>> dominators;
// 存储每个基本块的支配树信息
unordered_map<L_block *, imm_Dominator> tree_dominators;
// 存储每个基本块的DF
unordered_map<L_block *, unordered_set<L_block *>> DF_array;
// 存储控制流图的逆图
unordered_map<L_block *, Node<LLVMIR::L_block *> *> revers_graph;
// 存储临时变量与目标架构操作数的映射
unordered_map<Temp_temp *, AS_operand *> temp2ASoper;

/*
初始化
*/
static void init_table()
{
    dominators.clear();
    tree_dominators.clear();
    DF_array.clear();
    revers_graph.clear();
    temp2ASoper.clear();
}

/*

*/
LLVMIR::L_prog *SSA(LLVMIR::L_prog *prog)
{
    for (auto &fun : prog->funcs)
    {
        init_table();
        combine_addr(fun);
        mem2reg(fun);
        auto RA_bg = Create_bg(fun->blocks);
        // printL_block(cout,RA_bg.mynodes[0]->info);
        //删除不可达代码 todo
        SingleSourceGraph(RA_bg.mynodes[0], RA_bg, fun);
        //活动性分析
        Liveness(RA_bg.mynodes[0], RA_bg, fun->args);
        //计算每个节点的必经节点
        Dominators(RA_bg);
        // printf_domi();
        //计算必经节点树
        tree_Dominators(RA_bg);
        // printf_D_tree();
        // 默认0是入口block
        //计算支配边界
        computeDF(RA_bg, RA_bg.mynodes[0]);
        // Show_graph(stdout,RA_bg);
        // printf_DF();
        //插Phi
        Place_phi_fu(RA_bg, fun);
        //变量重命名
        Rename(RA_bg);
        //
        combine_addr(fun);
    }
    return prog;
}

static bool is_mem_variable(L_stm *stm)
{
    return stm->type == L_StmKind::T_ALLOCA && stm->u.ALLOCA->dst->kind == OperandKind::TEMP && stm->u.ALLOCA->dst->u.TEMP->type == TempType::INT_PTR && stm->u.ALLOCA->dst->u.TEMP->len == 0;
}

// 保证相同的AS_operand,地址一样 。常量除外
// 合并相同的地址操作数。这样做是为了优化指令并减少内存的使用。
void combine_addr(LLVMIR::L_func *fun)
{
    unordered_map<Temp_temp *, unordered_set<AS_operand **>> temp_set;
    unordered_map<Name_name *, unordered_set<AS_operand **>> name_set;
    for (auto &block : fun->blocks)
    {
        for (auto &stm : block->instrs)
        {
            auto AS_operand_list = get_all_AS_operand(stm);
            for (auto AS_op : AS_operand_list)
            {
                if ((*AS_op)->kind == OperandKind::TEMP)
                {
                    temp_set[(*AS_op)->u.TEMP].insert(AS_op);
                }
                else if ((*AS_op)->kind == OperandKind::NAME)
                {
                    name_set[(*AS_op)->u.NAME].insert(AS_op);
                }
            }
        }
    }
    for (auto temp : temp_set)
    {
        AS_operand *fi_AS_op = **temp.second.begin();
        for (auto AS_op : temp.second)
        {
            *AS_op = fi_AS_op;
        }
    }
    for (auto name : name_set)
    {
        AS_operand *fi_AS_op = **name.second.begin();
        for (auto AS_op : name.second)
        {
            *AS_op = fi_AS_op;
        }
    }
}

/*
首先，我们要找到所有分配在栈上的标量 ，通过判断alloca + len==0 判断。
然后删除该指针所关联的 alloca ，store ，load 指令，并记录向该地址存取的标量。
最后将所有的标量名字替换成一个
*/
void mem2reg(LLVMIR::L_func *fun)
{
    // for (auto block : fun->blocks)
    // {
    //     auto it = block->instrs.begin();
    //     while(it != block->instrs.end())
    //     {
    //         L_stm *stm = *it;
    //         if (stm->type == L_StmKind::T_ALLOCA)
    //         {
    //             if (is_mem_variable(stm))
    //             {
    //                 AS_operand *new_oper = AS_Operand_Temp(Temp_newtemp_int());
    //                 temp2ASoper[stm->u.ALLOCA->dst->u.TEMP] = new_oper;
    //                 *it = L_Move(AS_Operand_Const(0), new_oper);
    //             }
    //         }
    //         else if (stm->type == L_StmKind::T_STORE)
    //         {
    //             AS_operand *ptr = stm->u.STORE->ptr;
    //             AS_operand *src = stm->u.STORE->src;

    //             if (src->kind == OperandKind::TEMP &&
    //                 src->u.TEMP->type == TempType::INT_TEMP &&
    //                 temp2ASoper.find(src->u.TEMP) != temp2ASoper.end())
    //             {
    //                 src = temp2ASoper[src->u.TEMP]; // 将src指向寄存器
    //                 stm->u.STORE->src = src;
    //             }

    //             if (ptr->kind == OperandKind::TEMP &&
    //                 ptr->u.TEMP->type == TempType::INT_PTR &&
    //                 ptr->u.TEMP->len == 0 &&
    //                 temp2ASoper.find(ptr->u.TEMP) != temp2ASoper.end())
    //             {
    //                 // 找到对应ptr寄存器
    //                 *it = L_Move(src, temp2ASoper[ptr->u.TEMP]);
    //                 // 直接将src移到寄存器
    //             }
    //             // 找不到对应ptr寄存器，保留store
    //         }
    //         else if (stm->type == L_StmKind::T_LOAD)
    //         {
    //             AS_operand *dst = stm->u.LOAD->dst;
    //             AS_operand *ptr = stm->u.LOAD->ptr;
                
    //             if (ptr->kind == OperandKind::TEMP &&
    //                 (temp2ASoper.find(ptr->u.TEMP) != temp2ASoper.end())) //如果ptr有对应寄存器
    //             {
    //                 if (dst->kind == OperandKind::TEMP)
    //                 {
    //                     temp2ASoper[dst->u.TEMP] = temp2ASoper[ptr->u.TEMP];
    //                     it = block->instrs.erase(it);
    //                     continue;
    //                 }
    //             }
    //         }
    //         else
    //         {   
    //             list<AS_operand **> as_list = get_all_AS_operand(stm);
    //             for (auto as : as_list)
    //             {
    //                 AS_operand *oper = *as;
    //                 if (oper->kind == OperandKind::TEMP && 
    //                 oper->u.TEMP->type == TempType::INT_TEMP && 
    //                 temp2ASoper.find(oper->u.TEMP)!=temp2ASoper.end())
    //                 {
    //                     *as =temp2ASoper[oper->u.TEMP];
    //                 }
    //             }

    //         }
    //         ++it;
    //     }
    // }
     // 将alloca语句转换为move
    for(auto block : fun->blocks){
        for(auto it = block->instrs.begin(); it!=block->instrs.end(); it++){
            L_stm* stm = *it;
            if(is_mem_variable(stm)){
                Temp_temp *new_temp = Temp_newtemp_int();
                AS_operand *new_oper = AS_Operand_Temp(new_temp);

                // 将旧的temp映射到新的temp
                temp2ASoper[stm->u.ALLOCA->dst->u.TEMP] = new_oper;
                
                // 默认值为0
                *it = L_Move(AS_Operand_Const(0), new_oper);
            }
        }
    }

    // 记录将栈上的标量load到的寄存器，然后在普通语句中进行替换
    unordered_map<Temp_temp*, AS_operand*> loadTemp2ASOper;

    for(auto block : fun->blocks){
        for(auto it = block->instrs.begin(); it!=block->instrs.end(); ){
            L_stm* stm = *it;
            switch(stm->type){
                case L_StmKind::T_STORE:{
                    AS_operand* ptr = stm->u.STORE->ptr;
                    AS_operand* src = stm->u.STORE->src;
                    if(src->kind==OperandKind::TEMP && src->u.TEMP->type==TempType::INT_TEMP && loadTemp2ASOper.find(src->u.TEMP)!=loadTemp2ASOper.end()){
                        src = loadTemp2ASOper[src->u.TEMP];
                        stm->u.STORE->src = src;
                    }
                    if(ptr->kind==OperandKind::TEMP && ptr->u.TEMP->type==TempType::INT_PTR && ptr->u.TEMP->len==0 && temp2ASoper.find(ptr->u.TEMP) != temp2ASoper.end()){
                        *it = L_Move(src, temp2ASoper[ptr->u.TEMP]);
                    }
                    break;
                }
                case L_StmKind::T_LOAD:{
                    AS_operand* dst = stm->u.LOAD->dst;
                    AS_operand* ptr = stm->u.LOAD->ptr;
                    if(ptr->kind==OperandKind::TEMP && ptr->u.TEMP->type==TempType::INT_PTR && ptr->u.TEMP->len==0 && (temp2ASoper.find(ptr->u.TEMP)!=temp2ASoper.end())){
                        if(dst->kind==OperandKind::TEMP){
                            loadTemp2ASOper[dst->u.TEMP] = temp2ASoper[ptr->u.TEMP];
                            auto old_it = it;
                            it++;
                            block->instrs.erase(old_it);
                            continue;
                        }
                        else{
                            assert(0);
                        }
                    }
                    break;
                }
                default:{
                    list<AS_operand**> as_list = get_all_AS_operand(stm);
                    for(auto as : as_list){
                        AS_operand *oper = *as;
                        if(oper->kind==OperandKind::TEMP && oper->u.TEMP->type==TempType::INT_TEMP && loadTemp2ASOper.find(oper->u.TEMP)!=loadTemp2ASOper.end()){
                            *as = loadTemp2ASOper[oper->u.TEMP];
                        }
                    }
                    break;
                }
            }

            it++;
        }
    }

}

/**
 * @note 计算支配节点
*/
void Dominators(GRAPH::Graph<LLVMIR::L_block *> &bg)
{
    unordered_set<L_block*> blocks = unordered_set<L_block*>();

    // 统计所有的block
    map<int, Node<L_block*>*> &nodes = bg.mynodes;
    for(auto pair:nodes){
        Node<L_block*>* node = pair.second;
        if(node==nullptr || node->nodeInfo()==nullptr){
            assert(0);
        }
        blocks.emplace(node->nodeInfo());
    }

    // 初始化
    //对于非根节点：将其支配集合初始设置为所有基本块，即 blocks
    for(auto pair : nodes){
        Node<L_block*>* node = pair.second;
        dominators[node->nodeInfo()] = unordered_set<L_block*>(blocks.begin(), blocks.end());
    }
    //对于根节点（入口节点 nodes[0]）：支配集合仅包含自身
    unordered_set<L_block*> root_block_dominators = unordered_set<L_block*>();
    root_block_dominators.emplace(nodes[0]->nodeInfo());
    dominators[nodes[0]->nodeInfo()] = root_block_dominators;

    // 迭代
    bool changed = true;
    while(changed){
        changed = false;
        for(auto pair : nodes){
            Node<L_block*>* node = pair.second;
            unordered_set<L_block*> node_dominators = dominators[node->nodeInfo()];
            int origin_size = node_dominators.size();
            NodeSet* preds = node->pred();

            for(auto pred_id:*preds){
                Node<L_block*>* pred = bg.mynodes[pred_id];
                if(origin_size>0){
                    node_dominators = make_intersection(node_dominators, dominators[pred->nodeInfo()]);
                }
            }   
            // 更新
            if(node_dominators.size()!=origin_size){
                changed = true;
                dominators[node->nodeInfo()] = node_dominators;
            }
        }
    }
}

void printf_domi()
{
    printf("Dominator:\n");
    for (auto x : dominators)
    {
        printf("Dom(%s)={", x.first->label->name.c_str());
        for (auto t : x.second)
        {
            printf("%s , ", t->label->name.c_str());
        }
        if (x.second.size() >= 1)
        {
            printf("\b\b");
        }
        printf("}\n");
    }
}

void printf_D_tree()
{
    printf("dominator tree:\n");
    for (auto x : tree_dominators)
    {
        printf("%s ", x.first->label->name.c_str());
        for (auto t : x.second.succs)
        {
            printf("%s ", t->label->name.c_str());
        }
        printf("}\n\n");
    }
}

void printf_DF()
{
    printf("DF:\n");
    for (auto x : DF_array)
    {
        printf("DF(%s)={", x.first->label->name.c_str());
        for (auto t : x.second)
        {
            printf("%s , ", t->label->name.c_str());
        }
        if (x.second.size() >= 1)
        {
            printf("\b\b");
        }
        printf("}\n");
    }
}

void tree_Dominators(GRAPH::Graph<LLVMIR::L_block *> &bg)
{
    //   Todo
     for(auto pair:dominators){
        L_block* block = pair.first;
        unordered_set<L_block*> block_dominators = pair.second;
        for(L_block* dominator:block_dominators){
            if(dominator==block){
                continue;
            }
            // 判断是否是其他必经节点的必经节点
            bool isIdom = true;
            for(L_block* other_dominator:block_dominators){
                if(other_dominator==block || other_dominator==dominator){
                    continue;
                }
                //如果找到了，说明不是idom，下一个
                if(dominators[other_dominator].find(dominator)!=dominators[other_dominator].end()){
                    isIdom = false;
                    break;
                }
            }
            if(isIdom){
                // 其实就是一颗树中的节点
                imm_Dominator idom = imm_Dominator();
                idom.pred = dominator;
                tree_dominators[block] = idom;
            }
        }
    }

    // 加入root，设置pred为nullptr
    imm_Dominator root_idom = imm_Dominator();
    root_idom.pred = nullptr;
    tree_dominators[bg.mynodes[0]->nodeInfo()] = root_idom;

    // 写入succ,完成树的创建
    for(auto pair:tree_dominators){
        L_block* block = pair.first;
        imm_Dominator idom = tree_dominators[block];
        
        if(idom.pred!=nullptr){
            tree_dominators[idom.pred].succs.emplace(block);
        }
    }
}

void computeDF(GRAPH::Graph<LLVMIR::L_block *> &bg, GRAPH::Node<LLVMIR::L_block *> *r)
{
    //   Todo
    unordered_set<L_block*> s= unordered_set<L_block*>();

    for(int succ_id:*r->succ()){
        Node<L_block*>* node = bg.mynodes[succ_id];
        imm_Dominator idom = tree_dominators[node->nodeInfo()];
        if(idom.pred != r->nodeInfo()){
            s.emplace(node->nodeInfo());
        }
    }

    imm_Dominator idom = tree_dominators[r->nodeInfo()];
    for(L_block* succ:idom.succs){
        int succ_id = bg.findNode(succ);
        if(succ_id==-1){
            assert(0);
        }
        computeDF(bg, bg.mynodes[succ_id]);

        unordered_set<L_block*> c_df_array = DF_array[succ];
        for(L_block* c_df:c_df_array){
            if(dominators[c_df].find(r->nodeInfo())==dominators[c_df].end() || r->nodeInfo()==c_df){
                s.emplace(c_df);
            }
        }
    }

    DF_array[r->nodeInfo()] = s;
}

// 只对标量做
void Place_phi_fu(GRAPH::Graph<LLVMIR::L_block *> &bg, L_func *fun)
{
     // 创建block -> index的映射
    unordered_map<L_block*, int> block2index;
    for (int i = 0; i < bg.nodecount; i++){
        // if (!bg.mynodes[i]){
        //     continue;
        // }
        block2index[bg.mynodes[i]->info] = i;
    }
    
    //step 1
    unordered_map<Temp_temp*, unordered_set<L_block*>> def_sites;
    for (int i = 0; i < bg.nodecount; i++){
        if (!bg.mynodes[i]){
            continue;
        }
        unordered_set<L_block*> def_site;
        for(auto& def_a: FG_def(bg.mynodes[i])){
            if (def_sites.find(def_a) == def_sites.end()){
                def_sites[def_a] = def_site;
            }
            if (def_sites[def_a].find(bg.mynodes[i]->info) == def_site.end()){
                def_sites[def_a].emplace(bg.mynodes[i]->info);
            }
        }
    }


    for (auto& temp_pair: def_sites){
        unordered_set<L_block*> w = temp_pair.second;
        //phi函数变量集合
        unordered_set<L_block*> f;
        while (!w.empty()){
            //从w删除某个节点n
            L_block* x = *w.begin();
            w.erase(x);
            unordered_set<L_block*> df_x = DF_array[x];
            
            for(auto& y: df_x){
                int node_index = block2index[y];
                TempSet_ y_in = FG_In(bg.mynodes[node_index]);
                if (f.find(y) == f.end() && y_in.find(temp_pair.first)!= y_in.end()){
                    // add phi
                    int y_index = block2index[y];
                    AS_operand* dst = AS_Operand_Temp(temp_pair.first);
                    std::vector<std::pair<AS_operand*,Temp_label*>> phis;
                    std::pair<AS_operand*,Temp_label*> new_phi_src;
                    
                    for(auto& pred: bg.mynodes[y_index]->preds){
                        new_phi_src = make_pair(dst, bg.mynodes[pred]->info->label);
                        phis.push_back(new_phi_src);
                    }
                    auto it = y->instrs.begin();
                    it++;
                    y->instrs.insert(it, L_Phi(dst, phis));

                    //f and w update
                    f.emplace(y);
                    if (w.find(y) == w.end()){
                        w.emplace(y);
                    }
                }
            }
        }
    }
    //std::cout<<"place phi finished"<<std::endl;
}

static list<AS_operand **> get_def_int_operand(LLVMIR::L_stm *stm)
{
    list<AS_operand **> ret1 = get_def_operand(stm), ret2;
    for (auto AS_op : ret1)
    {
        if ((**AS_op).u.TEMP->type == TempType::INT_TEMP)
        {
            ret2.push_back(AS_op);
        }
    }
    return ret2;
}

static list<AS_operand **> get_use_int_operand(LLVMIR::L_stm *stm)
{
    list<AS_operand **> ret1 = get_use_operand(stm), ret2;
    for (auto AS_op : ret1)
    {
        if ((**AS_op).u.TEMP->type == TempType::INT_TEMP)
        {
            ret2.push_back(AS_op);
        }
    }
    return ret2;
}

static void Rename_temp(GRAPH::Graph<LLVMIR::L_block *> &bg, GRAPH::Node<LLVMIR::L_block *> *n, unordered_map<Temp_temp *, stack<Temp_temp *>> &Stack)
{
    //   Todo
     for(L_stm* stm : n->nodeInfo()->instrs){
        if(stm->type!=L_StmKind::T_PHI){
            list<AS_operand**> used_operands = get_use_int_operand(stm);
            for(AS_operand** used_operand : used_operands){
                if(Stack.find((*used_operand)->u.TEMP)!=Stack.end()){
                    *used_operand = AS_Operand_Temp(Stack[(*used_operand)->u.TEMP].top());
                }
            }
        }

        list<AS_operand**> def_operands = get_def_int_operand(stm);
        for(AS_operand** def_operand : def_operands){
            if(Stack.find((*def_operand)->u.TEMP)!=Stack.end()){
                Temp_temp* new_temp = Temp_newtemp_int();
                Stack[(*def_operand)->u.TEMP].push(new_temp);
                *def_operand = AS_Operand_Temp(new_temp);
            }
        }
    }


    for(int succ_id : *n->succ()){
        Node<L_block*>* succ = bg.mynodes[succ_id];

        // 记录n是succ的第几个前驱
        int loc = 0;
        for(int pred_id:*succ->pred()){
            Node<L_block*>* pred = bg.mynodes[pred_id];
            if(n==pred)
                break;
            
            loc++;
        }

        for(L_stm* stm : succ->nodeInfo()->instrs){
            if(stm->type==L_StmKind::T_PHI){
                Temp_temp* old_temp = stm->u.PHI->phis[loc].first->u.TEMP;
                stm->u.PHI->phis[loc].first = AS_Operand_Temp(Stack[old_temp].top());
            }
        }
    }

    imm_Dominator idom = tree_dominators[n->nodeInfo()];
    for(L_block* succ:idom.succs){
        int node_id = bg.findNode(succ);
        Rename_temp(bg, bg.mynodes[node_id], Stack);
    }
}

void Rename(GRAPH::Graph<LLVMIR::L_block *> &bg)
{    // 初始化
    unordered_map<Temp_temp*, stack<Temp_temp*>> stack;
    for(auto pair:temp2ASoper){
        stack[pair.second->u.TEMP].push(pair.second->u.TEMP);
    }

    Rename_temp(bg, bg.mynodes[0], stack);
    //   Todo
}

template <typename T>
std::unordered_set<T> make_intersection(std::unordered_set<T> &tl1, std::unordered_set<T> &tl2)
{
    unordered_set<T> intersection = unordered_set<T>();
    for (auto &it : tl1)
    {
        if (tl2.find(it) != tl2.end())
        {
            intersection.emplace(it);
        }
    }
    return intersection;
}