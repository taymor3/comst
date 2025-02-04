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
#line 2 "parser.ypp" /* yacc.c:339  */

	#include "part3_helpers.h"
	
	using namespace std;

	extern int yylex();
	extern int yylineno;
    extern const char* yytext;
	
	Node *root_node;		//root node of parse tree
	Vec_buf code_buffer;	//buffer to store the riski commands
	variable_table var_table;
	Function_Table func_table;
	
	void yyerror(const char*);
	void semantic_err(string err);
	void operational_err(string err);

#line 85 "parser.tab.cpp" /* yacc.c:339  */

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
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    WRITE = 261,
    READ = 262,
    OPTIONAL = 263,
    WHILE = 264,
    DO = 265,
    IF = 266,
    RETURN = 267,
    ID = 268,
    INTEGERNUM = 269,
    REALNUM = 270,
    STR = 271,
    ASSIGN = 272,
    OR = 273,
    AND = 274,
    RELOP = 275,
    ADDOP = 276,
    MULOP = 277,
    NOT = 278,
    THEN = 279,
    ELSE = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 162 "parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

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
      31,    32,     2,     2,    21,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,    22,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,     2,    20,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,    18,     2,     2,     2,     2,
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
      15,    16,    24,    25,    26,    27,    28,    29,    30,    33,
      34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    46,    46,    79,    95,   100,   110,   122,
     125,   130,   133,   138,   141,   146,   156,   169,   173,   179,
     184,   190,   193,   198,   219,   233,   233,   254,   268,   292,
     297,   302,   309,   320,   325,   342,   345,   348,   356,   359,
     362,   365,   375,   400,   410,   430,   465,   489,   513,   543,
     561,   574,   591,   604,   617,   627,   761,   772,   811,   850,
     859,   889,   922,   931,   942,   954,   968,  1069,  1077,  1082,
    1097,  1111,  1118
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "WRITE", "READ",
  "OPTIONAL", "WHILE", "DO", "IF", "RETURN", "ID", "INTEGERNUM", "REALNUM",
  "STR", "'{'", "'}'", "'['", "']'", "','", "';'", "':'", "ASSIGN", "OR",
  "AND", "RELOP", "ADDOP", "MULOP", "NOT", "'('", "')'", "THEN", "ELSE",
  "$accept", "PROGRAM", "FDEFS", "$@1", "FUNC_DEC_API",
  "FUNC_DEC_ARGLIST_OPT", "DCL_OPT", "FUNC_DEF_API",
  "FUNC_DEF_ARGLIST_OPT", "DCL_OPT_VAL", "FUNC_ARGLIST", "BLK", "$@2",
  "DCL", "TYPE", "STLIST", "STMT", "return", "write", "read", "ASSN",
  "LVAL", "CNTRL", "BEXP", "EXP", "NUM", "CALL", "CALL_ARGS",
  "CALL_ARGLIST", "M", "N", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   123,   125,    91,
      93,    44,    59,    58,   272,   273,   274,   275,   276,   277,
     278,    40,    41,   279,   280
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -49

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -68,    40,    84,   -68,   -68,   -68,   -68,   -68,   -68,     3,
       2,    14,   -68,   -68,    -4,   -68,   138,    29,   -11,   -68,
      62,   -68,    96,   -68,    36,    53,   144,    28,   -68,    66,
      74,   110,   -68,   130,    81,   -68,    98,   -10,   -68,   -68,
      84,   -68,   -68,   -68,    78,   145,   -68,   -68,   127,   -68,
      99,   100,   -68,   -68,   119,   139,   -68,    16,    54,   103,
      67,   -68,   149,   -68,   -68,   -68,   -68,   -68,   148,   -68,
     108,   -68,   -68,   -68,   110,   165,    66,   166,   153,   -68,
      77,   163,    16,   147,    16,    22,   -19,   136,   -68,   113,
     164,    84,    19,   150,    90,   -68,    19,   -68,    19,    19,
     -68,    84,   -68,   151,   128,   -68,   152,    13,   -68,   114,
     126,   -68,   -68,   -68,    19,   -68,   146,    45,   154,   158,
      19,   -68,   116,   156,   -68,   -68,   159,   167,   168,   -68,
     -68,    16,    16,    98,    45,   -68,    19,   -68,   -68,   -68,
     -68,   -68,    98,   161,   -68,   157,    45,   -68,   -68,   -68,
      98,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     1,    29,    30,    31,     5,     3,     0,
       0,     0,    25,     4,     0,    33,     0,    15,     0,    12,
       0,    20,     0,    24,    71,     0,     0,     0,     7,     0,
       0,     0,    17,     0,    16,    26,     0,     0,    14,    28,
       0,    27,    64,    65,     0,     0,    11,     9,     0,    19,
       0,     0,    23,     8,     0,     0,    71,     0,     0,    61,
       0,    41,     0,    32,    40,    39,    38,    35,     0,    37,
       0,    62,    63,    13,     0,     0,     0,     0,     0,    18,
       0,     0,     0,    61,     0,     0,     0,     0,    43,     0,
       0,     0,    68,     0,     0,    34,     0,    36,     0,     0,
      22,     0,    10,     0,     0,    48,     0,     0,    54,     0,
       0,    71,    71,    71,     0,    42,     0,    70,     0,    67,
       0,    59,     0,    57,    58,    21,     0,     0,     0,    71,
      56,     0,     0,     0,    55,    66,     0,    60,    47,    45,
      44,    46,     0,    52,    53,    50,    69,    51,    72,    71,
       0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   -68,   -68,   155,   -21,   -68,   160,   -26,
     -68,   170,   -68,   -13,     1,   -68,   -17,   -68,   -68,   -68,
     -68,   111,   -68,   -67,   -36,   169,   -68,   -68,   -68,   -54,
     -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,     7,    18,    19,     8,    20,    21,
      22,    61,    15,    62,    41,    24,    63,    64,    65,    66,
      67,    68,    69,    86,    87,    71,    72,   118,   119,    36,
     149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    23,    82,     9,    38,    49,   111,   112,    46,    16,
      29,    25,    39,    26,   113,   107,    11,   108,   109,    12,
      52,    30,    89,   129,    94,     4,     5,     6,    17,    83,
      42,    43,    83,    42,    43,    83,    42,    43,   111,   112,
       3,    73,    42,    43,   104,    14,    84,    85,   100,   110,
      60,    28,    84,    85,    35,    38,   117,   131,   132,   133,
     122,    93,   123,   124,   143,   144,    37,    83,    42,    43,
       4,     5,     6,    98,    99,   142,    88,    39,   134,    45,
      83,    42,    43,    31,   137,    60,    93,     4,     5,     6,
      83,    42,    43,   103,    32,   150,    47,    70,    60,    74,
     146,    75,   125,    53,    54,    55,    70,    56,    60,    57,
      58,    59,    42,    43,    70,    12,   145,    33,    98,    99,
      29,    31,   121,    48,    90,   147,    91,   -48,    34,    60,
      97,    78,    79,   151,    92,   115,    98,    99,   138,   111,
     112,    98,    99,    16,    98,    99,   130,     4,     5,     6,
      80,    27,    40,   114,    98,    99,    98,    99,   121,    25,
     127,    26,    27,   114,    98,    99,    76,    90,    77,    91,
      81,    95,    96,   101,    40,   102,   105,   116,    92,   136,
      13,   139,   120,   126,   128,    99,   135,   112,    50,   140,
     141,   148,   106,    51,     0,     0,    44
};

