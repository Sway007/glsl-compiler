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
#define YYLAST   1183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  249
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
       2,     2,     2,    93,     2,     2,     2,    85,    90,     2,
      95,    96,    83,    81,    78,    82,    77,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,    75,
      91,    76,    92,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,    80,    89,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    88,    74,    94,     2,     2,     2,
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
     107,   109,   111,   113,   115,   120,   125,   131,   132,   135,
     156,   158,   160,   165,   170,   177,   181,   184,   186,   191,
     193,   195,   197,   199,   201,   203,   209,   214,   216,   219,
     223,   228,   230,   234,   236,   239,   242,   246,   248,   251,
     253,   255,   257,   259,   262,   264,   266,   268,   270,   272,
     274,   276,   278,   280,   282,   284,   286,   288,   290,   292,
     294,   296,   298,   300,   302,   306,   310,   312,   318,   320,
     324,   326,   330,   332,   336,   338,   342,   344,   348,   350,
     354,   356,   360,   364,   366,   370,   374,   378,   382,   384,
     388,   392,   394,   398,   402,   404,   408,   412,   416,   418,
     421,   424,   427,   429,   431,   433,   435,   437,   442,   444,
     448,   452,   455,   458,   460,   462,   464,   466,   468,   472,
     474,   478,   480,   484,   486,   488,   490,   492,   494,   496,
     498,   500,   502,   504,   506,   508,   513,   517,   522,   524,
     528,   530,   533,   536,   538,   541,   545,   547,   550,   552,
     556,   559,   561,   564,   568,   570,   573,   575,   577,   580,
     584,   586,   588,   590,   592,   594,   597,   600,   607,   615,
     624,   628,   633,   636,   640,   642,   646,   651,   658,   664,
     667,   671,   676,   682,   684,   688,   690,   694,   696,   699,
     705,   713,   719,   726,   728,   730,   732,   737,   740,   744,
     745,   747,   750,   753,   756,   760,   763,   765,   767,   769
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      98,     0,    -1,     3,    72,    73,   103,    74,    -1,    13,
      73,    71,    74,    -1,    14,    73,    71,    74,    -1,   124,
      -1,   123,    -1,   117,    -1,   129,    -1,   167,    -1,   118,
      -1,   101,    -1,    99,    -1,   100,    -1,   104,    -1,    -1,
     103,   102,    -1,     4,    72,   193,   105,   194,    -1,   106,
      -1,   105,   106,    -1,   101,    -1,   107,    -1,   112,    -1,
     115,    -1,    15,    73,   108,    74,    -1,    -1,   109,    -1,
     108,    75,   109,    -1,   110,    76,   111,    -1,    16,    -1,
      72,    -1,    17,    -1,     5,    72,   193,   113,   194,    -1,
     114,    -1,   113,   114,    -1,   101,    -1,   122,    -1,   107,
      -1,   126,    -1,    21,    72,    75,    -1,     9,    -1,    10,
      -1,    11,    -1,    12,    -1,   116,    76,     6,    75,    -1,
     116,    73,   119,    74,    -1,   116,     6,    73,   119,    74,
      -1,    -1,   120,   119,    -1,     6,    76,     6,    75,     6,
      76,    19,    75,     6,    76,    20,    75,     6,    76,    17,
      75,     6,    76,    18,    75,    -1,    22,    -1,    23,    -1,
     121,    76,   125,    75,    -1,     7,    76,   125,    75,    -1,
       7,    76,     7,    77,     6,    75,    -1,   171,     6,    75,
      -1,     7,     6,    -1,     6,    -1,    40,   136,   127,    75,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,   127,
      -1,     6,    -1,    28,     6,    73,   130,    74,    -1,    28,
      73,   130,    74,    -1,   131,    -1,   130,   131,    -1,   135,
     132,    75,    -1,   137,   135,   130,    75,    -1,   133,    -1,
     132,    78,   133,    -1,     6,    -1,     6,   134,    -1,    79,
      80,    -1,    79,   143,    80,    -1,   128,    -1,   127,   134,
      -1,    29,    -1,    30,    -1,    31,    -1,   138,    -1,   137,
     138,    -1,   139,    -1,   136,    -1,   140,    -1,   141,    -1,
      39,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
      36,    -1,    37,    -1,    38,    -1,    41,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,   125,    -1,
      17,    -1,   143,   142,    17,    -1,   143,   142,   125,    -1,
     145,    -1,   145,    86,   160,    87,   161,    -1,   146,    -1,
     145,    42,   146,    -1,   147,    -1,   146,    43,   147,    -1,
     148,    -1,   147,    44,   148,    -1,   149,    -1,   148,    88,
     149,    -1,   150,    -1,   149,    89,   150,    -1,   151,    -1,
     150,    90,   151,    -1,   152,    -1,   151,    45,   152,    -1,
     151,    46,   152,    -1,   153,    -1,   152,    91,   153,    -1,
     152,    92,   153,    -1,   152,    48,   153,    -1,   152,    47,
     153,    -1,   154,    -1,   153,    49,   154,    -1,   153,    50,
     154,    -1,   155,    -1,   154,    81,   155,    -1,   154,    82,
     155,    -1,   156,    -1,   155,    83,   156,    -1,   155,    84,
     156,    -1,   155,    85,   156,    -1,   158,    -1,    51,   156,
      -1,    52,   156,    -1,   157,   156,    -1,    81,    -1,    82,
      -1,    93,    -1,    94,    -1,   159,    -1,   158,    79,   160,
      80,    -1,   163,    -1,   158,    77,     6,    -1,   158,    77,
     163,    -1,   158,    51,    -1,   158,    52,    -1,   125,    -1,
      17,    -1,    18,    -1,    19,    -1,    20,    -1,    95,   160,
      96,    -1,   161,    -1,   160,    78,   161,    -1,   144,    -1,
     156,   162,   161,    -1,    76,    -1,    53,    -1,    54,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,   164,    -1,   166,    95,
     165,    96,    -1,   166,    95,    96,    -1,   166,    95,    24,
      96,    -1,   161,    -1,   165,    78,   161,    -1,   135,    -1,
     168,   177,    -1,   169,    96,    -1,   170,    -1,   170,   172,
      -1,   171,     6,    95,    -1,   135,    -1,   137,   135,    -1,
     173,    -1,   172,    78,   173,    -1,   137,   174,    -1,   174,
      -1,   135,     6,    -1,   135,     6,   134,    -1,   176,    -1,
     175,   176,    -1,   177,    -1,   178,    -1,    73,    74,    -1,
     195,   175,   196,    -1,   179,    -1,   185,    -1,   186,    -1,
     187,    -1,   192,    -1,   168,    75,    -1,   181,    75,    -1,
     137,     6,    73,   130,    74,    75,    -1,   137,     6,    73,
     130,    74,     6,    75,    -1,   137,     6,    73,   130,    74,
       6,   134,    75,    -1,   137,     6,    75,    -1,   137,     6,
     180,    75,    -1,    78,     6,    -1,   180,    78,     6,    -1,
     182,    -1,   181,    78,     6,    -1,   181,    78,     6,   134,
      -1,   181,    78,     6,   134,    76,   183,    -1,   181,    78,
       6,    76,   183,    -1,   171,     6,    -1,   171,     6,   134,
      -1,   171,     6,    76,   183,    -1,   171,     6,   134,    76,
     183,    -1,   161,    -1,    73,   184,    74,    -1,   183,    -1,
     184,    78,   183,    -1,    75,    -1,   160,    75,    -1,    63,
      95,   160,    96,   176,    -1,    63,    95,   160,    96,   176,
      64,   176,    -1,    65,    95,   189,    96,   176,    -1,    66,
      95,   188,   190,    96,   176,    -1,   185,    -1,   179,    -1,
     160,    -1,   171,     6,    76,   183,    -1,   191,    75,    -1,
     191,    75,   160,    -1,    -1,   189,    -1,    67,    75,    -1,
      68,    75,    -1,    69,    75,    -1,    69,   160,    75,    -1,
      70,    75,    -1,   195,    -1,   196,    -1,    73,    -1,    74,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    85,    89,    94,    95,    96,    97,    98,
      99,   104,   105,   106,   107,   110,   112,   117,   121,   122,
     126,   127,   128,   129,   133,   135,   137,   138,   142,   147,
     152,   153,   157,   161,   162,   166,   167,   168,   170,   174,
     178,   179,   180,   181,   185,   186,   190,   193,   195,   200,
     208,   209,   213,   217,   218,   223,   224,   229,   234,   239,
     240,   241,   242,   246,   247,   252,   253,   257,   258,   262,
     263,   267,   268,   272,   273,   277,   278,   282,   283,   287,
     288,   289,   293,   294,   298,   299,   300,   301,   302,   306,
     307,   308,   309,   310,   314,   315,   319,   323,   324,   325,
     326,   327,   331,   332,   333,   334,   338,   339,   343,   344,
     348,   349,   353,   354,   358,   359,   363,   364,   368,   369,
     373,   374,   375,   379,   380,   381,   382,   383,   387,   388,
     389,   393,   394,   395,   399,   400,   401,   402,   406,   407,
     408,   409,   412,   413,   414,   415,   419,   420,   421,   422,
     423,   424,   425,   429,   430,   431,   432,   433,   434,   438,
     439,   443,   444,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   462,   466,   467,   468,   472,   473,
     476,   480,   484,   488,   489,   493,   497,   498,   502,   503,
     507,   508,   512,   513,   517,   518,   522,   523,   527,   528,
     532,   533,   534,   535,   536,   540,   541,   543,   544,   545,
     547,   548,   555,   556,   560,   561,   562,   563,   564,   568,
     569,   570,   571,   575,   576,   580,   581,   585,   586,   591,
     592,   596,   597,   601,   602,   606,   607,   611,   612,   615,
     617,   621,   622,   623,   624,   625,   629,   633,   637,   641
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
  "';'", "'='", "'.'", "','", "'['", "']'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'!'", "'~'",
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
  "gl_render_state_prop", "gl_mian_shader_entry",
  "gl_main_shader_assignment", "gl_render_queue_assignment",
  "gl_variable_declaration", "variable_identifier", "precision_specifier",
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
  "shader_scope_brace", "shader_scope_end_brace", "scope_brace",
  "scope_end_brace", 0
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
     325,   326,   327,   123,   125,    59,    61,    46,    44,    91,
      93,    43,    45,    42,    47,    37,    63,    58,   124,    94,
      38,    60,    62,    33,   126,    40,    41
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
     121,   121,   122,   123,   123,   124,   124,   125,   126,   127,
     127,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     136,   136,   137,   137,   138,   138,   138,   138,   138,   139,
     139,   139,   139,   139,   140,   140,   141,   142,   142,   142,
     142,   142,   143,   143,   143,   143,   144,   144,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   150,   150,
     151,   151,   151,   152,   152,   152,   152,   152,   153,   153,
     153,   154,   154,   154,   155,   155,   155,   155,   156,   156,
     156,   156,   157,   157,   157,   157,   158,   158,   158,   158,
     158,   158,   158,   159,   159,   159,   159,   159,   159,   160,
     160,   161,   161,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   163,   164,   164,   164,   165,   165,
     166,   167,   168,   169,   169,   170,   171,   171,   172,   172,
     173,   173,   174,   174,   175,   175,   176,   176,   177,   177,
     178,   178,   178,   178,   178,   179,   179,   179,   179,   179,
     179,   179,   180,   180,   181,   181,   181,   181,   181,   182,
     182,   182,   182,   183,   183,   184,   184,   185,   185,   186,
     186,   187,   187,   188,   188,   189,   189,   190,   190,   191,
     191,   192,   192,   192,   192,   192,   193,   194,   195,   196
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     5,     1,     2,
       1,     1,     1,     1,     4,     0,     1,     3,     3,     1,
       1,     1,     5,     1,     2,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     4,     4,     5,     0,     2,    20,
       1,     1,     4,     4,     6,     3,     2,     1,     4,     1,
       1,     1,     1,     1,     1,     5,     4,     1,     2,     3,
       4,     1,     3,     1,     2,     2,     3,     1,     2,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     4,     1,     3,
       1,     2,     2,     1,     2,     3,     1,     2,     1,     3,
       2,     1,     2,     3,     1,     2,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     2,     2,     6,     7,     8,
       3,     4,     2,     3,     1,     3,     4,     6,     5,     2,
       3,     4,     5,     1,     3,     1,     3,     1,     2,     5,
       7,     5,     6,     1,     1,     1,     4,     2,     3,     0,
       1,     2,     2,     2,     3,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    15,     0,     0,    64,     0,
      40,    41,    42,    43,     0,     0,    59,    60,    61,    62,
       0,    79,    80,    81,    89,    90,    91,    92,    93,    94,
      95,    88,    96,     2,    12,    13,    11,    16,    14,     0,
       7,    10,     6,     5,    63,    77,     8,   186,    85,     0,
      82,    84,    86,    87,     9,     0,     0,   183,     0,     0,
      56,     0,     0,     0,     0,     0,     0,    47,     0,     0,
      78,   187,    83,   248,   181,     0,   182,     0,     0,   184,
     188,   191,     0,   248,     0,   246,    57,     0,     0,     0,
       0,     0,     0,    67,     0,     0,    47,     0,     0,    47,
       0,   103,    75,   102,     0,   198,    57,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   142,   143,   144,   145,     0,   153,   180,     0,   161,
     106,   108,   110,   112,   114,   116,   118,   120,   123,   128,
     131,   134,     0,   138,   146,     0,   159,   148,   174,     0,
       0,     0,     0,   194,   196,   197,   200,     0,   214,   201,
     202,   203,   204,   192,   190,     0,    55,   185,     0,     0,
       0,    20,     0,    18,    21,    22,    23,     0,    53,     3,
       4,     0,    66,    68,    73,     0,    71,     0,     0,     0,
      45,    48,    44,    76,    97,    98,    99,   100,   101,     0,
     180,   139,   140,     0,     0,     0,   241,   242,   243,     0,
     245,     0,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   163,     0,   141,   151,   152,     0,     0,
     228,     0,     0,   205,   219,   249,   195,   199,   206,     0,
     193,   189,     0,    25,     0,    19,    17,   247,     0,    65,
      74,    69,     0,     0,    46,     0,   104,   105,     0,   235,
       0,     0,   234,   233,   239,   244,   158,     0,   210,     0,
       0,   109,   134,     0,   111,   113,   115,   117,   119,   121,
     122,   127,   126,   124,   125,   129,   130,   132,   133,   135,
     136,   137,   162,   149,   150,     0,   160,    59,   176,   178,
       0,     0,   220,   215,     0,    29,     0,    26,     0,    39,
      54,    72,    70,     0,     0,     0,     0,   240,     0,     0,
       0,   212,   211,     0,     0,   147,   177,     0,   175,     0,
     223,   221,     0,     0,   216,    50,    51,     0,    35,    37,
       0,    33,     0,    36,    38,    24,     0,     0,     0,   229,
       0,   231,     0,   237,     0,   213,   107,   179,   225,     0,
     222,   218,     0,     0,    34,    32,     0,    27,    31,    30,
      28,     0,     0,   236,   232,   238,     0,   207,   224,     0,
     217,     0,     0,     0,   230,   208,     0,   226,    58,    52,
       0,   209,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    34,    35,   171,    37,     6,    38,   172,   173,
     174,   326,   327,   328,   390,   175,   360,   361,   176,    39,
      40,    41,    98,    99,   362,   363,    42,    43,   126,   364,
      44,    45,    46,    92,    93,   185,   186,    70,   200,    48,
      95,    50,    51,    52,    53,   199,   104,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   244,   147,   148,   320,   149,
      54,   150,    56,    57,   151,    79,    80,    81,   152,   153,
     154,   155,   156,   290,   157,   158,   351,   379,   159,   160,
     161,   284,   281,   338,   339,   162,    84,   266,    75,   267
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -318
static const yytype_int16 yypact[] =
{
      34,   -31,    54,   -13,  -318,  -318,   776,   -10,  -318,    17,
    -318,  -318,  -318,  -318,    24,    28,  -318,  -318,  -318,  -318,
      25,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,    11,
    -318,  -318,  -318,  -318,    -9,  -318,  -318,  -318,  -318,  1120,
    -318,  -318,  -318,  -318,  -318,    35,   -15,  1120,   107,    47,
    -318,   173,    82,    84,    85,  1120,    90,   118,   137,    10,
    -318,  -318,  -318,    91,  -318,   473,  -318,   164,  1120,    96,
    -318,  -318,   -53,  -318,  1048,  -318,  -318,   105,   114,   113,
     117,  1120,   941,  -318,   191,  1120,   118,   129,   134,   118,
     136,  -318,  -318,  -318,   135,  -318,     8,  -318,  -318,  -318,
    -318,   747,   747,   128,   145,   148,   169,   170,   653,   171,
    -318,  -318,  -318,  -318,  -318,   747,  -318,   206,  1142,  -318,
     -18,   204,   205,   162,   163,   161,   140,    19,    27,   112,
      77,   255,   747,    53,  -318,    31,  -318,  -318,  -318,   158,
     179,   250,   401,  -318,  -318,  -318,  -318,    37,  -318,  -318,
    -318,  -318,  -318,    -9,  -318,  1120,  -318,  -318,   185,   186,
     188,  -318,   842,  -318,  -318,  -318,  -318,   252,  -318,  -318,
    -318,   975,  -318,  -318,    -9,    50,  -318,  1120,   189,   256,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,    33,
    -318,  -318,  -318,   747,   617,   545,  -318,  -318,  -318,    70,
    -318,   -38,    41,   747,   747,   747,   747,   747,   747,   747,
     747,   747,   747,   747,   747,   747,   747,   747,   747,   747,
     747,   747,   747,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,  -318,  -318,   747,  -318,  -318,  -318,    22,   747,
    -318,   747,   321,  -318,   -24,  -318,  -318,  -318,  -318,   258,
    -318,  -318,    47,   249,   193,  -318,  -318,  -318,   194,  -318,
    -318,  -318,   191,   200,  -318,   195,  -318,  -318,   -33,   196,
     260,   175,  -318,  -318,   617,  -318,  -318,  1120,  -318,   266,
      74,   204,  -318,   -14,   205,   162,   163,   161,   140,    19,
      19,    27,    27,    27,    27,   112,   112,    77,    77,  -318,
    -318,  -318,  -318,   178,  -318,    51,  -318,   180,  -318,  -318,
      21,   668,   201,    71,  1084,  -318,   121,  -318,   203,  -318,
    -318,  -318,  -318,   276,   473,   208,   473,  -318,   190,   230,
     997,  -318,  -318,   300,   747,  -318,  -318,   747,  -318,   668,
    -318,  -318,   668,   668,   231,  -318,  -318,   147,  -318,  -318,
     895,  -318,   246,  -318,  -318,  -318,   249,     3,   248,   261,
     668,  -318,   473,   747,    13,  -318,  -318,  -318,  -318,   -45,
    -318,  -318,   668,   109,  -318,  -318,   320,  -318,  -318,  -318,
    -318,   313,   473,  -318,  -318,   196,   -41,  -318,  -318,   668,
    -318,   262,   267,   268,  -318,  -318,   269,  -318,  -318,  -318,
     330,  -318,   273,   331,   275,   346,   277,   341,   285,   355,
     286,   345,   289,  -318
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -318,  -318,  -318,  -318,    -3,  -318,  -318,  -318,  -318,   197,
    -303,  -318,     1,  -318,  -318,  -318,  -318,     5,  -318,  -318,
    -318,  -318,    58,  -318,  -318,  -318,  -318,  -318,   -57,  -318,
      -8,  -318,  -318,   -80,   -85,  -318,    98,  -154,    -6,    20,
      -1,   -34,  -318,  -318,  -318,  -318,  -318,  -318,  -318,   155,
     159,   160,   165,   166,   168,   -19,   -84,   -17,    -7,    72,
    -318,  -318,  -318,  -112,  -226,  -318,   130,  -318,  -318,  -318,
    -318,    -5,  -318,  -318,    -4,  -318,   214,   302,  -318,  -144,
     326,  -318,   183,  -318,  -318,  -318,  -317,  -318,   184,  -318,
    -318,  -318,    99,  -318,  -318,  -318,   123,    30,   -49,   240
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -187
static const yytype_int16 yytable[] =
{
      47,    55,    58,    36,    88,    49,   209,   183,   256,   260,
      85,   181,   103,   211,   -64,    72,    86,    66,   312,   396,
     388,   359,   166,    60,   213,   316,   319,   101,   313,   398,
     270,    64,   378,   399,   405,   380,   381,     1,    69,    86,
     251,     3,   167,    71,    72,   251,    16,    17,    18,    19,
     276,    77,   321,   393,     4,    69,    78,   359,   286,    94,
       5,    72,    59,   334,   251,   400,   222,   223,   214,   127,
      69,   167,    77,   344,   128,   389,   226,   227,    47,    55,
      58,    76,   407,    49,    67,    94,    94,    68,   397,   187,
     102,   278,   279,    61,    72,   350,   183,    62,    65,   347,
     322,    63,   293,   -64,   246,   247,   250,   273,    73,   251,
     224,   225,   258,    82,   287,   259,   288,   348,   376,   289,
      83,   377,    71,   350,    97,   271,   350,   350,   272,   251,
     248,   345,   249,    16,    17,    18,    19,   315,   301,   302,
     303,   304,   277,   100,   350,   285,   127,   353,   251,   342,
      69,   128,   343,    89,   188,    90,   350,   191,    91,    77,
     230,   231,   232,    96,    78,   105,    47,    55,    58,   354,
     163,    49,   279,   350,   165,    94,    21,    22,    23,    86,
      87,    94,   177,   201,   202,   220,   221,   179,   183,   178,
     369,   180,   371,   228,   229,   365,   366,   184,   127,   127,
     280,   299,   300,    49,   128,   189,     8,   340,   190,   305,
     306,   192,  -186,    85,   245,   193,   194,   195,   196,   197,
     198,   307,   308,   203,    16,    17,    18,    19,   394,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
     204,    32,   406,   205,   206,   207,   210,   215,   404,   216,
     217,   219,   218,   252,   253,   183,   254,   262,   268,   263,
     264,   395,   275,   274,   323,   325,   335,    94,   329,   330,
     333,   336,   341,   -64,   251,   332,   346,   352,   127,   367,
     280,    94,   368,    49,   370,   292,   372,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   309,   310,   311,   373,   375,   382,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    47,    55,
      58,   358,   386,    49,   391,   392,    86,   106,   127,   402,
     127,   243,   403,   128,    94,   128,   412,   408,   107,   108,
     109,   110,   409,   410,   411,   317,    17,    18,    19,   413,
     415,   414,   416,   417,    47,    55,    58,   358,   418,    49,
     419,   420,   421,   422,   423,   384,   127,   387,   291,   265,
     331,   128,   111,   112,   294,   401,   295,   383,   314,   261,
     164,    74,   296,   337,   297,   324,   127,   298,   282,   283,
     385,   128,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,   122,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,   123,   124,   125,   318,   107,   108,
     109,   110,     0,     0,     0,    16,    17,    18,    19,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,   114,   115,   116,   117,
     118,   119,     0,     0,    73,   255,   120,     0,     0,   106,
       0,     0,   121,   122,     0,     0,     0,     0,     0,     0,
     107,   108,   109,   110,   123,   124,   125,    16,    17,    18,
      19,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   114,   115,
     116,   117,   118,   119,     0,     0,    73,     0,   120,     0,
       0,   106,     0,     0,   121,   122,     0,     0,     0,     0,
       0,     0,   107,   108,   109,   110,   123,   124,   125,    16,
      17,    18,    19,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,     0,   106,     0,     0,   121,   122,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   123,   124,
     125,    16,    17,    18,    19,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,   106,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     107,   108,   109,   110,   106,     0,     0,    16,    17,    18,
      19,     0,     0,     0,     0,   107,   108,   109,   110,     0,
       0,     0,    16,    17,    18,    19,     0,     0,   121,   122,
       0,     0,     0,     0,   111,   112,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,     0,     0,     0,   121,   122,     0,     0,     0,     0,
       0,   349,     0,     0,     0,     0,   123,   124,   125,   121,
     122,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,   107,   108,   109,   110,     0,     0,
       0,    16,    17,    18,    19,     0,     0,     0,     0,     0,
       7,     0,     8,     9,     0,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,   111,   112,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,     0,   168,     8,     9,
      33,    10,    11,    12,    13,     0,     0,   169,     0,     0,
       0,     0,     0,   170,     0,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     9,     0,    10,    11,    12,    13,     0,     0,
     169,     0,     0,     0,     0,     0,   255,   355,   356,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   357,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,    18,    19,   255,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     8,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,    18,    19,     8,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   182,    32,     0,     0,     0,
       0,    16,    17,    18,    19,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,   168,     8,     9,     0,    10,    11,    12,
      13,     0,     0,   169,     0,     0,     0,     0,     0,   170,
       0,   374,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
       8,     9,     0,    10,    11,    12,    13,     0,     0,   169,
       0,     0,     0,     0,     0,     0,   355,   356,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   357,    32,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,   212,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,     0,     0,     0,     0,    16,    17,    18,    19,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32
};

static const yytype_int16 yycheck[] =
{
       6,     6,     6,     6,    61,     6,   118,    92,   152,   163,
      59,    91,    69,   125,     6,    49,     6,     6,   244,     6,
      17,   324,    75,     6,    42,   251,   252,    17,     6,    74,
     184,     6,   349,    78,    75,   352,   353,     3,    79,     6,
      78,    72,    95,    49,    78,    78,    24,    25,    26,    27,
      17,    57,    76,   370,     0,    79,    57,   360,    96,    65,
      73,    95,    72,    96,    78,   382,    47,    48,    86,    75,
      79,    95,    78,    87,    75,    72,    49,    50,    84,    84,
      84,    96,   399,    84,    73,    91,    92,    76,    75,    95,
      80,   203,   204,    76,   128,   321,   181,    73,    73,    78,
     254,    73,   214,    95,    51,    52,    75,   187,    73,    78,
      91,    92,    75,     6,    73,    78,    75,    96,   344,    78,
      73,   347,   128,   349,     6,    75,   352,   353,    78,    78,
      77,    80,    79,    24,    25,    26,    27,   249,   222,   223,
     224,   225,   199,     6,   370,    75,   152,    76,    78,    75,
      79,   152,    78,    71,    96,    71,   382,    99,    73,   165,
      83,    84,    85,    73,   165,    74,   172,   172,   172,   323,
       6,   172,   284,   399,    78,   181,    29,    30,    31,     6,
       7,   187,    77,   111,   112,    45,    46,    74,   273,    75,
     334,    74,   336,    81,    82,    74,    75,     6,   204,   205,
     204,   220,   221,   204,   205,    76,     6,   287,    74,   226,
     227,    75,     6,   262,   142,    80,    81,    82,    83,    84,
      85,   228,   229,    95,    24,    25,    26,    27,   372,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      95,    41,   396,    95,    75,    75,    75,    43,   392,    44,
      88,    90,    89,    95,    75,   340,     6,    72,     6,    73,
      72,   373,     6,    74,     6,    16,     6,   273,    75,    75,
      75,    96,     6,    95,    78,    75,    96,    76,   284,    76,
     284,   287,     6,   284,    76,   213,    96,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    75,     6,    76,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   324,   324,
     324,   324,    76,   324,    76,    64,     6,     6,   334,   386,
     336,    76,    19,   334,   340,   336,     6,    75,    17,    18,
      19,    20,    75,    75,    75,    24,    25,    26,    27,    76,
      75,    20,     6,    76,   360,   360,   360,   360,    17,   360,
      75,     6,    76,    18,    75,   360,   372,   366,   213,   172,
     272,   372,    51,    52,   215,   383,   216,   357,   248,   165,
      78,    55,   217,   284,   218,   262,   392,   219,   205,   205,
     360,   392,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    17,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    65,    66,    67,    68,
      69,    70,    -1,    -1,    73,    74,    75,    -1,    -1,     6,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    93,    94,    95,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    66,
      67,    68,    69,    70,    -1,    -1,    73,    -1,    75,    -1,
      -1,     6,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    93,    94,    95,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,     6,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    93,    94,
      95,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      17,    18,    19,    20,     6,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    93,    94,    95,    81,
      82,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    17,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
       4,    -1,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    -1,    -1,    -1,    -1,     5,     6,     7,
      74,     9,    10,    11,    12,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,    -1,     9,    10,    11,    12,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    74,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    74,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     6,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,     6,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    74,    41,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,     5,     6,     7,    -1,     9,    10,    11,
      12,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    74,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
       6,     7,    -1,     9,    10,    11,    12,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,     6,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    98,    72,     0,    73,   103,     4,     6,     7,
       9,    10,    11,    12,    13,    14,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    41,    74,    99,   100,   101,   102,   104,   116,
     117,   118,   123,   124,   127,   128,   129,   135,   136,   137,
     138,   139,   140,   141,   167,   168,   169,   170,   171,    72,
       6,    76,    73,    73,     6,    73,     6,    73,    76,    79,
     134,   135,   138,    73,   177,   195,    96,   135,   137,   172,
     173,   174,     6,    73,   193,   195,     6,     7,   125,    71,
      71,    73,   130,   131,   135,   137,    73,     6,   119,   120,
       6,    17,    80,   125,   143,    74,     6,    17,    18,    19,
      20,    51,    52,    63,    65,    66,    67,    68,    69,    70,
      75,    81,    82,    93,    94,    95,   125,   135,   137,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   163,   164,   166,
     168,   171,   175,   176,   177,   178,   179,   181,   182,   185,
     186,   187,   192,     6,   174,    78,    75,    95,     5,    15,
      21,   101,   105,   106,   107,   112,   115,    77,    75,    74,
      74,   130,    74,   131,     6,   132,   133,   135,   119,    76,
      74,   119,    75,    80,    81,    82,    83,    84,    85,   142,
     135,   156,   156,    95,    95,    95,    75,    75,    75,   160,
      75,   160,     6,    42,    86,    43,    44,    88,    89,    90,
      45,    46,    47,    48,    91,    92,    49,    50,    81,    82,
      83,    84,    85,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    76,   162,   156,    51,    52,    77,    79,
      75,    78,    95,    75,     6,    74,   176,   196,    75,    78,
     134,   173,    72,    73,    72,   106,   194,   196,     6,    74,
     134,    75,    78,   130,    74,     6,    17,   125,   160,   160,
     171,   189,   179,   185,   188,    75,    96,    73,    75,    78,
     180,   146,   156,   160,   147,   148,   149,   150,   151,   152,
     152,   153,   153,   153,   153,   154,   154,   155,   155,   156,
     156,   156,   161,     6,   163,   160,   161,    24,    96,   161,
     165,    76,   134,     6,   193,    16,   108,   109,   110,    75,
      75,   133,    75,    75,    96,     6,    96,   189,   190,   191,
     130,     6,    75,    78,    87,    80,    96,    78,    96,    73,
     161,   183,    76,    76,   134,    22,    23,    40,   101,   107,
     113,   114,   121,   122,   126,    74,    75,    76,     6,   176,
      76,   176,    96,    75,    74,     6,   161,   161,   183,   184,
     183,   183,    76,   136,   114,   194,    76,   109,    17,    72,
     111,    76,    64,   183,   176,   160,     6,    75,    74,    78,
     183,   127,   125,    19,   176,    75,   134,   183,    75,    75,
      75,    75,     6,    76,    20,    75,     6,    76,    17,    75,
       6,    76,    18,    75
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
#line 2051 "gs.tab.c"
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


#line 643 "./gs.y"


