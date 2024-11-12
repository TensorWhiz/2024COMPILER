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
    string name = *f->fnDecl->id;
    FuncType ret = funcReturnMap[name];
    emit_irs.clear();
    label(Temp_newlabel_named(name));
    localVarMap.clear();
    vector<Temp_temp *> args;
    for (auto &decl : f->fnDecl->paramDecl->varDecls)
    {
        switch (decl->kind)
        {
        case A_varDeclType::A_varDeclScalarKind:
        {
            if (decl->u.declScalar->type->type == A_dataType::A_nativeTypeKind)
            {
                Temp_temp *arg = Temp_newtemp_int();
                args.push_back(arg);
                Temp_temp *temp_ptr = Temp_newtemp_int_ptr(0);
                AS_operand *arg_ptr = AS_Operand_Temp(temp_ptr);
                alloc(arg_ptr);
                store(AS_Operand_Temp(arg), arg_ptr);
                localVarMap.emplace(*decl->u.declScalar->id, temp_ptr);
            }
            else // struct
            {
                Temp_temp *temp = Temp_newtemp_struct_ptr(0, *decl->u.declScalar->type->u.structType);
                args.push_back(temp);
                localVarMap.emplace(*decl->u.declScalar->id, temp);
            }
            break;
        }
        case A_varDeclType::A_varDeclArrayKind: // 数组
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
            break;
        }
        default:
        {
            assert(0);
            break;
        }
        }
    }
    // 语句
    for (auto &stmt : f->stmts)
    {
        ast2llvmBlock(stmt, nullptr, nullptr);
        if (stmt->kind == A_codeBlockStmtType::A_returnStmtKind)
            break;
    }

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
    {
        assert(0);
        break;
    }
    }
}

