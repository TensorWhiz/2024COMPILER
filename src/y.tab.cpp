<<<<<<< HEAD
/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
=======
/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

<<<<<<< HEAD
=======
/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

>>>>>>> 24f-assignment4
/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

<<<<<<< HEAD
/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"
=======
/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"
>>>>>>> 24f-assignment4

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.yacc"

#include <stdio.h>
#include "TeaplAst.h"
<<<<<<< HEAD

=======
>>>>>>> 24f-assignment4
extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(const char *s); 
extern int  yywrap();
<<<<<<< HEAD
}


#line 85 "y.tab.cpp"
=======

}


#line 86 "y.tab.cpp"
>>>>>>> 24f-assignment4

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

<<<<<<< HEAD
/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
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

#line 252 "y.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

=======
#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_SUB = 4,                        /* SUB  */
  YYSYMBOL_MUL = 5,                        /* MUL  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_LP = 7,                         /* LP  */
  YYSYMBOL_RP = 8,                         /* RP  */
  YYSYMBOL_LSB = 9,                        /* LSB  */
  YYSYMBOL_RSB = 10,                       /* RSB  */
  YYSYMBOL_LB = 11,                        /* LB  */
  YYSYMBOL_RB = 12,                        /* RB  */
  YYSYMBOL_COMMA = 13,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 14,                 /* SEMICOLON  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_NE = 16,                        /* NE  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_LE = 19,                        /* LE  */
  YYSYMBOL_GE = 20,                        /* GE  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_ARROW = 25,                     /* ARROW  */
  YYSYMBOL_DOT = 26,                       /* DOT  */
  YYSYMBOL_COLON = 27,                     /* COLON  */
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_ELSE = 29,                      /* ELSE  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 32,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 33,                     /* BREAK  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_FN = 35,                        /* FN  */
  YYSYMBOL_LET = 36,                       /* LET  */
  YYSYMBOL_STRUCT = 37,                    /* STRUCT  */
  YYSYMBOL_UNUM = 38,                      /* UNUM  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_NEG = 40,                       /* NEG  */
  YYSYMBOL_LOWER_THAN_LP = 41,             /* LOWER_THAN_LP  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Program = 43,                   /* Program  */
  YYSYMBOL_ProgramElementList = 44,        /* ProgramElementList  */
  YYSYMBOL_NUM = 45,                       /* NUM  */
  YYSYMBOL_Type = 46,                      /* Type  */
  YYSYMBOL_RightValList = 47,              /* RightValList  */
  YYSYMBOL_FnCall = 48,                    /* FnCall  */
  YYSYMBOL_ArrayExpr = 49,                 /* ArrayExpr  */
  YYSYMBOL_MemberExpr = 50,                /* MemberExpr  */
  YYSYMBOL_ExprUnit = 51,                  /* ExprUnit  */
  YYSYMBOL_ArithExpr = 52,                 /* ArithExpr  */
  YYSYMBOL_BoolUOpExpr = 53,               /* BoolUOpExpr  */
  YYSYMBOL_BoolBiOpExpr = 54,              /* BoolBiOpExpr  */
  YYSYMBOL_BoolExpr = 55,                  /* BoolExpr  */
  YYSYMBOL_ComExpr = 56,                   /* ComExpr  */
  YYSYMBOL_BoolUnit = 57,                  /* BoolUnit  */
  YYSYMBOL_BoolUnit_ = 58,                 /* BoolUnit_  */
  YYSYMBOL_RightVal = 59,                  /* RightVal  */
  YYSYMBOL_LeftVal = 60,                   /* LeftVal  */
  YYSYMBOL_AssignStmt = 61,                /* AssignStmt  */
  YYSYMBOL_VarDecl = 62,                   /* VarDecl  */
  YYSYMBOL_VarDef = 63,                    /* VarDef  */
  YYSYMBOL_VarDeclStmt = 64,               /* VarDeclStmt  */
  YYSYMBOL_VarDeclList = 65,               /* VarDeclList  */
  YYSYMBOL_StructDef = 66,                 /* StructDef  */
  YYSYMBOL_FnDecl = 67,                    /* FnDecl  */
  YYSYMBOL_ParamDecl = 68,                 /* ParamDecl  */
  YYSYMBOL_CodeBlockStmtList = 69,         /* CodeBlockStmtList  */
  YYSYMBOL_FnDef = 70,                     /* FnDef  */
  YYSYMBOL_IfStmt = 71,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 72,                 /* WhileStmt  */
  YYSYMBOL_CallStmt = 73,                  /* CallStmt  */
  YYSYMBOL_ReturnStmt = 74,                /* ReturnStmt  */
  YYSYMBOL_ContinueStmt = 75,              /* ContinueStmt  */
  YYSYMBOL_BreakStmt = 76,                 /* BreakStmt  */
  YYSYMBOL_CodeBlockStmt = 77,             /* CodeBlockStmt  */
  YYSYMBOL_CodeBlock = 78,                 /* CodeBlock  */
  YYSYMBOL_FnDeclStmt = 79,                /* FnDeclStmt  */
  YYSYMBOL_ProgramElement = 80             /* ProgramElement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


>>>>>>> 24f-assignment4


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

<<<<<<< HEAD
=======
/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

>>>>>>> 24f-assignment4
#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

<<<<<<< HEAD
=======

>>>>>>> 24f-assignment4
/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

<<<<<<< HEAD
=======

>>>>>>> 24f-assignment4
#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
<<<<<<< HEAD
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
=======
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
>>>>>>> 24f-assignment4
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

<<<<<<< HEAD
#if ! defined yyoverflow || YYERROR_VERBOSE
=======
#if !defined yyoverflow
>>>>>>> 24f-assignment4

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
<<<<<<< HEAD
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */

=======
#endif /* !defined yyoverflow */
>>>>>>> 24f-assignment4

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
<<<<<<< HEAD
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

#define YYUNDEFTOK  2
#define YYMAXUTOK   295
=======
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296
>>>>>>> 24f-assignment4


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
<<<<<<< HEAD
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
=======
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)
>>>>>>> 24f-assignment4

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
<<<<<<< HEAD
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   154,   159,   164,   168,   172,   176,   180,
     186,   190,   194,   198,   202,   208,   212,   218,   222,   228,
     232,   236,   240,   244,   248,   254,   258,   262,   268,   272,
     276,   280,   284,   288,   292,   296,   302,   306,   310,   314,
     318,   322,   326,   330,   336,   342,   346,   350,   356,   362,
     367,   371,   376,   380,   386,   392,   396,   402,   406,   410,
     414,   420,   424,   430,   434,   438,   442,   448,   452,   458,
     463,   467,   472,   476,   482,   487,   491,   496,   500,   506,
     512,   518,   522,   528,   534,   538,   544,   550,   554,   558,
     562,   566,   570,   574,   578,   582,   588,   593,   598,   604,
     610,   614,   620
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
=======
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   143,   143,   150,   155,   160,   164,   171,   175,   181,
     185,   191,   195,   201,   205,   209,   213,   219,   223,   230,
     234,   238,   243,   247,   251,   258,   262,   266,   270,   274,
     279,   285,   289,   295,   299,   306,   310,   314,   318,   322,
     326,   332,   336,   340,   346,   350,   354,   361,   367,   371,
     375,   381,   387,   391,   395,   399,   405,   409,   413,   417,
     421,   425,   432,   436,   442,   446,   452,   458,   462,   469,
     474,   479,   483,   489,   495,   499,   505,   511,   517,   521,
     527,   533,   539,   543,   547,   551,   555,   559,   563,   567,
     571,   577,   580,   586,   592,   596,   600,   604,   608
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

>>>>>>> 24f-assignment4
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
<<<<<<< HEAD
  "$end", "error", "$undefined", "ID", "UNUM", "INT", "LET", "STRUCT",
  "FN", "IF", "ELSE", "WHILE", "DOT", "CONTINUE", "BREAK", "RETURN",
  "SEMICOLON", "COMMA", "COLON", "ARROW", "ADD", "SUB", "MUL", "DIV", "OR",
  "AND", "LT", "LE", "GT", "GE", "EQ", "NE", "NOT", "LP", "RP", "LB", "RB",
  "LSB", "RSB", "AS", "NEG", "$accept", "Program", "ProgramElementList",
  "ProgramElement", "ArithExpr", "NUM", "ArrayExpr", "ExprUnit",
  "BoolExpr", "BoolUnit", "BoolUnit_", "AssignStmt", "LeftVal", "RightVal",
  "RightValList", "RightValRestList", "RightValRest", "FnCall",
  "VarDeclStmt", "VarDecl", "FieldDecl", "VarDef", "Type", "VarDeclList",
  "VarDeclRestList", "VarDeclRest", "FieldDeclList", "FieldDeclRestList",
  "FieldDeclRest", "StructDef", "ParamDecl", "FnDecl", "FnDeclStmt",
  "ReturnStmt", "FnDef", "CodeBlockStmt", "CodeBlockStmtList", "CodeBlock",
  "CallStmt", "IfStmt", "WhileStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-156)
