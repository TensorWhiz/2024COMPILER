#include "../mem2reg/bg_llvm.h"
#include "../../common/graph.hpp"

using namespace std;
using namespace LLVMIR;
using namespace GRAPH;

LLVMIR::L_prog *CSE_EASY(L_prog *prog);
void easy_cse(L_func *F);