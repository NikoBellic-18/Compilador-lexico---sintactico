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
#line 2 "compilersintactic.y"

#include <stdio.h>
extern int yylex(void);
extern char *yytext;
extern int yylineno;
void yyerror(char *s);
extern FILE *yyin;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { IN, FL, ST, BO, FN } DataType;

#define MAX_SYMBOLS 500


typedef struct {
    char *name;
    DataType type;  
    union {
        int intValue;
        float floatValue;
        char *stringValue;
        int boolValue;  
        char *fnValue;
    } value;
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

void addSymbol(char *name, DataType type) {
    for (int i = 0; i < symbolCount; ++i) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Error: El símbolo '%s' ya está definido.\nError en la linea: %i \n", name, yylineno);
            return;
        }
    }
    if (symbolCount >= MAX_SYMBOLS) {
        printf("Error: Se ha alcanzado el límite máximo de símbolos.\n");
        return;
    }

    symbolTable[symbolCount].name = strdup(name);
    symbolTable[symbolCount].type = type;

    switch (type) {
        case IN:
            symbolTable[symbolCount].value.intValue = 0;
            break;
        case FL:
            symbolTable[symbolCount].value.floatValue = 0.0f;
            break;
        case ST:
            symbolTable[symbolCount].value.stringValue = strdup("");
            break;
        case BO:
            symbolTable[symbolCount].value.boolValue = 0;
            break;
        case FN:
			symbolTable[symbolCount].value.fnValue = strdup("");
            break;
    }
    symbolCount++;
    
}

void *getSymbolValue(char *name, DataType *type) {
    for (int i = 0; i < symbolCount; ++i) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            *type = symbolTable[i].type;
            switch (*type) {
                case IN:
                    return &symbolTable[i].value.intValue;
                case FL:
                    return &symbolTable[i].value.floatValue;
                case ST:
                    return symbolTable[i].value.stringValue;
                case BO:
                    return &symbolTable[i].value.boolValue;
                case FN:
					return symbolTable[i].value.fnValue;
            }
        }
    }
    printf("Error: El símbolo '%s' no está definido en la linea: %i.", name, yylineno);
    yyerror("");
    return NULL;
}

void setIntValue(char *name, int value) {
    DataType type;
    int *valPtr = getSymbolValue(name, &type);
    if (valPtr != NULL && type == IN) {
        *valPtr = value;
    } else {
        printf("Error: Asignación incorrecta de tipo para '%s'. En la linea: %i .\n", name, yylineno);
    }
}


void setFloatValue(char *name, float value) {
    DataType type;
    float *valPtr = getSymbolValue(name, &type);
    if (valPtr != NULL && type == FL) {
        *valPtr = value;
    } else {
        printf("Error: Asignación incorrecta de tipo para '%s'. En la linea: %i .\n", name, yylineno);
    }
}

void setStringValue(char *name, char *value) {
    DataType type;
    char **valPtr = getSymbolValue(name, &type);
    if (valPtr != NULL && type == ST) {
        *valPtr = strdup(value);
    } else {
        printf("Error: Asignación incorrecta de tipo para '%s'. En la linea: %i .\n", name, yylineno);
    }
}

void setFnValue(char *name, char *value) {
    DataType type;
    char **valPtr = getSymbolValue(name, &type);
    if (valPtr != NULL && type == FN) {
        *valPtr = strdup(value);
    } else {
        printf("Error: Asignación incorrecta de tipo para '%s'. En la linea: %i .\n", name, yylineno);
    }
}

void setBooleanValue(char *name, int value) {
    DataType type;
    int *valPtr = getSymbolValue(name, &type);
    if (valPtr != NULL && type == BO) {
        *valPtr = value;
    } else {
        printf("Error: Asignación incorrecta de tipo para '%s' en la linea: %i.\n", name, yylineno);
    }
}


#line 215 "compilersintactic.tab.c"

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