=======
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "SUB", "MUL",
  "DIV", "LP", "RP", "LSB", "RSB", "LB", "RB", "COMMA", "SEMICOLON", "EQ",
  "NE", "LT", "GT", "LE", "GE", "ASSIGN", "AND", "OR", "NOT", "ARROW",
  "DOT", "COLON", "IF", "ELSE", "WHILE", "RETURN", "CONTINUE", "BREAK",
  "INT", "FN", "LET", "STRUCT", "UNUM", "ID", "NEG", "LOWER_THAN_LP",
  "$accept", "Program", "ProgramElementList", "NUM", "Type",
  "RightValList", "FnCall", "ArrayExpr", "MemberExpr", "ExprUnit",
  "ArithExpr", "BoolUOpExpr", "BoolBiOpExpr", "BoolExpr", "ComExpr",
  "BoolUnit", "BoolUnit_", "RightVal", "LeftVal", "AssignStmt", "VarDecl",
  "VarDef", "VarDeclStmt", "VarDeclList", "StructDef", "FnDecl",
  "ParamDecl", "CodeBlockStmtList", "FnDef", "IfStmt", "WhileStmt",
  "CallStmt", "ReturnStmt", "ContinueStmt", "BreakStmt", "CodeBlockStmt",
  "CodeBlock", "FnDeclStmt", "ProgramElement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-85)
>>>>>>> 24f-assignment4

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

<<<<<<< HEAD
#define YYTABLE_NINF (-48)
=======
#define YYTABLE_NINF (-55)
>>>>>>> 24f-assignment4

#define yytable_value_is_error(Yyn) \
  0

<<<<<<< HEAD
  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     135,     8,    28,    67,  -156,    73,  -156,   135,  -156,  -156,
      79,  -156,  -156,    72,    94,    97,    40,    82,  -156,  -156,
    -156,   124,  -156,    59,   102,    23,  -156,  -156,   113,   119,
      93,    95,    95,   115,   118,    14,  -156,  -156,  -156,    55,
     134,  -156,  -156,   124,   100,  -156,  -156,  -156,  -156,  -156,
      90,  -156,   148,   123,    16,    23,   126,  -156,    -3,  -156,
      20,  -156,  -156,    80,   151,   117,    87,   152,  -156,   137,
      23,    18,   138,   138,  -156,  -156,  -156,   154,   169,   104,
      23,  -156,  -156,  -156,    23,  -156,    43,    98,    23,    23,
      23,    23,   171,    59,   102,   113,  -156,   151,  -156,    59,
     102,   119,  -156,   152,   156,   159,   143,   -13,    33,   129,
      -9,  -156,   168,  -156,  -156,  -156,   141,   142,   165,  -156,
      59,   147,  -156,     1,     1,  -156,  -156,    21,  -156,   145,
    -156,  -156,  -156,   146,  -156,  -156,    59,    23,  -156,   159,
    -156,   -13,    33,   153,   136,   120,    23,    23,    23,    23,
      23,    23,   -13,   -13,  -156,   138,  -156,  -156,  -156,   149,
      23,   167,   172,  -156,  -156,  -156,  -156,   136,  -156,    23,
      23,    23,    23,    23,    23,  -156,   155,   157,   158,   160,
     161,   162,   173,  -156,  -156,   164,   150,    59,    59,   163,
     166,   170,   174,   175,   176,  -156,  -156,  -156,  -156,  -156,
    -156,    23,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,   177,  -156
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     9,     0,     2,     4,     5,     6,
       0,     7,     8,    58,     0,     0,     0,     0,     1,     3,
      83,    97,    86,     0,     0,     0,    55,    56,    75,    70,
      45,     0,     0,     0,     0,     0,    95,    46,    88,     0,
       0,    87,    92,    97,     0,    89,    90,    91,    68,    67,
      57,    15,     0,     0,    20,     0,    48,    19,    23,    14,
       0,    64,    22,     0,    77,     0,    58,    72,    80,     0,
      50,     0,     0,     0,    93,    94,    85,     0,     0,     0,
       0,    99,    96,    98,     0,    16,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    77,    79,     0,
       0,     0,    69,    72,    81,    52,     0,     0,     0,     0,
       0,    27,   100,   102,    84,    47,     0,     0,     0,    63,
       0,     0,    21,    10,    11,    12,    13,    24,    61,     0,
      78,    76,    57,     0,    73,    71,     0,     0,    49,    52,
      54,     0,     0,    35,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,    17,    18,    44,    59,
      50,     0,    60,    82,    53,    51,    35,     0,    43,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,    26,    25,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,    39,    40,
      41,    50,    66,    62,    59,    28,    29,    30,    31,    32,
      33,     0,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,   186,  -156,   -48,   -11,    31,   -70,   -65,   -93,
     179,  -156,    42,   -25,  -155,    62,  -156,    48,    50,   -17,
     107,  -156,   -91,  -156,   103,  -156,  -156,   106,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,   178,   -69,  -156,  -156,
    -156
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    56,    57,    58,    59,   145,   111,
      72,    38,    60,   105,   106,   138,   139,    62,     8,    14,
      64,    15,    50,    68,   102,   103,    65,    96,    97,     9,
      69,    10,    11,    42,    12,    43,    44,    22,    45,    46,
      47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   109,   128,   112,   113,   186,   110,    87,   132,   -46,
      77,    13,    67,    53,   143,   152,   153,    54,    51,   141,
     142,    54,    51,    90,    91,   154,    54,    51,   -45,   159,
      76,    16,    92,   -47,   -46,    52,    54,    51,   144,    52,
     123,   124,   125,   126,    52,   163,   211,    55,   166,    70,
     107,   108,    37,   -45,    52,   118,    55,    79,   -47,   119,
      87,   120,    48,    39,    49,   141,   108,    78,   117,    40,
      17,    41,   167,    18,    37,    28,   176,   177,   178,   179,
     180,   181,   121,   129,   134,    39,   184,   182,   183,   133,
      23,    40,    79,    41,    80,    20,   203,   204,    93,   189,
     190,   191,   192,   193,   194,    99,    51,   116,    51,    24,
      26,    25,   164,    27,    21,    29,    63,    94,    88,    89,
      90,    91,    66,    52,   100,    52,    70,    30,    71,    84,
       1,    74,   122,    31,    75,    32,    83,    33,    34,    35,
      36,     1,     2,     3,   152,   153,    88,    89,    90,    91,
      81,     4,    85,    98,   175,   146,   147,   148,   149,   150,
     151,    86,   169,   170,   171,   172,   173,   174,    95,   101,
     114,   104,   115,    21,   127,   136,   137,   140,   155,   156,
     157,   158,   160,   161,   162,   187,   202,   168,   185,   195,
     188,   196,   197,    19,   198,   199,   200,   205,   153,   201,
     206,   165,   130,   131,   207,     0,   135,     0,   208,   209,
     210,    73,     0,   212,     0,     0,     0,     0,     0,     0,
       0,    82
