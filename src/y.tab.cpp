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


#line 86 "y.tab.cpp"

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
       0,   142,   142,   149,   154,   159,   163,   170,   174,   180,
     184,   190,   194,   200,   204,   208,   212,   218,   222,   229,
     233,   237,   242,   246,   250,   257,   261,   265,   269,   273,
     278,   284,   288,   294,   298,   305,   309,   313,   317,   321,
     325,   331,   335,   339,   345,   349,   353,   360,   366,   370,
     374,   380,   386,   390,   394,   398,   404,   408,   412,   416,
     420,   424,   431,   435,   441,   445,   451,   457,   461,   468,
     473,   478,   482,   488,   494,   498,   504,   510,   516,   520,
     526,   532,   538,   542,   546,   550,   554,   558,   562,   566,
     570,   576,   579,   585,   591,   595,   599,   603,   607
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

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

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
};

static const yytype_int16 yycheck[] =
{
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
#line 1286 "y.tab.cpp"
    break;

  case 3: /* ProgramElementList: ProgramElement ProgramElementList  */
#line 150 "parser.yacc"
{
  (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement), (yyvsp[0].programElementList));
}
#line 1294 "y.tab.cpp"
    break;

  case 4: /* ProgramElementList: %empty  */
#line 154 "parser.yacc"
{
  (yyval.programElementList) = nullptr;
}
#line 1302 "y.tab.cpp"
    break;

  case 5: /* NUM: UNUM  */
#line 160 "parser.yacc"
{
    (yyval.tokenNum)=A_TokenNum((yyvsp[0].tokenNum)->pos,(yyvsp[0].tokenNum)->num);
}
#line 1310 "y.tab.cpp"
    break;

  case 6: /* NUM: SUB UNUM  */
#line 164 "parser.yacc"
{
    (yyval.tokenNum)=A_TokenNum((yyvsp[-1].pos),-(yyvsp[0].tokenNum)->num);
}
#line 1318 "y.tab.cpp"
    break;

  case 7: /* Type: INT  */
#line 171 "parser.yacc"
{
    (yyval.type) = A_NativeType((yyvsp[0].pos), A_intTypeKind);
}
#line 1326 "y.tab.cpp"
    break;

  case 8: /* Type: ID  */
#line 175 "parser.yacc"
{
    (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1334 "y.tab.cpp"
    break;

  case 9: /* RightValList: RightVal  */
#line 181 "parser.yacc"
{
    (yyval.rightValList) = A_RightValList((yyvsp[0].rightVal), nullptr);
}
#line 1342 "y.tab.cpp"
    break;

  case 10: /* RightValList: RightVal COMMA RightValList  */
#line 185 "parser.yacc"
{
    (yyval.rightValList) = A_RightValList((yyvsp[-2].rightVal), (yyvsp[0].rightValList));
}
#line 1350 "y.tab.cpp"
    break;

  case 11: /* FnCall: ID LP RightValList RP  */
#line 191 "parser.yacc"
{
    (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].rightValList));
}
#line 1358 "y.tab.cpp"
    break;

  case 12: /* FnCall: ID LP RP  */
#line 195 "parser.yacc"
{
    (yyval.fnCall) = A_FnCall((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, nullptr);
}
#line 1366 "y.tab.cpp"
    break;

  case 13: /* ArrayExpr: ID LSB NUM RSB  */
#line 201 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].tokenId)->pos, A_IdExprLVal((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id), A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num));
}
#line 1374 "y.tab.cpp"
    break;

  case 14: /* ArrayExpr: ID LSB ID RSB  */
#line 205 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].tokenId)->pos, A_IdExprLVal((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id), A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id));
}
#line 1382 "y.tab.cpp"
    break;

  case 15: /* ArrayExpr: LeftVal LSB NUM RSB  */
#line 209 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num));
}
#line 1390 "y.tab.cpp"
    break;

  case 16: /* ArrayExpr: LeftVal LSB ID RSB  */
#line 213 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id));
}
#line 1398 "y.tab.cpp"
    break;

  case 17: /* MemberExpr: ID DOT ID  */
#line 219 "parser.yacc"
{
    (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].tokenId)->pos, A_IdExprLVal((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id), (yyvsp[0].tokenId)->id);
}
#line 1406 "y.tab.cpp"
    break;

  case 18: /* MemberExpr: LeftVal DOT ID  */
#line 223 "parser.yacc"
{
    (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id);
}
#line 1414 "y.tab.cpp"
    break;

  case 19: /* ExprUnit: NUM  */