#include "compilersintactic.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_IFR = 4,                        /* IFR  */
  YYSYMBOL_STG = 5,                        /* STG  */
  YYSYMBOL_FLT = 6,                        /* FLT  */
  YYSYMBOL_MAS = 7,                        /* MAS  */
  YYSYMBOL_MEN = 8,                        /* MEN  */
  YYSYMBOL_MUL = 9,                        /* MUL  */
  YYSYMBOL_DIV = 10,                       /* DIV  */
  YYSYMBOL_TRUE = 11,                      /* TRUE  */
  YYSYMBOL_FALSE = 12,                     /* FALSE  */
  YYSYMBOL_VARS = 13,                      /* VARS  */
  YYSYMBOL_VARI = 14,                      /* VARI  */
  YYSYMBOL_VARF = 15,                      /* VARF  */
  YYSYMBOL_VARB = 16,                      /* VARB  */
  YYSYMBOL_CDO = 17,                       /* CDO  */
  YYSYMBOL_CWHILE = 18,                    /* CWHILE  */
  YYSYMBOL_FWHILE = 19,                    /* FWHILE  */
  YYSYMBOL_CFOR = 20,                      /* CFOR  */
  YYSYMBOL_FFOR = 21,                      /* FFOR  */
  YYSYMBOL_CIF = 22,                       /* CIF  */
  YYSYMBOL_FIF = 23,                       /* FIF  */
  YYSYMBOL_CEL = 24,                       /* CEL  */
  YYSYMBOL_FUN = 25,                       /* FUN  */
  YYSYMBOL_RET = 26,                       /* RET  */
  YYSYMBOL_STH = 27,                       /* STH  */
  YYSYMBOL_CASE = 28,                      /* CASE  */
  YYSYMBOL_BRK = 29,                       /* BRK  */
  YYSYMBOL_DUT = 30,                       /* DUT  */
  YYSYMBOL_TRY = 31,                       /* TRY  */
  YYSYMBOL_CATCH = 32,                     /* CATCH  */
  YYSYMBOL_ASIG = 33,                      /* ASIG  */
  YYSYMBOL_IGU = 34,                       /* IGU  */
  YYSYMBOL_DIF = 35,                       /* DIF  */
  YYSYMBOL_MEQ = 36,                       /* MEQ  */
  YYSYMBOL_MAQ = 37,                       /* MAQ  */
  YYSYMBOL_MEIQ = 38,                      /* MEIQ  */
  YYSYMBOL_MAIQ = 39,                      /* MAIQ  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_NEG = 41,                       /* NEG  */
  YYSYMBOL_OR = 42,                        /* OR  */
  YYSYMBOL_MOD = 43,                       /* MOD  */
  YYSYMBOL_APT = 44,                       /* APT  */
  YYSYMBOL_CPT = 45,                       /* CPT  */
  YYSYMBOL_ACH = 46,                       /* ACH  */
  YYSYMBOL_CCH = 47,                       /* CCH  */
  YYSYMBOL_ENDVAR = 48,                    /* ENDVAR  */
  YYSYMBOL_TWP = 49,                       /* TWP  */
  YYSYMBOL_COMA = 50,                      /* COMA  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_value = 53,                     /* value  */
  YYSYMBOL_boolean = 54,                   /* boolean  */
  YYSYMBOL_declaration = 55,               /* declaration  */
  YYSYMBOL_initialization = 56,            /* initialization  */
  YYSYMBOL_asignation = 57,                /* asignation  */
  YYSYMBOL_asignation_function = 58,       /* asignation_function  */
  YYSYMBOL_operation_int = 59,             /* operation_int  */
  YYSYMBOL_operation_int_exp = 60,         /* operation_int_exp  */
  YYSYMBOL_operation_float = 61,           /* operation_float  */
  YYSYMBOL_operation_float_exp = 62,       /* operation_float_exp  */
  YYSYMBOL_condition = 63,                 /* condition  */
  YYSYMBOL_conditioncomp = 64,             /* conditioncomp  */
  YYSYMBOL_ifcondition = 65,               /* ifcondition  */
  YYSYMBOL_body = 66,                      /* body  */
  YYSYMBOL_bodies = 67,                    /* bodies  */
  YYSYMBOL_body_stmt = 68,                 /* body_stmt  */
  YYSYMBOL_elsebody = 69,                  /* elsebody  */
  YYSYMBOL_if = 70,                        /* if  */
  YYSYMBOL_whilecondition = 71,            /* whilecondition  */
  YYSYMBOL_while = 72,                     /* while  */
  YYSYMBOL_73_do_while = 73,               /* do-while  */
  YYSYMBOL_for = 74,                       /* for  */
  YYSYMBOL_for_asignation = 75,            /* for_asignation  */
  YYSYMBOL_switch = 76,                    /* switch  */
  YYSYMBOL_cases = 77,                     /* cases  */
  YYSYMBOL_case = 78,                      /* case  */
  YYSYMBOL_79_try_catch = 79,              /* try-catch  */
  YYSYMBOL_function = 80,                  /* function  */
  YYSYMBOL_parameters = 81                 /* parameters  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   417

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  321

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   167,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   189,   190,   191,   194,   195,   198,   199,   200,
     201,   204,   205,   206,   207,   208,   209,   210,   213,   214,
     215,   216,   217,   218,   219,   222,   223,   224,   225,   228,
     229,   230,   231,   232,   233,   242,   243,   244,   245,   246,
     253,   254,   255,   256,   257,   267,   268,   269,   270,   271,
     272,   281,   282,   283,   284,   292,   293,   294,   295,   296,
     297,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   327,
     328,   329,   330,   331,   332,   335,   336,   337,   340,   343,
     344,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   359,   360,   363,   364,   367,   368,   369,   372,   375,
     378,   379,   381,   382,   385,   388,   389,   392,   393,   395,
     398,   399,   401,   402,   403,   404
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "IFR", "STG",
  "FLT", "MAS", "MEN", "MUL", "DIV", "TRUE", "FALSE", "VARS", "VARI",
  "VARF", "VARB", "CDO", "CWHILE", "FWHILE", "CFOR", "FFOR", "CIF", "FIF",
  "CEL", "FUN", "RET", "STH", "CASE", "BRK", "DUT", "TRY", "CATCH", "ASIG",
  "IGU", "DIF", "MEQ", "MAQ", "MEIQ", "MAIQ", "AND", "NEG", "OR", "MOD",
  "APT", "CPT", "ACH", "CCH", "ENDVAR", "TWP", "COMA", "$accept",
  "program", "value", "boolean", "declaration", "initialization",
  "asignation", "asignation_function", "operation_int",
  "operation_int_exp", "operation_float", "operation_float_exp",
  "condition", "conditioncomp", "ifcondition", "body", "bodies",
  "body_stmt", "elsebody", "if", "whilecondition", "while", "do-while",
  "for", "for_asignation", "switch", "cases", "case", "try-catch",
  "function", "parameters", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     258,   -25,   107,   124,   180,   192,   -24,   -14,    19,    95,
     198,    98,   -24,   234,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   194,    -9,    -2,    -1,    25,   279,
     147,   102,   -24,   168,   102,   -24,   128,   213,   160,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
       2,   171,     9,   185,   189,    26,   -68,    69,   -68,   193,
     -68,   205,   -68,   225,   -68,   166,   -68,   235,   238,   239,
     242,   208,   207,   -68,   206,   279,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   230,   -68,   -68,   -68,   -68,
     219,   188,   119,    20,   232,   260,   277,   280,   135,   190,
     243,   264,     3,   245,   247,   142,   295,   297,   304,   306,
     328,   -68,   -68,   150,   326,   327,   329,   330,   331,   -68,
     -68,   -68,    46,   335,   336,   337,   338,   -68,   -68,   138,
     339,   340,   341,   342,   -68,   -68,   286,    18,    34,    61,
      92,   294,   296,   310,   317,   318,   319,   301,   -68,   -68,
     -68,   308,   312,   316,   320,   324,   183,   208,   208,   208,
     208,   208,   208,   179,   179,   -68,   115,   126,   -68,   -68,
     -68,   321,   322,   -68,   -68,   -68,   332,   325,   -24,   -68,
      65,   307,   353,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   223,
     314,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   323,
     -68,   333,   -68,   357,   355,   334,   204,   -68,   -24,   358,
      10,   343,   131,   183,   183,   315,   344,    54,   -68,    46,
     138,   -68,   -68,   -68,   -68,   -68,   325,   -68,   208,   345,
      94,   -68,   -24,   183,   183,   346,   348,   183,   183,   208,
     347,   349,   -24,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     351,   352,   354,   350,   -24,   356,   360,   361,   359,   -68,
     367,   -68,   221,   362,   363,   -68,   364,   365,   366,   368,
     369,   -68,   -68,   -68,   -24,   -24,   380,   370,   -68,   382,
     -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,    49,     0,    65,     0,
      27,     0,    28,     0,    29,     0,    30,     0,     0,     0,
       0,     0,     0,   120,     0,   110,   113,   114,   115,   116,
     117,   118,   119,   129,    23,     0,    22,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    38,     0,     0,     0,     0,     0,     0,    40,
      41,    42,     0,     0,     0,     0,     0,    43,    50,     0,
       0,     0,     0,     0,    44,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,   125,   126,
     128,     0,     0,   107,   105,   106,   123,   142,     0,   143,
       0,     0,     0,    60,    61,    62,    64,    63,    55,    56,
      57,    59,    58,    76,    77,    78,    80,    79,    71,    72,
      73,    74,    75,    51,    52,    53,    54,    67,    68,    69,
      70,    31,    32,    36,    33,    37,    34,    35,   111,    90,
      89,    95,    91,    96,    92,    97,    93,    98,    94,     0,
       0,    81,    83,    85,    86,    87,    88,    82,    84,     0,
      99,     0,   100,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,    23,
      24,    45,    46,    47,    48,   140,   144,   145,     0,     0,
       0,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   136,   139,   101,   103,   102,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,   138,     0,     0,     0,   121,     0,     0,     0,     0,
       0,   137,   132,   133,     0,     0,     0,     0,   130,     0,
     131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -67,   -28,   371,    59,   -11,   117,   309,   -42,
     305,   -43,   -33,   373,   -68,   -12,   298,   -68,   -68,   103,
     -68,    51,   112,   155,   -68,   161,   -68,    99,   162,   163,
     -68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    13,    91,   229,    14,    73,    16,   179,    55,    56,
      57,    58,    93,    94,    35,    30,    74,    75,   258,    76,
      32,    77,    78,    79,   303,    80,   270,   271,    81,    82,
     180
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    99,    42,    92,   147,   105,    98,   177,    24,   106,
     107,   108,   109,   128,   135,   113,   114,   115,   116,   117,
      95,   105,    29,   101,    59,   106,   107,   108,   109,   122,
      31,    61,    63,   123,   124,   125,   126,   122,   268,    60,
     269,   123,   124,   125,   126,   110,    62,    64,   178,   105,
     111,    18,   118,   106,   107,   108,   109,   119,    65,    15,
     166,   110,   167,    33,    44,   168,   212,   113,   114,   115,
     116,   117,    41,    66,   127,   129,   130,   131,   132,   133,
     279,    83,   213,   280,   220,   222,   224,   226,   228,   110,
     231,   232,   233,   234,   235,   236,   128,   135,   129,   130,
     131,   132,   133,    17,   118,    84,    85,    86,    87,   214,
     248,    25,    19,    88,    89,   249,    43,   134,    84,    85,
      86,    87,   268,   230,   269,    45,    88,    89,    26,    84,
      85,    86,    87,   240,   242,   237,   238,    88,    89,    34,
     215,   283,    37,    90,   113,   114,   115,   116,   117,   183,
     184,   185,   186,   163,   164,    20,   239,   193,   194,   195,
     196,    21,    22,    23,   165,     7,   247,   241,    46,   163,
     164,   273,   102,   274,    47,    48,    49,   141,   142,   261,
     173,   118,    96,    97,    27,   187,    84,    85,    86,    87,
      88,    89,   104,   197,    88,    89,    28,    50,   136,    51,
      52,   281,    36,   264,   263,    53,    54,   259,   137,    86,
     260,    84,   292,    86,    87,    88,    89,   103,   262,   112,
     275,   276,   157,   158,   159,   160,   161,   162,   307,   308,
     166,   139,   167,   120,    39,   174,   265,   121,     1,   143,
     286,   287,   144,   145,   290,   291,   146,     2,     3,     4,
       5,     6,     7,   149,     8,   148,     9,   163,   164,    10,
     285,    11,     1,   156,   151,    12,   152,   153,   154,   155,
     295,     2,     3,     4,     5,     6,     7,   169,     8,   170,
       9,   171,   300,    10,   172,    11,   304,   176,   175,    12,
     181,   182,    67,    68,    69,    70,     6,     7,   188,     8,
     189,     9,   316,   317,    10,    71,    11,   190,    72,   191,
      12,    84,   219,    86,    87,    84,   221,    86,    87,    84,
     223,    86,    87,    84,   225,    86,    87,    84,   227,    86,
      87,   192,   198,   199,   211,   200,   201,   202,   203,   204,
     205,   206,   216,    59,   217,   207,   208,   209,   210,   218,
      61,    63,    65,   250,   243,   244,   245,   251,   246,   252,
     255,   256,   266,   277,   302,     1,   267,   253,   140,   284,
     138,     0,   312,   150,   313,     0,     0,   254,     0,     0,
     257,     0,     0,     0,    40,     0,     0,     0,   272,     0,
       0,   288,   278,   289,   282,   293,   306,   299,   294,   296,
     297,   318,   298,   320,   301,     0,   305,   100,   310,     0,
     309,     0,   311,   314,     0,   315,     0,   319
};

static const yytype_int16 yycheck[] =
{
      12,    34,    13,    31,    71,     3,    34,     4,    33,     7,
       8,     9,    10,    55,    57,     6,     7,     8,     9,    10,
      32,     3,    46,    35,    33,     7,     8,     9,    10,     3,
      44,    33,    33,     7,     8,     9,    10,     3,    28,    48,
      30,     7,     8,     9,    10,    43,    48,    48,    45,     3,
      48,     0,    43,     7,     8,     9,    10,    48,    33,     0,
      40,    43,    42,    44,    13,    45,    48,     6,     7,     8,
       9,    10,    13,    48,    48,     6,     7,     8,     9,    10,
      26,    30,    48,    29,   151,   152,   153,   154,   155,    43,
     157,   158,   159,   160,   161,   162,   138,   140,     6,     7,
       8,     9,    10,     0,    43,     3,     4,     5,     6,    48,
      45,     4,     0,    11,    12,    50,    13,    48,     3,     4,
       5,     6,    28,   156,    30,    13,    11,    12,     4,     3,
       4,     5,     6,   166,   167,   163,   164,    11,    12,    44,
      48,    47,    44,    41,     6,     7,     8,     9,    10,     7,
       8,     9,    10,    34,    35,     0,    41,     7,     8,     9,
      10,     0,     0,     0,    45,    18,   178,    41,    13,    34,
      35,    40,    44,    42,    13,    13,    13,    11,    12,   246,
      45,    43,    14,    15,     4,    43,     3,     4,     5,     6,
      11,    12,    32,    43,    11,    12,     4,     3,     5,     5,
       6,   268,     4,   246,   246,    11,    12,     3,     3,     5,
       6,     3,   279,     5,     6,    11,    12,     4,   246,    48,
     253,   254,    34,    35,    36,    37,    38,    39,     7,     8,
      40,     6,    42,    48,     0,    45,   248,    48,     4,     4,
     273,   274,     4,     4,   277,   278,     4,    13,    14,    15,
      16,    17,    18,    47,    20,    48,    22,    34,    35,    25,
     272,    27,     4,    44,    34,    31,    36,    37,    38,    39,
     282,    13,    14,    15,    16,    17,    18,    45,    20,    19,
      22,     4,   294,    25,     4,    27,   297,    23,    45,    31,
      45,    44,    13,    14,    15,    16,    17,    18,     3,    20,
       3,    22,   314,   315,    25,    26,    27,     3,    29,     3,
      31,     3,     4,     5,     6,     3,     4,     5,     6,     3,
       4,     5,     6,     3,     4,     5,     6,     3,     4,     5,
       6,     3,     6,     6,    48,     6,     6,     6,     3,     3,
       3,     3,    48,    33,    48,     6,     6,     6,     6,    48,
      33,    33,    33,    46,    33,    33,    24,     4,    33,    45,
       3,     6,     4,    48,     4,     4,   249,    44,    63,   270,
      61,    -1,     7,    75,     8,    -1,    -1,    44,    -1,    -1,
      46,    -1,    -1,    -1,    13,    -1,    -1,    -1,    45,    -1,
      -1,    45,    48,    45,    49,    48,    29,    47,    49,    48,
      48,    21,    48,    21,    48,    -1,    47,    34,    45,    -1,
      48,    -1,    48,    45,    -1,    46,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    13,    14,    15,    16,    17,    18,    20,    22,
      25,    27,    31,    52,    55,    56,    57,    70,    72,    73,
      74,    76,    79,    80,    33,     4,     4,     4,     4,    46,
      66,    44,    71,    44,    44,    65,     4,    44,    66,     0,
      55,    56,    57,    70,    72,    73,    74,    76,    79,    80,
       3,     5,     6,    11,    12,    59,    60,    61,    62,    33,
      48,    33,    48,    33,    48,    33,    48,    13,    14,    15,
      16,    26,    29,    56,    67,    68,    70,    72,    73,    74,
      76,    79,    80,    72,     3,     4,     5,     6,    11,    12,
      41,    53,    54,    63,    64,    66,    14,    15,    54,    63,
      64,    66,    44,     4,    32,     3,     7,     8,     9,    10,
      43,    48,    48,     6,     7,     8,     9,    10,    43,    48,
      48,    48,     3,     7,     8,     9,    10,    48,    60,     6,
       7,     8,     9,    10,    48,    62,     5,     3,    59,     6,
      61,    11,    12,     4,     4,     4,     4,    53,    48,    47,
      67,    34,    36,    37,    38,    39,    44,    34,    35,    36,
      37,    38,    39,    34,    35,    45,    40,    42,    45,    45,
      19,     4,     4,    45,    45,    45,    23,     4,    45,    58,
      81,    45,    44,     7,     8,     9,    10,    43,     3,     3,
       3,     3,     3,     7,     8,     9,    10,    43,     6,     6,
       6,     6,     6,     3,     3,     3,     3,     6,     6,     6,
       6,    48,    48,    48,    48,    48,    48,    48,    48,     4,
      53,     4,    53,     4,    53,     4,    53,     4,    53,    54,
      63,    53,    53,    53,    53,    53,    53,    54,    54,    41,
      63,    41,    63,    33,    33,    24,    33,    66,    45,    50,
      46,     4,    45,    44,    44,     3,     6,    46,    69,     3,
       6,    53,    54,    60,    62,    66,     4,    58,    28,    30,
      77,    78,    45,    40,    42,    63,    63,    48,    48,    26,
      29,    53,    49,    47,    78,    66,    63,    63,    45,    45,
      63,    63,    53,    48,    49,    66,    48,    48,    48,    47,
      66,    48,     4,    75,    57,    47,    29,     7,     8,    48,
      45,    48,     7,     8,    45,    46,    66,    66,    21,    47,
      21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    54,    54,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    65,    65,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    70,    70,    71,    71,    71,    72,    73,
      74,    74,    75,    75,    76,    77,    77,    78,    78,    79,
      80,    80,    81,    81,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     5,     5,     5,     5,     5,     5,     5,     4,     4,
       4,     4,     4,     4,     4,     3,     3,     3,     3,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     6,     6,     6,     6,     3,     3,     3,     3,     2,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     4,     6,     3,     3,     3,     4,     3,
      14,    15,     3,     3,     7,     1,     2,     6,     4,     7,
       6,     5,     1,     1,     3,     3
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
  case 27: /* declaration: VARS IFR ENDVAR  */