void ast2llvmStmtvarDecl(aA_varDeclStmt s)
{
    if (s->kind == A_varDeclKind)
    {
        if (s->u.varDecl->kind == A_varDeclScalarKind)
        {
            aA_varDeclScalar varDeclScalar = s->u.varDecl->u.declScalar;
            if (varDeclScalar->type->type == A_structTypeKind)
            {
                Temp_temp *temp = Temp_newtemp_struct_ptr(0, *varDeclScalar->type->u.structType);
                localVarMap.emplace(*varDeclScalar->id, temp);
                alloc(AS_Operand_Temp(temp));
            }
            else if (varDeclScalar->type->type == A_dataType::A_nativeTypeKind)
            {
                Temp_temp *temp = Temp_newtemp_int_ptr(0);
                localVarMap.emplace(*varDeclScalar->id, temp);
                alloc(AS_Operand_Temp(temp));
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
                alloc(AS_Operand_Temp(temp));
            }
            else if (varDeclArray->type->type == A_nativeTypeKind)
            {
                Temp_temp *temp = Temp_newtemp_int_ptr(varDeclArray->len);
                localVarMap.emplace(*varDeclArray->id, temp);
                alloc(AS_Operand_Temp(temp));
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
            if (varDefScalar->type->type == A_nativeTypeKind)
            {
                Temp_temp *temp = Temp_newtemp_int_ptr(0);
                AS_operand *dst = AS_Operand_Temp(temp);
                localVarMap.emplace(*varDefScalar->id, temp);
                alloc(dst);
                AS_operand *right = ast2llvmRightVal(varDefScalar->val);
                loadAndStore(dst, right);
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
                alloc(dst);
                AS_operand *base_ptr = dst;
                int i = 0;
                for (; i < varDefArray->len; i++)
                {
                    AS_operand *new_ptr = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
                    AS_operand *index = AS_Operand_Const(i);
                    gep(new_ptr, base_ptr, index);
                    AS_operand *val = ast2llvmRightVal(varDefArray->vals[i]);
                    loadAndStore(new_ptr, val);
                }
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
    loadAndStore(left, right);
}

void ast2llvmStmtcall(aA_callStmt s)
{
    ast2llvmfnCall(s->fnCall);
}

AS_operand *ast2llvmfnCall(aA_fnCall callExpr)
{
    vector<AS_operand *> args;
    string name = *callExpr->fn;
    for (int i = 0; i < callExpr->vals.size(); i++)
    {

        AS_operand *temp = ast2llvmRightVal(callExpr->vals[i]);

        if (temp->kind == OperandKind::TEMP && (temp->u.TEMP->len > 0 || temp->u.TEMP->len == -1) ||
            temp->kind == OperandKind::NAME && (temp->u.NAME->len > 0 || temp->u.TEMP->len == -1))
        {
            if (temp->u.TEMP->type == TempType::INT_PTR ||
                temp->u.NAME->type == TempType::INT_PTR)
            {
                AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int_ptr(-1));
                AS_operand *index = AS_Operand_Const(0);
                gep(dst, temp, index);
                args.push_back(dst);
            }
            else if (temp->u.TEMP->type == TempType::STRUCT_PTR ||
                     temp->u.NAME->type == TempType::STRUCT_PTR)
            {
                AS_operand *dst = AS_Operand_Temp(Temp_newtemp_struct_ptr(-1, move(temp->u.TEMP->structname)));
                AS_operand *index = AS_Operand_Const(0);
                gep(dst, temp, index);
                args.push_back(dst);
            }
        }
        else
        {
            AS_operand *left = Ptr2Val(temp);
            args.push_back(left);
        }
    }

    AS_operand *res = nullptr;
    FuncType funcType = funcReturnMap[name];
    if (funcType.type == ReturnType::VOID_TYPE)
    {
        emit_irs.push_back(L_Voidcall(name, args));
    }
    else if (funcType.type == ReturnType::INT_TYPE)
    {
        res = AS_Operand_Temp(Temp_newtemp_int());
        emit_irs.push_back(L_Call(name, res, args));
    }
    else
        assert(0);
    return res;
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
    std::vector<string> ifVector;
    for (int i = 0; i < s->ifStmts.size(); i++)
    {
        // ast2llvmBlock(s->ifStmts[i], con_label, bre_label, ifVector);
        ast2llvmBlock(s->ifStmts[i], con_label, bre_label);
        if (s->ifStmts[i]->kind == A_codeBlockStmtType::A_returnStmtKind)
            break;
    }
    // 删除if代码块内的局部变量
    // for(int i = 0;i<ifVector.size();i++)
    //     localVarMap.erase(ifVector[i]);
    // ifVector.clear();
    jump(end_label);

    // 翻译else代码块
    label(false_label);
    // std::vector<string> elseVector;
    for (int i = 0; i < s->elseStmts.size(); i++)
    {
        // ast2llvmBlock(s->elseStmts[i], con_label, bre_label, elseVector);
        ast2llvmBlock(s->elseStmts[i], con_label, bre_label);
        if (s->elseStmts[i]->kind == A_codeBlockStmtType::A_returnStmtKind)
            break;
    }
    // 删除if代码块内的局部变量
    // for(int i = 0;i<elseVector.size();i++)
    //     localVarMap.erase(elseVector[i]);
    // elseVector.clear();
    jump(end_label);

    // end标签
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
    // std::vector<string> whileVector;
    for (int i = 0; i < s->whileStmts.size(); i++)
    {
        // ast2llvmBlock(s->whileStmts[i], new_con_label, new_bre_label, whileVector);
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
    if (s->retVal == nullptr)
    {
        retVoid();
    }
    else
    {
        retVal(Ptr2Val(ast2llvmRightVal(s->retVal)));
    }
}

AS_operand *ast2llvmArray(aA_arrayExpr arrExpr)
{
    AS_operand *base_ptr = ast2llvmLeftVal(arrExpr->arr);
    AS_operand *index = Ptr2Val(ast2llvmIndexExpr(arrExpr->idx));
    AS_operand *new_ptr = nullptr;

    // 获取new_ptr的类型
    if (base_ptr->kind == OperandKind::NAME)
    {
        Name_name *name = base_ptr->u.NAME;
        if (name->type == TempType::INT_PTR)
        {
            new_ptr = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
        }
        else
        {
            new_ptr = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, name->structname));
        }
    }
    else if (base_ptr->kind == OperandKind::TEMP)
    {
        Temp_temp *temp = base_ptr->u.TEMP;
        if (temp->type == TempType::INT_PTR)
        {
            new_ptr = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
        }
        else if (temp->type == TempType::STRUCT_PTR)
        {
            new_ptr = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, temp->structname));
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

    gep(new_ptr, base_ptr, index);
    return new_ptr;
}

AS_operand *ast2llvmMember(aA_memberExpr memberExpr)
{
    // 1. 确定base_ptr
    AS_operand *base_ptr = ast2llvmLeftVal(memberExpr->structId);

    // 2. 确定index
    string structName = std::string();
    // 确定结构体名称
    if (base_ptr->kind == OperandKind::TEMP)
    {
        Temp_temp *temp = base_ptr->u.TEMP;
        structName = temp->structname;
    }
    else
    {
        Name_name *name = base_ptr->u.NAME;
        structName = name->structname;
    }

    StructInfo structInfo = structInfoMap[structName];
    MemberInfo memberInfo = structInfo.memberinfos[*memberExpr->memberId];
    AS_operand *index = AS_Operand_Const(memberInfo.offset);

    // 3. 确定new_ptr
    AS_operand *new_ptr = nullptr;
    switch (memberInfo.def.kind)
    {
    case TempType::INT_TEMP:
    {
        //??? int
        new_ptr = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
        break;
    }
    case TempType::INT_PTR:
    {
        new_ptr = AS_Operand_Temp(Temp_newtemp_int_ptr(memberInfo.def.len));
        break;
    }
    case TempType::STRUCT_TEMP:
    {
        new_ptr = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, memberInfo.def.structname));
        break;
    }
    case TempType::STRUCT_PTR:
    {
        new_ptr = AS_Operand_Temp(Temp_newtemp_struct_ptr(memberInfo.def.len, memberInfo.def.structname));
        break;
    }
    default:
    {
        break;
    }
    }

    gep(new_ptr, base_ptr, index);
    return new_ptr;
}

