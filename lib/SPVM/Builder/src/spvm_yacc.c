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
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse SPVM_yyparse
#define yylex   SPVM_yylex
#define yyerror SPVM_yyerror
#define yylval  SPVM_yylval
#define yychar  SPVM_yychar
#define yydebug SPVM_yydebug
#define yynerrs SPVM_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PACKAGE = 258,
     HAS = 259,
     SUB = 260,
     OUR = 261,
     ENUM = 262,
     MY = 263,
     SELF = 264,
     USE = 265,
     DESCRIPTOR = 266,
     IF = 267,
     UNLESS = 268,
     ELSIF = 269,
     ELSE = 270,
     FOR = 271,
     WHILE = 272,
     LAST = 273,
     NEXT = 274,
     SWITCH = 275,
     CASE = 276,
     DEFAULT = 277,
     EVAL = 278,
     NAME = 279,
     VAR_NAME = 280,
     CONSTANT = 281,
     PACKAGE_VAR_NAME = 282,
     EXCEPTION_VAR = 283,
     UNDEF = 284,
     VOID = 285,
     BYTE = 286,
     SHORT = 287,
     INT = 288,
     LONG = 289,
     FLOAT = 290,
     DOUBLE = 291,
     STRING = 292,
     OBJECT = 293,
     AMPERSAND = 294,
     DOT3 = 295,
     FATCAMMA = 296,
     RW = 297,
     RO = 298,
     WO = 299,
     BEGIN = 300,
     REQUIRE = 301,
     RETURN = 302,
     WEAKEN = 303,
     CROAK = 304,
     CURRENT_PACKAGE = 305,
     SPECIAL_ASSIGN = 306,
     ASSIGN = 307,
     COND_OR = 308,
     COND_AND = 309,
     BIT_XOR = 310,
     BIT_OR = 311,
     BIT_AND = 312,
     ISA = 313,
     REL = 314,
     SHIFT = 315,
     REMAINDER = 316,
     DIVIDE = 317,
     MULTIPLY = 318,
     CAST = 319,
     NEW = 320,
     LENGTH = 321,
     DEREF = 322,
     REF = 323,
     UMINUS = 324,
     SCALAR = 325,
     BIT_NOT = 326,
     COND_NOT = 327,
     DEC = 328,
     INC = 329,
     ARROW = 330
   };
#endif
/* Tokens.  */
#define PACKAGE 258
#define HAS 259
#define SUB 260
#define OUR 261
#define ENUM 262
#define MY 263
#define SELF 264
#define USE 265
#define DESCRIPTOR 266
#define IF 267
#define UNLESS 268
#define ELSIF 269
#define ELSE 270
#define FOR 271
#define WHILE 272
#define LAST 273
#define NEXT 274
#define SWITCH 275
#define CASE 276
#define DEFAULT 277
#define EVAL 278
#define NAME 279
#define VAR_NAME 280
#define CONSTANT 281
#define PACKAGE_VAR_NAME 282
#define EXCEPTION_VAR 283
#define UNDEF 284
#define VOID 285
#define BYTE 286
#define SHORT 287
#define INT 288
#define LONG 289
#define FLOAT 290
#define DOUBLE 291
#define STRING 292
#define OBJECT 293
#define AMPERSAND 294
#define DOT3 295
#define FATCAMMA 296
#define RW 297
#define RO 298
#define WO 299
#define BEGIN 300
#define REQUIRE 301
#define RETURN 302
#define WEAKEN 303
#define CROAK 304
#define CURRENT_PACKAGE 305
#define SPECIAL_ASSIGN 306
#define ASSIGN 307
#define COND_OR 308
#define COND_AND 309
#define BIT_XOR 310
#define BIT_OR 311
#define BIT_AND 312
#define ISA 313
#define REL 314
#define SHIFT 315
#define REMAINDER 316
#define DIVIDE 317
#define MULTIPLY 318
#define CAST 319
#define NEW 320
#define LENGTH 321
#define DEREF 322
#define REF 323
#define UMINUS 324
#define SCALAR 325
#define BIT_NOT 326
#define COND_NOT 327
#define DEC 328
#define INC 329
#define ARROW 330