#line 198 "compilersintactic.y"
                                                {addSymbol((yyvsp[-1].strval), ST);}
#line 1511 "compilersintactic.tab.c"
    break;

  case 28: /* declaration: VARI IFR ENDVAR  */
#line 199 "compilersintactic.y"
                                                                {addSymbol((yyvsp[-1].strval), IN);}
#line 1517 "compilersintactic.tab.c"
    break;

  case 29: /* declaration: VARF IFR ENDVAR  */
#line 200 "compilersintactic.y"
                                                                {addSymbol((yyvsp[-1].strval), FL);}
#line 1523 "compilersintactic.tab.c"
    break;

  case 30: /* declaration: VARB IFR ENDVAR  */
#line 201 "compilersintactic.y"
                                                                {addSymbol((yyvsp[-1].strval), BO);}
#line 1529 "compilersintactic.tab.c"
    break;

  case 31: /* initialization: VARS IFR ASIG STG ENDVAR  */
#line 204 "compilersintactic.y"
                                                         {addSymbol((yyvsp[-3].strval), ST); setStringValue((yyvsp[-3].strval), (yyvsp[-1].strval));}
#line 1535 "compilersintactic.tab.c"
    break;

  case 32: /* initialization: VARI IFR ASIG INT ENDVAR  */
