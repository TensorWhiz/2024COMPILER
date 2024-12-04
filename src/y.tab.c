/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(const char *s); 
extern int  yywrap();
}


#line 86 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    NUM = 293,                     /* NUM  */
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
#define NUM 293
#define ID 294
#define NEG 295
#define LOWER_THAN_LP 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
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
  

#line 268 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
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
  YYSYMBOL_NUM = 38,                       /* NUM  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_NEG = 40,                       /* NEG  */
  YYSYMBOL_LOWER_THAN_LP = 41,             /* LOWER_THAN_LP  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Program = 43,                   /* Program  */
  YYSYMBOL_Type = 44,                      /* Type  */
  YYSYMBOL_RightValList = 45,              /* RightValList  */
  YYSYMBOL_FnCall = 46,                    /* FnCall  */
  YYSYMBOL_ArrayExpr = 47,                 /* ArrayExpr  */
  YYSYMBOL_MemberExpr = 48,                /* MemberExpr  */
  YYSYMBOL_ExprUnit = 49,                  /* ExprUnit  */
  YYSYMBOL_ArithUExpr = 50,                /* ArithUExpr  */
  YYSYMBOL_ArithExpr = 51,                 /* ArithExpr  */
  YYSYMBOL_BoolUOpExpr = 52,               /* BoolUOpExpr  */
  YYSYMBOL_BoolBiOpExpr = 53,              /* BoolBiOpExpr  */
  YYSYMBOL_BoolExpr = 54,                  /* BoolExpr  */
  YYSYMBOL_ComExpr = 55,                   /* ComExpr  */
  YYSYMBOL_BoolUnit = 56,                  /* BoolUnit  */
  YYSYMBOL_RightVal = 57,                  /* RightVal  */
  YYSYMBOL_LeftVal = 58,                   /* LeftVal  */
  YYSYMBOL_AssignStmt = 59,                /* AssignStmt  */
  YYSYMBOL_VarDecl = 60,                   /* VarDecl  */
  YYSYMBOL_VarDef = 61,                    /* VarDef  */
  YYSYMBOL_VarDeclStmt = 62,               /* VarDeclStmt  */
  YYSYMBOL_VarDeclList = 63,               /* VarDeclList  */
  YYSYMBOL_StructDef = 64,                 /* StructDef  */
  YYSYMBOL_FnDecl = 65,                    /* FnDecl  */
  YYSYMBOL_ParamDecl = 66,                 /* ParamDecl  */
  YYSYMBOL_CodeBlockStmtList = 67,         /* CodeBlockStmtList  */
  YYSYMBOL_FnDef = 68,                     /* FnDef  */
  YYSYMBOL_IfStmt = 69,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 70,                 /* WhileStmt  */
  YYSYMBOL_CallStmt = 71,                  /* CallStmt  */
  YYSYMBOL_ReturnStmt = 72,                /* ReturnStmt  */
  YYSYMBOL_ContinueStmt = 73,              /* ContinueStmt  */
  YYSYMBOL_BreakStmt = 74,                 /* BreakStmt  */
  YYSYMBOL_CodeBlockStmt = 75,             /* CodeBlockStmt  */
  YYSYMBOL_CodeBlock = 76,                 /* CodeBlock  */
  YYSYMBOL_FnDeclStmt = 77,                /* FnDeclStmt  */
  YYSYMBOL_ProgramElement = 78,            /* ProgramElement  */
  YYSYMBOL_ProgramElementList = 79         /* ProgramElementList  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   142,   142,   149,   153,   159,   163,   169,   173,   179,
     183,   187,   191,   198,   202,   209,   213,   217,   221,   225,
     229,   233,   240,   247,   251,   255,   259,   263,   268,   274,
     278,   284,   288,   295,   299,   303,   307,   311,   315,   322,
     326,   330,   336,   340,   346,   350,   354,   360,   366,   370,
     374,   378,   384,   388,   392,   396,   400,   404,   411,   415,
     421,   425,   431,   437,   441,   448,   453,   458,   462,   468,
     474,   478,   484,   490,   496,   500,   506,   512,   518,   522,
     526,   530,   534,   538,   542,   546,   550,   556,   559,   565,
     571,   575,   579,   583,   587,   593,   598
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "SUB", "MUL",
  "DIV", "LP", "RP", "LSB", "RSB", "LB", "RB", "COMMA", "SEMICOLON", "EQ",
  "NE", "LT", "GT", "LE", "GE", "ASSIGN", "AND", "OR", "NOT", "ARROW",
  "DOT", "COLON", "IF", "ELSE", "WHILE", "RETURN", "CONTINUE", "BREAK",
  "INT", "FN", "LET", "STRUCT", "NUM", "ID", "NEG", "LOWER_THAN_LP",
  "$accept", "Program", "Type", "RightValList", "FnCall", "ArrayExpr",
  "MemberExpr", "ExprUnit", "ArithUExpr", "ArithExpr", "BoolUOpExpr",
  "BoolBiOpExpr", "BoolExpr", "ComExpr", "BoolUnit", "RightVal", "LeftVal",
  "AssignStmt", "VarDecl", "VarDef", "VarDeclStmt", "VarDeclList",
  "StructDef", "FnDecl", "ParamDecl", "CodeBlockStmtList", "FnDef",
  "IfStmt", "WhileStmt", "CallStmt", "ReturnStmt", "ContinueStmt",
  "BreakStmt", "CodeBlockStmt", "CodeBlock", "FnDeclStmt",
  "ProgramElement", "ProgramElementList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      81,   -94,    20,    50,    61,   119,   -94,   -94,   144,   -94,
     -94,    81,   -94,   121,   138,    46,   -94,    10,   143,   150,
     165,   -94,    99,   -94,   -94,   -94,   140,    -6,     6,   107,
     172,   107,    82,   145,   -94,   -94,   140,   -94,   -94,   178,
     179,     4,   173,   174,   171,   175,   -94,   128,   -94,   -94,
     180,   -94,   -94,   -94,   -94,   -94,   -94,   112,    22,    88,
     177,   -94,   183,   184,   185,     8,     6,     6,   -94,   127,
     -94,   124,   130,   151,   -94,   157,   -94,   -94,    16,   -94,
     -94,   -94,   -94,   -94,   181,     2,   182,   186,   187,   -94,
     188,     6,     6,   -94,   190,   -94,   -94,    86,   -94,     6,
     -94,   -94,   107,   107,   140,   168,   -94,   -94,     8,   -94,
     169,    43,   151,   -94,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     6,     6,     6,   -94,   189,   192,
     195,   -94,   -94,   -94,   191,   199,   -94,   -94,   200,   196,
     -94,   -94,   -94,   107,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   176,   176,   -94,   -94,   -94,   193,   -94,
     -94,     6,    84,   198,   198,   -94,   -94,   -94,   -94,   -94,
     201,   194,   -94,   -94,   198,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      96,    94,     0,     0,     0,     0,    90,    91,     0,    93,
      92,    96,     2,     0,    44,    45,    46,     0,     0,     0,
       0,     1,     0,    89,    69,    95,    66,     0,     0,     0,
       0,     0,     0,     0,    58,    59,     0,    87,    78,     0,
       0,     0,     0,     0,    44,     0,    45,     0,    80,    79,
       0,    82,    83,    81,    84,    85,    86,    68,    51,    50,
      60,    65,     0,     0,     0,     0,     0,     0,    15,    16,
      18,    19,    20,    27,    21,    42,    41,    31,    43,    39,
      32,    53,     3,     4,    48,     0,    49,     0,     0,    13,
       0,     0,     0,    75,     0,    76,    77,     0,    73,     0,
      88,    67,     0,     0,     0,    63,     9,    10,     0,    22,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     5,
       0,    11,    12,    62,     0,     0,    74,     8,     0,     0,
      48,    49,    61,     0,    27,    17,    40,    37,    38,    33,
      35,    34,    36,    23,    24,    25,    26,    29,    30,    52,
      55,     0,     0,     0,     0,     7,    47,    64,     6,    56,
       0,    71,    72,    54,     0,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -31,   -93,    -5,    -2,    -1,   -38,   -94,   -16,
     -94,   -94,   -61,   -94,   -30,   -25,     0,   -94,   208,   -94,
       1,   -29,   -94,   -94,   -94,   141,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -65,   -94,   -94,   203
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,    84,   128,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   129,    17,    48,    60,    19,
       6,    61,     7,     8,    62,    50,     9,    51,    52,    53,
      54,    55,    56,    57,    24,    10,    11,    12
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,    15,    16,    81,   138,   111,    65,    90,    65,    66,
      65,    66,    65,    66,   127,   108,    94,    45,    93,    32,
      46,    16,    47,    49,    59,    16,    67,   109,    67,   112,
      67,    27,    63,    64,    59,    16,    33,   113,   124,   125,
      68,    69,    68,    69,    68,    69,    68,    69,   -44,   102,
     110,   146,    45,   112,   112,    46,    16,    47,    49,    13,
     -50,   134,   135,   157,   158,   124,   125,    30,   168,   170,
     144,   140,   141,    31,   139,   142,   147,   148,   149,   150,
     151,   152,   144,   144,   144,   144,   112,   112,    65,    14,
      65,    66,   110,    66,   137,     1,   169,   -45,   171,   172,
      20,   159,    59,    16,   153,   154,   155,   156,    67,   175,
      67,    37,   167,    38,   -45,   103,     2,     3,     4,    21,
      87,    88,    68,    69,    68,    69,    38,    39,    26,    40,
      41,    42,    43,   -45,    97,     3,    27,    32,    44,   -46,
      39,    82,    40,    41,    42,    43,    83,    27,     3,    99,
     -45,    44,   -51,   -44,    33,    22,   -46,    34,    23,    28,
     120,   121,   122,   123,    35,    29,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    36,   145,    97,    58,
      27,   122,   123,    85,    89,    91,    92,    95,    96,    98,
     104,   105,   100,   143,   106,   107,   131,   132,   101,   163,
     133,   160,   126,   130,   136,   161,   162,   164,   165,    22,
     166,    18,     0,   173,    25,   124,     0,     0,     0,     0,
       0,     0,     0,   174
};

static const yytype_int16 yycheck[] =
{
      31,     3,     3,    28,    97,    66,     4,    36,     4,     7,
       4,     7,     4,     7,    12,     7,    41,    22,    14,     9,
      22,    22,    22,    22,    26,    26,    24,    65,    24,    67,
      24,     9,    38,    39,    36,    36,    26,    67,    22,    23,
      38,    39,    38,    39,    38,    39,    38,    39,    26,    27,
      66,     8,    57,    91,    92,    57,    57,    57,    57,    39,
      14,    91,    92,   124,   125,    22,    23,    21,   161,   162,
     108,   102,   103,    27,    99,   104,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,     4,    39,
       4,     7,   108,     7,     8,    14,    12,     9,   163,   164,
      39,   126,   104,   104,   120,   121,   122,   123,    24,   174,
      24,    12,   143,    14,    26,    27,    35,    36,    37,     0,
      38,    39,    38,    39,    38,    39,    14,    28,     7,    30,
      31,    32,    33,     9,     7,    36,     9,     9,    39,     9,
      28,    34,    30,    31,    32,    33,    39,     9,    36,    21,
      26,    39,    14,    26,    26,    11,    26,    14,    14,    21,
       3,     4,     5,     6,    14,    27,    15,    16,    17,    18,
      19,    20,     3,     4,     5,     6,    11,     8,     7,    39,
       9,     5,     6,    11,    39,     7,     7,    14,    14,    14,
      13,     8,    12,    25,    10,    10,    10,    10,    57,     8,
      12,    12,    21,    21,    14,    13,    11,     8,     8,    11,
      14,     3,    -1,    12,    11,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    35,    36,    37,    43,    62,    64,    65,    68,
      77,    78,    79,    39,    39,    47,    48,    58,    60,    61,
      39,     0,    11,    14,    76,    79,     7,     9,    21,    27,
      21,    27,     9,    26,    14,    14,    11,    12,    14,    28,
      30,    31,    32,    33,    39,    46,    47,    58,    59,    62,
      67,    69,    70,    71,    72,    73,    74,    75,    39,    47,
      60,    63,    66,    38,    39,     4,     7,    24,    38,    39,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    34,    39,    44,    11,    44,    38,    39,    39,
      63,     7,     7,    14,    57,    14,    14,     7,    14,    21,
      12,    67,    27,    27,    13,     8,    10,    10,     7,    49,
      51,    54,    49,    56,    15,    16,    17,    18,    19,    20,
       3,     4,     5,     6,    22,    23,    21,    12,    45,    57,
      21,    10,    10,    12,    56,    56,    14,     8,    45,    57,
      44,    44,    63,    25,    49,     8,     8,    49,    49,    49,
      49,    49,    49,    51,    51,    51,    51,    54,    54,    57,
      12,    13,    11,     8,     8,     8,    14,    44,    45,    12,
      45,    76,    76,    12,    29,    76
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    50,    51,    51,    51,    51,    51,    52,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    56,
      56,    56,    57,    57,    58,    58,    58,    59,    60,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    62,    62,
      63,    63,    64,    65,    65,    66,    66,    67,    67,    68,
      69,    69,    70,    71,    72,    72,    73,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      78,    78,    78,    78,    78,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     4,     3,     4,
       4,     4,     4,     3,     3,     1,     1,     3,     1,     1,
       1,     1,     2,     3,     3,     3,     3,     1,     2,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     4,     3,     3,
       1,     1,     5,     3,     7,     5,     6,     4,     3,     3,
       1,     3,     5,     5,     7,     1,     0,     2,     1,     2,
       7,     5,     5,     2,     3,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       1,     1,     1,     1,     1,     2,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
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
  case 2: /* Program: ProgramElementList  */
