#include "ssa.h"
#include <cassert>
#include <fstream>
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
{
    LLVMIR::L_block *pred;
    unordered_set<LLVMIR::L_block *> succs;
};

unordered_map<L_block *, unordered_set<L_block *>> dominators;
unordered_map<L_block *, imm_Dominator> tree_dominators;
unordered_map<L_block *, unordered_set<L_block *>> DF_array;
unordered_map<L_block *, Node<LLVMIR::L_block *> *> revers_graph;
unordered_map<Temp_temp *, AS_operand *> temp2ASoper;

static void init_table()
{
    dominators.clear();
    tree_dominators.clear();
    DF_array.clear();
    revers_graph.clear();
    temp2ASoper.clear();
}

LLVMIR::L_prog *SSA(LLVMIR::L_prog *prog)
{
    for (auto &fun : prog->funcs)
    {
        init_table();
        combine_addr(fun);
        //developFuncEntryBlock(fun);
        // mem2reg(fun);
        //  std::cout<<"mem2reg finish"<<std::endl;
        auto RA_bg = Create_bg(fun->blocks);
        SingleSourceGraph(RA_bg.mynodes[0], RA_bg, fun);
        Liveness(RA_bg.mynodes[0], RA_bg, fun->args);
        Dominators(RA_bg);
        // printf_domi();
        tree_Dominators(RA_bg);
        // printf_D_tree();
        // 默认0是入口block
        computeDF(RA_bg, RA_bg.mynodes[0]);
        // printf_DF();

        Place_phi_fu(RA_bg, fun);
        // std::cout<<"phi"<<std::endl;
        Rename(RA_bg);
        combine_addr(fun);
    }
    return prog;
}

static bool is_mem_variable(L_stm *stm)
{
    return stm->type == L_StmKind::T_ALLOCA && stm->u.ALLOCA->dst->kind == OperandKind::TEMP && stm->u.ALLOCA->dst->u.TEMP->type == TempType::INT_PTR && stm->u.ALLOCA->dst->u.TEMP->len == 0;
}

// 保证相同的AS_operand,地址一样 。常量除外
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

std::vector<L_stm *> allAllocaStms;
std::map<L_stm *, std::vector<L_block *>> allocDefs; // alloc -> list of defs
std::map<L_stm *, std::vector<L_block *>> allocUses; // alloc -> list of uses
// void developFuncEntryBlock(LLVMIR::L_func *fun)
// {
//     allAllocaStms.clear();
//     allocDefs.clear();
//     allocUses.clear();
//     auto entryBlock = fun->blocks.front();

//     for (auto block : fun->blocks)
//     {
//         list<L_stm *>::iterator it = block->instrs.begin();
//         while (it != block->instrs.end())
//         {
//             if (is_mem_variable(*it))
//             {
//                 allAllocaStms.push_back(*it);
//                 it = block->instrs.erase(it);
//             }
//             else
//             {
//                 ++it;
//             }
//         }
//     }
//     auto it = entryBlock->instrs.begin();
//     it++;

//     for (auto allocStm : allAllocaStms)
//     {
//         entryBlock->instrs.insert(it, allocStm); // 将 alloc 插入到入口块

//         // 查找所有使用 alloc 指令的指令
//         for (auto block : fun->blocks)
//         {
//             for (auto userIt = block->instrs.begin(); userIt != block->instrs.end(); ++userIt)
//             {
//                 auto alloc_temp = allocStm->u.ALLOCA->dst;

//                 auto operands = get_use_operand(*userIt);
//                 for (auto operand : operands)
//                 {
//                     if ((*operand)->kind == OperandKind::TEMP && (*operand)->u.TEMP == alloc_temp->u.TEMP)
//                     {
//                         allocUses[allocStm].push_back(block); // 记录使用 alloc 的指令
//                     }
//                 }

