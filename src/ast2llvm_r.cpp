#include "ast2llvm.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <cassert>
#include <list>

using namespace std;
using namespace LLVMIR;

static unordered_map<string, FuncType> funcReturnMap;
static unordered_map<string, StructInfo> structInfoMap;
static unordered_map<string, Name_name *> globalVarMap;
static unordered_map<string, Temp_temp *> localVarMap;
static list<L_stm *> emit_irs;

void ast2llvmBlockList(vector<aA_codeBlockStmt> &stmts, Temp_label *con_label, Temp_label *bre_label)
{
    for (aA_codeBlockStmt stmt : stmts)
    {
        ast2llvmBlock(stmt, con_label, bre_label);
    }
}

LLVMIR::L_prog *ast2llvm(aA_program p)
{
    auto defs = ast2llvmProg_first(p);
    auto funcs = ast2llvmProg_second(p);
    vector<L_func *> funcs_block;
    for (const auto &f : funcs)
    {
        funcs_block.push_back(ast2llvmFuncBlock(f));
    }
    for (auto &f : funcs_block)
    {
        ast2llvm_moveAlloca(f);
    }
    return new L_prog(defs, funcs_block);
}

int ast2llvmRightVal_first(aA_rightVal r)
{
    if (r == nullptr)
    {
        return 0;
    }
    switch (r->kind)
    {
    case A_arithExprValKind:
    {
        return ast2llvmArithExpr_first(r->u.arithExpr);
        break;
    }
    case A_boolExprValKind:
    {
        return ast2llvmBoolExpr_first(r->u.boolExpr);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmBoolExpr_first(aA_boolExpr b)
{
    switch (b->kind)
    {
    case A_boolBiOpExprKind:
    {
        return ast2llvmBoolBiOpExpr_first(b->u.boolBiOpExpr);
        break;
    }
    case A_boolUnitKind:
    {
        return ast2llvmBoolUnit_first(b->u.boolUnit);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmBoolBiOpExpr_first(aA_boolBiOpExpr b)
{
    int l = ast2llvmBoolExpr_first(b->left);
    int r = ast2llvmBoolExpr_first(b->right);
    if (b->op == A_and)
    {
        return l && r;
    }
    else
    {
        return l || r;
    }
}

int ast2llvmBoolUOpExpr_first(aA_boolUOpExpr b)
{
    if (b->op == A_not)
    {
        return !ast2llvmBoolUnit_first(b->cond);
    }
    return 0;
}

int ast2llvmBoolUnit_first(aA_boolUnit b)
{
    switch (b->kind)
    {
    case A_comOpExprKind:
    {
        return ast2llvmComOpExpr_first(b->u.comExpr);
        break;
    }
    case A_boolExprKind:
    {
        return ast2llvmBoolExpr_first(b->u.boolExpr);
        break;
    }
    case A_boolUOpExprKind:
    {
        return ast2llvmBoolUOpExpr_first(b->u.boolUOpExpr);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmComOpExpr_first(aA_comExpr c)
{
    auto l = ast2llvmExprUnit_first(c->left);
    auto r = ast2llvmExprUnit_first(c->right);
    switch (c->op)
    {
    case A_lt:
    {
        return l < r;
        break;
    }
    case A_le:
    {
        return l <= r;
        break;
    }
    case A_gt:
    {
        return l > r;
        break;
    }
    case A_ge:
    {
        return l >= r;
        break;
    }
    case A_eq:
    {
        return l == r;
        break;
    }
    case A_ne:
    {
        return l != r;
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmArithBiOpExpr_first(aA_arithBiOpExpr a)
{
    auto l = ast2llvmArithExpr_first(a->left);
    auto r = ast2llvmArithExpr_first(a->right);
    switch (a->op)
    {
    case A_add:
    {
        return l + r;
        break;
    }
    case A_sub:
    {
        return l - r;
        break;
    }
    case A_mul:
    {
        return l * r;
        break;
    }
    case A_div:
    {
        return l / r;
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmArithUExpr_first(aA_arithUExpr a)
{
    if (a->op == A_neg)
    {
        return -ast2llvmExprUnit_first(a->expr);
    }
    return 0;
}

int ast2llvmArithExpr_first(aA_arithExpr a)
{
    switch (a->kind)
    {
    case A_arithBiOpExprKind:
    {
        return ast2llvmArithBiOpExpr_first(a->u.arithBiOpExpr);
        break;
    }
    case A_exprUnitKind:
    {
        return ast2llvmExprUnit_first(a->u.exprUnit);
        break;
    }
    default:
        assert(0);
        break;
    }
    return 0;
}

int ast2llvmExprUnit_first(aA_exprUnit e)
{
    if (e->kind == A_numExprKind)
    {
        return e->u.num;
    }
    else if (e->kind == A_arithExprKind)
    {
        return ast2llvmArithExpr_first(e->u.arithExpr);
    }
    else if (e->kind == A_arithUExprKind)
    {
        return ast2llvmArithUExpr_first(e->u.arithUExpr);
    }
    else
    {
        assert(0);
    }
    return 0;
}

std::vector<LLVMIR::L_def *> ast2llvmProg_first(aA_program p)
{
    vector<L_def *> defs;
    for (const auto &v : p->programElements)
    {
        switch (v->kind)
        {
        case A_programNullStmtKind:
        {
            break;
        }
        case A_programVarDeclStmtKind:
        {
            if (v->u.varDeclStmt->kind == A_varDeclKind)
            {
                if (v->u.varDeclStmt->u.varDecl->kind == A_varDeclScalarKind)
                {
                    if (v->u.varDeclStmt->u.varDecl->u.declScalar->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                                             Name_newname_struct(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declScalar->id), *v->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType));
                        TempDef def(TempType::STRUCT_TEMP, 0, *v->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                                             Name_newname_int(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declScalar->id)));
                        TempDef def(TempType::INT_TEMP, 0);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id, def, vector<int>()));
                    }
                }
                else if (v->u.varDeclStmt->u.varDecl->kind == A_varDeclArrayKind)
                {
                    if (v->u.varDeclStmt->u.varDecl->u.declArray->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                                             Name_newname_struct_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declArray->id), v->u.varDeclStmt->u.varDecl->u.declArray->len, *v->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType));
                        TempDef def(TempType::STRUCT_PTR, v->u.varDeclStmt->u.varDecl->u.declArray->len, *v->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                                             Name_newname_int_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declArray->id), v->u.varDeclStmt->u.varDecl->u.declArray->len));
                        TempDef def(TempType::INT_PTR, v->u.varDeclStmt->u.varDecl->u.declArray->len);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id, def, vector<int>()));
                    }
                }
                else
                {
                    assert(0);
                }
            }
            else if (v->u.varDeclStmt->kind == A_varDefKind)
            {
                if (v->u.varDeclStmt->u.varDef->kind == A_varDefScalarKind)
                {
                    if (v->u.varDeclStmt->u.varDef->u.defScalar->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defScalar->id,
                                             Name_newname_struct(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defScalar->id), *v->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType));
                        TempDef def(TempType::STRUCT_TEMP, 0, *v->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defScalar->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defScalar->id,
                                             Name_newname_int(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defScalar->id)));
                        TempDef def(TempType::INT_TEMP, 0);
                        vector<int> init;
                        init.push_back(ast2llvmRightVal_first(v->u.varDeclStmt->u.varDef->u.defScalar->val));
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defScalar->id, def, init));
                    }
                }
                else if (v->u.varDeclStmt->u.varDef->kind == A_varDefArrayKind)
                {
                    if (v->u.varDeclStmt->u.varDef->u.defArray->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defArray->id,
                                             Name_newname_struct_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defArray->id), v->u.varDeclStmt->u.varDef->u.defArray->len, *v->u.varDeclStmt->u.varDef->u.defArray->type->u.structType));
                        TempDef def(TempType::STRUCT_PTR, v->u.varDeclStmt->u.varDef->u.defArray->len, *v->u.varDeclStmt->u.varDef->u.defArray->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defArray->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defArray->id,
                                             Name_newname_int_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defArray->id), v->u.varDeclStmt->u.varDef->u.defArray->len));
                        TempDef def(TempType::INT_PTR, v->u.varDeclStmt->u.varDef->u.defArray->len);
                        vector<int> init;
                        for (auto &el : v->u.varDeclStmt->u.varDef->u.defArray->vals)
                        {
                            init.push_back(ast2llvmRightVal_first(el));
                        }
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defArray->id, def, init));
                    }
                }
                else
                {
                    assert(0);
                }
            }
            else
            {
                assert(0);
            }
            break;
        }
        case A_programStructDefKind:
        {
            StructInfo si;
            int off = 0;
            vector<TempDef> members;
            for (const auto &decl : v->u.structDef->varDecls)
            {
                if (decl->kind == A_varDeclScalarKind)
                {
                    if (decl->u.declScalar->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_TEMP, 0, *decl->u.declScalar->type->u.structType);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declScalar->id, info);
                        members.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_TEMP, 0);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declScalar->id, info);
                        members.push_back(def);
                    }
                }
                else if (decl->kind == A_varDeclArrayKind)
                {
                    if (decl->u.declArray->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR, decl->u.declArray->len, *decl->u.declArray->type->u.structType);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declArray->id, info);
                        members.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_PTR, decl->u.declArray->len);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declArray->id, info);
                        members.push_back(def);
                    }
                }
                else
                {
                    assert(0);
                }
            }
            structInfoMap.emplace(*v->u.structDef->id, std::move(si));
            defs.push_back(L_Structdef(*v->u.structDef->id, members));
            break;
        }
        case A_programFnDeclStmtKind:
        {
            FuncType type;
            if (v->u.fnDeclStmt->fnDecl->type == nullptr)
            {
                type.type = ReturnType::VOID_TYPE;
            }
            else if (v->u.fnDeclStmt->fnDecl->type->type == A_nativeTypeKind)
            {
                type.type = ReturnType::INT_TYPE;
            }
            else if (v->u.fnDeclStmt->fnDecl->type->type == A_structTypeKind)
            {
                type.type = ReturnType::STRUCT_TYPE;
                type.structname = *v->u.fnDeclStmt->fnDecl->type->u.structType;
            }
            else
            {
                assert(0);
            }
            if (funcReturnMap.find(*v->u.fnDeclStmt->fnDecl->id) == funcReturnMap.end())
                funcReturnMap.emplace(*v->u.fnDeclStmt->fnDecl->id, std::move(type));
            vector<TempDef> args;
            for (const auto &decl : v->u.fnDeclStmt->fnDecl->paramDecl->varDecls)
            {
                if (decl->kind == A_varDeclScalarKind)
                {
                    if (decl->u.declScalar->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR, 0, *decl->u.declScalar->type->u.structType);
                        args.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_TEMP, 0);
                        args.push_back(def);
                    }
                }
                else if (decl->kind == A_varDeclArrayKind)
                {
                    if (decl->u.declArray->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR, -1, *decl->u.declArray->type->u.structType);
                        args.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_PTR, -1);
                        args.push_back(def);
                    }
                }
                else
                {
                    assert(0);
                }
            }
            defs.push_back(L_Funcdecl(*v->u.fnDeclStmt->fnDecl->id, args, type));
            break;
        }
        case A_programFnDefKind:
        {
            if (funcReturnMap.find(*v->u.fnDef->fnDecl->id) == funcReturnMap.end())
            {
                FuncType type;
                if (v->u.fnDef->fnDecl->type == nullptr)
                {
                    type.type = ReturnType::VOID_TYPE;
                }
                else if (v->u.fnDef->fnDecl->type->type == A_nativeTypeKind)
                {
                    type.type = ReturnType::INT_TYPE;
                }
                else if (v->u.fnDef->fnDecl->type->type == A_structTypeKind)
                {
                    type.type = ReturnType::STRUCT_TYPE;
                    type.structname = *v->u.fnDef->fnDecl->type->u.structType;
                }
                else
                {
                    assert(0);
                }
                funcReturnMap.emplace(*v->u.fnDef->fnDecl->id, std::move(type));
            }
            break;
        }
        default:
            assert(0);
            break;
        }
    }
    return defs;
}

