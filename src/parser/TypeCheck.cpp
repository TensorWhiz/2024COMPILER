#include "TypeCheck.h"

//global tabels
//typeMap func2retType; // function name to return type

// global token ids to type
typeMap g_token2Type; 

// local token ids to type, since func param can override global param
typeMap funcparam_token2Type;
vector<typeMap*> local_token2Type;

//当前作用域下token2type
typeMap * curr_map = &g_token2Type;
//数组声明时长度
arrayLengthMap array2Length;
//当前函数
string curr_func = "";
// 记录函数参数 
paramMemberMap func2Param;
// 记录结构体成员
paramMemberMap struct2Members;
//记录已def的函数
funcSet defined_funcs;

deduced_map dmap;


// private util functions
void error_print(std::ostream& out, A_pos p, string info){
    out << "Typecheck error in line " << p->line << ", col " << p->col << ": " << info << std::endl;
    exit(0);
}

void print_token_map(typeMap* map){
    for(auto it = map->begin(); it != map->end(); it++){
        std::cout << it->first << " : ";
        switch (it->second->type->type){
        case A_dataType::A_nativeTypeKind:
            switch (it->second->type->u.nativeType){
            case A_nativeType::A_intTypeKind:
                std::cout << "int";
                break;
            default:
                break;
            }
            break;
        case A_dataType::A_structTypeKind:
            std::cout << *(it->second->type->u.structType);
            break;
        default:
            break;
        }
        switch(it->second->isVarArrFunc){
            case 0:
                std::cout << " scalar";
                break;
            case 1:
                std::cout << " array";
                break;
            case 2:
                std::cout << " function";
                break;
        }
        std::cout << std::endl;
    }
}

void print_token_maps(){
    std::cout << "global token2Type:" << std::endl;
    print_token_map(&g_token2Type);
    std::cout << "local token2Type:" << std::endl;
    print_token_map(&funcparam_token2Type);
}

bool comp_aA_type(aA_type target, aA_type t){
    if(!target || !t)
        return false;
    if(target->type != t->type)
        return false;
    if(target->type == A_dataType::A_nativeTypeKind)
        if(target->u.nativeType != t->u.nativeType)
            return false;
    if(target->type == A_dataType::A_structTypeKind)
        if(target->u.structType != t->u.structType)
            return false;
    return true;
}

bool comp_tc_type(tc_type target, tc_type t){
    if(!target || !t)
        return false;
    
    // arr kind first
    if (target->isVarArrFunc && t->isVarArrFunc == 0)
        return false;
    
    // if target type is nullptr, alwayse ok
    return comp_aA_type(target->type, t->type);
}

tc_type tc_Type(aA_type t, uint isVarArrFunc){
    tc_type ret = new tc_type_;//???
    ret->type = t;
    ret->isVarArrFunc = isVarArrFunc;
    return ret;
}

tc_type tc_Type(aA_varDecl vd){
    if(vd->kind == A_varDeclType::A_varDeclScalarKind)
        return tc_Type(vd->u.declScalar->type, 0);
    else if(vd->kind == A_varDeclType::A_varDeclArrayKind)
        return tc_Type(vd->u.declArray->type, 1);
    return nullptr;
}

tc_type get_type_(typeMap* pmap, string tokenID){
    if(funcparam_token2Type.find(tokenID) != funcparam_token2Type.end())
        return funcparam_token2Type[tokenID];
    if(pmap->find(tokenID) != pmap->end())
        return (*pmap)[tokenID];
    if(g_token2Type.find(tokenID)!=g_token2Type.end())
         return g_token2Type[tokenID];

        
    return nullptr;
}

