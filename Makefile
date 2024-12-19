CXX = clang++
CXXFLAGS = -std=c++17 -g -O0

TESTCASE_DIR := tests/public
TESTCASES = $(wildcard $(TESTCASE_DIR)/*.tea)
LLFILES = $(patsubst $(TESTCASE_DIR)/%.tea,$(TESTCASE_DIR)/%.ast,$(TESTCASES))

.SECONDARY: $(LLFILES)

run: $(patsubst $(TESTCASE_DIR)/%.tea,$(TESTCASE_DIR)/%.ll,$(TESTCASES))

$(TESTCASE_DIR)/%.ll: $(TESTCASE_DIR)/%.tea build/compiler
	@./test-functional2.sh $* $(TESTCASE_DIR)
	@echo

build/compiler: build/y.tab.o build/lex.yy.o build/TeaplAst.o build/TeaplaAst.o build/PrintTeaplaAst.o build/compiler.o build/llvm_ir.o build/ast2llvm.o build/printLLVM.o build/asm_arm.o build/llvm2asm.o build/printASM.o build/temp.o build/allocReg.o build/ssa.o build/bg_llvm.o build/liveness.o build/constpropagation.o build/easy.o
	$(CXX) $(CXXFLAGS) -o build/compiler $^

build/y.tab.cpp: src/parser/parser.yacc src/common/TeaplAst.h
	@yacc -o build/y.tab.cpp -d $< -v --debug

build/y.tab.hpp: src/parser/parser.yacc
	@yacc -o build/y.tab.cpp -d $< -v --debug

build/lex.yy.cpp: src/parser/lexer.lex build/y.tab.hpp build/y.tab.cpp
	@lex -o build/lex.yy.cpp $<

build/y.tab.o: build/y.tab.cpp build/y.tab.hpp
	$(CXX) $(CXXFLAGS) -c $< -o build/y.tab.o

build/lex.yy.o: build/lex.yy.cpp build/y.tab.hpp
	$(CXX) $(CXXFLAGS) -c $< -o build/lex.yy.o

build/TeaplAst.o: src/common/TeaplAst.cpp src/common/TeaplAst.h
	$(CXX) $(CXXFLAGS) -c $< -o build/TeaplAst.o

build/TeaplaAst.o: src/common/TeaplaAst.cpp src/common/TeaplAst.h
	$(CXX) $(CXXFLAGS) -c $< -o build/TeaplaAst.o

build/PrintTeaplaAst.o: src/common/PrintTeaplaAst.cpp src/common/PrintTeaplaAst.h
	$(CXX) $(CXXFLAGS) -c $< -o build/PrintTeaplaAst.o

build/compiler.o: src/compiler.cpp build/TeaplAst.o build/TeaplaAst.o build/PrintTeaplaAst.o build/y.tab.o build/lex.yy.o build/llvm_ir.o build/ast2llvm.o build/printLLVM.o build/asm_arm.o build/llvm2asm.o build/printASM.o build/temp.o build/ssa.o build/bg_llvm.o build/liveness.o build/constpropagation.o build/easy.o
	$(CXX) $(CXXFLAGS) -c $< -o build/compiler.o

build/llvm_ir.o: src/ir/llvm_ir.cpp src/ir/llvm_ir.h src/ir/temp.cpp src/ir/temp.h
	$(CXX) $(CXXFLAGS) -c $< -o build/llvm_ir.o

build/ast2llvm.o: src/ir/ast2llvm.cpp src/ir/ast2llvm.h src/ir/llvm_ir.cpp src/ir/llvm_ir.h src/ir/temp.cpp src/ir/temp.h
	$(CXX) $(CXXFLAGS) -c $< -o build/ast2llvm.o

build/printLLVM.o: src/ir/printLLVM.cpp src/ir/printLLVM.h src/ir/llvm_ir.cpp src/ir/llvm_ir.h src/ir/temp.cpp src/ir/temp.h
	$(CXX) $(CXXFLAGS) -c $< -o build/printLLVM.o

build/asm_arm.o: src/asm/asm_arm.cpp src/asm/asm_arm.h src/ir/temp.cpp src/ir/temp.h
	$(CXX) $(CXXFLAGS) -c $< -o build/asm_arm.o

build/llvm2asm.o: src/asm/llvm2asm.cpp src/asm/llvm2asm.h src/asm/asm_arm.cpp src/asm/asm_arm.h src/ir/llvm_ir.cpp src/ir/llvm_ir.h src/ir/temp.cpp src/ir/temp.h src/asm/register_rules.h
	$(CXX) $(CXXFLAGS) -c $< -o build/llvm2asm.o

build/printASM.o: src/asm/printASM.cpp src/asm/printASM.h src/asm/allocReg.cpp src/asm/allocReg.h src/asm/asm_arm.cpp src/asm/asm_arm.h
	$(CXX) $(CXXFLAGS) -c $< -o build/printASM.o

build/temp.o: src/ir/temp.cpp src/ir/temp.h
	$(CXX) $(CXXFLAGS) -c $< -o build/temp.o

build/ssa.o: src/optimization/mem2reg/ssa.cpp src/optimization/mem2reg/ssa.h
	$(CXX) $(CXXFLAGS) -c $< -o build/ssa.o

build/bg_llvm.o: src/optimization/mem2reg/bg_llvm.cpp src/optimization/mem2reg/bg_llvm.h src/common/graph.hpp
	$(CXX) $(CXXFLAGS) -c $< -o build/bg_llvm.o

build/liveness.o: src/optimization/mem2reg/liveness.cpp src/optimization/mem2reg/liveness.h src/common/graph.hpp
	$(CXX) $(CXXFLAGS) -c $< -o build/liveness.o

build/allocReg.o: src/asm/allocReg.cpp src/asm/allocReg.h src/asm/asm_arm.cpp src/asm/asm_arm.h src/ir/temp.cpp src/ir/temp.h src/asm/register_rules.h src/asm/llvm2asm.h
	$(CXX) $(CXXFLAGS) -c $< -o build/allocReg.o

build/constpropagation.o: src/optimization/constpropagation/constpropagation.cpp src/optimization/constpropagation/constpropagation.h src/optimization/mem2reg/ssa.h  src/optimization/mem2reg/liveness.h src/common/graph.hpp
	$(CXX) $(CXXFLAGS) -c $< -o build/constpropagation.o

build/easy.o: src/optimization/cse/easy.cpp src/optimization/cse/easy.h src/common/graph.hpp src/optimization/mem2reg/bg_llvm.h
	$(CXX) $(CXXFLAGS) -c $< -o build/easy.o

clean:
	rm -f build/compiler \
	output/*.ll output/ir/*.out output/ir/*.txt  output/ir/*.ll \
	output/asm/* output/asm/*.o output/asm/*.out \
	$(TESTCASE_DIR)/*.S $(TESTCASE_DIR)/*.ll $(TESTCASE_DIR)/*.ast
