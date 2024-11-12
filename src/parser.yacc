%{
#include <stdio.h>
#include "TeaplAst.h"
extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(const char *s); 
extern int  yywrap();

}

%}

// TODO:
// your parser

%union {
A_pos pos;
A_type type;
A_varDecl varDecl;
A_varDef varDef;
A_rightVal rightVal;
A_arithExpr arithExpr;
A_boolExpr boolExpr;
A_arithBiOpExpr arithBiOpExpr;
A_arithUExpr arithUExpr;
A_exprUnit exprUnit;
A_fnCall fnCall;
A_indexExpr indexExpr;
A_arrayExpr arrayExpr;
A_memberExpr memberExpr;
A_boolUnit boolUnit;
A_boolBiOpExpr boolBiOpExpr;
A_boolUOpExpr boolUOpExpr;
A_comExpr comExpr;
A_leftVal leftVal;
A_assignStmt assignStmt;
A_rightValList rightValList;
A_varDefScalar varDefScalar;
A_varDefArray varDefArray;
A_varDeclScalar varDeclScalar;
A_varDeclArray varDeclArray;
A_varDeclStmt varDeclStmt;
A_varDeclList varDeclList;
A_structDef structDef;
A_paramDecl paramDecl;
A_fnDecl fnDecl;
A_fnDef fnDef;
A_codeBlockStmt codeBlockStmt;
A_ifStmt ifStmt;
A_whileStmt whileStmt;
A_fnDeclStmt fnDeclStmt;
A_callStmt callStmt;
A_returnStmt returnStmt;
A_programElement programElement;
A_codeBlockStmtList codeBlockStmtList;
A_programElementList programElementList;
A_program program;
A_tokenId tokenId;
A_tokenNum tokenNum;
  
}

%token <pos> ADD
%token <pos> SUB
%token <pos> MUL
%token <pos> DIV

%token <pos> LP RP LSB RSB LB RB
%token <pos> COMMA SEMICOLON 
%token <pos> EQ NE LT GT LE GE
%token <pos> ASSIGN
%token <pos> AND OR NOT
%token <pos> ARROW DOT COLON
%token <pos> IF ELSE WHILE RETURN CONTINUE BREAK
%token <pos> INT
%token <pos> FN LET
%token <pos> STRUCT

%token <tokenNum> UNUM

%token <tokenId> ID

//优先级自下而上递增
%left COMMA
%right ASSIGN
%left OR
%left AND 
%left EQ NE

%left LT GT LE GE 
%left ADD SUB
%left MUL DIV
%nonassoc NEG
%right NOT
%nonassoc LOWER_THAN_LP
%left LP RP LSB RSB DOT 

%type <tokenNum> NUM
%type <program> Program
%type <arithExpr> ArithExpr
%type <programElementList> ProgramElementList
%type <programElement> ProgramElement
%type <exprUnit> ExprUnit
%type <structDef> StructDef
%type <varDeclStmt> VarDeclStmt
%type <fnDeclStmt> FnDeclStmt
%type <fnDef> FnDef
%type <fnCall> FnCall
%type <arrayExpr> ArrayExpr
%type <memberExpr> MemberExpr
%type <leftVal> LeftVal
%type <varDecl> VarDecl
%type <varDef> VarDef
%type <type> Type
%type <varDeclList> VarDeclList
%type <rightVal> RightVal
%type <rightValList> RightValList
%type <assignStmt> AssignStmt
%type <paramDecl> ParamDecl
%type <fnDecl> FnDecl
%type <codeBlockStmt> CodeBlockStmt
%type <ifStmt> IfStmt
%type <whileStmt> WhileStmt
%type <callStmt> CallStmt
%type <returnStmt> ReturnStmt
%type <codeBlockStmtList> CodeBlockStmtList
%type <boolExpr> BoolExpr
%type <boolUnit> BoolUnit
%type <boolUnit> BoolUnit_
%type <codeBlockStmtList> CodeBlock
%type <pos> ContinueStmt
%type <pos> BreakStmt
%type <boolBiOpExpr> BoolBiOpExpr
%type <comExpr> ComExpr
%type <boolUOpExpr> BoolUOpExpr