// public functions
void check_Prog(std::ostream& out, aA_program p){
    for (auto ele : p->programElements)
    {
        if(ele->kind == A_programVarDeclStmtKind){
            check_VarDecl(out, ele->u.varDeclStmt);
        }else if (ele->kind == A_programStructDefKind){
            check_StructDef(out, ele->u.structDef);
        }
    }
    
    for (auto ele : p->programElements){
        if(ele->kind == A_programFnDeclStmtKind){
            check_FnDeclStmt(out, ele->u.fnDeclStmt);
        }
        else if (ele->kind == A_programFnDefKind){
            check_FnDecl(out, ele->u.fnDef->fnDecl);
        }
    }

    for (auto ele : p->programElements){
        if(ele->kind == A_programFnDefKind){
            check_FnDef(out, ele->u.fnDef);
        }
        else if (ele->kind == A_programNullStmtKind){
            // do nothing
        }
    }

    out << "Typecheck passed!" << std::endl;
    return;
}

void check_VarDecl(std::ostream& out, aA_varDeclStmt vd){
    if (!vd)
        return;
    string name;
    if (vd->kind == A_varDeclStmtType::A_varDeclKind){
        aA_varDecl vdecl = vd->u.varDecl;
        if(vdecl->kind == A_varDeclType::A_varDeclScalarKind){
            /* fill code here*/
            name = *vdecl->u.declScalar->id;    
            check_isStructTypeDefined(out, vdecl->u.declScalar->type);      
        }
        else{ //vdecl->kind == A_varDeclType::A_varDeclArrayKind
            /* fill code here*/
            name = *vdecl->u.declArray->id;
            check_isStructTypeDefined(out, vdecl->u.declArray->type);    
        }
        //curr_map局部不冲突即可
        if(get_type_(curr_map, name) != nullptr){
            error_print(out, vdecl->pos, "This id is already defined! ");
            return;
        }
        tc_type t = tc_Type(vdecl);
        curr_map->insert({name, t});
        dmap.insert({name,vdecl});

    }
    else if (vd->kind == A_varDeclStmtType::A_varDefKind){
        /* fill code here, allow omited type */
        // decl and def
        aA_varDef vdef = vd->u.varDef;
        if (vdef->kind == A_varDefType::A_varDefScalarKind){
            aA_varDefScalar varDefScalar = vdef->u.defScalar;
            name = *varDefScalar->id;
            if(get_type_(curr_map, name) != nullptr){
                error_print(out, vdef->pos, "This id is already defined! ");
                return;
            }
            check_isStructTypeDefined(out, varDefScalar->type);
            tc_type t = check_rightVal(out, varDefScalar->val);
            
            // 处理缺省类型
            if(varDefScalar->type == nullptr){
                tc_type deduced_type = t;
                curr_map->insert({name, deduced_type});
                return;
            }
            else if(comp_tc_type(t, tc_Type(varDefScalar->type, 0))){
                curr_map->insert({name, tc_Type(varDefScalar->type, 0)});
                return;
            }
            else{
                error_print(out, vd->pos, "Assignment type does not match variable type!1");
                return;
            }

        }
        else if (vdef->kind == A_varDefType::A_varDefArrayKind){
            /* fill code here, allow omited type */
            aA_varDefArray varDefArray = vdef->u.defArray;
            name = *varDefArray->id;
            if(get_type_(curr_map, name) != nullptr){
                error_print(out, vdef->pos, "This id is already defined! ");
                return;
            }
           check_isStructTypeDefined(out, varDefArray->type);
            if(varDefArray->len!=varDefArray->vals.size()){
                error_print(out, vdef->pos, "Length mismatch! ");
                return;
            }
            array2Length[name] = varDefArray->len;
            tc_type t = check_rightVal(out, varDefArray->vals[0]);
            // 检查是否缺省类型
            if(varDefArray->type != nullptr && !comp_tc_type(t, tc_Type(varDefArray->type, 0))){
                error_print(out, vd->pos, "Assignment type does not match variable type!2");
                return;
            }

            for(aA_rightVal rv: varDefArray->vals){
                    if(!comp_tc_type(t,check_rightVal(out, rv))){
                        error_print(out, vd->pos, "Assignment type does not match variable type!3");
                        return;
                    }     
            }
            curr_map->insert({name, tc_Type(varDefArray->type, 1)});
        }

    }
}

void check_StructDef(std::ostream& out, aA_structDef sd){
    if (!sd)
        return;
    string name = *sd->id;
    if (struct2Members.find(name) != struct2Members.end())
        error_print(out, sd->pos, "This id is already defined!");
    struct2Members[name] = &(sd->varDecls);
    return;
}