/* Copy the first part of user declarations.  */
#line 5 "yacc/spvm_yacc.y"

  #include <stdio.h>
  
  #include "spvm_compiler.h"
  #include "spvm_yacc_util.h"
  #include "spvm_toke.h"
  #include "spvm_op.h"
  #include "spvm_dumper.h"
  #include "spvm_constant.h"
  #include "spvm_type.h"
  #include "spvm_block.h"
  #include "spvm_list.h"
  #include "spvm_package.h"


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 279 "spvm_yacc.tab.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1748

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  200
/* YYNRULES -- Number of states.  */
#define YYNSTATES  386

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      80,    86,     2,    61,    87,    62,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,    85,
       2,     2,     2,     2,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    81,     2,    88,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,     2,    84,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    64,    65,    66,    67,
      68,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    13,    17,    23,
      27,    28,    30,    33,    35,    37,    39,    41,    44,    46,
      48,    51,    55,    62,    65,    68,    72,    73,    75,    79,
      82,    84,    86,    90,    96,   103,   114,   125,   135,   148,
     149,   151,   153,   157,   161,   163,   167,   168,   170,   174,
     175,   177,   180,   182,   183,   185,   188,   190,   192,   194,
     196,   198,   200,   202,   204,   206,   208,   211,   214,   217,
     220,   224,   227,   231,   234,   237,   239,   249,   255,   261,
     265,   268,   274,   281,   288,   289,   292,   299,   303,   306,
     307,   309,   311,   313,   315,   317,   319,   321,   323,   325,
     327,   329,   331,   333,   335,   337,   339,   341,   343,   345,
     347,   349,   351,   353,   357,   359,   363,   366,   368,   371,
     374,   377,   380,   383,   386,   389,   393,   397,   401,   405,
     409,   413,   417,   421,   425,   429,   433,   437,   440,   443,
     449,   451,   455,   458,   462,   468,   473,   478,   483,   490,
     494,   501,   505,   511,   517,   522,   527,   530,   533,   536,
     541,   545,   551,   554,   557,   560,   565,   569,   573,   577,
     581,   584,   588,   593,   596,   598,   600,   602,   604,   606,
     608,   610,   612,   614,   616,   618,   620,   622,   624,   627,
     631,   635,   640,   645,   647,   649,   651,   653,   654,   656,
     660
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      90,     0,    -1,    91,    -1,    -1,    92,    -1,    92,    93,
      -1,    93,    -1,     3,   156,    94,    -1,     3,   156,    83,
     115,    94,    -1,    82,    95,    84,    -1,    -1,    96,    -1,
      96,    97,    -1,    97,    -1,   107,    -1,   108,    -1,   101,
      -1,   106,    85,    -1,    99,    -1,    98,    -1,    45,   128,
      -1,    10,   156,    85,    -1,    10,   156,    80,   163,    86,
      85,    -1,    46,   156,    -1,     7,   102,    -1,    82,   103,
      84,    -1,    -1,   104,    -1,   104,    87,   105,    -1,   104,
      87,    -1,   105,    -1,   162,    -1,   162,    52,    26,    -1,
       6,    27,    83,   115,   155,    -1,     4,   161,    83,   115,
     155,    85,    -1,   115,     5,   162,    83,   160,    80,   110,
     113,    86,   128,    -1,   115,     5,   162,    83,   160,    80,
     110,   113,    86,    85,    -1,   115,     5,    83,   160,    80,
     110,   113,    86,   128,    -1,    81,   111,    88,   115,     5,
      83,   160,    80,   110,   113,    86,   128,    -1,    -1,   111,
      -1,   114,    -1,   114,    87,   111,    -1,   111,    87,   112,
      -1,   112,    -1,   153,    83,   155,    -1,    -1,    40,    -1,
     153,    83,     9,    -1,    -1,   116,    -1,   116,    11,    -1,
      11,    -1,    -1,   118,    -1,   118,   119,    -1,   119,    -1,
     126,    -1,   120,    -1,   121,    -1,   128,    -1,   122,    -1,
     123,    -1,   124,    -1,   129,    -1,   125,    -1,   132,    85,
      -1,    18,    85,    -1,    19,    85,    -1,    47,    85,    -1,
      47,   132,    85,    -1,    49,    85,    -1,    49,   132,    85,
      -1,   145,    85,    -1,   146,    85,    -1,    85,    -1,    16,
      80,   131,    85,   131,    85,   131,    86,   128,    -1,    17,
      80,   131,    86,   128,    -1,    20,    80,   132,    86,   128,
      -1,    21,   132,    83,    -1,    22,    83,    -1,    12,    80,
     100,    86,   128,    -1,    12,    80,   131,    86,   128,   127,
      -1,    13,    80,   131,    86,   128,   127,    -1,    -1,    15,
     128,    -1,    14,    80,   131,    86,   128,   127,    -1,    82,
     117,    84,    -1,    23,   128,    -1,    -1,   133,    -1,   132,
      -1,   151,    -1,   153,    -1,    28,    -1,   154,    -1,    26,
      -1,    29,    -1,   143,    -1,   144,    -1,   142,    -1,   140,
      -1,   138,    -1,   139,    -1,   147,    -1,   148,    -1,   152,
      -1,   136,    -1,   134,    -1,   150,    -1,   149,    -1,   137,
      -1,   135,    -1,    80,   132,    86,    -1,    50,    -1,   133,
      87,   132,    -1,   133,    87,    -1,   132,    -1,    61,   132,
      -1,    62,   132,    -1,    75,   132,    -1,    78,   132,    -1,
     132,    78,    -1,    77,   132,    -1,   132,    77,    -1,   132,
      61,   132,    -1,   132,    62,   132,    -1,   132,    63,   132,
      -1,   132,    66,   132,    -1,   132,    65,   132,    -1,   132,
      64,   132,    -1,   132,    55,   132,    -1,   132,    39,   132,
      -1,   132,    56,   132,    -1,   132,    60,   132,    -1,   132,
      52,   132,    -1,   132,    51,   132,    -1,    68,   156,    -1,
      68,   159,    -1,    68,   158,    82,   130,    84,    -1,   109,
      -1,    81,   130,    88,    -1,   141,   132,    -1,    80,   155,
      86,    -1,   132,    79,    81,   132,    88,    -1,   142,    81,
     132,    88,    -1,   144,    81,   132,    88,    -1,    24,    80,
     130,    86,    -1,   156,    79,   162,    80,   130,    86,    -1,
     156,    79,   162,    -1,   132,    79,   162,    80,   130,    86,
      -1,   132,    79,   162,    -1,   132,    79,    80,   130,    86,
      -1,   132,    79,    82,   161,    84,    -1,   144,    82,   161,
      84,    -1,   142,    82,   161,    84,    -1,    48,   144,    -1,
      48,   142,    -1,    69,   132,    -1,    69,    82,   132,    84,
      -1,    74,    69,   132,    -1,    74,    69,    82,   132,    84,
      -1,    70,   132,    -1,    71,   153,    -1,    72,   153,    -1,
      72,    82,   153,    84,    -1,   132,    59,   132,    -1,   131,
      58,   155,    -1,   131,    53,   131,    -1,   131,    54,   131,
      -1,    76,   131,    -1,    80,   151,    86,    -1,     8,   153,
      83,   155,    -1,     8,   153,    -1,    25,    -1,    27,    -1,
     156,    -1,   158,    -1,   157,    -1,    24,    -1,    31,    -1,
      32,    -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,
      38,    -1,    37,    -1,   156,    39,    -1,   156,    81,    88,
      -1,   158,    81,    88,    -1,   156,    81,   132,    88,    -1,
     158,    81,   132,    88,    -1,   155,    -1,    30,    -1,    24,
      -1,    24,    -1,    -1,   164,    -1,   164,    87,   162,    -1,
     162,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    74,    77,    90,   104,   107,   111,   117,
     126,   129,   141,   155,   158,   159,   160,   161,   162,   163,
     166,   175,   179,   185,   192,   198,   207,   210,   223,   237,
     241,   244,   248,   254,   260,   266,   270,   276,   280,   296,
     299,   310,   318,   337,   351,   354,   361,   364,   367,   378,
     381,   394,   408,   412,   415,   428,   442,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   458,   459,   460,
     464,   468,   472,   476,   477,   478,   484,   490,   496,   502,
     508,   511,   519,   530,   544,   547,   551,   557,   565,   572,
     575,   588,   589,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   616,   619,   633,   637,   643,   648,
     653,   659,   664,   669,   674,   681,   686,   691,   695,   699,
     703,   707,   711,   715,   719,   725,   729,   735,   739,   743,
     747,   770,   777,   784,   790,   794,   798,   804,   808,   812,
     817,   821,   826,   832,   836,   840,   846,   852,   858,   863,
     868,   873,   880,   885,   891,   896,   903,   907,   911,   915,
     919,   923,   929,   933,   939,   945,   951,   952,   953,   956,
     960,   966,   972,   978,   984,   990,   996,  1002,  1010,  1016,
    1020,  1026,  1030,  1036,  1037,  1043,  1046,  1050,  1053,  1066,
    1080
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PACKAGE", "HAS", "SUB", "OUR", "ENUM",
  "MY", "SELF", "USE", "DESCRIPTOR", "IF", "UNLESS", "ELSIF", "ELSE",
  "FOR", "WHILE", "LAST", "NEXT", "SWITCH", "CASE", "DEFAULT", "EVAL",
  "NAME", "VAR_NAME", "CONSTANT", "PACKAGE_VAR_NAME", "EXCEPTION_VAR",
  "UNDEF", "VOID", "BYTE", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE",
  "STRING", "OBJECT", "AMPERSAND", "DOT3", "FATCAMMA", "RW", "RO", "WO",
  "BEGIN", "REQUIRE", "RETURN", "WEAKEN", "CROAK", "CURRENT_PACKAGE",
  "SPECIAL_ASSIGN", "ASSIGN", "COND_OR", "COND_AND", "BIT_XOR", "BIT_OR",
  "BIT_AND", "ISA", "REL", "SHIFT", "'+'", "'-'", "'.'", "REMAINDER",
  "DIVIDE", "MULTIPLY", "CAST", "NEW", "'@'", "LENGTH", "DEREF", "REF",
  "UMINUS", "SCALAR", "BIT_NOT", "COND_NOT", "DEC", "INC", "ARROW", "'('",
  "'['", "'{'", "':'", "'}'", "';'", "')'", "','", "']'", "$accept",
  "grammar", "opt_packages", "packages", "package", "package_block",
  "opt_declarations", "declarations", "declaration", "begin_block", "use",
  "require", "enumeration", "enumeration_block", "opt_enumeration_values",
  "enumeration_values", "enumeration_value", "our", "has", "sub",
  "anon_sub", "opt_args", "args", "arg", "opt_vaarg", "invocant",
  "opt_descriptors", "descriptors", "opt_statements", "statements",
  "statement", "for_statement", "while_statement", "switch_statement",
  "case_statement", "default_statement", "if_require_statement",
  "if_statement", "else_statement", "block", "eval_block",
  "opt_expression_terms", "term", "expression_term", "expression_terms",
  "unop", "incdec", "binop", "assign", "new", "array_init", "convert_type",
  "convert", "array_access", "call_sub", "field_access", "weaken_field",
  "weaken_array_element", "array_length", "string_length", "deref", "ref",
  "condition_term", "my_var", "var", "package_var_access", "type",
  "basic_type", "ref_type", "array_type", "array_type_with_length",
  "type_or_void", "field_name", "sub_name", "opt_sub_names", "sub_names", 0
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
     315,    43,    45,    46,   316,   317,   318,   319,   320,    64,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
      40,    91,   123,    58,   125,    59,    41,    44,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    93,    93,    94,
      95,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      98,    99,    99,   100,   101,   102,   103,   103,   104,   104,
     104,   105,   105,   106,   107,   108,   108,   109,   109,   110,
     110,   110,   110,   111,   111,   112,   113,   113,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   120,   121,   122,   123,
     124,   125,   126,   126,   127,   127,   127,   128,   129,   130,
     130,   131,   131,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   133,   133,   133,   134,   134,
     134,   135,   135,   135,   135,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   137,   137,   138,   138,   138,
     138,   139,   140,   141,   142,   142,   142,   143,   143,   143,
     143,   143,   143,   144,   144,   144,   145,   146,   147,   147,
     147,   147,   148,   149,   150,   150,   151,   151,   151,   151,
     151,   151,   152,   152,   153,   154,   155,   155,   155,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   157,   158,
     158,   159,   159,   160,   160,   161,   162,   163,   163,   164,
     164
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     3,     5,     3,
       0,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       2,     3,     6,     2,     2,     3,     0,     1,     3,     2,
       1,     1,     3,     5,     6,    10,    10,     9,    12,     0,
       1,     1,     3,     3,     1,     3,     0,     1,     3,     0,
       1,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     2,     3,     2,     2,     1,     9,     5,     5,     3,
       2,     5,     6,     6,     0,     2,     6,     3,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     5,
       1,     3,     2,     3,     5,     4,     4,     4,     6,     3,
       6,     3,     5,     5,     4,     4,     2,     2,     2,     4,
       3,     5,     2,     2,     2,     4,     3,     3,     3,     3,
       2,     3,     4,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     4,     4,     1,     1,     1,     1,     0,     1,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     4,     6,   179,   180,   181,   182,
     183,   184,   185,   187,   186,     0,     1,     5,    10,    49,
       7,     0,     0,     0,     0,    52,     0,     0,    11,    13,
      19,    18,    16,     0,    14,    15,     0,    50,     0,   195,
       0,     0,    26,    24,     0,    49,    20,     9,    12,    17,
       0,    51,     8,    49,    49,   196,     0,    27,    30,    31,
     197,    21,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,   179,   174,    96,   175,    94,    97,    49,
      49,    49,   114,    49,    49,     0,    49,    49,     0,     0,
       0,    49,    49,    49,    49,    49,    75,   140,     0,     0,
      49,    56,    58,    59,    61,    62,    63,    65,    57,    60,
      64,     0,   108,   112,   107,   111,   102,   103,   101,    49,
     100,    98,    99,     0,     0,   104,   105,   110,   109,   106,
      93,    95,     0,     0,     0,     0,    25,    29,     0,   200,
       0,   198,   173,    49,    49,    49,    49,    67,    68,    49,
       0,    80,    88,    49,    69,     0,     0,   100,    99,    71,
       0,   118,   119,   137,     0,   138,    49,   158,   162,   163,
       0,   164,    49,   120,   123,   121,     0,     0,   176,   178,
     177,     0,    44,     0,   117,    90,    93,     0,    87,    55,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,   124,   122,     0,    66,   142,    49,     0,    49,
       0,    73,    74,     0,     0,     0,   176,    33,    28,    32,
       0,     0,     0,     0,    49,    49,     0,     0,    91,    92,
       0,     0,     0,     0,    79,     0,    70,    72,    49,    49,
      49,     0,     0,    49,   160,   113,   143,   188,     0,     0,
       0,    49,   141,   116,     0,     0,   132,   136,   135,   131,
     133,   134,   125,   126,   127,   130,   129,   128,    49,    49,
       0,   151,     0,     0,     0,     0,   149,   194,   193,     0,
      34,    22,   199,   172,    23,   170,     0,    91,    92,     0,
      49,    49,     0,     0,    49,     0,    49,     0,     0,   147,
     189,     0,   190,     0,     0,   159,   165,     0,    43,     0,
       0,   115,    45,     0,     0,     0,     0,    49,   145,   155,
     146,   154,    49,    39,   171,    81,   168,   169,   167,    84,
     166,    84,     0,    77,    78,   191,   192,   139,   161,     0,
      39,   152,   144,   153,     0,     0,    46,    40,    41,     0,
       0,     0,    82,    83,    49,     0,    46,   150,   148,    47,
       0,     0,     0,    49,    85,     0,     0,     0,     0,    42,
      48,     0,     0,    39,     0,    36,    35,     0,    76,    46,
      37,    84,     0,    86,     0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    20,    27,    28,    29,    30,
      31,   226,    32,    43,    56,    57,    58,    33,    34,    35,
      97,   346,   347,   182,   360,   348,    98,    37,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   352,   109,
     110,   183,   227,   228,   185,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   229,   129,   130,   131,   278,   132,   179,   180,
     165,   279,    40,    59,   140,   141
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -347
static const yytype_int16 yypact[] =
{
      27,   511,    34,  -347,    27,  -347,  -347,  -347,  -347,  -347,
    -347,  -347,  -347,  -347,  -347,   -57,  -347,  -347,    91,    43,
    -347,    38,    44,    -9,   511,  -347,    -7,    -4,    91,  -347,
    -347,  -347,  -347,    14,  -347,  -347,    98,   109,    47,  -347,
      52,    54,   102,  -347,   -58,   562,  -347,  -347,  -347,  -347,
     102,  -347,  -347,    43,    43,  -347,    74,    55,  -347,   100,
     102,  -347,   130,    94,    96,   108,   111,    93,   110,   116,
    1237,   118,    -7,   128,  -347,  -347,  -347,  -347,  -347,   702,
    1237,   767,  -347,  1237,  1237,   511,   965,  1237,   130,    -6,
     114,  1237,  1237,  1237,  1237,   296,  -347,  -347,   209,   132,
     637,  -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,  -347,
    -347,  1458,  -347,  -347,  -347,  -347,  -347,  -347,  -347,  1237,
     -33,  -347,    30,   134,   135,  -347,  -347,  -347,  -347,  -347,
    -347,  -347,   144,   159,   511,   511,  -347,   102,   208,  -347,
     163,   164,   172,  1095,  1166,  1166,  1166,  -347,  -347,  1237,
    1611,  -347,  -347,   491,  -347,  1489,  1669,    42,    58,  -347,
    1520,     4,     4,   169,   112,  -347,  1237,     4,     4,  -347,
     130,  -347,  1030,     4,    68,    68,  1400,   170,    -2,  -347,
     179,    62,  -347,   173,  1669,   178,   184,   191,  -347,  -347,
    1237,  1237,  1237,  1237,  1237,  1237,  1237,  1237,  1237,  1237,
    1237,  1237,  -347,  -347,   -12,  -347,     4,  1237,    38,  1237,
      38,  -347,  -347,   102,   447,   190,   -24,  -347,  -347,  -347,
     192,   102,   511,   511,  1166,  1166,   201,    36,  1640,  -347,
     103,   151,   149,  1429,  -347,   206,  -347,  -347,   361,   426,
     832,  1551,   211,  1237,     4,  -347,  -347,  -347,   188,   205,
     130,    43,  -347,   900,   511,   447,   167,  1669,  1669,   167,
     167,   220,   121,   121,   121,     4,     4,     4,   491,  1237,
      38,   198,    53,   212,  1271,   216,   222,  -347,  -347,   223,
    -347,  -347,  -347,  -347,  -347,  -347,    -8,  1371,   219,    -7,
    1166,  1166,   511,    -7,  1237,    -7,  1166,    -7,    -7,  -347,
    -347,  1291,  -347,  1321,   224,  -347,  -347,  1581,  -347,   184,
     301,  1669,  -347,   229,   225,  1341,   226,   491,  -347,  -347,
    -347,  -347,   491,   130,  -347,  -347,   -22,   254,  -347,    71,
    1669,    71,   194,  -347,  -347,  -347,  -347,  -347,  -347,   231,
     130,  -347,  -347,  -347,   230,   232,   275,   248,   249,   234,
     239,    -7,  -347,  -347,  1166,   447,   275,  -347,  -347,  -347,
     251,   130,   382,  1166,  -347,   185,   258,   253,   -44,   248,
    -347,   204,    -7,   130,    -7,  -347,  -347,    -7,  -347,   275,
    -347,    71,   255,  -347,    -7,  -347
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -347,  -347,  -347,  -347,   336,   304,  -347,  -347,   316,  -347,
    -347,  -347,  -347,  -347,  -347,  -347,   213,  -347,  -347,  -347,
    -347,  -329,   -92,    95,  -346,  -347,   -14,  -347,  -347,  -347,
     256,  -347,  -347,  -347,  -347,  -347,  -347,  -347,  -307,   -25,
    -347,  -140,  -137,   -28,  -347,  -347,  -347,  -347,  -347,  -347,
    -347,  -347,  -347,   268,  -347,   271,  -347,  -347,  -347,  -347,
    -347,  -347,   137,  -347,   -60,  -347,   -74,    -1,  -347,   270,
    -347,  -249,  -192,   -29,  -347,  -347
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -158
static const yytype_int16 yytable[] =
{
      15,    46,   142,   181,    36,    38,   313,   230,   231,   232,
     367,   356,    55,   235,    36,   247,   273,   111,   275,    74,
     177,   133,    60,    44,   353,    18,    19,    61,   169,   171,
       1,   139,   291,   382,    16,   186,   292,   247,    45,   134,
     135,   375,   150,   190,   379,   290,   291,   152,   207,   208,
     292,   155,   156,   160,    25,   161,   162,   248,   167,   168,
     215,   217,    39,   173,   174,   175,   176,   184,   268,   269,
     270,    41,   111,    42,   383,    45,   170,   213,   316,   248,
      47,   202,   203,   204,   163,   350,   351,   285,   286,   290,
     291,   206,   190,   178,   292,    21,   -49,    22,    23,    49,
     304,    24,    25,    50,   191,   192,   366,   190,   193,   194,
     242,   209,   210,   195,   196,   197,   198,   199,   200,   201,
      51,   233,   293,   207,   208,   184,    55,  -157,   314,    18,
     202,   203,   204,   216,   216,    53,    26,    54,   241,   209,
     210,   318,   137,  -156,   244,  -158,  -158,   204,   283,   250,
     251,   177,   138,   326,   327,    74,   290,   291,   136,   332,
     190,   292,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   143,   271,   144,   344,   147,   272,
     312,   274,   345,   172,   276,   199,   200,   201,   145,   295,
     309,   146,   282,   239,   240,   148,   149,   287,   202,   203,
     204,   151,   290,   291,   290,   291,   190,   292,   153,   292,
     301,   303,   184,   216,   187,   307,   188,   365,   328,   211,
     212,   216,   284,   213,   178,   311,   371,   195,   196,   197,
     198,   199,   200,   201,   219,   297,   296,   310,   290,   291,
     184,   315,   214,   292,   202,   203,   204,   290,   291,   220,
     238,   221,   292,   216,   216,   222,   246,   290,   291,   190,
     249,   252,   292,   349,   325,   253,   330,   254,   329,   369,
     331,   372,   333,   334,   255,   280,   300,   281,   317,   354,
     349,   196,   197,   198,   199,   200,   201,   289,   312,   184,
     377,   216,   299,   302,   184,   306,   319,   202,   203,   204,
     321,   309,   322,   323,    62,   324,   339,    25,   337,   340,
     343,   341,   292,   349,   355,   359,   357,   362,   358,   363,
      73,    74,    75,    76,    77,    78,   364,     7,     8,     9,
      10,    11,    12,    13,    14,   250,   361,   368,   373,   374,
      17,   384,    52,   376,    48,   308,    82,   378,   157,   380,
     218,   158,   381,     0,   216,   164,   189,    83,    84,   385,
       0,   216,   288,     0,    85,    86,    87,    88,    89,    62,
      90,    91,    25,    92,    93,     0,    94,    95,     0,     0,
       0,     0,     0,     0,   -89,    73,    74,    75,    76,    77,
      78,   370,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     6,     0,     0,     0,
       0,    82,     0,     7,     8,     9,    10,    11,    12,    13,
      14,     0,    83,    84,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    62,    90,    91,    25,    92,    93,
       0,    94,    95,     0,     0,     0,     0,     0,     0,   300,
      73,    74,    75,    76,    77,    78,     0,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     0,    82,   277,     7,     8,
       9,    10,    11,    12,    13,    14,     0,    83,    84,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    62,
      90,    91,    25,    92,    93,     0,    94,    95,     0,     0,
       0,     0,     0,     0,   302,    73,    74,    75,    76,    77,
      78,     0,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,    82,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,    83,    84,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,     0,    90,    91,     0,    92,    93,
      62,    94,    95,    25,    63,    64,     0,   -89,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,    90,    91,     0,    92,
      93,     0,    94,    95,    45,    62,   -53,    96,    25,    63,
      64,     0,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      62,    90,    91,    25,    92,    93,     0,    94,    95,    45,
       0,   -54,    96,     0,     0,     0,    73,    74,    75,    76,
      77,    78,     0,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    62,    90,    91,    25,    92,
      93,     0,    94,    95,     0,     0,     0,   154,     0,     0,
       0,    73,    74,    75,    76,    77,    78,     0,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      62,    90,    91,    25,    92,    93,     0,    94,    95,     0,
       0,     0,   159,     0,     0,     0,    73,    74,    75,    76,
      77,    78,     0,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,   -49,    90,    91,    62,    92,
      93,    25,    94,    95,     0,     0,   -89,     0,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,    77,    78,
       0,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    62,    90,    91,    25,    92,    93,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,     0,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    62,    90,
      91,    25,    92,    93,     0,    94,    95,   166,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,    77,    78,
       0,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    62,    90,    91,    25,    92,    93,     0,
      94,    95,   243,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,     0,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,     0,     0,
       0,   223,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,     0,    90,
      91,   224,    92,    93,    62,   225,    95,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,     0,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    84,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,     0,
      90,    91,   224,    92,    93,    62,   225,    95,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    78,     0,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
     190,    90,    91,     0,    92,    93,     0,    94,    95,     0,
       0,     0,   191,   192,     0,     0,   193,   194,     0,     0,
     190,   195,   196,   197,   198,   199,   200,   201,     0,     0,
       0,     0,   191,   192,     0,     0,   193,   194,   202,   203,
     204,   195,   196,   197,   198,   199,   200,   201,     0,   320,
     190,     0,     0,     0,     0,     0,     0,     0,   202,   203,
     204,     0,   191,   192,     0,     0,   193,   194,     0,   335,
     190,   195,   196,   197,   198,   199,   200,   201,     0,     0,
       0,     0,   191,   192,     0,     0,   193,   194,   202,   203,
     204,   195,   196,   197,   198,   199,   200,   201,     0,   336,
     190,     0,     0,     0,     0,     0,     0,     0,   202,   203,
     204,     0,   191,   192,     0,     0,   193,   194,     0,   342,
     294,   195,   196,   197,   198,   199,   200,   201,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,   202,   203,
     204,   191,   192,     0,     0,   193,   194,   245,     0,     0,
     195,   196,   197,   198,   199,   200,   201,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   203,   204,
     191,   192,     0,     0,   193,   194,   245,     0,     0,   195,
     196,   197,   198,   199,   200,   201,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,   202,   203,   204,   191,
     192,     0,     0,   193,   194,   298,     0,     0,   195,   196,
     197,   198,   199,   200,   201,     0,     0,     0,   190,     0,
       0,     0,     0,     0,     0,   202,   203,   204,     0,     0,
     191,   192,     0,   205,   193,   194,     0,     0,     0,   195,
     196,   197,   198,   199,   200,   201,     0,     0,     0,   190,
       0,     0,     0,     0,     0,     0,   202,   203,   204,     0,
       0,   191,   192,     0,   236,   193,   194,     0,     0,     0,
     195,   196,   197,   198,   199,   200,   201,     0,     0,     0,
     190,     0,     0,     0,     0,     0,     0,   202,   203,   204,
       0,     0,   191,   192,     0,   237,   193,   194,     0,     0,
       0,   195,   196,   197,   198,   199,   200,   201,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,   202,   203,
     204,     0,   191,   192,     0,   305,   193,   194,     0,     0,
       0,   195,   196,   197,   198,   199,   200,   201,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,   202,   203,
     204,     0,   191,   192,     0,   338,   193,   194,     0,     0,
       0,   195,   196,   197,   198,   199,   200,   201,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,   202,   203,
     204,   191,   192,     0,   234,   193,   194,     0,     0,   294,
     195,   196,   197,   198,   199,   200,   201,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   203,   204,
     191,   192,     0,     0,   193,   194,     0,     0,     0,   195,
     196,   197,   198,   199,   200,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   202,   203,   204
};

static const yytype_int16 yycheck[] =
{
       1,    26,    62,    95,    18,    19,   255,   144,   145,   146,
     356,   340,    24,   153,    28,    39,   208,    45,   210,    25,
      94,    50,    80,    24,   331,    82,    83,    85,    88,    89,
       3,    60,    54,   379,     0,    95,    58,    39,    82,    53,
      54,    85,    70,    39,   373,    53,    54,    72,    81,    82,
      58,    79,    80,    81,    11,    83,    84,    81,    86,    87,
     134,   135,    24,    91,    92,    93,    94,    95,    80,    81,
      82,    27,   100,    82,   381,    82,    82,    79,   270,    81,
      84,    77,    78,    79,    85,    14,    15,   224,   225,    53,
      54,   119,    39,    94,    58,     4,     5,     6,     7,    85,
     240,    10,    11,     5,    51,    52,   355,    39,    55,    56,
     170,    81,    82,    60,    61,    62,    63,    64,    65,    66,
      11,   149,    86,    81,    82,   153,    24,    85,   268,    82,
      77,    78,    79,   134,   135,    83,    45,    83,   166,    81,
      82,    88,    87,    85,   172,    77,    78,    79,   222,    87,
      88,   225,    52,   290,   291,    25,    53,    54,    84,   296,
      39,    58,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,    80,   204,    80,   317,    85,   207,
     254,   209,   322,    69,   213,    64,    65,    66,    80,    86,
     250,    80,   221,    81,    82,    85,    80,   225,    77,    78,
      79,    83,    53,    54,    53,    54,    39,    58,    80,    58,
     238,   239,   240,   214,     5,   243,    84,   354,   292,    85,
      85,   222,   223,    79,   225,   253,   363,    60,    61,    62,
      63,    64,    65,    66,    26,    86,    85,   251,    53,    54,
     268,   269,    83,    58,    77,    78,    79,    53,    54,    86,
      81,    87,    58,   254,   255,    83,    86,    53,    54,    39,
      81,    88,    58,   323,   289,    87,   294,    83,   293,   361,
     295,    86,   297,   298,    83,    85,    88,    85,    80,    85,
     340,    61,    62,    63,    64,    65,    66,    86,   362,   317,
      86,   292,    86,    88,   322,    84,    84,    77,    78,    79,
      84,   361,    80,    80,     8,    86,     5,    11,    84,    80,
      84,    86,    58,   373,    83,    40,    86,    83,    86,    80,
      24,    25,    26,    27,    28,    29,   351,    31,    32,    33,
      34,    35,    36,    37,    38,    87,    87,    86,    80,    86,
       4,    86,    38,   368,    28,   250,    50,   372,    80,   374,
     137,    80,   377,    -1,   355,    85,   100,    61,    62,   384,
      -1,   362,   225,    -1,    68,    69,    70,    71,    72,     8,
      74,    75,    11,    77,    78,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    24,    25,    26,    27,    28,
      29,     9,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    50,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,     8,    74,    75,    11,    77,    78,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    50,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,     8,
      74,    75,    11,    77,    78,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    50,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    -1,    74,    75,    -1,    77,    78,
       8,    80,    81,    11,    12,    13,    -1,    86,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    -1,    74,    75,    -1,    77,
      78,    -1,    80,    81,    82,     8,    84,    85,    11,    12,
      13,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
       8,    74,    75,    11,    77,    78,    -1,    80,    81,    82,
      -1,    84,    85,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,     8,    74,    75,    11,    77,
      78,    -1,    80,    81,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
       8,    74,    75,    11,    77,    78,    -1,    80,    81,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,     5,    74,    75,     8,    77,
      78,    11,    80,    81,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,     8,    74,    75,    11,    77,    78,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,     8,    74,
      75,    11,    77,    78,    -1,    80,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,     8,    74,    75,    11,    77,    78,    -1,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,     8,    80,    81,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,
      74,    75,    76,    77,    78,     8,    80,    81,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      39,    74,    75,    -1,    77,    78,    -1,    80,    81,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    -1,
      39,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    77,    78,
      79,    60,    61,    62,    63,    64,    65,    66,    -1,    88,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    88,
      39,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    56,    77,    78,
      79,    60,    61,    62,    63,    64,    65,    66,    -1,    88,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    51,    52,    -1,    -1,    55,    56,    -1,    88,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    51,    52,    -1,    -1,    55,    56,    86,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      51,    52,    -1,    -1,    55,    56,    86,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    51,
      52,    -1,    -1,    55,    56,    86,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      51,    52,    -1,    85,    55,    56,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    51,    52,    -1,    85,    55,    56,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    51,    52,    -1,    85,    55,    56,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    51,    52,    -1,    84,    55,    56,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    51,    52,    -1,    84,    55,    56,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    51,    52,    -1,    83,    55,    56,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      51,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    90,    91,    92,    93,    24,    31,    32,    33,
      34,    35,    36,    37,    38,   156,     0,    93,    82,    83,
      94,     4,     6,     7,    10,    11,    45,    95,    96,    97,
      98,    99,   101,   106,   107,   108,   115,   116,   115,    24,
     161,    27,    82,   102,   156,    82,   128,    84,    97,    85,
       5,    11,    94,    83,    83,    24,   103,   104,   105,   162,
      80,    85,     8,    12,    13,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    47,
      48,    49,    50,    61,    62,    68,    69,    70,    71,    72,
      74,    75,    77,    78,    80,    81,    85,   109,   115,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   128,
     129,   132,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   152,
     153,   154,   156,   162,   115,   115,    84,    87,    52,   162,
     163,   164,   153,    80,    80,    80,    80,    85,    85,    80,
     132,    83,   128,    80,    85,   132,   132,   142,   144,    85,
     132,   132,   132,   156,   158,   159,    82,   132,   132,   153,
      82,   153,    69,   132,   132,   132,   132,   155,   156,   157,
     158,   111,   112,   130,   132,   133,   153,     5,    84,   119,
      39,    51,    52,    55,    56,    60,    61,    62,    63,    64,
      65,    66,    77,    78,    79,    85,   132,    81,    82,    81,
      82,    85,    85,    79,    83,   155,   156,   155,   105,    26,
      86,    87,    83,    46,    76,    80,   100,   131,   132,   151,
     131,   131,   131,   132,    83,   130,    85,    85,    81,    81,
      82,   132,   153,    82,   132,    86,    86,    39,    81,    81,
      87,    88,    88,    87,    83,    83,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,    80,    81,
      82,   162,   132,   161,   132,   161,   162,    30,   155,   160,
      85,    85,   162,   155,   156,   131,   131,   132,   151,    86,
      53,    54,    58,    86,    59,    86,    85,    86,    86,    86,
      88,   132,    88,   132,   130,    84,    84,   132,   112,   153,
     115,   132,   155,   160,   130,   132,   161,    80,    88,    84,
      88,    84,    80,    80,    86,   128,   131,   131,   155,   128,
     132,   128,   131,   128,   128,    88,    88,    84,    84,     5,
      80,    86,    88,    84,   130,   130,   110,   111,   114,   153,
      14,    15,   127,   127,    85,    83,   110,    86,    86,    40,
     113,    87,    83,    80,   128,   131,   160,   113,    86,   111,
       9,   131,    86,    80,    86,    85,   128,    86,   128,   110,
     128,   128,   113,   127,    86,   128
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
      yyerror (compiler, YY_("syntax error: cannot back up")); \
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
# if YYLTYPE_IS_TRIVIAL
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, compiler)
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
		  Type, Value, compiler); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, SPVM_COMPILER* compiler)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, compiler)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    SPVM_COMPILER* compiler;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (compiler);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, SPVM_COMPILER* compiler)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, compiler)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    SPVM_COMPILER* compiler;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, compiler);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, SPVM_COMPILER* compiler)
