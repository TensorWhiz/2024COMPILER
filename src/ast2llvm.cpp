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
            if (v->u.varDeclStmt->kind == A_varDeclKind) // 处理变量decl
            {
                if (v->u.varDeclStmt->u.varDecl->kind == A_varDeclScalarKind) // 标量
                {
                    if (v->u.varDeclStmt->u.varDecl->u.declScalar->type->type == A_structTypeKind) // 结构体
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                                             Name_newname_struct(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declScalar->id), *v->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType));
                        TempDef def(TempType::STRUCT_TEMP, 0, *v->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id, def, vector<int>()));
                    }
                    else // int
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                                             Name_newname_int(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declScalar->id)));
                        TempDef def(TempType::INT_TEMP, 0);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id, def, vector<int>()));
                    }
                }
                else if (v->u.varDeclStmt->u.varDecl->kind == A_varDeclArrayKind)
                {
                    if (v->u.varDeclStmt->u.varDecl->u.declArray->type->type == A_structTypeKind) // 结构体数组
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                                             Name_newname_struct_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declArray->id), v->u.varDeclStmt->u.varDecl->u.declArray->len, *v->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType));
                        TempDef def(TempType::STRUCT_PTR, v->u.varDeclStmt->u.varDecl->u.declArray->len, *v->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id, def, vector<int>()));
                    }
                    else // int数组
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
            else if (v->u.varDeclStmt->kind == A_varDefKind) // 处理变量decl+def
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
    emit_irs.clear();
    localVarMap.clear();
    string name = *f->fnDecl->id;
    label(Temp_newlabel_named(name));

    vector<Temp_temp *> args;
    for (auto &decl : f->fnDecl->paramDecl->varDecls)
    {
        if (decl->kind == A_varDeclType::A_varDeclScalarKind)
        {

            if (decl->u.declScalar->type->type == A_dataType::A_nativeTypeKind)
            {
                Temp_temp *arg = Temp_newtemp_int();
                args.push_back(arg);
                Temp_temp *temp_ptr = Temp_newtemp_int_ptr(0);
                AS_operand *arg_ptr = AS_Operand_Temp(temp_ptr);
                emit_irs.push_back(L_Alloca(arg_ptr));
                store(AS_Operand_Temp(arg), arg_ptr);
                localVarMap.emplace(*decl->u.declScalar->id, temp_ptr);
            }
            else // struct
            {
                Temp_temp *temp = Temp_newtemp_struct_ptr(0, *decl->u.declScalar->type->u.structType);
                args.push_back(temp);
                localVarMap.emplace(*decl->u.declScalar->id, temp);
            }
        }
        else if (decl->kind == A_varDeclType::A_varDeclArrayKind) // 数组
        {
            if (decl->u.declArray->type->type == A_dataType::A_nativeTypeKind)
            {
                // int
                Temp_temp *temp = Temp_newtemp_int_ptr(-1);
                args.push_back(temp);
                localVarMap.emplace(*decl->u.declArray->id, temp);
            }
            else
            {
                // struct
                Temp_temp *temp = Temp_newtemp_struct_ptr(-1, *decl->u.declArray->type->u.structType);
                args.push_back(temp);
                localVarMap.emplace(*decl->u.declArray->id, temp);
            }
        }
        else
            assert(0);
    }



    // 处理函数体的语句块
    for (auto &stmt : f->stmts)
    {
        ast2llvmBlock(stmt, nullptr, nullptr);
        if (stmt->kind == A_codeBlockStmtType::A_returnStmtKind)
            break;
    }

    // 如果最后没有返回语句，函数会依据返回类型生成默认返回。
    if (emit_irs.back()->type != L_StmKind::T_RETURN)
    {
        if (funcReturnMap[*f->fnDecl->id].type == ReturnType::VOID_TYPE)
            emit_irs.push_back(L_Ret(nullptr));
        else
            emit_irs.push_back(L_Ret(AS_Operand_Const(0)));
    }

    FuncType ret = funcReturnMap[name];

    return new Func_local(name, ret, args, emit_irs);
}

