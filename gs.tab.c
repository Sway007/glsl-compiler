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
     blend_state = 263,
     depth_state = 264,
     stencil_state = 265,
     raster_state = 266,
     EditorProperties = 267,
     EditorMacros = 268,
     tags = 269,
     ReplacementTag = 270,
     INT_CONSTANT = 271,
     FLOAT_CONSTANT = 272,
     true = 273,
     false = 274,
     UsePass = 275,
     VertexShader = 276,
     FragmentShader = 277,
     void = 278,
     float = 279,
     int = 280,
     mat4 = 281,
     struct = 282,
     highp = 283,
     mediemp = 284,
     lowp = 285,
     const = 286,
     in = 287,
     out = 288,
     inout = 289,
     centroid = 290,
     SMOOTH = 291,
     FLAT = 292,
     PRECISE = 293,
     PRECISION = 294,
     INVARIANT = 295,
     or = 296,
     xor = 297,
     and = 298,
     eq = 299,
     neq = 300,
     ge = 301,
     le = 302,
     left_op = 303,
     right_op = 304,
     INC_OP = 305,
     DEC_OP = 306,
     MUL_ASSIGN = 307,
     DIV_ASSIGN = 308,
     MOD_ASSIGN = 309,
     ADD_ASSIGN = 310,
     SUB_ASSIGN = 311,
     LEFT_ASSIGN = 312,
     RIGHT_ASSIGN = 313,
     AND_ASSIGN = 314,
     XOR_ASSIGN = 315,
     OR_ASSIGN = 316,
     IF = 317,
     ELSE = 318,
     WHILE = 319,
     FOR = 320,
     CONTINUE = 321,
     BREAK = 322,
     RETURN = 323,
     DISCARD = 324,
     TODO = 325,
     string_const = 326
   };
