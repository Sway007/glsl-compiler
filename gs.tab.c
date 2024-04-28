/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     shader = 258,
     subshader = 259,
     pass = 260,
     id = 261,
     render_queue_type = 262,
     blend_factor = 263,
     blend_state = 264,
     depth_state = 265,
     stencil_state = 266,
     raster_state = 267,
     EditorProperties = 268,
     EditorMacros = 269,
     tags = 270,
     ReplacementTag = 271,
     INT_CONSTANT = 272,
     FLOAT_CONSTANT = 273,
     true = 274,
     false = 275,
     UsePass = 276,
     VertexShader = 277,
     FragmentShader = 278,
     void = 279,
     float = 280,
     int = 281,
     mat4 = 282,
     struct = 283,
     highp = 284,
     mediemp = 285,
     lowp = 286,
     const = 287,
     in = 288,
     out = 289,
     inout = 290,
     centroid = 291,
     SMOOTH = 292,
     FLAT = 293,
     PRECISE = 294,
     PRECISION = 295,
     INVARIANT = 296,
     or = 297,
     xor = 298,
     and = 299,
     eq = 300,
     neq = 301,
     ge = 302,
     le = 303,
     left_op = 304,
     right_op = 305,
     INC_OP = 306,
     DEC_OP = 307,
     MUL_ASSIGN = 308,
     DIV_ASSIGN = 309,
     MOD_ASSIGN = 310,
     ADD_ASSIGN = 311,
     SUB_ASSIGN = 312,
     LEFT_ASSIGN = 313,
     RIGHT_ASSIGN = 314,
     AND_ASSIGN = 315,
     XOR_ASSIGN = 316,
     OR_ASSIGN = 317,
     IF = 318,
     ELSE = 319,
     WHILE = 320,
     FOR = 321,
     CONTINUE = 322,
     BREAK = 323,
     RETURN = 324,
     DISCARD = 325,
     TODO = 326,
     string_const = 327
   };
#endif
/* Tokens.  */
#define shader 258
#define subshader 259
#define pass 260
#define id 261
#define render_queue_type 262
#define blend_factor 263
#define blend_state 264
#define depth_state 265
#define stencil_state 266
#define raster_state 267
#define EditorProperties 268
#define EditorMacros 269
#define tags 270
#define ReplacementTag 271
#define INT_CONSTANT 272
#define FLOAT_CONSTANT 273
#define true 274
#define false 275
#define UsePass 276
#define VertexShader 277
#define FragmentShader 278
#define void 279
#define float 280
#define int 281
#define mat4 282
#define struct 283
#define highp 284
#define mediemp 285
#define lowp 286
#define const 287
#define in 288
#define out 289
#define inout 290
#define centroid 291
#define SMOOTH 292
#define FLAT 293
#define PRECISE 294
#define PRECISION 295
#define INVARIANT 296
#define or 297
#define xor 298
#define and 299
#define eq 300
#define neq 301
#define ge 302
#define le 303
#define left_op 304
#define right_op 305
#define INC_OP 306
#define DEC_OP 307
#define MUL_ASSIGN 308
#define DIV_ASSIGN 309
#define MOD_ASSIGN 310
#define ADD_ASSIGN 311
#define SUB_ASSIGN 312
#define LEFT_ASSIGN 313
#define RIGHT_ASSIGN 314
#define AND_ASSIGN 315
#define XOR_ASSIGN 316
#define OR_ASSIGN 317
#define IF 318
#define ELSE 319
#define WHILE 320
#define FOR 321
#define CONTINUE 322
#define BREAK 323
#define RETURN 324
#define DISCARD 325
#define TODO 326
#define string_const 327




