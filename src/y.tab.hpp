<<<<<<< HEAD
/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
=======
/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
>>>>>>> 24f-assignment4
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
<<<<<<< HEAD
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
=======
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */
>>>>>>> 24f-assignment4

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

<<<<<<< HEAD
/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */
=======
/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */
>>>>>>> 24f-assignment4

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

<<<<<<< HEAD
/* Token type.  */
=======
/* Token kinds.  */
>>>>>>> 24f-assignment4
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
<<<<<<< HEAD
    ID = 258,
    UNUM = 259,
    INT = 260,
    LET = 261,
    STRUCT = 262,
    FN = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    DOT = 267,
    CONTINUE = 268,
    BREAK = 269,
    RETURN = 270,
    SEMICOLON = 271,
    COMMA = 272,
    COLON = 273,
    ARROW = 274,
    ADD = 275,
    SUB = 276,
    MUL = 277,
    DIV = 278,
    OR = 279,
    AND = 280,
    LT = 281,
    LE = 282,
    GT = 283,
    GE = 284,
    EQ = 285,
    NE = 286,
    NOT = 287,
    LP = 288,
    RP = 289,
    LB = 290,
    RB = 291,
    LSB = 292,
    RSB = 293,
    AS = 294,
    NEG = 295
  };
#endif
/* Tokens.  */
#define ID 258
#define UNUM 259
#define INT 260
#define LET 261
#define STRUCT 262
#define FN 263
#define IF 264
#define ELSE 265
#define WHILE 266
#define DOT 267
#define CONTINUE 268
#define BREAK 269
#define RETURN 270
#define SEMICOLON 271
#define COMMA 272
#define COLON 273
#define ARROW 274
#define ADD 275
#define SUB 276
#define MUL 277
#define DIV 278
#define OR 279
#define AND 280
#define LT 281
#define LE 282
#define GT 283
#define GE 284
#define EQ 285
#define NE 286
#define NOT 287
#define LP 288
#define RP 289
#define LB 290
#define RB 291
#define LSB 292
#define RSB 293
#define AS 294
#define NEG 295
=======
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ADD = 258,                     /* ADD  */
    SUB = 259,                     /* SUB  */
    MUL = 260,                     /* MUL  */
    DIV = 261,                     /* DIV  */
    LP = 262,                      /* LP  */
    RP = 263,                      /* RP  */
    LSB = 264,                     /* LSB  */
    RSB = 265,                     /* RSB  */
    LB = 266,                      /* LB  */
    RB = 267,                      /* RB  */
    COMMA = 268,                   /* COMMA  */
    SEMICOLON = 269,               /* SEMICOLON  */
    EQ = 270,                      /* EQ  */
    NE = 271,                      /* NE  */
    LT = 272,                      /* LT  */
    GT = 273,                      /* GT  */
    LE = 274,                      /* LE  */
    GE = 275,                      /* GE  */
    ASSIGN = 276,                  /* ASSIGN  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    NOT = 279,                     /* NOT  */
    ARROW = 280,                   /* ARROW  */
    DOT = 281,                     /* DOT  */
    COLON = 282,                   /* COLON  */
    IF = 283,                      /* IF  */
    ELSE = 284,                    /* ELSE  */
    WHILE = 285,                   /* WHILE  */
    RETURN = 286,                  /* RETURN  */
    CONTINUE = 287,                /* CONTINUE  */
    BREAK = 288,                   /* BREAK  */
    INT = 289,                     /* INT  */
    FN = 290,                      /* FN  */
    LET = 291,                     /* LET  */
    STRUCT = 292,                  /* STRUCT  */
    UNUM = 293,                    /* UNUM  */
    ID = 294,                      /* ID  */
    NEG = 295,                     /* NEG  */
    LOWER_THAN_LP = 296            /* LOWER_THAN_LP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define LP 262
#define RP 263
#define LSB 264
#define RSB 265
#define LB 266
#define RB 267
#define COMMA 268
#define SEMICOLON 269
#define EQ 270
#define NE 271
#define LT 272
#define GT 273
#define LE 274
#define GE 275
#define ASSIGN 276
#define AND 277
#define OR 278
#define NOT 279
#define ARROW 280
#define DOT 281
#define COLON 282
#define IF 283
#define ELSE 284
#define WHILE 285
#define RETURN 286
#define CONTINUE 287
#define BREAK 288
#define INT 289
#define FN 290
#define LET 291
#define STRUCT 292
#define UNUM 293
#define ID 294
#define NEG 295
#define LOWER_THAN_LP 296
>>>>>>> 24f-assignment4

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
<<<<<<< HEAD
#line 17 "parser.yacc"

  A_pos pos;
  A_tokenId tokenId;
  A_tokenNum tokenNum;
  A_type type;
  A_program program;
  A_programElementList programElementList;
  A_programElement programElement;
  A_fnDef fnDef;
  A_fnDeclStmt fnDeclStmt;
  A_structDef structDef;
  A_varDeclStmt varDeclStmt;
  A_codeBlockStmt codeBlockStmt;
  A_codeBlockStmtList codeBlockStmtList;
  A_returnStmt returnStmt;
  A_whileStmt whileStmt;
  A_ifStmt ifStmt;
  A_callStmt callStmt;
  A_assignStmt assignStmt;
  A_paramDecl paramDecl;
  A_fnDecl fnDecl;
  A_varDeclList varDeclList;
  A_varDef varDef;
  A_varDecl varDecl;
  A_leftVal leftVal;
  A_rightVal rightVal;
  A_boolUnit boolUnit;
  A_boolExpr boolExpr;
  A_arithExpr arithExpr;
  A_exprUnit exprUnit;
  A_fnCall fnCall;
  A_rightValList rightValList;
  A_arrayExpr arrayExpr;

#line 172 "y.tab.hpp"
=======
#line 19 "parser.yacc"

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
  

#line 196 "y.tab.hpp"
>>>>>>> 24f-assignment4

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

<<<<<<< HEAD
int yyparse (void);

=======

int yyparse (void);


>>>>>>> 24f-assignment4
#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