void check_FnDecl(std::ostream& out, aA_fnDecl fd){
    if (!fd)
        return;
    string name = *fd->id;
    if (func2Param.find(name)!=func2Param.end()){
        // error_print(out, fd->pos, "The function has been declared!");
        // return;
        //检查返回值
        if(!comp_aA_type(get_type_(&g_token2Type, name)->type, fd->type)){
            error_print(out, fd->pos, "The function return type does not match declaration!");
            return;
        }

        //检查大小
        if(func2Param[name]->size() != fd->paramDecl->varDecls.size()){
            error_print(out, fd->pos, "The function parameter number does not match declaration!");
            return;
        }

        //逐个检查
        for(int i = 0;i<func2Param[name]->size(); i++){
            A_varDeclType paramType = func2Param[name]->at(i)->kind;

            if(paramType != fd->paramDecl->varDecls[i]->kind){
                error_print(out, fd->pos, "The function parameter kind does not match declaration!");
                return;
            }

            

            if(paramType == A_varDeclType::A_varDeclScalarKind){
               

                if(!comp_aA_type(func2Param[name]->at(i)->u.declScalar->type, fd->paramDecl->varDecls[i]->u.declScalar->type)){
                    error_print(out, fd->pos, "The function parameter type does not match declaration!");
                    return;
                }

            }
            else { // A_varDeclType::A_varDefArrayKind
                

                if(!comp_aA_type(func2Param[name]->at(i)->u.declArray->type, fd->paramDecl->varDecls[i]->u.declArray->type)){
                    error_print(out, fd->pos, "The function parameter type does not match declaration!");
                    return;
                }
              
            }
        }
        
    }
    else{
        // if not defined
        /* fill code here */
        g_token2Type[name] = tc_Type(fd->type, 2);  // 2代表函数
        func2Param[name] = &(fd->paramDecl->varDecls);
    }
    return;
}

void check_FnDeclStmt(std::ostream& out, aA_fnDeclStmt fd){
    if (!fd)
        return;
    check_FnDecl(out, fd->fnDecl);
    return;
} 

void check_FnDef(std::ostream& out, aA_fnDef fd)
{
    if (!fd)
        return;
    // should match if declared
    check_FnDecl(out, fd->fnDecl);
    // add params to local tokenmap, func params override global ones
    for (aA_varDecl vd : fd->fnDecl->paramDecl->varDecls)
    {
        /* fill code here */

        if(vd->kind==A_varDeclType::A_varDeclScalarKind){

            if(get_type_(&g_token2Type, *vd->u.declScalar->id)!=nullptr){
                    error_print(out,vd->pos, "duplicate definition!");
                    return;
            }
            funcparam_token2Type[*vd->u.declScalar->id]=tc_Type(vd);
        }
        else if(vd->kind==A_varDeclType::A_varDeclArrayKind){
            if(get_type_(&g_token2Type, *vd->u.declArray->id)!=nullptr){
                    error_print(out,vd->pos, "duplicate definition!");
                    return;
                }
            
            funcparam_token2Type[*vd->u.declArray->id]=tc_Type(vd);
        }
        else{
            error_print(out,fd->pos,"error: check_fndef");
            return;
        }

    }
    /* fill code here */
    enter_scope();
    curr_func = *fd->fnDecl->id;
    for (aA_codeBlockStmt stmt : fd->stmts)
    {
        check_CodeblockStmt(out, stmt);
        // return value type should match
        /* fill code here */  
    }
    leave_scope();
    curr_func = "";
    // remove params
    for (aA_varDecl vd : fd->fnDecl->paramDecl->varDecls)
    {
        if(vd->kind == A_varDeclType::A_varDeclScalarKind){
            funcparam_token2Type.erase(*vd->u.declScalar->id);
        }else{
            funcparam_token2Type.erase(*vd->u.declArray->id);
        }
    }

    defined_funcs.push_back(*fd->fnDecl->id);
    return;
}