void ast2llvmBlock(aA_codeBlockStmt b, Temp_label *con_label, Temp_label *bre_label)
{
    switch (b->kind)
    {
    case A_codeBlockStmtType::A_nullStmtKind:
    {
        break;
    }
    case A_codeBlockStmtType::A_varDeclStmtKind:
    {
        ast2llvmStmtvarDecl(b->u.varDeclStmt);
        break;
    }
    case A_codeBlockStmtType::A_assignStmtKind:
    {
        ast2llvmStmtassign(b->u.assignStmt);
        break;
    }
    case A_codeBlockStmtType::A_callStmtKind:
    {
        ast2llvmStmtcall(b->u.callStmt);
        break;
    }
    case A_codeBlockStmtType::A_ifStmtKind:
    {
        ast2llvmStmtif(b->u.ifStmt, con_label, bre_label);
        break;
    }
    case A_codeBlockStmtType::A_whileStmtKind:
    {
        ast2llvmStmtwhile(b->u.whileStmt);
        break;
    }
    case A_codeBlockStmtType::A_returnStmtKind:
    {
        ast2llvmStmtreturn(b->u.returnStmt);
        break;
    }
    case A_codeBlockStmtType::A_continueStmtKind:
    {
        jump(con_label);
        break;
    }
    case A_codeBlockStmtType::A_breakStmtKind:
    {
        jump(bre_label);
        break;
    }
    default:
        assert(0);
    }
}

void ast2llvmStmtvarDecl(aA_varDeclStmt s)
{
    if (s->kind == A_varDeclKind)
    {
        if (s->u.varDecl->kind == A_varDeclScalarKind)
        {
            aA_varDeclScalar varDeclScalar = s->u.varDecl->u.declScalar;
            if (varDeclScalar->type == nullptr)
            {
                Temp_temp *temp = Temp_newtemp_int_ptr(0);
                localVarMap.emplace(*varDeclScalar->id, temp);
                emit_irs.push_back(L_Alloca(AS_Operand_Temp(temp)));
            }
            else if (varDeclScalar->type->type == A_structTypeKind)
            {
                Temp_temp *temp = Temp_newtemp_struct_ptr(0, *varDeclScalar->type->u.structType);
                localVarMap.emplace(*varDeclScalar->id, temp);
                emit_irs.push_back(L_Alloca(AS_Operand_Temp(temp)));
            }
            else if (varDeclScalar->type->type == A_dataType::A_nativeTypeKind)
            {
                Temp_temp *temp = Temp_newtemp_int_ptr(0);
                // if (localVarMap.find(id) != localVarMap.end())
                //         localVarMap[id] = var;
                //     else
                localVarMap.emplace(*varDeclScalar->id, temp);
                emit_irs.push_back(L_Alloca(AS_Operand_Temp(temp)));
                ;
            }
            else
                assert(0);
        }
        else if (s->u.varDecl->kind == A_varDeclArrayKind)
        {
            aA_varDeclArray varDeclArray = s->u.varDecl->u.declArray;
            if (varDeclArray->type->type == A_structTypeKind)
            {
                Temp_temp *temp = Temp_newtemp_struct_ptr(varDeclArray->len, *varDeclArray->type->u.structType);
                localVarMap.emplace(*varDeclArray->id, temp);
                emit_irs.push_back(L_Alloca(AS_Operand_Temp(temp)));
            }
            else if (varDeclArray->type->type == A_nativeTypeKind)
            {
                Temp_temp *temp = Temp_newtemp_int_ptr(varDeclArray->len);
                localVarMap.emplace(*varDeclArray->id, temp);
                emit_irs.push_back(L_Alloca(AS_Operand_Temp(temp)));
            }
            else
                assert(0);
        }
        else
            assert(0);
    }
    else if (s->kind == A_varDefKind)
    {
        if (s->u.varDef->kind == A_varDefScalarKind)
        {
            aA_varDefScalar varDefScalar = s->u.varDef->u.defScalar;
            aA_rightVal val = varDefScalar->val;
            Temp_temp *temp;
            AS_operand *dst;

            if (varDefScalar->type->type == A_nativeTypeKind)
            {
                temp = Temp_newtemp_int_ptr(0);
                dst = AS_Operand_Temp(temp);
                localVarMap.emplace(*varDefScalar->id, temp);
                emit_irs.push_back(L_Alloca(dst));
                emit_irs.push_back(L_Store(ast2llvmRightVal(val), dst));
            }
            else if (varDefScalar->type->type == A_structTypeKind)
            {
                // 只能一个一个个赋值
            }
            else
                assert(0);
        }
        else if (s->u.varDef->kind == A_varDefArrayKind)
        {
            aA_varDefArray varDefArray = s->u.varDef->u.defArray;
            if (varDefArray->type->type == A_nativeTypeKind)
            {
                Temp_temp *temp = Temp_newtemp_int_ptr(varDefArray->len);
                AS_operand *dst = AS_Operand_Temp(temp);
                localVarMap.emplace(*varDefArray->id, temp);
                emit_irs.push_back(L_Alloca(dst));
                AS_operand *base_ptr = dst;
                int i = 0;
                for (; i < varDefArray->len; i++)
                {
                    AS_operand *new_ptr = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
                    gep(new_ptr, base_ptr, AS_Operand_Const(i));
                    emit_irs.push_back(L_Store(ast2llvmRightVal(varDefArray->vals[i]), new_ptr));
                }
            }
            else if (varDefArray->type->type == A_dataType::A_structTypeKind)
            {
            }
            else
                assert(0);
        }
        else
            assert(0);
    }
}