#line 143 "parser.yacc"
{  
  root = A_Program((yyvsp[0].programElementList));
  (yyval.program) = A_Program((yyvsp[0].programElementList));
}
#line 1458 "y.tab.c"
    break;

  case 3: /* Type: INT  */
#line 150 "parser.yacc"
{
    (yyval.type) = A_NativeType((yyvsp[0].pos), A_intTypeKind);
}
#line 1466 "y.tab.c"
    break;

  case 4: /* Type: ID  */
#line 154 "parser.yacc"
{
    (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1474 "y.tab.c"
    break;

  case 5: /* RightValList: RightVal  */
#line 160 "parser.yacc"
{
    (yyval.rightValList) = A_RightValList((yyvsp[0].rightVal), nullptr);
}
#line 1482 "y.tab.c"
    break;

  case 6: /* RightValList: RightVal COMMA RightValList  */
#line 164 "parser.yacc"
{
    (yyval.rightValList) = A_RightValList((yyvsp[-2].rightVal), (yyvsp[0].rightValList));
}
#line 1490 "y.tab.c"
    break;

  case 7: /* FnCall: ID LP RightValList RP  */
#line 170 "parser.yacc"
{
    (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].rightValList));
}
#line 1498 "y.tab.c"
    break;

  case 8: /* FnCall: ID LP RP  */