#line 205 "compilersintactic.y"
                                                                         {addSymbol((yyvsp[-3].strval), IN); setIntValue((yyvsp[-3].strval),(yyvsp[-1].intval));}
#line 1541 "compilersintactic.tab.c"
    break;

  case 33: /* initialization: VARF IFR ASIG FLT ENDVAR  */
#line 206 "compilersintactic.y"
                                                                         {addSymbol((yyvsp[-3].strval), FL); setFloatValue((yyvsp[-3].strval), (yyvsp[-1].floatval));}
#line 1547 "compilersintactic.tab.c"
    break;

  case 34: /* initialization: VARB IFR ASIG TRUE ENDVAR  */
#line 207 "compilersintactic.y"
                                                                          {addSymbol((yyvsp[-3].strval), BO); setIntValue((yyvsp[-3].strval),1);}
#line 1553 "compilersintactic.tab.c"
    break;

  case 35: /* initialization: VARB IFR ASIG FALSE ENDVAR  */
#line 208 "compilersintactic.y"
                                                                           {addSymbol((yyvsp[-3].strval), BO); setIntValue((yyvsp[-3].strval),0);}
#line 1559 "compilersintactic.tab.c"
    break;

  case 36: /* initialization: VARI IFR ASIG operation_int ENDVAR  */