#endif
/* Tokens.  */
#define shader 258
#define subshader 259
#define pass 260
#define id 261
#define render_queue_type 262
#define blend_state 263
#define depth_state 264
#define stencil_state 265
#define raster_state 266
#define EditorProperties 267
#define EditorMacros 268
#define tags 269
#define ReplacementTag 270
#define INT_CONSTANT 271
#define FLOAT_CONSTANT 272
#define true 273
#define false 274
#define UsePass 275
#define VertexShader 276
#define FragmentShader 277
#define void 278
#define float 279
#define int 280
#define mat4 281
#define struct 282
#define highp 283
#define mediemp 284
#define lowp 285
#define const 286
#define in 287
#define out 288
#define inout 289
#define centroid 290
#define SMOOTH 291
#define FLAT 292
#define PRECISE 293
#define PRECISION 294
#define INVARIANT 295
#define or 296
#define xor 297
#define and 298
#define eq 299
#define neq 300
#define ge 301
#define le 302
#define left_op 303
#define right_op 304
#define INC_OP 305
#define DEC_OP 306
#define MUL_ASSIGN 307
#define DIV_ASSIGN 308
#define MOD_ASSIGN 309
#define ADD_ASSIGN 310
#define SUB_ASSIGN 311
#define LEFT_ASSIGN 312
#define RIGHT_ASSIGN 313
#define AND_ASSIGN 314
#define XOR_ASSIGN 315
#define OR_ASSIGN 316
#define IF 317
#define ELSE 318
#define WHILE 319
#define FOR 320
#define CONTINUE 321
#define BREAK 322
#define RETURN 323
#define DISCARD 324
#define TODO 325
#define string_const 326




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
#line 249 "gs.tab.c"

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
#define YYLAST   1091

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  248
/* YYNRULES -- Number of states.  */
#define YYNSTATES  422

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    92,     2,     2,     2,    84,    89,     2,
      94,    95,    82,    80,    77,    81,    76,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    74,
      90,    75,    91,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    78,     2,    79,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    87,    73,    93,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71
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
     156,   158,   160,   165,   170,   177,   181,   184,   189,   191,
     193,   195,   197,   199,   201,   207,   212,   214,   217,   221,
     226,   228,   232,   234,   237,   240,   244,   246,   249,   251,
     253,   255,   257,   260,   262,   264,   266,   268,   270,   272,
     274,   276,   278,   280,   282,   284,   286,   288,   290,   292,
     294,   296,   298,   300,   304,   308,   310,   316,   318,   322,
     324,   328,   330,   334,   336,   340,   342,   346,   348,   352,
     354,   358,   362,   364,   368,   372,   376,   380,   382,   386,
     390,   392,   396,   400,   402,   406,   410,   414,   416,   419,
     422,   425,   427,   429,   431,   433,   435,   440,   442,   446,
     450,   453,   456,   458,   460,   462,   464,   466,   470,   472,
     476,   478,   482,   484,   486,   488,   490,   492,   494,   496,
     498,   500,   502,   504,   506,   511,   515,   520,   522,   526,
     528,   531,   534,   536,   539,   543,   545,   548,   550,   554,
     557,   559,   562,   566,   568,   571,   573,   575,   578,   582,
     584,   586,   588,   590,   592,   595,   598,   605,   613,   622,
     626,   631,   634,   638,   640,   644,   649,   656,   662,   665,
     669,   674,   680,   682,   686,   688,   692,   694,   697,   703,
     711,   717,   724,   726,   728,   730,   735,   738,   742,   743,
     745,   748,   751,   754,   758,   761,   763,   765,   767
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      97,     0,    -1,     3,    71,    72,   102,    73,    -1,    12,
      72,    70,    73,    -1,    13,    72,    70,    73,    -1,   123,
      -1,   122,    -1,   116,    -1,   127,    -1,   165,    -1,   117,
      -1,   100,    -1,    98,    -1,    99,    -1,   103,    -1,    -1,
     102,   101,    -1,     4,    71,   191,   104,   192,    -1,   105,
      -1,   104,   105,    -1,   100,    -1,   106,    -1,   111,    -1,
     114,    -1,    14,    72,   107,    73,    -1,    -1,   108,    -1,
     107,    74,   108,    -1,   109,    75,   110,    -1,    15,    -1,
      71,    -1,    16,    -1,     5,    71,   191,   112,   192,    -1,
     113,    -1,   112,   113,    -1,   100,    -1,   121,    -1,   106,
      -1,   124,    -1,    20,    71,    74,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,   115,    75,     6,    74,    -1,
     115,    72,   118,    73,    -1,   115,     6,    72,   118,    73,
      -1,    -1,   119,   118,    -1,     6,    75,     6,    74,     6,
      75,    18,    74,     6,    75,    19,    74,     6,    75,    16,
      74,     6,    75,    17,    74,    -1,    21,    -1,    22,    -1,
     120,    75,     6,    74,    -1,     7,    75,     6,    74,    -1,
       7,    75,     7,    76,     6,    74,    -1,   169,     6,    74,
      -1,     7,     6,    -1,    39,   134,   125,    74,    -1,    23,
      -1,    24,    -1,    25,    -1,    26,    -1,   125,    -1,     6,
      -1,    27,     6,    72,   128,    73,    -1,    27,    72,   128,
      73,    -1,   129,    -1,   128,   129,    -1,   133,   130,    74,
      -1,   135,   133,   128,    74,    -1,   131,    -1,   130,    77,
     131,    -1,     6,    -1,     6,   132,    -1,    78,    79,    -1,
      78,   141,    79,    -1,   126,    -1,   125,   132,    -1,    28,
      -1,    29,    -1,    30,    -1,   136,    -1,   135,   136,    -1,
     137,    -1,   134,    -1,   138,    -1,   139,    -1,    38,    -1,
      31,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
      36,    -1,    37,    -1,    40,    -1,    80,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,     6,    -1,    16,    -1,
     141,   140,    16,    -1,   141,   140,     6,    -1,   143,    -1,
     143,    85,   158,    86,   159,    -1,   144,    -1,   143,    41,
     144,    -1,   145,    -1,   144,    42,   145,    -1,   146,    -1,
     145,    43,   146,    -1,   147,    -1,   146,    87,   147,    -1,
     148,    -1,   147,    88,   148,    -1,   149,    -1,   148,    89,
     149,    -1,   150,    -1,   149,    44,   150,    -1,   149,    45,
     150,    -1,   151,    -1,   150,    90,   151,    -1,   150,    91,
     151,    -1,   150,    47,   151,    -1,   150,    46,   151,    -1,
     152,    -1,   151,    48,   152,    -1,   151,    49,   152,    -1,
     153,    -1,   152,    80,   153,    -1,   152,    81,   153,    -1,
     154,    -1,   153,    82,   154,    -1,   153,    83,   154,    -1,
     153,    84,   154,    -1,   156,    -1,    50,   154,    -1,    51,
     154,    -1,   155,   154,    -1,    80,    -1,    81,    -1,    92,
      -1,    93,    -1,   157,    -1,   156,    78,   158,    79,    -1,
     161,    -1,   156,    76,     6,    -1,   156,    76,   161,    -1,
     156,    50,    -1,   156,    51,    -1,     6,    -1,    16,    -1,
      17,    -1,    18,    -1,    19,    -1,    94,   158,    95,    -1,
     159,    -1,   158,    77,   159,    -1,   142,    -1,   154,   160,
     159,    -1,    75,    -1,    52,    -1,    53,    -1,    54,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,   162,    -1,   164,    94,   163,    95,
      -1,   164,    94,    95,    -1,   164,    94,    23,    95,    -1,
     159,    -1,   163,    77,   159,    -1,   133,    -1,   166,   175,
      -1,   167,    95,    -1,   168,    -1,   168,   170,    -1,   169,
       6,    94,    -1,   133,    -1,   135,   133,    -1,   171,    -1,
     170,    77,   171,    -1,   135,   172,    -1,   172,    -1,   133,
       6,    -1,   133,     6,   132,    -1,   174,    -1,   173,   174,
      -1,   175,    -1,   176,    -1,    72,    73,    -1,   193,   173,
     194,    -1,   177,    -1,   183,    -1,   184,    -1,   185,    -1,
     190,    -1,   166,    74,    -1,   179,    74,    -1,   135,     6,
      72,   128,    73,    74,    -1,   135,     6,    72,   128,    73,
       6,    74,    -1,   135,     6,    72,   128,    73,     6,   132,
      74,    -1,   135,     6,    74,    -1,   135,     6,   178,    74,
      -1,    77,     6,    -1,   178,    77,     6,    -1,   180,    -1,
     179,    77,     6,    -1,   179,    77,     6,   132,    -1,   179,
      77,     6,   132,    75,   181,    -1,   179,    77,     6,    75,
     181,    -1,   169,     6,    -1,   169,     6,   132,    -1,   169,
       6,    75,   181,    -1,   169,     6,   132,    75,   181,    -1,
     159,    -1,    72,   182,    73,    -1,   181,    -1,   182,    77,
     181,    -1,    74,    -1,   158,    74,    -1,    62,    94,   158,
      95,   174,    -1,    62,    94,   158,    95,   174,    63,   174,
      -1,    64,    94,   187,    95,   174,    -1,    65,    94,   186,
     188,    95,   174,    -1,   183,    -1,   177,    -1,   158,    -1,
     169,     6,    75,   181,    -1,   189,    74,    -1,   189,    74,
     158,    -1,    -1,   187,    -1,    66,    74,    -1,    67,    74,
      -1,    68,    74,    -1,    68,   158,    74,    -1,    69,    74,
      -1,   193,    -1,   194,    -1,    72,    -1,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    84,    88,    93,    94,    95,    96,    97,
      98,   103,   104,   105,   106,   109,   111,   116,   120,   121,
     125,   126,   127,   128,   132,   134,   136,   137,   141,   146,
     151,   152,   156,   160,   161,   165,   166,   167,   169,   173,
     177,   178,   179,   180,   184,   185,   189,   192,   194,   199,
     207,   208,   212,   216,   217,   222,   223,   228,   233,   234,
     235,   236,   240,   241,   246,   247,   251,   252,   256,   257,
     261,   262,   266,   267,   271,   272,   276,   277,   281,   282,
     283,   287,   288,   292,   293,   294,   295,   296,   300,   301,
     302,   303,   304,   308,   309,   313,   317,   318,   319,   320,
     321,   325,   326,   327,   328,   332,   333,   337,   338,   342,
     343,   347,   348,   352,   353,   357,   358,   362,   363,   367,
     368,   369,   373,   374,   375,   376,   377,   381,   382,   383,
     387,   388,   389,   393,   394,   395,   396,   400,   401,   402,
     403,   406,   407,   408,   409,   413,   414,   415,   416,   417,
     418,   419,   423,   424,   425,   426,   427,   428,   432,   433,
     437,   438,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   456,   460,   461,   462,   466,   467,   470,
     474,   478,   482,   483,   487,   491,   492,   496,   497,   501,
     502,   506,   507,   511,   512,   516,   517,   521,   522,   526,
     527,   528,   529,   530,   534,   535,   537,   538,   539,   541,
     542,   549,   550,   554,   555,   556,   557,   558,   562,   563,
     564,   565,   569,   570,   574,   575,   579,   580,   585,   586,
     590,   591,   595,   596,   600,   601,   605,   606,   609,   611,
     615,   616,   617,   618,   619,   623,   627,   631,   635
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "shader", "subshader", "pass", "id",
  "render_queue_type", "blend_state", "depth_state", "stencil_state",
  "raster_state", "EditorProperties", "EditorMacros", "tags",
  "ReplacementTag", "INT_CONSTANT", "FLOAT_CONSTANT", "true", "false",
  "UsePass", "VertexShader", "FragmentShader", "void", "float", "int",
  "mat4", "struct", "highp", "mediemp", "lowp", "const", "in", "out",
  "inout", "centroid", "SMOOTH", "FLAT", "PRECISE", "PRECISION",
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
  "gl_variable_declaration", "precision_specifier",
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
     325,   326,   123,   125,    59,    61,    46,    44,    91,    93,
      43,    45,    42,    47,    37,    63,    58,   124,    94,    38,
      60,    62,    33,   126,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    98,    99,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   101,   102,   102,   103,   104,   104,
     105,   105,   105,   105,   106,   107,   107,   107,   108,   109,
     110,   110,   111,   112,   112,   113,   113,   113,   113,   114,
     115,   115,   115,   115,   116,   116,   117,   118,   118,   119,
     120,   120,   121,   122,   122,   123,   123,   124,   125,   125,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     134,   135,   135,   136,   136,   136,   136,   136,   137,   137,
     137,   137,   137,   138,   138,   139,   140,   140,   140,   140,
     140,   141,   141,   141,   141,   142,   142,   143,   143,   144,
     144,   145,   145,   146,   146,   147,   147,   148,   148,   149,
     149,   149,   150,   150,   150,   150,   150,   151,   151,   151,
     152,   152,   152,   153,   153,   153,   153,   154,   154,   154,
     154,   155,   155,   155,   155,   156,   156,   156,   156,   156,
     156,   156,   157,   157,   157,   157,   157,   157,   158,   158,
     159,   159,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   161,   162,   162,   162,   163,   163,   164,
     165,   166,   167,   167,   168,   169,   169,   170,   170,   171,
     171,   172,   172,   173,   173,   174,   174,   175,   175,   176,
     176,   176,   176,   176,   177,   177,   177,   177,   177,   177,
     177,   178,   178,   179,   179,   179,   179,   179,   180,   180,
     180,   180,   181,   181,   182,   182,   183,   183,   184,   184,
     185,   185,   186,   186,   187,   187,   188,   188,   189,   189,
     190,   190,   190,   190,   190,   191,   192,   193,   194
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     5,     1,     2,
       1,     1,     1,     1,     4,     0,     1,     3,     3,     1,
       1,     1,     5,     1,     2,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     4,     4,     5,     0,     2,    20,
       1,     1,     4,     4,     6,     3,     2,     4,     1,     1,
       1,     1,     1,     1,     5,     4,     1,     2,     3,     4,
       1,     3,     1,     2,     2,     3,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     5,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     4,     1,     3,     1,
       2,     2,     1,     2,     3,     1,     2,     1,     3,     2,
       1,     2,     3,     1,     2,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     2,     2,     6,     7,     8,     3,
       4,     2,     3,     1,     3,     4,     6,     5,     2,     3,
       4,     5,     1,     3,     1,     3,     1,     2,     5,     7,
       5,     6,     1,     1,     1,     4,     2,     3,     0,     1,
       2,     2,     2,     3,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    15,     0,     0,    63,     0,
      40,    41,    42,    43,     0,     0,    58,    59,    60,    61,
       0,    78,    79,    80,    88,    89,    90,    91,    92,    93,
      94,    87,    95,     2,    12,    13,    11,    16,    14,     0,
       7,    10,     6,     5,    62,    76,     8,   185,    84,     0,
      81,    83,    85,    86,     9,     0,     0,   182,     0,     0,
      56,     0,     0,     0,     0,     0,     0,    47,     0,     0,
      77,   186,    82,   247,   180,     0,   181,     0,     0,   183,
     187,   190,     0,   247,     0,   245,     0,     0,     0,     0,
       0,     0,    66,     0,     0,    47,     0,     0,    47,     0,
     101,   102,    74,     0,   197,   152,   153,   154,   155,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
     141,   142,   143,   144,     0,   179,     0,   160,   105,   107,
     109,   111,   113,   115,   117,   119,   122,   127,   130,   133,
       0,   137,   145,     0,   158,   147,   173,     0,     0,     0,
       0,   193,   195,   196,   199,     0,   213,   200,   201,   202,
     203,   191,   189,     0,    55,   184,     0,     0,     0,    20,
       0,    18,    21,    22,    23,    53,     0,     3,     4,     0,
      65,    67,    72,     0,    70,     0,     0,     0,    45,    48,
      44,    75,    96,    97,    98,    99,   100,     0,   179,   138,
     139,     0,     0,     0,   240,   241,   242,     0,   244,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   162,     0,   140,   150,   151,     0,     0,   227,     0,
       0,   204,   218,   248,   194,   198,   205,     0,   192,   188,
       0,    25,     0,    19,    17,   246,     0,    64,    73,    68,
       0,     0,    46,     0,   104,   103,     0,   234,     0,     0,
     233,   232,   238,   243,   157,     0,   209,     0,     0,   108,
     133,     0,   110,   112,   114,   116,   118,   120,   121,   126,
     125,   123,   124,   128,   129,   131,   132,   134,   135,   136,
     161,   148,   149,     0,   159,    58,   175,   177,     0,     0,
     219,   214,     0,    29,     0,    26,     0,    39,    54,    71,
      69,     0,     0,     0,     0,   239,     0,     0,     0,   211,
     210,     0,     0,   146,   176,     0,   174,     0,   222,   220,
       0,     0,   215,    50,    51,     0,    35,    37,     0,    33,
       0,    36,    38,    24,     0,     0,     0,   228,     0,   230,
       0,   236,     0,   212,   106,   178,   224,     0,   221,   217,
       0,     0,    34,    32,     0,    27,    31,    30,    28,     0,
       0,   235,   231,   237,     0,   206,   223,     0,   216,     0,
       0,     0,   229,   207,     0,   225,    57,    52,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    34,    35,   169,    37,     6,    38,   170,   171,
     172,   324,   325,   326,   388,   173,   358,   359,   174,    39,
      40,    41,    97,    98,   360,   361,    42,    43,   362,    44,
      45,    46,    91,    92,   183,   184,    70,   198,    48,    94,
      50,    51,    52,    53,   197,   103,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   242,   145,   146,   318,   147,    54,
     148,    56,    57,   149,    79,    80,    81,   150,   151,   152,
     153,   154,   288,   155,   156,   349,   377,   157,   158,   159,
     282,   279,   336,   337,   160,    84,   264,    75,   265
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -317
static const yytype_int16 yypact[] =
{
      12,   -44,    40,   -34,  -317,  -317,   725,     4,  -317,    20,
    -317,  -317,  -317,  -317,   -26,    10,  -317,  -317,  -317,  -317,
       5,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,
    -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,    14,
    -317,  -317,  -317,  -317,   -10,  -317,  -317,  -317,  -317,   519,
    -317,  -317,  -317,  -317,  -317,    25,    32,   519,   117,    63,
    -317,   202,    73,    80,    88,   519,   111,   166,   184,     8,
    -317,  -317,  -317,   126,  -317,   414,  -317,   233,   519,   165,
    -317,  -317,   -37,  -317,  1018,  -317,   174,   178,   185,   186,
     519,   875,  -317,   251,   519,   166,   191,   194,   166,   195,
    -317,  -317,  -317,    58,  -317,     6,  -317,  -317,  -317,  -317,
     647,   647,   176,   177,   179,   198,   201,   594,   203,  -317,
    -317,  -317,  -317,  -317,   647,   262,  1051,  -317,   -22,   238,
     240,   215,   216,   214,   171,   -25,   173,   137,   130,    57,
     647,    53,  -317,    -7,  -317,  -317,  -317,   211,   232,   301,
     342,  -317,  -317,  -317,  -317,    82,  -317,  -317,  -317,  -317,
    -317,   -10,  -317,   519,  -317,  -317,   237,   239,   241,  -317,
     776,  -317,  -317,  -317,  -317,  -317,   303,  -317,  -317,   921,
    -317,  -317,   -10,    84,  -317,   519,   242,   304,  -317,  -317,
    -317,  -317,  -317,  -317,  -317,  -317,  -317,    38,  -317,  -317,
    -317,   647,   558,   486,  -317,  -317,  -317,    93,  -317,   -54,
      47,   647,   647,   647,   647,   647,   647,   647,   647,   647,
     647,   647,   647,   647,   647,   647,   647,   647,   647,   647,
     647,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,
    -317,  -317,   647,  -317,  -317,  -317,    24,   647,  -317,   647,
     169,  -317,   -39,  -317,  -317,  -317,  -317,   307,  -317,  -317,
      63,   299,   246,  -317,  -317,  -317,   248,  -317,  -317,  -317,
     251,   200,  -317,   249,  -317,  -317,   -35,   247,   319,   234,
    -317,  -317,   558,  -317,  -317,   519,  -317,   321,   100,   238,
    -317,   -15,   240,   215,   216,   214,   171,   -25,   -25,   173,
     173,   173,   173,   137,   137,   130,   130,  -317,  -317,  -317,
    -317,   236,  -317,    99,  -317,   243,  -317,  -317,   -19,   609,
     259,   125,   685,  -317,   170,  -317,   260,  -317,  -317,  -317,
    -317,   330,   414,   264,   414,  -317,   245,   263,   967,  -317,
    -317,   335,   647,  -317,  -317,   647,  -317,   609,  -317,  -317,
     609,   609,   267,  -317,  -317,    78,  -317,  -317,   829,  -317,
     268,  -317,  -317,  -317,   299,     2,   269,   282,   609,  -317,
     414,   647,    22,  -317,  -317,  -317,  -317,    21,  -317,  -317,
     609,   122,  -317,  -317,   340,  -317,  -317,  -317,  -317,   329,
     414,  -317,  -317,   247,    48,  -317,  -317,   609,  -317,   275,
     276,   277,  -317,  -317,   288,  -317,  -317,  -317,   350,  -317,
     306,   344,   309,   379,   311,   371,   314,   384,   316,   377,
     322,  -317
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -317,  -317,  -317,  -317,    -3,  -317,  -317,  -317,  -317,   225,
    -305,  -317,    33,  -317,  -317,  -317,  -317,    41,  -317,  -317,
    -317,  -317,   109,  -317,  -317,  -317,  -317,  -317,  -317,    17,
    -317,  -317,   -80,   -87,  -317,   131,  -153,    -6,    45,    -1,
     -33,  -317,  -317,  -317,  -317,  -317,  -317,  -317,   192,   189,
     199,   190,   196,   204,    27,   -68,    28,    29,    71,  -317,
    -317,  -317,  -111,  -217,  -317,   172,  -317,  -317,  -317,  -317,
      -5,  -317,  -317,    -4,  -317,   254,   341,  -317,  -143,   369,
    -317,   222,  -317,  -317,  -317,  -316,  -317,   223,  -317,  -317,
    -317,   145,  -317,  -317,  -317,   168,    83,   -50,   279
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -186
static const yytype_int16 yytable[] =
{
      47,    55,    58,    36,   181,    49,   207,   254,   258,    85,
     179,    64,   -63,   209,   100,     1,    72,   357,   386,   211,
      66,   220,   221,   249,   101,   310,    60,     3,   394,   268,
     311,   376,   314,   317,   378,   379,   319,   164,     5,    69,
       4,   284,   249,    71,   274,    72,    62,    16,    17,    18,
      19,    77,   391,   357,   275,   165,    78,   165,   345,    93,
     332,    72,   249,   212,   398,   222,   223,   248,    69,   125,
     249,   342,    77,   387,   126,    59,   346,    65,    47,    55,
      58,   405,    63,    49,    93,    93,    67,   102,   185,    68,
     276,   277,   181,    72,   396,    61,   395,    73,   397,   320,
     -63,   291,   348,   244,   245,   271,    21,    22,    23,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   285,
      71,   286,   403,    82,   287,   374,    69,    76,   375,   246,
     348,   247,   241,   348,   348,    83,   313,   191,   192,   193,
     194,   195,   196,    88,   125,    16,    17,    18,    19,   126,
      89,   348,   299,   300,   301,   302,   256,    77,   269,   257,
      90,   270,    78,   348,    47,    55,    58,   283,   352,    49,
     249,   277,    96,    93,   340,   105,   249,   341,   343,    93,
     348,   199,   200,    95,   181,   106,   107,   108,   109,   367,
      99,   369,   315,    17,    18,    19,   125,   125,   278,   104,
     351,    49,   126,    69,   186,   338,     8,   189,    86,    87,
      85,   243,   228,   229,   230,   218,   219,   226,   227,   110,
     111,   224,   225,    16,    17,    18,    19,   392,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   161,
      32,   404,   163,   363,   364,   297,   298,   402,   175,   120,
     121,   181,   303,   304,   176,   305,   306,   182,   177,   178,
     393,   122,   123,   124,   316,    93,   187,   188,  -185,   190,
     201,   202,   204,   203,   330,   205,   125,   208,   278,    93,
     213,    49,   290,   214,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   307,
     308,   309,   215,   217,   216,   250,   251,   252,   260,   266,
     273,   261,   262,   321,   323,   272,    47,    55,    58,   356,
     327,    49,   328,   331,   249,   333,   125,   339,   125,   334,
     -63,   126,    93,   126,   350,   365,   366,   371,   344,   368,
     370,   373,   380,   384,   389,   390,   400,   401,   105,   406,
     407,   408,    47,    55,    58,   356,   410,    49,   106,   107,
     108,   109,   409,   412,   125,    16,    17,    18,    19,   126,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   411,    32,   413,   125,   414,   415,   416,   417,   126,
     418,   419,   110,   111,   420,   263,   421,   385,   399,   382,
     381,   329,   292,   289,   112,   294,   113,   114,   115,   116,
     117,   118,   295,   293,    73,   253,   119,   259,   312,   162,
     105,   296,   120,   121,    74,   280,   281,   335,   322,   255,
     106,   107,   108,   109,   122,   123,   124,    16,    17,    18,
      19,   383,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,     0,   113,   114,
     115,   116,   117,   118,     0,     0,    73,     0,   119,     0,
       0,     0,   105,     0,   120,   121,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   122,   123,   124,    16,
      17,    18,    19,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     8,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,     0,     0,
       0,     0,    16,    17,    18,    19,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
     119,     0,     0,     0,   105,     0,   120,   121,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   122,   123,
     124,    16,    17,    18,    19,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,     0,
     105,     0,     0,     0,     0,     0,     0,     0,   110,   111,
     106,   107,   108,   109,     0,   105,     0,    16,    17,    18,
      19,     0,     0,     0,     0,   106,   107,   108,   109,     0,
       0,     0,    16,    17,    18,    19,     0,     0,   120,   121,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
     122,   123,   124,   105,     0,     0,     0,     0,     0,   110,
     111,     0,     0,   106,   107,   108,   109,     0,   206,     0,
      16,    17,    18,    19,   120,   121,     0,     0,     0,     0,
       0,   347,     0,     0,     0,     0,   122,   123,   124,   120,
     121,     8,     9,    10,    11,    12,    13,   110,   111,   167,
       0,   122,   123,   124,     0,     0,   353,   354,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   355,    32,     0,   120,   121,     7,
       0,     8,     9,    10,    11,    12,    13,    14,    15,   122,
     123,   124,     0,     0,     0,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   166,     8,     9,    10,    11,    12,    13,     0,     0,
     167,     0,     0,     0,     0,     0,   168,     0,    33,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,     0,     0,   167,     0,     0,     0,     0,     0,   253,
     353,   354,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   355,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
      18,    19,   253,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,   180,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,    18,    19,   267,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,     8,     9,    10,    11,    12,    13,
       0,     0,   167,     0,     0,     0,     0,     0,   168,     0,
     372,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   210,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32
};

static const yytype_int16 yycheck[] =
{
       6,     6,     6,     6,    91,     6,   117,   150,   161,    59,
      90,     6,     6,   124,     6,     3,    49,   322,    16,    41,
       6,    46,    47,    77,    16,   242,     6,    71,     6,   182,
       6,   347,   249,   250,   350,   351,    75,    74,    72,    78,
       0,    95,    77,    49,     6,    78,    72,    23,    24,    25,
      26,    57,   368,   358,    16,    94,    57,    94,    77,    65,
      95,    94,    77,    85,   380,    90,    91,    74,    78,    75,
      77,    86,    78,    71,    75,    71,    95,    72,    84,    84,
      84,   397,    72,    84,    90,    91,    72,    79,    94,    75,
     201,   202,   179,   126,    73,    75,    74,    72,    77,   252,
      94,   212,   319,    50,    51,   185,    28,    29,    30,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    72,
     126,    74,    74,     6,    77,   342,    78,    95,   345,    76,
     347,    78,    75,   350,   351,    72,   247,    79,    80,    81,
      82,    83,    84,    70,   150,    23,    24,    25,    26,   150,
      70,   368,   220,   221,   222,   223,    74,   163,    74,    77,
      72,    77,   163,   380,   170,   170,   170,    74,   321,   170,
      77,   282,     6,   179,    74,     6,    77,    77,    79,   185,
     397,   110,   111,    72,   271,    16,    17,    18,    19,   332,
       6,   334,    23,    24,    25,    26,   202,   203,   202,    73,
      75,   202,   203,    78,    95,   285,     6,    98,     6,     7,
     260,   140,    82,    83,    84,    44,    45,    80,    81,    50,
      51,    48,    49,    23,    24,    25,    26,   370,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,     6,
      40,   394,    77,    73,    74,   218,   219,   390,    74,    80,
      81,   338,   224,   225,    76,   226,   227,     6,    73,    73,
     371,    92,    93,    94,    95,   271,    75,    73,     6,    74,
      94,    94,    74,    94,    74,    74,   282,    74,   282,   285,
      42,   282,   211,    43,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,    87,    89,    88,    94,    74,     6,    71,     6,
       6,    72,    71,     6,    15,    73,   322,   322,   322,   322,
      74,   322,    74,    74,    77,     6,   332,     6,   334,    95,
      94,   332,   338,   334,    75,    75,     6,    74,    95,    75,
      95,     6,    75,    75,    75,    63,     6,    18,     6,    74,
      74,    74,   358,   358,   358,   358,     6,   358,    16,    17,
      18,    19,    74,    19,   370,    23,    24,    25,    26,   370,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    75,    40,    74,   390,     6,    75,    16,    74,   390,
       6,    75,    50,    51,    17,   170,    74,   364,   381,   358,
     355,   270,   213,   211,    62,   215,    64,    65,    66,    67,
      68,    69,   216,   214,    72,    73,    74,   163,   246,    78,
       6,   217,    80,    81,    55,   203,   203,   282,   260,   150,
      16,    17,    18,    19,    92,    93,    94,    23,    24,    25,
      26,   358,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    64,    65,
      66,    67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,     6,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    92,    93,    94,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,     6,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      74,    -1,    -1,    -1,     6,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    92,    93,
      94,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      16,    17,    18,    19,    -1,     6,    -1,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
      -1,    -1,    23,    24,    25,    26,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,
      92,    93,    94,     6,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    16,    17,    18,    19,    -1,    74,    -1,
      23,    24,    25,    26,    80,    81,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    92,    93,    94,    80,
      81,     6,     7,     8,     9,    10,    11,    50,    51,    14,
      -1,    92,    93,    94,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    80,    81,     4,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    20,    -1,    73,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    73,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    73,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    73,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    73,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      73,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,     6,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    97,    71,     0,    72,   102,     4,     6,     7,
       8,     9,    10,    11,    12,    13,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    40,    73,    98,    99,   100,   101,   103,   115,
     116,   117,   122,   123,   125,   126,   127,   133,   134,   135,
     136,   137,   138,   139,   165,   166,   167,   168,   169,    71,
       6,    75,    72,    72,     6,    72,     6,    72,    75,    78,
     132,   133,   136,    72,   175,   193,    95,   133,   135,   170,
     171,   172,     6,    72,   191,   193,     6,     7,    70,    70,
      72,   128,   129,   133,   135,    72,     6,   118,   119,     6,
       6,    16,    79,   141,    73,     6,    16,    17,    18,    19,
      50,    51,    62,    64,    65,    66,    67,    68,    69,    74,
      80,    81,    92,    93,    94,   133,   135,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   161,   162,   164,   166,   169,
     173,   174,   175,   176,   177,   179,   180,   183,   184,   185,
     190,     6,   172,    77,    74,    94,     5,    14,    20,   100,
     104,   105,   106,   111,   114,    74,    76,    73,    73,   128,
      73,   129,     6,   130,   131,   133,   118,    75,    73,   118,
      74,    79,    80,    81,    82,    83,    84,   140,   133,   154,
     154,    94,    94,    94,    74,    74,    74,   158,    74,   158,
       6,    41,    85,    42,    43,    87,    88,    89,    44,    45,
      46,    47,    90,    91,    48,    49,    80,    81,    82,    83,
      84,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    75,   160,   154,    50,    51,    76,    78,    74,    77,
      94,    74,     6,    73,   174,   194,    74,    77,   132,   171,
      71,    72,    71,   105,   192,   194,     6,    73,   132,    74,
      77,   128,    73,     6,     6,    16,   158,   158,   169,   187,
     177,   183,   186,    74,    95,    72,    74,    77,   178,   144,
     154,   158,   145,   146,   147,   148,   149,   150,   150,   151,
     151,   151,   151,   152,   152,   153,   153,   154,   154,   154,
     159,     6,   161,   158,   159,    23,    95,   159,   163,    75,
     132,     6,   191,    15,   107,   108,   109,    74,    74,   131,
      74,    74,    95,     6,    95,   187,   188,   189,   128,     6,
      74,    77,    86,    79,    95,    77,    95,    72,   159,   181,
      75,    75,   132,    21,    22,    39,   100,   106,   112,   113,
     120,   121,   124,    73,    74,    75,     6,   174,    75,   174,
      95,    74,    73,     6,   159,   159,   181,   182,   181,   181,
      75,   134,   113,   192,    75,   108,    16,    71,   110,    75,
      63,   181,   174,   158,     6,    74,    73,    77,   181,   125,
       6,    18,   174,    74,   132,   181,    74,    74,    74,    74,
       6,    75,    19,    74,     6,    75,    16,    74,     6,    75,
      17,    74
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
#line 2030 "gs.tab.c"
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


#line 637 "./gs.y"