AS_operand *ast2llvmId(string id)
{
    if (localVarMap.find(id) != localVarMap.end())
    {
        Temp_temp *temp = localVarMap[id];
        return AS_Operand_Temp(localVarMap[id]);
    }
    else
    {
        return AS_Operand_Name(globalVarMap[id]);
    }
}

AS_operand *ast2llvmRightVal(aA_rightVal r)
{
    switch (r->kind)
    {
    case A_rightValType::A_arithExprValKind:
    {
        return ast2llvmArithExpr(r->u.arithExpr);
        break;
    }
    case A_rightValType::A_boolExprValKind:
    {
        string name = "bool" + to_string(r->pos->col) + "_" + to_string(r->pos->line);
        Temp_label *true_label = Temp_newlabel_named(name + "_true");
        Temp_label *false_label = Temp_newlabel_named(name + "_false");
        Temp_label *end_label = Temp_newlabel_named(name + "_end");

        AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
        alloc(dst);

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
        break;
    }
    default:
    {
        break;
    }
    }
    assert(0);
    return nullptr;
}

AS_operand *ast2llvmLeftVal(aA_leftVal l)
{
    switch (l->kind)
    {
    case A_leftValType::A_arrValKind:
    {
        return ast2llvmArray(l->u.arrExpr);
    }
    case A_leftValType::A_memberValKind:
    {
        return ast2llvmMember(l->u.memberExpr);
    }
    case A_leftValType::A_varValKind:
    {
        return ast2llvmId(*l->u.id);
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
        if ((localVarMap.find(*index->u.id)) != localVarMap.end())
        {
            Temp_temp *temp = localVarMap[*index->u.id];
            if (temp->type == TempType::INT_PTR)
            {
                AS_operand *ret = AS_Operand_Temp(Temp_newtemp_int());
                emit_irs.push_back(L_Load(ret, AS_Operand_Temp(temp)));
                return ret;
            }
            else if (temp->type == TempType::INT_TEMP)
            {
                AS_operand *ret = AS_Operand_Temp(temp);
                return ret;
            }
            else
                assert(0);
        }
        else if ((globalVarMap.find(*index->u.id)) != globalVarMap.end())
        {
            AS_operand *ope_name = AS_Operand_Name(globalVarMap[*index->u.id]);
            AS_operand *ope_dst;
            if (globalVarMap[*index->u.id]->type == TempType::INT_TEMP)
            {
                ope_dst = AS_Operand_Temp(Temp_newtemp_int());
                emit_irs.push_back(L_Load(ope_dst, ope_name));
            }
            else
                ope_dst = ope_name;
            return ope_dst;
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
}

AS_operand *ast2llvmBoolExpr(aA_boolExpr b, Temp_label *true_label, Temp_label *false_label)
{
    switch (b->kind)
    {
    case A_boolExprType::A_boolBiOpExprKind:
    {
        // void
        ast2llvmBoolBiOpExpr(b->u.boolBiOpExpr, true_label, false_label);
        break;
    }
    case A_boolExprType::A_boolUnitKind:
    {
        // void
        ast2llvmBoolUnit(b->u.boolUnit, true_label, false_label);
        break;
    }
    default:
    {
        break;
    }
    }
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

        label(next_label);
        ast2llvmBoolExpr(b->right, true_label, false_label);

        break;
    }
    case A_boolBiOp::A_or:
    {
        ast2llvmBoolExpr(b->left, true_label, next_label);

        label(next_label);
        ast2llvmBoolExpr(b->right, true_label, false_label);

        break;
    }
    default:
    {
        break;
    }
    }
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
        ast2llvmBoolUnit(b->u.boolUOpExpr->cond, false_label, true_label);
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
    AS_operand *left = Ptr2Val(ast2llvmExprUnit(c->left));
    AS_operand *right = Ptr2Val(ast2llvmExprUnit(c->right));
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
    AS_operand *left = Ptr2Val(ast2llvmArithExpr(a->left));
    AS_operand *right = Ptr2Val(ast2llvmArithExpr(a->right));
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
    {
        break;
    }
    }
    return dst;
}