#line 174 "parser.yacc"
{
    (yyval.fnCall) = A_FnCall((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, nullptr);
}
#line 1506 "y.tab.c"
    break;

  case 9: /* ArrayExpr: ID LSB NUM RSB  */
#line 180 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].tokenId)->pos, A_IdExprLVal((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id), A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num));
}
#line 1514 "y.tab.c"
    break;

  case 10: /* ArrayExpr: ID LSB ID RSB  */
#line 184 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].tokenId)->pos, A_IdExprLVal((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id), A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id));
}
#line 1522 "y.tab.c"
    break;

  case 11: /* ArrayExpr: LeftVal LSB NUM RSB  */
#line 188 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num));
}
#line 1530 "y.tab.c"
    break;

  case 12: /* ArrayExpr: LeftVal LSB ID RSB  */
#line 192 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id));
}
#line 1538 "y.tab.c"
    break;

  case 13: /* MemberExpr: LeftVal DOT ID  */
#line 199 "parser.yacc"
{
    (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id);
}
#line 1546 "y.tab.c"
    break;

  case 14: /* MemberExpr: LeftVal DOT ID  */
#line 203 "parser.yacc"
{
    (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id);
}
#line 1554 "y.tab.c"
    break;

  case 15: /* ExprUnit: NUM  */