static const yytype_int16 yycheck[] =
{
      36,    14,    56,     2,    25,    31,    25,    26,    29,    13,
      21,    21,    25,    23,    33,    82,    13,    84,    85,    17,
      33,    32,    58,    10,    60,     3,     4,     5,    32,    13,
      14,    15,    13,    14,    15,    13,    14,    15,    25,    26,
       0,    40,    14,    15,    80,    31,    30,    31,    74,    85,
      31,    22,    30,    31,    18,    76,    92,   111,   112,   113,
      96,    60,    98,    99,   131,   132,    13,    13,    14,    15,
       3,     4,     5,    28,    29,   129,    22,    90,   114,    13,
      13,    14,    15,    21,   120,    31,    85,     3,     4,     5,
      13,    14,    15,    16,    32,   149,    22,   133,    31,    21,
     136,    23,   101,    22,     6,     7,   142,     9,    31,    11,
      12,    13,    14,    15,   150,    17,   133,    21,    28,    29,
      21,    21,    32,    13,    21,   142,    23,    24,    32,    31,
      22,    32,    32,   150,    31,    22,    28,    29,    22,    25,
      26,    28,    29,    13,    28,    29,    32,     3,     4,     5,
      31,    24,     8,    27,    28,    29,    28,    29,    32,    21,
      32,    23,    24,    27,    28,    29,    21,    21,    23,    23,
      31,    22,    24,     8,     8,    22,    13,    13,    31,    21,
      10,    22,    32,    32,    32,    29,    32,    26,    33,    22,
      22,    34,    81,    33,    -1,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    37,     0,     3,     4,     5,    39,    42,    49,
      38,    13,    17,    46,    31,    47,    13,    32,    40,    41,
      43,    44,    45,    48,    50,    21,    23,    24,    22,    21,
      32,    21,    32,    21,    32,    18,    64,    13,    41,    48,
       8,    49,    14,    15,    60,    13,    41,    22,    13,    44,
      40,    43,    48,    22,     6,     7,     9,    11,    12,    13,
      31,    46,    48,    51,    52,    53,    54,    55,    56,    57,
      59,    60,    61,    49,    21,    23,    21,    23,    32,    32,
      31,    31,    64,    13,    30,    31,    58,    59,    22,    59,
      21,    23,    31,    49,    59,    22,    24,    22,    28,    29,
      44,     8,    22,    16,    59,    13,    56,    58,    58,    58,
      59,    25,    26,    33,    27,    22,    13,    59,    62,    63,
      32,    32,    59,    59,    59,    49,    32,    32,    32,    10,
      32,    64,    64,    64,    59,    32,    21,    59,    22,    22,
      22,    22,    64,    58,    58,    51,    59,    51,    34,    65,
      64,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    38,    37,    37,    37,    39,    39,    39,
      39,    40,    40,    41,    41,    42,    42,    42,    42,    43,
      43,    44,    44,    45,    45,    47,    46,    48,    48,    49,
      49,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    54,    55,    56,    57,
      57,    57,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    62,    62,    63,
      63,    64,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     4,     2,     0,     5,     6,     6,
       8,     3,     1,     4,     3,     4,     5,     5,     7,     3,
       1,     6,     5,     3,     1,     0,     4,     3,     3,     1,
       1,     1,     3,     0,     2,     1,     2,     1,     1,     1,
       1,     1,     3,     2,     5,     5,     5,     4,     1,     9,
       5,     6,     4,     4,     2,     3,     3,     3,     3,     3,
       4,     1,     1,     1,     1,     1,     4,     1,     0,     3,
       1,     0,     0
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
        case 2:
#line 41 "parser.ypp" /* yacc.c:1646  */
    { 		//---------------------------------------------rule below finished---------------------------------------------
				root_node = new Node();		
			}
#line 1353 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 46 "parser.ypp" /* yacc.c:1646  */
    {	//mid rule action@@@-------------------rule below finished---------------------------------------------
				//1.casting
				FuncApiSymbol* func_def_api1 = dynamic_cast<FuncApiSymbol*>((yyvsp[0]));	
				//2.check function
				Function_Table_Entry* func_entry = func_table.find_func_entry(func_def_api1->func_id);
				if(func_entry == NULL){		//not in symbol table - add it
					func_entry = func_table.insert_func_entry(func_def_api1->ret_type, func_def_api1->func_id, func_def_api1->func_args);
				}
				else{	//the function is defined
					if(!func_entry->is_matching(func_def_api1->ret_type, func_def_api1->func_id, func_def_api1->func_args)){
						string err = string("rule 3: definition of function '") + func_def_api1->func_id + "' doesn't match it's declaration";
						semantic_err(err);
					}
					if(func_entry->def_line != -1){	//function already defined
						string err = string("redefinition of function '") + func_def_api1->func_id + "'";
						semantic_err(err);
					}
				}
				//3. assignments
				func_entry->func_args = func_def_api1->func_args;
				func_table.curr_func_entry = func_entry;
				var_table.func_args = func_entry->func_args;
				func_entry->define_and_backpatch(code_buffer.nextquad());
			}
#line 1382 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 70 "parser.ypp" /* yacc.c:1646  */
    { 
				(yyval) = new Node();
				StmtSymbol *blk1 = dynamic_cast<StmtSymbol*>((yyvsp[0]));	

				code_buffer.backpatch(blk1->nextlist, code_buffer.nextquad());
				string ret =  "RETRN";
				code_buffer.emit(ret);	//rule 5: in case no explicit return, ensure returning to caller

			}
#line 1396 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "parser.ypp" /* yacc.c:1646  */
    { 
				//1.casting
				(yyval) = new Node();
				FuncApiSymbol* func_dec_api1 = dynamic_cast<FuncApiSymbol*>((yyvsp[0]));	
				//2.check function
				Function_Table_Entry* func_entry = func_table.find_func_entry(func_dec_api1->func_id);
				if(func_entry == NULL){		//not in symbol table - add it
					func_entry = func_table.insert_func_entry(func_dec_api1->ret_type, func_dec_api1->func_id, func_dec_api1->func_args);
				}
				else{	//the function is defined
					if(!func_entry->is_matching(func_dec_api1->ret_type, func_dec_api1->func_id, func_dec_api1->func_args)){
						string err = string("redeclaration of function '") + func_dec_api1->func_id + "'";
						semantic_err(err);
					}
				}
			}
#line 1417 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "parser.ypp" /* yacc.c:1646  */
    { 
				(yyval) = new Node();
			}
#line 1425 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "parser.ypp" /* yacc.c:1646  */
    { //---------------------------------------------rule below finished------------------------------------
		//1.casting
		(yyval) = new FuncApiSymbol();
		FuncApiSymbol* func_dec_api0 = dynamic_cast<FuncApiSymbol*>((yyval));
		TypeSymbol *type1 = dynamic_cast<TypeSymbol*>((yyvsp[-4]));	
        Terminal *id1 = dynamic_cast<Terminal*>((yyvsp[-3]));	
		//2.assignments
		func_dec_api0->ret_type = type1->type_value;
		func_dec_api0->func_id = id1->terminal_value;
	}
#line 1440 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "parser.ypp" /* yacc.c:1646  */
    { //---------------------------------------------rule below finished-------------------------------
		//1.casting
		(yyval) = new FuncApiSymbol();
		FuncApiSymbol* func_dec_api0 = dynamic_cast<FuncApiSymbol*>((yyval));	
		TypeSymbol *type1 = dynamic_cast<TypeSymbol*>((yyvsp[-5]));	
        Terminal *id1 = dynamic_cast<Terminal*>((yyvsp[-4]));	
		FuncArgsSymbol* func_arglist1 = dynamic_cast<FuncArgsSymbol*>((yyvsp[-2]));	
		//2.assignments
		func_dec_api0->ret_type = type1->type_value;
		func_dec_api0->func_id = id1->terminal_value;
		func_dec_api0->func_args = func_arglist1->args;
	}
#line 1457 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 122 "parser.ypp" /* yacc.c:1646  */
    { //+++++++++++++++++++++++++++++rule contains optional++++not implemented++++++++++++++++++
		
	}
#line 1465 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 125 "parser.ypp" /* yacc.c:1646  */
    { //+++++++++++++++++++++++++++++rule contains optional++++not implemented+
		
	}
#line 1473 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 130 "parser.ypp" /* yacc.c:1646  */
    { //+++++++++++++++++++++++++++++rule contains optional++++not implemented++++++++++
		
	}
#line 1481 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 133 "parser.ypp" /* yacc.c:1646  */
    {		//+++++++++++++++++++++++++++++rule contains optional++++not implemented+++++++++++++++++++++++
		
	}
#line 1489 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 138 "parser.ypp" /* yacc.c:1646  */
    { //+++++++++++++++++++++++++++++rule contains optional++++not implemented+++++++++++++++++++++++
		
	}
#line 1497 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "parser.ypp" /* yacc.c:1646  */
    {		//+++++++++++++++++++++++++++++rule contains optional++++not implemented+++++++++++++++++++++++
		
	}
#line 1505 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 146 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new FuncApiSymbol();
		FuncApiSymbol* func_def_api0 = dynamic_cast<FuncApiSymbol*>((yyval));	
		TypeSymbol *type1 = dynamic_cast<TypeSymbol*>((yyvsp[-3]));	
        Terminal *id1 = dynamic_cast<Terminal*>((yyvsp[-2]));	
		//2.assignments
		func_def_api0->ret_type = type1->type_value;
		func_def_api0->func_id = id1->terminal_value;
	}