void ast2llvmStmtassign(aA_assignStmt s)
{
    AS_operand *left = ast2llvmLeftVal(s->leftVal);
    AS_operand *right = ast2llvmRightVal(s->rightVal);
    emit_irs.push_back(L_Store(right, left));
}

void ast2llvmStmtcall(aA_callStmt s)
{
        string funcName = *s->fnCall->fn;
        vector<AS_operand *> args;
        for (const auto &val : s->fnCall->vals)
        {
            args.push_back(ast2llvmRightVal(val));
        }
        if (funcReturnMap.find(funcName) != funcReturnMap.end())
        {
            emit_irs.push_back(L_Voidcall(funcName, args));
        }
        else
            assert(0);
}

AS_operand *ast2llvmfnCall(aA_fnCall callExpr)
{
    if (funcReturnMap.find(*callExpr->fn) != funcReturnMap.end())
        {
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
            vector<AS_operand *> args;
            for (auto val : callExpr->vals)
            {
                args.push_back(ast2llvmRightVal(val));
            }
            emit_irs.push_back(L_Call(*callExpr->fn, res, args));
            return res;
        }
        else
            assert(0);
}

void ast2llvmStmtif(aA_ifStmt s, Temp_label *con_label, Temp_label *bre_label)
{
    string name = "if_" + to_string(s->pos->col) + "_" + to_string(s->pos->line);
    Temp_label *true_label = Temp_newlabel_named(name + "_true");
    Temp_label *false_label = Temp_newlabel_named(name + "_false");
    Temp_label *end_label = Temp_newlabel_named(name + "_end");
    ast2llvmBoolUnit(s->boolUnit, true_label, false_label);

    // 翻译if代码块
    label(true_label);
    for (int i = 0; i < s->ifStmts.size(); i++)
    {
        ast2llvmBlock(s->ifStmts[i], con_label, bre_label);
        if (s->ifStmts[i]->kind == A_codeBlockStmtType::A_returnStmtKind)
            break;
    }
    // 删除if代码块内的局部变量
    // for(int i = 0;i<ifVector.size();i++)
    //     localVarMap.erase(ifVector[i]);
    // ifVector.clear();
    jump(end_label);
    label(false_label);
    for (int i = 0; i < s->elseStmts.size(); i++)
    {
        ast2llvmBlock(s->elseStmts[i], con_label, bre_label);
        if (s->elseStmts[i]->kind == A_codeBlockStmtType::A_returnStmtKind)
            break;
    }
    // 删除if代码块内的局部变量
    // for(int i = 0;i<elseVector.size();i++)
    //     localVarMap.erase(elseVector[i]);
    // elseVector.clear();
    jump(end_label);
    label(end_label);
}

