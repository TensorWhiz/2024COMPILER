#include "../mem2reg/bg_llvm.h"
#include "../../common/graph.hpp"
#include "../../ir/temp.h"
using namespace std;
using namespace LLVMIR;
using namespace GRAPH;

unordered_map<AS_operand *, unordered_map<int, AS_operand *>> baseaddr_stored;
void easy_cse(L_func *F)
{
    list<L_stm *> del_list;
    for (auto bb : F->blocks)
    {
        baseaddr_stored.clear();
        for (auto instr : bb->instrs)
        {
            if (instr->type == L_StmKind::T_GEP)
            {
                bool flag = false;
                for (auto pair1 : baseaddr_stored)
                {
                    if (pair1.first->u.TEMP == instr->u.GEP->base_ptr->u.TEMP)
                    {
                        for (auto pair2 : pair1.second)
                        {
                            if (pair2.first == instr->u.GEP->index->u.ICONST)
                            {
                                *(instr->u.GEP->new_ptr) = *(pair2.second);
                                del_list.push_back(instr);
                                flag = true;
                                break;
                            }
                        }
                    }
                }

                if (flag)
                    continue;

                baseaddr_stored[instr->u.GEP->base_ptr][instr->u.GEP->index->u.ICONST] = instr->u.GEP->new_ptr;
            }
        }
    }

    for (auto it : del_list)
    {
        it->removeFromBlock();
    }
}

LLVMIR::L_prog *CSE_EASY(L_prog *prog)
{
    for (auto F : prog->funcs)
    {
        easy_cse(F);
    }
    return prog;
}
