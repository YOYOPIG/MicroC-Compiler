/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "codeGen.h"
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
extern int errorStatus;
extern bool isFunction;
extern bool isArg;
extern bool forwardDeclarationLine;
extern char errID[256];
extern bool dumpTheTableRightHereAccordingToTheHomeworkRequirement;
extern int tableScope;

////For jasmin code gen
FILE* file;

//DS for table
typedef struct element{
	char Name[256];
	char Kind[10]; // 3 kinds
	char Type[10];
	int Scope;
	int index;
	char Attribute[1000]; //func input
	bool isForwardFunction;
	struct element* next;
} tableElement;

tableElement *scope[30];

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(int tar_scope, char tar_name[256]);
void create_symbol();
int insert_symbol(int tar_scope, char name[256], char type[10], char kind[10], bool forward);
void set_dump_symbol(int tar_scope);
void dump_symbol(int tar_scope, bool print);
void yyerror(char *s);
void ysemError(short type);

void Dbug(char *s);

/* Global variables coming in hot */
int fuckin_flag1 = 0;
int cur_scope = 0;
char last_queried_data_type[10] = {};
char lookup_var_name[256] = {};
char lookup_var_type[10] = {};
int lookup_var_scope; /*0:global, else:local*/
char lookup_var_index[10] = {};
char assign_var_name[256] = {};
char assign_var_type[10] = {};
char assign_var_index[10] = {};


#line 125 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRINT = 258,
    IF = 259,
    ELSE = 260,
    FOR = 261,
    WHILE = 262,
    ID = 263,
    SEMICOLON = 264,
    ADD = 265,
    SUB = 266,
    MUL = 267,
    DIV = 268,
    MOD = 269,
    INC = 270,
    DEC = 271,
    MT = 272,
    LT = 273,
    MTE = 274,
    LTE = 275,
    EQ = 276,
    NE = 277,
    ASGN = 278,
    ADDASGN = 279,
    SUBASGN = 280,
    MULASGN = 281,
    DIVASGN = 282,
    MODASGN = 283,
    AND = 284,
    OR = 285,
    NOT = 286,
    LB = 287,
    RB = 288,
    LCB = 289,
    RCB = 290,
    LSB = 291,
    RSB = 292,
    COMMA = 293,
    VOID = 294,
    INT = 295,
    FLOAT = 296,
    STRING = 297,
    BOOL = 298,
    RET = 299,
    I_CONST = 300,
    F_CONST = 301,
    STR_CONST = 302,
    TRUE = 303,
    FALSE = 304
  };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define ID 263
#define SEMICOLON 264
#define ADD 265
#define SUB 266
#define MUL 267
#define DIV 268
#define MOD 269
#define INC 270
#define DEC 271
#define MT 272
#define LT 273
#define MTE 274
#define LTE 275
#define EQ 276
#define NE 277
#define ASGN 278
#define ADDASGN 279
#define SUBASGN 280
#define MULASGN 281
#define DIVASGN 282
#define MODASGN 283
#define AND 284
#define OR 285
#define NOT 286
#define LB 287
#define RB 288
#define LCB 289
#define RCB 290
#define LSB 291
#define RSB 292
#define COMMA 293
#define VOID 294
#define INT 295
#define FLOAT 296
#define STRING 297
#define BOOL 298
#define RET 299
#define I_CONST 300
#define F_CONST 301
#define STR_CONST 302
#define TRUE 303
#define FALSE 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 64 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char string[1000];
    _Bool bool_val;