#line 210 "parser.yacc"
{
    (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 1562 "y.tab.c"
    break;

  case 16: /* ExprUnit: ID  */
#line 214 "parser.yacc"
{
    (yyval.exprUnit) = A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1570 "y.tab.c"
    break;

  case 17: /* ExprUnit: LP ArithExpr RP  */
#line 218 "parser.yacc"
{
    (yyval.exprUnit) = A_ArithExprUnit((yyvsp[-1].arithExpr)->pos, (yyvsp[-1].arithExpr));
}
#line 1578 "y.tab.c"
    break;

  case 18: /* ExprUnit: FnCall  */
#line 222 "parser.yacc"
{
    (yyval.exprUnit) = A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
}
#line 1586 "y.tab.c"
    break;

  case 19: /* ExprUnit: ArrayExpr  */
#line 226 "parser.yacc"
{
    (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1594 "y.tab.c"
    break;

  case 20: /* ExprUnit: MemberExpr  */
#line 230 "parser.yacc"
{
    (yyval.exprUnit) = A_MemberExprUnit((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1602 "y.tab.c"
    break;

  case 21: /* ExprUnit: ArithUExpr  */
#line 234 "parser.yacc"
{
    (yyval.exprUnit) = A_ArithUExprUnit((yyvsp[0].arithUExpr)->pos, (yyvsp[0].arithUExpr));
}
#line 1610 "y.tab.c"
    break;

  case 22: /* ArithUExpr: SUB ExprUnit  */
#line 241 "parser.yacc"
{
    (yyval.arithUExpr) = A_ArithUExpr((yyvsp[-1].pos), A_neg, (yyvsp[0].exprUnit));
}
#line 1618 "y.tab.c"
    break;

  case 23: /* ArithExpr: ArithExpr ADD ArithExpr  */
#line 248 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_add, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1626 "y.tab.c"
    break;

  case 24: /* ArithExpr: ArithExpr SUB ArithExpr  */
#line 252 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_sub, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1634 "y.tab.c"
    break;

  case 25: /* ArithExpr: ArithExpr MUL ArithExpr  */
#line 256 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_mul, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1642 "y.tab.c"
    break;

  case 26: /* ArithExpr: ArithExpr DIV ArithExpr  */
#line 260 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_div, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1650 "y.tab.c"
    break;

  case 27: /* ArithExpr: ExprUnit  */
#line 264 "parser.yacc"
{
    (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
}
#line 1658 "y.tab.c"
    break;

  case 28: /* BoolUOpExpr: NOT BoolUnit  */
#line 269 "parser.yacc"
{
  (yyval.boolUOpExpr) = A_BoolUOpExpr((yyvsp[-1].pos), A_not, (yyvsp[0].boolUnit));
}
#line 1666 "y.tab.c"
    break;

  case 29: /* BoolBiOpExpr: BoolExpr AND BoolExpr  */
#line 275 "parser.yacc"
{
    (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_and, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
}
#line 1674 "y.tab.c"
    break;

  case 30: /* BoolBiOpExpr: BoolExpr OR BoolExpr  */
#line 279 "parser.yacc"
{
    (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_or, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
}
#line 1682 "y.tab.c"
    break;

  case 31: /* BoolExpr: BoolBiOpExpr  */
#line 285 "parser.yacc"
{
    (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[0].boolBiOpExpr)->pos, (yyvsp[0].boolBiOpExpr));
}
#line 1690 "y.tab.c"
    break;

  case 32: /* BoolExpr: BoolUnit  */
#line 289 "parser.yacc"
{
    (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
}
#line 1698 "y.tab.c"
    break;

  case 33: /* ComExpr: ExprUnit LT ExprUnit  */
#line 296 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_lt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1706 "y.tab.c"
    break;

  case 34: /* ComExpr: ExprUnit LE ExprUnit  */
#line 300 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_le, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1714 "y.tab.c"
    break;

  case 35: /* ComExpr: ExprUnit GT ExprUnit  */
#line 304 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_gt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1722 "y.tab.c"
    break;

  case 36: /* ComExpr: ExprUnit GE ExprUnit  */
#line 308 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ge, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1730 "y.tab.c"
    break;

  case 37: /* ComExpr: ExprUnit EQ ExprUnit  */
#line 312 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_eq, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1738 "y.tab.c"
    break;

  case 38: /* ComExpr: ExprUnit NE ExprUnit  */
#line 316 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ne, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1746 "y.tab.c"
    break;

  case 39: /* BoolUnit: ComExpr  */
#line 323 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[0].comExpr)->pos, (yyvsp[0].comExpr));
}
#line 1754 "y.tab.c"
    break;

  case 40: /* BoolUnit: LP BoolExpr RP  */
#line 327 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
}
#line 1762 "y.tab.c"
    break;

  case 41: /* BoolUnit: BoolUOpExpr  */
#line 331 "parser.yacc"
{
    (yyval.boolUnit)=A_BoolUOpExprUnit((yyvsp[0].boolUOpExpr)->pos, (yyvsp[0].boolUOpExpr));
}
#line 1770 "y.tab.c"
    break;

  case 42: /* RightVal: ArithExpr  */
#line 337 "parser.yacc"
{
    (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
}
#line 1778 "y.tab.c"
    break;

  case 43: /* RightVal: BoolExpr  */
#line 341 "parser.yacc"
{
    (yyval.rightVal) = A_BoolExprRVal((yyvsp[0].boolExpr)->pos, (yyvsp[0].boolExpr));
}
#line 1786 "y.tab.c"
    break;

  case 44: /* LeftVal: ID  */
#line 347 "parser.yacc"
{
    (yyval.leftVal) = A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1794 "y.tab.c"
    break;

  case 45: /* LeftVal: ArrayExpr  */
#line 351 "parser.yacc"
{
    (yyval.leftVal) = A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1802 "y.tab.c"
    break;

  case 46: /* LeftVal: MemberExpr  */
#line 355 "parser.yacc"
{
    (yyval.leftVal) = A_MemberExprLVal((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1810 "y.tab.c"
    break;

  case 47: /* AssignStmt: LeftVal ASSIGN RightVal SEMICOLON  */
#line 361 "parser.yacc"
{
    (yyval.assignStmt) = A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
}
#line 1818 "y.tab.c"
    break;

  case 48: /* VarDecl: ID COLON Type  */
#line 367 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[-2].tokenId)->pos, A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type)));
}
#line 1826 "y.tab.c"
    break;

  case 49: /* VarDecl: ArrayExpr COLON Type  */
#line 371 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Array((yyvsp[-2].arrayExpr)->pos, A_VarDeclArray((yyvsp[-2].arrayExpr)->pos, (yyvsp[-2].arrayExpr)->arr->u.id, (yyvsp[-2].arrayExpr)->idx->u.num, (yyvsp[0].type)));
}
#line 1834 "y.tab.c"
    break;

  case 50: /* VarDecl: ArrayExpr  */
#line 375 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Array((yyvsp[0].arrayExpr)->pos, A_VarDeclArray((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr)->arr->u.id, (yyvsp[0].arrayExpr)->idx->u.num, nullptr));
}
#line 1842 "y.tab.c"
    break;

  case 51: /* VarDecl: ID  */
#line 379 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[0].tokenId)->pos, A_VarDeclScalar((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id, nullptr));
}
#line 1850 "y.tab.c"
    break;

  case 52: /* VarDef: ID COLON Type ASSIGN RightVal  */
#line 385 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Scalar((yyvsp[-4].tokenId)->pos, A_VarDefScalar((yyvsp[-4].tokenId)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal)));
}
#line 1858 "y.tab.c"
    break;

  case 53: /* VarDef: ID ASSIGN RightVal  */
#line 389 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Scalar((yyvsp[-2].tokenId)->pos, A_VarDefScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, nullptr, (yyvsp[0].rightVal)));
}
#line 1866 "y.tab.c"
    break;

  case 54: /* VarDef: ArrayExpr COLON Type ASSIGN LB RightValList RB  */
#line 393 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-6].arrayExpr)->pos, A_VarDefArray((yyvsp[-6].arrayExpr)->pos, (yyvsp[-6].arrayExpr)->arr->u.id, (yyvsp[-6].arrayExpr)->idx->u.num, (yyvsp[-4].type), (yyvsp[-1].rightValList)));
}
#line 1874 "y.tab.c"
    break;

  case 55: /* VarDef: ArrayExpr ASSIGN LB RightValList RB  */
#line 397 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-4].arrayExpr)->pos, A_VarDefArray((yyvsp[-4].arrayExpr)->pos, (yyvsp[-4].arrayExpr)->arr->u.id, (yyvsp[-4].arrayExpr)->idx->u.num, nullptr, (yyvsp[-1].rightValList)));
}
#line 1882 "y.tab.c"
    break;

  case 56: /* VarDef: ArrayExpr COLON Type ASSIGN LB RB  */
#line 401 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-5].arrayExpr)->pos, A_VarDefArray((yyvsp[-5].arrayExpr)->pos, (yyvsp[-5].arrayExpr)->arr->u.id, (yyvsp[-5].arrayExpr)->idx->u.num, (yyvsp[-3].type), nullptr));
}
#line 1890 "y.tab.c"
    break;

  case 57: /* VarDef: ArrayExpr ASSIGN LB RB  */
#line 405 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-3].arrayExpr)->pos, A_VarDefArray((yyvsp[-3].arrayExpr)->pos, (yyvsp[-3].arrayExpr)->arr->u.id, (yyvsp[-3].arrayExpr)->idx->u.num, nullptr, nullptr));
}
#line 1898 "y.tab.c"
    break;

  case 58: /* VarDeclStmt: LET VarDecl SEMICOLON  */
#line 412 "parser.yacc"
{
    (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-2].pos), (yyvsp[-1].varDecl));
}
#line 1906 "y.tab.c"
    break;

  case 59: /* VarDeclStmt: LET VarDef SEMICOLON  */
#line 416 "parser.yacc"
{
    (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-2].pos), (yyvsp[-1].varDef));
}
#line 1914 "y.tab.c"
    break;

  case 60: /* VarDeclList: VarDecl  */
#line 422 "parser.yacc"
{
    (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl), nullptr);
}
#line 1922 "y.tab.c"
    break;

  case 61: /* VarDeclList: VarDecl COMMA VarDeclList  */