#line 1520 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 156 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new FuncApiSymbol();
		FuncApiSymbol* func_def_api0 = dynamic_cast<FuncApiSymbol*>((yyval));	
		TypeSymbol *type1 = dynamic_cast<TypeSymbol*>((yyvsp[-4]));	
        Terminal *id1 = dynamic_cast<Terminal*>((yyvsp[-3]));	
		FuncArgsSymbol* func_arglist1 = dynamic_cast<FuncArgsSymbol*>((yyvsp[-1]));	
		//2.assignments
		func_def_api0->ret_type = type1->type_value;
		func_def_api0->func_id = id1->terminal_value;
		func_def_api0->func_args = func_arglist1->args;

	}
#line 1538 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 169 "parser.ypp" /* yacc.c:1646  */
    { //+++++++++++++++++++++++++++++rule contains optional++++not implemented+++++++++++++++++++++++
		

	}
#line 1547 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 173 "parser.ypp" /* yacc.c:1646  */
    { //+++++++++++++++++++++++++++++rule contains optional++++not implemented+++++++++++++++++++++++
		

	}
#line 1556 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 179 "parser.ypp" /* yacc.c:1646  */
    { //+++++++++++++++++++++++++++++rule contains optional++++not implemented+++++++++++++++++++++++
		

	}
#line 1565 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 184 "parser.ypp" /* yacc.c:1646  */
    { //+++++++++++++++++++++++++++++rule contains optional++++not implemented+++++++++++++++++++++++
		

	}
#line 1574 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 190 "parser.ypp" /* yacc.c:1646  */
    { //+++++++++++++++++++++++++++++rule contains optional++++not implemented+++++++++++++++++++++++
		
	}
#line 1582 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 193 "parser.ypp" /* yacc.c:1646  */
    { //+++++++++++++++++++++++++++++rule contains optional++++not implemented+++++++++++++++++++++++
		
	}
#line 1590 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 198 "parser.ypp" /* yacc.c:1646  */
    { //-----------------------------------rule below finished---------------------------------------------
		//1.casting
		(yyval)=new FuncArgsSymbol();
        FuncArgsSymbol* func_arglist0 = dynamic_cast<FuncArgsSymbol*>((yyval));	
		FuncArgsSymbol* func_arglist1 = dynamic_cast<FuncArgsSymbol*>((yyvsp[-2]));	
        DclSymbol* dcl1 = dynamic_cast<DclSymbol*>((yyvsp[0]));	
		//2.check parameters - if needed we do assignments
		func_arglist0->args = func_arglist1->args;	//parent symbol gets child symbol argument list
		for(string id : dcl1->dcl_list){
            for(Arg_dcl arg_i : func_arglist0->args){
				if(arg_i.id == id){	//duplicate name for that variable
					string err = string("rule 6: redeclaration of variable '") + id + "'";
					semantic_err(err);
				}
			}
			//variable doesn't exist in func list, so we add it
			Arg_dcl arg = {id, dcl1->id_type};
            func_arglist0->args.push_back(arg);
        }

	}
#line 1616 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 219 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval)=new FuncArgsSymbol();
        FuncArgsSymbol* func_arglist0 = dynamic_cast<FuncArgsSymbol*>((yyval));	
        DclSymbol* dcl1 = dynamic_cast<DclSymbol*>((yyvsp[0]));	
		//2.assignments
		//for every variable in declaration list, we create argument and add it to function argument list
        for(string id : dcl1->dcl_list){
            Arg_dcl arg = {id, dcl1->id_type};
            func_arglist0->args.push_back(arg);
        }
	}
#line 1633 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 233 "parser.ypp" /* yacc.c:1646  */
    {	//mid rule action@@@-------------------------------------------rule below finished---------------------------------------------
		var_table.add_block_table();	//add var table for this block
		//add all the variables to the created block so it knows them
		if(var_table.func_args.size() > 0){
			for(Arg_dcl arg : var_table.func_args){
				var_table.block_tables.front().insert_variable(arg.id, arg.type);
			}
			var_table.func_args.clear();	//empty the list of arguments
		}

	}
#line 1649 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 244 "parser.ypp" /* yacc.c:1646  */
    { 
		(yyval)=new StmtSymbol();
        StmtSymbol *blk0 = dynamic_cast<StmtSymbol*>((yyval));	
        StmtSymbol *stlist1 = dynamic_cast<StmtSymbol*>((yyvsp[-1]));	

        blk0->nextlist = stlist1->nextlist;
        var_table.remove_block_table();		//remove the block table when exiting the block
	}
#line 1662 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 254 "parser.ypp" /* yacc.c:1646  */
    {  	//-------------------------------------------------rule below finished---------------------------------------------
		//1.casting
		(yyval) = new DclSymbol();
		DclSymbol* dcl0 = dynamic_cast<DclSymbol*>((yyval));	
		Terminal* id1 = dynamic_cast<Terminal*>((yyvsp[-2]));	
		TypeSymbol* type1 = dynamic_cast<TypeSymbol*>((yyvsp[0]));	
		//2.var check
		if(type1->type_value == void_t){
            semantic_err("rule 2: can't declare variable of type void");
		}
        //3.assignments
        dcl0->id_type = type1->type_value;
        dcl0->dcl_list.push_front(id1->terminal_value);
	}
#line 1681 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 268 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new DclSymbol();
		DclSymbol* dcl0 = dynamic_cast<DclSymbol*>((yyval));	
		Terminal* id1 = dynamic_cast<Terminal*>((yyvsp[-2]));	
		DclSymbol* dcl1 = dynamic_cast<DclSymbol*>((yyvsp[0]));	
		//2.var check
		//check if variable is already declared in this scope
		auto it = dcl1->dcl_list.begin();
		while(it != dcl1->dcl_list.end()){
			if(*it == id1->terminal_value){
				string err = string("rule 6: redeclaration of variable '") + id1->terminal_value + "'";
				semantic_err(err);
			}
			it++;
		}
		//3.assignments
		dcl0->id_type = dcl1->id_type;
        dcl0->dcl_list = dcl1->dcl_list;
        dcl0->dcl_list.push_front(id1->terminal_value);

	}
