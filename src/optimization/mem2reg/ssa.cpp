#include "ssa.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include "bg_llvm.h"
#include "../../common/graph.hpp"
#include "liveness.h"

using namespace std;
using namespace LLVMIR;
using namespace GRAPH;

unordered_map<L_block *, unordered_set<L_block *>> dominators;
unordered_map<L_block *, imm_Dominator> tree_dominators;
unordered_map<L_block *, unordered_set<L_block *>> df_array;
unordered_map<L_block *, Node<LLVMIR::L_block *> *> revers_graph;
unordered_map<Temp_temp *, AS_operand *> temp2ASoper;

static void init_table()
{
    dominators.clear();
    tree_dominators.clear();
    df_array.clear();
    revers_graph.clear();
    temp2ASoper.clear();
}

LLVMIR::L_prog *SSA(LLVMIR::L_prog *prog)
{
    for (auto fun : prog->funcs)
    {
        init_table();
        combine_addr(fun);
        // developFuncEntryBlock(*fun);
        // mem2reg(fun);
        //   auto RA_bg = Create_bg(fun->blocks);
        //   SingleSourceGraph(RA_bg.mynodes[0], RA_bg, fun);
        //   Liveness(RA_bg.mynodes[0], RA_bg, fun->args);
        //   Dominators(RA_bg);
        //   tree_Dominators(RA_bg);
        //   computeDF(RA_bg, RA_bg.mynodes[0]);
        //   Place_phi_fu(RA_bg, fun);
        //   Rename(RA_bg);
        runOnFunction(*fun);
        combine_addr(fun);
    }
    return prog;
}

void set_stm_block(LLVMIR::L_func *fun)
{
    for (auto &block : fun->blocks)
    {
        for (auto &stm : block->instrs)
        {
            stm->bb = block;
        }
    }
}

bool is_mem_variable(L_stm *stm)
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
    unordered_set<L_block *> dom_set;
    dom_set.emplace(bg.mynodes[0]->info);
    dominators[bg.mynodes[0]->info] = dom_set;
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
    for (auto x : df_array)
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

        unordered_set<L_block *> c_df_array = df_array[succ];
        for (L_block *c_df : c_df_array)
        {
            if (dominators[c_df].find(r->info) == dominators[c_df].end() || r->info == c_df)
            {
                s.emplace(c_df);
            }
        }
    }

    df_array[r->info] = s;
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
            unordered_set<L_block *> DF_n = df_array[n];
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