#line 209 "compilersintactic.y"
                                                                                   {addSymbol((yyvsp[-3].strval), IN); setIntValue((yyvsp[-3].strval), (yyvsp[-1].intval));}
#line 1565 "compilersintactic.tab.c"
    break;

  case 37: /* initialization: VARF IFR ASIG operation_float ENDVAR  */
#line 210 "compilersintactic.y"
                                                                                     {addSymbol((yyvsp[-3].strval), FL); setFloatValue((yyvsp[-3].strval), (yyvsp[-1].floatval));}
#line 1571 "compilersintactic.tab.c"
    break;

  case 38: /* asignation: IFR ASIG STG ENDVAR  */
#line 213 "compilersintactic.y"
                                                                {setStringValue((yyvsp[-3].strval),(yyvsp[-1].strval));}
#line 1577 "compilersintactic.tab.c"
    break;

  case 39: /* asignation: IFR ASIG INT ENDVAR  */
#line 214 "compilersintactic.y"
                                                                        {setIntValue((yyvsp[-3].strval),(yyvsp[-1].intval));}
#line 1583 "compilersintactic.tab.c"
    break;

  case 40: /* asignation: IFR ASIG FLT ENDVAR  */
#line 215 "compilersintactic.y"
                                                                        {setFloatValue((yyvsp[-3].strval),(yyvsp[-1].floatval));}