//                 auto operands = get_def_operand(*userIt);
//                 for (auto operand : operands)
//                 {
//                     if ((*operand)->kind == OperandKind::TEMP && (*operand)->u.TEMP == alloc_temp->u.TEMP)
//                     {
//                         allocDefs[allocStm].push_back(block); // 记录使用 alloc 的指令
//                     }
//                 }
//             }
//         }
//     }
// }

bool isAllocaPromotable(const L_stm *AI)
{
    // Only allow direct loads and stores...

    //   for (const User *U : AI->users()) {
    //     if (const LoadInst *LI = dyn_cast<LoadInst>(U)) {
    //       if (LI->getType() != AI->getAllocatedType())
    //         return false;
    //     } else if (const StoreInst *SI = dyn_cast<StoreInst>(U)) {
    //       if (SI->getValueOperand() == AI ||
    //           SI->getValueOperand()->getType() != AI->getAllocatedType())
    //         return false; // Don't allow a store OF the AI, only INTO the AI.
    //       // Note that atomic stores can be transformed; atomic semantics do
    //       // not have any meaning for a local alloca.
    //     }else {
    //       return false;
    //     }
    //   }

    return true;
}

void PromoteMem2RegRun(L_block *BB, std::vector<L_stm *> Allocas, DominatorTree &DT)
{
    for (int AllocaNum = 0; AllocaNum != Allocas.size(); ++AllocaNum)
    {
        // L_stm *AI = Allocas[AllocaNum];
        // if (allocUses.find(AI) != allocUses.end())
        // {
        //     if (allocUses[AI].empty())
        //         BB->instrs.remove(AI);
        //     // If there are no uses of the alloca, just delete it now.
        //     // Remove the alloca from the Allocas list, since it has been processed
        //     //    RemoveFromAllocasList(AllocaNum);
        //     continue;
        // }
    }
}

void PromoteMemToReg(L_block *BB, std::vector<L_stm *> Allocas, DominatorTree &DT)
{
    // If there is nothing to do, bail out...
    if (Allocas.empty())
        return;
    PromoteMem2RegRun(BB, Allocas, DT);
}

static bool promoteMemoryToRegister(LLVMIR::L_func *F, DominatorTree &DT)
{
    std::vector<L_stm *> Allocas;
    auto BB = F->blocks.front(); // Get the entry node for the function
    bool Changed = false;
    while (true)
    {
        Allocas.clear();
        // Find allocas that are safe to promote, by looking at all instructions in
        // the entry node
        list<L_stm *>::iterator it = BB->instrs.begin();
        while (it != BB->instrs.end())
        {
            if ((*it)->type == L_StmKind::T_ALLOCA) // Is it an alloca?
                if (isAllocaPromotable(*it))
                    Allocas.push_back(*it);
        }
        if (Allocas.empty())
            break;

        PromoteMemToReg(BB, Allocas, DT);
        Changed = true;
    }
    return Changed;
}