=======
/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      87,   -85,   -27,   -20,    21,    55,   -85,   -85,   -85,    64,
     -85,   -85,    87,    98,    93,   142,   -85,     4,    80,    99,
      96,   -85,   103,   -85,   -85,   -85,    77,    14,    27,    86,
       3,   107,     3,    72,   101,   -85,   -85,    77,   -85,   -85,
     130,   130,    25,   133,   141,     7,   145,   -85,   132,   -85,
     -85,   148,   -85,   -85,   -85,   -85,   -85,   -85,   118,    17,
     117,   151,   -85,   153,   127,   -85,   158,   170,    27,     7,
     -85,   -85,   112,   136,   -85,   179,   -85,   -85,   -85,   -85,
     165,    70,   166,   178,   180,   -85,   177,    34,   181,   181,
     -85,   182,   -85,   -85,    89,   -85,    27,   -85,   -85,     3,
       3,    77,   168,   -85,   -85,   -85,   173,    27,    27,    27,
      27,    27,   -85,   183,   184,   187,   -85,   -85,   -85,    34,
      16,   155,   186,   -85,    61,   191,   -85,   162,   -85,   -85,
     -85,   192,   188,   -85,   -85,   -85,     3,   -85,    22,    22,
     -85,   -85,   -85,   -85,    27,    91,   155,   -85,   144,   193,
      34,   -85,    27,    27,    27,    27,    27,    27,   -85,   -85,
      16,    16,   -85,   181,   -85,   -85,   -85,   -85,   -85,   194,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   185,
     -85,   -85
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    98,     0,     0,     0,     0,     2,    94,    95,     0,
      97,    96,     4,     0,    55,    49,    50,     0,     0,     0,
       0,     1,     0,    93,    73,     3,    70,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    63,     0,    91,    82,
       0,     0,     0,     0,     0,    48,     0,    49,     0,    84,
      83,     0,    86,    87,    85,    88,    89,    90,    72,    55,
      54,    64,    69,     0,     0,     5,     0,     0,     0,    20,
      19,    22,    23,    24,    29,    47,    57,    17,     7,     8,
      52,     0,    53,     0,     0,    18,     0,     0,     0,     0,
      79,     0,    80,    81,     0,    77,     0,    92,    71,     0,
       0,     0,    67,     6,    14,    13,     0,     0,     0,     0,
       0,     0,    61,     0,     9,     0,    16,    15,    66,     0,
       0,     0,    43,    33,     0,     0,    34,    75,    76,    78,
      12,     0,     0,    52,    53,    65,     0,    21,    25,    26,
      27,    28,    56,    59,     0,     0,    29,    43,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,    46,    45,
       0,     0,    44,     0,    11,    51,    68,    10,    60,     0,
      42,    41,    39,    40,    35,    37,    36,    38,    31,    32,
      74,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   196,    79,   -32,   -83,   -13,    -2,    -1,   -65,
     -60,   116,   -85,   -80,   122,    84,   164,   -25,   -12,   -85,
     207,   -85,    -7,   -31,   -85,   -85,   -85,   154,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -84,   -85,   -85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,    70,    80,   113,    71,    72,    73,    74,
      75,   147,   123,   148,   149,   126,    88,   114,    17,    49,
      61,    19,     7,    62,     8,     9,    63,    51,    10,    52,
      53,    54,    55,    56,    57,    58,    24,    11,    12
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,    15,    16,    76,   127,   128,    86,   124,   106,    46,
      48,   131,    13,    33,    94,    50,    27,    91,    64,    14,
      47,    16,   121,   150,    60,    16,    27,   109,   110,    64,
      34,    64,    68,    29,    68,    60,    16,    78,    64,    90,
     120,   119,    79,    29,    99,    46,    48,   138,   139,   140,
     141,    50,    65,    66,   146,    21,    47,    16,   120,   106,
      20,   167,   169,    65,    69,    65,    69,   133,   134,   159,
     135,   132,    65,    69,    64,    22,    64,    68,    23,   180,
     178,   179,   112,   160,   161,   121,   142,   172,   173,   174,
     175,   176,   177,    64,    35,    64,    68,   130,    68,    60,
      16,     1,    27,   168,   166,    26,    67,    37,    65,    69,
      65,    83,    84,    36,    28,    38,    59,    39,    81,    29,
      30,   -49,     2,     3,     4,    77,   -49,    65,    69,    65,
      69,    40,    39,    41,    42,    43,    44,    87,   -49,     3,
      85,    33,    45,   -49,   100,   -50,    40,    92,    41,    42,
      43,    44,   170,    96,     3,    93,   -54,    45,    34,    95,
      97,   102,   -50,    31,   101,   103,   160,   161,   104,    32,
     152,   153,   154,   155,   156,   157,   107,   108,   109,   110,
     105,   137,   107,   108,   109,   110,   111,   115,   116,   118,
     117,   163,    22,   136,   158,   143,   129,   144,   145,   162,
     164,   171,   165,   122,   151,    89,   181,   160,    25,   125,
      18,     0,    98
>>>>>>> 24f-assignment4
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
      25,    71,    93,    72,    73,   160,    71,    55,    99,    12,
      35,     3,    29,    24,   107,    24,    25,     3,     4,    32,
      33,     3,     4,    22,    23,    34,     3,     4,    12,   120,
      16,     3,    12,    12,    37,    21,     3,     4,   108,    21,
      88,    89,    90,    91,    21,   136,   201,    33,   141,    33,
      32,    33,    21,    37,    21,    80,    33,    37,    37,    84,
     108,    18,     3,    21,     5,    32,    33,    12,    79,    21,
       3,    21,   142,     0,    43,    35,   146,   147,   148,   149,
     150,   151,    39,    94,   101,    43,   155,   152,   153,   100,
      18,    43,    37,    43,    39,    16,   187,   188,    18,   169,
     170,   171,   172,   173,   174,    18,     4,     3,     4,    37,
      16,    39,   137,    16,    35,    33,     3,    37,    20,    21,
      22,    23,     3,    21,    37,    21,    33,     3,    33,    39,
       6,    16,    34,     9,    16,    11,    36,    13,    14,    15,
      16,     6,     7,     8,    24,    25,    20,    21,    22,    23,
      16,    16,     4,    36,    34,    26,    27,    28,    29,    30,
      31,    38,    26,    27,    28,    29,    30,    31,    17,    17,
      16,    34,     3,    35,     3,    19,    17,    34,    10,    38,
      38,    16,    35,    38,    38,    18,    36,    34,    39,    34,
      18,    34,    34,     7,    34,    34,    34,    34,    25,    35,
      34,   139,    95,    97,    34,    -1,   103,    -1,    34,    34,
      34,    32,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    16,    42,    43,    44,    59,    70,
      72,    73,    75,     3,    60,    62,     3,     3,     0,    43,
      16,    35,    78,    18,    37,    39,    16,    16,    35,    33,
       3,     9,    11,    13,    14,    15,    16,    47,    52,    53,
      58,    59,    74,    76,    77,    79,    80,    81,     3,     5,
      63,     4,    21,    46,     3,    33,    45,    46,    47,    48,
      53,    54,    58,     3,    61,    67,     3,    60,    64,    71,
      33,    33,    51,    51,    16,    16,    16,    54,    12,    37,
      39,    16,    77,    36,    39,     4,    38,    45,    20,    21,
      22,    23,    12,    18,    37,    17,    68,    69,    36,    18,
      37,    17,    65,    66,    34,    54,    55,    32,    33,    48,
      49,    50,    78,    78,    16,     3,     3,    46,    54,    54,
      18,    39,    34,    45,    45,    45,    45,     3,    63,    46,
      61,    68,    63,    46,    60,    65,    19,    17,    56,    57,
      34,    32,    33,    50,    48,    49,    26,    27,    28,    29,
      30,    31,    24,    25,    34,    10,    38,    38,    16,    63,
      35,    38,    38,    63,    54,    56,    50,    48,    34,    26,
      27,    28,    29,    30,    31,    34,    48,    48,    48,    48,
      48,    48,    49,    49,    78,    39,    55,    18,    18,    48,
      48,    48,    48,    48,    48,    34,    34,    34,    34,    34,
      34,    35,    36,    63,    63,    34,    34,    34,    34,    34,
      34,    55,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    45,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    49,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    53,    53,    53,    54,    55,
      55,    56,    56,    57,    58,    59,    59,    60,    60,    60,
      60,    61,    61,    62,    62,    62,    62,    63,    63,    64,
      64,    65,    65,    66,    67,    67,    68,    68,    69,    70,
      71,    72,    72,    73,    74,    74,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    78,    79,
      80,    80,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     1,     2,     4,     4,     1,
       1,     3,     1,     1,     3,     3,     3,     1,     5,     5,
       5,     5,     5,     5,     3,     2,     5,     5,     5,     5,
       5,     5,     3,     4,     4,     1,     1,     3,     1,     2,
       0,     2,     0,     2,     4,     3,     3,     3,     1,     6,
       4,     3,     6,     5,     3,    10,     8,     1,     1,     2,
       0,     2,     0,     2,     2,     0,     2,     0,     2,     5,
       1,     5,     7,     2,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     0,     3,     2,
       3,     5,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0
