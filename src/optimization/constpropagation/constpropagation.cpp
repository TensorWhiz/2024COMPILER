#include "../mem2reg/ssa.h"
#include "constpropagation.h"
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
#include "../mem2reg/bg_llvm.h"
#include "../../common/graph.hpp"
#include "../mem2reg/liveness.h"
#include "../../ir/temp.h"

using namespace std;
using namespace LLVMIR;
using namespace GRAPH;
GRAPH::Graph<LLVMIR::L_block *> RA_bg;
std::set<std::pair<L_block *, L_block *>> marked;
std::vector<std::pair<L_block *, L_block *>> cfg_worklist;
std::vector<L_stm *> ssa_worklist;
InstructionVisitor instruction_visitor;
ValueMap value_map;
L_func *ff;

AS_operand *constFold(L_stm *inst)
{
    if (inst->type == L_StmKind::T_CMP)
    {
        auto v1 = value_map.get(inst->u.CMP->left).value;
        auto v2 = value_map.get(inst->u.CMP->right).value;
        if (v1 == nullptr || v2 == nullptr)
            return nullptr;
        switch (inst->u.CMP->op)
        {
        case L_relopKind::T_eq:
            return AS_Operand_Const(v1->u.ICONST == v2->u.ICONST);
        case L_relopKind::T_ne:
            return AS_Operand_Const(v1->u.ICONST != v2->u.ICONST);
        case L_relopKind::T_lt:
            return AS_Operand_Const(v1->u.ICONST < v2->u.ICONST);
        case L_relopKind::T_gt:
            return AS_Operand_Const(v1->u.ICONST > v2->u.ICONST);
        case L_relopKind::T_le:
            return AS_Operand_Const(v1->u.ICONST <= v2->u.ICONST);
        case L_relopKind::T_ge:
            return AS_Operand_Const(v1->u.ICONST >= v2->u.ICONST);
        default:
            return nullptr;
        }
    }
    else if (inst->type == L_StmKind::T_BINOP)
    {
        auto v1 = value_map.get(inst->u.BINOP->left).value;
        auto v2 = value_map.get(inst->u.BINOP->right).value;
        if (v1 == nullptr || v2 == nullptr)
            return nullptr;
        switch (inst->u.BINOP->op)
        {
        case L_binopKind::T_plus:
            return AS_Operand_Const(v1->u.ICONST + v2->u.ICONST);
        case L_binopKind::T_minus:
            return AS_Operand_Const(v1->u.ICONST - v2->u.ICONST);
        case L_binopKind::T_mul:
            return AS_Operand_Const(v1->u.ICONST * v2->u.ICONST);
        case L_binopKind::T_div:
            return AS_Operand_Const(v1->u.ICONST / v2->u.ICONST);
        }
    }
    return nullptr;
}

InstructionVisitor::InstructionVisitor() : inst(nullptr), bb(nullptr), prev_status(), cur_status() {};

LLVMIR::L_prog *PropagateConst(L_prog *prog)
{
    for (auto F : prog->funcs)
    {
        ff = F;
        combine_addr(F);
        set_stm_block(F);
        RA_bg = Create_bg(F->blocks);
        SingleSourceGraph(RA_bg.mynodes[0], RA_bg, F);
        pc();
    }
    return prog;
}