std::vector<Func_local *> ast2llvmProg_second(aA_program p)
{
    vector<Func_local *> funcs;
    for (const auto &v : p->programElements)
    {
        switch (v->kind)
        {
        case A_programNullStmtKind:
        {
            break;
        }
        case A_programVarDeclStmtKind:
        {
            break;
        }
        case A_programStructDefKind:
        {
            break;
        }
        case A_programFnDeclStmtKind:
        {
            break;
        }
        case A_programFnDefKind:
        {
            funcs.push_back(ast2llvmFunc(v->u.fnDef));
            emit_irs.clear();
            localVarMap.clear();
            break;
        }
        default:
            assert(0);
            break;
        }
    }
    return funcs;
}

Func_local *ast2llvmFunc(aA_fnDef f)
{
    vector<Temp_temp *> args;
    Temp_temp *arg;
    emit_irs.push_back(L_Label(Temp_newlabel_named(*f->fnDecl->id)));
    // 首先创建参数的中间表示寄存器列表，然后依次处理每个参数声明，检查其类型并分配相应的临时寄存器。
    for (const auto &p : f->fnDecl->paramDecl->varDecls)
    {
        if (p->kind == A_varDeclType::A_varDeclScalarKind)
        {
            if (p->u.declScalar->type->type == A_dataType::A_nativeTypeKind)
            {
                arg = Temp_newtemp_int();
                args.push_back(arg);
                Temp_temp *var = Temp_newtemp_int_ptr(0);
                localVarMap.emplace(*p->u.declScalar->id, var);
                AS_operand *dst = AS_Operand_Temp(var);
                emit_irs.push_back(L_Alloca(dst));
                emit_irs.push_back(L_Store(AS_Operand_Temp(arg), dst));
            }
            else if (p->u.declScalar->type->type == A_dataType::A_structTypeKind)
            {
                arg = Temp_newtemp_struct_ptr(0, *p->u.declScalar->type->u.structType);
                args.push_back(arg);
                localVarMap.emplace(*p->u.declScalar->id, arg);
            }
            else
                assert(0);
        }
        else if (p->kind == A_varDeclType::A_varDeclArrayKind)
        {
            if (p->u.declArray->type->type == A_dataType::A_nativeTypeKind)
            {
                arg = Temp_newtemp_int_ptr(-1);
                args.push_back(arg);
                localVarMap.emplace(*p->u.declArray->id, arg);
            }
            else if (p->u.declArray->type->type == A_dataType::A_structTypeKind)
            {
                arg = Temp_newtemp_struct_ptr(-1, *p->u.declArray->type->u.structType);
                args.push_back(arg);
                localVarMap.emplace(*p->u.declArray->id, arg);
            }
            else
                assert(0);
        }
        else
            assert(0);
    }

    ast2llvmBlockList(f->stmts, nullptr, nullptr); // 处理函数体的语句块

    // 如果最后没有返回语句，函数会依据返回类型生成默认返回。
    if (emit_irs.back()->type != L_StmKind::T_RETURN)
    {
        if (funcReturnMap[*f->fnDecl->id].type == ReturnType::VOID_TYPE)
            emit_irs.push_back(L_Ret(nullptr));
        else
            emit_irs.push_back(L_Ret(AS_Operand_Const(0)));
    }

    return new Func_local(*f->fnDecl->id, funcReturnMap[*f->fnDecl->id], args, emit_irs);
}