#line 426 "parser.yacc"
{
    (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList));
}
#line 1930 "y.tab.c"
    break;

  case 62: /* StructDef: STRUCT ID LB VarDeclList RB  */
#line 432 "parser.yacc"
{
    (yyval.structDef) = A_StructDef((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
}
#line 1938 "y.tab.c"
    break;

  case 63: /* FnDecl: FN ID LP ParamDecl RP  */
#line 438 "parser.yacc"
{
    (yyval.fnDecl) = A_FnDecl((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), nullptr);
}
#line 1946 "y.tab.c"
    break;

  case 64: /* FnDecl: FN ID LP ParamDecl RP ARROW Type  */
#line 442 "parser.yacc"
{
    (yyval.fnDecl) = A_FnDecl((yyvsp[-6].pos), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
}
#line 1954 "y.tab.c"
    break;

  case 65: /* ParamDecl: VarDeclList  */
#line 449 "parser.yacc"
{
    (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
}
#line 1962 "y.tab.c"
    break;

  case 66: /* ParamDecl: %empty  */
#line 453 "parser.yacc"
{
    (yyval.paramDecl) = A_ParamDecl(nullptr);
}
#line 1970 "y.tab.c"
    break;

  case 67: /* CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList  */
#line 459 "parser.yacc"
{
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
}
#line 1978 "y.tab.c"
    break;

  case 68: /* CodeBlockStmtList: CodeBlockStmt  */
#line 463 "parser.yacc"
{
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[0].codeBlockStmt), nullptr);
}
#line 1986 "y.tab.c"
    break;

  case 69: /* FnDef: FnDecl CodeBlock  */
#line 469 "parser.yacc"
{
    (yyval.fnDef) = A_FnDef((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl), (yyvsp[0].codeBlockStmtList));
}
#line 1994 "y.tab.c"
    break;

  case 70: /* IfStmt: IF LP BoolUnit RP CodeBlock ELSE CodeBlock  */
#line 475 "parser.yacc"
{
    (yyval.ifStmt) = A_IfStmt((yyvsp[-6].pos), (yyvsp[-4].boolUnit), (yyvsp[-2].codeBlockStmtList), (yyvsp[0].codeBlockStmtList));
}
#line 2002 "y.tab.c"
    break;

  case 71: /* IfStmt: IF LP BoolUnit RP CodeBlock  */
#line 479 "parser.yacc"
{
    (yyval.ifStmt) = A_IfStmt((yyvsp[-4].pos), (yyvsp[-2].boolUnit), (yyvsp[0].codeBlockStmtList), nullptr);
}
#line 2010 "y.tab.c"
    break;

  case 72: /* WhileStmt: WHILE LP BoolUnit RP CodeBlock  */
#line 485 "parser.yacc"
{
    (yyval.whileStmt) = A_WhileStmt((yyvsp[-4].pos), (yyvsp[-2].boolUnit), (yyvsp[0].codeBlockStmtList));
}
#line 2018 "y.tab.c"
    break;

  case 73: /* CallStmt: FnCall SEMICOLON  */
#line 491 "parser.yacc"
{
    (yyval.callStmt) = A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
}
#line 2026 "y.tab.c"
    break;

  case 74: /* ReturnStmt: RETURN RightVal SEMICOLON  */
#line 497 "parser.yacc"
{
    (yyval.returnStmt) = A_ReturnStmt((yyvsp[-2].pos), (yyvsp[-1].rightVal));
}
#line 2034 "y.tab.c"
    break;

  case 75: /* ReturnStmt: RETURN SEMICOLON  */
#line 501 "parser.yacc"
{
    (yyval.returnStmt) = A_ReturnStmt((yyvsp[-1].pos), nullptr);
}
#line 2042 "y.tab.c"
    break;

  case 76: /* ContinueStmt: CONTINUE SEMICOLON  */
#line 507 "parser.yacc"
{
    (yyval.pos) = (yyvsp[-1].pos);
}
#line 2050 "y.tab.c"
    break;

  case 77: /* BreakStmt: BREAK SEMICOLON  */
#line 513 "parser.yacc"
{
    (yyval.pos) = (yyvsp[-1].pos);
}
#line 2058 "y.tab.c"
    break;

  case 78: /* CodeBlockStmt: SEMICOLON  */
#line 519 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[0].pos));
}
#line 2066 "y.tab.c"
    break;

  case 79: /* CodeBlockStmt: VarDeclStmt  */
#line 523 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 2074 "y.tab.c"
    break;

  case 80: /* CodeBlockStmt: AssignStmt  */
#line 527 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[0].assignStmt)->pos, (yyvsp[0].assignStmt));
}
#line 2082 "y.tab.c"
    break;

  case 81: /* CodeBlockStmt: CallStmt  */