void pc()
{
    value_map.clear();
    marked.clear();
    cfg_worklist.clear();
    ssa_worklist.clear();
    instruction_visitor = InstructionVisitor();
    cfg_worklist.emplace_back(nullptr, ff->getEntryBlock());

    for (auto *bb : ff->blocks)
    {
        for (auto expr : bb->instrs)
        {

            auto def = get_stm_def_operand(expr);
            if (def != nullptr)
                value_map.set(def, {Status::TOP, nullptr});
        }
    }

    auto i = 0;
    auto j = 0;
    while (i < cfg_worklist.size() || j < ssa_worklist.size())
    {

        while (i < cfg_worklist.size())
        {

            auto [pre_bb, bb] = cfg_worklist[i++];

            if (marked.count({pre_bb, bb}) != 0)
                continue;
            marked.insert({pre_bb, bb});

            for (auto *inst : bb->instrs)
                instruction_visitor.visit(inst);
        }
        while (j < ssa_worklist.size())
        {
            auto *inst = ssa_worklist[j++];
            auto bb = inst->bb;
            auto bb_id = RA_bg.findNode(bb);
            auto bb_node = RA_bg.mynodes[bb_id];

            for (auto pre_bb_id : bb_node->preds)
            {
                auto pre_bb = RA_bg.mynodes[pre_bb_id]->info;
                if (marked.count({pre_bb, bb}) != 0)
                {
                    instruction_visitor.visit(inst);
                    break;
                }
            }
        }
    }
    replaceConstant();
    //rewriteBrPhi();
}

void replaceConstant()
{
    combine_addr(ff);
    std::vector<L_stm *> delete_list;

    for (auto *bb : ff->blocks)
    {
        for (auto *inst : bb->instrs)
        {
            AS_operand *def = get_stm_def_operand(inst);

            if (def != nullptr && value_map.get(def).status == Status::CONST)
            {
                auto const_operand = AS_Operand_Const(value_map.get(def).value->u.ICONST);
                *def = *const_operand;
                if (inst->type != L_StmKind::T_CJUMP)
                    delete_list.push_back(inst);
            }
        }
    }
    for (auto inst : delete_list)
    {
        inst->removeFromBlock();
    }
}

void rewriteBrPhi()
{
    for (auto bb_it = ff->blocks.begin(); bb_it != ff->blocks.end();)
    {
        L_block *bb = *bb_it;
        bb_it++;
        if (bb->instrs.empty())
            continue;
        auto branch_inst = bb->instrs.back();
        if (branch_inst->type == L_StmKind::T_CJUMP)
        {
            auto const_cond = branch_inst->u.CJUMP->dst;
            if (const_cond->kind == OperandKind::ICONST)
            {
                auto true_bb = label2block(branch_inst->u.CJUMP->true_label, ff);
                auto false_bb = label2block(branch_inst->u.CJUMP->false_label, ff);

                if (const_cond != 0)
                {
                    //condBrToJmp(branch_inst, true_bb, false_bb);
                    //rewritePhi(branch_inst->bb, false_bb);
                }

                else
                {
                    //condBrToJmp(branch_inst, false_bb, true_bb);
                    //rewritePhi(branch_inst->bb, true_bb);
                }
            }
        }
    }
}

void rewritePhi(L_block *bb, L_block *invalid_bb)
{
    std::vector<L_stm *> delete_list;
    for (auto it = invalid_bb->instrs.begin(); it != invalid_bb->instrs.end();)
    {
        auto phi_inst = *it;
        if (phi_inst->type == L_StmKind::T_PHI)
        {
            for (auto pair = phi_inst->u.PHI->phis.begin(); pair != phi_inst->u.PHI->phis.end();)
            {
                if ((*pair).second == bb->label)
                {
                    pair = phi_inst->u.PHI->phis.erase(pair);
                    continue;
                }

                pair++;
            }
            assert(phi_inst->u.PHI->phis.size()!=0);
            if (phi_inst->u.PHI->phis.size() == 1)
            {
                // *phi_inst->u.PHI->dst = *phi_inst->u.PHI->phis[0].first;
                // delete_list.push_back(phi_inst);
            }
        }
        it++;
    }
    for (auto inst : delete_list)
    {
        inst->removeFromBlock();
    }
}