%start Program

%%                   /* beginning of rules section */
Program: ProgramElementList 
{  
  root = A_Program($1);
  $$ = A_Program($1);
}
;

ProgramElementList: ProgramElement ProgramElementList
{
  $$ = A_ProgramElementList($1, $2);
}
|
{
  $$ = nullptr;
}
;

NUM:UNUM
{
    $$=A_TokenNum($1->pos,$1->num);
}
| SUB UNUM %prec NEG
{
    $$=A_TokenNum($1,-$2->num);
}
;


Type: INT
{
    $$ = A_NativeType($1, A_intTypeKind);
}
| ID
{
    $$ = A_StructType($1->pos, $1->id);
}
;

RightValList: RightVal
{
    $$ = A_RightValList($1, nullptr);
}
| RightVal COMMA RightValList
{
    $$ = A_RightValList($1, $3);
}
;

FnCall: ID LP RightValList RP
{
    $$ = A_FnCall($1->pos, $1->id, $3);
}
| ID LP RP     // 无参数
{
    $$ = A_FnCall($1->pos, $1->id, nullptr);
}
;

ArrayExpr: ID LSB NUM RSB
{
    $$ = A_ArrayExpr($1->pos, A_IdExprLVal($1->pos, $1->id), A_NumIndexExpr($3->pos, $3->num));
}
| ID LSB ID RSB
{
    $$ = A_ArrayExpr($1->pos, A_IdExprLVal($1->pos, $1->id), A_IdIndexExpr($3->pos, $3->id));
}
| LeftVal LSB NUM RSB
{
    $$ = A_ArrayExpr($1->pos, $1, A_NumIndexExpr($3->pos, $3->num));
}
| LeftVal LSB ID RSB
{
    $$ = A_ArrayExpr($1->pos, $1, A_IdIndexExpr($3->pos, $3->id));
}
;

MemberExpr: ID DOT ID
{
    $$ = A_MemberExpr($1->pos, A_IdExprLVal($1->pos, $1->id), $3->id);
}
| LeftVal DOT ID
{
    $$ = A_MemberExpr($1->pos, $1, $3->id);
}
;

//表达式单元
ExprUnit: NUM
{
    $$ = A_NumExprUnit($1->pos, $1->num);
}
| ID
{
    $$ = A_IdExprUnit($1->pos, $1->id);
}
| LP ArithExpr RP
{
    $$ = A_ArithExprUnit($2->pos, $2);
}

| FnCall
{
    $$ = A_CallExprUnit($1->pos, $1);
} 
| ArrayExpr
{
    $$ = A_ArrayExprUnit($1->pos, $1);
}   
| MemberExpr
{
    $$ = A_MemberExprUnit($1->pos, $1);
}
;

//算数表达式
ArithExpr: ArithExpr ADD ArithExpr
{
    $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_add, $1, $3));
}
| ArithExpr SUB ArithExpr
{
    $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_sub, $1, $3));
}
| ArithExpr MUL ArithExpr
{
    $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_mul, $1, $3));
}
| ArithExpr DIV ArithExpr
{
    $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_div, $1, $3));
}
| ExprUnit
{
    $$ = A_ExprUnit($1->pos, $1);
}
;
BoolUOpExpr: NOT BoolUnit
{
  $$ = A_BoolUOpExpr($1, A_not, $2);
}
;

BoolBiOpExpr: BoolExpr  AND  BoolExpr 
{
    $$ = A_BoolBiOpExpr($1->pos, A_and, $1, $3);
} 
| BoolExpr   OR  BoolExpr 
{
    $$ = A_BoolBiOpExpr($1->pos, A_or, $1, $3);
}
;

BoolExpr: BoolBiOpExpr
{
    $$ = A_BoolBiOp_Expr($1->pos, $1);
}
| BoolUnit
{
    $$ = A_BoolExpr($1->pos, $1);
}
;