AS_operand *ast2llvmArithUExpr(aA_arithUExpr a)
{
    AS_operand *zero = AS_Operand_Const(0);
    AS_operand *val = Ptr2Val(ast2llvmExprUnit(a->expr));
    AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());

    binop(L_binopKind::T_minus, zero, val, dst);
    return dst;
}

AS_operand *ast2llvmArithExpr(aA_arithExpr a)
{
    switch (a->kind)
    {
    case A_arithExprType::A_arithBiOpExprKind:
    {
        return ast2llvmArithBiOpExpr(a->u.arithBiOpExpr);
        break;
    }
    case A_arithExprType::A_exprUnitKind:
    {
        return ast2llvmExprUnit(a->u.exprUnit);
        break;
    }
    default:
    {
        break;
    }
    }
    assert(0);
    return nullptr;
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
        return ast2llvmId(*e->u.id);
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
        return ast2llvmArray(e->u.arrayExpr);
    }
    case A_memberExprKind:
    {
        return ast2llvmMember(e->u.memberExpr);
    }
    case A_arithUExprKind:
    {
        return ast2llvmArithUExpr(e->u.arithUExpr);
    }
    default:
    {
        break;
    }
    }
    assert(0);
    return nullptr;
}

LLVMIR::L_func *ast2llvmFuncBlock(Func_local *f)
{
    list<L_block *> blocks;
    // 存储基本块中的指令
    std::list<L_stm *> instrs;
    // 存储基本块的后继标签
    // std::unordered_set<Temp_label *> succs;
    // // 创建初始基本块
    // L_block *lblock = new L_block(Temp_newlabel(), succs, instrs);
    // lblock->instrs.push_back(L_Label(lblock->label));

    // Temp_label *label;
    // // 标志是否已有后继
    // bool hasSuccs = true;
    // // 标志是否已有返回语句
    // bool notRet = true;

    for (auto x : f->irs)
    {
        if (x->type == L_StmKind::T_LABEL)
        {
            // 标签
            if (!instrs.empty())
            {
                // 遇到一个标签，当前块指令未完，添加到标签的jump指令并保存当前块
                instrs.push_back(L_Jump(x->u.LABEL->label));
                blocks.push_back(L_Block(instrs));
                instrs.clear();
            }
            instrs.push_back(x);
        }
        else if (x->type == L_StmKind::T_CJUMP || x->type == L_StmKind::T_JUMP || x->type == L_StmKind::T_RETURN)
        {
            // 遇到jump指令
            instrs.push_back(x);
            if (instrs.front()->type != L_StmKind::T_LABEL)
            {
                instrs.push_front(L_Label(Temp_newlabel()));
            }
            blocks.push_back(L_Block(instrs));
            instrs.clear();
        }
        else
        {
            instrs.push_back(x);
        }

        if (x == f->irs.back())
        {
            if (instrs.size() != 0)
            {
                if (instrs.front()->type != L_StmKind::T_LABEL)
                {
                    instrs.push_front(L_Label(Temp_newlabel()));
                }
                if (f->ret.type == ReturnType::VOID_TYPE)
                    instrs.push_back(L_Ret(nullptr));
                else
                    instrs.push_back(L_Ret(AS_Operand_Const(0)));
                blocks.push_back(L_Block(instrs));
                instrs.clear();
            }
        }
    }
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
 * @brief alloc语句
 * @brief %dst = alloca <ty>
 * @param AS_operand* 操作数，指针寄存器
 */
void alloc(AS_operand *res)
{
    // The  alloca  instruction allocates memory on the stack frame of the currently executing function, to be automatically released when this function returns to its caller
    emit_irs.push_back(L_Alloca(res));
}

/**
 * @brief 赋值语句
 * @brief store i32 %src, i32* %ptr
 * @param AS_operand* 操作数，左值
 */
void loadAndStore(AS_operand *dst, AS_operand *src)
{
    // 把指针寄存器转为值寄存器
    AS_operand *src_val = Ptr2Val(src);
    // AS_operand *dst_ptr = Val2Ptr(dst);

    emit_irs.push_back(L_Store(src_val, dst));
}

/**
 * @brief ret语句
 * @brief ret void
 *
 */
void retVoid()
{
    emit_irs.push_back(L_Ret(nullptr));
}

/**
 * @brief ret i32 %ret
 * @param ret
 */
void retVal(AS_operand *ret)
{
    emit_irs.push_back(L_Ret(ret));
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

/**
 * @brief 加载语句
 * @param AS_operand* 操作数，指针寄存器
 * @return AS_operand* 操作数，值寄存器
 */
AS_operand *Ptr2Val(AS_operand *left)
{
    switch (left->kind)
    {
    case OperandKind::TEMP:
    {
        switch (left->u.TEMP->type)
        {
        case TempType::INT_PTR:
        {
            AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());
            emit_irs.push_back(L_Load(dst, left));
            return dst;
        }
        default:
        {
            return left;
        }
        }
        break;
    }
    case OperandKind::NAME:
    {
        switch (left->u.NAME->type)
        {
        case TempType::INT_TEMP:
        case TempType::INT_PTR:
        {
            AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());
            emit_irs.push_back(L_Load(dst, left));
            return dst;
        }
        default:
        {
            return left;
        }
        }
        break;
    }
    case OperandKind::ICONST:
    {
        return left;
    }
    default:
    {
        assert(0);
        break;
    }
    }
}