static void Rename_temp(GRAPH::Graph<LLVMIR::L_block *> &bg, GRAPH::Node<LLVMIR::L_block *> *n, unordered_map<Temp_temp *, stack<Temp_temp *>> &Stack)
{
    // 处理前保留原def的temp
    unordered_map<Temp_temp *, int> origin_def_times;

    // 语句处理;
    for (auto &stm : n->info->instrs)
    {
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

std::vector<L_stm *> Allocas_Promoted;
std::vector<L_stm *> Allocas_UnPromoted;
std::unordered_map<AS_operand *, std::unordered_set<L_block *>> DefsBlock;
std::unordered_map<AS_operand *, std::unordered_set<L_block *>> UsesBlock;

unordered_map<AS_operand *, vector<L_stm *>> allocDefs; // alloc -> list of defs
unordered_map<AS_operand *, vector<L_stm *>> allocUses; // alloc -> list of uses

std::map<L_block *, std::map<L_stm *, Temp_temp *>> PhiMap;

/// @brief 存储基本块的支配边界
unordered_map<L_block *, unordered_set<L_block *>> DomFsBlock;
L_stm *OnlyStore;

void developFuncEntryBlock(L_func &fun)
{
    std::vector<L_stm *> F_Allocas;
    auto entryBlock = fun.blocks.front();
    for (auto block : fun.blocks)
    {
        list<L_stm *>::iterator it = block->instrs.begin();
        while (it != block->instrs.end())
        {

            if (is_mem_variable(*it))
            {

                auto alloc = (*it)->u.ALLOCA;
                allocUses[alloc->dst] = {};
                allocDefs[alloc->dst] = {};
                UsesBlock[alloc->dst] = {};
                DefsBlock[alloc->dst] = {};
                F_Allocas.push_back(*it);
                it = block->instrs.erase(it);
            }
            else
            {
                if ((*it)->type == L_StmKind::T_LOAD)
                {
                }
                else if ((*it)->type == L_StmKind::T_STORE)
                {
                }

                it++;
            }
        }
    }
    auto it = entryBlock->instrs.begin();
    it++;

    for (auto allocStm : F_Allocas)
    {
        entryBlock->instrs.insert(it, allocStm);
    }
}

int getInstructionIndex(L_block *BB, L_stm *I)
{
    int index = 0;
    for (auto it : BB->instrs)
    {
        if (I == it)
            return index;
        index++;
    }
    return -1;
}

bool rewriteSingleStoreAlloca(GRAPH::Graph<LLVMIR::L_block *> &bg, L_stm *stm)
{
    L_alloca *alloca = stm->u.ALLOCA;
    // bool StoringGlobalVal = !isa<Instruction>(OnlyStore->getOperand(0));
    bool StoringGlobalVal = false;
    L_block *StoreBB = OnlyStore->bb;
    int StoreIndex = -1;
    UsesBlock[alloca->dst].clear();
    for (auto it : allocUses[alloca->dst])
    {
        // if (it == OnlyStore)
        //     continue;
        if (it->type == L_StmKind::T_LOAD)
        {
            L_block *LoadBB = it->bb;
            if (!StoringGlobalVal)
            { // Non-instructions are always dominated.
                if (LoadBB == StoreBB)
                {
                    if (StoreIndex == -1)
                        StoreIndex = getInstructionIndex(StoreBB, OnlyStore);

                    if (unsigned(StoreIndex) > getInstructionIndex(StoreBB, it))
                    {
                        UsesBlock[alloca->dst].insert(StoreBB);
                        continue;
                    }
                }
                else if (!is_dominate(tree_dominators, StoreBB, LoadBB))
                {
                    UsesBlock[alloca->dst].insert(LoadBB);
                    continue;
                }
            }

            AS_operand *ReplVal = OnlyStore->u.STORE->src;
            // replace use of load dst
            for (auto b : bg.mynodes)
            {
                for (auto instr : b.second->info->instrs)
                {
                    auto ops = get_use_int_operand(instr);
                    for (auto op : ops)
                    {
                        if ((*op)->u.TEMP == (it->u.LOAD->dst->u.TEMP))
                        {
                            (*op) = ReplVal;
                        }
                    }
                }
            }
            it->removeFromBlock();
        }
    }

    if (!UsesBlock[alloca->dst].empty())
        return false;
    else
    {
        OnlyStore->removeFromBlock();
        stm->removeFromBlock();
        return true;
    }
}

/// 这个函数用于判断alloca指令，是否只有load/store. 如果没有使用，或者只有load和store返回true, 否则返回false
bool isPromote(L_alloca *AI)
{

    // Only allow direct and non-volatile loads and stores...
    // for (L_stm *U : allocUses[AI->dst])
    // {
    //     if (U->type == L_StmKind::T_LOAD)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
    // for (L_stm *U : allocDefs[AI->dst])
    // {
    //     if (U->type == L_StmKind::T_STORE)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }

    return true;
}

/// 收集promoted的alloca指令
void collectPromotedAllocas(L_func &F)
{
    L_block *BB;

    Allocas_Promoted.clear();

    BB = F.getEntryBlock();
    for (auto instr : BB->instrs)
    {
        if (is_mem_variable(instr))
        {
            if (isPromote(instr->u.ALLOCA))
            {
                Allocas_Promoted.push_back(instr);
            }
        }
    }
}

/// 分析alloca指令，找出他定义的块和使用的块
void analysisAlloca(L_func &F, L_alloca *alloc)
{
    OnlyStore = nullptr;
    for (auto block : F.blocks)
    {
        for (auto it : block->instrs)
        {
            if (it->type == L_StmKind::T_LOAD && it->u.LOAD->ptr->u.TEMP == alloc->dst->u.TEMP)
            {
                assert(it->u.LOAD->ptr == alloc->dst);
                allocUses[it->u.LOAD->ptr].push_back(it);
                UsesBlock[it->u.LOAD->ptr].emplace(block);
            }
            else if (it->type == L_StmKind::T_STORE && it->u.STORE->ptr->u.TEMP == alloc->dst->u.TEMP)
            {
                allocDefs[it->u.STORE->ptr].push_back(it);
                DefsBlock[it->u.STORE->ptr].emplace(block);
                OnlyStore = it;
            }
        }
    }
}

void Rename_temp_alloca(GRAPH::Graph<LLVMIR::L_block *> &bg, GRAPH::Node<LLVMIR::L_block *> *n, unordered_map<Temp_temp *, std::stack<AS_operand *>> &Stack, std::vector<L_stm *> &InstCanBeRemoveList, std::unordered_set<AS_operand *> GepPtrList)
{
    for (auto &stm : n->info->instrs)
    {
        if (stm->type == L_StmKind::T_ALLOCA)
        {
            if (is_mem_variable(stm))
                InstCanBeRemoveList.push_back(stm);
        }

        else if (stm->type == L_StmKind::T_STORE)
        {
            if (GepPtrList.find(stm->u.STORE->ptr) != GepPtrList.end())
                continue;

            if (stm->u.STORE->ptr->kind == OperandKind::NAME)
                continue;

            Stack[stm->u.STORE->ptr->u.TEMP].push(stm->u.STORE->src);
            InstCanBeRemoveList.push_back(stm);
        }
        else if (stm->type == L_StmKind::T_LOAD)
        {
            bool del = true;
            if (stm->u.LOAD->ptr->kind == OperandKind::TEMP && stm->u.LOAD->dst->kind == OperandKind::TEMP)
            {
                 if (GepPtrList.find(stm->u.LOAD->ptr) != GepPtrList.end())
                continue;
               *(stm->u.LOAD->dst)=*Stack[stm->u.LOAD->ptr->u.TEMP].top();
                InstCanBeRemoveList.push_back(stm);
                
                }

        }
        else if (stm->type == L_StmKind::T_PHI)

        {
            AS_operand *new_op = AS_Operand_Temp(Temp_newtemp_int());
            Stack[stm->u.PHI->dst->u.TEMP].push(new_op);
            stm->u.PHI->dst = new_op;
            // Stack[PhiMap[n->info][stm]].push(stm->u.PHI->dst);
        }
        else if (stm->type == L_StmKind::T_GEP)
        {
            GepPtrList.insert(stm->u.GEP->new_ptr);
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
                    if (Stack.find(stm->u.PHI->phis[j].first->u.TEMP) != Stack.end())
                    {
                        AS_operand *temp = Stack[stm->u.PHI->phis[j].first->u.TEMP].top();
                        auto op = temp;
                        // assert(op->kind!=OperandKind::ICONST);
                        stm->u.PHI->phis[j] = make_pair(op, n->info->label);
                    }
                }
            }
        }
    }

    // 处理子节点
    for (auto &son : tree_dominators[n->info].succs)
    {
        int son_index = bg.findNode(son);
        Rename_temp_alloca(bg, bg.mynodes[son_index], Stack, InstCanBeRemoveList, GepPtrList);
    }

    // pop出这个block压入的v
    for (auto &stm : n->info->instrs)
    {
        if (stm->type == L_StmKind::T_STORE)
        {
            Stack[stm->u.STORE->ptr->u.TEMP].pop();
        }
        else if (stm->type == L_StmKind::T_PHI)
        {
            Stack[PhiMap[n->info][stm]].pop();
        }
    }
}