#line 1589 "compilersintactic.tab.c"
    break;

  case 41: /* asignation: IFR ASIG TRUE ENDVAR  */
#line 216 "compilersintactic.y"
                                                                         {setIntValue((yyvsp[-3].strval),1);}
#line 1595 "compilersintactic.tab.c"
    break;

  case 42: /* asignation: IFR ASIG FALSE ENDVAR  */
#line 217 "compilersintactic.y"
                                                                          {setIntValue((yyvsp[-3].strval),0);}
#line 1601 "compilersintactic.tab.c"
    break;

  case 43: /* asignation: IFR ASIG operation_int ENDVAR  */
#line 218 "compilersintactic.y"
                                                                              {setIntValue((yyvsp[-3].strval),(yyvsp[-1].intval));}
#line 1607 "compilersintactic.tab.c"
    break;

  case 44: /* asignation: IFR ASIG operation_float ENDVAR  */
#line 219 "compilersintactic.y"
                                                                                {setFloatValue((yyvsp[-3].strval),(yyvsp[-1].floatval));}
#line 1613 "compilersintactic.tab.c"
    break;

  case 54: /* operation_int: operation_int DIV INT  */
#line 233 "compilersintactic.y"
                                                                      {
							if ((yyvsp[0].intval) == 0) {
								yyerror("División por cero");
								(yyval.intval) = 0;
							} else {
								(yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);
							}}
