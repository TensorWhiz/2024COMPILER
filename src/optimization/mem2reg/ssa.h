#ifndef __SSA
#define __SSA


#include "../../ir/temp.h"
#include "../../ir/llvm_ir.h"
#include "../../common/graph.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>

LLVMIR::L_prog* SSA(LLVMIR::L_prog*prog);
void combine_addr(LLVMIR::L_func* fun);
void mem2reg(LLVMIR::L_func* fun);
void Dominators(GRAPH::Graph<LLVMIR::L_block*>& bg);
void tree_Dominators(GRAPH::Graph<LLVMIR::L_block*>& bg);
void computeDF(GRAPH::Graph<LLVMIR::L_block*>& bg,GRAPH::Node<LLVMIR::L_block*>* r);
void Place_phi_fu(GRAPH::Graph<LLVMIR::L_block*>& bg,LLVMIR:: L_func*fun);
void Rename(GRAPH::Graph<LLVMIR::L_block*>& bg);
void printf_domi();
void printf_D_tree();
void printf_DF();

template <typename T>
std::unordered_set<T> make_intersection(std::unordered_set<T> &tl1, std::unordered_set<T> &tl2);
void developFuncEntryBlock(LLVMIR::L_func *fun); 

struct imm_Dominator
{
    LLVMIR::L_block *pred;
    std::unordered_set<LLVMIR::L_block *> succs;
};
typedef std::unordered_map<LLVMIR::L_block *, imm_Dominator> DominatorTree;
bool is_mem_variable(LLVMIR::L_stm *stm);

bool runOnFunction(LLVMIR::L_func &F);
void developFuncEntryBlock(LLVMIR::L_func &fun);
bool is_dominate(DominatorTree tree,LLVMIR::L_block* b1,LLVMIR::L_block*b2);
void set_stm_block(LLVMIR::L_func *fun);
#endif