void Rename_alloca(GRAPH::Graph<LLVMIR::L_block *> &bg, L_func &F)
{
    // 初始化set
    unordered_map<Temp_temp *, stack<AS_operand *>> Stack;
    for (auto alloc : Allocas_Promoted)
    {
        Stack[alloc->u.ALLOCA->dst->u.TEMP] = stack<AS_operand *>{};
        Stack[alloc->u.ALLOCA->dst->u.TEMP].push(AS_Operand_Const(0));
    }

    std::vector<L_stm *> InstCanBeRemoveList;
    std::unordered_set<AS_operand *> GepPtrList;
    Rename_temp_alloca(bg, bg.mynodes[0], Stack, InstCanBeRemoveList, GepPtrList);

    while (!InstCanBeRemoveList.empty())
    {
        auto Inst = InstCanBeRemoveList.back();
        Inst->removeFromBlock();
        InstCanBeRemoveList.pop_back();
    }
}

void insertPhi(GRAPH::Graph<LLVMIR::L_block *> &bg, L_func *fun)
{
    // unordered_map<L_block *, unordered_set<Temp_temp *>> A_orig;
    // unordered_map<Temp_temp *,unordered_set<L_block *>>defsites;
    // for(auto b:bg.mynodes){
    //     for(auto temp:FG_def(b.second)){
    //         A_orig[b.second->info].insert(temp);
    //         defsites[temp].insert(b.second->info);
    //     }

    // }

    // unordered_map<L_block *, unordered_set<AS_operand *>> A_phi;
    /// 插入phi节点
    for (auto alloc : Allocas_Promoted)
    {
        unordered_set<L_block *> W;
        unordered_set<L_block *> f;
        Temp_temp *a = alloc->u.ALLOCA->dst->u.TEMP;
        for (L_block *b : DefsBlock[alloc->u.ALLOCA->dst])
        {
            W.insert(b);
        }
        // W=defsites[a];
        while (!W.empty())
        {
            L_block *n = *W.begin();
            W.erase(n);
            for (auto &Y : df_array[n])
            {
                // int y_index = bg.findNode(Y);
                // TempSet_ y_in = FG_In(bg.mynodes[y_index]);
                if (f.find(Y) == f.end())
                // if (A_phi[Y].find(a)==A_phi[Y].end()&&y_in.find(a->u.TEMP) != y_in.end())
                { // insert phi
                    AS_operand *dst = AS_Operand_Temp(a);
                    std::vector<std::pair<AS_operand *, Temp_label *>> phis;
                    for (auto &pred : bg.mynodes[bg.findNode(Y)]->preds)
                    {
                        phis.push_back(make_pair(dst, bg.mynodes[pred]->info->label));
                    }
                    auto it = Y->instrs.begin();
                    it++;
                    L_stm *phi = L_Phi(dst, phis);
                    Y->instrs.insert(it, phi);
                    //
                    f.insert(Y);
                    PhiMap[Y].insert({phi, alloc->u.ALLOCA->dst->u.TEMP});
                    // Add the frontier to the worklist
                    if (W.find(Y) == W.end())
                        W.insert(Y);
                }
            }
        }
    }
}