#line 1625 "compilersintactic.tab.c"
    break;

  case 55: /* operation_int_exp: INT MAS INT  */
#line 242 "compilersintactic.y"
                                                {(yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval);}
#line 1631 "compilersintactic.tab.c"
    break;

  case 56: /* operation_int_exp: INT MEN INT  */
#line 243 "compilersintactic.y"
                                                                {(yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval);}
#line 1637 "compilersintactic.tab.c"
    break;

  case 57: /* operation_int_exp: INT MUL INT  */
#line 244 "compilersintactic.y"
                                                                {(yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval);}
#line 1643 "compilersintactic.tab.c"
    break;

  case 58: /* operation_int_exp: INT MOD INT  */
#line 245 "compilersintactic.y"
                                                                {(yyval.intval) = (yyvsp[-2].intval) % (yyvsp[0].intval);}
#line 1649 "compilersintactic.tab.c"
    break;

  case 59: /* operation_int_exp: INT DIV INT  */
#line 246 "compilersintactic.y"
                                                            {
							if ((yyvsp[0].intval) == 0) {
								yyerror("División por cero");
								(yyval.intval) = 0;
							} else {
								(yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);
							}}
#line 1661 "compilersintactic.tab.c"
    break;

  case 60: /* operation_int_exp: INT INT MAS  */
#line 253 "compilersintactic.y"
                                                            {(yyval.intval) = (yyvsp[-2].intval) + (yyvsp[-1].intval);}
#line 1667 "compilersintactic.tab.c"
    break;

  case 61: /* operation_int_exp: INT INT MEN  */
#line 254 "compilersintactic.y"
                                                            {(yyval.intval) = (yyvsp[-2].intval) - (yyvsp[-1].intval);}
#line 1673 "compilersintactic.tab.c"
    break;

  case 62: /* operation_int_exp: INT INT MUL  */
#line 255 "compilersintactic.y"
                                                            {(yyval.intval) = (yyvsp[-2].intval) * (yyvsp[-1].intval);}
#line 1679 "compilersintactic.tab.c"
    break;

  case 63: /* operation_int_exp: INT INT MOD  */
#line 256 "compilersintactic.y"
                                                            {(yyval.intval) = (yyvsp[-2].intval) % (yyvsp[-1].intval);}
#line 1685 "compilersintactic.tab.c"
    break;

  case 64: /* operation_int_exp: INT INT DIV  */
#line 257 "compilersintactic.y"
                                                            {
							if ((yyvsp[-1].intval) == 0) {
								yyerror("División por cero");
								(yyval.intval) = 0;
							} else {
								(yyval.intval) = (yyvsp[-2].intval) / (yyvsp[-1].intval);
							}
					}
#line 1698 "compilersintactic.tab.c"
    break;

  case 70: /* operation_float: operation_float DIV FLT  */