#line 1708 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 292 "parser.ypp" /* yacc.c:1646  */
    { 	//---------------------------------------------------------rule below finished---------------------------------------------
		(yyval) = new TypeSymbol();
		TypeSymbol* type0 = dynamic_cast<TypeSymbol*>((yyval));	
		type0->type_value = int_;	
	}
#line 1718 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 297 "parser.ypp" /* yacc.c:1646  */
    { 
		(yyval) = new TypeSymbol();
		TypeSymbol* type0 = dynamic_cast<TypeSymbol*>((yyval));	
		type0->type_value = float_;	
	}
#line 1728 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 302 "parser.ypp" /* yacc.c:1646  */
    { 
		(yyval) = new TypeSymbol();
		TypeSymbol* type0 = dynamic_cast<TypeSymbol*>((yyval));	
		type0->type_value = void_t;	
	}
#line 1738 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 309 "parser.ypp" /* yacc.c:1646  */
    {	//---------------------------------------------rule below finished---------------------------------------------
		//1.casting
		(yyval) = new StmtSymbol();
		StmtSymbol* stlist0 = dynamic_cast<StmtSymbol*>((yyval));
        StmtSymbol* stlist1 = dynamic_cast<StmtSymbol*>((yyvsp[-2]));
        Marker_M_Symbol* M1 = dynamic_cast<Marker_M_Symbol*>((yyvsp[-1]));
        StmtSymbol* stmt1 = dynamic_cast<StmtSymbol*>((yyvsp[0]));
		//2.control flow
		code_buffer.backpatch(stlist1->nextlist, M1->quad);
        stlist0->nextlist.merge(stmt1->nextlist);
	}
#line 1754 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 320 "parser.ypp" /* yacc.c:1646  */
    { 
		(yyval) = new StmtSymbol();
	}
#line 1762 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 325 "parser.ypp" /* yacc.c:1646  */
    { 		//---------------------------------------------rule below finished-------------------------------------------------
		//1.casting
		(yyval) = new StmtSymbol();
		DclSymbol* dcl1 = dynamic_cast<DclSymbol*>((yyvsp[-1]));	
		//2. var check
		for(string id : dcl1->dcl_list){
			//check if variable is already declared in this scope
			if(var_table.find_var_in_block(id)){
				string err = string("rule 6: redeclaration of variable '") + id + "'";
				semantic_err(err);
			}
			var_table.block_tables.front().insert_variable(id, dcl1->id_type);	//add this variable to the inner-most block
		}
		//3. add var to the stack
		string three_add_code = string("ADD2I") + " " + SP + " " + SP + " " + to_string(dcl1->dcl_list.size() * 4);	//update stack
		code_buffer.emit(three_add_code);
	}
#line 1784 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 342 "parser.ypp" /* yacc.c:1646  */
    { 		
		(yyval) = new StmtSymbol();
	}
#line 1792 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 345 "parser.ypp" /* yacc.c:1646  */
    {		
		(yyval) = new StmtSymbol();
	}
#line 1800 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 348 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new StmtSymbol();
		StmtSymbol* stmt0 = dynamic_cast<StmtSymbol*>((yyval));	
		StmtSymbol* cntrl1 = dynamic_cast<StmtSymbol*>((yyvsp[0]));	
		//2.control flow
		stmt0->nextlist = cntrl1->nextlist;
	}
#line 1813 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 356 "parser.ypp" /* yacc.c:1646  */
    { 
		(yyval) = new StmtSymbol();
	}
#line 1821 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 359 "parser.ypp" /* yacc.c:1646  */
    { 
		(yyval) = new StmtSymbol();
	}
#line 1829 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 362 "parser.ypp" /* yacc.c:1646  */
    { 
		(yyval) = new StmtSymbol();
	}
#line 1837 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 365 "parser.ypp" /* yacc.c:1646  */
    {
		//1.casting
		(yyval) = new StmtSymbol();
		StmtSymbol* stmt0 = dynamic_cast<StmtSymbol*>((yyval));	
		StmtSymbol* blk1 = dynamic_cast<StmtSymbol*>((yyvsp[0]));	
		//2.control flow
		stmt0->nextlist = blk1->nextlist;
	}
#line 1850 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 375 "parser.ypp" /* yacc.c:1646  */
    {		//---------------------------------------------rule below finished-----------------------------------------
		//1.casting
		(yyval) = new Node();
		ExpSymbol* exp1 = dynamic_cast<ExpSymbol*>((yyvsp[-1]));	
		//2.check return types
		if(func_table.curr_func_entry->ret_type != exp1->exp_type){
            semantic_err("rule 1: assignment between different types is not allowed");
		} 

		if(exp1->exp_type == void_t){	
            semantic_err("rule 2: can't assign from variable of type void");	
		}
		//3.move return value to defined return register
		string three_add_code;
		if(exp1->exp_type == int_){
            three_add_code = string("COPYI") + " " + RT_I + " " + exp1->place;
			code_buffer.emit(three_add_code);
		}
        else if(exp1->exp_type == float_){
            three_add_code = string("COPYF") + " " + RT_F + " " + exp1->place;
			code_buffer.emit(three_add_code);
		}
		string ret =  "RETRN";
		code_buffer.emit(ret);
	}
#line 1880 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 400 "parser.ypp" /* yacc.c:1646  */
    { 
		(yyval) = new Node();
		if(func_table.curr_func_entry->ret_type != void_t){
            semantic_err("return with no value, in non-void function");
		}
        string ret =  "RETRN";
		code_buffer.emit(ret);
	}
#line 1893 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 410 "parser.ypp" /* yacc.c:1646  */
    { //---------------------------------------------rule below finished-----------------------------------------
		//1.casting
		(yyval) = new Node();
		ExpSymbol* exp1 = dynamic_cast<ExpSymbol*>((yyvsp[-2]));	
		//2.execute assembly
		string three_add_code;
		string letter_type;
        if(exp1->exp_type == int_){
            letter_type = "I";
		}
        else if(exp1->exp_type == float_){
            letter_type = "F";
		}
		else{	//type == void_t)
            semantic_err("rule 2: can't write to variable of type void");
		}
		three_add_code = string("PRNT") + letter_type + " " + exp1->place;
		code_buffer.emit(three_add_code);

	}
#line 1918 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 430 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new Node();
		Terminal* str1 = dynamic_cast<Terminal*>((yyvsp[-2]));	
		//2.execute assembly
		//check special character within string
		string print_ascii;
		string str = str1->terminal_value;
		for(int i = 0; i < str.length(); i++){
			if(str[i] == '\\'){
                i++;
                if(str[i] == 'n'){
                    print_ascii = "PRNTC 10";
					code_buffer.emit(print_ascii);	//ASCII value of \n
				}
				else if(str[i] == 't'){
                    print_ascii = "PRNTC 9";
					code_buffer.emit(print_ascii);	//ASCII value of \t
				}
				else if(str[i] == '"'){
                    print_ascii = "PRNTC 34";
					code_buffer.emit(print_ascii);	//ASCII value of "
				}
                else{	// backslash with no meaning, error
                        operational_err("illegal use of \\");
                }
            }
			else {	//no special character
                string three_add_code = string("PRNTC") + " " + to_string(int(str[i]));		//print ascii value
				code_buffer.emit(three_add_code);
            }
		}
	}
