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
     LightMode = 272,
     INT_CONSTANT = 273,
     FLOAT_CONSTANT = 274,
     true = 275,
     false = 276,
     Vector2 = 277,
     Vector3 = 278,
     Vector4 = 279,
     Color = 280,
     UsePass = 281,
     VertexShader = 282,
     FragmentShader = 283,
     void = 284,
     float = 285,
     int = 286,
     mat4 = 287,
     struct = 288,
     highp = 289,
     mediemp = 290,
     lowp = 291,
     const = 292,
     in = 293,
     out = 294,
     inout = 295,
     centroid = 296,
     SMOOTH = 297,
     FLAT = 298,
     PRECISE = 299,
     PRECISION = 300,
     INVARIANT = 301,
     or = 302,
     xor = 303,
     and = 304,
     eq = 305,
     neq = 306,
     ge = 307,
     le = 308,
     left_op = 309,
     right_op = 310,
     INC_OP = 311,
     DEC_OP = 312,
     MUL_ASSIGN = 313,
     DIV_ASSIGN = 314,
     MOD_ASSIGN = 315,
     ADD_ASSIGN = 316,
     SUB_ASSIGN = 317,
     LEFT_ASSIGN = 318,
     RIGHT_ASSIGN = 319,
     AND_ASSIGN = 320,
     XOR_ASSIGN = 321,
     OR_ASSIGN = 322,
     IF = 323,
     ELSE = 324,
     WHILE = 325,
     FOR = 326,
     CONTINUE = 327,
     BREAK = 328,
     RETURN = 329,
     DISCARD = 330,
     TODO = 331,
     string_const = 332
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
#define LightMode 272
#define INT_CONSTANT 273
#define FLOAT_CONSTANT 274
#define true 275
#define false 276
#define Vector2 277
#define Vector3 278
#define Vector4 279
#define Color 280
#define UsePass 281
#define VertexShader 282
#define FragmentShader 283
#define void 284
#define float 285
#define int 286
#define mat4 287
#define struct 288
#define highp 289
#define mediemp 290
#define lowp 291
#define const 292
#define in 293
#define out 294
#define inout 295
#define centroid 296
#define SMOOTH 297
#define FLAT 298
#define PRECISE 299
#define PRECISION 300
#define INVARIANT 301
#define or 302
#define xor 303
#define and 304
#define eq 305
#define neq 306
#define ge 307
#define le 308
#define left_op 309
#define right_op 310
#define INC_OP 311
#define DEC_OP 312
#define MUL_ASSIGN 313
#define DIV_ASSIGN 314
#define MOD_ASSIGN 315
#define ADD_ASSIGN 316
#define SUB_ASSIGN 317
#define LEFT_ASSIGN 318
#define RIGHT_ASSIGN 319
#define AND_ASSIGN 320
#define XOR_ASSIGN 321
#define OR_ASSIGN 322
#define IF 323
#define ELSE 324
#define WHILE 325
#define FOR 326
#define CONTINUE 327
#define BREAK 328
#define RETURN 329
#define DISCARD 330
#define TODO 331
#define string_const 332




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
#line 261 "gs.tab.c"

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
#define YYLAST   1294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  264
/* YYNRULES -- Number of states.  */
#define YYNSTATES  454

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   332

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,     2,     2,     2,    92,    97,     2,
      84,    85,    90,    88,    80,    89,    83,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    94,    82,
      98,    81,    99,    93,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    86,     2,    87,    96,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,    95,    79,   101,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    14,    19,    21,    23,    25,    27,
      29,    31,    33,    35,    37,    39,    41,    44,    50,    52,
      55,    57,    59,    61,    63,    68,    69,    71,    75,    79,
      81,    83,    85,    87,    89,    91,    97,    99,   102,   104,
     106,   108,   110,   113,   115,   117,   119,   121,   126,   131,
     137,   139,   142,   173,   175,   177,   179,   181,   186,   188,
     190,   194,   198,   203,   205,   207,   209,   214,   219,   223,
     226,   228,   233,   235,   237,   239,   241,   243,   245,   251,
     256,   258,   261,   265,   270,   272,   276,   278,   281,   284,
     288,   290,   293,   295,   297,   299,   301,   304,   306,   308,
     310,   312,   314,   316,   318,   320,   322,   324,   326,   328,
     330,   332,   334,   336,   338,   340,   342,   344,   348,   352,
     354,   360,   362,   366,   368,   372,   374,   378,   380,   384,
     386,   390,   392,   396,   398,   402,   406,   408,   412,   416,
     420,   424,   426,   430,   434,   436,   440,   444,   446,   450,
     454,   458,   460,   463,   466,   469,   471,   473,   475,   477,
     479,   484,   486,   490,   494,   497,   500,   502,   504,   506,
     508,   510,   514,   516,   520,   522,   526,   528,   530,   532,
     534,   536,   538,   540,   542,   544,   546,   548,   550,   555,
     559,   564,   566,   570,   572,   575,   578,   580,   583,   587,
     589,   592,   594,   598,   601,   603,   606,   610,   612,   615,
     617,   619,   622,   626,   629,   633,   635,   637,   639,   641,
     643,   646,   649,   656,   664,   673,   677,   682,   685,   689,
     691,   695,   700,   707,   713,   716,   720,   725,   731,   733,
     737,   739,   743,   745,   748,   754,   762,   768,   775,   777,
     779,   781,   786,   789,   793,   794,   796,   799,   802,   805,
     809,   812,   814,   816,   818
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     103,     0,    -1,     3,    77,    78,   108,    79,    -1,    13,
      78,    76,    79,    -1,    14,    78,    76,    79,    -1,   133,
      -1,   132,    -1,   122,    -1,   138,    -1,   176,    -1,   123,
      -1,   106,    -1,   104,    -1,   105,    -1,   109,    -1,   107,
      -1,   108,   107,    -1,     4,    77,   203,   110,   206,    -1,
     111,    -1,   110,   111,    -1,   106,    -1,   112,    -1,   117,
      -1,   120,    -1,    15,    78,   113,    79,    -1,    -1,   114,
      -1,   113,    80,   114,    -1,   115,    81,   116,    -1,    16,
      -1,    17,    -1,    77,    -1,    18,    -1,    20,    -1,    21,
      -1,     5,    77,   204,   118,   206,    -1,   119,    -1,   118,
     119,    -1,   106,    -1,   131,    -1,   112,    -1,   135,    -1,
      26,    77,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,   121,    81,     6,    82,    -1,   121,    78,   124,    79,
      -1,   121,     6,    78,   124,    79,    -1,   125,    -1,   125,
     124,    -1,   129,    81,     6,    82,   129,    81,    20,    82,
     129,    81,    21,    82,   129,    81,    18,    82,   129,    81,
      19,    82,   129,    81,     6,    83,     6,    82,   129,    81,
     127,    82,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,   126,    84,   128,    85,    -1,    18,    -1,    19,    -1,
     128,    80,    18,    -1,   128,    80,    19,    -1,     6,    86,
      18,    87,    -1,     6,    -1,    27,    -1,    28,    -1,   130,
      81,     6,    82,    -1,     7,    81,     6,    82,    -1,   180,
       6,    82,    -1,     7,     6,    -1,     6,    -1,    45,   145,
     136,    82,    -1,    29,    -1,    30,    -1,    31,    -1,    32,
      -1,   136,    -1,     6,    -1,    33,     6,    78,   139,    79,
      -1,    33,    78,   139,    79,    -1,   140,    -1,   139,   140,
      -1,   144,   141,    82,    -1,   146,   144,   139,    82,    -1,
     142,    -1,   141,    80,   142,    -1,     6,    -1,     6,   143,
      -1,    86,    87,    -1,    86,   152,    87,    -1,   137,    -1,
     136,   143,    -1,    34,    -1,    35,    -1,    36,    -1,   147,
      -1,   146,   147,    -1,   148,    -1,   145,    -1,   149,    -1,
     150,    -1,    44,    -1,    37,    -1,    38,    -1,    39,    -1,
      40,    -1,    41,    -1,    42,    -1,    43,    -1,    46,    -1,
      88,    -1,    89,    -1,    90,    -1,    91,    -1,    92,    -1,
     134,    -1,    18,    -1,   152,   151,    18,    -1,   152,   151,
     134,    -1,   154,    -1,   154,    93,   169,    94,   170,    -1,
     155,    -1,   154,    47,   155,    -1,   156,    -1,   155,    48,
     156,    -1,   157,    -1,   156,    49,   157,    -1,   158,    -1,
     157,    95,   158,    -1,   159,    -1,   158,    96,   159,    -1,
     160,    -1,   159,    97,   160,    -1,   161,    -1,   160,    50,
     161,    -1,   160,    51,   161,    -1,   162,    -1,   161,    98,
     162,    -1,   161,    99,   162,    -1,   161,    53,   162,    -1,
     161,    52,   162,    -1,   163,    -1,   162,    54,   163,    -1,
     162,    55,   163,    -1,   164,    -1,   163,    88,   164,    -1,
     163,    89,   164,    -1,   165,    -1,   164,    90,   165,    -1,
     164,    91,   165,    -1,   164,    92,   165,    -1,   167,    -1,
      56,   165,    -1,    57,   165,    -1,   166,   165,    -1,    88,
      -1,    89,    -1,   100,    -1,   101,    -1,   168,    -1,   167,
      86,   169,    87,    -1,   172,    -1,   167,    83,     6,    -1,
     167,    83,   172,    -1,   167,    56,    -1,   167,    57,    -1,
     134,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      84,   169,    85,    -1,   170,    -1,   169,    80,   170,    -1,
     153,    -1,   165,   171,   170,    -1,    81,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    67,    -1,   173,    -1,
     175,    84,   174,    85,    -1,   175,    84,    85,    -1,   175,
      84,    29,    85,    -1,   170,    -1,   174,    80,   170,    -1,
     144,    -1,   177,   186,    -1,   178,    85,    -1,   179,    -1,
     179,   181,    -1,   180,     6,    84,    -1,   144,    -1,   146,
     144,    -1,   182,    -1,   181,    80,   182,    -1,   146,   183,
      -1,   183,    -1,   144,     6,    -1,   144,     6,   143,    -1,
     185,    -1,   184,   185,    -1,   187,    -1,   188,    -1,    78,
      79,    -1,    78,   184,    79,    -1,    78,    79,    -1,   205,
     184,   206,    -1,   189,    -1,   195,    -1,   196,    -1,   197,
      -1,   202,    -1,   177,    82,    -1,   191,    82,    -1,   146,
       6,    78,   139,    79,    82,    -1,   146,     6,    78,   139,
      79,     6,    82,    -1,   146,     6,    78,   139,    79,     6,
     143,    82,    -1,   146,     6,    82,    -1,   146,     6,   190,
      82,    -1,    80,     6,    -1,   190,    80,     6,    -1,   192,
      -1,   191,    80,     6,    -1,   191,    80,     6,   143,    -1,
     191,    80,     6,   143,    81,   193,    -1,   191,    80,     6,
      81,   193,    -1,   180,     6,    -1,   180,     6,   143,    -1,
     180,     6,    81,   193,    -1,   180,     6,   143,    81,   193,
      -1,   170,    -1,    78,   194,    79,    -1,   193,    -1,   194,
      80,   193,    -1,    82,    -1,   169,    82,    -1,    68,    84,
     169,    85,   185,    -1,    68,    84,   169,    85,   185,    69,
     185,    -1,    70,    84,   199,    85,   185,    -1,    71,    84,
     198,   200,    85,   185,    -1,   195,    -1,   189,    -1,   169,
      -1,   180,     6,    81,   193,    -1,   201,    82,    -1,   201,
      82,   169,    -1,    -1,   199,    -1,    72,    82,    -1,    73,
      82,    -1,    74,    82,    -1,    74,   169,    82,    -1,    75,
      82,    -1,   205,    -1,   205,    -1,    78,    -1,    79,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    91,    95,   100,   101,   102,   103,   104,
     105,   110,   111,   112,   113,   117,   118,   123,   127,   128,
     132,   133,   134,   135,   139,   141,   143,   144,   148,   153,
     154,   159,   160,   161,   162,   166,   170,   171,   175,   176,
     177,   179,   183,   187,   188,   189,   190,   194,   195,   199,
     203,   204,   209,   220,   221,   222,   223,   227,   231,   232,
     233,   234,   238,   239,   243,   244,   248,   252,   257,   258,
     263,   268,   273,   274,   275,   276,   280,   281,   286,   287,
     291,   292,   296,   297,   301,   302,   306,   307,   311,   312,
     316,   317,   321,   322,   323,   327,   328,   332,   333,   334,
     335,   336,   340,   341,   342,   343,   344,   348,   349,   353,
     357,   358,   359,   360,   361,   365,   366,   367,   368,   372,
     373,   377,   378,   382,   383,   387,   388,   392,   393,   397,
     398,   402,   403,   407,   408,   409,   413,   414,   415,   416,
     417,   421,   422,   423,   427,   428,   429,   433,   434,   435,
     436,   440,   441,   442,   443,   446,   447,   448,   449,   453,
     454,   455,   456,   457,   458,   459,   463,   464,   465,   466,
     467,   468,   472,   473,   477,   478,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   496,   500,   501,
     502,   506,   507,   510,   514,   518,   522,   523,   527,   531,
     532,   536,   537,   541,   542,   546,   547,   551,   552,   556,
     557,   561,   562,   565,   566,   570,   571,   572,   573,   574,
     578,   579,   581,   582,   583,   585,   586,   593,   594,   598,
     599,   600,   601,   602,   606,   607,   608,   609,   613,   614,
     618,   619,   623,   624,   629,   630,   634,   635,   639,   640,
     644,   645,   649,   650,   653,   655,   659,   660,   661,   662,
     663,   667,   671,   675,   679
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
  "tags", "ReplacementTag", "LightMode", "INT_CONSTANT", "FLOAT_CONSTANT",
  "true", "false", "Vector2", "Vector3", "Vector4", "Color", "UsePass",
  "VertexShader", "FragmentShader", "void", "float", "int", "mat4",
  "struct", "highp", "mediemp", "lowp", "const", "in", "out", "inout",
  "centroid", "SMOOTH", "FLAT", "PRECISE", "PRECISION", "INVARIANT", "or",
  "xor", "and", "eq", "neq", "ge", "le", "left_op", "right_op", "INC_OP",
  "DEC_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "IF", "ELSE", "WHILE", "FOR", "CONTINUE", "BREAK", "RETURN",
  "DISCARD", "TODO", "string_const", "'{'", "'}'", "','", "'='", "';'",
  "'.'", "'('", "')'", "'['", "']'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'!'", "'~'", "$accept",
  "gl_shader_program", "gl_editor_prop_declaration",
  "gl_editor_macro_declaration", "gl_common_global_declaration",
  "gl_shader_global_declaration", "gl_shader_global_declaration_list",
  "gl_subshader_program", "gl_subshader_global_declaration_list",
  "gl_subshader_global_declaration", "gl_tag_specifier",
  "gl_tag_assignment_list", "gl_tag_assignment", "gl_tag_id",
  "gl_tag_value", "gl_pass_program", "gl_pass_global_declaration_list",
  "gl_pass_global_declaration", "gl_use_pass_declaration",
  "gl_render_state_declarator", "gl_render_state_assignment",
  "gl_render_state_declaration", "gl_render_state_prop_list",
  "gl_render_state_prop_assignment", "gl_engine_type",
  "gl_engine_type_init", "gl_engine_type_init_param_list",
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
  "compound_statement_no_scope", "compound_statement", "simple_statement",
  "declaration", "identifier_list", "init_declarator_list",
  "single_declaration", "initializer", "initializer_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "for_init_statement", "condition", "for_rest_statement", "conditionopt",
  "jump_statement", "subshader_scope_brace", "pass_scope_brace",
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
     325,   326,   327,   328,   329,   330,   331,   332,   123,   125,
      44,    61,    59,    46,    40,    41,    91,    93,    43,    45,
      42,    47,    37,    63,    58,   124,    94,    38,    60,    62,
      33,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   104,   105,   106,   106,   106,   106,   106,
     106,   107,   107,   107,   107,   108,   108,   109,   110,   110,
     111,   111,   111,   111,   112,   113,   113,   113,   114,   115,
     115,   116,   116,   116,   116,   117,   118,   118,   119,   119,
     119,   119,   120,   121,   121,   121,   121,   122,   122,   123,
     124,   124,   125,   126,   126,   126,   126,   127,   128,   128,
     128,   128,   129,   129,   130,   130,   131,   132,   133,   133,
     134,   135,   136,   136,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   145,   146,   146,   147,   147,   147,
     147,   147,   148,   148,   148,   148,   148,   149,   149,   150,
     151,   151,   151,   151,   151,   152,   152,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   160,   161,   161,   161,   161,
     161,   162,   162,   162,   163,   163,   163,   164,   164,   164,
     164,   165,   165,   165,   165,   166,   166,   166,   166,   167,
     167,   167,   167,   167,   167,   167,   168,   168,   168,   168,
     168,   168,   169,   169,   170,   170,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   172,   173,   173,
     173,   174,   174,   175,   176,   177,   178,   178,   179,   180,
     180,   181,   181,   182,   182,   183,   183,   184,   184,   185,
     185,   186,   186,   187,   187,   188,   188,   188,   188,   188,
     189,   189,   189,   189,   189,   189,   189,   190,   190,   191,
     191,   191,   191,   191,   192,   192,   192,   192,   193,   193,
     194,   194,   195,   195,   196,   196,   197,   197,   198,   198,
     199,   199,   200,   200,   201,   201,   202,   202,   202,   202,
     202,   203,   204,   205,   206
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     1,     2,
       1,     1,     1,     1,     4,     0,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     5,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     4,     4,     5,
       1,     2,    30,     1,     1,     1,     1,     4,     1,     1,
       3,     3,     4,     1,     1,     1,     4,     4,     3,     2,
       1,     4,     1,     1,     1,     1,     1,     1,     5,     4,
       1,     2,     3,     4,     1,     3,     1,     2,     2,     3,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       5,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       4,     1,     3,     1,     2,     2,     1,     2,     3,     1,
       2,     1,     3,     2,     1,     2,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     1,     1,     1,     1,     1,
       2,     2,     6,     7,     8,     3,     4,     2,     3,     1,
       3,     4,     6,     5,     2,     3,     4,     5,     1,     3,
       1,     3,     1,     2,     5,     7,     5,     6,     1,     1,
       1,     4,     2,     3,     0,     1,     2,     2,     2,     3,
       2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    77,     0,    43,
      44,    45,    46,     0,     0,    72,    73,    74,    75,     0,
      92,    93,    94,   102,   103,   104,   105,   106,   107,   108,
     101,   109,    12,    13,    11,    15,     0,    14,     0,     7,
      10,     6,     5,    76,    90,     8,   199,    98,     0,    95,
      97,    99,   100,     9,     0,     0,   196,     0,     0,    69,
       0,     0,     0,     0,     0,     2,    16,     0,     0,     0,
       0,    91,   200,    96,     0,   194,   195,     0,     0,   197,
     201,   204,     0,   263,     0,   261,     0,     0,     0,     0,
       0,    80,     0,     0,     0,    63,     0,    50,     0,     0,
      70,   116,    88,   115,     0,    70,   167,   168,   169,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
     211,   242,     0,   155,   156,   157,   158,   166,   193,     0,
     174,   119,   121,   123,   125,   127,   129,   131,   133,   136,
     141,   144,   147,     0,   151,   159,     0,   172,   161,   187,
       0,     0,     0,     0,   207,   209,   210,   215,     0,   229,
     216,   217,   218,   219,     0,   205,   203,     0,    68,   198,
       0,     0,     0,    20,     0,    18,    21,    22,    23,    67,
       3,     4,     0,    79,    81,    86,     0,    84,     0,     0,
       0,    48,    51,     0,    47,    89,   110,   111,   112,   113,
     114,     0,   193,   152,   153,     0,     0,     0,   256,   257,
     258,     0,   260,   213,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   176,     0,   154,   164,
     165,     0,     0,     0,   243,     0,   220,   234,   212,   208,
       0,   221,     0,   206,   202,     0,    25,    42,   264,    19,
      17,    78,    87,     0,    82,     0,    49,     0,     0,   117,
     118,     0,   250,     0,     0,   249,   248,   254,   259,   171,
       0,     0,   225,     0,   122,   147,     0,   124,   126,   128,
     130,   132,   134,   135,   140,   139,   137,   138,   142,   143,
     145,   146,   148,   149,   150,   175,   162,   163,     0,   173,
      72,   189,   191,     0,     0,   235,   230,   214,     0,   262,
      29,    30,     0,    26,     0,    85,    83,    62,     0,     0,
       0,     0,   255,     0,     0,     0,   227,     0,   226,     0,
     160,   190,     0,   188,     0,   238,   236,     0,     0,   231,
      64,    65,     0,    38,    40,     0,    36,     0,    39,    41,
      24,     0,     0,     0,   244,     0,   246,     0,   252,     0,
     228,   120,   192,   240,     0,   237,   233,     0,     0,    37,
      35,     0,    27,    32,    33,    34,    31,    28,     0,     0,
     251,   247,   253,     0,   222,   239,     0,   232,     0,     0,
       0,   245,   223,     0,   241,    71,    66,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,     0,     0,     0,    52,    58,    59,     0,
       0,    57,    60,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    32,    33,    34,    35,    36,    37,   174,   175,
     176,   332,   333,   334,   397,   177,   365,   366,   178,    38,
      39,    40,    96,    97,   443,   444,   449,    98,   367,   368,
      41,    42,   127,   369,    43,    44,    45,    90,    91,   186,
     187,    71,   202,    47,   129,    49,    50,    51,    52,   201,
     104,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   247,
     148,   149,   323,   150,    53,   151,    55,    56,   152,    79,
      80,    81,   153,   154,    75,   155,   156,   157,   293,   158,
     159,   356,   384,   160,   161,   162,   287,   284,   343,   344,
     163,    84,   328,   164,   270
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -327
static const yytype_int16 yypact[] =
{
      43,     5,    74,    11,  -327,  1120,    35,  -327,    38,  -327,
    -327,  -327,  -327,    63,    83,  -327,  -327,  -327,  -327,    23,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,   932,  -327,    33,  -327,
    -327,  -327,  -327,    86,  -327,  -327,  -327,  -327,  1221,  -327,
    -327,  -327,  -327,  -327,   115,    36,  1221,   170,   151,  -327,
     244,   180,   189,   191,  1221,  -327,  -327,   193,   277,   285,
      20,  -327,  -327,  -327,   347,  -327,  -327,   287,  1221,   232,
    -327,  -327,    98,  -327,  1162,  -327,   231,   235,   236,  1221,
    1003,  -327,   310,  1221,   277,   233,   239,   277,   241,   246,
    -327,  -327,  -327,  -327,    62,    14,  -327,  -327,  -327,  -327,
     805,   805,   242,   245,   247,   248,   250,    46,   251,   256,
    -327,  -327,   805,  -327,  -327,  -327,  -327,  -327,   331,  1248,
    -327,   -31,   291,   292,   249,   252,   254,    94,   -28,   102,
     111,    99,   644,   805,   -29,  -327,   124,  -327,  -327,  -327,
     259,   263,   340,   421,  -327,  -327,  -327,  -327,   136,  -327,
    -327,  -327,  -327,  -327,   569,    86,  -327,  1221,  -327,  -327,
     270,   271,   275,  -327,   202,  -327,  -327,  -327,  -327,  -327,
    -327,  -327,  1049,  -327,  -327,    86,   144,  -327,  1221,   276,
     336,  -327,  -327,   350,  -327,  -327,  -327,  -327,  -327,  -327,
    -327,    24,  -327,  -327,  -327,   805,   715,   642,  -327,  -327,
    -327,   145,  -327,  -327,   -40,    51,   805,   805,   805,   805,
     805,   805,   805,   805,   805,   805,   805,   805,   805,   805,
     805,   805,   805,   805,   805,   805,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,   805,  -327,  -327,
    -327,   107,   805,   805,  -327,   756,  -327,   -26,  -327,  -327,
     351,  -327,   495,  -327,  -327,   151,   237,  -327,  -327,  -327,
    -327,  -327,  -327,   310,  -327,   878,  -327,   272,   281,  -327,
    -327,    47,   278,   364,   286,  -327,  -327,   715,  -327,  -327,
    1221,   367,  -327,   167,   291,  -327,   -58,   292,   249,   252,
     254,    94,   -28,   -28,   102,   102,   102,   102,   111,   111,
      99,    99,  -327,  -327,  -327,  -327,   290,  -327,   -46,  -327,
     295,  -327,  -327,    78,   776,   294,    37,  -327,  1203,  -327,
    -327,  -327,   184,  -327,   311,  -327,  -327,  -327,   277,   569,
     314,   569,  -327,   312,   316,  1067,  -327,   390,  -327,   805,
    -327,  -327,   805,  -327,   776,  -327,  -327,   776,   776,   318,
    -327,  -327,   132,  -327,  -327,   985,  -327,   319,  -327,  -327,
    -327,   237,    29,   320,   333,   776,  -327,   569,   805,     8,
    -327,  -327,  -327,  -327,   188,  -327,  -327,   776,   166,  -327,
    -327,   399,  -327,  -327,  -327,  -327,  -327,  -327,   386,   569,
    -327,  -327,   278,   -14,  -327,  -327,   776,  -327,   325,   326,
     327,  -327,  -327,   328,  -327,  -327,  -327,   277,  -327,   330,
     391,   332,   277,   335,   395,   341,   277,   343,   409,   348,
     277,   352,   426,   354,   428,   356,   277,   362,   198,  -327,
    -327,  -327,  -327,   360,   363,   255,  -327,  -327,  -327,    80,
     257,  -327,  -327,  -327
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -327,  -327,  -327,  -327,   -77,   410,  -327,  -327,  -327,   280,
    -309,  -327,    95,  -327,  -327,  -327,  -327,    84,  -327,  -327,
    -327,  -327,    87,  -327,  -327,  -327,  -327,  -326,  -327,  -327,
    -327,  -327,   -59,  -327,    81,  -327,  -327,   -80,   -87,  -327,
     195,  -148,    -5,   108,    -3,   -30,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,   258,   253,   260,   261,   262,   264,    54,
      34,    50,    58,    76,  -327,  -327,  -327,  -112,  -232,  -327,
     221,  -327,  -327,  -327,  -327,    -4,  -327,  -327,    -1,  -327,
     306,   397,   321,  -147,  -327,  -327,  -327,   269,  -327,  -327,
    -327,   -37,  -327,   273,  -327,  -327,  -327,   197,  -327,  -327,
    -327,  -327,  -327,   -50,  -249
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -200
static const yytype_int16 yytable[] =
{
      46,    54,    48,   184,    57,   211,   259,   173,    85,   182,
     214,   103,   373,   327,   403,   315,   216,   263,    73,   364,
     -77,   319,   253,   322,   225,   226,   100,   249,   250,    63,
     100,    46,    54,    48,   253,    57,   349,   272,   101,    67,
     253,   350,   279,    72,    59,   289,     1,   393,    73,   394,
     395,    77,   105,    78,   251,   324,   364,   252,   169,    92,
      70,    93,   217,    73,   106,   107,   108,   109,   412,   128,
     227,   228,    70,    77,     4,    15,    16,    17,    18,    46,
      54,    48,     3,    57,    92,    92,    93,    93,   188,     5,
     404,   419,   355,   281,   282,   184,   423,   173,   -77,    73,
     427,    64,   110,   111,   431,   296,   396,   102,   275,   325,
     437,    68,    58,   316,    69,   259,   390,   381,   358,    60,
     382,    76,   355,    70,    72,   355,   355,   253,   210,   290,
     122,   291,   339,   292,   123,   124,    15,    16,    17,    18,
     318,    61,   280,   355,   223,   224,   125,   126,   128,   195,
     196,   197,   198,   199,   200,   355,   229,   230,   352,   128,
     450,    62,    77,   353,    78,   451,    20,    21,    22,    46,
      54,    48,    70,    57,   355,   282,    82,    92,   359,    93,
     168,   189,   169,    92,   192,    93,   203,   204,   184,   233,
     234,   235,   374,    74,   376,    15,    16,    17,    18,   231,
     232,   128,   128,    48,   253,   283,   254,   170,     7,     8,
     345,     9,    10,    11,    12,   329,   260,   171,   261,   248,
     439,   440,   441,   442,   273,   253,   274,   288,   172,    83,
     401,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,   347,    31,   348,
      86,   363,   411,   330,   331,   413,    87,   128,   184,   304,
     305,   306,   307,   370,   371,    88,   402,   405,   406,    89,
      92,    94,    93,   447,   448,   452,   453,   302,   303,   308,
     309,   268,   128,    95,    48,    92,   283,    93,   363,   310,
     311,    99,   295,   165,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   312,
     313,   314,   167,   179,   180,   181,   185,   383,   191,   190,
     385,   386,   193,    46,    54,    48,   205,    57,   194,   206,
     208,   207,   209,   212,   128,   213,   128,  -199,   400,   218,
      92,   219,    93,   255,   220,   256,   257,   265,   221,   266,
     407,   222,   267,   105,   277,   276,   278,   326,   253,   337,
      46,    54,    48,   338,    57,   106,   107,   108,   109,   414,
     340,   341,   128,   346,   -77,   357,    15,    16,    17,    18,
     351,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   372,    31,   128,   375,   380,   377,   378,   387,
     391,   398,   399,   110,   111,   409,   410,   415,   416,   417,
     418,   420,   421,   425,   422,   112,   424,   113,   114,   115,
     116,   117,   118,   426,   428,   119,   120,   105,   429,   121,
     430,   122,   433,   432,   435,   123,   124,   434,   436,   106,
     107,   108,   109,   438,   445,   446,    66,   125,   126,   389,
      15,    16,    17,    18,   269,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,   392,    31,   335,   408,
     388,   297,   317,   264,   294,   166,   285,   110,   111,   298,
     286,   299,     0,   300,   342,   262,   301,     0,     0,   112,
       0,   113,   114,   115,   116,   117,   118,     0,     0,   119,
     258,   105,     0,   121,     0,   122,     0,     0,     0,   123,
     124,     0,     0,   106,   107,   108,   109,     0,     0,     0,
       0,   125,   126,     0,    15,    16,    17,    18,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,   113,   114,   115,   116,   117,
     118,     0,     0,   119,   268,   105,     0,   121,     0,   122,
       0,     0,     0,   123,   124,     0,     0,   106,   107,   108,
     109,     0,     0,     0,     0,   125,   126,     0,    15,    16,
      17,    18,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,     0,   113,
     114,   115,   116,   117,   118,     0,     0,   119,   105,     0,
       0,   121,     0,   122,     0,     0,     0,   123,   124,     0,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   125,
     126,    15,    16,    17,    18,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
       0,     0,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,   121,   246,   122,     0,     0,     0,
     123,   124,     0,   106,   107,   108,   109,     0,     0,     0,
       0,     0,   125,   126,    15,    16,    17,    18,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,   105,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   111,     0,   106,   107,   108,   109,     0,     0,
       0,     0,   105,     0,     0,   320,    16,    17,    18,     0,
       0,     0,     0,     0,   106,   107,   108,   109,     0,   122,
       0,     0,     0,   123,   124,    15,    16,    17,    18,     0,
       0,   105,   110,   111,     0,   125,   126,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,     0,     0,     0,
       0,     0,   110,   111,    15,    16,    17,    18,     0,     0,
     122,   321,     0,     0,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,   354,     0,   125,   126,     0,     0,
     122,   110,   111,     0,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,   126,     0,     0,
       0,     0,     0,     0,     7,     0,     0,     0,     0,   122,
       0,     0,     0,   123,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,   126,    15,    16,    17,
      18,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,     7,     8,
       0,     9,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     9,    10,    11,    12,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,    65,   360,   361,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
     362,    31,    15,    16,    17,    18,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,    31,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,   268,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,    15,    16,
      17,    18,   183,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,    31,    15,    16,    17,    18,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     7,     8,   271,     9,
      10,    11,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   379,     0,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    31,   170,     7,     8,
       0,     9,    10,    11,    12,     0,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,     0,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,     7,
       8,     0,     9,    10,    11,    12,     0,     0,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     0,
     360,   361,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,   362,    31,
      15,    16,    17,    18,   215,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,    17,
      18,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,    31
};

static const yytype_int16 yycheck[] =
{
       5,     5,     5,    90,     5,   117,   153,    84,    58,    89,
     122,    70,   338,   262,     6,   247,    47,   165,    48,   328,
       6,   253,    80,   255,    52,    53,     6,    56,    57,     6,
       6,    36,    36,    36,    80,    36,    94,   185,    18,     6,
      80,    87,    18,    48,     6,    85,     3,    18,    78,    20,
      21,    56,     6,    56,    83,    81,   365,    86,    84,    64,
      86,    64,    93,    93,    18,    19,    20,    21,    82,    74,
      98,    99,    86,    78,     0,    29,    30,    31,    32,    84,
      84,    84,    77,    84,    89,    90,    89,    90,    93,    78,
      82,   417,   324,   205,   206,   182,   422,   174,    84,   129,
     426,    78,    56,    57,   430,   217,    77,    87,   188,   257,
     436,    78,    77,     6,    81,   262,   365,   349,    81,    81,
     352,    85,   354,    86,   129,   357,   358,    80,    82,    78,
      84,    80,    85,    82,    88,    89,    29,    30,    31,    32,
     252,    78,   201,   375,    50,    51,   100,   101,   153,    87,
      88,    89,    90,    91,    92,   387,    54,    55,    80,   164,
      80,    78,   167,    85,   167,    85,    34,    35,    36,   174,
     174,   174,    86,   174,   406,   287,     6,   182,   326,   182,
      82,    94,    84,   188,    97,   188,   110,   111,   275,    90,
      91,    92,   339,    78,   341,    29,    30,    31,    32,    88,
      89,   206,   207,   206,    80,   206,    82,     5,     6,     7,
     290,     9,    10,    11,    12,   265,    80,    15,    82,   143,
      22,    23,    24,    25,    80,    80,    82,    82,    26,    78,
     377,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    80,    46,    82,
       6,   328,   399,    16,    17,   403,    76,   262,   345,   225,
     226,   227,   228,    79,    80,    76,   378,    79,    80,    78,
     275,    78,   275,    18,    19,    18,    19,   223,   224,   229,
     230,    79,   287,     6,   287,   290,   287,   290,   365,   231,
     232,     6,   216,     6,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    80,    82,    79,    79,     6,   354,    79,    86,
     357,   358,    81,   328,   328,   328,    84,   328,    82,    84,
      82,    84,    82,    82,   339,    79,   341,     6,   375,    48,
     345,    49,   345,    84,    95,    82,     6,    77,    96,    78,
     387,    97,    77,     6,    18,    79,     6,     6,    80,    87,
     365,   365,   365,    82,   365,    18,    19,    20,    21,   406,
       6,    85,   377,     6,    84,    81,    29,    30,    31,    32,
      85,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    81,    46,   399,    81,     6,    85,    82,    81,
      81,    81,    69,    56,    57,     6,    20,    82,    82,    82,
      82,    81,    21,    18,    82,    68,    81,    70,    71,    72,
      73,    74,    75,    82,    81,    78,    79,     6,    19,    82,
      82,    84,     6,    81,     6,    88,    89,    83,    82,    18,
      19,    20,    21,    81,    84,    82,    36,   100,   101,   365,
      29,    30,    31,    32,   174,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   371,    46,   273,   388,
     362,   218,   251,   167,   216,    78,   207,    56,    57,   219,
     207,   220,    -1,   221,   287,   164,   222,    -1,    -1,    68,
      -1,    70,    71,    72,    73,    74,    75,    -1,    -1,    78,
      79,     6,    -1,    82,    -1,    84,    -1,    -1,    -1,    88,
      89,    -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,   100,   101,    -1,    29,    30,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    71,    72,    73,    74,
      75,    -1,    -1,    78,    79,     6,    -1,    82,    -1,    84,
      -1,    -1,    -1,    88,    89,    -1,    -1,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,   100,   101,    -1,    29,    30,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      71,    72,    73,    74,    75,    -1,    -1,    78,     6,    -1,
      -1,    82,    -1,    84,    -1,    -1,    -1,    88,    89,    -1,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,   100,
     101,    29,    30,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    82,    81,    84,    -1,    -1,    -1,
      88,    89,    -1,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,   100,   101,    29,    30,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    46,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    -1,    84,
      -1,    -1,    -1,    88,    89,    29,    30,    31,    32,    -1,
      -1,     6,    56,    57,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    56,    57,    29,    30,    31,    32,    -1,    -1,
      84,    85,    -1,    -1,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,   100,   101,    -1,    -1,
      84,    56,    57,    -1,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,    29,    30,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,     6,     7,
      -1,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,    -1,     9,    10,    11,    12,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    79,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    29,    30,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    46,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    79,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    46,    29,    30,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    -1,     6,     7,    79,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,     5,     6,     7,
      -1,     9,    10,    11,    12,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,     6,
       7,    -1,     9,    10,    11,    12,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      29,    30,    31,    32,     6,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   103,    77,     0,    78,     4,     6,     7,     9,
      10,    11,    12,    13,    14,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    46,   104,   105,   106,   107,   108,   109,   121,   122,
     123,   132,   133,   136,   137,   138,   144,   145,   146,   147,
     148,   149,   150,   176,   177,   178,   179,   180,    77,     6,
      81,    78,    78,     6,    78,    79,   107,     6,    78,    81,
      86,   143,   144,   147,    78,   186,    85,   144,   146,   181,
     182,   183,     6,    78,   203,   205,     6,    76,    76,    78,
     139,   140,   144,   146,    78,     6,   124,   125,   129,     6,
       6,    18,    87,   134,   152,     6,    18,    19,    20,    21,
      56,    57,    68,    70,    71,    72,    73,    74,    75,    78,
      79,    82,    84,    88,    89,   100,   101,   134,   144,   146,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   172,   173,
     175,   177,   180,   184,   185,   187,   188,   189,   191,   192,
     195,   196,   197,   202,   205,     6,   183,    80,    82,    84,
       5,    15,    26,   106,   110,   111,   112,   117,   120,    82,
      79,    79,   139,    79,   140,     6,   141,   142,   144,   124,
      86,    79,   124,    81,    82,    87,    88,    89,    90,    91,
      92,   151,   144,   165,   165,    84,    84,    84,    82,    82,
      82,   169,    82,    79,   169,     6,    47,    93,    48,    49,
      95,    96,    97,    50,    51,    52,    53,    98,    99,    54,
      55,    88,    89,    90,    91,    92,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    81,   171,   165,    56,
      57,    83,    86,    80,    82,    84,    82,     6,    79,   185,
      80,    82,   184,   143,   182,    77,    78,    77,    79,   111,
     206,    79,   143,    80,    82,   139,    79,    18,     6,    18,
     134,   169,   169,   180,   199,   189,   195,   198,    82,    85,
      78,    80,    82,   190,   155,   165,   169,   156,   157,   158,
     159,   160,   161,   161,   162,   162,   162,   162,   163,   163,
     164,   164,   165,   165,   165,   170,     6,   172,   169,   170,
      29,    85,   170,   174,    81,   143,     6,   206,   204,   205,
      16,    17,   113,   114,   115,   142,    82,    87,    82,    85,
       6,    85,   199,   200,   201,   139,     6,    80,    82,    94,
      87,    85,    80,    85,    78,   170,   193,    81,    81,   143,
      27,    28,    45,   106,   112,   118,   119,   130,   131,   135,
      79,    80,    81,   129,   185,    81,   185,    85,    82,    79,
       6,   170,   170,   193,   194,   193,   193,    81,   145,   119,
     206,    81,   114,    18,    20,    21,    77,   116,    81,    69,
     193,   185,   169,     6,    82,    79,    80,   193,   136,     6,
      20,   185,    82,   143,   193,    82,    82,    82,    82,   129,
      81,    21,    82,   129,    81,    18,    82,   129,    81,    19,
      82,   129,    81,     6,    83,     6,    82,   129,    81,    22,
      23,    24,    25,   126,   127,    84,    82,    18,    19,   128,
      80,    85,    18,    19
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
#line 2110 "gs.tab.c"
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


#line 681 "./gs.y"