#else
static void
yy_reduce_print (yyvsp, yyrule, compiler)
    YYSTYPE *yyvsp;
    int yyrule;
    SPVM_COMPILER* compiler;
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
		       		       , compiler);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, compiler); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, SPVM_COMPILER* compiler)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, compiler)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    SPVM_COMPILER* compiler;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (compiler);

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
int yyparse (SPVM_COMPILER* compiler);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






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
yyparse (SPVM_COMPILER* compiler)
#else
int
yyparse (compiler)
    SPVM_COMPILER* compiler;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

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
        case 2:
#line 67 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_grammar(compiler, (yyvsp[(1) - (1)].opval));
      compiler->op_grammar = (yyval.opval);
    ;}
    break;

  case 3:
#line 74 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 4:
#line 78 "yacc/spvm_yacc.y"
    {
      if ((yyvsp[(1) - (1)].opval)->id == SPVM_OP_C_ID_LIST) {
        (yyval.opval) = (yyvsp[(1) - (1)].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (1)].opval));
        (yyval.opval) = op_list;
      }
    ;}
    break;

  case 5:
#line 91 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_list;
      if ((yyvsp[(1) - (2)].opval)->id == SPVM_OP_C_ID_LIST) {
        op_list = (yyvsp[(1) - (2)].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (2)].opval)->file, (yyvsp[(1) - (2)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (2)].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(2) - (2)].opval));
      
      (yyval.opval) = op_list;
    ;}
    break;

  case 7:
#line 108 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_package(compiler, (yyvsp[(1) - (3)].opval), (yyvsp[(2) - (3)].opval), (yyvsp[(3) - (3)].opval), NULL);
    ;}
    break;

  case 8:
#line 112 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_package(compiler, (yyvsp[(1) - (5)].opval), (yyvsp[(2) - (5)].opval), (yyvsp[(5) - (5)].opval), (yyvsp[(4) - (5)].opval));
    ;}
    break;

  case 9:
#line 118 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_class_block = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_CLASS_BLOCK, (yyvsp[(1) - (3)].opval)->file, (yyvsp[(1) - (3)].opval)->line);
      SPVM_OP_insert_child(compiler, op_class_block, op_class_block->last, (yyvsp[(2) - (3)].opval));
      (yyval.opval) = op_class_block;
    ;}
    break;

  case 10:
#line 126 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 11:
#line 130 "yacc/spvm_yacc.y"
    {
      if ((yyvsp[(1) - (1)].opval)->id == SPVM_OP_C_ID_LIST) {
        (yyval.opval) = (yyvsp[(1) - (1)].opval);
      }
      else {
        (yyval.opval) = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
        SPVM_OP_insert_child(compiler, (yyval.opval), (yyval.opval)->last, (yyvsp[(1) - (1)].opval));
      }
    ;}
    break;

  case 12:
#line 142 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_list;
      if ((yyvsp[(1) - (2)].opval)->id == SPVM_OP_C_ID_LIST) {
        op_list = (yyvsp[(1) - (2)].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (2)].opval)->file, (yyvsp[(1) - (2)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (2)].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(2) - (2)].opval));
      
      (yyval.opval) = op_list;
    ;}
    break;

  case 20:
#line 167 "yacc/spvm_yacc.y"
    { 
      SPVM_OP* op_sub = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_SUB, compiler->cur_file, compiler->cur_line);
      SPVM_OP* op_sub_name = SPVM_OP_new_op_name(compiler, "BEGIN", compiler->cur_file, compiler->cur_line);
      SPVM_OP* op_void_type = SPVM_OP_new_op_void_type(compiler, compiler->cur_file, compiler->cur_line);
      (yyval.opval) = SPVM_OP_build_sub(compiler, op_sub, op_sub_name, op_void_type, NULL, NULL, (yyvsp[(2) - (2)].opval), NULL, NULL, 1);
    ;}
    break;

  case 21:
#line 176 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_use(compiler, (yyvsp[(1) - (3)].opval), (yyvsp[(2) - (3)].opval), NULL, 0);
    ;}
    break;

  case 22:
#line 180 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_use(compiler, (yyvsp[(1) - (6)].opval), (yyvsp[(2) - (6)].opval), (yyvsp[(4) - (6)].opval), 0);
    ;}
    break;

  case 23:
#line 186 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_use = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_USE, compiler->cur_file, compiler->cur_line);
      (yyval.opval) = SPVM_OP_build_use(compiler, op_use, (yyvsp[(2) - (2)].opval), NULL, 1);
    ;}
    break;

  case 24:
#line 193 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_enumeration(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 25:
#line 199 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_enum_block = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ENUM_BLOCK, (yyvsp[(1) - (3)].opval)->file, (yyvsp[(1) - (3)].opval)->line);
      SPVM_OP_insert_child(compiler, op_enum_block, op_enum_block->last, (yyvsp[(2) - (3)].opval));
      (yyval.opval) = op_enum_block;
    ;}
    break;

  case 26:
#line 207 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 27:
#line 211 "yacc/spvm_yacc.y"
    {
      if ((yyvsp[(1) - (1)].opval)->id == SPVM_OP_C_ID_LIST) {
        (yyval.opval) = (yyvsp[(1) - (1)].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (1)].opval));
        (yyval.opval) = op_list;
      }
    ;}
    break;

  case 28:
#line 224 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_list;
      if ((yyvsp[(1) - (3)].opval)->id == SPVM_OP_C_ID_LIST) {
        op_list = (yyvsp[(1) - (3)].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (3)].opval)->file, (yyvsp[(1) - (3)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (3)].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(3) - (3)].opval));
      
      (yyval.opval) = op_list;
    ;}
    break;

  case 29:
#line 238 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = (yyvsp[(1) - (2)].opval);
    ;}
    break;

  case 31:
#line 245 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_enumeration_value(compiler, (yyvsp[(1) - (1)].opval), NULL);
    ;}
    break;

  case 32:
#line 249 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_enumeration_value(compiler, (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 33:
#line 255 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_our(compiler, (yyvsp[(1) - (5)].opval), (yyvsp[(2) - (5)].opval), (yyvsp[(4) - (5)].opval), (yyvsp[(5) - (5)].opval));
    ;}
    break;

  case 34:
#line 261 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_has(compiler, (yyvsp[(1) - (6)].opval), (yyvsp[(2) - (6)].opval), (yyvsp[(4) - (6)].opval), (yyvsp[(5) - (6)].opval));
    ;}
    break;

  case 35:
#line 267 "yacc/spvm_yacc.y"
    {
       (yyval.opval) = SPVM_OP_build_sub(compiler, (yyvsp[(2) - (10)].opval), (yyvsp[(3) - (10)].opval), (yyvsp[(5) - (10)].opval), (yyvsp[(7) - (10)].opval), (yyvsp[(1) - (10)].opval), (yyvsp[(10) - (10)].opval), NULL, (yyvsp[(8) - (10)].opval), 0);
     ;}
    break;

  case 36:
#line 271 "yacc/spvm_yacc.y"
    {
       (yyval.opval) = SPVM_OP_build_sub(compiler, (yyvsp[(2) - (10)].opval), (yyvsp[(3) - (10)].opval), (yyvsp[(5) - (10)].opval), (yyvsp[(7) - (10)].opval), (yyvsp[(1) - (10)].opval), NULL, NULL, (yyvsp[(8) - (10)].opval), 0);
     ;}
    break;

  case 37:
#line 277 "yacc/spvm_yacc.y"
    {
       (yyval.opval) = SPVM_OP_build_sub(compiler, (yyvsp[(2) - (9)].opval), NULL, (yyvsp[(4) - (9)].opval), (yyvsp[(6) - (9)].opval), (yyvsp[(1) - (9)].opval), (yyvsp[(9) - (9)].opval), NULL, (yyvsp[(7) - (9)].opval), 0);
     ;}
    break;

  case 38:
#line 281 "yacc/spvm_yacc.y"
    {
       SPVM_OP* op_list_args;
       if ((yyvsp[(2) - (12)].opval)->id == SPVM_OP_C_ID_LIST) {
         op_list_args = (yyvsp[(2) - (12)].opval);
       }
       else {
         op_list_args = SPVM_OP_new_op_list(compiler, (yyvsp[(2) - (12)].opval)->file, (yyvsp[(2) - (12)].opval)->line);
         SPVM_OP_insert_child(compiler, op_list_args, op_list_args->last, (yyvsp[(2) - (12)].opval));
       }
       
       (yyval.opval) = SPVM_OP_build_sub(compiler, (yyvsp[(5) - (12)].opval), NULL, (yyvsp[(7) - (12)].opval), (yyvsp[(9) - (12)].opval), (yyvsp[(4) - (12)].opval), (yyvsp[(12) - (12)].opval), op_list_args, (yyvsp[(10) - (12)].opval), 0);
     ;}
    break;

  case 39:
#line 296 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 40:
#line 300 "yacc/spvm_yacc.y"
    {
      if ((yyvsp[(1) - (1)].opval)->id == SPVM_OP_C_ID_LIST) {
        (yyval.opval) = (yyvsp[(1) - (1)].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (1)].opval));
        (yyval.opval) = op_list;
      }
    ;}
    break;

  case 41:
#line 311 "yacc/spvm_yacc.y"
    {
       // Add invocant to arguments
       SPVM_OP* op_args = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
       SPVM_OP_insert_child(compiler, op_args, op_args->last, (yyvsp[(1) - (1)].opval));
       
       (yyval.opval) = op_args;
    ;}
    break;

  case 42:
#line 319 "yacc/spvm_yacc.y"
    {
      // Add invocant to arguments
      SPVM_OP* op_args;
      if ((yyvsp[(3) - (3)].opval)->id == SPVM_OP_C_ID_LIST) {
        op_args = (yyvsp[(3) - (3)].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (3)].opval)->file, (yyvsp[(1) - (3)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(3) - (3)].opval));
        op_args = op_list;
      }
      
      SPVM_OP_insert_child(compiler, op_args, op_args->first, (yyvsp[(1) - (3)].opval));
       
      (yyval.opval) = op_args;
    ;}
    break;

  case 43:
#line 338 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_list;
      if ((yyvsp[(1) - (3)].opval)->id == SPVM_OP_C_ID_LIST) {
        op_list = (yyvsp[(1) - (3)].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (3)].opval)->file, (yyvsp[(1) - (3)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (3)].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(3) - (3)].opval));
      
      (yyval.opval) = op_list;
    ;}
    break;

  case 45:
#line 355 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_arg(compiler, (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 46:
#line 361 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = NULL;
    ;}
    break;

  case 48:
#line 368 "yacc/spvm_yacc.y"
    {
      SPVM_TYPE* type = SPVM_TYPE_new(compiler);
      type->is_self = 1;
      SPVM_OP* op_type = SPVM_OP_new_op_type(compiler, type, (yyvsp[(3) - (3)].opval)->file, (yyvsp[(3) - (3)].opval)->line);
      
      (yyval.opval) = SPVM_OP_build_arg(compiler, (yyvsp[(1) - (3)].opval), op_type);
    ;}
    break;

  case 49:
#line 378 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 50:
#line 382 "yacc/spvm_yacc.y"
    {
      if ((yyvsp[(1) - (1)].opval)->id == SPVM_OP_C_ID_LIST) {
        (yyval.opval) = (yyvsp[(1) - (1)].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (1)].opval));
        (yyval.opval) = op_list;
      }
    ;}
    break;

  case 51:
#line 395 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_list;
      if ((yyvsp[(1) - (2)].opval)->id == SPVM_OP_C_ID_LIST) {
        op_list = (yyvsp[(1) - (2)].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (2)].opval)->file, (yyvsp[(1) - (2)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (2)].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(2) - (2)].opval));
      
      (yyval.opval) = op_list;
    ;}
    break;

  case 53:
#line 412 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 54:
#line 416 "yacc/spvm_yacc.y"
    {
      if ((yyvsp[(1) - (1)].opval)->id == SPVM_OP_C_ID_LIST) {
        (yyval.opval) = (yyvsp[(1) - (1)].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (1)].opval));
        (yyval.opval) = op_list;
      }
    ;}
    break;

  case 55:
#line 429 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_list;
      if ((yyvsp[(1) - (2)].opval)->id == SPVM_OP_C_ID_LIST) {
        op_list = (yyvsp[(1) - (2)].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (2)].opval)->file, (yyvsp[(1) - (2)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (2)].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(2) - (2)].opval));
      
      (yyval.opval) = op_list;
    ;}
    break;

  case 66:
#line 455 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = (yyvsp[(1) - (2)].opval);
    ;}
    break;

  case 69:
#line 461 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_return(compiler, (yyvsp[(1) - (2)].opval), NULL);
    ;}
    break;

  case 70:
#line 465 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_return(compiler, (yyvsp[(1) - (3)].opval), (yyvsp[(2) - (3)].opval));
    ;}
    break;

  case 71:
#line 469 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_croak(compiler, (yyvsp[(1) - (2)].opval), NULL);
    ;}
    break;

  case 72:
#line 473 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_croak(compiler, (yyvsp[(1) - (3)].opval), (yyvsp[(2) - (3)].opval));
    ;}
    break;

  case 75:
#line 479 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_NULL, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 76:
#line 485 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_for_statement(compiler, (yyvsp[(1) - (9)].opval), (yyvsp[(3) - (9)].opval), (yyvsp[(5) - (9)].opval), (yyvsp[(7) - (9)].opval), (yyvsp[(9) - (9)].opval));
    ;}
    break;

  case 77:
#line 491 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_while_statement(compiler, (yyvsp[(1) - (5)].opval), (yyvsp[(3) - (5)].opval), (yyvsp[(5) - (5)].opval));
    ;}
    break;

  case 78:
#line 497 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_switch_statement(compiler, (yyvsp[(1) - (5)].opval), (yyvsp[(3) - (5)].opval), (yyvsp[(5) - (5)].opval));
    ;}
    break;

  case 79:
#line 503 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_case_statement(compiler, (yyvsp[(1) - (3)].opval), (yyvsp[(2) - (3)].opval));
    ;}
    break;

  case 81:
#line 512 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_if_require = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_IF_REQUIRE, compiler->cur_file, compiler->cur_line);
      
      (yyval.opval) = SPVM_OP_build_if_require_statement(compiler, op_if_require, (yyvsp[(3) - (5)].opval), (yyvsp[(5) - (5)].opval));
    ;}
    break;

  case 82:
#line 520 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_if = SPVM_OP_build_if_statement(compiler, (yyvsp[(1) - (6)].opval), (yyvsp[(3) - (6)].opval), (yyvsp[(5) - (6)].opval), (yyvsp[(6) - (6)].opval));
      
      // if is wraped with block to allow the following syntax
      //  if (my $var = 3) { ... }
      SPVM_OP* op_block = SPVM_OP_new_op_block(compiler, (yyvsp[(1) - (6)].opval)->file, (yyvsp[(1) - (6)].opval)->line);
      SPVM_OP_insert_child(compiler, op_block, op_block->last, op_if);
      
      (yyval.opval) = op_block;
    ;}
    break;

  case 83:
#line 531 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_if = SPVM_OP_build_if_statement(compiler, (yyvsp[(1) - (6)].opval), (yyvsp[(3) - (6)].opval), (yyvsp[(5) - (6)].opval), (yyvsp[(6) - (6)].opval));
      
      // if is wraped with block to allow the following syntax
      //  if (my $var = 3) { ... }
      SPVM_OP* op_block = SPVM_OP_new_op_block(compiler, (yyvsp[(1) - (6)].opval)->file, (yyvsp[(1) - (6)].opval)->line);
      SPVM_OP_insert_child(compiler, op_block, op_block->last, op_if);
      
      (yyval.opval) = op_block;
    ;}
    break;

  case 84:
#line 544 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_NULL, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 85:
#line 548 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = (yyvsp[(2) - (2)].opval);
    ;}
    break;

  case 86:
#line 552 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_if_statement(compiler, (yyvsp[(1) - (6)].opval), (yyvsp[(3) - (6)].opval), (yyvsp[(5) - (6)].opval), (yyvsp[(6) - (6)].opval));
    ;}
    break;

  case 87:
#line 558 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_block = SPVM_OP_new_op_block(compiler, (yyvsp[(1) - (3)].opval)->file, (yyvsp[(1) - (3)].opval)->line);
      SPVM_OP_insert_child(compiler, op_block, op_block->last, (yyvsp[(2) - (3)].opval));
      (yyval.opval) = op_block;
    ;}
    break;

  case 88:
#line 566 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_eval(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 89:
#line 572 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 90:
#line 576 "yacc/spvm_yacc.y"
    {
      if ((yyvsp[(1) - (1)].opval)->id == SPVM_OP_C_ID_LIST) {
        (yyval.opval) = (yyvsp[(1) - (1)].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (1)].opval));
        (yyval.opval) = op_list;
      }
    ;}
    break;

  case 113:
#line 613 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_single_parenthes_term(compiler, (yyvsp[(2) - (3)].opval));
    ;}
    break;

  case 115:
#line 620 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_list;
      if ((yyvsp[(1) - (3)].opval)->id == SPVM_OP_C_ID_LIST) {
        op_list = (yyvsp[(1) - (3)].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (3)].opval)->file, (yyvsp[(1) - (3)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (3)].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(3) - (3)].opval));
      
      (yyval.opval) = op_list;
    ;}
    break;

  case 116:
#line 634 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = (yyvsp[(1) - (2)].opval);
    ;}
    break;

  case 117:
#line 638 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = (yyvsp[(1) - (1)].opval);
    ;}
    break;

  case 118:
#line 644 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_PLUS, (yyvsp[(1) - (2)].opval)->file, (yyvsp[(1) - (2)].opval)->line);
      (yyval.opval) = SPVM_OP_build_unop(compiler, op, (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 119:
#line 649 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_negate = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_NEGATE, (yyvsp[(1) - (2)].opval)->file, (yyvsp[(1) - (2)].opval)->line);
      (yyval.opval) = SPVM_OP_build_unop(compiler, op_negate, (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 120:
#line 654 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_unop(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 121:
#line 660 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_PRE_INC, (yyvsp[(1) - (2)].opval)->file, (yyvsp[(1) - (2)].opval)->line);
      (yyval.opval) = SPVM_OP_build_incdec(compiler, op, (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 122:
#line 665 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_POST_INC, (yyvsp[(2) - (2)].opval)->file, (yyvsp[(2) - (2)].opval)->line);
      (yyval.opval) = SPVM_OP_build_incdec(compiler, op, (yyvsp[(1) - (2)].opval));
    ;}
    break;

  case 123:
#line 670 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_PRE_DEC, (yyvsp[(1) - (2)].opval)->file, (yyvsp[(1) - (2)].opval)->line);
      (yyval.opval) = SPVM_OP_build_incdec(compiler, op, (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 124:
#line 675 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_POST_DEC, (yyvsp[(2) - (2)].opval)->file, (yyvsp[(2) - (2)].opval)->line);
      (yyval.opval) = SPVM_OP_build_incdec(compiler, op, (yyvsp[(1) - (2)].opval));
    ;}
    break;

  case 125:
#line 682 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ADD, (yyvsp[(2) - (3)].opval)->file, (yyvsp[(2) - (3)].opval)->line);
      (yyval.opval) = SPVM_OP_build_binop(compiler, op, (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 126:
#line 687 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_SUBTRACT, (yyvsp[(2) - (3)].opval)->file, (yyvsp[(2) - (3)].opval)->line);
      (yyval.opval) = SPVM_OP_build_binop(compiler, op, (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 127:
#line 692 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_concat(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 128:
#line 696 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 129:
#line 700 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 130:
#line 704 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 131:
#line 708 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 132:
#line 712 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 133:
#line 716 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 134:
#line 720 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 135:
#line 726 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_assign(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 136:
#line 730 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_special_assign(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 137:
#line 736 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_new(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval), NULL);
    ;}
    break;

  case 138:
#line 740 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_new(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval), NULL);
    ;}
    break;

  case 139:
#line 744 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_new(compiler, (yyvsp[(1) - (5)].opval), (yyvsp[(2) - (5)].opval), (yyvsp[(4) - (5)].opval));
    ;}
    break;

  case 140:
#line 748 "yacc/spvm_yacc.y"
    {
      // Package
      SPVM_OP* op_package = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_PACKAGE, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      
      // Create class block
      SPVM_OP* op_class_block = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_CLASS_BLOCK, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      SPVM_OP* op_list_declarations = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
      SPVM_OP_insert_child(compiler, op_list_declarations, op_list_declarations->last, (yyvsp[(1) - (1)].opval));
      SPVM_OP_insert_child(compiler, op_class_block, op_class_block->last, op_list_declarations);
      
      // Build package
      SPVM_OP_build_package(compiler, op_package, NULL, op_class_block, NULL);

      // Type
      SPVM_OP* op_type = SPVM_OP_new_op_type(compiler, op_package->uv.package->op_type->uv.type, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      
      // New
      SPVM_OP* op_new = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_NEW, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      (yyval.opval) = SPVM_OP_build_new(compiler, op_new, op_type, NULL);
    ;}
    break;

  case 141:
#line 771 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_array_init = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ARRAY_INIT, compiler->cur_file, compiler->cur_line);
      (yyval.opval) = SPVM_OP_build_array_init(compiler, op_array_init, (yyvsp[(2) - (3)].opval));
    ;}
    break;

  case 142:
#line 778 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_convert = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_CONVERT, (yyvsp[(1) - (2)].opval)->file, (yyvsp[(1) - (2)].opval)->line);
      (yyval.opval) = SPVM_OP_build_convert(compiler, op_convert, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 143:
#line 785 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = (yyvsp[(2) - (3)].opval);
    ;}
    break;

  case 144:
#line 791 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_array_access(compiler, (yyvsp[(1) - (5)].opval), (yyvsp[(4) - (5)].opval));
    ;}
    break;

  case 145:
#line 795 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_array_access(compiler, (yyvsp[(1) - (4)].opval), (yyvsp[(3) - (4)].opval));
    ;}
    break;

  case 146:
#line 799 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_array_access(compiler, (yyvsp[(1) - (4)].opval), (yyvsp[(3) - (4)].opval));
    ;}
    break;

  case 147:
#line 805 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, NULL, (yyvsp[(1) - (4)].opval), (yyvsp[(3) - (4)].opval));
    ;}
    break;

  case 148:
#line 809 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, (yyvsp[(1) - (6)].opval), (yyvsp[(3) - (6)].opval), (yyvsp[(5) - (6)].opval));
    ;}
    break;

  case 149:
#line 813 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_expression_terms = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (3)].opval)->file, (yyvsp[(2) - (3)].opval)->line);
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval), op_expression_terms);
    ;}
    break;

  case 150:
#line 818 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, (yyvsp[(1) - (6)].opval), (yyvsp[(3) - (6)].opval), (yyvsp[(5) - (6)].opval));
    ;}
    break;

  case 151:
#line 822 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_expression_terms = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (3)].opval)->file, (yyvsp[(2) - (3)].opval)->line);
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval), op_expression_terms);
    ;}
    break;

  case 152:
#line 827 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_sub_name = SPVM_OP_new_op_name(compiler, "", (yyvsp[(2) - (5)].opval)->file, (yyvsp[(2) - (5)].opval)->line);
      (yyval.opval) = SPVM_OP_build_call_sub(compiler, (yyvsp[(1) - (5)].opval), op_sub_name, (yyvsp[(4) - (5)].opval));
    ;}
    break;

  case 153:
#line 833 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_field_access(compiler, (yyvsp[(1) - (5)].opval), (yyvsp[(4) - (5)].opval));
    ;}
    break;

  case 154:
#line 837 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_field_access(compiler, (yyvsp[(1) - (4)].opval), (yyvsp[(3) - (4)].opval));
    ;}
    break;

  case 155:
#line 841 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_field_access(compiler, (yyvsp[(1) - (4)].opval), (yyvsp[(3) - (4)].opval));
    ;}
    break;

  case 156:
#line 847 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_weaken_field(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 157:
#line 853 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_weaken_array_element(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 158:
#line 859 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_array_length = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ARRAY_LENGTH, compiler->cur_file, compiler->cur_line);
      (yyval.opval) = SPVM_OP_build_array_length(compiler, op_array_length, (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 159:
#line 864 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_array_length = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ARRAY_LENGTH, compiler->cur_file, compiler->cur_line);
      (yyval.opval) = SPVM_OP_build_array_length(compiler, op_array_length, (yyvsp[(3) - (4)].opval));
    ;}
    break;

  case 160:
#line 869 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_array_length = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ARRAY_LENGTH, compiler->cur_file, compiler->cur_line);
      (yyval.opval) = SPVM_OP_build_array_length(compiler, op_array_length, (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 161:
#line 874 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_array_length = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_ARRAY_LENGTH, compiler->cur_file, compiler->cur_line);
      (yyval.opval) = SPVM_OP_build_array_length(compiler, op_array_length, (yyvsp[(4) - (5)].opval));
    ;}
    break;

  case 162:
#line 881 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_string_length(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 163:
#line 886 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_deref(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 164:
#line 892 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_ref = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_REF, (yyvsp[(1) - (2)].opval)->file, (yyvsp[(1) - (2)].opval)->line);
      (yyval.opval) = SPVM_OP_build_ref(compiler, op_ref, (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 165:
#line 897 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_ref = SPVM_OP_new_op(compiler, SPVM_OP_C_ID_REF, (yyvsp[(1) - (4)].opval)->file, (yyvsp[(1) - (4)].opval)->line);
      (yyval.opval) = SPVM_OP_build_ref(compiler, op_ref, (yyvsp[(3) - (4)].opval));
    ;}
    break;

  case 166:
#line 904 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_binop(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 167:
#line 908 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_isa(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 168:
#line 912 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_or(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 169:
#line 916 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_and(compiler, (yyvsp[(2) - (3)].opval), (yyvsp[(1) - (3)].opval), (yyvsp[(3) - (3)].opval));
    ;}
    break;

  case 170:
#line 920 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_not(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval));
    ;}
    break;

  case 171:
#line 924 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_single_parenthes_term(compiler, (yyvsp[(2) - (3)].opval));
    ;}
    break;

  case 172:
#line 930 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_my(compiler, (yyvsp[(1) - (4)].opval), (yyvsp[(2) - (4)].opval), (yyvsp[(4) - (4)].opval));
    ;}
    break;

  case 173:
#line 934 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_my(compiler, (yyvsp[(1) - (2)].opval), (yyvsp[(2) - (2)].opval), NULL);
    ;}
    break;

  case 174:
#line 940 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_var(compiler, (yyvsp[(1) - (1)].opval));
    ;}
    break;

  case 175:
#line 946 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_package_var_access(compiler, (yyvsp[(1) - (1)].opval));
    ;}
    break;

  case 179:
#line 957 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_basic_type(compiler, (yyvsp[(1) - (1)].opval));
    ;}
    break;

  case 180:
#line 961 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_type = SPVM_OP_new_op_byte_type(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      
      (yyval.opval) = op_type;
    ;}
    break;

  case 181:
#line 967 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_type = SPVM_OP_new_op_short_type(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      
      (yyval.opval) = op_type;
    ;}
    break;

  case 182:
#line 973 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_type = SPVM_OP_new_op_int_type(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      
      (yyval.opval) = op_type;
    ;}
    break;

  case 183:
#line 979 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_type = SPVM_OP_new_op_long_type(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      
      (yyval.opval) = op_type;
    ;}
    break;

  case 184:
#line 985 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_type = SPVM_OP_new_op_float_type(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      
      (yyval.opval) = op_type;
    ;}
    break;

  case 185:
#line 991 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_type = SPVM_OP_new_op_double_type(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      
      (yyval.opval) = op_type;
    ;}
    break;

  case 186:
#line 997 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_type = SPVM_OP_new_op_any_object_type(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      
      (yyval.opval) = op_type;
    ;}
    break;

  case 187:
#line 1003 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_type = SPVM_OP_new_op_string_type(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
      
      (yyval.opval) = op_type;
    ;}
    break;

  case 188:
#line 1011 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_ref_type(compiler, (yyvsp[(1) - (2)].opval));
    ;}
    break;

  case 189:
#line 1017 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_array_type(compiler, (yyvsp[(1) - (3)].opval), NULL);
    ;}
    break;

  case 190:
#line 1021 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_array_type(compiler, (yyvsp[(1) - (3)].opval), NULL);
    ;}
    break;

  case 191:
#line 1027 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_array_type(compiler, (yyvsp[(1) - (4)].opval), (yyvsp[(3) - (4)].opval));
    ;}
    break;

  case 192:
#line 1031 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_build_array_type(compiler, (yyvsp[(1) - (4)].opval), (yyvsp[(3) - (4)].opval));
    ;}
    break;

  case 194:
#line 1038 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op_void_type(compiler, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 197:
#line 1050 "yacc/spvm_yacc.y"
    {
      (yyval.opval) = SPVM_OP_new_op_list(compiler, compiler->cur_file, compiler->cur_line);
    ;}
    break;

  case 198:
#line 1054 "yacc/spvm_yacc.y"
    {
      if ((yyvsp[(1) - (1)].opval)->id == SPVM_OP_C_ID_LIST) {
        (yyval.opval) = (yyvsp[(1) - (1)].opval);
      }
      else {
        SPVM_OP* op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (1)].opval)->file, (yyvsp[(1) - (1)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (1)].opval));
        (yyval.opval) = op_list;
      }
    ;}
    break;

  case 199:
#line 1067 "yacc/spvm_yacc.y"
    {
      SPVM_OP* op_list;
      if ((yyvsp[(1) - (3)].opval)->id == SPVM_OP_C_ID_LIST) {
        op_list = (yyvsp[(1) - (3)].opval);
      }
      else {
        op_list = SPVM_OP_new_op_list(compiler, (yyvsp[(1) - (3)].opval)->file, (yyvsp[(1) - (3)].opval)->line);
        SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(1) - (3)].opval));
      }
      SPVM_OP_insert_child(compiler, op_list, op_list->last, (yyvsp[(3) - (3)].opval));
      
      (yyval.opval) = op_list;
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 3366 "spvm_yacc.tab.c"
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
      yyerror (compiler, YY_("syntax error"));
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
	    yyerror (compiler, yymsg);
	  }
	else
	  {
	    yyerror (compiler, YY_("syntax error"));
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
		      yytoken, &yylval, compiler);
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
		  yystos[yystate], yyvsp, compiler);
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
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, compiler);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, compiler);
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


#line 1082 "yacc/spvm_yacc.y"