#line 270 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 287 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   424

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   108,   112,   113,   114,   115,   116,   117,
     118,   119,   123,   124,   125,   126,   127,   131,   132,   136,
     137,   142,   143,   144,   145,   146,   150,   151,   151,   155,
     156,   160,   161,   165,   166,   170,   171,   175,   175,   176,
     180,   181,   182,   183,   186,   196,   197,   198,   199,   203,
     204,   205,   209,   210,   211,   212,   213,   217,   218,   222,
     223,   224,   228,   229,   233,   234,   235,   236,   237,   238,
     242,   243,   244,   248,   249,   253,   254,   258,   259,   263,
     264,   265,   266,   267,   268,   272,   273,   277,   278,   279,
     283,   284,   288,   289,   290,   291,   292,   296,   300,   313,
     317
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "IF", "ELSE", "FOR", "WHILE",
  "ID", "SEMICOLON", "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC", "MT",
  "LT", "MTE", "LTE", "EQ", "NE", "ASGN", "ADDASGN", "SUBASGN", "MULASGN",
  "DIVASGN", "MODASGN", "AND", "OR", "NOT", "LB", "RB", "LCB", "RCB",
  "LSB", "RSB", "COMMA", "VOID", "INT", "FLOAT", "STRING", "BOOL", "RET",
  "I_CONST", "F_CONST", "STR_CONST", "TRUE", "FALSE", "$accept", "program",
  "statement", "declaration", "function_item_list", "function_item",
  "type", "compound_statement", "$@1", "a_random_nonterminal",
  "another_random_nonterminal_what_is_going_on_out_here",
  "expression_statement", "expression", "assignment_expression", "$@2",
  "unary_expression", "postfix_expression", "primary_expression",
  "constants", "arguments", "unary_operator", "cast_expression",
  "assignment_operator", "logical_expression", "relational_expression",
  "arithmetic_expression", "high_precedence_arithmetic_expression",
  "relational_operator", "lp_arithmetic_operator",
  "hp_arithmetic_operator", "selection_statement", "iteration_statement",
  "print_func", "print_tar", "ID_expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -69

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -69,   122,   -69,   -17,   -11,    -3,    19,   -69,   -69,   -69,
     -69,   350,   350,   -69,   350,    39,   -69,   -69,   -69,   -69,
     -69,    16,   -69,   -69,   -69,   -69,   -69,   -69,   -69,    75,
     -69,   -69,     0,   -69,    54,     1,   -69,   -69,   375,    15,
     123,    43,    23,   -69,   -69,   -69,   -69,    49,   350,   258,
     350,   -69,   -69,   -19,   -69,   216,   -69,    78,    11,   -69,
     350,   163,   -69,   -69,   277,    60,   -69,   -69,   350,   350,
     -69,   -69,   -69,   -69,   -69,   -69,   350,   -69,   -69,   350,
     -69,   -69,   -69,   350,   -69,    53,   -69,   -15,   303,   303,
      22,   -69,   -69,   -69,   169,   -69,   -69,   -69,   350,   153,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   350,   -69,   -69,
      34,    80,   -69,   123,   123,    43,    23,   -69,   -69,   216,
     322,   331,   216,   -69,   -69,    84,   148,    52,   -69,    75,
     -69,   -69,   350,   375,   111,   216,    77,   216,    86,   -69,
     -69,   -69,   108,   153,   -69,   -69,   -69,   216,   -69,   216,
     -69,   216,   -69,   -69,   -69,   -69,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,     0,   100,    33,    59,
      60,     0,     0,    61,     0,    27,    25,    21,    22,    24,
      23,     0,    52,    53,    54,    55,    56,     2,     4,     0,
       5,     6,     0,    35,    78,    40,    44,    50,     0,    39,
      72,    74,    76,     7,     8,     9,    49,     0,     0,     0,
       0,    41,    42,     0,    26,     0,    10,     0,     0,    34,
       0,     0,    47,    48,     0,     0,    62,    43,     0,     0,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
      87,    88,    89,     0,    99,     0,    98,     0,     0,     0,
       0,    51,    32,     4,     0,    29,    11,    13,     0,    20,
      36,    64,    68,    69,    65,    66,    67,     0,    45,    57,
       0,     0,    78,    71,    70,    73,    75,    77,    97,     0,
       0,     0,     0,    28,    30,    44,     0,     0,    18,     0,
      38,    46,     0,     0,    91,     0,     0,     0,     0,    92,
      12,    14,    16,    20,    19,    58,    63,     0,    95,     0,
      93,     0,    15,    17,    90,    96,    94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,    -1,   -42,   -69,   -23,   -59,   -69,   -69,   -69,
      33,   -39,    -9,   -18,   -69,   -10,   -69,    37,    92,   -69,
     -69,    14,   -69,   -69,   -57,   -68,    70,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    92,    28,   127,   128,    29,    30,    55,    94,
      95,    31,    32,    33,    61,    34,    35,    36,    37,   110,
      38,    67,   107,    39,    40,    41,    42,    76,    79,    83,
      43,    44,    45,    85,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    51,    52,    57,    58,    53,   111,    88,   115,    59,
      89,   113,   114,    93,    91,    47,    62,    63,   119,    60,
      97,    48,    86,    60,     7,    56,     9,    10,    66,    49,
     126,    11,    12,    64,    98,    80,    81,    82,    60,    87,
     129,    90,   100,    99,    68,    69,   109,    13,    14,   120,
     121,    50,    93,    77,    78,   122,    53,     7,   112,   112,
      60,    22,    23,    24,    25,    26,   112,   131,     7,   112,
       9,    10,   132,   117,    54,    11,    12,   -37,   -37,   -37,
     -37,   -37,   -37,     7,   129,   142,   118,    96,   112,   130,
     143,    13,    14,   140,    22,    23,    24,    25,    26,    16,
      17,    18,    19,    20,   144,    22,    23,    24,    25,    26,
     149,   136,   138,   133,   145,    60,   147,   152,   134,   151,
     153,   139,     2,    66,    60,     3,     4,   124,     5,     6,
       7,     8,     9,    10,   148,   125,   150,    11,    12,    84,
      70,    71,    72,    73,    74,    75,   154,   146,   155,   116,
     156,     0,     0,    13,    14,     0,    15,   141,    77,    78,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     3,     4,     0,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    11,    12,   101,   102,   103,   104,
     105,   106,    16,    17,    18,    19,    20,     0,     0,     0,
      13,    14,     0,    15,   123,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     3,
       4,     0,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
      15,     0,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     7,     8,     9,    10,
       0,     0,     0,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     9,    10,    13,
      14,     0,    11,    12,     0,     0,     0,    16,    17,    18,
      19,    20,     0,    22,    23,    24,    25,    26,    13,    14,
     108,     7,     8,     9,    10,     0,     0,     0,    11,    12,
       0,     0,    22,    23,    24,    25,    26,     0,     0,     0,
       7,     0,     9,    10,    13,    14,     0,    11,    12,     7,
       0,     9,    10,     0,     0,     0,    11,    12,    22,    23,
      24,    25,    26,    13,    14,   135,     0,     0,     7,     0,
       9,    10,    13,    14,   137,    11,    12,    22,    23,    24,
      25,    26,     0,     0,     0,     0,    22,    23,    24,    25,
      26,    13,    14,     7,     0,     9,    10,     0,     0,     0,
      11,    12,     0,     0,     0,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,    13,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,    26
};