void condBrToJmp(L_stm *inst, L_block *jmp_bb,
                 L_block *invalid_bb)
{
    auto bb = inst->bb;
    auto new_inst=L_Jump(jmp_bb->label);
    new_inst->bb=bb;
    *inst = *new_inst;
    int bb_no = RA_bg.findNode(bb);
    int invalid_bb_no = RA_bg.findNode(invalid_bb);
    auto bb_node = RA_bg.mynodes[bb_no];
    auto invalid_bb_node = RA_bg.mynodes[invalid_bb_no];
    bb->succs.erase(invalid_bb->label);
    bb_node->succs.erase(invalid_bb_no);
    invalid_bb_node->preds.erase(bb_no);
}

void InstructionVisitor::visit(L_stm *instr)
{
    inst = instr;
    bb = inst->bb;
    if (inst->type == L_StmKind::T_JUMP)
    {
        prev_status = {Status::BOT};
        cur_status = {Status::BOT};
        visit_br(inst);
    }
    else if (inst->type == L_StmKind::T_CJUMP)
    {
        auto def = instr->u.CJUMP->dst;
        prev_status = value_map.get(def);
        cur_status = prev_status;
        visit_br(inst);
    }
    else if (inst->type == L_StmKind::T_PHI)
    {
        auto def = instr->u.PHI->dst;
        prev_status = value_map.get(def);
        cur_status = prev_status;
        visit_phi(inst);
    }
    else if (inst->type == L_StmKind::T_BINOP || inst->type == L_StmKind::T_CMP)
    {
        auto def = get_stm_def_operand(inst);
        prev_status = value_map.get(def);
        cur_status = prev_status;
        visit_foldable(inst);
    }
    else
    {
        auto def = get_stm_def_operand(inst);
        if (def == nullptr)
            return;
        prev_status = value_map.get(def);
        cur_status = {Status::BOT, nullptr};
    }

    if (cur_status != prev_status)
    {
        auto def = get_stm_def_operand(inst);
        value_map.set(def, cur_status);
        for (auto b : ff->blocks)
        {
            for (auto it : b->instrs)
            {
                auto ops = get_use_int_operand(it);
                for (auto op : ops)
                {
                    if (*op == def)
                    {
                        ssa_worklist.push_back(it);
                        break;
                    }
                }
            }
        }
    }
}

void InstructionVisitor::visit_phi(L_stm *inst)
{
    const int phi_size = inst->u.PHI->phis.size();
    for (int i = 0; i < phi_size; i++)
    {
        auto pre_bb = label2block(inst->u.PHI->phis[i].second, ff);
        if (marked.count({pre_bb, bb}) != 0)
        {
            auto op = inst->u.PHI->phis[i].first;
            auto op_status = value_map.get(op);
            cur_status ^= op_status;
        }
    }
}

void InstructionVisitor::visit_br(L_stm *inst)
{
    if (inst->type == L_StmKind::T_JUMP)
    {
        auto jmp_bb = label2block(inst->u.JUMP->jump, ff);
        cfg_worklist.emplace_back(bb, jmp_bb);
        return;
    }

    auto true_bb = label2block(inst->u.CJUMP->true_label, ff);
    auto false_bb = label2block(inst->u.CJUMP->false_label, ff);
    auto const_cond = value_map.get(inst->u.CJUMP->dst).value;
    if (const_cond != nullptr)
    {
        const_cond->u.ICONST != 0 ? cfg_worklist.emplace_back(bb, true_bb)
                                  : cfg_worklist.emplace_back(bb, false_bb);
    }
    else
    {
        cfg_worklist.emplace_back(bb, true_bb);
        cfg_worklist.emplace_back(bb, false_bb);
    }
}

void InstructionVisitor::visit_foldable(L_stm *inst)
{
    auto folded = constFold(inst);
    if (folded != nullptr)
    {
        cur_status = {Status::CONST, folded};
        return;
    }
    cur_status = {Status::TOP, nullptr};
    for (auto op : get_use_operand(inst))
    {
        if (value_map.get(*op).is_bot())
        {
            cur_status = {Status::BOT, nullptr};
            return;
        }
    }
}