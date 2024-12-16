#include <fstream>
#include <iostream>
#include <iostream>
#include "common/TeaplAst.h"
#include "common/TeaplaAst.h"
#include "common/PrintTeaplaAst.h"
// #include "TypeCheck.h"
#include "../build/y.tab.hpp"
#include "ir/llvm_ir.h"
#include "ir/ast2llvm.h"
#include "ir/printLLVM.h"
#include "asm/llvm2asm.h"
#include "asm/printASM.h"
#include "optimization/mem2reg/ssa.h"
#include "common/graph.hpp"
#include "optimization/mem2reg/bg_llvm.h"
#include "optimization/constpropagation/constpropagation.h"
#define YACCDEBUG 0
#define ASMDEBUG 1
using namespace std;
using namespace LLVMIR;

extern int yyparse();
extern YYSTYPE yylval;
extern int yydebug;
int asmdebug;

int line, col;

A_program root;
aA_program aroot;

int main(int argc, char * argv[]) {

    #if YACCDEBUG
        yydebug = 1;
    #endif
    #if ASMDEBUG
        asmdebug = 1;
    #endif

    line = 1;
    col = 1;

    string input_name = argv[1];
    auto dot_pos = input_name.find('.');
    if(dot_pos == input_name.npos)
    {
        cout << "input error";
        return -1;
    }
    string file_name(input_name.substr(0,dot_pos));
    
    freopen(argv[1], "r", stdin);  
    ofstream ASTStream;
    ASTStream.open(file_name+".ast");

    yyparse();
    
    
    aroot = aA_Program(root);
    print_aA_Program(aroot, ASTStream);
    ASTStream.close();

    // check_Prog(&std::cout, aroot);

    ofstream LLVMStream;
    LLVMStream.open(file_name + ".ll");
    auto l_prog = ast2llvm(aroot);
    l_prog=SSA(l_prog);
    l_prog=PropagateConst(l_prog);

    printL_prog(LLVMStream,l_prog);
    LLVMStream.close();

    ofstream ASMStream;
    ASMStream.open(file_name + ".S");
    auto as_prog = llvm2asm(*l_prog);

    printAS_prog(ASMStream,as_prog);
    ASMStream.close();

    return 0;
}