/// @brief 执行alloca2reg
/// @param F
void executeMem2Reg(L_func &F, GRAPH::Graph<LLVMIR::L_block *> &bg)
{
    for (auto it = Allocas_Promoted.begin(); it != Allocas_Promoted.end();)
    {
        L_stm *AI = (*it);
        analysisAlloca(F, AI->u.ALLOCA);
        auto a = allocUses[AI->u.ALLOCA->dst];

        if (allocUses[AI->u.ALLOCA->dst].empty())
        {
            for (auto &stm : allocDefs[AI->u.ALLOCA->dst])
            {
                stm->removeFromBlock();
            }
            AI->removeFromBlock();

            it = Allocas_Promoted.erase(it);

            continue;
        }

        if (allocDefs[AI->u.ALLOCA->dst].size() == 1)
        {
            if (rewriteSingleStoreAlloca(bg, AI))
            {
                it = Allocas_Promoted.erase(it);
                continue;
            }
        }
        it++;
    }
    // Place_phi_fu(bg,&F);
    insertPhi(bg, &F);
    // combine_addr(&F);
    Rename_alloca(bg, F);
    // combine_addr(&F);
}

bool runOnFunction(L_func &F)
{
    Allocas_Promoted.clear();
    DefsBlock.clear();
    UsesBlock.clear();
    PhiMap.clear();
    DomFsBlock.clear();
    allocUses.clear();
    allocDefs.clear();

    developFuncEntryBlock(F);
    set_stm_block(&F);
    collectPromotedAllocas(F);

    if (Allocas_Promoted.empty())
        return true;

    // /// 计算支配树
    auto RA_bg = Create_bg(F.blocks);
    SingleSourceGraph(RA_bg.mynodes[0], RA_bg, &F);
    Liveness(RA_bg.mynodes[0], RA_bg, F.args);
    Dominators(RA_bg);
    tree_Dominators(RA_bg);
    computeDF(RA_bg, RA_bg.mynodes[0]);
    // printf_DF();
    // printf_D_tree();
    executeMem2Reg(F, RA_bg);
    return true;
}

bool is_dominate(DominatorTree tree, L_block *b1, L_block *b2)
{
    if (b1 == b2)
    {
        return true;
    }

    L_block *pred = tree[b2].pred;
    while (pred != nullptr)
    {
        if (pred == b1)
        {
            return true;
        }
        pred = tree[pred].pred;
    }
    // for (L_block* succ : tree[b2].succs) {
    //     if (is_dominate(tree, b1, succ)) {
    //         return true;
    //     }
    // }
    return false;
}