static const yytype_int16 yycheck[] =
{
       1,    11,    12,    21,    29,    14,    65,    49,    76,     9,
      49,    68,    69,    55,    33,    32,    15,    16,    33,    38,
       9,    32,    47,    38,     8,     9,    10,    11,    38,    32,
      98,    15,    16,    32,    23,    12,    13,    14,    38,    48,
      99,    50,    60,    32,    29,    30,    64,    31,    32,    88,
      89,    32,    94,    10,    11,    33,    65,     8,    68,    69,
      38,    45,    46,    47,    48,    49,    76,    33,     8,    79,
      10,    11,    38,    83,    35,    15,    16,    23,    24,    25,
      26,    27,    28,     8,   143,    33,    33,     9,    98,   107,
      38,    31,    32,     9,    45,    46,    47,    48,    49,    39,
      40,    41,    42,    43,   129,    45,    46,    47,    48,    49,
      33,   120,   121,    33,   132,    38,     5,     9,   119,    33,
     143,   122,     0,   133,    38,     3,     4,    94,     6,     7,
       8,     9,    10,    11,   135,    98,   137,    15,    16,    47,
      17,    18,    19,    20,    21,    22,   147,   133,   149,    79,
     151,    -1,    -1,    31,    32,    -1,    34,     9,    10,    11,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    23,    24,    25,    26,
      27,    28,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      34,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    10,    11,    31,
      32,    -1,    15,    16,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    -1,    45,    46,    47,    48,    49,    31,    32,
      33,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      -1,    -1,    45,    46,    47,    48,    49,    -1,    -1,    -1,
       8,    -1,    10,    11,    31,    32,    -1,    15,    16,     8,
      -1,    10,    11,    -1,    -1,    -1,    15,    16,    45,    46,
      47,    48,    49,    31,    32,    33,    -1,    -1,     8,    -1,
      10,    11,    31,    32,    33,    15,    16,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    31,    32,     8,    -1,    10,    11,    -1,    -1,    -1,
      15,    16,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,     0,     3,     4,     6,     7,     8,     9,    10,
      11,    15,    16,    31,    32,    34,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    52,    53,    56,
      57,    61,    62,    63,    65,    66,    67,    68,    70,    73,
      74,    75,    76,    80,    81,    82,    84,    32,    32,    32,
      32,    65,    65,    62,    35,    58,     9,    63,    84,     9,
      38,    64,    15,    16,    32,    32,    65,    71,    29,    30,
      17,    18,    19,    20,    21,    22,    77,    10,    11,    78,
      12,    13,    14,    79,    68,    83,    84,    62,    53,    61,
      62,    33,    52,    53,    59,    60,     9,     9,    23,    32,
      63,    23,    24,    25,    26,    27,    28,    72,    33,    63,
      69,    56,    65,    74,    74,    75,    76,    65,    33,    33,
      61,    61,    33,    35,    60,    67,    75,    54,    55,    56,
      63,    33,    38,    33,    52,    33,    62,    33,    62,    52,
       9,     9,    33,    38,    84,    63,    71,     5,    52,    33,
      52,    33,     9,    55,    52,    52,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    56,    56,    56,    56,    57,    58,    57,    59,
      59,    60,    60,    61,    61,    62,    62,    64,    63,    63,
      65,    65,    65,    65,    66,    66,    66,    66,    66,    67,
      67,    67,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    82,    83,    83,
      84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       2,     3,     5,     3,     5,     6,     5,     3,     1,     2,
       0,     1,     1,     1,     1,     1,     2,     0,     4,     1,
       2,     1,     1,     1,     2,     1,     3,     0,     4,     1,
       1,     2,     2,     2,     1,     3,     4,     2,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     5,     5,     6,     7,     6,     7,     4,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 12:
#line 123 "compiler_hw3.y" /* yacc.c:1646  */
    { /*[SCOPE] cur_scope, [NAME] $2 [Type] $1*/int i = insert_symbol(cur_scope, (yyvsp[-3].string), (yyvsp[-4].string), "variable", false); if(cur_scope==0) CGGlobalVar((yyvsp[-3].string), (yyvsp[-4].string), 1, (yyvsp[-1].string)); else { char str[12]; sprintf(str, "%d", i);CGLocalVar(str, (yyvsp[-1].string), (yyvsp[-4].string)); } }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "compiler_hw3.y" /* yacc.c:1646  */
    { /*[SCOPE] cur_scope, [NAME] $2 [Type] $1*/int i = insert_symbol(cur_scope, (yyvsp[-1].string), (yyvsp[-2].string), "variable", false); if(cur_scope==0) CGGlobalVar((yyvsp[-1].string), (yyvsp[-2].string), 0, ""); else { char str[12]; sprintf(str, "%d", i);CGLocalVar(str, "0", (yyvsp[-2].string)); } }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "compiler_hw3.y" /* yacc.c:1646  */
    { /*[SCOPE] cur_scope, [NAME] $2 [Type] $1*/int i = insert_symbol(cur_scope, (yyvsp[-3].string), (yyvsp[-4].string), "variable", false); if(cur_scope==0) CGGlobalVar((yyvsp[-3].string), (yyvsp[-4].string), 0, "No globals here"); else { char str[12]; sprintf(str, "%d", i);CGSaveToRegister(str, (yyvsp[-4].string)); } }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 126 "compiler_hw3.y" /* yacc.c:1646  */
    { /*[SCOPE] cur_scope, [NAME] $2 [Type] $1*/insert_symbol(cur_scope, (yyvsp[-4].string), (yyvsp[-5].string), "function", true); isFunction = true; forwardDeclarationLine = true;}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 127 "compiler_hw3.y" /* yacc.c:1646  */
    { /*[SCOPE] cur_scope, [NAME] $2 [Type] $1*/insert_symbol(cur_scope, (yyvsp[-3].string), (yyvsp[-4].string), "function", false); isFunction = true; CGFunction((yyvsp[-3].string), (yyvsp[-4].string));}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 136 "compiler_hw3.y" /* yacc.c:1646  */
    { /*printf("[SCOPE] %d, [NAME] %s [Type] %s\n", cur_scope+1, $2, $1);*/insert_symbol(cur_scope + 1, (yyvsp[0].string), (yyvsp[-1].string), "parameter", false); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 142 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "int"); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 143 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "float"); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 144 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "bool"); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 145 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "string"); }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 146 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "void"); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 151 "compiler_hw3.y" /* yacc.c:1646  */
    {cur_scope++;}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 151 "compiler_hw3.y" /* yacc.c:1646  */
    {cur_scope--; set_dump_symbol(cur_scope+1); if(cur_scope==0) writeAssemblyCode("return\n.end method\n");}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 175 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(assign_var_index, lookup_var_index); strcpy(assign_var_type, lookup_var_type); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 175 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("\nWEEEEEE\n%d\n", lookup_var_scope);CGCheckSpecialAssignment((yyvsp[-1].string), assign_var_type); CGSaveToRegister(assign_var_index, assign_var_type); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 181 "compiler_hw3.y" /* yacc.c:1646  */
    { CGIncrement(); CGSaveToRegister(lookup_var_index, lookup_var_type); CGLoadRegister(lookup_var_index, lookup_var_type); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 182 "compiler_hw3.y" /* yacc.c:1646  */
    { CGDecrement(); CGSaveToRegister(lookup_var_index, lookup_var_type); CGLoadRegister(lookup_var_index, lookup_var_type); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 186 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[0].string), "ID")==0) 
												{ 
													if(lookup_var_scope==0) 
														CGLoadGlobal(lookup_var_name, lookup_var_type);
													else
														CGLoadRegister(lookup_var_index, lookup_var_type);
												} 
											  else if(strcmp((yyvsp[0].string), "")!=0) 
											  	CGLoadConst((yyvsp[0].string)); 
											}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 196 "compiler_hw3.y" /* yacc.c:1646  */
    { isFunction = true; }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 197 "compiler_hw3.y" /* yacc.c:1646  */
    { isFunction = true; }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 198 "compiler_hw3.y" /* yacc.c:1646  */
    { CGIncrement(); CGSaveToRegister(lookup_var_index, lookup_var_type);  CGLoadRegister(lookup_var_index, lookup_var_type); CGDecrement(); }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 199 "compiler_hw3.y" /* yacc.c:1646  */
    { CGDecrement(); CGSaveToRegister(lookup_var_index, lookup_var_type);  CGLoadRegister(lookup_var_index, lookup_var_type); CGIncrement(); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 203 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), "ID"); if(lookup_symbol(cur_scope, (yyvsp[0].string))==0){ errorStatus = 2; strcpy(errID, (yyvsp[0].string)); } }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 204 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 205 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), ""); }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 209 "compiler_hw3.y" /* yacc.c:1646  */
    {strcpy((yyval.string), yytext); strcpy(last_queried_data_type, "int");}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 210 "compiler_hw3.y" /* yacc.c:1646  */
    {strcpy((yyval.string), yytext); strcpy(last_queried_data_type, "float");}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 211 "compiler_hw3.y" /* yacc.c:1646  */
    {strcpy((yyval.string), yytext); strcpy(last_queried_data_type, "string");}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 212 "compiler_hw3.y" /* yacc.c:1646  */
    {strcpy((yyval.string), yytext); strcpy(last_queried_data_type, "bool");}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 213 "compiler_hw3.y" /* yacc.c:1646  */
    {strcpy((yyval.string), yytext); strcpy(last_queried_data_type, "bool");}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 217 "compiler_hw3.y" /* yacc.c:1646  */
    { isArg = true; }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 218 "compiler_hw3.y" /* yacc.c:1646  */
    { isArg = true; }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 233 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 234 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 235 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 236 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 237 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 238 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 253 "compiler_hw3.y" /* yacc.c:1646  */
    { CGArithmetic((yyvsp[-1].string), "int"); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 258 "compiler_hw3.y" /* yacc.c:1646  */
    { CGArithmetic((yyvsp[-1].string), "int"); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 272 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 273 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 277 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 278 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 279 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 300 "compiler_hw3.y" /* yacc.c:1646  */
    { 
				if(lookup_symbol(cur_scope, (yyvsp[0].string))==0)
				{ 
					errorStatus = 2;  strcpy(errID, (yyvsp[0].string));
				} 
				strcpy((yyval.string), (yyvsp[0].string)); 
				if(lookup_var_scope==0) 
					CGPrintGlobal(lookup_var_name, lookup_var_type); 
				else 
				{ 
					CGPrintRegister(lookup_var_index, lookup_var_type);
				}
			}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 313 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); CGPrint((yyvsp[0].string), last_queried_data_type);}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 317 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.string), yytext); }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1848 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
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

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 320 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
	file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
	fclose(file);

	create_symbol();
    yyparse();
	dump_symbol(0, true);
	if(fuckin_flag1!=1)
		printf("\nTotal lines: %d \n",yylineno);

	// fprintf(file, "\treturn\n"
    //               ".end method\n");

    return 0;
}