#line 1956 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 465 "parser.ypp" /* yacc.c:1646  */
    { 	//---------------------------------------------rule below finished-----------------------------------------
		//1.casting
		(yyval) = new Node();
		Node* read0 = dynamic_cast<Node*>((yyval));	
		ExpSymbol* lval1 = dynamic_cast<ExpSymbol*>((yyvsp[-2]));	
		//2.execute assembly
		string three_add_code;
		string letter_type = "I";
		if(lval1->exp_type == float_){
			letter_type = "F";
		}
		else if(lval1->exp_type == void_t){		
			semantic_err("rule 2: can't read to variable of type void");
		}
		string temp_reg = var_table.block_tables.front().next_temp_reg(lval1->exp_type);
		three_add_code = string("READ")+letter_type + " " + temp_reg;
		code_buffer.emit(three_add_code);
		three_add_code = string("STOR")+letter_type + " " + temp_reg + " " + lval1->place + " " + "0";	
		code_buffer.emit(three_add_code);
		

	}
#line 1983 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 489 "parser.ypp" /* yacc.c:1646  */
    {	//---------------------------------------------rule below finished-----------------------------------------
		//1.casting
		(yyval) = new StmtSymbol();
		StmtSymbol* assn0 = dynamic_cast<StmtSymbol*>((yyval));	
		ExpSymbol* lval1 = dynamic_cast<ExpSymbol*>((yyvsp[-3]));	
		ExpSymbol* exp1 = dynamic_cast<ExpSymbol*>((yyvsp[-1]));	
		//2.check same types
		if(lval1->exp_type != exp1->exp_type){	
			semantic_err("rule 1: assignment between different types is not allowed");
		}
		//3.execute assembly
		string letter_type = "I";
		if(lval1->exp_type == float_){
			letter_type = "F";
		}
		else if(lval1->exp_type == void_t){		
			semantic_err("rule 2: can't assign to variable of type void");
		}
		string three_add_code = string("STOR")+letter_type + " " + exp1->place + " " + lval1->place + " " + "0";	
		code_buffer.emit(three_add_code);

	}
#line 2010 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 513 "parser.ypp" /* yacc.c:1646  */
    {     		//---------------------------------------------rule below finished-------------------------------------------------
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* lval0 = dynamic_cast<ExpSymbol*>((yyval));	
		Terminal* id1 = dynamic_cast<Terminal*>((yyvsp[0]));	

		//2.checking if variable ID is declared
		Var_Table_Entry var_entry;
		if(!var_table.is_var_exist(var_entry, id1->terminal_value)){
			string err = "variable '" + id1->terminal_value + "' is not declared";
			semantic_err(err);
		}
		//3.execute assembly
		string three_add_code;
		string temp_reg = var_table.block_tables.front().next_temp_reg(int_);
		three_add_code = string("ADD2I") + " " + temp_reg + " " + DP + " " + to_string(var_entry.offset);
		code_buffer.emit(three_add_code);
		//4.assignments
        lval0->place = temp_reg;		//update parent symbol place
		lval0->exp_type = var_entry.type;	//update parent symbol type

		if(var_entry.type == float_){	//if variable type is float
                    string float_reg = var_table.block_tables.front().next_temp_reg(float_);
                    three_add_code = string("CITOF") + " " + float_reg + " " + temp_reg;
					code_buffer.emit(three_add_code);
                    lval0->place = float_reg;
        }
	}
#line 2043 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 543 "parser.ypp" /* yacc.c:1646  */
    {     //--------------------------------------rule below finished--------------------------------
		//1.casting
		(yyval) = new StmtSymbol();
		StmtSymbol* cntrl0 = dynamic_cast<StmtSymbol*>((yyval));	
		BexpSymbol* bexp1 = dynamic_cast<BexpSymbol*>((yyvsp[-7]));	
		Marker_M_Symbol* M1 = dynamic_cast<Marker_M_Symbol*>((yyvsp[-5]));	
		StmtSymbol* stmt1 = dynamic_cast<StmtSymbol*>((yyvsp[-4]));	
		Marker_N_Symbol* N1 = dynamic_cast<Marker_N_Symbol*>((yyvsp[-2]));	
		Marker_M_Symbol* M2 = dynamic_cast<Marker_M_Symbol*>((yyvsp[-1]));	
		StmtSymbol* stmt2 = dynamic_cast<StmtSymbol*>((yyvsp[0]));	
		//2.control flow
		code_buffer.backpatch(bexp1->truelist, M1->quad);
        code_buffer.backpatch(bexp1->falselist, M2->quad);
        cntrl0->nextlist.merge(N1->nextlist);
        cntrl0->nextlist.merge(stmt1->nextlist);
        cntrl0->nextlist.merge(stmt2->nextlist);

	}
#line 2066 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 561 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new StmtSymbol();
		StmtSymbol* cntrl0 = dynamic_cast<StmtSymbol*>((yyval));	
		BexpSymbol* bexp1 = dynamic_cast<BexpSymbol*>((yyvsp[-3]));	
		Marker_M_Symbol* M1 = dynamic_cast<Marker_M_Symbol*>((yyvsp[-1]));	
		StmtSymbol* stmt1 = dynamic_cast<StmtSymbol*>((yyvsp[0]));	
		//2.control flow
		code_buffer.backpatch(bexp1->truelist, M1->quad);
		cntrl0->nextlist.merge(bexp1->falselist);
		cntrl0->nextlist.merge(stmt1->nextlist);

	}
#line 2084 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 574 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new StmtSymbol();
		StmtSymbol* cntrl0 = dynamic_cast<StmtSymbol*>((yyval));	
		Marker_M_Symbol* M1 = dynamic_cast<Marker_M_Symbol*>((yyvsp[-4]));
		BexpSymbol* bexp1 = dynamic_cast<BexpSymbol*>((yyvsp[-3]));	
		Marker_M_Symbol* M2 = dynamic_cast<Marker_M_Symbol*>((yyvsp[-1]));
		StmtSymbol* stmt1 = dynamic_cast<StmtSymbol*>((yyvsp[0]));	
		//2.control flow
		code_buffer.backpatch(bexp1->truelist, M2->quad);
		code_buffer.backpatch(stmt1->nextlist, M1->quad);
		cntrl0->nextlist.merge(bexp1->falselist);
		string three_add_code = string("UJUMP") + " " + to_string(M1->quad);
		code_buffer.emit(three_add_code);
	}
#line 2104 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 591 "parser.ypp" /* yacc.c:1646  */
    {    		//---------------------------------------------rule below finished-----------------------------------------
		//1.casting
		(yyval) = new BexpSymbol();
		BexpSymbol* bexp0 = dynamic_cast<BexpSymbol*>((yyval));	
		BexpSymbol* bexp1 = dynamic_cast<BexpSymbol*>((yyvsp[-3]));	
		Marker_M_Symbol* M = dynamic_cast<Marker_M_Symbol*>((yyvsp[-1])); 
		BexpSymbol* bexp2 = dynamic_cast<BexpSymbol*>((yyvsp[0]));	
		//2.control flow
		code_buffer.backpatch(bexp1->falselist, M->quad);
        bexp0->truelist.merge(bexp1->truelist);
        bexp0->truelist.merge(bexp2->truelist);
        bexp0->falselist.merge(bexp2->falselist);
	}
#line 2122 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 604 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new BexpSymbol();
		BexpSymbol* bexp0 = dynamic_cast<BexpSymbol*>((yyval));	 
		BexpSymbol* bexp1 = dynamic_cast<BexpSymbol*>((yyvsp[-3]));	 
		Marker_M_Symbol* M = dynamic_cast<Marker_M_Symbol*>((yyvsp[-1])); 
		BexpSymbol* bexp2 = dynamic_cast<BexpSymbol*>((yyvsp[0]));	
		//2.control flow
		code_buffer.backpatch(bexp1->truelist, M->quad);
		bexp0->truelist.merge(bexp2->truelist);	
		bexp0->falselist.merge(bexp1->falselist);
		bexp0->falselist.merge(bexp2->falselist);
	}