#line 230 "parser.yacc"
{
    (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 1422 "y.tab.cpp"
    break;

  case 20: /* ExprUnit: ID  */
#line 234 "parser.yacc"
{
    (yyval.exprUnit) = A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1430 "y.tab.cpp"
    break;

  case 21: /* ExprUnit: LP ArithExpr RP  */
#line 238 "parser.yacc"
{
    (yyval.exprUnit) = A_ArithExprUnit((yyvsp[-1].arithExpr)->pos, (yyvsp[-1].arithExpr));
}
#line 1438 "y.tab.cpp"
    break;

  case 22: /* ExprUnit: FnCall  */
#line 243 "parser.yacc"
{
    (yyval.exprUnit) = A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
}
#line 1446 "y.tab.cpp"
    break;

  case 23: /* ExprUnit: ArrayExpr  */
#line 247 "parser.yacc"
{
    (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1454 "y.tab.cpp"
    break;

  case 24: /* ExprUnit: MemberExpr  */
#line 251 "parser.yacc"
{
    (yyval.exprUnit) = A_MemberExprUnit((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1462 "y.tab.cpp"
    break;

  case 25: /* ArithExpr: ArithExpr ADD ArithExpr  */
#line 258 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_add, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1470 "y.tab.cpp"
    break;

  case 26: /* ArithExpr: ArithExpr SUB ArithExpr  */
#line 262 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_sub, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1478 "y.tab.cpp"
    break;

  case 27: /* ArithExpr: ArithExpr MUL ArithExpr  */
#line 266 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_mul, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1486 "y.tab.cpp"
    break;

  case 28: /* ArithExpr: ArithExpr DIV ArithExpr  */
#line 270 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_div, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 1494 "y.tab.cpp"
    break;

  case 29: /* ArithExpr: ExprUnit  */
#line 274 "parser.yacc"
{
    (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
}
#line 1502 "y.tab.cpp"
    break;

  case 30: /* BoolUOpExpr: NOT BoolUnit  */
#line 279 "parser.yacc"
{
  (yyval.boolUOpExpr) = A_BoolUOpExpr((yyvsp[-1].pos), A_not, (yyvsp[0].boolUnit));
}
#line 1510 "y.tab.cpp"
    break;

  case 31: /* BoolBiOpExpr: BoolExpr AND BoolExpr  */
#line 285 "parser.yacc"
{
    (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_and, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
}
#line 1518 "y.tab.cpp"
    break;

  case 32: /* BoolBiOpExpr: BoolExpr OR BoolExpr  */
#line 289 "parser.yacc"
{
    (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_or, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
}
#line 1526 "y.tab.cpp"
    break;

  case 33: /* BoolExpr: BoolBiOpExpr  */
#line 295 "parser.yacc"
{
    (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[0].boolBiOpExpr)->pos, (yyvsp[0].boolBiOpExpr));
}
#line 1534 "y.tab.cpp"
    break;

  case 34: /* BoolExpr: BoolUnit  */
#line 299 "parser.yacc"
{
    (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
}
#line 1542 "y.tab.cpp"
    break;

  case 35: /* ComExpr: ExprUnit LT ExprUnit  */
#line 306 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_lt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1550 "y.tab.cpp"
    break;

  case 36: /* ComExpr: ExprUnit LE ExprUnit  */
#line 310 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_le, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1558 "y.tab.cpp"
    break;

  case 37: /* ComExpr: ExprUnit GT ExprUnit  */
#line 314 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_gt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1566 "y.tab.cpp"
    break;

  case 38: /* ComExpr: ExprUnit GE ExprUnit  */
#line 318 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ge, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1574 "y.tab.cpp"
    break;

  case 39: /* ComExpr: ExprUnit EQ ExprUnit  */
#line 322 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_eq, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1582 "y.tab.cpp"
    break;

  case 40: /* ComExpr: ExprUnit NE ExprUnit  */
#line 326 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ne, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1590 "y.tab.cpp"
    break;

  case 41: /* BoolUnit: LP ComExpr RP  */
#line 332 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-2].pos), (yyvsp[-1].comExpr));
}
#line 1598 "y.tab.cpp"
    break;

  case 42: /* BoolUnit: LP BoolExpr RP  */
#line 336 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
}
#line 1606 "y.tab.cpp"
    break;

  case 43: /* BoolUnit: BoolUOpExpr  */
#line 340 "parser.yacc"
{
    (yyval.boolUnit)=A_BoolUOpExprUnit((yyvsp[0].boolUOpExpr)->pos, (yyvsp[0].boolUOpExpr));
}
#line 1614 "y.tab.cpp"
    break;

  case 44: /* BoolUnit_: LP ComExpr RP  */
#line 346 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-2].pos), (yyvsp[-1].comExpr));
}
#line 1622 "y.tab.cpp"
    break;

  case 45: /* BoolUnit_: LP BoolExpr RP  */
#line 350 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
}
#line 1630 "y.tab.cpp"
    break;

  case 46: /* BoolUnit_: LP BoolUOpExpr RP  */
#line 354 "parser.yacc"
{
    (yyval.boolUnit)=A_BoolUOpExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolUOpExpr));
}
#line 1638 "y.tab.cpp"
    break;

  case 47: /* RightVal: ArithExpr  */
#line 361 "parser.yacc"
{
    (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
}
#line 1646 "y.tab.cpp"
    break;

  case 48: /* LeftVal: ID  */
#line 367 "parser.yacc"
{
    (yyval.leftVal) = A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1654 "y.tab.cpp"
    break;

  case 49: /* LeftVal: ArrayExpr  */
#line 371 "parser.yacc"
{
    (yyval.leftVal) = A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1662 "y.tab.cpp"
    break;

  case 50: /* LeftVal: MemberExpr  */
#line 375 "parser.yacc"
{
    (yyval.leftVal) = A_MemberExprLVal((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1670 "y.tab.cpp"
    break;

  case 51: /* AssignStmt: LeftVal ASSIGN RightVal SEMICOLON  */
#line 381 "parser.yacc"
{
    (yyval.assignStmt) = A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
}
#line 1678 "y.tab.cpp"
    break;

  case 52: /* VarDecl: ID COLON Type  */
#line 387 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[-2].tokenId)->pos, A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type)));
}
#line 1686 "y.tab.cpp"
    break;

  case 53: /* VarDecl: ArrayExpr COLON Type  */
#line 391 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Array((yyvsp[-2].arrayExpr)->pos, A_VarDeclArray((yyvsp[-2].arrayExpr)->pos, (yyvsp[-2].arrayExpr)->arr->u.id, (yyvsp[-2].arrayExpr)->idx->u.num, (yyvsp[0].type)));
}
#line 1694 "y.tab.cpp"
    break;

  case 54: /* VarDecl: ArrayExpr  */
#line 395 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Array((yyvsp[0].arrayExpr)->pos, A_VarDeclArray((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr)->arr->u.id, (yyvsp[0].arrayExpr)->idx->u.num, nullptr));
}
#line 1702 "y.tab.cpp"
    break;

  case 55: /* VarDecl: ID  */
#line 399 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[0].tokenId)->pos, A_VarDeclScalar((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id, nullptr));
}
#line 1710 "y.tab.cpp"
    break;

  case 56: /* VarDef: ID COLON Type ASSIGN RightVal  */
#line 405 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Scalar((yyvsp[-4].tokenId)->pos, A_VarDefScalar((yyvsp[-4].tokenId)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal)));
}
#line 1718 "y.tab.cpp"
    break;

  case 57: /* VarDef: ID ASSIGN RightVal  */
#line 409 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Scalar((yyvsp[-2].tokenId)->pos, A_VarDefScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, nullptr, (yyvsp[0].rightVal)));
}
#line 1726 "y.tab.cpp"
    break;

  case 58: /* VarDef: ArrayExpr COLON Type ASSIGN LB RightValList RB  */
#line 413 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-6].arrayExpr)->pos, A_VarDefArray((yyvsp[-6].arrayExpr)->pos, (yyvsp[-6].arrayExpr)->arr->u.id, (yyvsp[-6].arrayExpr)->idx->u.num, (yyvsp[-4].type), (yyvsp[-1].rightValList)));
}
#line 1734 "y.tab.cpp"
    break;

  case 59: /* VarDef: ArrayExpr ASSIGN LB RightValList RB  */
#line 417 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-4].arrayExpr)->pos, A_VarDefArray((yyvsp[-4].arrayExpr)->pos, (yyvsp[-4].arrayExpr)->arr->u.id, (yyvsp[-4].arrayExpr)->idx->u.num, nullptr, (yyvsp[-1].rightValList)));
}
#line 1742 "y.tab.cpp"
    break;

  case 60: /* VarDef: ArrayExpr COLON Type ASSIGN LB RB  */
#line 421 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-5].arrayExpr)->pos, A_VarDefArray((yyvsp[-5].arrayExpr)->pos, (yyvsp[-5].arrayExpr)->arr->u.id, (yyvsp[-5].arrayExpr)->idx->u.num, (yyvsp[-3].type), nullptr));
}
#line 1750 "y.tab.cpp"
    break;

  case 61: /* VarDef: ArrayExpr ASSIGN LB RB  */
#line 425 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[-3].arrayExpr)->pos, A_VarDefArray((yyvsp[-3].arrayExpr)->pos, (yyvsp[-3].arrayExpr)->arr->u.id, (yyvsp[-3].arrayExpr)->idx->u.num, nullptr, nullptr));
}
#line 1758 "y.tab.cpp"
    break;

  case 62: /* VarDeclStmt: LET VarDecl SEMICOLON  */
#line 432 "parser.yacc"
{
    (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-2].pos), (yyvsp[-1].varDecl));
}
#line 1766 "y.tab.cpp"
    break;

  case 63: /* VarDeclStmt: LET VarDef SEMICOLON  */