void ast2llvmStmtwhile(aA_whileStmt s)
{
    string name = "while_" + to_string(s->pos->col) + "_" + to_string(s->pos->line);
    Temp_label *new_con_label = Temp_newlabel_named(name + "_cond");
    Temp_label *new_bre_label = Temp_newlabel_named(name + "_bre");
    Temp_label *true_label = Temp_newlabel_named(name + "_whilestms");
    jump(new_con_label);
    label(new_con_label);
    ast2llvmBoolUnit(s->boolUnit, true_label, new_bre_label);

    label(true_label);
    for (int i = 0; i < s->whileStmts.size(); i++)
    {
        ast2llvmBlock(s->whileStmts[i], new_con_label, new_bre_label);
        if (s->whileStmts[i]->kind == A_codeBlockStmtType::A_returnStmtKind)
            break;
    }
    // for(int i = 0;i<whileVector.size();i++)
    //     localVarMap.erase(whileVector[i]);
    jump(new_con_label);
    label(new_bre_label);
}

void ast2llvmStmtreturn(aA_returnStmt s)
{
    emit_irs.push_back(L_Ret(ast2llvmRightVal(s->retVal)));
}

AS_operand *ast2llvmArray_1(aA_arrayExpr arrExpr)
{
    AS_operand *base_ptr = ast2llvmLeftVal(arrExpr->arr);
    AS_operand *index = ast2llvmIndexExpr(arrExpr->idx);
    AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
    AS_operand *mid = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
    gep(mid, base_ptr, index);
    load(res, mid);
    return res;
}

