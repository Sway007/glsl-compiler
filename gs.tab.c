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
#define YYLAST   1451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNRULES -- Number of states.  */
#define YYNSTATES  418

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
       2,     2,     2,    92,     2,     2,     2,    91,    84,     2,
      94,    95,    89,    87,    77,    88,    76,    90,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    74,
      85,    75,    86,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    78,     2,    79,    83,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    82,    73,    93,     2,     2,     2,
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
      80,    82,    84,    90,    92,    95,    97,    99,   101,   105,
     107,   109,   111,   113,   118,   123,   129,   130,   133,   154,
     156,   158,   163,   168,   175,   179,   181,   183,   185,   187,
     189,   191,   197,   202,   204,   207,   211,   216,   218,   222,
     224,   227,   229,   232,   235,   239,   241,   244,   246,   248,
     250,   252,   255,   257,   259,   261,   263,   265,   267,   269,
     271,   273,   275,   277,   279,   281,   283,   285,   291,   293,
     297,   299,   303,   305,   309,   311,   315,   317,   321,   323,
     327,   329,   333,   337,   339,   343,   347,   351,   355,   357,
     361,   365,   367,   371,   375,   377,   381,   385,   389,   391,
     394,   397,   400,   402,   404,   406,   408,   410,   415,   417,
     421,   425,   428,   431,   433,   435,   437,   439,   441,   445,
     447,   451,   453,   457,   459,   461,   463,   465,   467,   469,
     471,   473,   475,   477,   479,   481,   486,   490,   495,   497,
     501,   503,   506,   509,   511,   514,   518,   520,   522,   525,
     527,   531,   534,   536,   539,   541,   544,   548,   551,   555,
     557,   560,   562,   564,   567,   571,   573,   575,   577,   579,
     581,   584,   587,   592,   599,   607,   616,   620,   625,   627,
     630,   634,   636,   640,   645,   652,   658,   661,   665,   671,
     676,   678,   682,   684,   688,   690,   693,   699,   707,   713,
     720,   722,   724,   726,   728,   730,   735,   738,   742,   743,
     745,   748,   751,   754,   758
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      97,     0,    -1,     3,    71,    72,   102,    73,    -1,    12,
      72,    70,    73,    -1,    13,    72,    70,    73,    -1,   123,
      -1,   122,    -1,   116,    -1,   126,    -1,   164,    -1,   117,
      -1,   100,    -1,    98,    -1,    99,    -1,   103,    -1,    -1,
     102,   101,    -1,     4,    71,    72,   104,    73,    -1,   105,
      -1,   104,   105,    -1,   100,    -1,   106,    -1,   111,    -1,
     114,    -1,    14,    72,   107,    73,    -1,    -1,   108,    -1,
     107,    74,   108,    -1,   109,    75,   110,    -1,    15,    -1,
      71,    -1,    16,    -1,     5,    71,    72,   112,    73,    -1,
     113,    -1,   112,   113,    -1,   100,    -1,   121,    -1,   106,
      -1,    20,    71,    74,    -1,     8,    -1,     9,    -1,    10,
      -1,    11,    -1,   115,    75,     6,    74,    -1,   115,    72,
     118,    73,    -1,   115,     6,    72,   118,    73,    -1,    -1,
     119,   118,    -1,     6,    75,     6,    74,     6,    75,    18,
      74,     6,    75,    19,    74,     6,    75,    16,    74,     6,
      75,    17,    74,    -1,    21,    -1,    22,    -1,   120,    75,
       6,    74,    -1,     7,    75,     6,    74,    -1,     7,    75,
       7,    76,     6,    74,    -1,   169,     6,    74,    -1,    23,
      -1,    24,    -1,    25,    -1,    26,    -1,   124,    -1,     6,
      -1,    27,     6,    72,   127,    73,    -1,    27,    72,   127,
      73,    -1,   128,    -1,   127,   128,    -1,   133,   129,    74,
      -1,   135,   133,   127,    74,    -1,   130,    -1,   129,    77,
     130,    -1,     6,    -1,     6,   131,    -1,   132,    -1,   131,
     132,    -1,    78,    79,    -1,    78,   140,    79,    -1,   125,
      -1,   124,   131,    -1,    28,    -1,    29,    -1,    30,    -1,
     136,    -1,   135,   136,    -1,   137,    -1,   134,    -1,   138,
      -1,   139,    -1,    38,    -1,    31,    -1,    32,    -1,    33,
      -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,    40,
      -1,   141,    -1,   142,    -1,   142,    80,   157,    81,   158,
      -1,   143,    -1,   142,    41,   143,    -1,   144,    -1,   143,
      42,   144,    -1,   145,    -1,   144,    43,   145,    -1,   146,
      -1,   145,    82,   146,    -1,   147,    -1,   146,    83,   147,
      -1,   148,    -1,   147,    84,   148,    -1,   149,    -1,   148,
      44,   149,    -1,   148,    45,   149,    -1,   150,    -1,   149,
      85,   150,    -1,   149,    86,   150,    -1,   149,    47,   150,
      -1,   149,    46,   150,    -1,   151,    -1,   150,    48,   151,
      -1,   150,    49,   151,    -1,   152,    -1,   151,    87,   152,
      -1,   151,    88,   152,    -1,   153,    -1,   152,    89,   153,
      -1,   152,    90,   153,    -1,   152,    91,   153,    -1,   155,
      -1,    50,   153,    -1,    51,   153,    -1,   154,   153,    -1,
      87,    -1,    88,    -1,    92,    -1,    93,    -1,   156,    -1,
     155,    78,   157,    79,    -1,   160,    -1,   155,    76,     6,
      -1,   155,    76,   160,    -1,   155,    50,    -1,   155,    51,
      -1,     6,    -1,    16,    -1,    17,    -1,    18,    -1,    19,
      -1,    94,   157,    95,    -1,   158,    -1,   157,    77,   158,
      -1,   141,    -1,   153,   159,   158,    -1,    75,    -1,    52,
      -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,    57,
      -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,   161,
      -1,   163,    94,   162,    95,    -1,   163,    94,    95,    -1,
     163,    94,    23,    95,    -1,   158,    -1,   162,    77,   158,
      -1,   133,    -1,   165,   173,    -1,   166,    95,    -1,   167,
      -1,   167,   170,    -1,   169,   168,    94,    -1,     6,    -1,
     133,    -1,   135,   133,    -1,   171,    -1,   170,    77,   171,
      -1,   135,   172,    -1,   172,    -1,   135,   133,    -1,   133,
      -1,   133,     6,    -1,   133,     6,   131,    -1,    72,    73,
      -1,    72,   174,    73,    -1,   175,    -1,   174,   175,    -1,
     176,    -1,   177,    -1,    72,    73,    -1,    72,   174,    73,
      -1,   178,    -1,   185,    -1,   186,    -1,   187,    -1,   193,
      -1,   165,    74,    -1,   181,    74,    -1,    39,   134,   124,
      74,    -1,   135,     6,    72,   127,    73,    74,    -1,   135,
       6,    72,   127,    73,   179,    74,    -1,   135,     6,    72,
     127,    73,   179,   131,    74,    -1,   135,     6,    74,    -1,
     135,     6,   180,    74,    -1,     6,    -1,    77,   179,    -1,
     180,    77,   179,    -1,   182,    -1,   181,    77,   179,    -1,
     181,    77,   179,   131,    -1,   181,    77,   179,   131,    75,
     183,    -1,   181,    77,   179,    75,   183,    -1,   169,   179,
      -1,   169,   179,   131,    -1,   169,   179,   131,    75,   183,
      -1,   169,   179,    75,   183,    -1,   158,    -1,    72,   184,
      73,    -1,   183,    -1,   184,    77,   183,    -1,    74,    -1,
     157,    74,    -1,    62,    94,   157,    95,   175,    -1,    62,
      94,   157,    95,   175,    63,   175,    -1,    64,    94,   190,
      95,   188,    -1,    65,    94,   189,   191,    95,   188,    -1,
     173,    -1,   177,    -1,   185,    -1,   178,    -1,   157,    -1,
     169,     6,    75,   183,    -1,   192,    74,    -1,   192,    74,
     157,    -1,    -1,   190,    -1,    66,    74,    -1,    67,    74,
      -1,    68,    74,    -1,    68,   157,    74,    -1,    69,    74,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    84,    88,    93,    94,    95,    96,    97,
      98,   103,   104,   105,   106,   109,   111,   116,   120,   121,
     125,   126,   127,   128,   132,   134,   136,   137,   141,   146,
     151,   152,   156,   160,   161,   165,   166,   167,   171,   175,
     176,   177,   178,   182,   183,   187,   190,   192,   197,   205,
     206,   210,   214,   215,   219,   224,   225,   226,   227,   231,
     232,   237,   238,   242,   243,   247,   248,   252,   253,   257,
     258,   262,   263,   267,   268,   272,   273,   277,   278,   279,
     283,   284,   288,   289,   290,   291,   292,   296,   297,   298,
     299,   300,   304,   305,   309,   313,   317,   318,   322,   323,
     327,   328,   332,   333,   337,   338,   342,   343,   347,   348,
     352,   353,   354,   358,   359,   360,   361,   362,   366,   367,
     368,   372,   373,   374,   378,   379,   380,   381,   385,   386,
     387,   388,   391,   392,   393,   394,   398,   399,   400,   401,
     402,   403,   404,   408,   409,   410,   411,   412,   413,   421,
     422,   426,   427,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   445,   449,   450,   451,   455,   456,
     459,   463,   467,   471,   472,   476,   480,   484,   485,   489,
     490,   494,   495,   496,   497,   501,   502,   506,   507,   511,
     512,   516,   517,   521,   522,   526,   527,   528,   529,   530,
     534,   535,   536,   537,   538,   539,   540,   541,   545,   549,
     550,   554,   555,   556,   557,   558,   562,   563,   564,   565,
     569,   570,   574,   575,   579,   580,   585,   586,   590,   591,
     595,   596,   600,   601,   605,   606,   610,   611,   614,   616,
     620,   621,   622,   623,   624
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
  "';'", "'='", "'.'", "','", "'['", "']'", "'?'", "':'", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'",
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
  "gl_variable_declaration", "ext_builtin_type_specifier_nonarray",
  "type_specifier_nonarray", "struct_specifier", "struct_declaration_list",
  "struct_declaration", "struct_declarator_list", "struct_declarator",
  "array_specifier_list", "array_specifier", "type_specifier",
  "precision_qualifier", "type_qualifier", "single_type_qualifier",
  "storage_qualifier", "interpolation_qualifier", "invariant_qualifier",
  "constant_expression", "conditional_expression", "logical_or_expression",
  "logical_xor_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression",
  "expression", "assignment_expression", "assignment_operator",
  "function_call", "function_call_generic", "function_call_parameter_list",
  "function_identifier", "function_definition", "function_prototype",
  "function_declarator", "function_header", "function_name",
  "fully_specified_type", "function_parameter_list",
  "parameter_declaration", "parameter_declarator",
  "compound_statement_no_new_scope", "statement_list", "statement",
  "compound_statement", "simple_statement", "declaration",
  "decl_identifier", "identifier_list", "init_declarator_list",
  "single_declaration", "initializer", "initializer_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "statement_no_new_scope", "for_init_statement", "condition",
  "for_rest_statement", "conditionopt", "jump_statement", 0
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
      63,    58,   124,    94,    38,    60,    62,    43,    45,    42,
      47,    37,    33,   126,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    98,    99,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   101,   102,   102,   103,   104,   104,
     105,   105,   105,   105,   106,   107,   107,   107,   108,   109,
     110,   110,   111,   112,   112,   113,   113,   113,   114,   115,
     115,   115,   115,   116,   116,   117,   118,   118,   119,   120,
     120,   121,   122,   122,   123,   124,   124,   124,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   134,
     135,   135,   136,   136,   136,   136,   136,   137,   137,   137,
     137,   137,   138,   138,   139,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   148,   149,   149,   149,   149,   149,   150,   150,
     150,   151,   151,   151,   152,   152,   152,   152,   153,   153,
     153,   153,   154,   154,   154,   154,   155,   155,   155,   155,
     155,   155,   155,   156,   156,   156,   156,   156,   156,   157,
     157,   158,   158,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   160,   161,   161,   161,   162,   162,
     163,   164,   165,   166,   166,   167,   168,   169,   169,   170,
     170,   171,   171,   171,   171,   172,   172,   173,   173,   174,
     174,   175,   175,   176,   176,   177,   177,   177,   177,   177,
     178,   178,   178,   178,   178,   178,   178,   178,   179,   180,
     180,   181,   181,   181,   181,   181,   182,   182,   182,   182,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     188,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   193,   193,   193
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     5,     1,     2,
       1,     1,     1,     1,     4,     0,     1,     3,     3,     1,
       1,     1,     5,     1,     2,     1,     1,     1,     3,     1,
       1,     1,     1,     4,     4,     5,     0,     2,    20,     1,
       1,     4,     4,     6,     3,     1,     1,     1,     1,     1,
       1,     5,     4,     1,     2,     3,     4,     1,     3,     1,
       2,     1,     2,     2,     3,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     4,     1,     3,
       1,     2,     2,     1,     2,     3,     1,     1,     2,     1,
       3,     2,     1,     2,     1,     2,     3,     2,     3,     1,
       2,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       2,     2,     4,     6,     7,     8,     3,     4,     1,     2,
       3,     1,     3,     4,     6,     5,     2,     3,     5,     4,
       1,     3,     1,     3,     1,     2,     5,     7,     5,     6,
       1,     1,     1,     1,     1,     4,     2,     3,     0,     1,
       2,     2,     2,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    15,     0,     0,    60,     0,
      39,    40,    41,    42,     0,     0,    55,    56,    57,    58,
       0,    77,    78,    79,    87,    88,    89,    90,    91,    92,
      93,    86,    94,     2,    12,    13,    11,    16,    14,     0,
       7,    10,     6,     5,    59,    75,     8,   177,    83,     0,
      80,    82,    84,    85,     9,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     0,    76,
      71,   178,    81,     0,   171,   172,   184,     0,   174,   179,
     182,   176,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,     0,    46,     0,     0,    46,     0,   143,   144,
     145,   146,   147,     0,     0,    73,   132,   133,   134,   135,
       0,   170,     0,    95,    96,    98,   100,   102,   104,   106,
     108,   110,   113,   118,   121,   124,     0,   128,   136,   138,
     164,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,   224,   170,     0,   151,   124,     0,   149,
       0,     0,     0,   189,   191,   192,   195,     0,   211,   196,
     197,   198,   199,   185,   183,   181,     0,    54,   175,     0,
       0,     0,    20,     0,    18,    21,    22,    23,    52,     0,
       3,     4,     0,    62,    64,    69,     0,    67,     0,     0,
       0,    44,    47,    43,   129,   130,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   141,
     142,     0,     0,     0,     0,     0,     0,     0,   240,   241,
     242,     0,   244,   193,     0,    60,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   153,     0,   225,     0,
     200,   208,   216,   188,   190,   201,     0,   186,   180,     0,
      25,     0,    17,    19,     0,    61,    70,    65,     0,     0,
      45,     0,   148,    99,     0,   101,   103,   105,   107,   109,
     111,   112,   117,   116,   114,   115,   119,   120,   122,   123,
     125,   126,   127,   139,   140,     0,    55,   166,   168,     0,
       0,     0,   234,     0,     0,   233,   232,   238,   243,   194,
       0,   206,     0,     0,   152,   150,     0,   217,   208,   212,
       0,    29,     0,    26,     0,    38,    53,    68,    66,     0,
       0,   137,   167,     0,   165,   202,     0,     0,     0,   239,
       0,     0,     0,   209,   207,     0,     0,   220,   219,     0,
       0,   213,    49,    50,    35,    37,     0,    33,     0,    36,
      24,     0,     0,     0,    97,   169,   226,     0,   230,   231,
     228,     0,   236,     0,   210,   222,     0,   218,   215,     0,
      32,    34,     0,    27,    31,    30,    28,     0,     0,   235,
     229,   237,   203,     0,   221,     0,   214,     0,     0,   227,
     204,     0,   223,    51,     0,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    34,    35,   172,    37,     6,    38,   173,   174,
     175,   322,   323,   324,   386,   176,   356,   357,   177,    39,
      40,    41,    95,    96,   358,   359,    42,    43,    44,    45,
      46,    89,    90,   186,   187,    69,    70,   111,    48,   145,
      50,    51,    52,    53,   112,   146,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   147,   126,   127,
     128,   148,   149,   247,   129,   130,   299,   131,    54,   150,
      56,    57,    82,   151,    78,    79,    80,   368,   152,   153,
     154,   155,   156,   252,   313,   157,   158,   348,   376,   159,
     160,   161,   370,   307,   304,   340,   341,   162
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -334
static const yytype_int16 yypact[] =
{
      41,   -50,    61,   -20,  -334,  -334,  1023,    72,  -334,    36,
    -334,  -334,  -334,  -334,    82,    87,  -334,  -334,  -334,  -334,
      21,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,    16,
    -334,  -334,  -334,  -334,    97,  -334,  -334,  -334,  -334,  1390,
    -334,  -334,  -334,  -334,  -334,   105,    54,  1390,   177,   113,
      30,   118,   121,   142,  1390,   151,   221,   223,   192,    97,
    -334,  -334,  -334,   398,  -334,  -334,   224,  1390,   154,  -334,
    -334,   159,   140,  1322,   162,   161,   167,   168,  1390,  1179,
    -334,   239,  1390,   221,   171,   174,   221,   178,     8,  -334,
    -334,  -334,  -334,   911,   911,  -334,  -334,  -334,  -334,  -334,
     911,  -334,   180,  -334,   -23,   219,   226,   182,   179,   183,
      52,   -21,    71,    40,    15,  -334,   911,    58,  -334,  -334,
    -334,   172,  -334,   176,   181,   184,   187,   196,   198,   107,
     199,   477,  -334,  -334,   268,  1411,  -334,  1070,    -8,  -334,
     202,   271,   556,  -334,  -334,  -334,  -334,    63,  -334,  -334,
    -334,  -334,  -334,    97,   224,  -334,  1390,  -334,  -334,   217,
     220,   222,  -334,  1080,  -334,  -334,  -334,  -334,  -334,   285,
    -334,  -334,  1225,  -334,  -334,    97,    64,  -334,  1390,   225,
     288,  -334,  -334,  -334,  -334,  -334,   -57,  -334,   911,   911,
     911,   911,   911,   911,   911,   911,   911,   911,   911,   911,
     911,   911,   911,   911,   911,   911,   911,   911,  -334,  -334,
    -334,    24,   911,   232,    49,   911,   951,   872,  -334,  -334,
    -334,    68,  -334,  -334,   635,   -32,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,   911,  -334,   911,
    -334,   201,    69,  -334,  -334,  -334,   290,    97,  -334,   227,
     282,   228,  -334,  -334,   233,  -334,    97,  -334,   239,   338,
    -334,   234,  -334,   219,   -49,   226,   182,   179,   183,    52,
     -21,   -21,    71,    71,    71,    71,    40,    40,    15,    15,
    -334,  -334,  -334,   206,  -334,    95,   214,  -334,  -334,   -36,
     236,    17,   244,   305,   218,  -334,  -334,   951,  -334,  -334,
    1390,  -334,   290,    74,  -334,  -334,   990,    75,  -334,    77,
    1357,  -334,   106,  -334,   247,  -334,  -334,  -334,  -334,   317,
     911,  -334,  -334,   911,  -334,  -334,   714,   253,   793,  -334,
     238,   255,  1271,  -334,  -334,   290,   990,  -334,  -334,   990,
     990,    86,  -334,  -334,  -334,  -334,  1133,  -334,   256,  -334,
    -334,   282,    -1,   259,  -334,  -334,   272,   990,  -334,  -334,
    -334,   793,   911,    18,  -334,  -334,   -44,  -334,  -334,   990,
    -334,  -334,   333,  -334,  -334,  -334,  -334,   322,   714,  -334,
    -334,   244,  -334,     2,  -334,   990,  -334,   267,   269,  -334,
    -334,    25,  -334,  -334,   336,  -334,   270,   327,   273,   342,
     274,   339,   283,   350,   284,   341,   286,  -334
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -334,  -334,  -334,  -334,    -3,  -334,  -334,  -334,  -334,   204,
    -301,  -334,    19,  -334,  -334,  -334,  -334,    23,  -334,  -334,
    -334,  -334,    70,  -334,  -334,  -334,  -334,  -334,   157,  -334,
    -334,   -78,   -82,  -334,   115,  -154,   -64,    -6,   252,    -4,
     -38,  -334,  -334,  -334,  -334,   337,  -334,   208,   207,   209,
     211,   205,   215,    -9,   -93,     1,    12,   186,  -334,  -334,
    -334,  -104,  -160,  -334,   188,  -334,  -334,  -334,  -334,    -5,
    -334,  -334,  -334,    -2,  -334,   245,   343,   363,   298,  -144,
    -334,  -315,   213,  -244,  -334,  -334,  -334,  -333,  -334,   216,
    -334,  -334,    73,  -334,   134,  -334,  -334,  -334
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -178
static const yytype_int16 yytable[] =
{
      47,    55,    49,    36,    58,   132,   196,   184,   254,   257,
     182,    72,   319,   375,   -60,   384,   377,   378,   198,   355,
     249,     3,    65,   369,   318,   207,   208,    63,   249,   394,
     293,   266,   330,   395,   389,   231,    84,    85,   272,    72,
     310,   333,   311,    71,     1,   312,   396,    16,    17,    18,
      19,    76,     5,    77,    72,   355,   369,   199,    91,   334,
      92,     4,   402,   298,   209,   210,   248,   144,   343,   249,
     385,   164,    16,    17,    18,    19,   400,    47,    55,    49,
      68,    58,    91,    91,    92,    92,   188,   314,    66,   315,
     254,    67,   392,    64,   249,   274,   205,   206,   317,   405,
     184,   374,   -60,    68,   215,   216,   217,    72,   219,   220,
     269,    60,   336,    98,   282,   283,   284,   285,   295,   211,
     212,   301,   302,    99,   100,   101,   102,   213,   214,   393,
      16,    17,    18,    19,   221,   144,   222,   255,   267,    71,
     256,   268,   308,    59,   316,   249,   144,    68,   344,    75,
     349,   345,   350,    68,    61,    68,   347,   103,   104,    62,
      76,   379,    77,   189,    68,   351,   192,    47,    55,    49,
     364,    58,   249,   365,   331,    68,    91,    73,    92,   360,
     361,   230,    91,    81,    92,    83,   347,   184,    86,   347,
     347,    87,   366,   132,   106,   107,   280,   281,    98,   108,
     109,   110,   132,   302,    21,    22,    23,   347,    99,   100,
     101,   102,   286,   287,    88,    16,    17,    18,    19,   347,
     144,   144,    49,    93,   303,   288,   289,    94,   144,    97,
     163,   166,   342,   167,   168,   347,   178,   179,    98,   401,
     180,   181,   103,   104,   399,   185,   190,   191,    99,   100,
     101,   102,   193,   132,   125,   296,    17,    18,    19,   197,
     184,   200,   203,    91,   202,    92,   223,   204,   391,   201,
     228,   105,   229,   232,  -177,   225,   250,   251,   226,   106,
     107,   227,   103,   104,   108,   109,   110,   132,   259,   194,
     195,   264,   260,   261,   271,  -176,   318,   321,   270,   320,
     -60,   144,   325,    49,    91,   303,    92,   326,   329,   332,
     335,   337,   218,   338,    47,    55,    49,   354,    58,   106,
     107,   249,   362,   363,   108,   109,   110,   297,   367,   372,
     144,   382,   144,   371,   387,   388,    91,   132,    92,   397,
     398,   403,   406,   404,     8,   407,   408,   409,   410,   411,
      47,    55,    49,   354,    58,   412,   414,   413,   416,   415,
     417,    16,    17,    18,    19,   144,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   263,    32,   381,
     383,   300,   144,   327,   125,   224,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   290,   291,   292,    98,   113,   273,   275,   278,   294,
     276,   258,   328,   277,    99,   100,   101,   102,    74,   279,
     165,    16,    17,    18,    19,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   133,    32,   234,
     305,   339,     0,   306,   390,     0,     0,     0,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,     0,   106,   107,     0,     0,     0,
     108,   109,   110,    99,   100,   101,   102,     0,     0,     0,
      16,    17,    18,    19,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   133,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
       0,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     233,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,   106,   107,     0,     0,     0,   108,
     109,   110,    99,   100,   101,   102,     0,     0,     0,    16,
      17,    18,    19,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   133,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,     0,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   253,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,   106,   107,     0,     0,     0,   108,   109,
     110,    99,   100,   101,   102,     0,     0,     0,    16,    17,
      18,    19,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   133,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,     0,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   309,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,     0,   106,   107,     0,     0,     0,   108,   109,   110,
      99,   100,   101,   102,     0,     0,     0,    16,    17,    18,
      19,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   133,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,     0,   135,   136,
     137,   138,   139,   140,     0,     0,   141,     0,   143,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,   106,   107,     0,     0,     0,   108,   109,   110,    99,
     100,   101,   102,     0,     0,     0,    16,    17,    18,    19,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,   133,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,   135,   136,   137,
     138,   139,   140,     0,     0,    73,     0,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,     0,
     106,   107,     0,     0,     0,   108,   109,   110,    99,   100,
     101,   102,     0,     0,     0,    16,    17,    18,    19,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   133,    32,     0,     0,     0,     0,    98,     0,     0,
       0,     0,   103,   104,     0,     0,     0,    99,   100,   101,
     102,     0,     0,     0,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,   106,
     107,   103,   104,     0,   108,   109,   110,    99,   100,   101,
     102,     0,     0,     0,    16,    17,    18,    19,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,     0,     0,     0,     0,    98,     0,   106,   107,
       0,   103,   104,   108,   109,   110,    99,   100,   101,   102,
       0,     0,     0,    16,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     8,
       9,    10,    11,    12,    13,    14,    15,     0,   106,   107,
     103,   104,     0,   108,   109,   110,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,   346,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,   108,   109,   110,   169,     8,     9,    10,    11,
      12,    13,     0,     0,   170,     0,    33,     0,     0,     0,
     171,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,     0,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,   246,     0,   170,     0,     0,
       0,     0,     0,   262,   352,   353,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    17,    18,    19,   380,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
      18,    19,   183,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,   265,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     8,     9,
      10,    11,    12,    13,     0,     0,   170,     0,     0,     0,
       0,     0,   171,     0,   373,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,    32,     8,     9,    10,    11,    12,    13,     0,
       0,   170,     0,     0,     0,     0,     0,     0,   352,   353,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     8,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,   235,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,     0,     0,     0,    16,    17,    18,    19,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32
};

static const yytype_int16 yycheck[] =
{
       6,     6,     6,     6,     6,    69,   110,    89,   152,   163,
      88,    49,   256,   346,     6,    16,   349,   350,    41,   320,
      77,    71,     6,   338,     6,    46,    47,     6,    77,    73,
       6,   185,    81,    77,   367,   139,     6,     7,    95,    77,
      72,    77,    74,    49,     3,    77,   379,    23,    24,    25,
      26,    57,    72,    57,    92,   356,   371,    80,    64,    95,
      64,     0,   395,   223,    85,    86,    74,    73,   312,    77,
      71,    77,    23,    24,    25,    26,    74,    83,    83,    83,
      78,    83,    88,    89,    88,    89,    92,   247,    72,   249,
     234,    75,    74,    72,    77,   199,    44,    45,   252,    74,
     182,   345,    94,    78,    89,    90,    91,   145,    50,    51,
     188,    75,    95,     6,   207,   208,   209,   210,   222,    48,
      49,   225,   226,    16,    17,    18,    19,    87,    88,   373,
      23,    24,    25,    26,    76,   141,    78,    74,    74,   145,
      77,    77,    74,    71,    75,    77,   152,    78,    74,    95,
      75,    77,    75,    78,    72,    78,   316,    50,    51,    72,
     166,    75,   166,    93,    78,   319,    96,   173,   173,   173,
     330,   173,    77,   333,    79,    78,   182,    72,   182,    73,
      74,    74,   188,     6,   188,    72,   346,   269,    70,   349,
     350,    70,   336,   257,    87,    88,   205,   206,     6,    92,
      93,    94,   266,   307,    28,    29,    30,   367,    16,    17,
      18,    19,   211,   212,    72,    23,    24,    25,    26,   379,
     226,   227,   226,    72,   226,   213,   214,     6,   234,     6,
       6,    77,   310,    74,    94,   395,    74,    76,     6,   393,
      73,    73,    50,    51,   388,     6,    75,    73,    16,    17,
      18,    19,    74,   317,    68,    23,    24,    25,    26,    79,
     342,    42,    83,   269,    82,   269,    94,    84,   372,    43,
      74,    79,    74,    74,     6,    94,    74,     6,    94,    87,
      88,    94,    50,    51,    92,    93,    94,   351,    71,   103,
     104,     6,    72,    71,     6,    94,     6,    15,    73,    72,
      94,   307,    74,   307,   310,   307,   310,    74,    74,    95,
      74,     6,   126,    95,   320,   320,   320,   320,   320,    87,
      88,    77,    75,     6,    92,    93,    94,    95,    75,    74,
     336,    75,   338,    95,    75,    63,   342,   401,   342,     6,
      18,    74,     6,    74,     6,    75,    19,    74,     6,    75,
     356,   356,   356,   356,   356,    16,     6,    74,    17,    75,
      74,    23,    24,    25,    26,   371,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,   173,    40,   356,
     361,   224,   388,   268,   198,   133,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,     6,    68,   198,   200,   203,   221,
     201,   166,    74,   202,    16,    17,    18,    19,    55,   204,
      77,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,   141,
     227,   307,    -1,   227,   371,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    64,    65,    66,    67,    68,    69,    -1,    -1,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    87,    88,    -1,    -1,    -1,
      92,    93,    94,    16,    17,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    64,    65,    66,    67,    68,    69,    -1,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    87,    88,    -1,    -1,    -1,    92,
      93,    94,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      64,    65,    66,    67,    68,    69,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    87,    88,    -1,    -1,    -1,    92,    93,
      94,    16,    17,    18,    19,    -1,    -1,    -1,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    64,
      65,    66,    67,    68,    69,    -1,    -1,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    87,    88,    -1,    -1,    -1,    92,    93,    94,
      16,    17,    18,    19,    -1,    -1,    -1,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    64,    65,
      66,    67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    87,    88,    -1,    -1,    -1,    92,    93,    94,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    64,    65,    66,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      87,    88,    -1,    -1,    -1,    92,    93,    94,    16,    17,
      18,    19,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    16,    17,    18,
      19,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    87,
      88,    50,    51,    -1,    92,    93,    94,    16,    17,    18,
      19,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    -1,    -1,    -1,     6,    -1,    87,    88,
      -1,    50,    51,    92,    93,    94,    16,    17,    18,    19,
      -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    87,    88,
      50,    51,    -1,    92,    93,    94,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    72,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      -1,    -1,    92,    93,    94,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    -1,    73,    -1,    -1,    -1,
      20,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    75,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    73,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    73,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    73,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     6,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,     6,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    28,
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
     116,   117,   122,   123,   124,   125,   126,   133,   134,   135,
     136,   137,   138,   139,   164,   165,   166,   167,   169,    71,
      75,    72,    72,     6,    72,     6,    72,    75,    78,   131,
     132,   133,   136,    72,   173,    95,   133,   135,   170,   171,
     172,     6,   168,    72,     6,     7,    70,    70,    72,   127,
     128,   133,   135,    72,     6,   118,   119,     6,     6,    16,
      17,    18,    19,    50,    51,    79,    87,    88,    92,    93,
      94,   133,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   160,
     161,   163,   132,    39,    62,    64,    65,    66,    67,    68,
      69,    72,    73,    74,   133,   135,   141,   153,   157,   158,
     165,   169,   174,   175,   176,   177,   178,   181,   182,   185,
     186,   187,   193,     6,   133,   172,    77,    74,    94,     5,
      14,    20,   100,   104,   105,   106,   111,   114,    74,    76,
      73,    73,   127,    73,   128,     6,   129,   130,   133,   118,
      75,    73,   118,    74,   153,   153,   157,    79,    41,    80,
      42,    43,    82,    83,    84,    44,    45,    46,    47,    85,
      86,    48,    49,    87,    88,    89,    90,    91,   153,    50,
      51,    76,    78,    94,   134,    94,    94,    94,    74,    74,
      74,   157,    74,    73,   174,     6,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    75,   159,    74,    77,
      74,     6,   179,    73,   175,    74,    77,   131,   171,    71,
      72,    71,    73,   105,     6,    73,   131,    74,    77,   127,
      73,     6,    95,   143,   157,   144,   145,   146,   147,   148,
     149,   149,   150,   150,   150,   150,   151,   151,   152,   152,
     153,   153,   153,     6,   160,   157,    23,    95,   158,   162,
     124,   157,   157,   169,   190,   178,   185,   189,    74,    73,
      72,    74,    77,   180,   158,   158,    75,   131,     6,   179,
      72,    15,   107,   108,   109,    74,    74,   130,    74,    74,
      81,    79,    95,    77,    95,    74,    95,     6,    95,   190,
     191,   192,   127,   179,    74,    77,    72,   158,   183,    75,
      75,   131,    21,    22,   100,   106,   112,   113,   120,   121,
      73,    74,    75,     6,   158,   158,   175,    75,   173,   177,
     188,    95,    74,    73,   179,   183,   184,   183,   183,    75,
      73,   113,    75,   108,    16,    71,   110,    75,    63,   183,
     188,   157,    74,   179,    73,    77,   183,     6,    18,   175,
      74,   131,   183,    74,    74,    74,     6,    75,    19,    74,
       6,    75,    16,    74,     6,    75,    17,    74
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
#line 2097 "gs.tab.c"
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


#line 626 "./gs.y"