#line 272 "compilersintactic.y"
                                                                        {
							if ((yyvsp[0].floatval) == 0) {
								yyerror("División por cero");
								(yyval.floatval) = 0;
							} else {
								(yyval.floatval) = (yyvsp[-2].floatval) / (yyvsp[0].floatval);
							}}
#line 1710 "compilersintactic.tab.c"
    break;

  case 71: /* operation_float_exp: FLT MAS FLT  */
#line 281 "compilersintactic.y"
                                        {(yyval.floatval) = (yyvsp[-2].floatval) + (yyvsp[0].floatval);}
#line 1716 "compilersintactic.tab.c"
    break;

  case 72: /* operation_float_exp: FLT MEN FLT  */
#line 282 "compilersintactic.y"
                                                                {(yyval.floatval) = (yyvsp[-2].floatval) - (yyvsp[0].floatval);}
#line 1722 "compilersintactic.tab.c"
    break;

  case 73: /* operation_float_exp: FLT MUL FLT  */
#line 283 "compilersintactic.y"
                                                                {(yyval.floatval) = (yyvsp[-2].floatval) * (yyvsp[0].floatval);}
#line 1728 "compilersintactic.tab.c"
    break;

  case 74: /* operation_float_exp: FLT DIV FLT  */
#line 284 "compilersintactic.y"
                                                                {
							if ((yyvsp[0].floatval) == 0) {
								yyerror("División por cero");
								(yyval.floatval) = 0;
							} else {
								(yyval.floatval) = (yyvsp[-2].floatval) / (yyvsp[0].floatval);
							}
					}
#line 1741 "compilersintactic.tab.c"
    break;

  case 75: /* operation_float_exp: FLT MOD FLT  */
#line 292 "compilersintactic.y"
                                                                {(yyval.floatval) = (int)(yyvsp[-2].floatval) % (int)(yyvsp[0].floatval);}
#line 1747 "compilersintactic.tab.c"
    break;

  case 76: /* operation_float_exp: FLT FLT MAS  */
#line 293 "compilersintactic.y"
                                                            {(yyval.floatval) = (yyvsp[-2].floatval) + (yyvsp[-1].floatval);}
#line 1753 "compilersintactic.tab.c"
    break;

  case 77: /* operation_float_exp: FLT FLT MEN  */
#line 294 "compilersintactic.y"
                                                            {(yyval.floatval) = (yyvsp[-2].floatval) - (yyvsp[-1].floatval);}
#line 1759 "compilersintactic.tab.c"
    break;

  case 78: /* operation_float_exp: FLT FLT MUL  */
#line 295 "compilersintactic.y"
                                                            {(yyval.floatval) = (yyvsp[-2].floatval) * (yyvsp[-1].floatval);}
#line 1765 "compilersintactic.tab.c"
    break;

  case 79: /* operation_float_exp: FLT FLT MOD  */
#line 296 "compilersintactic.y"
                                                            {(yyval.floatval) = (int)(yyvsp[-2].floatval) % (int)(yyvsp[-1].floatval);}
#line 1771 "compilersintactic.tab.c"
    break;

  case 80: /* operation_float_exp: FLT FLT DIV  */
#line 297 "compilersintactic.y"
                                                            {
							if ((yyvsp[-1].floatval) == 0) {
								yyerror("División por cero");
								(yyval.floatval) = 0;
							} else {
								(yyval.floatval) = (yyvsp[-2].floatval) / (yyvsp[-1].floatval);
							}
					}
#line 1784 "compilersintactic.tab.c"
    break;

  case 140: /* function: FUN IFR APT parameters CPT body  */
#line 398 "compilersintactic.y"
                                                                        {addSymbol((yyvsp[-4].strval), FN);setFnValue((yyvsp[-4].strval), (yyvsp[-4].strval));}
#line 1790 "compilersintactic.tab.c"
    break;

  case 141: /* function: FUN IFR APT CPT body  */
#line 399 "compilersintactic.y"
                                                                     {addSymbol((yyvsp[-3].strval), FN);setFnValue((yyvsp[-3].strval), (yyvsp[-3].strval));}
#line 1796 "compilersintactic.tab.c"
    break;


#line 1800 "compilersintactic.tab.c"

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

#line 407 "compilersintactic.y"


/** Seccion de codigo de usuario **/


void yyerror(char *s) {
    printf("Error sintáctico: %s en la linea: %i\n", s, yylineno);
}

int main(int argc, char **argv){
	printf("Inicio del programa: \n");
	if(argc > 1){
		yyin = fopen(argv[1], "rt");
	}else{
		yyin = stdin;
	}
	yyparse();
	return 0;
}