AS_operand *ast2llvmArray_2(aA_arrayExpr arrExpr)
{
    AS_operand *arr = ast2llvmLeftVal(arrExpr->arr);
    AS_operand *index = ast2llvmIndexExpr(arrExpr->idx);
    AS_operand *res;
    if (arr->kind == OperandKind::NAME)
    {
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
    gep(res, arr, index);
    return res;
}

AS_operand *ast2llvmMember_1(aA_memberExpr memberExpr)
{
    // 1. 确定base_ptr
    AS_operand *base_ptr = ast2llvmLeftVal(memberExpr->structId);
    AS_operand *mid = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
    AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
    if (base_ptr->kind == OperandKind::TEMP)
    {
        string structName = base_ptr->u.TEMP->structname;
        // 确定位置
        StructInfo structInfo = structInfoMap[structName];
        MemberInfo memberInfo = structInfo.memberinfos[*memberExpr->memberId];
        AS_operand *index = AS_Operand_Const(memberInfo.offset);

        gep(mid, base_ptr, index);
        load(res, mid);
    }
    else if (base_ptr->kind == OperandKind::NAME)
    {
        string structName = base_ptr->u.NAME->structname;

        StructInfo structInfo = structInfoMap[structName];
        MemberInfo memberInfo = structInfo.memberinfos[*memberExpr->memberId];
        AS_operand *index = AS_Operand_Const(memberInfo.offset);

        gep(mid, base_ptr, index);
        load(res, mid);
    }
    else
        assert(0);
    return res;
}

AS_operand *ast2llvmMember_2(aA_memberExpr memberExpr)
{
    AS_operand *base = ast2llvmLeftVal(memberExpr->structId);
    AS_operand *res;
    AS_operand *index;

    // 如果基地址是全局变量（名字操作数）
    if (base->kind == OperandKind::NAME)
    {
        // 获取成员的偏移量和定义
        int offset = structInfoMap[base->u.NAME->structname].memberinfos[*memberExpr->memberId].offset;
        index = AS_Operand_Const(offset);
        TempDef def = structInfoMap[base->u.NAME->structname].memberinfos[*memberExpr->memberId].def;

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
        int offset = structInfoMap[base->u.TEMP->structname].memberinfos[*memberExpr->memberId].offset;
        index = AS_Operand_Const(offset);
        TempDef def = structInfoMap[base->u.TEMP->structname].memberinfos[*memberExpr->memberId].def;

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

AS_operand *ast2llvmId_2(string id)
{
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

AS_operand *ast2llvmId_1(string id)
{
    if (localVarMap.find(id) != localVarMap.end())
    {
        AS_operand *temp = AS_Operand_Temp(localVarMap[id]);
        if (localVarMap[id]->type == TempType::INT_PTR && localVarMap[id]->len == 0)
        {
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
            emit_irs.push_back(L_Load(res, temp));
            return res;
        }
        else if (localVarMap[id]->type == TempType::INT_PTR && localVarMap[id]->len > 0)
        {
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_int_ptr(-1));
            AS_operand *index = AS_Operand_Const(0);
            gep(res, temp, index);
            return res;
        }
        else if(localVarMap[id]->type == TempType::STRUCT_PTR){
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_struct_ptr(-1, move(temp->u.TEMP->structname)));
            AS_operand *index = AS_Operand_Const(0);
            gep(res, temp, index);
            return res;
        }

        return temp;
    }
    else if (globalVarMap.find(id) != globalVarMap.end()) // 如果变量是全局变量
    {
        AS_operand *temp = AS_Operand_Name(globalVarMap[id]);
        if (globalVarMap[id]->type == TempType::INT_TEMP)
        {
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
            emit_irs.push_back(L_Load(res, temp));
            return res;
        }
        else if (globalVarMap[id]->type == TempType::INT_PTR && globalVarMap[id]->len >= 0)
        {
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_int_ptr(-1));
            AS_operand *index = AS_Operand_Const(0);
            gep(res, temp, index);
            return res;
        }
        else if(globalVarMap[id]->type == TempType::STRUCT_PTR ){
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_struct_ptr(-1, move(temp->u.TEMP->structname)));
            AS_operand *index = AS_Operand_Const(0);
            gep(res, temp, index);
            return res;
        }

        else
            return temp;
    }
    else
        assert(0);
}

AS_operand *ast2llvmRightVal(aA_rightVal r)
{
    // 检查右值是否为空，如果为空则直接返回nullptr
    if (r == nullptr)
        return nullptr;

    switch (r->kind)
    {
    case A_rightValType::A_arithExprValKind:
    {
        return ast2llvmArithExpr(r->u.arithExpr);
    }
    case A_rightValType::A_boolExprValKind:
    {
        string name = "bool" + to_string(r->pos->col) + "_" + to_string(r->pos->line);
        Temp_label *true_label = Temp_newlabel_named(name + "_true");
        Temp_label *false_label = Temp_newlabel_named(name + "_false");
        Temp_label *end_label = Temp_newlabel_named(name + "_end");
        // 分配一个寄存器来存储布尔表达式的值（0或1）
        AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
        emit_irs.push_back(L_Alloca(dst));
        // 生成布尔表达式的LLVM IR代码，并根据结果跳转到true_label或false_label
        ast2llvmBoolExpr(r->u.boolExpr, true_label, false_label);

        label(true_label);
        store(AS_Operand_Const(1), dst);
        jump(end_label);

        label(false_label);
        store(AS_Operand_Const(0), dst);
        jump(end_label);

        label(end_label);
        AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
        // 从dst加载到res中
        load(res, dst);

        return res;
    }
    default:
        assert(0);
    }
}

AS_operand *ast2llvmLeftVal(aA_leftVal l)
{
    switch (l->kind)
    {
    case A_leftValType::A_arrValKind:
    {
        return ast2llvmArray_2(l->u.arrExpr);
    }
    case A_leftValType::A_memberValKind:
    {
        return ast2llvmMember_2(l->u.memberExpr);
    }
    case A_leftValType::A_varValKind:
    {
        return ast2llvmId_2(*l->u.id);
    }
    default:
    {
        break;
    }
    }
    return nullptr;
}