#line 531 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[0].callStmt)->pos, (yyvsp[0].callStmt));
}
#line 2090 "y.tab.c"
    break;

  case 82: /* CodeBlockStmt: IfStmt  */
#line 535 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[0].ifStmt)->pos, (yyvsp[0].ifStmt));
}
#line 2098 "y.tab.c"
    break;

  case 83: /* CodeBlockStmt: WhileStmt  */
#line 539 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[0].whileStmt)->pos, (yyvsp[0].whileStmt));
}
#line 2106 "y.tab.c"
    break;

  case 84: /* CodeBlockStmt: ReturnStmt  */
#line 543 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[0].returnStmt)->pos, (yyvsp[0].returnStmt));
}
#line 2114 "y.tab.c"
    break;

  case 85: /* CodeBlockStmt: ContinueStmt  */
#line 547 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[0].pos));
}
#line 2122 "y.tab.c"
    break;

  case 86: /* CodeBlockStmt: BreakStmt  */
#line 551 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[0].pos));
}
#line 2130 "y.tab.c"
    break;

  case 87: /* CodeBlock: LB RB  */
#line 556 "parser.yacc"
                {
    (yyval.codeBlockStmtList) = nullptr;
}
#line 2138 "y.tab.c"
    break;

  case 88: /* CodeBlock: LB CodeBlockStmtList RB  */