#line 436 "parser.yacc"
{
    (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-2].pos), (yyvsp[-1].varDef));
}
#line 1774 "y.tab.cpp"
    break;

  case 64: /* VarDeclList: VarDecl  */
#line 442 "parser.yacc"
{
    (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl), nullptr);
}
#line 1782 "y.tab.cpp"
    break;

  case 65: /* VarDeclList: VarDecl COMMA VarDeclList  */
#line 446 "parser.yacc"
{
    (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList));
}
#line 1790 "y.tab.cpp"
    break;

  case 66: /* StructDef: STRUCT ID LB VarDeclList RB  */
#line 452 "parser.yacc"
{
    (yyval.structDef) = A_StructDef((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
}
#line 1798 "y.tab.cpp"
    break;

  case 67: /* FnDecl: FN ID LP ParamDecl RP  */
#line 458 "parser.yacc"
{
    (yyval.fnDecl) = A_FnDecl((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), nullptr);
}
#line 1806 "y.tab.cpp"
    break;

  case 68: /* FnDecl: FN ID LP ParamDecl RP ARROW Type  */
#line 462 "parser.yacc"
{
    (yyval.fnDecl) = A_FnDecl((yyvsp[-6].pos), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
}
#line 1814 "y.tab.cpp"
    break;

  case 69: /* ParamDecl: VarDeclList  */
#line 469 "parser.yacc"
{
    (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
}
#line 1822 "y.tab.cpp"
    break;

  case 70: /* ParamDecl: %empty  */
#line 473 "parser.yacc"
{
    (yyval.paramDecl) = A_ParamDecl(nullptr);
}
#line 1830 "y.tab.cpp"
    break;

  case 71: /* CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList  */
#line 479 "parser.yacc"
{
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
}
#line 1838 "y.tab.cpp"
    break;

  case 72: /* CodeBlockStmtList: CodeBlockStmt  */
#line 483 "parser.yacc"
{
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[0].codeBlockStmt), nullptr);
}
#line 1846 "y.tab.cpp"
    break;

  case 73: /* FnDef: FnDecl CodeBlock  */
#line 489 "parser.yacc"
{
    (yyval.fnDef) = A_FnDef((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl), (yyvsp[0].codeBlockStmtList));
}
#line 1854 "y.tab.cpp"
    break;

  case 74: /* IfStmt: IF BoolUnit_ CodeBlock ELSE CodeBlock  */
#line 495 "parser.yacc"
{
    (yyval.ifStmt) = A_IfStmt((yyvsp[-4].pos), (yyvsp[-3].boolUnit), (yyvsp[-2].codeBlockStmtList), (yyvsp[0].codeBlockStmtList));
}
#line 1862 "y.tab.cpp"
    break;

  case 75: /* IfStmt: IF BoolUnit_ CodeBlock  */
#line 499 "parser.yacc"
{
    (yyval.ifStmt) = A_IfStmt((yyvsp[-2].pos), (yyvsp[-1].boolUnit), (yyvsp[0].codeBlockStmtList), nullptr);
}
#line 1870 "y.tab.cpp"
    break;

  case 76: /* WhileStmt: WHILE BoolUnit_ CodeBlock  */
#line 505 "parser.yacc"
{
    (yyval.whileStmt) = A_WhileStmt((yyvsp[-2].pos), (yyvsp[-1].boolUnit), (yyvsp[0].codeBlockStmtList));
}
#line 1878 "y.tab.cpp"
    break;

  case 77: /* CallStmt: FnCall SEMICOLON  */
#line 511 "parser.yacc"
{
    (yyval.callStmt) = A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
}
#line 1886 "y.tab.cpp"
    break;

  case 78: /* ReturnStmt: RETURN RightVal SEMICOLON  */
#line 517 "parser.yacc"
{
    (yyval.returnStmt) = A_ReturnStmt((yyvsp[-2].pos), (yyvsp[-1].rightVal));
}
#line 1894 "y.tab.cpp"
    break;

  case 79: /* ReturnStmt: RETURN SEMICOLON  */
#line 521 "parser.yacc"
{
    (yyval.returnStmt) = A_ReturnStmt((yyvsp[-1].pos), nullptr);
}
#line 1902 "y.tab.cpp"
    break;

  case 80: /* ContinueStmt: CONTINUE SEMICOLON  */
#line 527 "parser.yacc"
{
    (yyval.pos) = (yyvsp[-1].pos);
}
#line 1910 "y.tab.cpp"
    break;

  case 81: /* BreakStmt: BREAK SEMICOLON  */
#line 533 "parser.yacc"
{
    (yyval.pos) = (yyvsp[-1].pos);
}
#line 1918 "y.tab.cpp"
    break;

  case 82: /* CodeBlockStmt: SEMICOLON  */
#line 539 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[0].pos));
}
#line 1926 "y.tab.cpp"
    break;

  case 83: /* CodeBlockStmt: VarDeclStmt  */
#line 543 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1934 "y.tab.cpp"
    break;

  case 84: /* CodeBlockStmt: AssignStmt  */
#line 547 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[0].assignStmt)->pos, (yyvsp[0].assignStmt));
}
#line 1942 "y.tab.cpp"
    break;

  case 85: /* CodeBlockStmt: CallStmt  */