void ast2llvmBoolUOpExpr(aA_boolUOpExpr b, Temp_label *true_label, Temp_label *false_label)
{
    ast2llvmBoolUnit(b->cond, false_label, true_label);
}

void ast2llvmBlock(aA_codeBlockStmt b, Temp_label *con_label, Temp_label *bre_label)
{
    switch (b->kind)
    {
    case A_codeBlockStmtType::A_assignStmtKind:
    {
        // 处理赋值语句，将右值转换为LLVM IR操作数并存储到左值位置
        AS_operand *r = ast2llvmRightVal(b->u.assignStmt->rightVal);
        AS_operand *l = ast2llvmLeftVal(b->u.assignStmt->leftVal);
        emit_irs.push_back(L_Store(r, l));
        break;
    }
    case A_codeBlockStmtType::A_breakStmtKind:
    {
        // 处理break语句，跳转到循环的结束标签
        assert(bre_label);
        emit_irs.push_back(L_Jump(bre_label));
        break;
    }
    case A_codeBlockStmtType::A_callStmtKind:
    {
        // 处理函数调用语句，将函数名和参数转化为LLVM IR格式
        string funcName = *b->u.callStmt->fnCall->fn;
        vector<AS_operand *> args;
        for (const auto &val : b->u.callStmt->fnCall->vals)
        {
            args.push_back(ast2llvmRightVal(val));
        }
        if (funcReturnMap.find(funcName) != funcReturnMap.end())
        {
            emit_irs.push_back(L_Voidcall(funcName, args));
        }
        else
            assert(0);
        break;
    }
    case A_codeBlockStmtType::A_continueStmtKind:
    {
        // 处理continue语句，跳转到循环的继续标签
        assert(con_label);
        emit_irs.push_back(L_Jump(con_label));
        break;
    }
    case A_codeBlockStmtType::A_ifStmtKind:
    {
        // 处理if语句，设置布尔条件并分别跳转到if分支和else分支(内部递归)
        Temp_label *if_label = Temp_newlabel();
        Temp_label *else_label = Temp_newlabel();
        Temp_label *after_label = Temp_newlabel();
        ast2llvmBoolUnit(b->u.ifStmt->boolUnit, if_label, else_label);
        emit_irs.push_back(L_Label(if_label));
        ast2llvmBlockList(b->u.ifStmt->ifStmts, con_label, bre_label);
        emit_irs.push_back(L_Jump(after_label));
        emit_irs.push_back(L_Label(else_label));
        ast2llvmBlockList(b->u.ifStmt->elseStmts, con_label, bre_label);
        emit_irs.push_back(L_Jump(after_label));
        emit_irs.push_back(L_Label(after_label));
        break;
    }
    case A_codeBlockStmtType::A_returnStmtKind:
    {
        emit_irs.push_back(L_Ret(ast2llvmRightVal(b->u.returnStmt->retVal)));
        break;
    }
    case A_codeBlockStmtType::A_varDeclStmtKind:
    {
        // 处理变量声明，包括标量和数组类型
        if (b->u.varDeclStmt->kind == A_varDeclStmtType::A_varDeclKind)
        {
            if (b->u.varDeclStmt->u.varDecl->kind == A_varDeclType::A_varDeclScalarKind)
            {
                string id = *b->u.varDeclStmt->u.varDecl->u.declScalar->id;
                Temp_temp *var;
                if (b->u.varDeclStmt->u.varDecl->u.declScalar->type->type == A_dataType::A_nativeTypeKind)
                {
                    var = Temp_newtemp_int_ptr(0);
                    if (localVarMap.find(id) != localVarMap.end())
                        localVarMap[id] = var;
                    else
                        localVarMap.emplace(id, var);
                    emit_irs.push_back(L_Alloca(AS_Operand_Temp(var)));
                }
                else if (b->u.varDeclStmt->u.varDecl->u.declScalar->type->type == A_dataType::A_structTypeKind)
                {
                    var = Temp_newtemp_struct_ptr(0, *b->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType);
                    if (localVarMap.find(id) != localVarMap.end())
                        localVarMap[id] = var;
                    else
                        localVarMap.emplace(id, var);
                    emit_irs.push_back(L_Alloca(AS_Operand_Temp(var)));
                }
            }
            else if (b->u.varDeclStmt->u.varDecl->kind == A_varDeclType::A_varDeclArrayKind)
            {
                int len = b->u.varDeclStmt->u.varDecl->u.declArray->len;
                string id = *b->u.varDeclStmt->u.varDecl->u.declArray->id;
                Temp_temp *var;
                if (b->u.varDeclStmt->u.varDecl->u.declArray->type->type == A_dataType::A_nativeTypeKind)
                {
                    var = Temp_newtemp_int_ptr(len);
                    if (localVarMap.find(id) != localVarMap.end())
                        localVarMap[id] = var;
                    else
                        localVarMap.emplace(id, var);
                    emit_irs.push_back(L_Alloca(AS_Operand_Temp(var)));
                }
                else if (b->u.varDeclStmt->u.varDecl->u.declArray->type->type == A_dataType::A_structTypeKind)
                {
                    var = Temp_newtemp_struct_ptr(len, *b->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType);
                    if (localVarMap.find(id) != localVarMap.end())
                        localVarMap[id] = var;
                    else
                        localVarMap.emplace(id, var);
                    emit_irs.push_back(L_Alloca(AS_Operand_Temp(var)));
                }
            }
        }
        else if (b->u.varDeclStmt->kind == A_varDeclStmtType::A_varDefKind)
        {
            if (b->u.varDeclStmt->u.varDef->kind == A_varDefType::A_varDefScalarKind)
            {
                string id = *b->u.varDeclStmt->u.varDef->u.defScalar->id;
                aA_rightVal val = b->u.varDeclStmt->u.varDef->u.defScalar->val;
                Temp_temp *var;
                AS_operand *dst;
                if (b->u.varDeclStmt->u.varDef->u.defScalar->type->type == A_dataType::A_nativeTypeKind)
                {
                    var = Temp_newtemp_int_ptr(0);
                    if (localVarMap.find(id) != localVarMap.end())
                        localVarMap[id] = var;
                    else
                        localVarMap.emplace(id, var);
                    dst = AS_Operand_Temp(var);
                    emit_irs.push_back(L_Alloca(dst));
                    emit_irs.push_back(L_Store(ast2llvmRightVal(val), dst));
                }
                else if (b->u.varDeclStmt->u.varDef->u.defScalar->type->type == A_dataType::A_structTypeKind)
                {
                    var = Temp_newtemp_struct_ptr(0, *b->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType);
                    if (localVarMap.find(id) != localVarMap.end())
                        localVarMap[id] = var;
                    else
                        localVarMap.emplace(id, var);
                    dst = AS_Operand_Temp(var);
                    emit_irs.push_back(L_Alloca(dst));
                    // emit_irs.push_back(L_Store(ast2llvmRightVal(val),dst));
                }
            }
            else if (b->u.varDeclStmt->u.varDef->kind == A_varDefType::A_varDefArrayKind)
            {
                string id = *b->u.varDeclStmt->u.varDef->u.defArray->id;
                int len = b->u.varDeclStmt->u.varDef->u.defArray->len;
                vector<aA_rightVal> vals = b->u.varDeclStmt->u.varDef->u.defArray->vals;
                Temp_temp *var;
                AS_operand *base;
                if (b->u.varDeclStmt->u.varDef->u.defArray->type->type == A_dataType::A_nativeTypeKind)
                {
                    var = Temp_newtemp_int_ptr(len);
                    if (localVarMap.find(id) != localVarMap.end())
                        localVarMap[id] = var;
                    else
                        localVarMap.emplace(id, var);
                    base = AS_Operand_Temp(var);
                    emit_irs.push_back(L_Alloca(base));
                    for (int i = 0; i < len; i++)
                    {
                        var = Temp_newtemp_int_ptr(0);
                        AS_operand *target = AS_Operand_Temp(var);
                        emit_irs.push_back(L_Gep(target, base, AS_Operand_Const(i)));
                        emit_irs.push_back(L_Store(ast2llvmRightVal(vals[i]), target));
                    }
                }
                else if (b->u.varDeclStmt->u.varDef->u.defArray->type->type == A_dataType::A_structTypeKind)
                {
                    var = Temp_newtemp_struct_ptr(len, *b->u.varDeclStmt->u.varDef->u.defArray->type->u.structType);
                    if (localVarMap.find(id) != localVarMap.end())
                        localVarMap[id] = var;
                    else
                        localVarMap.emplace(id, var);
                    base = AS_Operand_Temp(var);
                    emit_irs.push_back(L_Alloca(base));
                    for (int i = 0; i < len; i++)
                    {
                        var = Temp_newtemp_struct_ptr(0, *b->u.varDeclStmt->u.varDef->u.defArray->type->u.structType);
                        AS_operand *target = AS_Operand_Temp(var);
                        emit_irs.push_back(L_Gep(target, base, AS_Operand_Const(i)));
                    }
                }
            }
        }
        break;
    }
    case A_codeBlockStmtType::A_whileStmtKind:
    {
        Temp_label *while_label = Temp_newlabel();
        emit_irs.push_back(L_Jump(while_label));
        emit_irs.push_back(L_Label(while_label));
        Temp_label *codeblock_label = Temp_newlabel();
        Temp_label *break_label = Temp_newlabel();
        ast2llvmBoolUnit(b->u.whileStmt->boolUnit, codeblock_label, break_label);
        emit_irs.push_back(L_Label(codeblock_label));
        ast2llvmBlockList(b->u.whileStmt->whileStmts, while_label, break_label);
        emit_irs.push_back(L_Jump(while_label));
        emit_irs.push_back(L_Label(break_label));
    }
    break;
    default:
        break;
    }
}