void mem2reg(LLVMIR::L_func *fun)
{
    for (auto x : fun->blocks)
    {
        for (auto &it : x->instrs)
        {
            if (is_mem_variable(it))
            {
                auto temp = AS_Operand_Temp(Temp_newtemp_int());
                temp2ASoper[(it)->u.ALLOCA->dst->u.TEMP] = temp;
                it = L_Move(AS_Operand_Const(0), temp);
            }
        }
    }
    unordered_map<Temp_temp *, AS_operand *> mem_scalar_load;

    for (auto x : fun->blocks)
    {
        list<L_stm *>::iterator it = x->instrs.begin();
        while (it != x->instrs.end())
        {
            switch ((*it)->type)
            {
            case L_StmKind::T_STORE:
            {
                AS_operand *res = nullptr;
                AS_operand *src = nullptr;
                auto store = (*it)->u.STORE;
                if (store->ptr->kind == OperandKind::TEMP && store->ptr->u.TEMP->type == TempType::INT_PTR && store->ptr->u.TEMP->len == 0)
                {
                    if (temp2ASoper.find(store->ptr->u.TEMP) != temp2ASoper.end())
                        res = temp2ASoper[store->ptr->u.TEMP];
                }
                if (store->src->kind == OperandKind::TEMP && store->src->u.TEMP->type == TempType::INT_TEMP)
                    src = mem_scalar_load[store->src->u.TEMP];
                if (res == nullptr)
                {
                    if (src != nullptr)
                    {
                        store->src = src;
                    }
                }
                else
                {
                    (*it) = L_Move(src == nullptr ? store->src : src, res);
                }
                break;
            }
            case L_StmKind::T_LOAD:
            {
                AS_operand *res = nullptr;
                AS_operand *src = nullptr;
                auto load = (*it)->u.LOAD;
                if (load->ptr->kind == OperandKind::TEMP && load->ptr->u.TEMP->type == TempType::INT_PTR && load->ptr->u.TEMP->len == 0)
                {
                    if (temp2ASoper.find(load->ptr->u.TEMP) != temp2ASoper.end())
                    {
                        mem_scalar_load[load->dst->u.TEMP] = temp2ASoper[load->ptr->u.TEMP];
                        it = x->instrs.erase(it);
                        continue;
                    }
                }
                break;
            }
            case L_StmKind::T_BINOP:
            case L_StmKind::T_CMP:
            case L_StmKind::T_MOVE:
            case L_StmKind::T_GEP:
            case L_StmKind::T_CALL:
            case L_StmKind::T_VOID_CALL:
            case L_StmKind::T_RETURN:
            default:
            {
                auto ass = get_all_AS_operand(*it);
                for (auto &as : ass)
                {
                    if ((*as)->kind == OperandKind::TEMP && (*as)->u.TEMP->type == TempType::INT_TEMP)
                    {
                        if (mem_scalar_load.find((*as)->u.TEMP) != mem_scalar_load.end())
                        {
                            *as = mem_scalar_load[(*as)->u.TEMP];
                        }
                    }
                }
                break;
            }
            break;
            }
            it++;
        }
    }
}