#line 551 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[0].callStmt)->pos, (yyvsp[0].callStmt));
}
#line 1950 "y.tab.cpp"
    break;

  case 86: /* CodeBlockStmt: IfStmt  */
#line 555 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[0].ifStmt)->pos, (yyvsp[0].ifStmt));
}
#line 1958 "y.tab.cpp"
    break;

  case 87: /* CodeBlockStmt: WhileStmt  */
#line 559 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[0].whileStmt)->pos, (yyvsp[0].whileStmt));
}
#line 1966 "y.tab.cpp"
    break;

  case 88: /* CodeBlockStmt: ReturnStmt  */
#line 563 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[0].returnStmt)->pos, (yyvsp[0].returnStmt));
}
#line 1974 "y.tab.cpp"
    break;

  case 89: /* CodeBlockStmt: ContinueStmt  */
#line 567 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[0].pos));
}
#line 1982 "y.tab.cpp"
    break;

  case 90: /* CodeBlockStmt: BreakStmt  */
#line 571 "parser.yacc"
{
    (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[0].pos));
}
#line 1990 "y.tab.cpp"
    break;

  case 91: /* CodeBlock: LB RB  */
#line 576 "parser.yacc"
                {
    (yyval.codeBlockStmtList) = nullptr;
}
#line 1998 "y.tab.cpp"
    break;

  case 92: /* CodeBlock: LB CodeBlockStmtList RB  */
#line 580 "parser.yacc"
{
    (yyval.codeBlockStmtList) = (yyvsp[-1].codeBlockStmtList);
}
#line 2006 "y.tab.cpp"
    break;

  case 93: /* FnDeclStmt: FnDecl SEMICOLON  */
#line 586 "parser.yacc"
{
    (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
}
#line 2014 "y.tab.cpp"
    break;

  case 94: /* ProgramElement: VarDeclStmt  */
#line 592 "parser.yacc"
{
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 2022 "y.tab.cpp"
    break;

  case 95: /* ProgramElement: StructDef  */
#line 596 "parser.yacc"
{
  (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
}
#line 2030 "y.tab.cpp"
    break;

  case 96: /* ProgramElement: FnDeclStmt  */
#line 600 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
}
#line 2038 "y.tab.cpp"
    break;

  case 97: /* ProgramElement: FnDef  */
#line 604 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
}
#line 2046 "y.tab.cpp"
    break;

  case 98: /* ProgramElement: SEMICOLON  */
#line 608 "parser.yacc"
{
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos));
}
#line 2054 "y.tab.cpp"
    break;


#line 2058 "y.tab.cpp"

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

#line 616 "parser.yacc"


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