//比较表达式
ComExpr: ExprUnit LT ExprUnit
{
  $$ = A_ComExpr($1->pos, A_lt, $1, $3);
}
| ExprUnit LE ExprUnit
{
  $$ = A_ComExpr($1->pos, A_le, $1, $3);
}
| ExprUnit GT ExprUnit
{
  $$ = A_ComExpr($1->pos, A_gt, $1, $3);
}
| ExprUnit GE ExprUnit
{
  $$ = A_ComExpr($1->pos, A_ge, $1, $3);
}
| ExprUnit EQ ExprUnit
{
  $$ = A_ComExpr($1->pos, A_eq, $1, $3);
}
| ExprUnit NE ExprUnit
{
  $$ = A_ComExpr($1->pos, A_ne, $1, $3);
}
;

BoolUnit:LP ComExpr RP
{
  $$ = A_ComExprUnit($1, $2);
}
| LP BoolExpr RP
{
  $$ = A_BoolExprUnit($1, $2);
}
| BoolUOpExpr %prec LOWER_THAN_LP
{
    $$=A_BoolUOpExprUnit($1->pos, $1);
}
;

BoolUnit_: LP ComExpr RP 
{
  $$ = A_ComExprUnit($1, $2);
}
| LP BoolExpr RP
{
  $$ = A_BoolExprUnit($1, $2);
}
| LP BoolUOpExpr RP 
{
    $$=A_BoolUOpExprUnit($1, $2);
}
;


RightVal: ArithExpr
{
    $$ = A_ArithExprRVal($1->pos, $1);
}
;

LeftVal: ID  %prec LOWER_THAN_LP
{
    $$ = A_IdExprLVal($1->pos, $1->id);
}
| ArrayExpr
{
    $$ = A_ArrExprLVal($1->pos, $1);
}
| MemberExpr
{
    $$ = A_MemberExprLVal($1->pos, $1);
}
;

AssignStmt: LeftVal ASSIGN RightVal SEMICOLON
{
    $$ = A_AssignStmt($1->pos, $1, $3);
}
;

VarDecl: ID COLON Type
{
    $$ = A_VarDecl_Scalar($1->pos, A_VarDeclScalar($1->pos, $1->id, $3));
}
| ArrayExpr COLON Type
{
    $$ = A_VarDecl_Array($1->pos, A_VarDeclArray($1->pos, $1->arr->u.id, $1->idx->u.num, $3));
}
| ArrayExpr
{
    $$ = A_VarDecl_Array($1->pos, A_VarDeclArray($1->pos, $1->arr->u.id, $1->idx->u.num, nullptr));
}
| ID  // 允许在声明时不指定类型
{
    $$ = A_VarDecl_Scalar($1->pos, A_VarDeclScalar($1->pos, $1->id, nullptr));
}
;

VarDef: ID COLON Type ASSIGN RightVal
{
    $$ = A_VarDef_Scalar($1->pos, A_VarDefScalar($1->pos, $1->id, $3, $5));
}
| ID ASSIGN RightVal
{
    $$ = A_VarDef_Scalar($1->pos, A_VarDefScalar($1->pos, $1->id, nullptr, $3));
}
| ArrayExpr COLON Type ASSIGN LB RightValList RB
{
    $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->arr->u.id, $1->idx->u.num, $3, $6));
}
| ArrayExpr ASSIGN LB RightValList RB
{
    $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->arr->u.id, $1->idx->u.num, nullptr, $4));
}
| ArrayExpr COLON Type ASSIGN LB RB
{
    $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->arr->u.id, $1->idx->u.num, $3, nullptr));
}
| ArrayExpr ASSIGN LB RB
{
    $$ = A_VarDef_Array($1->pos, A_VarDefArray($1->pos, $1->arr->u.id, $1->idx->u.num, nullptr, nullptr));
}
;