// 将AST中的右值表达式转换为LLVM IR中的操作数
AS_operand *ast2llvmRightVal(aA_rightVal r)
{
    // 检查右值是否为空，如果为空则直接返回nullptr
    if (r == nullptr)
        return nullptr;

    // 如果右值是算术表达式类型
    if (r->kind == A_rightValType::A_arithExprValKind)
    {
        // 递归调用将算术表达式转换为LLVM操作数
        return ast2llvmArithExpr(r->u.arithExpr);
    }
    // 如果右值是布尔表达式类型
    else if (r->kind == A_rightValType::A_boolExprValKind)
    {
        // 创建新的标签用于布尔表达式的分支跳转
        Temp_label *true_label = Temp_newlabel();
        Temp_label *false_label = Temp_newlabel();
        Temp_label *after_label = Temp_newlabel();

        // 分配一个寄存器来存储布尔表达式的值（0或1）
        AS_operand *bool_var = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
        emit_irs.push_back(L_Alloca(bool_var));

        // 生成布尔表达式的LLVM IR代码，并根据结果跳转到true_label或false_label
        ast2llvmBoolExpr(r->u.boolExpr, true_label, false_label);

        // true_label: 如果布尔表达式为真，存储1到bool_var
        emit_irs.push_back(L_Label(true_label));
        emit_irs.push_back(L_Store(AS_Operand_Const(1), bool_var));
        emit_irs.push_back(L_Jump(after_label));

        // false_label: 如果布尔表达式为假，存储0到bool_var
        emit_irs.push_back(L_Label(false_label));
        emit_irs.push_back(L_Store(AS_Operand_Const(0), bool_var));
        emit_irs.push_back(L_Jump(after_label));

        // after_label: 加载bool_var的值作为返回的结果
        emit_irs.push_back(L_Label(after_label));
        AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
        emit_irs.push_back(L_Load(res, bool_var));

        // 返回表示布尔表达式结果的LLVM操作数
        return res;
    }
    else
        // 如果右值类型未知，则触发断言
        assert(0);
}