void check_CodeblockStmt(std::ostream& out, aA_codeBlockStmt cs){
    if(!cs)
        return;
    // variables declared in a code block should not duplicate with outer ones.
    switch (cs->kind)
    {
    case A_codeBlockStmtType::A_varDeclStmtKind:
        check_VarDecl(out, cs->u.varDeclStmt);
        break;
    case A_codeBlockStmtType::A_assignStmtKind:
        check_AssignStmt(out, cs->u.assignStmt);
        break;
    case A_codeBlockStmtType::A_ifStmtKind:
        check_IfStmt(out, cs->u.ifStmt);
        break;
    case A_codeBlockStmtType::A_whileStmtKind:
        check_WhileStmt(out, cs->u.whileStmt);
        break;
    case A_codeBlockStmtType::A_callStmtKind:
        check_CallStmt(out, cs->u.callStmt);
        break;
    case A_codeBlockStmtType::A_returnStmtKind:
        check_ReturnStmt(out, cs->u.returnStmt);
        break;
    default:
        break;
    }
    return;
}

void check_AssignStmt(std::ostream& out, aA_assignStmt as){
    if(!as)
        return;
    string name;
    tc_type deduced_type; // deduced type if type is omitted at decl
    deduced_type = check_rightVal(out, as->rightVal);
    switch (as->leftVal->kind)
    {
        case A_leftValType::A_varValKind:{
            name = *as->leftVal->u.id;
            /* fill code here */
            tc_type tc_tp=get_type_(curr_map,name);
            //没找到--保错
            if(tc_tp == nullptr){
                error_print(out, as->pos, "Variable not defined!");
                return;
            }
            //找到--1.没类型 2.1 有类型不匹配 2.2 有类型匹配
            if(tc_tp->type == nullptr){
                curr_map->find(name)->second = deduced_type;
                dmap.find(name)->second->kind= A_varDeclScalarKind;
                dmap.find(name)->second->u.declScalar->type=deduced_type->type;
            }
            else{
                if(!comp_tc_type(tc_tp, deduced_type)){
                    error_print(out, as->pos, "Assignment type does not match variable type!4");
                    return;
                }
       
            }
        }
            break;
        case A_leftValType::A_arrValKind:{
            /* fill code here */
            name = *as->leftVal->u.arrExpr->arr->u.id;
            tc_type tc_tp=get_type_(curr_map,name);
            //没找到--保错
            if(tc_tp == nullptr)
                error_print(out, as->pos, "Variable not defined!");
            //找到--1.没类型 2.1 有类型不匹配 2.2 有类型匹配
            if(tc_tp->type == nullptr){
                tc_tp->type=deduced_type->type;
                curr_map->find(name)->second = deduced_type;
            }
            else{
                if(!comp_tc_type(tc_tp, tc_Type(deduced_type->type,1))){
                   error_print(out, as->pos, "Assignment type does not match variable type!5"); 
                   return;
                }
     
            }

        }
            break;
        case A_leftValType::A_memberValKind:{
            /* fill code here */
            aA_memberExpr me = as->leftVal->u.memberExpr;
            string structID = *me->structId->u.id;
            //检查类型
            if(me->structId->kind != A_leftValType::A_varValKind){
                error_print(out, as->pos, "Multi-level is not surpported!");
                return;
            } 
            //检查id
            if(struct2Members.find(structID) != struct2Members.end()){
                error_print(out, as->pos, "check_assignstmt struct not found!");
                return;
            }
            tc_type tc_tp = get_type_(curr_map, structID);
            if(tc_tp == nullptr){
                error_print(out, as->pos, "Struct not defined!");
                return;
            }
            if(tc_tp->type->type != A_dataType::A_structTypeKind){
                error_print(out, as->pos, "Not a struct type!");
                return;
            }
            //check member
            vector<aA_varDecl>* memberDecls = struct2Members.find(*(tc_tp->type->u.structType))->second;
            bool isExist = false;
            for(aA_varDecl vd: *memberDecls){
                string id;
                if(vd->kind == A_varDeclType::A_varDeclScalarKind)
                    id = *vd->u.declScalar->id;
                else//A_varDeclType::A_varDeclArrayKind
                    id = *vd->u.declArray->id;
                
                if(id == *me->memberId){
                    if(!comp_tc_type(tc_Type(vd), deduced_type)){
                        error_print(out, as->pos, "Assignment type does not match struct member type!");
                        return;
                    }   
                    isExist = true;
                    break;
                }
            }

            if(!isExist){
                error_print(out, as->pos, "Struct member not defined!");
                return;
            }  

        }
            break;
    }
    return;
}