AS_operand *ast2llvmIndexExpr(aA_indexExpr index)
{
    if (index->kind == A_numIndexKind)
        return AS_Operand_Const(index->u.num);
    else if (index->kind == A_indexExprKind::A_idIndexKind)
    {
        string id = *index->u.id;

        if ((localVarMap.find(id)) != localVarMap.end())
        {
            Temp_temp *temp = localVarMap[id];

            // 创建一个新的整数寄存器
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
            // 获取局部变量对应的寄存器
            AS_operand *mid = AS_Operand_Temp(temp);

            if (temp->type == TempType::INT_PTR)
            {
                emit_irs.push_back(L_Load(res, mid));
                return res;
            }
            else if (temp->type == TempType::INT_TEMP)
                return mid;
            else
                assert(0);
        }
        else if ((globalVarMap.find(id)) != globalVarMap.end())
        {
            AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
            AS_operand *ope_name = AS_Operand_Name(globalVarMap[id]);
            if (globalVarMap[id]->type == TempType::INT_TEMP)
            {
                emit_irs.push_back(L_Load(res, ope_name));
            }
            else
                res = ope_name;
            return res;
        }
        else
            assert(0);
    }
    else
        assert(0);
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
    aA_boolExpr left = b->left;

    string name = "bb" + to_string(b->right->pos->col) + "_" + to_string(b->right->pos->line);
    // next_label是第二部分的标签
    Temp_label *next_label = Temp_newlabel_named(name + "_next");

    switch (b->op)
    {
    case A_boolBiOp::A_and:
    {
        ast2llvmBoolExpr(b->left, next_label, false_label);
        break;
    }
    case A_boolBiOp::A_or:
    {
        ast2llvmBoolExpr(b->left, true_label, next_label);
        break;
    }
    default:
        assert(0);
    }
    label(next_label);
    ast2llvmBoolExpr(b->right, true_label, false_label);
}

void ast2llvmBoolUOpExpr(aA_boolUOpExpr b, Temp_label *true_label, Temp_label *false_label)
{
    ast2llvmBoolUnit(b->cond, false_label, true_label);
}

void ast2llvmBoolUnit(aA_boolUnit b, Temp_label *true_label, Temp_label *false_label)
{
    switch (b->kind)
    {
    case A_boolUnitType::A_boolExprKind:
    {
        ast2llvmBoolExpr(b->u.boolExpr, true_label, false_label);
        break;
    }
    case A_boolUnitType::A_boolUOpExprKind:
    {
        ast2llvmBoolUOpExpr(b->u.boolUOpExpr, true_label, false_label);
        break;
    }
    case A_boolUnitType::A_comOpExprKind:
    {
        ast2llvmComOpExpr(b->u.comExpr, true_label, false_label);
        break;
    }
    default:
    {
        break;
    }
    }
}

void ast2llvmComOpExpr(aA_comExpr c, Temp_label *true_label, Temp_label *false_label)
{
    AS_operand *left = ast2llvmExprUnit(c->left);
    AS_operand *right = ast2llvmExprUnit(c->right);
    AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());

    switch (c->op)
    {
    case A_comOp::A_eq:
    {
        cmp(L_relopKind::T_eq, left, right, dst);
        break;
    }
    case A_comOp::A_ge:
    {
        cmp(L_relopKind::T_ge, left, right, dst);
        break;
    }
    case A_comOp::A_gt:
    {
        cmp(L_relopKind::T_gt, left, right, dst);
        break;
    }
    case A_comOp::A_le:
    {
        cmp(L_relopKind::T_le, left, right, dst);
        break;
    }
    case A_comOp::A_lt:
    {
        cmp(L_relopKind::T_lt, left, right, dst);
        break;
    }
    case A_comOp::A_ne:
    {
        cmp(L_relopKind::T_ne, left, right, dst);
        break;
    }
    default:
    {
        break;
    }
    }
    cjump(dst, true_label, false_label);
}