bool Set_eq(std::unordered_set<LLVMIR::L_block *> &a, std::unordered_set<LLVMIR::L_block *> &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    for (auto x : a)
    {
        if (b.find(x) == b.end())
        {
            return false;
        }
    }
    return true;
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

void Dominators(GRAPH::Graph<LLVMIR::L_block *> &bg)
{
    // 初始化
    // 对于根节点（入口节点 nodes[0]）：支配集合仅包含自身
    unordered_set<L_block *> dom_set;
    dom_set.emplace(bg.mynodes[0]->info);
    dominators[bg.mynodes[0]->info] = dom_set;
    // 对于非根节点：将其支配集合初始设置为所有基本块，即 blocks
    for (int i = 1; i < bg.nodecount; i++)
    {
        unordered_set<L_block *> dom_set = unordered_set<L_block *>();
        for (int j = 0; j < bg.nodecount; j++)
        {
            dom_set.emplace(bg.mynodes[j]->info);
        }
        dominators[bg.mynodes[i]->info] = dom_set;
    }

    bool change = true;
    while (change)
    {
        change = false;
        for (int i = 1; i < bg.nodecount; i++)
        {
            unordered_set<L_block *> dom_set = dominators[bg.mynodes[i]->info]; // 当前D[n]
            unordered_set<L_block *> pred_dom_intersection;                     // pred[n] D[p]交集
            bool first = true;
            unordered_set<L_block *> pred_dom_set;

            for (auto &pred_num : bg.mynodes[i]->preds)
            {

                pred_dom_set = dominators[bg.mynodes[pred_num]->info];
                if (first)
                {
                    for (auto &pre_dom : pred_dom_set)
                    {
                        pred_dom_intersection.emplace(pre_dom);
                    }
                    first = false;
                }
                else
                {
                    auto it = pred_dom_intersection.begin();
                    while (it != pred_dom_intersection.end())
                    {

                        if (pred_dom_set.find(*it) == pred_dom_set.end())
                        {
                            it = pred_dom_intersection.erase(it);
                        }
                        else
                            it++;
                    }
                }
            }
            pred_dom_intersection.emplace(bg.mynodes[i]->info);

            if (!Set_eq(dom_set, pred_dom_intersection))
            {
                change = true;
            }
            dominators[bg.mynodes[i]->info] = pred_dom_intersection;
        }
    }
}

void printf_domi()
{
    FILE *f = fopen("./tests/domi.txt", "w");
    fprintf(f, "Dominator:\n");
    for (auto x : dominators)
    {
        fprintf(f, "%s :\n", x.first->label->name.c_str());
        for (auto t : x.second)
        {
            fprintf(f, "%s ", t->label->name.c_str());
        }
        fprintf(f, "\n\n");
    }
    fclose(f);
}

void printf_D_tree()
{
    FILE *f = fopen("./tests/domi_tree.txt", "w");
    fprintf(f, "dominator tree:\n");
    for (auto x : tree_dominators)
    {
        fprintf(f, "%s :\n", x.first->label->name.c_str());
        for (auto t : x.second.succs)
        {
            fprintf(f, "%s ", t->label->name.c_str());
        }
        fprintf(f, "\n\n");
    }
    fclose(f);
}

void printf_DF()
{
    FILE *f = fopen("./tests/df.txt", "w");
    fprintf(f, "DF:\n");
    for (auto x : DF_array)
    {
        fprintf(f, "%s :\n", x.first->label->name.c_str());
        for (auto t : x.second)
        {
            fprintf(f, "%s ", t->label->name.c_str());
        }
        fprintf(f, "\n\n");
    }
    fclose(f);
}

void tree_Dominators(GRAPH::Graph<LLVMIR::L_block *> &bg)
{
    // 初始化
    for (int i = 0; i < bg.nodecount; i++)
    {
        imm_Dominator imm_origin;
        tree_dominators[bg.mynodes[i]->info] = imm_origin;
    }

    for (int i = 1; i < bg.nodecount; i++)
    {
        unordered_set<L_block *> doms = dominators[bg.mynodes[i]->info];
        L_block *nearest = bg.mynodes[i]->info;
        for (auto &dom : doms)
        {
            int flag = 0;
            if (dom == bg.mynodes[i]->info)
            {
                continue;
            }
            for (auto &other_dom : doms)
            {
                if (dom == other_dom || other_dom == bg.mynodes[i]->info)
                {
                    continue;
                }
                unordered_set<L_block *> other_dom_doms = dominators[other_dom];
                if (other_dom_doms.find(dom) != other_dom_doms.end())
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                continue;
            }
            else
            {
                nearest = dom;
                break;
            }
        }

        tree_dominators[bg.mynodes[i]->info].pred = nearest;
        tree_dominators[nearest].succs.emplace(bg.mynodes[i]->info);
    }
}

void computeDF(GRAPH::Graph<LLVMIR::L_block *> &bg, GRAPH::Node<LLVMIR::L_block *> *r)
{
    //   Todo
    unordered_set<L_block *> s;
    for (int succ_id : r->succs)
    {
        Node<L_block *> *y = bg.mynodes[succ_id];
        auto idom = tree_dominators[y->info].pred;
        if (idom != r->info)
            s.emplace(y->info);
    }

    for (L_block *succ : tree_dominators[r->info].succs)
    {
        int succ_id = bg.findNode(succ);
        computeDF(bg, bg.mynodes[succ_id]);

        unordered_set<L_block *> c_df_array = DF_array[succ];
        for (L_block *c_df : c_df_array)
        {
            if (dominators[c_df].find(r->info) == dominators[c_df].end() || r->info == c_df)
            {
                s.emplace(c_df);
            }
        }
    }

    DF_array[r->info] = s;
}

// 只对标量做
void Place_phi_fu(GRAPH::Graph<LLVMIR::L_block *> &bg, L_func *fun)
{
    // step 1
    unordered_map<Temp_temp *, unordered_set<L_block *>> def_sites;
    unordered_map<L_block *, unordered_set<Temp_temp *>> A_phi;
    for (int i = 0; i < bg.nodecount; i++)
    {
        unordered_set<L_block *> def_site;
        for (auto &def_a : FG_def(bg.mynodes[i]))
        {
            if (def_sites.find(def_a) == def_sites.end())
            {
                def_sites[def_a] = def_site;
            }
            if (def_sites[def_a].find(bg.mynodes[i]->info) == def_site.end())
            {
                def_sites[def_a].emplace(bg.mynodes[i]->info);
            }
        }
    }

    for (auto &pair : def_sites)
    {
        Temp_temp *a = pair.first;
        unordered_set<L_block *> w = pair.second;
        while (!w.empty())
        {
            L_block *n = *w.begin();
            unordered_set<L_block *> DF_n = DF_array[n];
            w.erase(n);
            for (auto &y : DF_n)
            {
                int y_index = bg.findNode(y);
                TempSet_ y_in = FG_In(bg.mynodes[y_index]);

                if (A_phi[y].find(a) == A_phi[y].end() && y_in.find(a) != y_in.end())
                {
                    AS_operand *dst = AS_Operand_Temp(a);
                    Node<L_block *> *y_node = bg.mynodes[y_index];
                    std::vector<std::pair<AS_operand *, Temp_label *>> phis;
                    for (auto &pred : y_node->preds)
                    {
                        phis.push_back(make_pair(dst, bg.mynodes[pred]->info->label));
                    }
                    auto it = y->instrs.begin();
                    it++;
                    y->instrs.insert(it, L_Phi(dst, phis));
                    A_phi[y].emplace(a);
                    auto A_orig_y = FG_def(y_node);
                    if (A_orig_y.find(a) == A_orig_y.end())
                    {
                        w.emplace(y);
                    }
                }
            }
        }
    }
    // std::cout<<"place phi finished"<<std::endl;
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
    // 处理前保留原def的temp
    unordered_map<Temp_temp *, int> origin_def_times;

    // 语句处理;
    for (auto &stm : n->info->instrs)
    {
        // 先处理非phi的use: 存在i = i+1 的情况
        if (stm->type != L_StmKind::T_PHI)
        {
            for (auto use_operand : get_use_int_operand(stm))
            {
                *use_operand = AS_Operand_Temp(Stack[(*use_operand)->u.TEMP].top());
            }
        }
        // 处理def
        for (auto def_operand : get_def_int_operand(stm))
        {
            Temp_temp *new_temp = Temp_newtemp_int();
            Stack[(*def_operand)->u.TEMP].push(new_temp);
            if (origin_def_times.find((*def_operand)->u.TEMP) == origin_def_times.end())
            {
                origin_def_times[(*def_operand)->u.TEMP] = 1;
            }
            else
            {
                origin_def_times[(*def_operand)->u.TEMP] += 1;
            }

            *def_operand = AS_Operand_Temp(new_temp);
        }
    }
    // 后继处理
    for (auto &succ : n->succs)
    {
        int j = 0;
        for (auto &pred : bg.mynodes[succ]->preds)
        {
            if (n->mykey == pred)
            {
                break;
            }
            j++;
        }
        for (auto &stm : bg.mynodes[succ]->info->instrs)
        {
            if (stm->type == L_StmKind::T_PHI)
            {
                if (stm->u.PHI->phis[j].second == n->info->label)
                {
                    stm->u.PHI->phis[j] = make_pair(AS_Operand_Temp(Stack[stm->u.PHI->phis[j].first->u.TEMP].top()), n->info->label);
                }
            }
        }
    }

    // 处理子节点
    for (auto &son : tree_dominators[n->info].succs)
    {
        int son_index = bg.findNode(son);
        Rename_temp(bg, bg.mynodes[son_index], Stack);
    }

    // pop出这个block压入的v
    for (auto temp_pair : origin_def_times)
    {
        for (int i = 0; i < temp_pair.second; i++)
        {
            Stack[temp_pair.first].pop();
        }
    }
}

void Rename(GRAPH::Graph<LLVMIR::L_block *> &bg)
{
    // 初始化set
    TempSet_ temp_list_def;
    TempSet_ temp_list_use;
    int count = 0;
    unordered_map<Temp_temp *, stack<Temp_temp *>> Stack;
    unordered_map<Temp_temp *, int> Count;

    for (int i = 0; i < bg.nodecount; i++)
    {
        if (!bg.mynodes[i])
        {
            continue;
        }
        temp_list_def = FG_def(bg.mynodes[i]);
        temp_list_use = FG_use(bg.mynodes[i]);
        for (auto &temp_def : temp_list_def)
        {
            if (Stack.find(temp_def) == Stack.end())
            {
                count = 0;
                Count[temp_def] = count;
                stack<Temp_temp *> stack_empty;
                stack_empty.emplace(temp_def);
                Stack[temp_def] = stack_empty;
            }
        }

        for (auto &temp_use : temp_list_use)
        {
            if (Stack.find(temp_use) == Stack.end())
            {
                count = 0;
                Count[temp_use] = count;
                stack<Temp_temp *> stack_empty;
                stack_empty.emplace(temp_use);
                Stack[temp_use] = stack_empty;
            }
        }
    }

    Rename_temp(bg, bg.mynodes[0], Stack);
}

void QueuePhiNode(GRAPH::Graph<LLVMIR::L_block *> &bg, L_block *block, Temp_temp *alloca)
{
    // 遍历基本块，更新 φ 节点操作数
    for (auto &stm : block->instrs)
    {
        if (stm->type == L_StmKind::T_PHI)
        {
            // 更新 φ 节点的前驱信息
            for (auto &phi : stm->u.PHI->phis)
            {
                if (phi.second == block->label)
                {
                    phi.first = AS_Operand_Temp(alloca); // 替换为新的 alloca 值
                }
            }
        }
    }
}

// void PromoteMemoryToRegister(LLVMIR::L_func *F, DominatorTree &DT, GRAPH::Graph<LLVMIR::L_block *> &bg)
// {
//     // Step 1: Initialize
//     std::unordered_map<L_stm *, L_stm *> newPhis;      // For storing new Phi nodes
//     std::unordered_map<L_block *, bool> block_visited; // To mark visited blocks

//     // Mark all blocks as unvisited
//     for (auto block : F->blocks)
//     {
//         block_visited[block] = false;
//     }

//     // Step 2: Process Alloca statements
//     for (auto &allocaStm : allAllocaStms)
//     {
//         // Reset visited status for each alloca
//         for (auto block : F->blocks)
//             block_visited[block] = false;

//         std::vector<L_block *> worklist1 = allocDefs[allocaStm]; // Worklist containing blocks that define the alloca

//         while (!worklist1.empty())
//         {
//             L_block *bb = worklist1.back();
//             worklist1.pop_back();

//             // Iterate over dominator frontiers
//             for (L_block *df : DF_array[bb])
//             {
//                 if (block_visited[df])
//                     continue; // Skip if already visited
//                 block_visited[df] = true;

//                 // Insert a new Phi node in df if needed
//                 int y_index = bg.findNode(df);
//                 AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());
//                 Node<L_block *> *y_node = bg.mynodes[y_index];
//                 std::vector<std::pair<AS_operand *, Temp_label *>> phis;
//                 for (auto &pred : y_node->preds)
//                 {
//                     phis.push_back(make_pair(dst, bg.mynodes[pred]->info->label));
//                 }

//                 // Insert the Phi node into the basic block
//                 auto it = df->instrs.begin();
//                 it++; // Ensure we insert after the first instruction
//                 L_stm* phi=L_Phi(dst, phis);
//                 df->instrs.insert(it,phi );
//                 newPhis[phi] = allocaStm; // Record the mapping of Phi node to alloca
//                 worklist1.push_back(df); // Add the frontier to the worklist
//             }
//         }
//     }

//     // Step 3: Rename variables in the SSA form
//     for (auto block : F->blocks)
//         block_visited[block] = false;

//     std::list<std::pair<L_block *, std::unordered_map<L_stm *, AS_operand *>>> worklist2;
//     worklist2.push_back({F->blocks.front(), {}}); // Initialize with entry block
//     unordered_map<Temp_temp *, AS_operand *> mem_scalar_load;
    
//     while (!worklist2.empty())
//     {
//         auto [bb, incomingVals] = worklist2.back();
//         worklist2.pop_back();

//         if (block_visited[bb])
//             continue; // Skip if already visited
//         block_visited[bb] = true;
        
//         // Process each instruction in the basic block
//         for (L_stm *inst : bb->instrs)
//         {
//             switch (inst->type)
//             {
//             case L_StmKind::T_ALLOCA:
//                 bb->instrs.remove(inst); // Remove the alloca instruction
//                 break;

//             case L_StmKind::T_STORE:
//             {
//                 AS_operand *res = nullptr;
//                 AS_operand *src = nullptr;
//                 auto store = inst->u.STORE;
//                 if (store->ptr->kind == OperandKind::TEMP && store->ptr->u.TEMP->type == TempType::INT_PTR && store->ptr->u.TEMP->len == 0)
//                 {
//                     if (temp2ASoper.find(store->ptr->u.TEMP) != temp2ASoper.end())
//                         res = temp2ASoper[store->ptr->u.TEMP];
//                 }
//                 if (store->src->kind == OperandKind::TEMP && store->src->u.TEMP->type == TempType::INT_TEMP)
//                     src = mem_scalar_load[store->src->u.TEMP];
//                 if (res == nullptr)
//                 {
//                     if (src != nullptr)
//                     {
//                         store->src = src;
//                     }
//                 }
//                 else
//                 {
//                     inst = L_Move(src == nullptr ? store->src : src, res);
//                 }
//                 break;
//             }
//             case L_StmKind::T_LOAD:
//             {
//                 AS_operand *res = nullptr;
//                 AS_operand *src = nullptr;
//                 auto load =inst->u.LOAD;
//                 if (load->ptr->kind == OperandKind::TEMP && load->ptr->u.TEMP->type == TempType::INT_PTR && load->ptr->u.TEMP->len == 0)
//                 {
//                     if (temp2ASoper.find(load->ptr->u.TEMP) != temp2ASoper.end())
//                     {
//                         mem_scalar_load[load->dst->u.TEMP] = temp2ASoper[load->ptr->u.TEMP];
//                         bb->instrs.remove(inst);
//                         continue;
//                     }
//                 }
//                 break;
//             }

//             case L_StmKind::T_PHI:
//                 // Handle Phi instructions
//                 if (newPhis.count(inst))
//                 {
//                     //incomingVals[newPhis[inst]] = inst; // Update incoming value for the Phi node
//                 }
//                 break;

//             default:
//                 break;
//             }
//         }

//         // Update incoming values for successor blocks
//         for (auto succ : bb->succs)
//         {
//             for (auto &val : incomingVals)
//             {
//             //    incomingVals[succ][val.first] = val.second; // Propagate incoming values to successors
//             }
//             //worklist2.push_back({succ, incomingVals}); // Add successor to the worklist
//         }
//     }
// }