// 将AST中的左值表达式转换为LLVM IR中的操作数
AS_operand *ast2llvmLeftVal(aA_leftVal l)
{
    // 如果左值是变量类型
    if (l->kind == A_leftValType::A_varValKind)
    {
        // 获取变量名
        string id = *l->u.id;

        // 如果变量是局部变量
        if (localVarMap.find(id) != localVarMap.end())
        {
            // 返回局部变量对应的寄存器
            return AS_Operand_Temp(localVarMap[id]);
        }
        // 如果变量是全局变量
        else if (globalVarMap.find(id) != globalVarMap.end())
        {
            // 返回全局变量对应的名字操作数
            return AS_Operand_Name(globalVarMap[id]);
        }
        else
            // 如果变量未定义，则触发断言
            assert(0);
    }
    // 如果左值是数组类型
    else if (l->kind == A_leftValType::A_arrValKind)
    {
        // 计算数组索引表达式的LLVM操作数
        AS_operand *index = ast2llvmIndexExpr(l->u.arrExpr->idx);

        // 获取数组的基地址操作数
        AS_operand *arr = ast2llvmLeftVal(l->u.arrExpr->arr);
        AS_operand *res;

        // 如果数组基地址是全局变量
        if (arr->kind == OperandKind::NAME)
        {
            // 根据变量类型分配合适的寄存器
            if (arr->u.NAME->type == TempType::INT_PTR)
            {
                res = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
            }
            else if (arr->u.NAME->type == TempType::STRUCT_PTR)
            {
                res = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, arr->u.NAME->structname));
            }
            else
                assert(0);
        }
        // 如果数组基地址是寄存器
        else if (arr->kind == OperandKind::TEMP)
        {
            if (arr->u.TEMP->type == TempType::INT_PTR)
            {
                res = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
            }
            else if (arr->u.TEMP->type == TempType::STRUCT_PTR)
            {
                res = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, arr->u.TEMP->structname));
            }
            else
                assert(0);
        }
        else
            assert(0);

        // 生成GEP，用于数组索引操作
        emit_irs.push_back(L_Gep(res, arr, index));
        return res;
    }
    // 如果左值是结构体成员类型
    else if (l->kind == A_leftValType::A_memberValKind)
    {
        // 获取结构体的基地址操作数
        AS_operand *base = ast2llvmLeftVal(l->u.memberExpr->structId);
        AS_operand *res;
        AS_operand *index;

        // 如果基地址是全局变量（名字操作数）
        if (base->kind == OperandKind::NAME)
        {
            // 获取成员的偏移量和定义
            int offset = structInfoMap[base->u.NAME->structname].memberinfos[*l->u.memberExpr->memberId].offset;
            index = AS_Operand_Const(offset);
            TempDef def = structInfoMap[base->u.NAME->structname].memberinfos[*l->u.memberExpr->memberId].def;

            // 根据成员类型分配合适的寄存器
            if (base->u.NAME->type == TempType::STRUCT_TEMP)
            {
                if (def.kind == TempType::INT_TEMP)
                {
                    res = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
                }
                else if (def.kind == TempType::INT_PTR)
                {
                    res = AS_Operand_Temp(Temp_newtemp_int_ptr(def.len));
                }
                else if (def.kind == TempType::STRUCT_TEMP)
                {
                    res = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, def.structname));
                }
                else if (def.kind == TempType::STRUCT_PTR)
                {
                    res = AS_Operand_Temp(Temp_newtemp_struct_ptr(def.len, def.structname));
                }
                else
                    assert(0);
            }
            else
                assert(0);
        }
        // 如果基地址是寄存器
        else if (base->kind == OperandKind::TEMP)
        {
            int offset = structInfoMap[base->u.TEMP->structname].memberinfos[*l->u.memberExpr->memberId].offset;
            index = AS_Operand_Const(offset);
            TempDef def = structInfoMap[base->u.TEMP->structname].memberinfos[*l->u.memberExpr->memberId].def;

            // 根据成员类型分配合适的寄存器
            if (base->u.TEMP->type == TempType::STRUCT_PTR && base->u.TEMP->len == 0)
            {
                if (def.kind == TempType::INT_TEMP)
                {
                    res = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
                }
                else if (def.kind == TempType::INT_PTR)
                {
                    res = AS_Operand_Temp(Temp_newtemp_int_ptr(def.len));
                }
                else if (def.kind == TempType::STRUCT_TEMP)
                {
                    res = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, def.structname));
                }
                else if (def.kind == TempType::STRUCT_PTR)
                {
                    res = AS_Operand_Temp(Temp_newtemp_struct_ptr(def.len, def.structname));
                }
                else
                    assert(0);
            }
            else
                assert(0);
        }
        else
            assert(0);

        // 生成GEP指令，用于访问结构体成员
        emit_irs.push_back(L_Gep(res, base, index));
        return res;
    }

    // 如果左值类型不符合任何已知类型，则触发断言
    assert(0);
}