void yyerror(char *s)
{
	printf("%d: %s\n", yylineno + 1, buf);
	if(errorStatus==1)
    {
        errorStatus = 0;
        if(isFunction)
        {
            ysemError(2);
        }
        else
        {
            ysemError(3);
        }
    }
    else if(errorStatus==2)
    {
        errorStatus = 0;
        if(isFunction)
        {
			ysemError(2);
        }
            else
                ysemError(1);
    }
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno + 1, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
	fuckin_flag1 = 1;
}

void Dbug(char *s)
{
    printf("%s\n", s);
}

void create_symbol() 
{
	//initialize symbol table
	int i;
	for(i=0;i<30;++i)
	{
		scope[i] = NULL;
	}
}

//Ret value: 
//-2 :forward function
//-1 :Error
//int: index that inserted
int insert_symbol(int tar_scope, char name[256], char type[10], char kind[10], bool forward)
{
	//create new element
	tableElement* newElement = malloc(sizeof(tableElement));
	strcpy(newElement->Name, name);
	strcpy(newElement->Type, type);
	strcpy(newElement->Kind, kind);
	newElement->index = 0;
	newElement->isForwardFunction = forward;
	if(strcmp(kind, "function") != 0)
		strcpy(newElement->Attribute, "");
	else
	{
		tableElement* iter = scope[tar_scope+1];
		if(iter)
		{
			strcpy(newElement->Attribute, iter->Type);
			while(iter->next)
			{
				iter = iter->next;
				strcat(newElement->Attribute, ",");
				strcat(newElement->Attribute, iter->Type);
			}
		}
	}

	int tmp = lookup_symbol(tar_scope, name);
	if(tmp == 1)
	{
		errorStatus = 1;
		strcpy(errID, name);
		return -1;
	}
	else if(tmp == 2)
	{
		//forward function
		return -2;
	}


	if(scope[tar_scope] == NULL)
	{
		// Empty, insert new
		scope[tar_scope] = newElement;
		newElement->next = NULL;
		newElement->index = 0;
		return 0;
	}
	else
	{
		// Not empty, insert new to tail
		int index = 0;
		tableElement* iter = scope[tar_scope];
		while(iter->next)
		{
			index++;
			iter = iter->next;
		}
		iter->next = newElement;
		newElement->next = NULL;
		index++;
		newElement->index = index;
		return index;
	}
}