=======
      32,     3,     3,    28,    88,    89,    37,    87,    68,    22,
      22,    94,    39,     9,     7,    22,     9,    42,     4,    39,
      22,    22,    87,     7,    26,    26,     9,     5,     6,     4,
      26,     4,     7,    26,     7,    37,    37,    34,     4,    14,
      24,     7,    39,    26,    27,    58,    58,   107,   108,   109,
     110,    58,    38,    39,   119,     0,    58,    58,    24,   119,
      39,   144,   145,    38,    39,    38,    39,    99,   100,     8,
     101,    96,    38,    39,     4,    11,     4,     7,    14,   163,
     160,   161,    12,    22,    23,   150,   111,   152,   153,   154,
     155,   156,   157,     4,    14,     4,     7,     8,     7,   101,
     101,    14,     9,    12,   136,     7,    27,    11,    38,    39,
      38,    39,    33,    14,    21,    12,    39,    14,    11,    26,
      27,     9,    35,    36,    37,    39,     9,    38,    39,    38,
      39,    28,    14,    30,    31,    32,    33,     7,    26,    36,
      39,     9,    39,    26,    27,     9,    28,    14,    30,    31,
      32,    33,     8,    21,    36,    14,    14,    39,    26,    14,
      12,     8,    26,    21,    13,    38,    22,    23,    10,    27,
      15,    16,    17,    18,    19,    20,     3,     4,     5,     6,
      10,     8,     3,     4,     5,     6,    21,    21,    10,    12,
      10,    29,    11,    25,     8,    12,    14,    13,    11,     8,
       8,     8,    14,    87,   120,    41,    12,    22,    12,    87,
       3,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    35,    36,    37,    43,    44,    64,    66,    67,
      70,    79,    80,    39,    39,    49,    50,    60,    62,    63,
      39,     0,    11,    14,    78,    44,     7,     9,    21,    26,
      27,    21,    27,     9,    26,    14,    14,    11,    12,    14,
      28,    30,    31,    32,    33,    39,    48,    49,    60,    61,
      64,    69,    71,    72,    73,    74,    75,    76,    77,    39,
      49,    62,    65,    68,     4,    38,    39,    45,     7,    39,
      45,    48,    49,    50,    51,    52,    59,    39,    34,    39,
      46,    11,    46,    39,    45,    39,    65,     7,    58,    58,
      14,    59,    14,    14,     7,    14,    21,    12,    69,    27,
      27,    13,     8,    38,    10,    10,    52,     3,     4,     5,
       6,    21,    12,    47,    59,    21,    10,    10,    12,     7,
      24,    51,    53,    54,    55,    56,    57,    78,    78,    14,
       8,    47,    59,    46,    46,    65,    25,     8,    52,    52,
      52,    52,    59,    12,    13,    11,    51,    53,    55,    56,
       7,    57,    15,    16,    17,    18,    19,    20,     8,     8,
      22,    23,     8,    29,     8,    14,    46,    47,    12,    47,
       8,     8,    51,    51,    51,    51,    51,    51,    55,    55,
      78,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    48,    49,    49,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    52,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    58,    58,    58,    59,    60,    60,
      60,    61,    62,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    69,    69,    70,    71,    71,    72,    73,    74,    74,
      75,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    79,    80,    80,    80,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     1,     1,     1,
       3,     4,     3,     4,     4,     4,     4,     3,     3,     1,
       1,     3,     1,     1,     1,     3,     3,     3,     3,     1,
       2,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     1,     1,
       1,     4,     3,     3,     1,     1,     5,     3,     7,     5,
       6,     4,     3,     3,     1,     3,     5,     5,     7,     1,
       0,     2,     1,     2,     5,     3,     3,     2,     3,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     2,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
>>>>>>> 24f-assignment4

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
<<<<<<< HEAD
=======
#define YYNOMEM         goto yyexhaustedlab
>>>>>>> 24f-assignment4


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

<<<<<<< HEAD
/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256

=======
/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF
>>>>>>> 24f-assignment4


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

<<<<<<< HEAD
/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
=======



# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
>>>>>>> 24f-assignment4
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
<<<<<<< HEAD
                  Type, Value); \
=======
                  Kind, Value); \
>>>>>>> 24f-assignment4
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
<<<<<<< HEAD
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
=======
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
>>>>>>> 24f-assignment4
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
<<<<<<< HEAD
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
=======
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
>>>>>>> 24f-assignment4
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
<<<<<<< HEAD
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
=======
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
>>>>>>> 24f-assignment4
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
<<<<<<< HEAD
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
=======
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
>>>>>>> 24f-assignment4
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
<<<<<<< HEAD
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
=======
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
>>>>>>> 24f-assignment4
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


<<<<<<< HEAD
#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */
=======



>>>>>>> 24f-assignment4

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
<<<<<<< HEAD
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
=======
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
>>>>>>> 24f-assignment4
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


<<<<<<< HEAD


/* The lookahead symbol.  */
=======
/* Lookahead token kind.  */
>>>>>>> 24f-assignment4
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


<<<<<<< HEAD
=======


>>>>>>> 24f-assignment4
/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
<<<<<<< HEAD
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
=======
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
>>>>>>> 24f-assignment4
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

<<<<<<< HEAD
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif
=======

>>>>>>> 24f-assignment4

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

<<<<<<< HEAD
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
=======
  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

>>>>>>> 24f-assignment4
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
<<<<<<< HEAD

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
=======
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
>>>>>>> 24f-assignment4
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
<<<<<<< HEAD
        goto yyexhaustedlab;
=======
        YYNOMEM;
>>>>>>> 24f-assignment4
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
<<<<<<< HEAD
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
=======
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
>>>>>>> 24f-assignment4
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

<<<<<<< HEAD
=======

>>>>>>> 24f-assignment4
  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

<<<<<<< HEAD
  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
=======
  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
>>>>>>> 24f-assignment4
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
<<<<<<< HEAD
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
=======
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
>>>>>>> 24f-assignment4
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
<<<<<<< HEAD
  case 2:
#line 148 "parser.yacc"
=======
  case 2: /* Program: ProgramElementList  */
#line 144 "parser.yacc"
>>>>>>> 24f-assignment4
{  
  root = A_Program((yyvsp[0].programElementList));
  (yyval.program) = A_Program((yyvsp[0].programElementList));
}
<<<<<<< HEAD
#line 1581 "y.tab.cpp"
    break;

  case 3:
#line 155 "parser.yacc"
{
  (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement), (yyvsp[0].programElementList));
}
#line 1589 "y.tab.cpp"
    break;

  case 4:
#line 159 "parser.yacc"
{
  (yyval.programElementList) = nullptr;
}
#line 1597 "y.tab.cpp"
    break;

  case 5:
#line 165 "parser.yacc"
{
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1605 "y.tab.cpp"
    break;

  case 6:
#line 169 "parser.yacc"
{
  (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
}
#line 1613 "y.tab.cpp"
    break;

  case 7:
#line 173 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
}
#line 1621 "y.tab.cpp"
    break;

  case 8:
#line 177 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
}
#line 1629 "y.tab.cpp"
    break;

  case 9:
#line 181 "parser.yacc"
{
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos));
}
#line 1637 "y.tab.cpp"
    break;

  case 10:
#line 187 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_add, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1645 "y.tab.cpp"
    break;

  case 11:
#line 191 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_sub, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1653 "y.tab.cpp"
    break;

  case 12:
#line 195 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_mul, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1661 "y.tab.cpp"
    break;

  case 13:
#line 199 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_div, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1669 "y.tab.cpp"
    break;

  case 14:
#line 203 "parser.yacc"
{
  (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
}
#line 1677 "y.tab.cpp"
    break;

  case 15:
#line 209 "parser.yacc"
{
  (yyval.tokenNum) = A_TokenNum((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 1685 "y.tab.cpp"
    break;

  case 16:
#line 213 "parser.yacc"
{
  (yyval.tokenNum) = A_TokenNum((yyvsp[-1].pos), -(yyvsp[0].tokenNum)->num);
}
#line 1693 "y.tab.cpp"
    break;

  case 17:
#line 219 "parser.yacc"
{
  (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id));
}
#line 1701 "y.tab.cpp"
    break;

  case 18:
#line 223 "parser.yacc"
{
  (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num));
}
#line 1709 "y.tab.cpp"
    break;

  case 19:
#line 229 "parser.yacc"
{
  (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 1717 "y.tab.cpp"
    break;

  case 20:
#line 233 "parser.yacc"
{
  (yyval.exprUnit) = A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1725 "y.tab.cpp"
    break;

  case 21:
#line 237 "parser.yacc"
{
  (yyval.exprUnit) = A_ArithExprUnit((yyvsp[-2].pos), (yyvsp[-1].arithExpr));
}
#line 1733 "y.tab.cpp"
    break;

  case 22:
#line 241 "parser.yacc"
{
  (yyval.exprUnit) = A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
}
#line 1741 "y.tab.cpp"
    break;

  case 23:
#line 245 "parser.yacc"
{
  (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1749 "y.tab.cpp"
    break;

  case 24:
#line 249 "parser.yacc"
{
  (yyval.exprUnit) = A_MemberExprUnit((yyvsp[-2].leftVal)->pos, A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id));
}
#line 1757 "y.tab.cpp"
    break;

  case 25:
#line 255 "parser.yacc"
{
  (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[-2].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_and, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr)));
}
#line 1765 "y.tab.cpp"
    break;

  case 26:
#line 259 "parser.yacc"
{
  (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[-2].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_or, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr)));
}
#line 1773 "y.tab.cpp"
    break;

  case 27:
#line 263 "parser.yacc"
{
  (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
}
#line 1781 "y.tab.cpp"
    break;

  case 28:
#line 269 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_lt, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1789 "y.tab.cpp"
    break;

  case 29:
#line 273 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_le, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1797 "y.tab.cpp"
    break;

  case 30:
#line 277 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_gt, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1805 "y.tab.cpp"
    break;

  case 31:
#line 281 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_ge, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1813 "y.tab.cpp"
    break;

  case 32:
#line 285 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_eq, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1821 "y.tab.cpp"
    break;

  case 33:
#line 289 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_ne, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1829 "y.tab.cpp"
    break;

  case 34:
#line 293 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
}
#line 1837 "y.tab.cpp"
    break;

  case 35:
#line 297 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[-1].pos), A_BoolUOpExpr((yyvsp[-1].pos), A_not, (yyvsp[0].boolUnit)));
}
#line 1845 "y.tab.cpp"
    break;

  case 36:
#line 303 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_lt, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1853 "y.tab.cpp"
    break;

  case 37:
#line 307 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_le, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1861 "y.tab.cpp"
    break;

  case 38:
#line 311 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_gt, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1869 "y.tab.cpp"
    break;

  case 39:
#line 315 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_ge, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1877 "y.tab.cpp"
    break;

  case 40:
#line 319 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_eq, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1885 "y.tab.cpp"
    break;

  case 41:
#line 323 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-3].exprUnit)->pos, A_ComExpr((yyvsp[-3].exprUnit)->pos, A_ne, (yyvsp[-3].exprUnit), (yyvsp[-1].exprUnit)));
}
#line 1893 "y.tab.cpp"
    break;

  case 42:
#line 327 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
}
#line 1901 "y.tab.cpp"
    break;

  case 43:
#line 331 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[-2].pos), A_BoolUOpExpr((yyvsp[-2].pos), A_not, (yyvsp[-1].boolUnit)));
}
#line 1909 "y.tab.cpp"
    break;

  case 44:
#line 337 "parser.yacc"
{
  (yyval.assignStmt) = A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
}
#line 1917 "y.tab.cpp"
    break;

  case 45:
#line 343 "parser.yacc"
{
  (yyval.leftVal) = A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1925 "y.tab.cpp"
    break;

  case 46:
#line 347 "parser.yacc"
{
  (yyval.leftVal) = A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1933 "y.tab.cpp"
    break;

  case 47:
#line 351 "parser.yacc"
{
  (yyval.leftVal) = A_MemberExprLVal((yyvsp[-2].leftVal)->pos, A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id));
}
#line 1941 "y.tab.cpp"
    break;

  case 48:
#line 357 "parser.yacc"
{
  (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
}
#line 1949 "y.tab.cpp"
    break;

  case 49:
#line 363 "parser.yacc"
{
  (yyval.rightValList) = A_RightValList((yyvsp[-1].rightVal), (yyvsp[0].rightValList));
}
#line 1957 "y.tab.cpp"
    break;

  case 50:
#line 367 "parser.yacc"
{
  (yyval.rightValList) = nullptr;
}
#line 1965 "y.tab.cpp"
    break;

  case 51:
#line 372 "parser.yacc"
{
  (yyval.rightValList) = A_RightValList((yyvsp[-1].rightVal), (yyvsp[0].rightValList));
}
#line 1973 "y.tab.cpp"
    break;

  case 52:
#line 376 "parser.yacc"
{
  (yyval.rightValList) = nullptr;
}
#line 1981 "y.tab.cpp"
    break;

  case 53:
#line 381 "parser.yacc"
{
  (yyval.rightVal) = (yyvsp[0].rightVal);
}
#line 1989 "y.tab.cpp"
    break;

  case 54:
#line 387 "parser.yacc"
{
  (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].rightValList));
}
#line 1997 "y.tab.cpp"
    break;

  case 55:
#line 393 "parser.yacc"
{
  (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-2].pos), (yyvsp[-1].varDecl));
}
#line 2005 "y.tab.cpp"
    break;

  case 56:
#line 397 "parser.yacc"
{
  (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-2].pos), (yyvsp[-1].varDef));
}
#line 2013 "y.tab.cpp"
    break;

  case 57:
#line 403 "parser.yacc"
{
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[-2].tokenId)->pos, A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type)));
}
#line 2021 "y.tab.cpp"
    break;

  case 58:
#line 407 "parser.yacc"
{
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[0].tokenId)->pos, A_VarDeclScalar((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id, nullptr));
}
#line 2029 "y.tab.cpp"
    break;

  case 59:
#line 411 "parser.yacc"
{
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[-5].tokenId)->pos, A_VarDeclArray((yyvsp[-5].tokenId)->pos, (yyvsp[-5].tokenId)->id, (yyvsp[-3].tokenNum)->num, (yyvsp[0].type)));
}
#line 2037 "y.tab.cpp"
    break;

  case 60:
#line 415 "parser.yacc"
{
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[-3].tokenId)->pos, A_VarDeclArray((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].tokenNum)->num, nullptr));
}
#line 2045 "y.tab.cpp"
    break;

  case 61:
#line 421 "parser.yacc"
{
  (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[-2].tokenId)->pos, A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type)));
}
#line 2053 "y.tab.cpp"
    break;

  case 62:
#line 425 "parser.yacc"
{
  (yyval.varDecl) = A_VarDecl_Array((yyvsp[-5].tokenId)->pos, A_VarDeclArray((yyvsp[-5].tokenId)->pos, (yyvsp[-5].tokenId)->id, (yyvsp[-3].tokenNum)->num, (yyvsp[0].type)));
}
#line 2061 "y.tab.cpp"
    break;

  case 63:
#line 431 "parser.yacc"
{
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[-4].tokenId)->pos, A_VarDefScalar((yyvsp[-4].tokenId)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal)));
}
#line 2069 "y.tab.cpp"
    break;

  case 64:
#line 435 "parser.yacc"
{
  (yyval.varDef) = A_VarDef_Scalar((yyvsp[-2].tokenId)->pos, A_VarDefScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, nullptr, (yyvsp[0].rightVal)));
}
#line 2077 "y.tab.cpp"
    break;

  case 65:
#line 439 "parser.yacc"
{
  (yyval.varDef) = A_VarDef_Array((yyvsp[-9].tokenId)->pos, A_VarDefArray((yyvsp[-9].tokenId)->pos, (yyvsp[-9].tokenId)->id, (yyvsp[-7].tokenNum)->num, (yyvsp[-4].type), (yyvsp[-1].rightValList)));
}
#line 2085 "y.tab.cpp"
    break;

  case 66:
#line 443 "parser.yacc"
{
  (yyval.varDef) = A_VarDef_Array((yyvsp[-7].tokenId)->pos, A_VarDefArray((yyvsp[-7].tokenId)->pos, (yyvsp[-7].tokenId)->id, (yyvsp[-5].tokenNum)->num, nullptr, (yyvsp[-1].rightValList)));
}
#line 2093 "y.tab.cpp"
    break;

  case 67:
#line 449 "parser.yacc"
{
  (yyval.type) = A_NativeType((yyvsp[0].pos), A_intTypeKind);
}
#line 2101 "y.tab.cpp"
    break;

  case 68:
#line 453 "parser.yacc"
{
  (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 2109 "y.tab.cpp"
    break;

  case 69:
#line 459 "parser.yacc"
{
  (yyval.varDeclList) = A_VarDeclList((yyvsp[-1].varDecl), (yyvsp[0].varDeclList));
}
#line 2117 "y.tab.cpp"
    break;

  case 70:
#line 463 "parser.yacc"
{
  (yyval.varDeclList) = nullptr;
}
#line 2125 "y.tab.cpp"
    break;

  case 71:
#line 468 "parser.yacc"
{
  (yyval.varDeclList) = A_VarDeclList((yyvsp[-1].varDecl), (yyvsp[0].varDeclList));
}
#line 2133 "y.tab.cpp"
    break;

  case 72:
#line 472 "parser.yacc"
{
  (yyval.varDeclList) = nullptr;
}
#line 2141 "y.tab.cpp"
    break;

  case 73:
#line 477 "parser.yacc"
{
  (yyval.varDecl) = (yyvsp[0].varDecl);
}
#line 2149 "y.tab.cpp"
    break;

  case 74:
#line 483 "parser.yacc"
{
  (yyval.varDeclList) = A_VarDeclList((yyvsp[-1].varDecl), (yyvsp[0].varDeclList));
}
#line 2157 "y.tab.cpp"
    break;

  case 75:
#line 487 "parser.yacc"
{
  (yyval.varDeclList) = nullptr;
}
#line 2165 "y.tab.cpp"
    break;

  case 76:
#line 492 "parser.yacc"
{
  (yyval.varDeclList) = A_VarDeclList((yyvsp[-1].varDecl), (yyvsp[0].varDeclList));
}
#line 2173 "y.tab.cpp"
    break;

  case 77:
#line 496 "parser.yacc"
{
  (yyval.varDeclList) = nullptr;
}
#line 2181 "y.tab.cpp"
    break;

  case 78:
#line 501 "parser.yacc"
{
  (yyval.varDecl) = (yyvsp[0].varDecl);
}
#line 2189 "y.tab.cpp"
    break;

  case 79:
#line 507 "parser.yacc"
{
  (yyval.structDef) = A_StructDef((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
}
#line 2197 "y.tab.cpp"
    break;

  case 80:
#line 513 "parser.yacc"
{
  (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
}
#line 2205 "y.tab.cpp"
    break;

  case 81:
#line 519 "parser.yacc"
{
  (yyval.fnDecl) = A_FnDecl((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), nullptr);
}
#line 2213 "y.tab.cpp"
    break;

  case 82:
#line 523 "parser.yacc"
{
  (yyval.fnDecl) = A_FnDecl((yyvsp[-6].pos), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
}
#line 2221 "y.tab.cpp"
    break;

  case 83:
#line 529 "parser.yacc"
{
  (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
}
#line 2229 "y.tab.cpp"
    break;

  case 84:
#line 535 "parser.yacc"
{
  (yyval.returnStmt) = A_ReturnStmt((yyvsp[-2].pos), (yyvsp[-1].rightVal));
}
#line 2237 "y.tab.cpp"
    break;

  case 85:
#line 539 "parser.yacc"
{
  (yyval.returnStmt) = A_ReturnStmt((yyvsp[-1].pos), nullptr);
}
#line 2245 "y.tab.cpp"
    break;

  case 86:
#line 545 "parser.yacc"
{
  (yyval.fnDef) = A_FnDef((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl), (yyvsp[0].codeBlockStmtList));
}
#line 2253 "y.tab.cpp"
    break;

  case 87:
#line 551 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 2261 "y.tab.cpp"
    break;

  case 88:
#line 555 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[0].assignStmt)->pos, (yyvsp[0].assignStmt));
}
#line 2269 "y.tab.cpp"
    break;

  case 89:
#line 559 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[0].callStmt)->pos, (yyvsp[0].callStmt));
}
#line 2277 "y.tab.cpp"
    break;

  case 90:
#line 563 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[0].ifStmt)->pos, (yyvsp[0].ifStmt));
}
#line 2285 "y.tab.cpp"
    break;

  case 91:
#line 567 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[0].whileStmt)->pos, (yyvsp[0].whileStmt));
}
#line 2293 "y.tab.cpp"
    break;

  case 92:
#line 571 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[0].returnStmt)->pos, (yyvsp[0].returnStmt));
}
#line 2301 "y.tab.cpp"
    break;

  case 93:
#line 575 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[-1].pos));
}
#line 2309 "y.tab.cpp"
    break;

  case 94:
#line 579 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[-1].pos));
}
#line 2317 "y.tab.cpp"
    break;

  case 95:
#line 583 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[0].pos));
}
#line 2325 "y.tab.cpp"
    break;

  case 96:
#line 589 "parser.yacc"
{
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
}
#line 2333 "y.tab.cpp"
    break;

  case 97:
#line 593 "parser.yacc"
{
  (yyval.codeBlockStmtList) = nullptr;
}
#line 2341 "y.tab.cpp"
    break;

  case 98:
#line 599 "parser.yacc"
{
  (yyval.codeBlockStmtList) = (yyvsp[-1].codeBlockStmtList);
}
#line 2349 "y.tab.cpp"
    break;

  case 99:
#line 605 "parser.yacc"
{
  (yyval.callStmt) = A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
}
#line 2357 "y.tab.cpp"
    break;

  case 100:
#line 611 "parser.yacc"
{
  (yyval.ifStmt) = A_IfStmt((yyvsp[-2].pos), (yyvsp[-1].boolUnit), (yyvsp[0].codeBlockStmtList), nullptr);
}
#line 2365 "y.tab.cpp"
    break;

  case 101:
#line 615 "parser.yacc"
{
  (yyval.ifStmt) = A_IfStmt((yyvsp[-4].pos), (yyvsp[-3].boolUnit), (yyvsp[-2].codeBlockStmtList), (yyvsp[0].codeBlockStmtList));
}
#line 2373 "y.tab.cpp"
    break;

  case 102:
#line 621 "parser.yacc"
{
  (yyval.whileStmt) = A_WhileStmt((yyvsp[-2].pos), (yyvsp[-1].boolUnit), (yyvsp[0].codeBlockStmtList));
}
#line 2381 "y.tab.cpp"
    break;


#line 2385 "y.tab.cpp"
=======
#line 1286 "y.tab.cpp"
    break;

  case 3: /* ProgramElementList: ProgramElement ProgramElementList  */
#line 151 "parser.yacc"
{
  (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement), (yyvsp[0].programElementList));
}
#line 1294 "y.tab.cpp"
    break;

  case 4: /* ProgramElementList: %empty  */
#line 155 "parser.yacc"
{
  (yyval.programElementList) = nullptr;
}
#line 1302 "y.tab.cpp"
    break;

  case 5: /* NUM: UNUM  */
#line 161 "parser.yacc"
{
    (yyval.tokenNum)=A_TokenNum((yyvsp[0].tokenNum)->pos,(yyvsp[0].tokenNum)->num);
}
#line 1310 "y.tab.cpp"
    break;

  case 6: /* NUM: SUB UNUM  */
#line 165 "parser.yacc"
{
    (yyval.tokenNum)=A_TokenNum((yyvsp[-1].pos),-(yyvsp[0].tokenNum)->num);
}
#line 1318 "y.tab.cpp"
    break;

  case 7: /* Type: INT  */
#line 172 "parser.yacc"
{
    (yyval.type) = A_NativeType((yyvsp[0].pos), A_intTypeKind);
}
#line 1326 "y.tab.cpp"
    break;

  case 8: /* Type: ID  */
#line 176 "parser.yacc"
{
    (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1334 "y.tab.cpp"
    break;

  case 9: /* RightValList: RightVal  */
#line 182 "parser.yacc"
{
    (yyval.rightValList) = A_RightValList((yyvsp[0].rightVal), nullptr);
}
#line 1342 "y.tab.cpp"
    break;

  case 10: /* RightValList: RightVal COMMA RightValList  */
#line 186 "parser.yacc"
{
    (yyval.rightValList) = A_RightValList((yyvsp[-2].rightVal), (yyvsp[0].rightValList));
}
#line 1350 "y.tab.cpp"
    break;

  case 11: /* FnCall: ID LP RightValList RP  */
#line 192 "parser.yacc"
{
    (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].rightValList));
}
#line 1358 "y.tab.cpp"
    break;

  case 12: /* FnCall: ID LP RP  */
#line 196 "parser.yacc"
{
    (yyval.fnCall) = A_FnCall((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, nullptr);
}
#line 1366 "y.tab.cpp"
    break;

  case 13: /* ArrayExpr: ID LSB NUM RSB  */
#line 202 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].tokenId)->pos, A_IdExprLVal((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id), A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num));
}
#line 1374 "y.tab.cpp"
    break;

  case 14: /* ArrayExpr: ID LSB ID RSB  */
#line 206 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].tokenId)->pos, A_IdExprLVal((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id), A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id));
}
#line 1382 "y.tab.cpp"
    break;

  case 15: /* ArrayExpr: LeftVal LSB NUM RSB  */
#line 210 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num));
}
#line 1390 "y.tab.cpp"
    break;

  case 16: /* ArrayExpr: LeftVal LSB ID RSB  */
#line 214 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id));
}
#line 1398 "y.tab.cpp"
    break;

  case 17: /* MemberExpr: ID DOT ID  */
#line 220 "parser.yacc"
{
    (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].tokenId)->pos, A_IdExprLVal((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id), (yyvsp[0].tokenId)->id);
}
#line 1406 "y.tab.cpp"
    break;

  case 18: /* MemberExpr: LeftVal DOT ID  */
#line 224 "parser.yacc"
{
    (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id);
}
#line 1414 "y.tab.cpp"
    break;

  case 19: /* ExprUnit: NUM  */