// 将AST中的方括号定义转换为LLVM IR中的操作数
AS_operand *ast2llvmIndexExpr(aA_indexExpr index)
{
    // 如果索引是一个数字
    if (index->kind == A_indexExprKind::A_numIndexKind)
    {
        // 直接返回数字常量
        return AS_Operand_Const(index->u.num);
    }
    // 如果索引是一个标识符
    else if (index->kind == A_indexExprKind::A_idIndexKind)
    {
        // 获取标识符的名称
        string id = *index->u.id;

        // 查找标识符是否在局部变量映射中
        if (localVarMap.find(id) != localVarMap.end())
        {
            // 创建一个新的整数寄存器
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
            // 获取局部变量对应的寄存器
            AS_operand *mid = AS_Operand_Temp(localVarMap[id]);

            // 如果局部变量是整数类型，则直接返回
            if (localVarMap[id]->type == TempType::INT_TEMP)
            {
                return mid;
            }

            // 如果不是整数类型，则加载其值到新寄存器并返回
            emit_irs.push_back(L_Load(res, mid));
            return res;
        }
        // 如果标识符在全局变量映射中
        else if (globalVarMap.find(id) != globalVarMap.end())
        {
            // 创建一个新的整数寄存器
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());

            // 加载全局变量的值到新寄存器
            emit_irs.push_back(L_Load(res, AS_Operand_Name(globalVarMap[id])));
            return res;
        }
        else
            // 如果标识符未定义，则触发断言
            assert(0);
    }
    else
    {
        // 如果索引表达式类型不符合任何已知类型，则触发断言
        assert(0);
    }
}