#line 560 "parser.yacc"
{
    (yyval.codeBlockStmtList) = (yyvsp[-1].codeBlockStmtList);
}
#line 2146 "y.tab.c"
    break;

  case 89: /* FnDeclStmt: FnDecl SEMICOLON  */
#line 566 "parser.yacc"
{
    (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
}
#line 2154 "y.tab.c"
    break;

  case 90: /* ProgramElement: VarDeclStmt  */
#line 572 "parser.yacc"
{
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 2162 "y.tab.c"
    break;

  case 91: /* ProgramElement: StructDef  */
#line 576 "parser.yacc"
{
  (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
}
#line 2170 "y.tab.c"
    break;

  case 92: /* ProgramElement: FnDeclStmt  */
#line 580 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
}
#line 2178 "y.tab.c"
    break;

  case 93: /* ProgramElement: FnDef  */
#line 584 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
}
#line 2186 "y.tab.c"
    break;

  case 94: /* ProgramElement: SEMICOLON  */
#line 588 "parser.yacc"
{
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos));
}
#line 2194 "y.tab.c"
    break;

  case 95: /* ProgramElementList: ProgramElement ProgramElementList  */
#line 594 "parser.yacc"
{
  (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement), (yyvsp[0].programElementList));
}
#line 2202 "y.tab.c"
    break;

  case 96: /* ProgramElementList: %empty  */
#line 598 "parser.yacc"
{
  (yyval.programElementList) = nullptr;
}
#line 2210 "y.tab.c"
    break;


#line 2214 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 606 "parser.yacc"


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