#line 2140 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 617 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new BexpSymbol();
		BexpSymbol* bexp0 = dynamic_cast<BexpSymbol*>((yyval));
		BexpSymbol* bexp1 = dynamic_cast<BexpSymbol*>((yyvsp[0]));
		//2.control flow
		//swap true and false lists in assignment to parent symbol
		bexp0->truelist.merge(bexp1->falselist);
		bexp0->falselist.merge(bexp1->truelist);
	}
#line 2155 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 627 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new BexpSymbol();
		BexpSymbol* bexp0 = dynamic_cast<BexpSymbol*>((yyval));	 
		ExpSymbol* exp1 = dynamic_cast<ExpSymbol*>((yyvsp[-2]));	
		Terminal* relop2 = dynamic_cast<Terminal*>((yyvsp[-1]));	
		ExpSymbol* exp2 = dynamic_cast<ExpSymbol*>((yyvsp[0]));	

		//2.check different types and if void type
		if(exp1->exp_type != exp2->exp_type){	
			semantic_err("RELOP operation between different types is not allowed");
		}
		if(exp1->exp_type == void_t || exp2->exp_type == void_t){	
			semantic_err("RELOP operation is not allowed on type void");
		}
		//3. execute relop command
		string three_add_code;
		string result_reg = var_table.block_tables.front().next_temp_reg(int_);	//assume it's int, otherwise need casting
		string letter_type = "I";
		if(exp1->exp_type == float_){
			letter_type = "F";
		}
		//if else on all relop operators
		if(relop2->terminal_value == "=="){
			if(exp1->exp_type == float_){
				string float_reg = var_table.block_tables.front().next_temp_reg(float_);
				three_add_code = string("SEQUF") + " " + float_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
				//now casting the result to int
				three_add_code = string("CFTOI") + " " + result_reg + " " + float_reg;
				code_buffer.emit(three_add_code);
			}
			else{	//type int, no casting
				three_add_code = string("SEQUI") + " " + result_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
			}
			bexp0->truelist.push_back(code_buffer.nextquad());
            three_add_code = string("BNEQZ") + " " + result_reg;	//expressions equal --> res=1 
			code_buffer.emit(three_add_code); 
		}
		else if(relop2->terminal_value == "<>"){
			if(exp1->exp_type == float_){
				string float_reg = var_table.block_tables.front().next_temp_reg(float_);
				three_add_code = string("SNEQF") + " " + float_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
				//now casting the result to int
				three_add_code = string("CFTOI") + " " + result_reg + " " + float_reg;
				code_buffer.emit(three_add_code);
			}
			else{	//type int, no casting
				three_add_code = string("SNEQI") + " " + result_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
			}
			bexp0->truelist.push_back(code_buffer.nextquad());
            three_add_code = string("BNEQZ") + " " + result_reg;	
			code_buffer.emit(three_add_code); 
		}
		else if(relop2->terminal_value == "<"){
			if(exp1->exp_type == float_){
				string float_reg = var_table.block_tables.front().next_temp_reg(float_);
				three_add_code = string("SLETF") + " " + float_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
				//now casting the result to int
				three_add_code = string("CFTOI") + " " + result_reg + " " + float_reg;
				code_buffer.emit(three_add_code);
			}
			else{	//type int, no casting
				three_add_code = string("SLETI") + " " + result_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
			}
			bexp0->truelist.push_back(code_buffer.nextquad());
            three_add_code = string("BNEQZ") + " " + result_reg;	
			code_buffer.emit(three_add_code); 
		}
		else if(relop2->terminal_value == "<="){
			if(exp1->exp_type == float_){
				string float_reg = var_table.block_tables.front().next_temp_reg(float_);
				three_add_code = string("SGRTF") + " " + float_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
				//now casting the result to int
				three_add_code = string("CFTOI") + " " + result_reg + " " + float_reg;
				code_buffer.emit(three_add_code);
			}
			else{	//type int, no casting
				three_add_code = string("SGRTI") + " " + result_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
			}
			bexp0->truelist.push_back(code_buffer.nextquad());
            three_add_code = string("BREQZ") + " " + result_reg;	//exp1 <= exp2 --> res=0 
			code_buffer.emit(three_add_code); 
		}
		else if(relop2->terminal_value == ">"){
			if(exp1->exp_type == float_){
				string float_reg = var_table.block_tables.front().next_temp_reg(float_);
				three_add_code = string("SGRTF") + " " + float_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
				//now casting the result to int
				three_add_code = string("CFTOI") + " " + result_reg + " " + float_reg;
				code_buffer.emit(three_add_code);
			}
			else{	//type int, no casting
				three_add_code = string("SGRTI") + " " + result_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
			}
			bexp0->truelist.push_back(code_buffer.nextquad());
            three_add_code = string("BNEQZ") + " " + result_reg;	
			code_buffer.emit(three_add_code); 
		}
		else if(relop2->terminal_value == ">="){
			if(exp1->exp_type == float_){
				string float_reg = var_table.block_tables.front().next_temp_reg(float_);
				three_add_code = string("SLETF") + " " + float_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
				//now casting the result to int
				three_add_code = string("CFTOI") + " " + result_reg + " " + float_reg;
				code_buffer.emit(three_add_code);
			}
			else{	//type int, no casting
				three_add_code = string("SLETI") + " " + result_reg + " " + exp1->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
			}
			bexp0->truelist.push_back(code_buffer.nextquad());
            three_add_code = string("BREQZ") + " " + result_reg;	//exp1 <= exp2 --> res=0 
			code_buffer.emit(three_add_code); 
		}
		else{
			operational_err("the operator is not RELOP");
		}	//end of if else

		bexp0->falselist.push_back(code_buffer.nextquad());	//update parent falselist
		string jump = "UJUMP";		//next command is jump if relop is false
		code_buffer.emit(jump);

	}
#line 2294 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 761 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new BexpSymbol();
		BexpSymbol* bexp0 = dynamic_cast<BexpSymbol*>((yyval));	    
        BexpSymbol* bexp1 = dynamic_cast<BexpSymbol*>((yyvsp[-1]));	
		//2.control flow
		bexp0->truelist = bexp1->truelist;        
        bexp0->falselist = bexp1->falselist; 
	}
#line 2308 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 772 "parser.ypp" /* yacc.c:1646  */
    {    		//---------------------------------------------rule below finished-----------------------------------------
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* exp0 = dynamic_cast<ExpSymbol*>((yyval));	
		ExpSymbol* exp1 = dynamic_cast<ExpSymbol*>((yyvsp[-2]));	
		Terminal* addop2 = dynamic_cast<Terminal*>((yyvsp[-1]));	
		ExpSymbol* exp2 = dynamic_cast<ExpSymbol*>((yyvsp[0]));	
		
		//2.check different types and if void type
		if(exp1->exp_type != exp2->exp_type){	
			semantic_err("ADDOP operation between different types is not allowed");
		}
		if(exp1->exp_type == void_t || exp2->exp_type == void_t){	
			semantic_err("ADDOP operation is not allowed on type void");
		}
		//3. execute addop command
		string three_add_code;
		string result_reg = var_table.block_tables.front().next_temp_reg(exp1->exp_type);
		string letter_type = "I";
		if(exp1->exp_type == float_){
			letter_type = "F";
		}

		if(addop2->terminal_value == "+"){
			three_add_code = string("ADD2") + letter_type + " " + result_reg + " " + exp1->place + " " + exp2->place;
			code_buffer.emit(three_add_code);
		}
		else if(addop2->terminal_value == "-"){
			three_add_code = string("SUBT") + letter_type + " " + result_reg + " " + exp1->place + " " + exp2->place;
			code_buffer.emit(three_add_code);
		}
		else{	//operational error
			operational_err("the operator is not ADDOP");
		}
		//4.assignments
		exp0->place = result_reg;		//update parent symbol place
		exp0->exp_type = exp1->exp_type;	//update parent symbol type

	}