AS_operand *ast2llvmBoolExpr(aA_boolExpr b, Temp_label *true_label, Temp_label *false_label)
{
    assert(true_label && false_label);
    if (b->kind == A_boolExprType::A_boolBiOpExprKind)
    {
        ast2llvmBoolBiOpExpr(b->u.boolBiOpExpr, true_label, false_label);
    }
    else if (b->kind == A_boolExprType::A_boolUnitKind)
    {
        ast2llvmBoolUnit(b->u.boolUnit, true_label, false_label);
    }
    else
        assert(0);
    return nullptr;
}

void ast2llvmBoolBiOpExpr(aA_boolBiOpExpr b, Temp_label *true_label, Temp_label *false_label)
{
    Temp_label *right_label = Temp_newlabel();
    switch (b->op)
    {
    case A_boolBiOp::A_and:
        ast2llvmBoolExpr(b->left, right_label, false_label);
        break;
    case A_boolBiOp::A_or:
        ast2llvmBoolExpr(b->left, true_label, right_label);
        break;
    default:
        assert(0);
    }
    emit_irs.push_back(L_Label(right_label));
    ast2llvmBoolExpr(b->right, true_label, false_label);
}

void ast2llvmBoolUnit(aA_boolUnit b, Temp_label *true_label, Temp_label *false_label)
{
    switch (b->kind)
    {
    case A_boolUnitType::A_boolExprKind:
        ast2llvmBoolExpr(b->u.boolExpr, true_label, false_label);
        break;
    case A_boolUnitType::A_boolUOpExprKind:
        ast2llvmBoolUOpExpr(b->u.boolUOpExpr, true_label, false_label);
        break;
    case A_boolUnitType::A_comOpExprKind:
        ast2llvmComOpExpr(b->u.comExpr, true_label, false_label);
        break;
    default:
        assert(0);
    }
}

void ast2llvmComOpExpr(aA_comExpr c, Temp_label *true_label, Temp_label *false_label)
{
    AS_operand *leftexpr = ast2llvmExprUnit(c->left);
    AS_operand *rightexpr = ast2llvmExprUnit(c->right);
    L_relopKind op;
    AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
    switch (c->op)
    {
    case A_comOp::A_lt:
        op = L_relopKind::T_lt;
        break;
    case A_comOp::A_le:
        op = L_relopKind::T_le;
        break;
    case A_comOp::A_gt:
        op = L_relopKind::T_gt;
        break;
    case A_comOp::A_ge:
        op = L_relopKind::T_ge;
        break;
    case A_comOp::A_eq:
        op = L_relopKind::T_eq;
        break;
    case A_comOp::A_ne:
        op = L_relopKind::T_ne;
        break;
    default:
        assert(0);
    }
    emit_irs.push_back(L_Cmp(op, leftexpr, rightexpr, res));
    emit_irs.push_back(L_Cjump(res, true_label, false_label));
}

AS_operand *ast2llvmArithBiOpExpr(aA_arithBiOpExpr a)
{
    AS_operand *l = ast2llvmArithExpr(a->left);
    AS_operand *r = ast2llvmArithExpr(a->right);
    AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());
    switch (a->op)
    {
    case A_add:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_plus, l, r, dst));
        return dst;
        break;
    }
    case A_sub:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_minus, l, r, dst));
        return dst;
        break;
    }
    case A_mul:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_mul, l, r, dst));
        return dst;
        break;
    }
    case A_div:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_div, l, r, dst));
        return dst;
        break;
    }
    default:
        assert(0);
        break;
    }
}