// Return 2 = found forwarded function, 1 = found, 0 = not found
int lookup_symbol(int tar_scope, char tar_name[256]) 
{
	tableElement* iter = scope[tar_scope];
	int cur_scope = tar_scope;
	while(cur_scope>=0)
	{
		while(iter)
		{
			if(strcmp(tar_name, iter->Name) == 0)
			{
				strcpy(last_queried_data_type, iter->Type);
				strcpy(lookup_var_name, iter->Name);
				strcpy(lookup_var_type, iter->Type);
				lookup_var_scope = cur_scope;
				sprintf(lookup_var_index, "%d", iter->index);
				if(iter->isForwardFunction)
				{
					iter->isForwardFunction = false;
					return 2;
				}
				return 1;
			}
			iter = iter->next;
		}
		cur_scope--;
		iter = scope[cur_scope];
	}
	return 0;
}

void set_dump_symbol(int tar_scope) {
	dumpTheTableRightHereAccordingToTheHomeworkRequirement = true;
	tableScope = tar_scope;
}

void dump_symbol(int tar_scope, bool print)
{
	if(scope[tar_scope] == NULL)
	{
		return;
	}
	if(!print)
	{
		scope[tar_scope] = NULL;
		return;
	}
	int ctr = 0;
	tableElement *cur = scope[tar_scope];
	printf("\nIndex     Name      Kind        Type      Scope     Attribute \n");
	while(cur)
	{
    	printf("\n%-10d%-10s%-12s%-10s%-10d%-10s", ctr, cur->Name, cur->Kind, cur->Type, tar_scope, cur->Attribute);
		cur = cur->next;
		ctr++;
	}
	printf("\n\n");
	scope[tar_scope] = NULL;
}

void ysemError(short type)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s", yylineno+1, buf);
    if(type==1)
        printf("\n| %s %s", "Undeclared variable", errID);
    else if(type==2)
        printf("\n| %s %s", "Undeclared function", errID);
    else if(type==3)
        printf("\n| %s %s", "Redeclared variable", errID);
    else if(type==4)
        printf("\n| %s %s", "Redeclared function", errID);
    printf("\n|-----------------------------------------------|\n\n");
}