void check_ArrayExpr(std::ostream& out, aA_arrayExpr ae){
    if(!ae)
        return;
    string name = *ae->arr->u.id;
    // check array name
    /* fill code here */
    if(get_type_(curr_map, name) == nullptr){
            error_print(out, ae->pos, "Array not defined!");
            return;   
    }
    // check index
    /* fill code here */    
    // TODO
    A_indexExprKind indexKind = ae->idx->kind;
    if(indexKind == A_indexExprKind::A_idIndexKind){
        // 检查id是否在当前定义域内
        if(get_type_(curr_map, *ae->idx->u.id) == nullptr){
            error_print(out, ae->pos, "Array index with id not defined!");
            return;
        }
    }
    else{// A_indexExprKind::A_numIndexKind
        int index = ae->idx->u.num;
        if(index < 0 || index >= array2Length[name]){
            error_print(out, ae->pos, "Array index out of range!");
            return;
        }
    }
    
}

tc_type check_MemberExpr(std::ostream& out, aA_memberExpr me){
    // check if the member exists and return the tyep of the member
    if(!me)
        return nullptr;
    string name = *me->structId->u.id;
    // check struct name
    /* fill code here */
    tc_type tc_tp = get_type_(curr_map, name);
    if(tc_tp == nullptr){
        error_print(out, me->pos, "Struct not defined!");
        return nullptr;
    }

    if(tc_tp->type->type != A_dataType::A_structTypeKind){
        error_print(out, me->pos, "Not a struct type!");
        return nullptr;
    }    
    // check member name
    /* fill code here */
    string structType = *tc_tp->type->u.structType;
    vector<aA_varDecl>* memberDecls = struct2Members[structType];
    //遍历struct所有member
    for(aA_varDecl vd: *memberDecls){
        string id;

        if(vd->kind == A_varDeclType::A_varDeclScalarKind)
            id = *vd->u.declScalar->id;
        else
            id = *vd->u.declArray->id;

        if(id == *me->memberId){
            if(vd->kind == A_varDeclType::A_varDeclScalarKind)
                return tc_Type(vd->u.declScalar->type, 0);
            else
                return tc_Type(vd->u.declArray->type, 1);
        }
    }
    return nullptr;
}


void check_IfStmt(std::ostream& out, aA_ifStmt is){
    if(!is)
        return;
    check_BoolUnit(out, is->boolUnit);
    /* fill code here, take care of variable scope */
    enter_scope();

    for(aA_codeBlockStmt s : is->ifStmts){
        check_CodeblockStmt(out, s);
    }
    leave_scope();
    enter_scope();
    /* fill code here */    
    for(aA_codeBlockStmt s : is->elseStmts){
        check_CodeblockStmt(out, s);
    }
    /* fill code here */
    leave_scope();
    return;
}


void check_BoolExpr(std::ostream& out, aA_boolExpr be){
    if(!be)
        return;
    switch (be->kind)
    {
    case A_boolExprType::A_boolBiOpExprKind:
        check_BoolExpr(out, be->u.boolBiOpExpr->left);
        check_BoolExpr(out, be->u.boolBiOpExpr->right);
        break;
    case A_boolExprType::A_boolUnitKind:
        check_BoolUnit(out, be->u.boolUnit);
        break;
    default:
        break;
    }
    return;
}