AS_operand *ast2llvmArithBiOpExpr(aA_arithBiOpExpr a)
{
    AS_operand *left = ast2llvmArithExpr(a->left);
    AS_operand *right = ast2llvmArithExpr(a->right);
    AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());

    switch (a->op)
    {
    case A_arithBiOp::A_add:
    {
        binop(L_binopKind::T_plus, left, right, dst);
        break;
    }
    case A_arithBiOp::A_div:
    {
        binop(L_binopKind::T_div, left, right, dst);
        break;
    }
    case A_arithBiOp::A_mul:
    {
        binop(L_binopKind::T_mul, left, right, dst);
        break;
    }
    case A_arithBiOp::A_sub:
    {
        binop(L_binopKind::T_minus, left, right, dst);
        break;
    }
    default:
        assert(0);
    }
    return dst;
}

AS_operand *ast2llvmArithUExpr(aA_arithUExpr a)
{
    AS_operand *zero = AS_Operand_Const(0);
    AS_operand *val = ast2llvmExprUnit(a->expr);
    AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());
    binop(L_binopKind::T_minus, zero, val, dst);
    return dst;
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
    switch (e->kind)
    {
    case A_numExprKind:
    {
        return AS_Operand_Const(e->u.num);
    }
    case A_idExprKind:
    {
        return ast2llvmId_1(*e->u.id);
    }
    case A_arithExprKind:
    {
        return ast2llvmArithExpr(e->u.arithExpr);
    }
    case A_fnCallKind:
    {
        return ast2llvmfnCall(e->u.callExpr);
    }
    case A_arrayExprKind:
    {
        return ast2llvmArray_1(e->u.arrayExpr);
    }
    case A_memberExprKind:
    {
        return ast2llvmMember_1(e->u.memberExpr);
    }
    case A_arithUExprKind:
    {
        return ast2llvmArithUExpr(e->u.arithUExpr);
    }
    default:
        assert(0);
    }
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

/**
 * @brief jump语句
 * @brief br label %jump
 * @note  会检查处理label为nullptr的情况
 * @param label
 */
void jump(Temp_label *label)
{
    if (label == nullptr)
        assert(0);
    emit_irs.push_back(L_Jump(label));
}

/**
 * @brief gep语句
 * @brief %new_ptr = getelementptr [len x i32], [len x i32]* %base_ptr, i32 0, i32 %index
 */
void gep(AS_operand *new_ptr, AS_operand *base_ptr, AS_operand *index)
{
    emit_irs.push_back(L_Gep(new_ptr, base_ptr, index));
}

/**
 * @brief label语句
 * @brief label:
 */
void label(Temp_label *label)
{
    emit_irs.push_back(L_Label(label));
}

/**
 * @brief store语句
 * @brief store i32 %src, i32* %ptr
 */
void store(AS_operand *src, AS_operand *dst)
{
    emit_irs.push_back(L_Store(src, dst));
}

/**
 * @brief load语句
 * @brief %dst = load i32, i32* %ptr
 */
void load(AS_operand *dst, AS_operand *src)
{
    emit_irs.push_back(L_Load(dst, src));
}

/**
 * @brief cmp语句
 * @brief %dst = icmp op i32 %left, %right
 */
void cmp(L_relopKind kind, AS_operand *left, AS_operand *right, AS_operand *dst)
{
    emit_irs.push_back(L_Cmp(kind, left, right, dst));
}

/**
 * @brief cjump语句
 * @brief br i1 %dst, %true_label, %false_label
 */
void cjump(AS_operand *con, Temp_label *true_label, Temp_label *false_label)
{
    emit_irs.push_back(L_Cjump(con, true_label, false_label));
}

/**
 * @brief binop语句
 * @brief %dst = op i32 %left,%right
 */
void binop(L_binopKind kind, AS_operand *left, AS_operand *right, AS_operand *dst)
{
    emit_irs.push_back(L_Binop(kind, left, right, dst));
}