#line 2352 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 811 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* exp0 = dynamic_cast<ExpSymbol*>((yyval));	
		ExpSymbol* exp1 = dynamic_cast<ExpSymbol*>((yyvsp[-2]));	
		Terminal* mulop2 = dynamic_cast<Terminal*>((yyvsp[-1]));	
		ExpSymbol* exp2 = dynamic_cast<ExpSymbol*>((yyvsp[0]));	

		//2.check different types and if void type
		if(exp1->exp_type != exp2->exp_type){	
			semantic_err("MULOP operation between different types is not allowed");
		}
		if(exp1->exp_type == void_t || exp2->exp_type == void_t){	
			semantic_err("MULOP operation is not allowed on type void");
		}
		//3. execute addop command
		string three_add_code;
		string result_reg = var_table.block_tables.front().next_temp_reg(exp1->exp_type);
		string letter_type = "I";
		if(exp1->exp_type == float_){
			letter_type = "F";
		}

		if(mulop2->terminal_value == "*"){
			three_add_code = string("MULT") + letter_type + " " + result_reg + " " + exp1->place + " " + exp2->place;
			code_buffer.emit(three_add_code);
		}
		else if(mulop2->terminal_value == "/"){
			three_add_code = string("DIVD") + letter_type + " " + result_reg + " " + exp1->place + " " + exp2->place;
			code_buffer.emit(three_add_code);
		}
		else{	//operational error
			operational_err("the operator is not MULOP");
		}
		//4.assignments
		exp0->place = result_reg;		//update parent symbol place
		exp0->exp_type = exp1->exp_type;	//update parent symbol type

	}
#line 2396 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 850 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* exp0 = dynamic_cast<ExpSymbol*>((yyval));	
		ExpSymbol* exp1 = dynamic_cast<ExpSymbol*>((yyvsp[-1]));	
		//2.assignments
		exp0->place = exp1->place;		//update parent symbol place
		exp0->exp_type = exp1->exp_type;	//update parent symbol type
	}
#line 2410 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 859 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* exp0 = dynamic_cast<ExpSymbol*>((yyval));	
		TypeSymbol* type1 = dynamic_cast<TypeSymbol*>((yyvsp[-2]));
		ExpSymbol* exp2 = dynamic_cast<ExpSymbol*>((yyvsp[0]));	
		//2.check different types and if void
		string three_add_code;
		if(type1->type_value == exp2->exp_type){	//sam type, no casting needed
			exp0->place = exp2->place;		//update parent symbol place
			exp0->exp_type = exp2->exp_type;	//update parent symbol type
		}
		else{
			if(type1->type_value == void_t || exp2->exp_type == void_t){
				semantic_err("casting from/to type void is not allowed");
			}	//3.assignments depends on type
			else if(type1->type_value == int_){	
				exp0->place = var_table.block_tables.front().next_temp_reg(int_);
				three_add_code = string("CFTOI") + " " + exp0->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
			}
			else{	//type == float_
				exp0->place = var_table.block_tables.front().next_temp_reg(float_);
				three_add_code = string("CITOF") + " " + exp0->place + " " + exp2->place;
				code_buffer.emit(three_add_code);
			}
			exp0->exp_type = type1->type_value;	//parent symbol gets the casting type
		}

	}
#line 2445 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 889 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* exp0 = dynamic_cast<ExpSymbol*>((yyval));	
		Terminal* id1 = dynamic_cast<Terminal*>((yyvsp[0]));	

		//2.checking if variable ID is declared
		Var_Table_Entry var_entry;
		if(!var_table.is_var_exist(var_entry, id1->terminal_value)){
			string err = "variable '" + id1->terminal_value + "' is not declared";
			semantic_err(err);
		}
		//3.execute assembly
		string three_add_code;
		string temp_reg = var_table.block_tables.front().next_temp_reg(var_entry.type);
		if(var_entry.type == float_){
			three_add_code = string("CITOF") + " " + DP_F + " " + DP;
			code_buffer.emit(three_add_code);
			three_add_code = string("LOADF") + " " + temp_reg + " " + DP_F + " " + to_string(var_entry.offset);
			code_buffer.emit(three_add_code);
		}
		else if(var_entry.type == int_){
			three_add_code = string("LOADI") + " " + temp_reg + " " + DP + " " + to_string(var_entry.offset);
			code_buffer.emit(three_add_code);
		}
		else{	//type == void 
			semantic_err("rule 2: can't declare variable of type void");
		}
		//4.assignments
		exp0->place = temp_reg;		//update parent symbol place
		exp0->exp_type = var_entry.type;	//update parent symbol type

	}
#line 2483 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 922 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* exp0 = dynamic_cast<ExpSymbol*>((yyval));	
		ExpSymbol* num1 = dynamic_cast<ExpSymbol*>((yyvsp[0]));	
		//2.assignments
		exp0->place = num1->place;		//update parent symbol place
		exp0->exp_type = num1->exp_type;	//update parent symbol type
	}
#line 2497 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 931 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* exp0 = dynamic_cast<ExpSymbol*>((yyval));	
		ExpSymbol* call1 = dynamic_cast<ExpSymbol*>((yyvsp[0]));
		//2.assignments
		exp0->place = call1->place;		//update parent symbol place
		exp0->exp_type = call1->exp_type;	//update parent symbol type
	}
#line 2511 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 942 "parser.ypp" /* yacc.c:1646  */
    {   		//---------------------------------------------rule below finished---------------------------------------------
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* num0 = dynamic_cast<ExpSymbol*>((yyval));	
		Terminal* int1 = dynamic_cast<Terminal*>((yyvsp[0]));	
		//2.assignments
		num0->place = var_table.block_tables.front().next_temp_reg(int_);	//update parent symbol place
		num0->exp_type = int_;		//update parent symbol type
		//3.execute assembly
		string three_add_code = string("COPYI") + " " + num0->place + " " + int1->terminal_value;
		code_buffer.emit(three_add_code);
	}
#line 2528 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 954 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* num0 = dynamic_cast<ExpSymbol*>((yyval));	
		Terminal* real1 = dynamic_cast<Terminal*>((yyvsp[0]));	
		//2.assignments
		num0->place = var_table.block_tables.front().next_temp_reg(float_);	//update parent symbol place
		num0->exp_type = float_;	//update parent symbol type
		//3.execute assembly
		string three_add_code = string("COPYF") + " " + num0->place + " " + real1->terminal_value;
		code_buffer.emit(three_add_code);
	}