VarDeclStmt: LET VarDecl SEMICOLON
{
    $$ = A_VarDeclStmt($1, $2);
}
| LET VarDef SEMICOLON
{
    $$ = A_VarDefStmt($1, $2);
}
;

VarDeclList: VarDecl
{
    $$ = A_VarDeclList($1, nullptr);
}
| VarDecl COMMA VarDeclList
{
    $$ = A_VarDeclList($1, $3);
}
;

StructDef: STRUCT ID LB VarDeclList RB
{
    $$ = A_StructDef($1, $2->id, $4);
}
;

FnDecl: FN ID LP ParamDecl RP 
{
    $$ = A_FnDecl($1, $2->id, $4, nullptr);
}
| FN ID LP ParamDecl RP ARROW Type
{
    $$ = A_FnDecl($1, $2->id, $4, $7);
}
;


ParamDecl: VarDeclList
{
    $$ = A_ParamDecl($1);
}
| 
{
    $$ = A_ParamDecl(nullptr);
}
;

CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList
{
    $$ = A_CodeBlockStmtList($1, $2);
}
| CodeBlockStmt
{
    $$ = A_CodeBlockStmtList($1, nullptr);
}
;

FnDef: FnDecl CodeBlock
{
    $$ = A_FnDef($1->pos, $1, $2);
}
;

IfStmt: IF BoolUnit_ CodeBlock ELSE CodeBlock
{
    $$ = A_IfStmt($1, $2, $3, $5);
}
| IF BoolUnit_ CodeBlock
{
    $$ = A_IfStmt($1, $2, $3, nullptr);
}
;

WhileStmt: WHILE BoolUnit_ CodeBlock
{
    $$ = A_WhileStmt($1, $2, $3);
}
;

CallStmt: FnCall SEMICOLON
{
    $$ = A_CallStmt($1->pos, $1);
}
;

ReturnStmt: RETURN RightVal SEMICOLON
{
    $$ = A_ReturnStmt($1, $2);
}
| RETURN SEMICOLON
{
    $$ = A_ReturnStmt($1, nullptr);
}
;

ContinueStmt: CONTINUE SEMICOLON
{
    $$ = $1;
}
;

BreakStmt: BREAK SEMICOLON
{
    $$ = $1;
}
;

CodeBlockStmt: SEMICOLON
{
    $$ = A_BlockNullStmt($1);
}
| VarDeclStmt
{
    $$ = A_BlockVarDeclStmt($1->pos, $1);
}
| AssignStmt
{
    $$ = A_BlockAssignStmt($1->pos, $1);
}
| CallStmt
{
    $$ = A_BlockCallStmt($1->pos, $1);
}
| IfStmt
{
    $$ = A_BlockIfStmt($1->pos, $1);
}
| WhileStmt
{
    $$ = A_BlockWhileStmt($1->pos, $1);
}
| ReturnStmt
{
    $$ = A_BlockReturnStmt($1->pos, $1);
}
| ContinueStmt
{
    $$ = A_BlockContinueStmt($1);
}
| BreakStmt
{
    $$ = A_BlockBreakStmt($1);
}
;

CodeBlock: LB RB{
    $$ = nullptr;
}
| LB CodeBlockStmtList RB
{
    $$ = $2;
}
;

FnDeclStmt: FnDecl SEMICOLON
{
    $$ = A_FnDeclStmt($1->pos, $1);
}
;

ProgramElement: VarDeclStmt
{
  $$ = A_ProgramVarDeclStmt($1->pos, $1);
}
| StructDef
{
  $$ = A_ProgramStructDef($1->pos, $1);
}
| FnDeclStmt
{
  $$ = A_ProgramFnDeclStmt($1->pos, $1);
}
| FnDef
{
  $$ = A_ProgramFnDef($1->pos, $1);
}
| SEMICOLON
{
  $$ = A_ProgramNullStmt($1);
}
;




%%

extern "C"{
void yyerror(const char * s)
{
  fprintf(stderr, "%s\n",s);
}
int yywrap()
{
  return(1);
}
}