void check_BoolUnit(std::ostream& out, aA_boolUnit bu){
    if(!bu)
        return;
    switch (bu->kind)
    {
        case A_boolUnitType::A_comOpExprKind:{
            /* fill code here */
            aA_comExpr comExpr = bu->u.comExpr;
            tc_type leftType = check_ExprUnit(out, comExpr->left);
            tc_type rightType = check_ExprUnit(out, comExpr->right);
            if(!comp_tc_type(leftType, rightType)){
                error_print(out, leftType->type->pos, "Comparison type does not match!");
            }

              
        }
            break;
        case A_boolUnitType::A_boolExprKind:
            check_BoolExpr(out, bu->u.boolExpr);
            break;
        case A_boolUnitType::A_boolUOpExprKind:
            check_BoolUnit(out, bu->u.boolUOpExpr->cond);
            break;
        default:
            break;
    }
    return;
}


tc_type check_ExprUnit(std::ostream& out, aA_exprUnit eu){
    // return the aA_type of expr eu
    if(!eu)
        return nullptr;
    tc_type ret;
    switch (eu->kind)
    {
        case A_exprUnitType::A_idExprKind:{
            /* fill code here */
            string name = *eu->u.id;
            tc_type tc_tp = get_type_(curr_map, name);
            if(tc_tp == nullptr)
                error_print(out, eu->pos, "Variable not defined!");
            // 返回变量的类型
            aA_type idt = new aA_type_;
            idt->pos = eu->pos;
            idt->type = tc_tp->type->type;
            if(idt->type == A_dataType::A_nativeTypeKind)
                idt->u.nativeType = tc_tp->type->u.nativeType;
            else
                idt->u.structType =tc_tp->type->u.structType;
            
            ret = tc_Type(idt, tc_tp->isVarArrFunc);
        }
            break;
        case A_exprUnitType::A_numExprKind:{
            aA_type numt = new aA_type_;
            numt->pos = eu->pos;
            numt->type = A_dataType::A_nativeTypeKind;
            numt->u.nativeType = A_nativeType::A_intTypeKind;
            ret = tc_Type(numt, 0);
        }
            break;
        case A_exprUnitType::A_fnCallKind:{
            check_FuncCall(out, eu->u.callExpr);
            // check_FuncCall will check if the function is defined
            /* fill code here */
            string func_name = *eu->u.callExpr->fn;
            aA_type funcCallt = new aA_type_;
            funcCallt->pos = eu->pos;
            funcCallt->type = g_token2Type[func_name]->type->type;
            
            if(funcCallt->type == A_dataType::A_nativeTypeKind)
                funcCallt->u.nativeType = g_token2Type[func_name]->type->u.nativeType;
            else
                funcCallt->u.structType = g_token2Type[func_name]->type->u.structType;

            // TODO 假设函数返回值都是标量
            ret = tc_Type(funcCallt, 0);
        }
            break;
        case A_exprUnitType::A_arrayExprKind:{
            check_ArrayExpr(out, eu->u.arrayExpr);
            /* fill code here */
            string array_name=*eu->u.arrayExpr->arr->u.id;
            aA_type aet = new aA_type_;
            aet->pos = eu->pos;
            if(eu->u.arrayExpr->arr->kind != A_leftValType::A_varValKind)
                error_print(out, eu->pos, "Only support One-level Array");

            tc_type tc_tp = get_type_(curr_map,array_name);

            aet->type = tc_tp->type->type;
            if(aet->type == A_dataType::A_nativeTypeKind)
                aet->u.nativeType =tc_tp->type->u.nativeType;
            else
                aet->u.structType = tc_tp->type->u.structType;

            ret = tc_Type(aet, 0);
        }
            break;
        case A_exprUnitType::A_memberExprKind:{
            ret = check_MemberExpr(out, eu->u.memberExpr);
        }
            break;
        case A_exprUnitType::A_arithExprKind:{
            ret = check_ArithExpr(out, eu->u.arithExpr);
        }
            break;
        case A_exprUnitType::A_arithUExprKind:{
            ret = check_ExprUnit(out, eu->u.arithUExpr->expr);
        }
            break;
    }
    return ret;
}