#line 231 "parser.yacc"
{
    (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 1422 "y.tab.cpp"
    break;

  case 20: /* ExprUnit: ID  */
#line 235 "parser.yacc"
{
    (yyval.exprUnit) = A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1430 "y.tab.cpp"
    break;

  case 21: /* ExprUnit: LP ArithExpr RP  */
#line 239 "parser.yacc"
{
    (yyval.exprUnit) = A_ArithExprUnit((yyvsp[-1].arithExpr)->pos, (yyvsp[-1].arithExpr));
}
#line 1438 "y.tab.cpp"
    break;

  case 22: /* ExprUnit: FnCall  */
#line 244 "parser.yacc"
{
    (yyval.exprUnit) = A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
}
#line 1446 "y.tab.cpp"
    break;

  case 23: /* ExprUnit: ArrayExpr  */
#line 248 "parser.yacc"
{
    (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1454 "y.tab.cpp"
    break;

  case 24: /* ExprUnit: MemberExpr  */
#line 252 "parser.yacc"
{
    (yyval.exprUnit) = A_MemberExprUnit((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1462 "y.tab.cpp"
    break;

  case 25: /* ArithExpr: ArithExpr ADD ArithExpr  */
#line 259 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_add, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1470 "y.tab.cpp"
    break;

  case 26: /* ArithExpr: ArithExpr SUB ArithExpr  */
#line 263 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_sub, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1478 "y.tab.cpp"
    break;

  case 27: /* ArithExpr: ArithExpr MUL ArithExpr  */
#line 267 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_mul, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1486 "y.tab.cpp"
    break;

  case 28: /* ArithExpr: ArithExpr DIV ArithExpr  */
#line 271 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_div, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1494 "y.tab.cpp"
    break;

  case 29: /* ArithExpr: ExprUnit  */
#line 275 "parser.yacc"
{
    (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
}
#line 1502 "y.tab.cpp"
    break;

  case 30: /* BoolUOpExpr: NOT BoolUnit  */
#line 280 "parser.yacc"
{
  (yyval.boolUOpExpr) = A_BoolUOpExpr((yyvsp[-1].pos), A_not, (yyvsp[0].boolUnit));
}
#line 1510 "y.tab.cpp"
    break;

  case 31: /* BoolBiOpExpr: BoolExpr AND BoolExpr  */
#line 286 "parser.yacc"
{
    (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_and, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
}
#line 1518 "y.tab.cpp"
    break;

  case 32: /* BoolBiOpExpr: BoolExpr OR BoolExpr  */
#line 290 "parser.yacc"
{
    (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_or, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
}
#line 1526 "y.tab.cpp"
    break;

  case 33: /* BoolExpr: BoolBiOpExpr  */
#line 296 "parser.yacc"
{
    (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[0].boolBiOpExpr)->pos, (yyvsp[0].boolBiOpExpr));
}
#line 1534 "y.tab.cpp"
    break;

  case 34: /* BoolExpr: BoolUnit  */
#line 300 "parser.yacc"
{
    (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
}
#line 1542 "y.tab.cpp"
    break;

  case 35: /* ComExpr: ExprUnit LT ExprUnit  */
#line 307 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_lt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1550 "y.tab.cpp"
    break;

  case 36: /* ComExpr: ExprUnit LE ExprUnit  */
#line 311 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_le, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1558 "y.tab.cpp"
    break;

  case 37: /* ComExpr: ExprUnit GT ExprUnit  */
#line 315 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_gt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1566 "y.tab.cpp"
    break;

  case 38: /* ComExpr: ExprUnit GE ExprUnit  */
#line 319 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ge, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1574 "y.tab.cpp"
    break;

  case 39: /* ComExpr: ExprUnit EQ ExprUnit  */
#line 323 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_eq, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1582 "y.tab.cpp"
    break;

  case 40: /* ComExpr: ExprUnit NE ExprUnit  */
#line 327 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ne, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1590 "y.tab.cpp"
    break;

  case 41: /* BoolUnit: LP ComExpr RP  */
#line 333 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-2].pos), (yyvsp[-1].comExpr));
}
#line 1598 "y.tab.cpp"
    break;

  case 42: /* BoolUnit: LP BoolExpr RP  */
#line 337 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
}
#line 1606 "y.tab.cpp"
    break;

  case 43: /* BoolUnit: BoolUOpExpr  */
#line 341 "parser.yacc"
{
    (yyval.boolUnit)=A_BoolUOpExprUnit((yyvsp[0].boolUOpExpr)->pos, (yyvsp[0].boolUOpExpr));
}
#line 1614 "y.tab.cpp"
    break;

  case 44: /* BoolUnit_: LP ComExpr RP  */
#line 347 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-2].pos), (yyvsp[-1].comExpr));
}
#line 1622 "y.tab.cpp"
    break;

  case 45: /* BoolUnit_: LP BoolExpr RP  */
#line 351 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
}
#line 1630 "y.tab.cpp"
    break;

  case 46: /* BoolUnit_: LP BoolUOpExpr RP  */
#line 355 "parser.yacc"
{
    (yyval.boolUnit)=A_BoolUOpExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolUOpExpr));
}
#line 1638 "y.tab.cpp"
    break;

  case 47: /* RightVal: ArithExpr  */
#line 362 "parser.yacc"
{
    (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
}
#line 1646 "y.tab.cpp"
    break;

  case 48: /* LeftVal: ID  */
#line 368 "parser.yacc"
{
    (yyval.leftVal) = A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1654 "y.tab.cpp"
    break;

  case 49: /* LeftVal: ArrayExpr  */
#line 372 "parser.yacc"
{
    (yyval.leftVal) = A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1662 "y.tab.cpp"
    break;

  case 50: /* LeftVal: MemberExpr  */
#line 376 "parser.yacc"
{
    (yyval.leftVal) = A_MemberExprLVal((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1670 "y.tab.cpp"
    break;

  case 51: /* AssignStmt: LeftVal ASSIGN RightVal SEMICOLON  */
#line 382 "parser.yacc"
{
    (yyval.assignStmt) = A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
}
#line 1678 "y.tab.cpp"
    break;

  case 52: /* VarDecl: ID COLON Type  */
#line 388 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[-2].tokenId)->pos, A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type)));
}
#line 1686 "y.tab.cpp"
    break;

  case 53: /* VarDecl: ArrayExpr COLON Type  */
#line 392 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Array((yyvsp[-2].arrayExpr)->pos, A_VarDeclArray((yyvsp[-2].arrayExpr)->pos, (yyvsp[-2].arrayExpr)->arr->u.id, (yyvsp[-2].arrayExpr)->idx->u.num, (yyvsp[0].type)));
}
#line 1694 "y.tab.cpp"
    break;

  case 54: /* VarDecl: ArrayExpr  */
#line 396 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Array((yyvsp[0].arrayExpr)->pos, A_VarDeclArray((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr)->arr->u.id, (yyvsp[0].arrayExpr)->idx->u.num, nullptr));
}
#line 1702 "y.tab.cpp"
    break;

  case 55: /* VarDecl: ID  */
#line 400 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[0].tokenId)->pos, A_VarDeclScalar((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id, nullptr));
}
#line 1710 "y.tab.cpp"
    break;

  case 56: /* VarDef: ID COLON Type ASSIGN RightVal  */
#line 406 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Scalar((yyvsp[-4].tokenId)->pos, A_VarDefScalar((yyvsp[-4].tokenId)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal)));
}
#line 1718 "y.tab.cpp"
    break;

  case 57: /* VarDef: ID ASSIGN RightVal  */
#line 410 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Scalar((yyvsp[-2].tokenId)->pos, A_VarDefScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, nullptr, (yyvsp[0].rightVal)));
}
#line 1726 "y.tab.cpp"
    break;

  case 58: /* VarDef: ArrayExpr COLON Type ASSIGN LB RightValList RB  */
#line 414 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-6].arrayExpr)->pos, A_VarDefArray((yyvsp[-6].arrayExpr)->pos, (yyvsp[-6].arrayExpr)->arr->u.id, (yyvsp[-6].arrayExpr)->idx->u.num, (yyvsp[-4].type), (yyvsp[-1].rightValList)));
}
#line 1734 "y.tab.cpp"
    break;

  case 59: /* VarDef: ArrayExpr ASSIGN LB RightValList RB  */
#line 418 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-4].arrayExpr)->pos, A_VarDefArray((yyvsp[-4].arrayExpr)->pos, (yyvsp[-4].arrayExpr)->arr->u.id, (yyvsp[-4].arrayExpr)->idx->u.num, nullptr, (yyvsp[-1].rightValList)));
}
#line 1742 "y.tab.cpp"
    break;

  case 60: /* VarDef: ArrayExpr COLON Type ASSIGN LB RB  */
#line 422 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-5].arrayExpr)->pos, A_VarDefArray((yyvsp[-5].arrayExpr)->pos, (yyvsp[-5].arrayExpr)->arr->u.id, (yyvsp[-5].arrayExpr)->idx->u.num, (yyvsp[-3].type), nullptr));
}
#line 1750 "y.tab.cpp"
    break;

  case 61: /* VarDef: ArrayExpr ASSIGN LB RB  */
#line 426 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-3].arrayExpr)->pos, A_VarDefArray((yyvsp[-3].arrayExpr)->pos, (yyvsp[-3].arrayExpr)->arr->u.id, (yyvsp[-3].arrayExpr)->idx->u.num, nullptr, nullptr));
}
#line 1758 "y.tab.cpp"
    break;

  case 62: /* VarDeclStmt: LET VarDecl SEMICOLON  */
#line 433 "parser.yacc"
{
    (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-2].pos), (yyvsp[-1].varDecl));
}
#line 1766 "y.tab.cpp"
    break;

  case 63: /* VarDeclStmt: LET VarDef SEMICOLON  */
#line 437 "parser.yacc"
{
    (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-2].pos), (yyvsp[-1].varDef));
}
#line 1774 "y.tab.cpp"
    break;

  case 64: /* VarDeclList: VarDecl  */
#line 443 "parser.yacc"
{
    (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl), nullptr);
}
#line 1782 "y.tab.cpp"
    break;

  case 65: /* VarDeclList: VarDecl COMMA VarDeclList  */