#line 2545 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 968 "parser.ypp" /* yacc.c:1646  */
    {  		//---------------------------------------------rule below finished-------------------------------------
		//1.casting
		(yyval) = new ExpSymbol();
		ExpSymbol* call0 = dynamic_cast<ExpSymbol*>((yyval));
		Terminal* id1 = dynamic_cast<Terminal*>((yyvsp[-3]));	
		CallArgsSymbol* call_args1 = dynamic_cast<CallArgsSymbol*>((yyvsp[-1]));	
		//2.finds the func 'ID' in function table
		Function_Table_Entry* func_entry = func_table.find_func_entry(id1->terminal_value);
		if(func_entry == NULL){
			string err = "function '" + id1->terminal_value + "' is not declared";
			semantic_err(err);
		}
		//3.check if number of args are matching
		if(call_args1->exp_args.size() != func_entry->func_args.size()){
            string err = string("wrong number of arguments passed to function '") + id1->terminal_value +"'";
			semantic_err(err);
		}
		//4.store caller saved registers and RA,DP, and FP caller registers
		string three_add_code;
		var_table.store();	//for each var: Mem[SP++] = var
        three_add_code = string("STORI") + " " + RA + " " + SP + " " + "0";	//Mem[SP] = RA
		code_buffer.emit(three_add_code);
		three_add_code = string("STORI") + " " + DP + " " + SP + " " + "4";	//Mem[SP+1*4] = DP
        code_buffer.emit(three_add_code); 
		three_add_code = string("STORI") + " " + FP + " " + SP + " " + "8";	//Mem[SP+2*4] = FP
        code_buffer.emit(three_add_code); 
		//5.updating frame pointer 
		three_add_code = string("ADD2I") + " " + FP + " " + SP + " " + "8";	
		code_buffer.emit(three_add_code);

		//Cast FP to FP_F 
        three_add_code = string("CITOF") + " " + FP_F + " " + FP;
		code_buffer.emit(three_add_code);

		/*****6. pre-call - store arguments, update dp and sp *****/
		
		//store arguments for callee in stack before call
		int i = 1;	
        auto func_arg_it = func_entry->func_args.begin();
        auto exp_arg_it = call_args1->exp_args.begin();

		for(;func_arg_it != func_entry->func_args.end();i++, func_arg_it++, exp_arg_it++){
            
			if(exp_arg_it->exp_type != func_arg_it->type){
				string err = string("rule 3: wrong type of argument passed to function '") + func_arg_it->id +"'";
				semantic_err(err);
			}
			//store arguments according to their type
            if(func_arg_it->type == int_){
                three_add_code = string("STORI") + " " + exp_arg_it->place + " " + FP + " " + to_string(i * 4);
				code_buffer.emit(three_add_code);
            } else if (func_arg_it->type == float_){
                three_add_code = string("STORF") + " " + exp_arg_it->place + " " + FP_F + " " + to_string(i * 4);
				code_buffer.emit(three_add_code);
            } else {
                string err = string("rule 2: can't pass parameter of type void to function '") + func_arg_it->id +"'";
				semantic_err(err);
            }
		}

		//update DP to point on the first arg
        three_add_code = string("ADD2I") + + " " DP + " " + FP + " " + to_string(4);
		code_buffer.emit(three_add_code);
        //update SP to point above arguments
		three_add_code = string("ADD2I") + " " + SP + " " + FP + " " + to_string((func_entry->func_args.size() + 1) * 4);
        code_buffer.emit(three_add_code);
        
		//jump to definition line of function
        three_add_code = string("JLINK") + " " + func_entry->get_func_def_place(code_buffer.nextquad());
        code_buffer.emit(three_add_code);

		/*****7. post-call - close stack of callee, restore FP,DP,RA and saved registers of caller *****/
        
		three_add_code = string("COPYI") + " " + SP + " " + FP;					//SP = FP
        code_buffer.emit(three_add_code);
		three_add_code = string("LOADI") + " " + FP + " " + FP + " " + "0";		//FP = Mem[FP]	
        code_buffer.emit(three_add_code);
		three_add_code = string("SUBTI") + " " + SP + " " + SP + " " + "8";		//SP-=2*4
        code_buffer.emit(three_add_code); 
		three_add_code = string("LOADI") + " " + DP + " " + SP + " " + "4";		//DP = Mem[SP+1*4]
        code_buffer.emit(three_add_code); 
		three_add_code = string("LOADI") + " " + RA + " " + SP + " " + "0";		//RA = Mem[SP]
        code_buffer.emit(three_add_code); 
        var_table.load();  //for each var: var = Mem[--SP]

		//8.update return type and value of parent symbol

		call0->exp_type = func_entry->ret_type;	//updates parent return type
        if(func_entry->ret_type == int_){
                call0->place = var_table.block_tables.front().next_temp_reg(int_);
                three_add_code = string("COPYI") + " " + call0->place + " " + RT_I;	
				code_buffer.emit(three_add_code);
        } else if(func_entry->ret_type == float_){
                call0->place = var_table.block_tables.front().next_temp_reg(float_);
                three_add_code = string("COPYF") + " " + call0->place + " " + RT_F;
				code_buffer.emit(three_add_code);
        }

	}
#line 2649 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1069 "parser.ypp" /* yacc.c:1646  */
    { 		//---------------------------------------------rule below finished-----------------------------------------
		//1.casting
		(yyval) = new CallArgsSymbol();
		CallArgsSymbol* call_arg0 = dynamic_cast<CallArgsSymbol*>((yyval));	
		CallArgsSymbol* call_arglist1 = dynamic_cast<CallArgsSymbol*>((yyvsp[0]));
		//2.assignments
		call_arg0->exp_args = call_arglist1->exp_args;	//parent symbol gets son symbol expressions
	}
#line 2662 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1077 "parser.ypp" /* yacc.c:1646  */
    { 
		(yyval) = new CallArgsSymbol();
	}
#line 2670 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1082 "parser.ypp" /* yacc.c:1646  */
    { 		//---------------------------------------------rule below finished-----------------------------
		//1.casting
		(yyval) = new CallArgsSymbol();
		CallArgsSymbol* call_arglist0 = dynamic_cast<CallArgsSymbol*>((yyval));	
		CallArgsSymbol* call_arglist1 = dynamic_cast<CallArgsSymbol*>((yyvsp[-2]));	
		ExpSymbol* exp = dynamic_cast<ExpSymbol*>((yyvsp[0]));	
		//2.check if void
		if(exp->exp_type == void_t){
			semantic_err("rule 2: can't declare function parameter of type void");
		}
		//3.assignments
		call_arglist0->exp_args = call_arglist1->exp_args;	//parent symbol gets son symbol expressions
		call_arglist0->exp_args.push_back(*exp);			//adding exp to parent expression vector

	}
#line 2690 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1097 "parser.ypp" /* yacc.c:1646  */
    { 
		//1.casting
		(yyval) = new CallArgsSymbol();
		CallArgsSymbol* call_arglist0 = dynamic_cast<CallArgsSymbol*>((yyval));
		ExpSymbol* exp = dynamic_cast<ExpSymbol*>((yyvsp[0]));	
		//2.check if void
		if(exp->exp_type == void_t){
			semantic_err("rule 2: can't declare func parameter of type void");
		}
		//3.assignments
		call_arglist0->exp_args.push_back(*exp);			//adding exp to parent expression vector
	}
#line 2707 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1111 "parser.ypp" /* yacc.c:1646  */
    {		//---------------------------------------------rule below finished-------------------------------------------------
		Marker_M_Symbol* M = new Marker_M_Symbol();
		M->quad = code_buffer.nextquad();
		(yyval) = M;
	}
#line 2717 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1118 "parser.ypp" /* yacc.c:1646  */
    {		//---------------------------------------------rule below finished-------------------------------------------------
		Marker_N_Symbol* N = new Marker_N_Symbol();
		N->nextlist.push_back(code_buffer.nextquad());
		string jump = "UJUMP";
		code_buffer.emit(jump);
		(yyval) = N;
	}
#line 2729 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2733 "parser.tab.cpp" /* yacc.c:1646  */
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
#line 1127 "parser.ypp" /* yacc.c:1906  */


/* Bison Epilogue */

//print syntax errors - code 2
void yyerror(const char*){
	printf("Syntax error: '%s' in line number %d\n", yytext, yylineno);
	exit(2);
}

//print semantic errors - code 3
void semantic_err(string err){
	const char* message = err.c_str();
	printf("Semantic error: %s in line number %d\n", message, yylineno);
	exit(3);
}

//print operational errors - code 9
void operational_err(string err){
	const char* message = err.c_str();
	printf("Operational error: %s\n", message);
	exit(9);
}