tc_type check_ArithExpr(std::ostream& out, aA_arithExpr ae){
    if(!ae)
        return nullptr;
    tc_type ret;
    switch (ae->kind)
    {
        case A_arithExprType::A_arithBiOpExprKind:{
            ret = check_ArithExpr(out, ae->u.arithBiOpExpr->left);
            tc_type rightTyep = check_ArithExpr(out, ae->u.arithBiOpExpr->right);
            if(ret->type->type > 0 || ret->type->type != A_dataType::A_nativeTypeKind || ret->type->u.nativeType != A_nativeType::A_intTypeKind ||
            rightTyep->type->type > 0 || rightTyep->type->type != A_dataType::A_nativeTypeKind || rightTyep->type->u.nativeType != A_nativeType::A_intTypeKind)
                error_print(out, ae->pos, "Only int can be arithmetic expression operation values!");
        }
            break;
        case A_arithExprType::A_exprUnitKind:
            ret = check_ExprUnit(out, ae->u.exprUnit);
            break;
    }
    return ret;
}


void check_FuncCall(std::ostream& out, aA_fnCall fc){
    if(!fc)
        return;
    // check if function defined
    string func_name = *fc->fn;
    /* fill code here */
    if(func2Param.find(func_name) == func2Param.end())
        error_print(out, fc->pos, "Function not defined!");
    if(func2Param[func_name]->size() != fc->vals.size())
        error_print(out, fc->pos, "Function parameter number does not match declaration!");
    for(int i = 0; i < fc->vals.size(); i++){
        /* fill code here */
        // 检查参数值类型是否与函数定义保持一致
        if(!comp_tc_type(tc_Type(func2Param[func_name]->at(i)), check_rightVal(out, fc->vals[i])))
            error_print(out, fc->vals[i]->pos, "Function parameter kind does not match declaration!");
    }
    return ;
}


void check_WhileStmt(std::ostream& out, aA_whileStmt ws){
    if(!ws)
        return;
    check_BoolUnit(out, ws->boolUnit);
    /* fill code here, take care of variable scope */
    enter_scope();
    for(aA_codeBlockStmt s : ws->whileStmts){
        check_CodeblockStmt(out, s);
    }

    /* fill code here */
    leave_scope();
    return;
}


void check_CallStmt(std::ostream& out, aA_callStmt cs){
    if(!cs)
        return;
    check_FuncCall(out, cs->fnCall);
    return;
}

void check_ReturnStmt(std::ostream& out, aA_returnStmt rs){
    if(!rs)
        return;
    if(curr_func.empty())
        error_print(out, rs->pos, "The returnStmt is in the wrong position! ");

    tc_type funcType = g_token2Type.find(curr_func)->second;
    tc_type ret = check_rightVal(out, rs->retVal);

    if(ret->isVarArrFunc!=0 || !comp_aA_type(ret->type, funcType->type))
        error_print(std::cout, rs->pos, "Return type does not match function return type!");
    return;
}

/**
 * 进入新的作用域
*/
void enter_scope(){
    typeMap * new_map;
    if (local_token2Type.size() == 0)
        new_map = new typeMap(g_token2Type);
    else
        new_map = new typeMap(*(local_token2Type.back()));
    
    local_token2Type.push_back(new_map);
    curr_map = new_map;
}

/**
 * 离开当前作用域
*/
void leave_scope(){
    local_token2Type.pop_back();
    delete curr_map;
    curr_map = local_token2Type.back();
}

tc_type check_rightVal(std::ostream& out, aA_rightVal rv){
    if(rv->kind == A_rightValType::A_arithExprValKind)
        return check_ArithExpr(out, rv->u.arithExpr);
    else{
        // A_rightValType::A_boolExprValKind
        check_BoolExpr(out, rv->u.boolExpr);
        aA_type aAType = new aA_type_;
        aAType->pos = rv->pos;
        aAType->type = A_dataType::A_nativeTypeKind;
        aAType->u.nativeType = A_nativeType::A_intTypeKind;
        tc_type ret = tc_Type(aAType, 0);   // 标量
        return ret;
    }
}

bool check_isStructTypeDefined(std::ostream& out, aA_type t){
    if(!t)
        return false;

    if(t->type == A_dataType::A_structTypeKind){
        if(struct2Members.find(*t->u.structType) == struct2Members.end()){
            error_print(out, t->pos, "Struct type not defined!");
            return false;
        }
    }
    
    return true;
}