#line 447 "parser.yacc"
{
    (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList));
}
#line 1790 "y.tab.cpp"
    break;

  case 66: /* StructDef: STRUCT ID LB VarDeclList RB  */
#line 453 "parser.yacc"
{
    (yyval.structDef) = A_StructDef((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
}
#line 1798 "y.tab.cpp"
    break;

  case 67: /* FnDecl: FN ID LP ParamDecl RP  */
#line 459 "parser.yacc"
{
    (yyval.fnDecl) = A_FnDecl((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), nullptr);
}
#line 1806 "y.tab.cpp"
    break;

  case 68: /* FnDecl: FN ID LP ParamDecl RP ARROW Type  */
#line 463 "parser.yacc"
{
    (yyval.fnDecl) = A_FnDecl((yyvsp[-6].pos), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
}
#line 1814 "y.tab.cpp"
    break;

  case 69: /* ParamDecl: VarDeclList  */
#line 470 "parser.yacc"
{
    (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
}
#line 1822 "y.tab.cpp"
    break;

  case 70: /* ParamDecl: %empty  */
#line 474 "parser.yacc"
{
    (yyval.paramDecl) = A_ParamDecl(nullptr);
}
#line 1830 "y.tab.cpp"
    break;

  case 71: /* CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList  */
#line 480 "parser.yacc"
{
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
}
#line 1838 "y.tab.cpp"
    break;

  case 72: /* CodeBlockStmtList: CodeBlockStmt  */
#line 484 "parser.yacc"
{
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[0].codeBlockStmt), nullptr);
}
#line 1846 "y.tab.cpp"
    break;

  case 73: /* FnDef: FnDecl CodeBlock  */
#line 490 "parser.yacc"
{
    (yyval.fnDef) = A_FnDef((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl), (yyvsp[0].codeBlockStmtList));
}
#line 1854 "y.tab.cpp"
    break;

  case 74: /* IfStmt: IF BoolUnit_ CodeBlock ELSE CodeBlock  */
#line 496 "parser.yacc"
{
    (yyval.ifStmt) = A_IfStmt((yyvsp[-4].pos), (yyvsp[-3].boolUnit), (yyvsp[-2].codeBlockStmtList), (yyvsp[0].codeBlockStmtList));
}
#line 1862 "y.tab.cpp"
    break;

  case 75: /* IfStmt: IF BoolUnit_ CodeBlock  */
#line 500 "parser.yacc"
{
    (yyval.ifStmt) = A_IfStmt((yyvsp[-2].pos), (yyvsp[-1].boolUnit), (yyvsp[0].codeBlockStmtList), nullptr);
}
#line 1870 "y.tab.cpp"
    break;

  case 76: /* WhileStmt: WHILE BoolUnit_ CodeBlock  */
#line 506 "parser.yacc"
{
    (yyval.whileStmt) = A_WhileStmt((yyvsp[-2].pos), (yyvsp[-1].boolUnit), (yyvsp[0].codeBlockStmtList));
}
#line 1878 "y.tab.cpp"
    break;

  case 77: /* CallStmt: FnCall SEMICOLON  */
#line 512 "parser.yacc"
{
    (yyval.callStmt) = A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
}
#line 1886 "y.tab.cpp"
    break;

  case 78: /* ReturnStmt: RETURN RightVal SEMICOLON  */
#line 518 "parser.yacc"
{
    (yyval.returnStmt) = A_ReturnStmt((yyvsp[-2].pos), (yyvsp[-1].rightVal));
}
#line 1894 "y.tab.cpp"
    break;

  case 79: /* ReturnStmt: RETURN SEMICOLON  */
#line 522 "parser.yacc"
{
    (yyval.returnStmt) = A_ReturnStmt((yyvsp[-1].pos), nullptr);
}
#line 1902 "y.tab.cpp"
    break;

  case 80: /* ContinueStmt: CONTINUE SEMICOLON  */
#line 528 "parser.yacc"
{
    (yyval.pos) = (yyvsp[-1].pos);
}
#line 1910 "y.tab.cpp"
    break;

  case 81: /* BreakStmt: BREAK SEMICOLON  */
#line 534 "parser.yacc"
{
    (yyval.pos) = (yyvsp[-1].pos);
}
#line 1918 "y.tab.cpp"
    break;

  case 82: /* CodeBlockStmt: SEMICOLON  */
#line 540 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[0].pos));
}
#line 1926 "y.tab.cpp"
    break;

  case 83: /* CodeBlockStmt: VarDeclStmt  */
#line 544 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1934 "y.tab.cpp"
    break;

  case 84: /* CodeBlockStmt: AssignStmt  */
#line 548 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[0].assignStmt)->pos, (yyvsp[0].assignStmt));
}
#line 1942 "y.tab.cpp"
    break;

  case 85: /* CodeBlockStmt: CallStmt  */
#line 552 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[0].callStmt)->pos, (yyvsp[0].callStmt));
}
#line 1950 "y.tab.cpp"
    break;

  case 86: /* CodeBlockStmt: IfStmt  */
#line 556 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[0].ifStmt)->pos, (yyvsp[0].ifStmt));
}
#line 1958 "y.tab.cpp"
    break;

  case 87: /* CodeBlockStmt: WhileStmt  */
#line 560 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[0].whileStmt)->pos, (yyvsp[0].whileStmt));
}
#line 1966 "y.tab.cpp"
    break;

  case 88: /* CodeBlockStmt: ReturnStmt  */
#line 564 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[0].returnStmt)->pos, (yyvsp[0].returnStmt));
}
#line 1974 "y.tab.cpp"
    break;

  case 89: /* CodeBlockStmt: ContinueStmt  */
#line 568 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[0].pos));
}
#line 1982 "y.tab.cpp"
    break;

  case 90: /* CodeBlockStmt: BreakStmt  */
#line 572 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[0].pos));
}
#line 1990 "y.tab.cpp"
    break;

  case 91: /* CodeBlock: LB RB  */
#line 577 "parser.yacc"
                {
    (yyval.codeBlockStmtList) = nullptr;
}
#line 1998 "y.tab.cpp"
    break;

  case 92: /* CodeBlock: LB CodeBlockStmtList RB  */
#line 581 "parser.yacc"
{
    (yyval.codeBlockStmtList) = (yyvsp[-1].codeBlockStmtList);
}
#line 2006 "y.tab.cpp"
    break;

  case 93: /* FnDeclStmt: FnDecl SEMICOLON  */
#line 587 "parser.yacc"
{
    (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
}
#line 2014 "y.tab.cpp"
    break;

  case 94: /* ProgramElement: VarDeclStmt  */
#line 593 "parser.yacc"
{
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 2022 "y.tab.cpp"
    break;

  case 95: /* ProgramElement: StructDef  */
#line 597 "parser.yacc"
{
  (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
}
#line 2030 "y.tab.cpp"
    break;

  case 96: /* ProgramElement: FnDeclStmt  */
#line 601 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
}
#line 2038 "y.tab.cpp"
    break;

  case 97: /* ProgramElement: FnDef  */
#line 605 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
}
#line 2046 "y.tab.cpp"
    break;

  case 98: /* ProgramElement: SEMICOLON  */
#line 609 "parser.yacc"
{
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos));
}
#line 2054 "y.tab.cpp"
    break;


#line 2058 "y.tab.cpp"
>>>>>>> 24f-assignment4

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
<<<<<<< HEAD
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
=======
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
>>>>>>> 24f-assignment4

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
<<<<<<< HEAD
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

=======
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
>>>>>>> 24f-assignment4
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
<<<<<<< HEAD
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



=======
      yyerror (YY_("syntax error"));
    }

>>>>>>> 24f-assignment4
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
<<<<<<< HEAD
=======
  ++yynerrs;
>>>>>>> 24f-assignment4

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

<<<<<<< HEAD
=======
  /* Pop stack until we find a state that shifts the error token.  */
>>>>>>> 24f-assignment4
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
<<<<<<< HEAD
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
=======
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
>>>>>>> 24f-assignment4
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
<<<<<<< HEAD
                  yystos[yystate], yyvsp);
=======
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
>>>>>>> 24f-assignment4
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
<<<<<<< HEAD
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
=======
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);
>>>>>>> 24f-assignment4

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
<<<<<<< HEAD
  goto yyreturn;
=======
  goto yyreturnlab;
>>>>>>> 24f-assignment4


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
<<<<<<< HEAD
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
=======
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
>>>>>>> 24f-assignment4
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
<<<<<<< HEAD
                  yystos[+*yyssp], yyvsp);
=======
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
>>>>>>> 24f-assignment4
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
<<<<<<< HEAD
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 626 "parser.yacc"
=======

  return yyresult;
}

#line 617 "parser.yacc"
>>>>>>> 24f-assignment4


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

<<<<<<< HEAD
=======

>>>>>>> 24f-assignment4