AS_operand *ast2llvmArithUExpr(aA_arithUExpr a)
{
    AS_operand *expr = ast2llvmExprUnit(a->expr);
    if (a->op == A_neg)
    {
        Temp_temp *temp = Temp_newtemp_int();
        AS_operand *dst = AS_Operand_Temp(temp);
        emit_irs.push_back(L_Binop(L_binopKind::T_minus, AS_Operand_Const(0), expr, dst));
        return dst;
    }
    assert(0);
}

AS_operand *ast2llvmArithExpr(aA_arithExpr a)
{
    if (a->kind == A_arithExprType::A_arithBiOpExprKind)
    {
        return ast2llvmArithBiOpExpr(a->u.arithBiOpExpr);
    }
    else if (a->kind == A_arithExprType::A_exprUnitKind)
    {
        return ast2llvmExprUnit(a->u.exprUnit);
    }
    else
        assert(0);
}

AS_operand *ast2llvmExprUnit(aA_exprUnit e)
{
    if (e->kind == A_exprUnitType::A_arithExprKind)
    {
        return ast2llvmArithExpr(e->u.arithExpr);
    }
    else if (e->kind == A_exprUnitType::A_arithUExprKind)
    {
        return ast2llvmArithUExpr(e->u.arithUExpr);
    }
    else if (e->kind == A_exprUnitType::A_arrayExprKind)
    {
        AS_operand *index = ast2llvmIndexExpr(e->u.arrayExpr->idx);
        AS_operand *base = ast2llvmLeftVal(e->u.arrayExpr->arr);
        AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
        AS_operand *mid = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
        emit_irs.push_back(L_Gep(mid, base, index));
        emit_irs.push_back(L_Load(res, mid));
        return res;
    }
    else if (e->kind == A_exprUnitType::A_fnCallKind)
    {
        if (funcReturnMap.find(*e->u.callExpr->fn) != funcReturnMap.end())
        {
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
            vector<AS_operand *> args;
            for (auto val : e->u.callExpr->vals)
            {
                args.push_back(ast2llvmRightVal(val));
            }
            emit_irs.push_back(L_Call(*e->u.callExpr->fn, res, args));
            return res;
        }
        else
            assert(0);
    }
    else if (e->kind == A_exprUnitType::A_idExprKind)
    {
        if (localVarMap.find(*e->u.id) != localVarMap.end())
        {
            AS_operand *temp = AS_Operand_Temp(localVarMap[*e->u.id]);
            if (localVarMap[*e->u.id]->type == TempType::INT_PTR && localVarMap[*e->u.id]->len == 0)
            {
                AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
                emit_irs.push_back(L_Load(res, temp));
                return res;
            }
            else
                return temp;
        }
        else if (globalVarMap.find(*e->u.id) != globalVarMap.end())
        {
            AS_operand *temp = AS_Operand_Name(globalVarMap[*e->u.id]);
            if (globalVarMap[*e->u.id]->type == TempType::INT_TEMP)
            {
                AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
                emit_irs.push_back(L_Load(res, temp));
                return res;
            }
            else
            {
                return temp;
            }
        }
        else
            assert(0);
    }
    else if (e->kind == A_exprUnitType::A_memberExprKind)
    {
        AS_operand *struc = ast2llvmLeftVal(e->u.memberExpr->structId);
        AS_operand *mid = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
        AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
        if (struc->kind == OperandKind::NAME)
        {
            string structName = struc->u.NAME->structname;
            int offset = structInfoMap[structName].memberinfos[*e->u.memberExpr->memberId].offset;
            emit_irs.push_back(L_Gep(mid, struc, AS_Operand_Const(offset)));
            emit_irs.push_back(L_Load(res, mid));
            return res;
        }
        else if (struc->kind == OperandKind::TEMP)
        {
            string structName = struc->u.TEMP->structname;
            int offset = structInfoMap[structName].memberinfos[*e->u.memberExpr->memberId].offset;
            emit_irs.push_back(L_Gep(mid, struc, AS_Operand_Const(offset)));
            emit_irs.push_back(L_Load(res, mid));
            return res;
        }
        else
            assert(0);
    }
    else if (e->kind == A_exprUnitType::A_numExprKind)
    {
        return AS_Operand_Const(e->u.num);
    }
    else
        assert(0);
}

LLVMIR::L_func *ast2llvmFuncBlock(Func_local *f)
{
    list<L_block *> blocks;
    list<L_stm *> blockIr;
    for (auto ir : f->irs)
    {
        if (ir->type == L_StmKind::T_LABEL)
        {
            if (blockIr.size() > 0)
                blocks.push_back(L_Block(blockIr));
            blockIr.clear();
        }
        blockIr.push_back(ir);
    }
    if (blockIr.size() > 0)
        blocks.push_back(L_Block(blockIr));
    return new L_func(f->name, f->ret, f->args, blocks);
}

void ast2llvm_moveAlloca(LLVMIR::L_func *f)
{
    auto first_block = f->blocks.front();
    for (auto i = ++f->blocks.begin(); i != f->blocks.end(); ++i)
    {
        for (auto it = (*i)->instrs.begin(); it != (*i)->instrs.end();)
        {
            if ((*it)->type == L_StmKind::T_ALLOCA)
            {
                first_block->instrs.insert(++first_block->instrs.begin(), *it);
                it = (*i)->instrs.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}