/* Copy the first part of user declarations.  */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 251 "gs.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  251
/* YYNRULES -- Number of states.  */
#define YYNSTATES  424

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    92,     2,     2,     2,    84,    89,     2,
      95,    96,    82,    80,    79,    81,    94,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    75,
      90,    76,    91,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    87,    74,    93,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    14,    19,    21,    23,    25,    27,
      29,    31,    33,    35,    37,    39,    40,    43,    49,    51,
      54,    56,    58,    60,    62,    67,    68,    70,    74,    78,
      80,    82,    84,    90,    92,    95,    97,    99,   101,   103,
     106,   108,   110,   112,   114,   119,   124,   130,   132,   135,
     156,   161,   163,   165,   167,   172,   177,   181,   184,   186,
     191,   193,   195,   197,   199,   201,   203,   209,   214,   216,
     219,   223,   228,   230,   234,   236,   239,   242,   246,   248,
     251,   253,   255,   257,   259,   262,   264,   266,   268,   270,
     272,   274,   276,   278,   280,   282,   284,   286,   288,   290,
     292,   294,   296,   298,   300,   302,   306,   310,   312,   318,
     320,   324,   326,   330,   332,   336,   338,   342,   344,   348,
     350,   354,   356,   360,   364,   366,   370,   374,   378,   382,
     384,   388,   392,   394,   398,   402,   404,   408,   412,   416,
     418,   421,   424,   427,   429,   431,   433,   435,   437,   442,
     444,   448,   452,   455,   458,   460,   462,   464,   466,   468,
     472,   474,   478,   480,   484,   486,   488,   490,   492,   494,
     496,   498,   500,   502,   504,   506,   508,   513,   517,   522,
     524,   528,   530,   533,   536,   538,   541,   545,   547,   550,
     552,   556,   559,   561,   564,   568,   570,   573,   575,   577,
     580,   584,   586,   588,   590,   592,   594,   597,   600,   607,
     615,   624,   628,   633,   636,   640,   642,   646,   651,   658,
     664,   667,   671,   676,   682,   684,   688,   690,   694,   696,
     699,   705,   713,   719,   726,   728,   730,   732,   737,   740,
     744,   745,   747,   750,   753,   756,   760,   763,   765,   767,
     769,   771
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      98,     0,    -1,     3,    72,    73,   103,    74,    -1,    13,
      73,    71,    74,    -1,    14,    73,    71,    74,    -1,   125,
      -1,   124,    -1,   117,    -1,   130,    -1,   168,    -1,   118,
      -1,   101,    -1,    99,    -1,   100,    -1,   104,    -1,    -1,
     103,   102,    -1,     4,    72,   194,   105,   196,    -1,   106,
      -1,   105,   106,    -1,   101,    -1,   107,    -1,   112,    -1,
     115,    -1,    15,    73,   108,    74,    -1,    -1,   109,    -1,
     108,    75,   109,    -1,   110,    76,   111,    -1,    16,    -1,
      72,    -1,    17,    -1,     5,    72,   195,   113,   196,    -1,
     114,    -1,   113,   114,    -1,   101,    -1,   123,    -1,   107,
      -1,   127,    -1,    21,    72,    -1,     9,    -1,    10,    -1,
      11,    -1,    12,    -1,   116,    76,     6,    75,    -1,   116,
      73,   119,    74,    -1,   116,     6,    73,   119,    74,    -1,
     120,    -1,   120,   119,    -1,   121,    76,     6,    75,   121,
      76,    19,    75,   121,    76,    20,    75,   121,    76,    17,
      75,   121,    76,    18,    75,    -1,     6,    77,    17,    78,
      -1,     6,    -1,    22,    -1,    23,    -1,   122,    76,     6,
      75,    -1,     7,    76,     6,    75,    -1,   172,     6,    75,
      -1,     7,     6,    -1,     6,    -1,    40,   137,   128,    75,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,   128,
      -1,     6,    -1,    28,     6,    73,   131,    74,    -1,    28,
      73,   131,    74,    -1,   132,    -1,   131,   132,    -1,   136,
     133,    75,    -1,   138,   136,   131,    75,    -1,   134,    -1,
     133,    79,   134,    -1,     6,    -1,     6,   135,    -1,    77,
      78,    -1,    77,   144,    78,    -1,   129,    -1,   128,   135,
      -1,    29,    -1,    30,    -1,    31,    -1,   139,    -1,   138,
     139,    -1,   140,    -1,   137,    -1,   141,    -1,   142,    -1,
      39,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
      36,    -1,    37,    -1,    38,    -1,    41,    -1,    80,    -1,
      81,    -1,    82,    -1,    83,    -1,    84,    -1,   126,    -1,
      17,    -1,   144,   143,    17,    -1,   144,   143,   126,    -1,
     146,    -1,   146,    85,   161,    86,   162,    -1,   147,    -1,
     146,    42,   147,    -1,   148,    -1,   147,    43,   148,    -1,
     149,    -1,   148,    44,   149,    -1,   150,    -1,   149,    87,
     150,    -1,   151,    -1,   150,    88,   151,    -1,   152,    -1,
     151,    89,   152,    -1,   153,    -1,   152,    45,   153,    -1,
     152,    46,   153,    -1,   154,    -1,   153,    90,   154,    -1,
     153,    91,   154,    -1,   153,    48,   154,    -1,   153,    47,
     154,    -1,   155,    -1,   154,    49,   155,    -1,   154,    50,
     155,    -1,   156,    -1,   155,    80,   156,    -1,   155,    81,
     156,    -1,   157,    -1,   156,    82,   157,    -1,   156,    83,
     157,    -1,   156,    84,   157,    -1,   159,    -1,    51,   157,
      -1,    52,   157,    -1,   158,   157,    -1,    80,    -1,    81,
      -1,    92,    -1,    93,    -1,   160,    -1,   159,    77,   161,
      78,    -1,   164,    -1,   159,    94,     6,    -1,   159,    94,
     164,    -1,   159,    51,    -1,   159,    52,    -1,   126,    -1,
      17,    -1,    18,    -1,    19,    -1,    20,    -1,    95,   161,
      96,    -1,   162,    -1,   161,    79,   162,    -1,   145,    -1,
     157,   163,   162,    -1,    76,    -1,    53,    -1,    54,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,   165,    -1,   167,    95,
     166,    96,    -1,   167,    95,    96,    -1,   167,    95,    24,
      96,    -1,   162,    -1,   166,    79,   162,    -1,   136,    -1,
     169,   178,    -1,   170,    96,    -1,   171,    -1,   171,   173,
      -1,   172,     6,    95,    -1,   136,    -1,   138,   136,    -1,
     174,    -1,   173,    79,   174,    -1,   138,   175,    -1,   175,
      -1,   136,     6,    -1,   136,     6,   135,    -1,   177,    -1,
     176,   177,    -1,   178,    -1,   179,    -1,    73,    74,    -1,
     197,   176,   198,    -1,   180,    -1,   186,    -1,   187,    -1,
     188,    -1,   193,    -1,   169,    75,    -1,   182,    75,    -1,
     138,     6,    73,   131,    74,    75,    -1,   138,     6,    73,
     131,    74,     6,    75,    -1,   138,     6,    73,   131,    74,
       6,   135,    75,    -1,   138,     6,    75,    -1,   138,     6,
     181,    75,    -1,    79,     6,    -1,   181,    79,     6,    -1,
     183,    -1,   182,    79,     6,    -1,   182,    79,     6,   135,
      -1,   182,    79,     6,   135,    76,   184,    -1,   182,    79,
       6,    76,   184,    -1,   172,     6,    -1,   172,     6,   135,
      -1,   172,     6,    76,   184,    -1,   172,     6,   135,    76,
     184,    -1,   162,    -1,    73,   185,    74,    -1,   184,    -1,
     185,    79,   184,    -1,    75,    -1,   161,    75,    -1,    63,
      95,   161,    96,   177,    -1,    63,    95,   161,    96,   177,
      64,   177,    -1,    65,    95,   190,    96,   177,    -1,    66,
      95,   189,   191,    96,   177,    -1,   186,    -1,   180,    -1,
     161,    -1,   172,     6,    76,   184,    -1,   192,    75,    -1,
     192,    75,   161,    -1,    -1,   190,    -1,    67,    75,    -1,
      68,    75,    -1,    69,    75,    -1,    69,   161,    75,    -1,
      70,    75,    -1,   197,    -1,   197,    -1,   198,    -1,    73,
      -1,    74,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    85,    89,    94,    95,    96,    97,    98,
      99,   104,   105,   106,   107,   110,   112,   117,   121,   122,
     126,   127,   128,   129,   133,   135,   137,   138,   142,   147,
     152,   153,   157,   161,   162,   166,   167,   168,   170,   174,
     178,   179,   180,   181,   185,   186,   190,   194,   195,   200,
     208,   209,   213,   214,   218,   222,   227,   228,   233,   238,
     243,   244,   245,   246,   250,   251,   256,   257,   261,   262,
     266,   267,   271,   272,   276,   277,   281,   282,   286,   287,
     291,   292,   293,   297,   298,   302,   303,   304,   305,   306,
     310,   311,   312,   313,   314,   318,   319,   323,   327,   328,
     329,   330,   331,   335,   336,   337,   338,   342,   343,   347,
     348,   352,   353,   357,   358,   362,   363,   367,   368,   372,
     373,   377,   378,   379,   383,   384,   385,   386,   387,   391,
     392,   393,   397,   398,   399,   403,   404,   405,   406,   410,
     411,   412,   413,   416,   417,   418,   419,   423,   424,   425,
     426,   427,   428,   429,   433,   434,   435,   436,   437,   438,
     442,   443,   447,   448,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   466,   470,   471,   472,   476,
     477,   480,   484,   488,   492,   493,   497,   501,   502,   506,
     507,   511,   512,   516,   517,   521,   522,   526,   527,   531,
     532,   536,   537,   538,   539,   540,   544,   545,   547,   548,
     549,   551,   552,   559,   560,   564,   565,   566,   567,   568,
     572,   573,   574,   575,   579,   580,   584,   585,   589,   590,
     595,   596,   600,   601,   605,   606,   610,   611,   615,   616,
     619,   621,   625,   626,   627,   628,   629,   633,   637,   641,
     645,   649
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "shader", "subshader", "pass", "id",
  "render_queue_type", "blend_factor", "blend_state", "depth_state",
  "stencil_state", "raster_state", "EditorProperties", "EditorMacros",
  "tags", "ReplacementTag", "INT_CONSTANT", "FLOAT_CONSTANT", "true",
  "false", "UsePass", "VertexShader", "FragmentShader", "void", "float",
  "int", "mat4", "struct", "highp", "mediemp", "lowp", "const", "in",
  "out", "inout", "centroid", "SMOOTH", "FLAT", "PRECISE", "PRECISION",
  "INVARIANT", "or", "xor", "and", "eq", "neq", "ge", "le", "left_op",
  "right_op", "INC_OP", "DEC_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "IF", "ELSE", "WHILE", "FOR", "CONTINUE",
  "BREAK", "RETURN", "DISCARD", "TODO", "string_const", "'{'", "'}'",
  "';'", "'='", "'['", "']'", "','", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'!'", "'~'", "'.'",
  "'('", "')'", "$accept", "gl_shader_program",
  "gl_editor_prop_declaration", "gl_editor_macro_declaration",
  "gl_common_global_declaration", "gl_shader_global_declaration",
  "gl_shader_global_declaration_list", "gl_subshader_program",
  "gl_subshader_global_declaration_list",
  "gl_subshader_global_declaration", "gl_tag_specifier",
  "gl_tag_assignment_list", "gl_tag_assignment", "gl_tag_id",
  "gl_tag_value", "gl_pass_program", "gl_pass_global_declaration_list",
  "gl_pass_global_declaration", "gl_use_pass_declaration",
  "gl_render_state_declarator", "gl_render_state_assignment",
  "gl_render_state_declaration", "gl_render_state_prop_list",
  "gl_render_state_prop_assignment", "gl_render_state_prop",
  "gl_mian_shader_entry", "gl_main_shader_assignment",
  "gl_render_queue_assignment", "gl_variable_declaration",
  "variable_identifier", "precision_specifier",
  "ext_builtin_type_specifier_nonarray", "type_specifier_nonarray",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "array_specifier",
  "type_specifier", "precision_qualifier", "type_qualifier",
  "single_type_qualifier", "storage_qualifier", "interpolation_qualifier",
  "invariant_qualifier", "integer_constant_expression_operator",
  "integer_constant_expression", "conditional_expression",
  "logical_or_expression", "logical_xor_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "unary_operator",
  "postfix_expression", "primary_expression", "expression",
  "assignment_expression", "assignment_operator", "function_call",
  "function_call_generic", "function_call_parameter_list",
  "function_identifier", "function_definition", "function_prototype",
  "function_declarator", "function_header", "fully_specified_type",
  "function_parameter_list", "parameter_declaration",
  "parameter_declarator", "statement_list", "statement",
  "compound_statement", "simple_statement", "declaration",
  "identifier_list", "init_declarator_list", "single_declaration",
  "initializer", "initializer_list", "expression_statement",
  "selection_statement", "iteration_statement", "for_init_statement",
  "condition", "for_rest_statement", "conditionopt", "jump_statement",
  "subshader_scope_brace", "pass_scope_brace", "shader_scope_end_brace",
  "scope_brace", "scope_end_brace", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   123,   125,    59,    61,    91,    93,    44,
      43,    45,    42,    47,    37,    63,    58,   124,    94,    38,
      60,    62,    33,   126,    46,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    97,    98,    99,   100,   101,   101,   101,   101,   101,
     101,   102,   102,   102,   102,   103,   103,   104,   105,   105,
     106,   106,   106,   106,   107,   108,   108,   108,   109,   110,
     111,   111,   112,   113,   113,   114,   114,   114,   114,   115,
     116,   116,   116,   116,   117,   117,   118,   119,   119,   120,
     121,   121,   122,   122,   123,   124,   125,   125,   126,   127,
     128,   128,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   137,   137,   138,   138,   139,   139,   139,   139,   139,
     140,   140,   140,   140,   140,   141,   141,   142,   143,   143,
     143,   143,   143,   144,   144,   144,   144,   145,   145,   146,
     146,   147,   147,   148,   148,   149,   149,   150,   150,   151,
     151,   152,   152,   152,   153,   153,   153,   153,   153,   154,
     154,   154,   155,   155,   155,   156,   156,   156,   156,   157,
     157,   157,   157,   158,   158,   158,   158,   159,   159,   159,
     159,   159,   159,   159,   160,   160,   160,   160,   160,   160,
     161,   161,   162,   162,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   164,   165,   165,   165,   166,
     166,   167,   168,   169,   170,   170,   171,   172,   172,   173,
     173,   174,   174,   175,   175,   176,   176,   177,   177,   178,
     178,   179,   179,   179,   179,   179,   180,   180,   180,   180,
     180,   180,   180,   181,   181,   182,   182,   182,   182,   182,
     183,   183,   183,   183,   184,   184,   185,   185,   186,   186,
     187,   187,   188,   188,   189,   189,   190,   190,   191,   191,
     192,   192,   193,   193,   193,   193,   193,   194,   195,   196,
     197,   198
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     5,     1,     2,
       1,     1,     1,     1,     4,     0,     1,     3,     3,     1,
       1,     1,     5,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     4,     4,     5,     1,     2,    20,
       4,     1,     1,     1,     4,     4,     3,     2,     1,     4,
       1,     1,     1,     1,     1,     1,     5,     4,     1,     2,
       3,     4,     1,     3,     1,     2,     2,     3,     1,     2,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     4,     1,
       3,     1,     2,     2,     1,     2,     3,     1,     2,     1,
       3,     2,     1,     2,     3,     1,     2,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     2,     6,     7,
       8,     3,     4,     2,     3,     1,     3,     4,     6,     5,
       2,     3,     4,     5,     1,     3,     1,     3,     1,     2,
       5,     7,     5,     6,     1,     1,     1,     4,     2,     3,
       0,     1,     2,     2,     2,     3,     2,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    15,     0,     0,    65,     0,
      40,    41,    42,    43,     0,     0,    60,    61,    62,    63,
       0,    80,    81,    82,    90,    91,    92,    93,    94,    95,
      96,    89,    97,     2,    12,    13,    11,    16,    14,     0,
       7,    10,     6,     5,    64,    78,     8,   187,    86,     0,
      83,    85,    87,    88,     9,     0,     0,   184,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,   188,    84,   250,   182,     0,   183,     0,     0,   185,
     189,   192,     0,   250,     0,   247,     0,     0,     0,     0,
       0,    68,     0,     0,     0,    51,     0,    47,     0,     0,
      58,   104,    76,   103,     0,   199,    58,   155,   156,   157,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   143,   144,   145,   146,     0,   154,   181,     0,   162,
     107,   109,   111,   113,   115,   117,   119,   121,   124,   129,
     132,   135,     0,   139,   147,     0,   160,   149,   175,     0,
       0,     0,     0,   195,   197,   198,   201,     0,   215,   202,
     203,   204,   205,   193,   191,     0,    56,   186,     0,     0,
       0,    20,     0,    18,    21,    22,    23,    55,     3,     4,
       0,    67,    69,    74,     0,    72,     0,     0,     0,    45,
      48,     0,    44,    77,    98,    99,   100,   101,   102,     0,
     181,   140,   141,     0,     0,     0,   242,   243,   244,     0,
     246,     0,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   164,     0,   142,   152,   153,     0,     0,
     229,     0,     0,   206,   220,   251,   196,   200,   207,     0,
     194,   190,     0,    25,    39,    19,    17,   249,    66,    75,
      70,     0,     0,    46,     0,     0,   105,   106,     0,   236,
       0,     0,   235,   234,   240,   245,   159,     0,   211,     0,
       0,   110,   135,     0,   112,   114,   116,   118,   120,   122,
     123,   128,   127,   125,   126,   130,   131,   133,   134,   136,
     137,   138,   163,     0,   150,   151,   161,    60,   177,   179,
       0,     0,   221,   216,     0,   248,    29,     0,    26,     0,
      73,    71,    50,     0,     0,     0,     0,   241,     0,     0,
       0,   213,   212,     0,     0,   148,   178,     0,   176,     0,
     224,   222,     0,     0,   217,    52,    53,     0,    35,    37,
       0,    33,     0,    36,    38,    24,     0,     0,     0,   230,
       0,   232,     0,   238,     0,   214,   108,   180,   226,     0,
     223,   219,     0,     0,    34,    32,     0,    27,    31,    30,
      28,     0,     0,   237,   233,   239,     0,   208,   225,     0,
     218,     0,     0,     0,   231,   209,     0,   227,    59,    54,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    34,    35,   171,    37,     6,    38,   172,   173,
     174,   327,   328,   329,   390,   175,   360,   361,   176,    39,
      40,    41,    96,    97,    98,   362,   363,    42,    43,   126,
     364,    44,    45,    46,    90,    91,   184,   185,    70,   200,
      48,    93,    50,    51,    52,    53,   199,   104,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   244,   147,   148,   320,
     149,    54,   150,    56,    57,   151,    79,    80,    81,   152,
     153,   154,   155,   156,   290,   157,   158,   351,   379,   159,
     160,   161,   284,   281,   338,   339,   162,    84,   324,   266,
      75,   267
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -307
static const yytype_int16 yypact[] =
{
      23,   -26,    77,    33,  -307,  -307,   753,    42,  -307,    12,
    -307,  -307,  -307,  -307,    47,    54,  -307,  -307,  -307,  -307,
       9,  -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,    39,
    -307,  -307,  -307,  -307,    -9,  -307,  -307,  -307,  -307,  1117,
    -307,  -307,  -307,  -307,  -307,    60,    59,  1117,   152,    96,
    -307,   166,   108,   110,   114,  1117,   156,   191,   205,     8,
    -307,  -307,  -307,   165,  -307,   453,  -307,   234,  1117,   163,
    -307,  -307,   -51,  -307,  1045,  -307,   168,   171,   173,  1117,
     938,  -307,   242,  1117,   191,   172,   178,   191,   174,   179,
    -307,  -307,  -307,  -307,    70,  -307,     7,  -307,  -307,  -307,
    -307,   663,   663,   160,   164,   167,   183,   186,   176,   189,
    -307,  -307,  -307,  -307,  -307,   663,  -307,   259,  1139,  -307,
     -25,   224,   226,   185,   187,   184,   130,    26,     3,   103,
     124,   291,   663,    -2,  -307,   -14,  -307,  -307,  -307,   181,
     199,   271,   374,  -307,  -307,  -307,  -307,    55,  -307,  -307,
    -307,  -307,  -307,    -9,  -307,  1117,  -307,  -307,   207,   209,
     208,  -307,   804,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
     972,  -307,  -307,    -9,    66,  -307,  1117,   210,   266,  -307,
    -307,   280,  -307,  -307,  -307,  -307,  -307,  -307,  -307,    64,
    -307,  -307,  -307,   663,   611,   532,  -307,  -307,  -307,    68,
    -307,   -42,    46,   663,   663,   663,   663,   663,   663,   663,
     663,   663,   663,   663,   663,   663,   663,   663,   663,   663,
     663,   663,   663,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,   663,  -307,  -307,  -307,   663,   112,
    -307,   663,    15,  -307,   -19,  -307,  -307,  -307,  -307,   281,
    -307,  -307,    96,   272,  -307,  -307,  -307,  -307,  -307,  -307,
    -307,   242,   838,  -307,   212,   217,  -307,  -307,   -41,   232,
     306,   218,  -307,  -307,   611,  -307,  -307,  1117,  -307,   307,
      81,   224,  -307,   -57,   226,   185,   187,   184,   130,    26,
      26,     3,     3,     3,     3,   103,   103,   124,   124,  -307,
    -307,  -307,  -307,   113,   220,  -307,  -307,   221,  -307,  -307,
     -32,   647,   240,   142,  1081,  -307,  -307,   140,  -307,   245,
    -307,  -307,  -307,   191,   453,   246,   453,  -307,   227,   249,
     994,  -307,  -307,   320,   663,  -307,  -307,   663,  -307,   647,
    -307,  -307,   647,   647,   251,  -307,  -307,   192,  -307,  -307,
     892,  -307,   255,  -307,  -307,  -307,   272,    -1,   256,   269,
     647,  -307,   453,   663,    30,  -307,  -307,  -307,  -307,    50,
    -307,  -307,   647,   138,  -307,  -307,   329,  -307,  -307,  -307,
    -307,   317,   453,  -307,  -307,   232,    67,  -307,  -307,   647,
    -307,   262,   263,   265,  -307,  -307,   267,  -307,  -307,  -307,
     191,  -307,   282,   323,   284,   191,   286,   340,   285,   191,
     287,   346,   293,  -307
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -307,  -307,  -307,  -307,    -4,  -307,  -307,  -307,  -307,   197,
    -304,  -307,     4,  -307,  -307,  -307,  -307,    11,  -307,  -307,
    -307,  -307,     0,  -307,  -306,  -307,  -307,  -307,  -307,   -59,
    -307,   -11,  -307,  -307,   -83,   -87,  -307,   102,  -155,    -6,
      17,     5,   -30,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
     162,   161,   169,   170,   177,   159,    10,    13,     6,    -3,
      78,  -307,  -307,  -307,  -113,  -221,  -307,   132,  -307,  -307,
    -307,  -307,    -5,  -307,  -307,     1,  -307,   214,   304,  -307,
    -148,   328,  -307,   211,  -307,  -307,  -307,  -136,  -307,   213,
    -307,  -307,  -307,   100,  -307,  -307,  -307,  -307,  -307,    28,
     -50,   237
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -188
static const yytype_int16 yytable[] =
{
      47,    55,    36,   182,   256,   209,   180,    58,   260,    85,
     103,    49,   211,   -65,   100,    64,   388,   213,    60,    72,
     359,   106,   251,   312,   166,   101,     1,   368,   269,   344,
     316,   319,   107,   108,   109,   110,   396,   251,   251,   317,
      17,    18,    19,    71,   167,    66,     3,   347,    72,   246,
     247,    77,   226,   227,   286,   334,   359,   321,    69,    92,
     214,   250,    78,    72,   348,   251,   111,   112,    69,   127,
     100,   389,    77,   222,   223,   248,   167,     4,    47,    55,
     128,   276,    65,    92,    92,    58,   102,   186,    61,    49,
     278,   279,   249,   182,   187,   121,   122,   190,    72,   322,
     350,   293,   -65,   272,   412,   397,     5,   123,   124,   416,
     125,   318,    67,   420,    59,    68,   224,   225,   314,   287,
      62,   288,    71,   376,   398,   289,   377,    63,   350,   399,
     258,   350,   350,    73,   259,   313,    16,    17,    18,    19,
     277,   270,   405,   285,    69,   271,   127,   251,   193,   350,
     194,   195,   196,   197,   198,    76,   342,   128,    82,    77,
     343,   350,    16,    17,    18,    19,    47,    55,   354,    83,
      78,   279,    86,    58,    92,   220,   221,    49,   350,    87,
      92,    88,   106,   228,   229,   182,   369,    89,   371,   201,
     202,   345,   251,   107,   108,   109,   110,    95,   127,   127,
      16,    17,    18,    19,   340,   280,   230,   231,   232,    49,
     128,    99,   325,   378,   365,   366,   380,   381,   353,    69,
     245,    21,    22,    23,   394,   307,   308,   111,   112,    94,
     299,   300,   305,   306,   393,   301,   302,   303,   304,   105,
     163,   406,   165,   177,   404,   178,   400,   179,   183,   188,
     191,   208,   189,   182,   192,   203,   121,   122,   206,   204,
     395,   207,   205,   407,   210,  -187,    92,   215,   123,   124,
     216,   125,   217,   219,   253,   218,   252,   254,   127,   262,
     264,    92,   263,   274,   273,   280,   275,   323,   326,    49,
     332,   292,   333,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   309,   310,
     311,   251,   335,   341,   336,   -65,   352,   346,    47,    55,
     358,   367,   370,   372,   373,    58,   375,   382,   127,    49,
     127,   386,   391,   392,    92,   402,   403,   408,   409,   128,
     410,   128,   411,   414,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    47,    55,   358,   418,   413,   415,
     419,    58,   417,   421,   422,    49,   127,   243,   423,   265,
     387,   384,   401,   330,   383,   291,   294,   128,   298,   261,
     106,   315,   164,    74,   337,   295,   127,   296,   385,   257,
       0,   107,   108,   109,   110,   297,     0,   128,    16,    17,
      18,    19,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,   282,     0,   283,     0,
       0,     0,     0,     0,     0,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,   114,
     115,   116,   117,   118,   119,     0,     0,    73,   255,   120,
       0,     0,     0,     0,   121,   122,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,   123,   124,     0,   125,
     107,   108,   109,   110,     0,     0,     0,    16,    17,    18,
      19,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   114,   115,
     116,   117,   118,   119,     0,     0,    73,     0,   120,     0,
       0,     0,     0,   121,   122,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,   123,   124,     0,   125,   107,
     108,   109,   110,     0,     0,     0,    16,    17,    18,    19,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,     0,     0,
       0,     0,   121,   122,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,   123,   124,     0,   125,   107,   108,
     109,   110,     0,     0,     0,    16,    17,    18,    19,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,    32,   106,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,   107,   108,   109,   110,     0,   106,
       0,    16,    17,    18,    19,     0,     0,     0,     0,     0,
     107,   108,   109,   110,     0,     0,     0,    16,    17,    18,
      19,   121,   122,     0,     0,     0,     0,     0,   111,   112,
       0,     0,     0,   123,   124,     0,   125,     0,     0,     0,
       0,     0,     0,     0,   111,   112,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
     124,     0,   125,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,   124,     7,   125,     8,
       9,     0,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
       8,     9,     0,    10,    11,    12,    13,     0,     0,   169,
       0,     0,     0,     0,     0,   170,     0,    33,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     8,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    17,    18,    19,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   255,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     9,
       0,    10,    11,    12,    13,     0,     0,   169,     0,     0,
       0,     0,     0,   331,   355,   356,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,   357,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    17,    18,    19,   255,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     8,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,    18,    19,
       8,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,   181,    32,     0,     0,     0,     0,    16,    17,
      18,    19,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,     0,     0,     0,
     168,     8,     9,     0,    10,    11,    12,    13,     0,     0,
     169,     0,     0,     0,     0,     0,   170,     0,   374,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,     8,     9,     0,
      10,    11,    12,    13,     0,     0,   169,     0,     0,     0,
       0,     0,     0,   355,   356,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   357,    32,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18,    19,   212,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,     0,
       0,     0,     0,    16,    17,    18,    19,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32
};

static const yytype_int16 yycheck[] =
{
       6,     6,     6,    90,   152,   118,    89,     6,   163,    59,
      69,     6,   125,     6,     6,     6,    17,    42,     6,    49,
     324,     6,    79,   244,    75,    17,     3,   333,   183,    86,
     251,   252,    17,    18,    19,    20,     6,    79,    79,    24,
      25,    26,    27,    49,    95,     6,    72,    79,    78,    51,
      52,    57,    49,    50,    96,    96,   360,    76,    77,    65,
      85,    75,    57,    93,    96,    79,    51,    52,    77,    75,
       6,    72,    78,    47,    48,    77,    95,     0,    84,    84,
      75,    17,    73,    89,    90,    84,    78,    93,    76,    84,
     203,   204,    94,   180,    94,    80,    81,    97,   128,   254,
     321,   214,    95,   186,   410,    75,    73,    92,    93,   415,
      95,    96,    73,   419,    72,    76,    90,    91,     6,    73,
      73,    75,   128,   344,    74,    79,   347,    73,   349,    79,
      75,   352,   353,    73,    79,   248,    24,    25,    26,    27,
     199,    75,    75,    75,    77,    79,   152,    79,    78,   370,
      80,    81,    82,    83,    84,    96,    75,   152,     6,   165,
      79,   382,    24,    25,    26,    27,   172,   172,   323,    73,
     165,   284,     6,   172,   180,    45,    46,   172,   399,    71,
     186,    71,     6,    80,    81,   272,   334,    73,   336,   111,
     112,    78,    79,    17,    18,    19,    20,     6,   204,   205,
      24,    25,    26,    27,   287,   204,    82,    83,    84,   204,
     205,     6,   262,   349,    74,    75,   352,   353,    76,    77,
     142,    29,    30,    31,   372,   228,   229,    51,    52,    73,
     220,   221,   226,   227,   370,   222,   223,   224,   225,    74,
       6,   396,    79,    75,   392,    74,   382,    74,     6,    77,
      76,    75,    74,   340,    75,    95,    80,    81,    75,    95,
     373,    75,    95,   399,    75,     6,   272,    43,    92,    93,
      44,    95,    87,    89,    75,    88,    95,     6,   284,    72,
      72,   287,    73,    17,    74,   284,     6,     6,    16,   284,
      78,   213,    75,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    79,     6,     6,    96,    95,    76,    96,   324,   324,
     324,    76,    76,    96,    75,   324,     6,    76,   334,   324,
     336,    76,    76,    64,   340,     6,    19,    75,    75,   334,
      75,   336,    75,    20,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   360,   360,   360,    17,    76,    75,
      75,   360,    76,    76,    18,   360,   372,    76,    75,   172,
     366,   360,   383,   271,   357,   213,   215,   372,   219,   165,
       6,   249,    78,    55,   284,   216,   392,   217,   360,   152,
      -1,    17,    18,    19,    20,   218,    -1,   392,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,   205,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      66,    67,    68,    69,    70,    -1,    -1,    73,    74,    75,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      17,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    66,
      67,    68,    69,    70,    -1,    -1,    73,    -1,    75,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,    17,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    17,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    17,    18,    19,    20,    -1,     6,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    80,    81,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,     4,    95,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,    -1,     9,    10,    11,    12,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    74,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     6,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    74,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,     9,    10,    11,    12,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    75,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    74,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     6,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
       6,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    74,    41,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
       5,     6,     7,    -1,     9,    10,    11,    12,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    21,    -1,    74,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,     6,     7,    -1,
       9,    10,    11,    12,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,     6,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    98,    72,     0,    73,   103,     4,     6,     7,
       9,    10,    11,    12,    13,    14,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    41,    74,    99,   100,   101,   102,   104,   116,
     117,   118,   124,   125,   128,   129,   130,   136,   137,   138,
     139,   140,   141,   142,   168,   169,   170,   171,   172,    72,
       6,    76,    73,    73,     6,    73,     6,    73,    76,    77,
     135,   136,   139,    73,   178,   197,    96,   136,   138,   173,
     174,   175,     6,    73,   194,   197,     6,    71,    71,    73,
     131,   132,   136,   138,    73,     6,   119,   120,   121,     6,
       6,    17,    78,   126,   144,    74,     6,    17,    18,    19,
      20,    51,    52,    63,    65,    66,    67,    68,    69,    70,
      75,    80,    81,    92,    93,    95,   126,   136,   138,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   164,   165,   167,
     169,   172,   176,   177,   178,   179,   180,   182,   183,   186,
     187,   188,   193,     6,   175,    79,    75,    95,     5,    15,
      21,   101,   105,   106,   107,   112,   115,    75,    74,    74,
     131,    74,   132,     6,   133,   134,   136,   119,    77,    74,
     119,    76,    75,    78,    80,    81,    82,    83,    84,   143,
     136,   157,   157,    95,    95,    95,    75,    75,    75,   161,
      75,   161,     6,    42,    85,    43,    44,    87,    88,    89,
      45,    46,    47,    48,    90,    91,    49,    50,    80,    81,
      82,    83,    84,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    76,   163,   157,    51,    52,    77,    94,
      75,    79,    95,    75,     6,    74,   177,   198,    75,    79,
     135,   174,    72,    73,    72,   106,   196,   198,    74,   135,
      75,    79,   131,    74,    17,     6,    17,   126,   161,   161,
     172,   190,   180,   186,   189,    75,    96,    73,    75,    79,
     181,   147,   157,   161,   148,   149,   150,   151,   152,   153,
     153,   154,   154,   154,   154,   155,   155,   156,   156,   157,
     157,   157,   162,   161,     6,   164,   162,    24,    96,   162,
     166,    76,   135,     6,   195,   197,    16,   108,   109,   110,
     134,    75,    78,    75,    96,     6,    96,   190,   191,   192,
     131,     6,    75,    79,    86,    78,    96,    79,    96,    73,
     162,   184,    76,    76,   135,    22,    23,    40,   101,   107,
     113,   114,   122,   123,   127,    74,    75,    76,   121,   177,
      76,   177,    96,    75,    74,     6,   162,   162,   184,   185,
     184,   184,    76,   137,   114,   196,    76,   109,    17,    72,
     111,    76,    64,   184,   177,   161,     6,    75,    74,    79,
     184,   128,     6,    19,   177,    75,   135,   184,    75,    75,
      75,    75,   121,    76,    20,    75,   121,    76,    17,    75,
     121,    76,    18,    75
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
/* Line 1267 of yacc.c.  */
#line 2058 "gs.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 651 "./gs.y"


