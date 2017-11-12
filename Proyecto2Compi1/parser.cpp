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
#line 1 "sintacticoProyecto2.y" /* yacc.c:339  */


/********************
  Declaraciones en C
**********************/

  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include "scanner.h"
  #include <QTextEdit>
  #include <QString>
  #include <iostream>
  #include "nodo.h"
  #include <QList>

  using namespace std;


  extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
  extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
  extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
  extern int linea ;
  extern int columna;
  int labelnodo = 0;
  //extern int yylex(void);
 // extern FILE *yyin;
  Nodo *raiz = nullptr;
  QTextEdit *expresion;
  QList<QString> *listErr = nullptr;
  void yyerror(const char *s);
  void inicializar(QTextEdit *le);
  void listaError(QList<QString> *listE);


#line 102 "parser.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    tImport = 258,
    tPublico = 259,
    tPrivado = 260,
    tClase = 261,
    tVar = 262,
    tString = 263,
    tInt = 264,
    tDouble = 265,
    tBool = 266,
    tChar = 267,
    tArreglo = 268,
    tSi = 269,
    tSino = 270,
    tPara = 271,
    tMientras = 272,
    tHacer = 273,
    tSalir = 274,
    tRetorna = 275,
    tVoid = 276,
    tConservar = 277,
    tGraficar = 278,
    tPintarC = 279,
    tMain = 280,
    tTrue = 281,
    tFalse = 282,
    tId = 283,
    tNumero = 284,
    tDecimal = 285,
    tCadena = 286,
    tCaracter = 287,
    tSalto = 288,
    tTab = 289,
    tPot = 290,
    tApostrofe = 291,
    tAnd = 292,
    tOr = 293,
    tNand = 294,
    tNor = 295,
    tXor = 296,
    tInterrC = 297,
    tInterrA = 298,
    tDolar = 299,
    tComa = 300,
    tIgual = 301,
    tSuma = 302,
    tResta = 303,
    tMultiplicacion = 304,
    tDivision = 305,
    tPotenciacion = 306,
    tNegacion = 307,
    tIgualacion = 308,
    tMayorIgual = 309,
    tMenorIgual = 310,
    tMenor = 311,
    tMayor = 312,
    tDiferenciacion = 313,
    tParentesisA = 314,
    tParentesisC = 315,
    tCA = 316,
    tCC = 317,
    tLLA = 318,
    tLLC = 319,
    tPtoComa = 320,
    tMasMas = 321,
    tMenosMenos = 322
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "sintacticoProyecto2.y" /* yacc.c:355  */

//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
struct Nodo * VAL;

#line 216 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  392

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   182,   182,   189,   197,   204,   209,   215,   223,   231,
     239,   245,   252,   260,   272,   277,   284,   288,   295,   300,
     306,   313,   320,   328,   336,   341,   349,   355,   361,   367,
     372,   380,   387,   392,   398,   404,   408,   413,   418,   424,
     430,   436,   443,   455,   463,   474,   484,   493,   498,   505,
     509,   513,   518,   522,   526,   531,   539,   546,   553,   562,
     569,   577,   583,   591,   595,   602,   608,   613,   617,   622,
     626,   633,   641,   648,   657,   662,   669,   674,   679,   683,
     688,   694,   698,   705,   713,   720,   729,   736,   746,   755,
     766,   773,   781,   791,   803,   814,   821,   831,   840,   851,
     858,   866,   876,   888,   900,   907,   917,   926,   937,   944,
     952,   962,   974,   986,   992,   999,  1009,  1021,  1026,  1032,
    1041,  1051,  1058,  1066,  1073,  1080,  1087,  1094,  1100,  1107,
    1114,  1121,  1128,  1135,  1142,  1150,  1157,  1164,  1171,  1178,
    1185,  1194,  1200,  1206,  1213,  1219,  1225,  1231,  1237,  1243,
    1249,  1255,  1262,  1276,  1281,  1286,  1290,  1296,  1302,  1309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tImport", "tPublico", "tPrivado",
  "tClase", "tVar", "tString", "tInt", "tDouble", "tBool", "tChar",
  "tArreglo", "tSi", "tSino", "tPara", "tMientras", "tHacer", "tSalir",
  "tRetorna", "tVoid", "tConservar", "tGraficar", "tPintarC", "tMain",
  "tTrue", "tFalse", "tId", "tNumero", "tDecimal", "tCadena", "tCaracter",
  "tSalto", "tTab", "tPot", "tApostrofe", "tAnd", "tOr", "tNand", "tNor",
  "tXor", "tInterrC", "tInterrA", "tDolar", "tComa", "tIgual", "tSuma",
  "tResta", "tMultiplicacion", "tDivision", "tPotenciacion", "tNegacion",
  "tIgualacion", "tMayorIgual", "tMenorIgual", "tMenor", "tMayor",
  "tDiferenciacion", "tParentesisA", "tParentesisC", "tCA", "tCC", "tLLA",
  "tLLC", "tPtoComa", "tMasMas", "tMenosMenos", "$accept", "INICIO", "S",
  "LIMPORTACION", "IMPORTACION", "LIDS", "VISIBILIDAD", "CLASE", "CUERPOS",
  "CUERPO", "TIPO", "VARIABLES", "DIMENSIONES", "ARREGLOS", "ARREGLO",
  "DIMENSION", "ASIGNARR", "CARR", "LEXPS", "LNOMBRES", "NOMBRES",
  "METODOS", "MET", "CUERPOFUNS", "CUERPOF", "RETORNAR", "CUERPOVOIDS",
  "CUERPOV", "CUERPOMAIN", "CUERPOM", "SI", "MIENTRAS", "SINO", "PARA",
  "CPARA", "SIF", "MIENTRASF", "SINOF", "PARAF", "CPARAF", "SIV",
  "MIENTRASV", "SINOV", "PARAV", "CPARAV", "PFS", "PF", "PARAMETROS",
  "PARAMETRO", "ASIGN", "COND", "EXPRESION", "PARMET", "ARRSM", "PARARRM", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

#define YYPACT_NINF -255

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-255)))

#define YYTABLE_NINF -11

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      95,    25,  -255,  -255,    71,  -255,    95,  -255,    96,  -255,
    -255,    19,  -255,  -255,  -255,    77,  -255,    81,    70,  -255,
    1071,    93,   889,   123,  -255,  -255,  -255,  -255,   920,  -255,
    -255,  -255,  -255,  -255,   112,    82,    84,  -255,  -255,  -255,
      44,    87,    92,    91,   129,   108,    25,   134,   140,   148,
    -255,   920,   162,  -255,   149,   153,    20,   857,  -255,   179,
     182,   151,   181,  1046,   920,  -255,   891,   163,  -255,  -255,
    -255,   -40,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
     857,   857,  -255,  1219,   -23,  -255,  -255,   187,   920,   857,
     177,   857,   194,   196,   183,   185,    61,   234,  -255,   202,
     215,  -255,  -255,  -255,  -255,   190,    67,  -255,   843,   891,
    -255,   191,  -255,  -255,  1047,   857,   857,   857,   857,   857,
     857,   857,   857,   857,   857,   857,   891,   891,   891,   891,
     891,   154,   226,  1072,     6,  1079,  1046,  -255,   227,   891,
     -14,  -255,  -255,  -255,   213,   214,  -255,    16,  -255,    65,
    1220,  -255,  -255,  -255,   142,  -255,   142,    56,   938,  1225,
    1225,  1225,  1225,   938,   137,   137,   210,   210,  -255,   857,
     203,   857,   222,   228,   229,   207,   211,    61,  -255,   231,
     376,  -255,  -255,  -255,  -255,  -255,  1046,   243,   230,   217,
    1046,   724,   220,   152,  -255,   857,  1021,   218,   857,  -255,
    -255,  -255,  1101,     9,  1108,   154,  -255,  -255,   257,   891,
     118,  -255,  -255,  -255,   753,   241,   891,   246,   782,   273,
     247,   248,   250,   857,   237,   857,   254,   256,   857,   239,
     242,    61,  -255,   259,   405,  -255,  -255,  -255,  -255,  -255,
     339,  -255,  -255,   154,   276,   261,   251,   154,   434,   252,
     482,  -255,   857,   293,   891,   311,  1046,  -255,   857,  -255,
    -255,  -255,  1130,    24,  1137,  1021,  -255,  1159,   286,   891,
     145,  -255,  -255,  -255,   255,   857,  -255,   -28,   -10,   463,
     269,   891,   278,   492,   299,   279,   283,   287,   -12,  -255,
     338,   857,   811,  1167,  1021,   302,   290,   272,  1021,   521,
    -255,   277,   511,  -255,   857,  -255,    -4,   270,  -255,  -255,
     324,   891,   366,   154,  -255,   857,  -255,  -255,  -255,  1046,
    -255,   857,   898,  -255,  -255,   550,   296,   891,   300,   579,
     329,   303,   305,   306,  -255,   857,    -5,  -255,   395,   857,
     608,  1189,   840,   904,   891,   337,   891,   424,  1021,  -255,
     857,  -255,  -255,  -255,    10,   154,  -255,   857,   927,  -255,
    -255,  -255,   891,   -23,     8,  -255,   453,   857,   637,  1197,
    -255,   666,   933,   891,   -23,  1021,  -255,   857,   956,  -255,
    -255,  -255,   891,   -23,   695,   962,   891,   -23,  -255,   891,
     -23,   -23
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      10,     0,    11,    12,     0,     2,    10,     6,     0,     4,
       9,     0,     1,     5,     3,     0,     7,     0,     0,     8,
       0,     0,     0,     0,    15,    16,    17,    24,     0,    18,
      19,    20,    21,    22,     0,     0,   113,    43,    13,    14,
       0,     0,     0,     0,     0,   114,     0,    41,     0,    26,
      40,   117,     0,   116,     0,     0,     0,     0,    23,     0,
       0,     0,   118,     0,   117,   115,     0,    25,    28,   149,
     150,   151,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,    42,   121,   134,    39,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,    76,     0,
       0,    75,    77,    78,    79,     0,     0,    27,     0,     0,
     152,   156,   158,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
       0,    81,    46,    74,     0,    29,   155,     0,    38,     0,
       0,   157,   140,   123,   122,   125,   126,   124,   132,   128,
     129,   130,   131,   133,   135,   136,   137,   138,   139,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    63,     0,
       0,    62,    66,    67,    68,   119,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,   153,
     154,   159,     0,     0,     0,     0,    65,    64,     0,     0,
       0,    69,    45,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    49,     0,     0,    48,    50,    51,    52,    53,
       0,    30,    37,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,    86,     0,     0,     0,    89,     0,    84,
      85,    83,     0,     0,     0,     0,    60,     0,     0,     0,
       0,    54,    44,    47,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,     0,    56,     0,    36,     0,     0,    32,    33,
     104,     0,     0,     0,   107,     0,    72,    73,    71,     0,
      90,     0,     0,    92,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,    98,
       0,    57,    58,    55,     0,     0,   108,     0,     0,   110,
     106,    91,     0,    94,     0,    96,     0,     0,     0,     0,
      34,     0,     0,     0,    93,     0,    99,     0,     0,   101,
      97,   109,     0,   112,     0,     0,     0,   111,   100,     0,
     103,   102
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -255,  -255,  -255,  -255,   347,   310,    39,   351,  -255,   340,
      -8,   -20,  -255,  -255,   312,  -255,  -255,  -255,  -232,  -255,
     -30,  -255,  -255,  -254,  -221,  -255,  -201,  -173,  -113,   -95,
      90,  -255,  -255,  -255,  -255,    18,  -255,  -255,  -255,  -255,
      48,  -255,  -255,  -255,  -255,  -255,  -255,   333,  -255,   -56,
     -33,   -60,   -80,   297,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    11,    97,     9,    23,    24,
      60,    98,    48,    67,    68,   241,   276,   277,   147,    49,
      99,    26,    37,   234,   235,   236,   180,   181,   100,   101,
     102,   103,   289,   104,   189,   237,   238,   365,   239,   297,
     182,   183,   337,   184,   246,    44,    45,    61,    62,   148,
      83,    84,   110,   111,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    82,    89,    25,   248,   143,   106,   213,   278,   169,
      50,   299,   151,   273,    36,   187,   140,   307,   244,   108,
      40,   109,   223,   191,   126,   127,   128,   129,   130,    85,
     194,   319,   195,   295,   188,   198,   308,   245,   355,     8,
     325,   198,   279,   306,   329,     8,   283,   113,   114,   150,
     151,   375,   296,    10,   309,   198,   133,    46,   135,    22,
     334,   198,    22,    16,    17,    17,   164,   165,   166,   167,
     168,    12,    47,   214,   370,   213,   199,   218,   273,   193,
     132,    66,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   115,   368,   117,   143,   210,     1,     2,
       3,   179,    15,   354,   273,    18,   213,    57,   273,    19,
     213,   178,   340,    20,   126,   127,   128,   129,   130,   143,
     108,   384,   109,   143,    21,   200,   109,     2,     3,   145,
     -10,   -10,   -10,   -10,   -10,   -10,   202,    27,   204,   222,
      41,    42,   242,   292,   -10,    43,    51,   273,   -10,   250,
     179,   270,    52,    53,   371,    21,   255,    54,     2,     3,
     178,   -10,   251,   273,   252,    38,   233,   213,   169,    55,
     170,   171,   172,   173,   174,   179,   232,   175,   176,   115,
      57,   117,   177,   119,    58,   178,   128,   129,   130,   303,
     262,   304,   264,    59,   290,   267,   287,   143,   213,   126,
     127,   128,   129,   130,   233,    63,   342,    47,    64,   302,
      86,    87,   221,   179,   232,    65,    21,   179,   179,     2,
       3,   312,   -10,   178,    66,   293,    88,   178,   178,    89,
     131,    90,    91,    92,    93,   233,   134,   136,    94,    95,
     137,    28,   138,    96,   139,   232,   141,   143,   333,   179,
     144,   338,   109,   179,   185,   192,   196,   142,   322,   178,
     197,   130,   203,   178,   233,   205,   208,   347,   233,   233,
     209,   215,   206,   207,   232,   211,   216,   217,   232,   232,
     220,   240,   341,   179,   363,   249,   366,   254,   343,   256,
     258,   259,   260,   178,   261,   233,   263,   265,   268,   233,
     266,   269,   374,   271,   280,   232,   358,   281,   288,   232,
     179,   282,   285,   383,   301,   311,   315,   369,   233,   305,
     178,   313,   387,   316,   372,   179,   390,   317,   232,   391,
     326,   318,   328,   335,   378,   178,   327,   331,   233,   336,
     274,   179,   346,   348,   385,   233,   350,   351,   232,   352,
     353,   178,   364,    13,   233,   232,    56,    14,   126,   127,
     128,   129,   130,    39,   232,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,   291,    21,   320,   107,
       2,     3,   376,   -10,   356,   126,   127,   128,   129,   130,
     169,    80,   170,   171,   172,   173,   174,   105,    81,   175,
     176,     0,   275,   321,   177,   149,    21,     0,     0,     2,
       3,     0,   -10,   126,   127,   128,   129,   130,   212,   223,
       0,   224,   225,   226,   227,   228,     0,     0,   229,   230,
       0,   339,     0,   231,     0,    21,     0,     0,     2,     3,
       0,   -10,   126,   127,   128,   129,   130,   272,   169,     0,
     170,   171,   172,   173,   174,     0,     0,   175,   176,     0,
     357,     0,   177,     0,    21,     0,     0,     2,     3,     0,
     -10,   126,   127,   128,   129,   130,   284,   169,     0,   170,
     171,   172,   173,   174,     0,     0,   175,   176,     0,   367,
       0,   177,     0,    21,     0,     0,     2,     3,     0,   -10,
     126,   127,   128,   129,   130,   310,   169,     0,   170,   171,
     172,   173,   174,     0,     0,   175,   176,     0,   377,     0,
     177,     0,    21,     0,     0,     2,     3,     0,   -10,   126,
     127,   128,   129,   130,   314,   223,     0,   224,   225,   226,
     227,   228,   286,     0,   229,   230,     0,     0,     0,   231,
       0,    21,     0,     0,     2,     3,     0,   -10,   126,   127,
     128,   129,   130,   330,   223,     0,   224,   225,   226,   227,
     228,   332,     0,   229,   230,     0,     0,     0,   231,     0,
      21,     0,     0,     2,     3,     0,   -10,     0,     0,     0,
       0,     0,   345,   223,     0,   224,   225,   226,   227,   228,
       0,     0,   229,   230,     0,     0,     0,   231,     0,    21,
       0,     0,     2,     3,     0,   -10,     0,     0,     0,     0,
       0,   349,   169,     0,   170,   171,   172,   173,   174,     0,
       0,   175,   176,     0,     0,     0,   177,     0,    21,     0,
       0,     2,     3,     0,   -10,     0,     0,     0,     0,     0,
     359,   223,     0,   224,   225,   226,   227,   228,     0,     0,
     229,   230,     0,     0,     0,   231,     0,    21,     0,     0,
       2,     3,     0,   -10,     0,     0,     0,     0,     0,   379,
     169,     0,   170,   171,   172,   173,   174,     0,     0,   175,
     176,     0,     0,     0,   177,     0,    21,     0,     0,     2,
       3,     0,   -10,     0,     0,     0,     0,     0,   381,   223,
       0,   224,   225,   226,   227,   228,     0,     0,   229,   230,
       0,     0,     0,   231,     0,    21,     0,     0,     2,     3,
       0,   -10,     0,     0,     0,     0,     0,   388,    89,     0,
      90,    91,    92,    93,     0,     0,     0,    94,    95,     0,
       0,     0,    96,     0,    21,     0,     0,     2,     3,     0,
     -10,     0,     0,     0,     0,     0,   219,    89,     0,    90,
      91,    92,    93,     0,     0,     0,    94,    95,     0,     0,
       0,    96,     0,    21,     0,     0,     2,     3,     0,   -10,
       0,     0,     0,     0,     0,   253,    89,     0,    90,    91,
      92,    93,     0,     0,     0,    94,    95,     0,     0,     0,
      96,     0,    21,     0,     0,     2,     3,     0,   -10,     0,
       0,     0,     0,     0,   257,    89,     0,    90,    91,    92,
      93,     0,     0,     0,    94,    95,     0,     0,     0,    96,
       0,    21,     0,     0,     2,     3,     0,   -10,     0,     0,
       0,     0,     0,   323,    89,     0,    90,    91,    92,    93,
       0,     0,     0,    94,    95,     0,     0,     0,    96,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,   361,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,    80,    28,    29,    30,    31,
      32,    33,    81,   146,   109,     0,     0,     0,     0,    80,
      34,     0,     0,     0,    35,     0,    81,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    29,    30,
      31,    32,    33,     0,     0,   115,   116,   117,   118,   119,
       0,   115,   116,   117,   118,   119,     0,     0,     0,     0,
      81,   120,   121,   122,   123,   124,   125,   120,   121,   122,
     123,   124,   125,   344,   115,   116,   117,   118,   119,   362,
     115,   116,   117,   118,   119,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   120,   121,   122,   123,
     124,   125,   373,   115,   116,   117,   118,   119,   382,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,   120,
     121,   122,   123,   124,   125,   120,   121,   122,   123,   124,
     125,   386,    21,     0,     0,     2,     3,   389,   -10,     0,
       0,     0,     0,     0,     0,   223,     0,   224,   225,   226,
     227,   228,     0,     0,   229,   230,     0,    21,     0,   231,
       2,     3,     0,   -10,     0,     0,     0,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,     0,     0,    94,
      95,     0,    21,     0,    96,     2,     3,     0,   -10,   -10,
     -10,   -10,   -10,   -10,   115,   116,   117,   118,   119,     0,
       0,     0,   -10,     0,     0,     0,   -10,     0,     0,     0,
     120,   121,   122,   123,   124,   125,     0,   152,     0,   115,
     116,   117,   118,   119,     0,   186,   115,   116,   117,   118,
     119,     0,   190,     0,     0,   120,   121,   122,   123,   124,
     125,     0,   120,   121,   122,   123,   124,   125,   115,   116,
     117,   118,   119,     0,   243,   115,   116,   117,   118,   119,
       0,   247,     0,     0,   120,   121,   122,   123,   124,   125,
       0,   120,   121,   122,   123,   124,   125,   115,   116,   117,
     118,   119,     0,   294,   115,   116,   117,   118,   119,     0,
     298,     0,     0,   120,   121,   122,   123,   124,   125,     0,
     120,   121,   122,   123,   124,   125,   115,   116,   117,   118,
     119,     0,     0,   300,   115,   116,   117,   118,   119,     0,
       0,   324,   120,   121,   122,   123,   124,   125,     0,     0,
     120,   121,   122,   123,   124,   125,   115,   116,   117,   118,
     119,     0,     0,   360,   115,   116,   117,   118,   119,     0,
       0,   380,   120,   121,   122,   123,   124,   125,     0,     0,
     120,   121,   122,   123,   124,   125,   115,   116,   117,   118,
     119,     0,   115,   116,   117,   118,   119,   126,   127,   128,
     129,   130,   120,   121,   122,   123,   124,   125,   120,     0,
       0,     0,   201,   125
};

static const yytype_int16 yycheck[] =
{
      20,    57,    14,    23,   205,   100,    66,   180,   240,    14,
      40,   265,   111,   234,    22,     9,    96,    45,     9,    59,
      28,    61,    14,   136,    47,    48,    49,    50,    51,    59,
      44,    43,    46,     9,    28,    45,    64,    28,    43,     0,
     294,    45,   243,   275,   298,     6,   247,    80,    81,   109,
     149,    43,    28,    28,    64,    45,    89,    13,    91,    20,
      64,    45,    23,    44,    45,    45,   126,   127,   128,   129,
     130,     0,    28,   186,    64,   248,    60,   190,   299,   139,
      88,    61,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    37,   348,    39,   191,   177,     3,     4,
       5,   131,     6,   335,   325,    28,   279,    46,   329,    28,
     283,   131,   313,    43,    47,    48,    49,    50,    51,   214,
      59,   375,    61,   218,     1,    60,    61,     4,     5,    62,
       7,     8,     9,    10,    11,    12,   169,    44,   171,   195,
      28,    59,   198,   256,    21,    61,    59,   368,    25,   209,
     180,   231,    60,    62,   355,     1,   216,    28,     4,     5,
     180,     7,    44,   384,    46,    42,   196,   340,    14,    61,
      16,    17,    18,    19,    20,   205,   196,    23,    24,    37,
      46,    39,    28,    41,    44,   205,    49,    50,    51,    44,
     223,    46,   225,    45,   254,   228,   252,   292,   371,    47,
      48,    49,    50,    51,   234,    43,   319,    28,    59,   269,
      28,    60,    60,   243,   234,    62,     1,   247,   248,     4,
       5,   281,     7,   243,    61,   258,    45,   247,   248,    14,
      43,    16,    17,    18,    19,   265,    59,    43,    23,    24,
      44,     7,    59,    28,    59,   265,    44,   342,   304,   279,
      60,   311,    61,   283,    28,    28,    43,    42,   291,   279,
      46,    51,    59,   283,   294,    43,    59,   327,   298,   299,
      59,    28,    44,    44,   294,    44,    46,    60,   298,   299,
      60,    63,   315,   313,   344,    28,   346,    46,   321,    43,
      17,    44,    44,   313,    44,   325,    59,    43,    59,   329,
      44,    59,   362,    44,    28,   325,   339,    46,    15,   329,
     340,    60,    60,   373,    28,    46,    17,   350,   348,    64,
     340,    43,   382,    44,   357,   355,   386,    44,   348,   389,
      28,    44,    60,    63,   367,   355,    46,    60,   368,    15,
       1,   371,    46,    43,   377,   375,    17,    44,   368,    44,
      44,   371,    15,     6,   384,   375,    46,     6,    47,    48,
      49,    50,    51,    23,   384,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    65,     1,   288,    67,
       4,     5,   364,     7,   336,    47,    48,    49,    50,    51,
      14,    52,    16,    17,    18,    19,    20,    64,    59,    23,
      24,    -1,    63,    65,    28,   108,     1,    -1,    -1,     4,
       5,    -1,     7,    47,    48,    49,    50,    51,    42,    14,
      -1,    16,    17,    18,    19,    20,    -1,    -1,    23,    24,
      -1,    65,    -1,    28,    -1,     1,    -1,    -1,     4,     5,
      -1,     7,    47,    48,    49,    50,    51,    42,    14,    -1,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    -1,
      65,    -1,    28,    -1,     1,    -1,    -1,     4,     5,    -1,
       7,    47,    48,    49,    50,    51,    42,    14,    -1,    16,
      17,    18,    19,    20,    -1,    -1,    23,    24,    -1,    65,
      -1,    28,    -1,     1,    -1,    -1,     4,     5,    -1,     7,
      47,    48,    49,    50,    51,    42,    14,    -1,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    -1,    65,    -1,
      28,    -1,     1,    -1,    -1,     4,     5,    -1,     7,    47,
      48,    49,    50,    51,    42,    14,    -1,    16,    17,    18,
      19,    20,    60,    -1,    23,    24,    -1,    -1,    -1,    28,
      -1,     1,    -1,    -1,     4,     5,    -1,     7,    47,    48,
      49,    50,    51,    42,    14,    -1,    16,    17,    18,    19,
      20,    60,    -1,    23,    24,    -1,    -1,    -1,    28,    -1,
       1,    -1,    -1,     4,     5,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    42,    14,    -1,    16,    17,    18,    19,    20,
      -1,    -1,    23,    24,    -1,    -1,    -1,    28,    -1,     1,
      -1,    -1,     4,     5,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    42,    14,    -1,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    -1,    -1,    -1,    28,    -1,     1,    -1,
      -1,     4,     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,
      42,    14,    -1,    16,    17,    18,    19,    20,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,     1,    -1,    -1,
       4,     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    42,
      14,    -1,    16,    17,    18,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    -1,    28,    -1,     1,    -1,    -1,     4,
       5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    42,    14,
      -1,    16,    17,    18,    19,    20,    -1,    -1,    23,    24,
      -1,    -1,    -1,    28,    -1,     1,    -1,    -1,     4,     5,
      -1,     7,    -1,    -1,    -1,    -1,    -1,    42,    14,    -1,
      16,    17,    18,    19,    -1,    -1,    -1,    23,    24,    -1,
      -1,    -1,    28,    -1,     1,    -1,    -1,     4,     5,    -1,
       7,    -1,    -1,    -1,    -1,    -1,    42,    14,    -1,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    28,    -1,     1,    -1,    -1,     4,     5,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    42,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,
      28,    -1,     1,    -1,    -1,     4,     5,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    42,    14,    -1,    16,    17,    18,
      19,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      -1,     1,    -1,    -1,     4,     5,    -1,     7,    -1,    -1,
      -1,    -1,    -1,    42,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    42,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    52,     7,     8,     9,    10,
      11,    12,    59,    60,    61,    -1,    -1,    -1,    -1,    52,
      21,    -1,    -1,    -1,    25,    -1,    59,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     8,     9,
      10,    11,    12,    -1,    -1,    37,    38,    39,    40,    41,
      -1,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      59,    53,    54,    55,    56,    57,    58,    53,    54,    55,
      56,    57,    58,    65,    37,    38,    39,    40,    41,    65,
      37,    38,    39,    40,    41,    37,    38,    39,    40,    41,
      53,    54,    55,    56,    57,    58,    53,    54,    55,    56,
      57,    58,    65,    37,    38,    39,    40,    41,    65,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    58,    53,    54,    55,    56,    57,
      58,    65,     1,    -1,    -1,     4,     5,    65,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    16,    17,    18,
      19,    20,    -1,    -1,    23,    24,    -1,     1,    -1,    28,
       4,     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    -1,     1,    -1,    28,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    58,    -1,    60,    -1,    37,
      38,    39,    40,    41,    -1,    43,    37,    38,    39,    40,
      41,    -1,    43,    -1,    -1,    53,    54,    55,    56,    57,
      58,    -1,    53,    54,    55,    56,    57,    58,    37,    38,
      39,    40,    41,    -1,    43,    37,    38,    39,    40,    41,
      -1,    43,    -1,    -1,    53,    54,    55,    56,    57,    58,
      -1,    53,    54,    55,    56,    57,    58,    37,    38,    39,
      40,    41,    -1,    43,    37,    38,    39,    40,    41,    -1,
      43,    -1,    -1,    53,    54,    55,    56,    57,    58,    -1,
      53,    54,    55,    56,    57,    58,    37,    38,    39,    40,
      41,    -1,    -1,    44,    37,    38,    39,    40,    41,    -1,
      -1,    44,    53,    54,    55,    56,    57,    58,    -1,    -1,
      53,    54,    55,    56,    57,    58,    37,    38,    39,    40,
      41,    -1,    -1,    44,    37,    38,    39,    40,    41,    -1,
      -1,    44,    53,    54,    55,    56,    57,    58,    -1,    -1,
      53,    54,    55,    56,    57,    58,    37,    38,    39,    40,
      41,    -1,    37,    38,    39,    40,    41,    47,    48,    49,
      50,    51,    53,    54,    55,    56,    57,    58,    53,    -1,
      -1,    -1,    62,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    69,    70,    71,    72,    74,    75,
      28,    73,     0,    72,    75,     6,    44,    45,    28,    28,
      43,     1,    74,    76,    77,    79,    89,    44,     7,     8,
       9,    10,    11,    12,    21,    25,    78,    90,    42,    77,
      78,    28,    59,    61,   113,   114,    13,    28,    80,    87,
      88,    59,    60,    62,    28,    61,    73,    46,    44,    45,
      78,   115,   116,    43,    59,    62,    61,    81,    82,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      52,    59,   117,   118,   119,    88,    28,    60,    45,    14,
      16,    17,    18,    19,    23,    24,    28,    74,    79,    88,
      96,    97,    98,    99,   101,   115,   119,    82,    59,    61,
     120,   121,   122,   118,   118,    37,    38,    39,    40,    41,
      53,    54,    55,    56,    57,    58,    47,    48,    49,    50,
      51,    43,    78,   118,    59,   118,    43,    44,    59,    59,
     120,    44,    42,    97,    60,    62,    60,    86,   117,   121,
     119,   122,    60,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,    14,
      16,    17,    18,    19,    20,    23,    24,    28,    79,    88,
      94,    95,   108,   109,   111,    28,    43,     9,    28,   102,
      43,    96,    28,   119,    44,    46,    43,    46,    45,    60,
      60,    62,   118,    59,   118,    43,    44,    44,    59,    59,
     120,    44,    42,    95,    96,    28,    46,    60,    96,    42,
      60,    60,   117,    14,    16,    17,    18,    19,    20,    23,
      24,    28,    79,    88,    91,    92,    93,   103,   104,   106,
      63,    83,   117,    43,     9,    28,   112,    43,    94,    28,
     119,    44,    46,    42,    46,   119,    43,    42,    17,    44,
      44,    44,   118,    59,   118,    43,    44,   118,    59,    59,
     120,    44,    42,    92,     1,    63,    84,    85,    86,    94,
      28,    46,    60,    94,    42,    60,    60,   117,    15,   100,
     119,    65,    96,   118,    43,     9,    28,   107,    43,    91,
      44,    28,   119,    44,    46,    64,    86,    45,    64,    64,
      42,    46,   119,    43,    42,    17,    44,    44,    44,    43,
      98,    65,   118,    42,    44,    91,    28,    46,    60,    91,
      42,    60,    60,   117,    64,    63,    15,   110,   119,    65,
      94,   118,    96,   118,    65,    42,    46,   119,    43,    42,
      17,    44,    44,    44,    86,    43,   108,    65,   118,    42,
      44,    42,    65,   119,    15,   105,   119,    65,    91,   118,
      64,    94,   118,    65,   119,    43,   103,    65,   118,    42,
      44,    42,    65,   119,    91,   118,    65,   119,    42,    65,
     119,   119
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    72,    73,    73,
      74,    74,    74,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    84,    84,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    90,    90,    90,    91,    91,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   120,   120,   121,   121,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     3,     3,     1,
       0,     1,     1,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     3,     1,     2,     1,     3,
       5,     2,     2,     2,     5,     3,     2,     3,     1,     3,
       1,     1,     3,     2,     9,     8,     6,     2,     1,     1,
       1,     1,     1,     1,     2,     5,     3,     5,     5,     3,
       2,     2,     1,     1,     2,     2,     1,     1,     1,     2,
       3,     5,     5,     5,     2,     1,     1,     1,     1,     1,
       2,     2,     3,     5,     5,     5,     5,     6,     7,     5,
       2,     4,     7,     8,     7,     5,     6,     7,     5,     2,
       4,     7,     8,     7,     5,     6,     7,     5,     2,     4,
       7,     8,     7,     0,     1,     3,     2,     0,     1,     4,
       2,     1,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     2,     1,     2,     1,     3
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
#line 182 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("INICIO", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
            raiz = (yyval.VAL);
        }
#line 1760 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 189 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

        (yyval.VAL) = new Nodo("S", "", linea, columna, labelnodo++);
        (yyval.VAL)->addHijo((yyvsp[-1].VAL));
        (yyval.VAL)->addHijo((yyvsp[0].VAL));


    }
#line 1773 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 197 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
        (yyval.VAL) = new Nodo("S", "", linea, columna, labelnodo++);
        (yyval.VAL)->addHijo((yyvsp[0].VAL));

    }
#line 1783 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 204 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("LIMPORTACION", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 1793 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 209 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("LIMPORTACION", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 1802 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 215 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
        (yyval.VAL) = new Nodo("IMPORTACION", "", linea, columna, labelnodo++);
        Nodo * nImport = new Nodo("tImport", "Import", linea, columna, labelnodo++);
        (yyval.VAL)->addHijo(nImport);
        (yyval.VAL)->addHijo((yyvsp[-1].VAL));
    }
#line 1813 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 223 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
        (yyval.VAL)= new Nodo("LIDS", "", linea, columna, labelnodo++);
        (yyval.VAL)->addHijo((yyvsp[-2].VAL));
        QString id1 = (yyvsp[0].TEXT);
        Nodo * nId = new Nodo("tId", id1, linea, columna, labelnodo++);
        (yyval.VAL)->addHijo(nId);

    }
#line 1826 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 231 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
        (yyval.VAL)= new Nodo("LIDS", "",linea, columna, labelnodo++);
        QString id = (yyvsp[0].TEXT);
        Nodo * identificador = new Nodo("tId", id, linea, columna, labelnodo++);
        (yyval.VAL)->addHijo(identificador);
    }
#line 1837 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 239 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("VISIBILIDAD", "", linea, columna, labelnodo++);
            Nodo * nVacio = new Nodo("tVacio", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nVacio);

        }
#line 1848 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 245 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL)= new Nodo("VISIBILIDAD", "",linea, columna, labelnodo++);
            Nodo * publico = new Nodo("tPublico", "publico", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(publico);


        }
#line 1860 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 252 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL)= new Nodo("VISIBILIDAD", "",linea, columna, labelnodo++);
            Nodo * privado = new Nodo("tPublico", "privado", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(privado);


        }
#line 1872 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 260 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL)= new Nodo("CLASE", "",linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-5].VAL));
            Nodo * clase = new Nodo("tClase", "Clase", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(clase);
            QString id2 = (yyvsp[-3].TEXT);
            Nodo * identificador = new Nodo("tId", id2, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(identificador);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
        }
#line 1887 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 272 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("CUERPOS", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 1897 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 277 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("CUERPOS", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));

        }
#line 1907 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 284 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL)= new Nodo("CUERPO", "",linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 1916 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 288 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

            (yyval.VAL)= new Nodo("CUERPO", "",linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 1926 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 295 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL)= new Nodo("TIPO", "",linea, columna, labelnodo++);
            Nodo * cadena = new Nodo("tString", "string", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(cadena);
        }
#line 1936 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 300 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL)= new Nodo("TIPO", "",linea, columna, labelnodo++);
            Nodo * integer = new Nodo("tInt", "int", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(integer);

        }
#line 1947 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 306 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

            (yyval.VAL)= new Nodo("TIPO", "",linea, columna, labelnodo++);
            Nodo * doble = new Nodo("tDouble", "double", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(doble);

        }
#line 1959 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 313 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

            (yyval.VAL)= new Nodo("TIPO", "",linea, columna, labelnodo++);
            Nodo * buleano = new Nodo("tBool", "bool", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(buleano);

        }
#line 1971 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 320 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

            (yyval.VAL)= new Nodo("TIPO", "",linea, columna, labelnodo++);
            Nodo * caracter = new Nodo("tChar", "char", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(caracter);
        }
#line 1982 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 328 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("VARIABLES", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
            Nodo * nvar = new Nodo("tVar", "var", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nvar);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
        }
#line 1995 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 336 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

        }
#line 2003 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 341 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("DIMENSIONES", "", linea, columna, labelnodo++);
            Nodo * nArreglo = new Nodo("tArreglo", "arreglo", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nArreglo);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            (yyval.VAL)->addHijo((yyvsp[0].VAL));

        }
#line 2016 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 349 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("DIMENSIONES", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 2025 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 355 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("ARREGLOS", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            (yyval.VAL)->addHijo((yyvsp[0].VAL));

        }
#line 2036 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 361 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("ARREGLOS", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 2045 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 367 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("ARREGLO", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));

        }
#line 2055 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 372 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("ARREGLO", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-3].VAL));
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 2065 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 380 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("DIMENSION", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));

        }
#line 2075 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 387 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("ASIGNARR", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));

        }
#line 2085 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 392 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("ASIGNARR", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
        }
#line 2094 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 398 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("CARR", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));

        }
#line 2105 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 404 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("CARR", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
        }
#line 2114 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 408 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

        }
#line 2122 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 413 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("LEXPS", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 2132 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 418 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("LEXPS", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 2141 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 424 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("LNOMBRES", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            (yyval.VAL)->addHijo((yyvsp[0].VAL));

        }
#line 2152 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 430 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("LNOMBRES", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 2161 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 436 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("NOMBRES", "", linea, columna, labelnodo++);
            QString ident = (yyvsp[0].TEXT);
            Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nId);

        }
#line 2173 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 443 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("NOMBRES", "", linea, columna, labelnodo++);
            QString ident = (yyvsp[-2].TEXT);
            Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nId);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 2185 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 455 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("METODOS", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 2195 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 463 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("MET", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-8].VAL));
            (yyval.VAL)->addHijo((yyvsp[-7].VAL));
            QString nId = (yyvsp[-6].TEXT);
            Nodo * nIdentificador = new Nodo("tId", nId, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nIdentificador);
            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));

        }
#line 2211 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 474 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("MET", "", linea, columna, labelnodo++);
                Nodo * nVoid = new Nodo("tVoid", "void", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nVoid);
                QString nId = (yyvsp[-6].TEXT);
                Nodo * nIdentificador = new Nodo("tId", nId, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nIdentificador);
                (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2226 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 484 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("MET", "", linea, columna, labelnodo++);
                Nodo * nMain = new Nodo("tMain", "Main", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nMain);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2237 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 493 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOFUNS", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2247 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 498 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOFUNS", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2256 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 505 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2265 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 509 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2274 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 513 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));

            }
#line 2284 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 518 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2293 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 522 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2302 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 526 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));

            }
#line 2312 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 531 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                QString ident  = (yyvsp[-4].TEXT);
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
                (yyval.VAL)->addHijo((yyvsp[-3].VAL));
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2325 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 539 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                QString ident  = (yyvsp[-2].TEXT);
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2337 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 546 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                Nodo *nGraf = new Nodo("Graficar", "Graficar", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nGraf);
                Nodo *nId = new Nodo("tId", (yyvsp[-2].TEXT), linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
            }
#line 2349 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 553 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                Nodo *nPintarC = new Nodo("tPintarC", "Pintar_Con", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nPintarC);
                (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            }
#line 2360 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 562 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("RETORNAR", "", linea, columna, labelnodo++);
                Nodo * nRetorna = new Nodo("tRetorna", "retorna", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nRetorna);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));

            }
#line 2372 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 569 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("RETORNAR", "", linea, columna, labelnodo++);
                Nodo * nSalir = new Nodo("tSalir", "salir", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nSalir);
            }
#line 2382 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 577 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOVOIDS", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                (yyval.VAL)->addHijo((yyvsp[0].VAL));

            }
#line 2393 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 583 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOVOIDS", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));

            }
#line 2403 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 591 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2412 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 595 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                Nodo * nRetorna = new Nodo("tRetorna", "retorna", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nRetorna);

            }
#line 2424 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 602 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                Nodo * nSalir = new Nodo("tSalir", "salir", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nSalir);
            }
#line 2435 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 608 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));

            }
#line 2445 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 613 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2454 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 617 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2464 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 622 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2473 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 626 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                QString ident  = (yyvsp[-2].TEXT);
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2485 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 633 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                QString ident  = (yyvsp[-4].TEXT);
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
                (yyval.VAL)->addHijo((yyvsp[-3].VAL));
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2498 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 641 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                Nodo *nGraf = new Nodo("tGraficar", "Graficar", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nGraf);
                Nodo *nId = new Nodo("tId", (yyvsp[-2].TEXT), linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
            }
#line 2510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 648 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                Nodo *nPintarC = new Nodo("tPintarC", "Pintar_Con", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nPintarC);
                (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            }
#line 2521 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 657 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOMAIN", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2531 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 662 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOMAIN", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2540 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 669 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));

            }
#line 2550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 674 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));

            }
#line 2560 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 679 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2569 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 683 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

                (yyval.VAL) = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2579 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 688 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

                (yyval.VAL) = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                Nodo * nSalir = new Nodo("tSalir", "salir", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nSalir);
            }
#line 2590 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 694 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2599 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 698 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                QString ident  = (yyvsp[-2].TEXT);
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2611 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 705 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                QString ident  = (yyvsp[-4].TEXT);
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
                (yyval.VAL)->addHijo((yyvsp[-3].VAL));
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2624 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 713 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                Nodo *nGraf = new Nodo("tGraficar", "Graficar", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nGraf);
                Nodo *nId = new Nodo("tId", (yyvsp[-2].TEXT), linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
            }
#line 2636 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 720 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                Nodo *nPintarC = new Nodo("tPintarC", "Pintar_Con", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nPintarC);
                (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            }
#line 2647 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 729 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("SI", "", linea, columna, labelnodo++);
                Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nSi);
                (yyval.VAL)->addHijo((yyvsp[-3].VAL));
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2659 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 736 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("SI", "", linea, columna, labelnodo++);
                Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nSi);
                (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                (yyval.VAL)->addHijo((yyvsp[-2].VAL));
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 746 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo ("MIENTRAS", "", linea, columna, labelnodo++);
                Nodo * nHacer = new Nodo("tHacer", "hacer", 0 ,0, labelnodo++ );
                (yyval.VAL)->addHijo(nHacer);
                (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nMientras);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2686 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 755 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("MIENTRAS", "", linea, columna, labelnodo++);
                Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nMientras);
                (yyval.VAL)->addHijo((yyvsp[-3].VAL));
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2698 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 766 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("SINO", "", linea, columna, labelnodo++);
                Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nSino);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));

            }
#line 2710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 773 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("SINO", "", linea, columna, labelnodo++);
                Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nSino);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            }
#line 2721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 781 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("PARA", "", linea, columna, labelnodo++);
                Nodo * nPara = new Nodo("tPara", "para", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nPara);
                (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                
            }
#line 2734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 791 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CPARA", "", linea, columna, labelnodo++);
                Nodo * nInt = new Nodo("tInt", "int", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nInt);
                QString identificador = (yyvsp[-6].TEXT);
                Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
                (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                (yyval.VAL)->addHijo((yyvsp[-2].VAL));
                (yyval.VAL)->addHijo((yyvsp[0].VAL));

            }
#line 2751 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 803 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("CPARA", "", linea, columna, labelnodo++);
                QString identificador = (yyvsp[-6].TEXT);
                Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);
                (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                (yyval.VAL)->addHijo((yyvsp[-2].VAL));
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 2765 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 814 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("SIF", "", linea, columna, labelnodo++);
                            Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nSi);
                            (yyval.VAL)->addHijo((yyvsp[-3].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                        }
#line 2777 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 821 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("SIF", "", linea, columna, labelnodo++);
                            Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nSi);
                            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
                            (yyval.VAL)->addHijo((yyvsp[0].VAL));
                        }
#line 2790 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 831 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo ("MIENTRASF", "", linea, columna, labelnodo++);
                            Nodo * nHacer = new Nodo("tHacer", "hacer", 0 ,0, labelnodo++ );
                            (yyval.VAL)->addHijo(nHacer);
                            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                            Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nMientras);
                            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                        }
#line 2804 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 840 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("MIENTRAS", "", linea, columna, labelnodo++);
                            Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nMientras);
                            (yyval.VAL)->addHijo((yyvsp[-3].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                        }
#line 2816 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 851 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("SINOF", "", linea, columna, labelnodo++);
                            Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nSino);
                            (yyval.VAL)->addHijo((yyvsp[0].VAL));

                        }
#line 2828 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 858 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("SINOF", "", linea, columna, labelnodo++);
                            Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nSino);
                            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                        }
#line 2839 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 866 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("PARAF", "", linea, columna, labelnodo++);
                            Nodo * nPara = new Nodo("tPara", "para", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nPara);
                            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-1].VAL));

                        }
#line 2852 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 876 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("CPARAF", "", linea, columna, labelnodo++);
                            Nodo * nInt = new Nodo("tInt", "int", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nInt);
                            QString identificador = (yyvsp[-6].TEXT);
                            Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nId);
                            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
                            (yyval.VAL)->addHijo((yyvsp[0].VAL));

                        }
#line 2869 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 888 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("CPARAF", "", linea, columna, labelnodo++);
                            QString identificador = (yyvsp[-6].TEXT);
                            Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nId);
                            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
                            (yyval.VAL)->addHijo((yyvsp[0].VAL));
                        }
#line 2883 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 900 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("SIV", "", linea, columna, labelnodo++);
                            Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nSi);
                            (yyval.VAL)->addHijo((yyvsp[-3].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                        }
#line 2895 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 907 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("SIV", "", linea, columna, labelnodo++);
                            Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nSi);
                            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
                            (yyval.VAL)->addHijo((yyvsp[0].VAL));
                        }
#line 2908 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 917 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo ("MIENTRASV", "", linea, columna, labelnodo++);
                            Nodo * nHacer = new Nodo("tHacer", "hacer", 0 ,0, labelnodo++ );
                            (yyval.VAL)->addHijo(nHacer);
                            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                            Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nMientras);
                            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                        }
#line 2922 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 926 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("MIENTRASV", "", linea, columna, labelnodo++);
                            Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nMientras);
                            (yyval.VAL)->addHijo((yyvsp[-3].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                        }
#line 2934 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 937 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("SINOV", "", linea, columna, labelnodo++);
                            Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nSino);
                            (yyval.VAL)->addHijo((yyvsp[0].VAL));

                        }
#line 2946 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 944 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("SINOV", "", linea, columna, labelnodo++);
                            Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nSino);
                            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                        }
#line 2957 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 952 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("PARAV", "", linea, columna, labelnodo++);
                            Nodo * nPara = new Nodo("tPara", "para", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nPara);
                            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-1].VAL));

                        }
#line 2970 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 962 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("CPARAV", "", linea, columna, labelnodo++);
                            Nodo * nInt = new Nodo("tInt", "int", linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nInt);
                            QString identificador = (yyvsp[-6].TEXT);
                            Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nId);
                            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
                            (yyval.VAL)->addHijo((yyvsp[0].VAL));

                        }
#line 2987 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 974 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                            (yyval.VAL) = new Nodo("CPARAV", "", linea, columna, labelnodo++);
                            QString identificador = (yyvsp[-6].TEXT);
                            Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                            (yyval.VAL)->addHijo(nId);
                            (yyval.VAL)->addHijo((yyvsp[-4].VAL));
                            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
                            (yyval.VAL)->addHijo((yyvsp[0].VAL));
                        }
#line 3001 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 986 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {

                (yyval.VAL) = new Nodo("PFS", "", linea, columna, labelnodo++);
                Nodo * nVacio = new Nodo("tVacio", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nVacio);
            }
#line 3012 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 992 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("PFS", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));

            }
#line 3022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 999 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("PF", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[-2].VAL));
                Nodo * nCA = new Nodo("tCA", "[" , linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nCA);
                Nodo * nCC = new Nodo("tCC", "]" , linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nCC);


            }
#line 3037 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1009 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("PF", "", linea, columna, labelnodo++);
                Nodo * nCA = new Nodo("tCA", "[" , linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nCA);
                Nodo * nCC = new Nodo("tCC", "]" , linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nCC);

            }
#line 3050 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1021 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("PARAMETROS", "", linea, columna, labelnodo++);
                Nodo * nVacio = new Nodo("tVacio", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nVacio);
           }
#line 3060 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1026 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("PARAMETROS", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[0].VAL));
            }
#line 3069 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1032 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("PARAMETRO", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[-3].VAL));
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                QString id = (yyvsp[0].TEXT);
                Nodo * nId = new Nodo("tId", id, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);

            }
#line 3083 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1041 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                (yyval.VAL) = new Nodo("PARAMETRO", "", linea, columna, labelnodo++);
                (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                QString id = (yyvsp[0].TEXT);
                Nodo * nId = new Nodo("tId", id, linea, columna, labelnodo++);
                (yyval.VAL)->addHijo(nId);

            }
#line 3096 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1051 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("ASIGN", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));

        }
#line 3106 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1058 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nOr = new Nodo("tOr", "||" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nOr);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));

        }
#line 3119 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1066 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nAnd = new Nodo("tAnd", "&&" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nAnd);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3131 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1073 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nXor = new Nodo("tXor", "&|" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nXor);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3143 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1080 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nNand = new Nodo("tNand", "!&&" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nNand);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3155 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1087 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nNor = new Nodo("tNor", "!||" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nNor);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3167 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1094 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            Nodo * nNegacion = new Nodo("tNegacion", "!" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nNegacion);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3178 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1100 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nMayorIgual = new Nodo("tMayorIgual", ">=" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nMayorIgual);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3190 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1107 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nMenorIgual = new Nodo("tMenorIgual", "<=" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nMenorIgual);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3202 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1114 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nMenor = new Nodo("tMenor", "<" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nMenor);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3214 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1121 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nMayor = new Nodo("tMayor", ">" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nMayor);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3226 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1128 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nIgualacion = new Nodo("tIgualacion", "==" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nIgualacion);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3238 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1135 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nDiferenciacion = new Nodo("tDiferenciacion", "!=" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nDiferenciacion);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3250 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1142 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("COND", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3259 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1150 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nMas = new Nodo("tSuma", "+" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nMas);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3271 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1157 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nMenos = new Nodo("tResta", "-" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nMenos);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3283 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1164 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nMultiplicacion = new Nodo("tMultiplicacion", "*" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nMultiplicacion);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3295 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1171 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nDivision = new Nodo("tDivision", "/" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nDivision);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3307 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1178 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo((yyvsp[-2].VAL));
            Nodo * nPotenciacion = new Nodo("tPotenciacion", "^" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nPotenciacion);
            (yyval.VAL)->addHijo((yyvsp[0].VAL));
        }
#line 3319 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1185 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            Nodo * nPA = new Nodo("tParentesisA", "(" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nPA);
            (yyval.VAL)->addHijo((yyvsp[-1].VAL));
            Nodo * nPC = new Nodo("tParentesisC", ")" ,linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nPC);

        }
#line 3333 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1194 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString number = (yyvsp[0].TEXT);
            Nodo * nNumero = new Nodo("tNumero", number, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nNumero);
        }
#line 3344 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1200 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString decimal = (yyvsp[0].TEXT);
            Nodo * nDecimal = new Nodo("tDecimal", decimal, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nDecimal);
        }
#line 3355 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1206 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString cadena = (yyvsp[0].TEXT);
            Nodo * nCadena = new Nodo("tCadena", cadena, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nCadena);

        }
#line 3367 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1213 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString caracter = (yyvsp[0].TEXT);
            Nodo * nCaracter = new Nodo("tCaracter", caracter, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nCaracter);
        }
#line 3378 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1219 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString salto = (yyvsp[0].TEXT);
            Nodo * nSalto = new Nodo("tSalto", salto, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nSalto);
        }
#line 3389 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1225 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString salto = (yyvsp[0].TEXT);
            Nodo * nSalto = new Nodo("tSalto", salto, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nSalto);
        }
#line 3400 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1231 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString pot = (yyvsp[0].TEXT);
            Nodo * nPot = new Nodo("tPot", pot, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nPot);
        }
#line 3411 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1237 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString apostrofe = (yyvsp[0].TEXT);
            Nodo * nApostrofe = new Nodo("tApostrofe", apostrofe, linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nApostrofe);
        }
#line 3422 "parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1243 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            Nodo * nTrue = new Nodo("tTrue", "true", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nTrue);

        }
#line 3433 "parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1249 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
            (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            Nodo * nFalse = new Nodo("tFalse", "false", linea, columna, labelnodo++);
            (yyval.VAL)->addHijo(nFalse);

        }
#line 3444 "parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1255 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                    (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
                    QString id = (yyvsp[0].TEXT);
                    Nodo * nIdentificador = new Nodo("tId", id, linea, columna, labelnodo++);
                    (yyval.VAL)->addHijo(nIdentificador);
                }
#line 3455 "parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1262 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                    (yyval.VAL) = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
                    QString id = (yyvsp[-1].TEXT);
                    Nodo * nIdentificador = new Nodo("tId", id, linea, columna, labelnodo++);
                    (yyval.VAL)->addHijo(nIdentificador);
                    (yyval.VAL)->addHijo((yyvsp[0].VAL));
                }
#line 3467 "parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1276 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                    (yyval.VAL) = new Nodo("PARMET", "", linea, columna, labelnodo++);
                    (yyval.VAL)->addHijo((yyvsp[-1].VAL));

                }
#line 3477 "parser.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1281 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                    (yyval.VAL) = new Nodo("PARMET", "", linea, columna, labelnodo++);
                    (yyval.VAL)->addHijo((yyvsp[-1].VAL));

                }
#line 3487 "parser.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1286 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                    (yyval.VAL) = new Nodo("PARMET", "", linea, columna, labelnodo++);

                }
#line 3496 "parser.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1290 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                    (yyval.VAL) = new Nodo("PARMET", "", linea, columna, labelnodo++);
                    (yyval.VAL)->addHijo((yyvsp[0].VAL));
                }
#line 3505 "parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1296 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                    (yyval.VAL) = new Nodo("ARRSM", "", linea, columna, labelnodo++);
                    (yyval.VAL)->addHijo((yyvsp[-1].VAL));
                    (yyval.VAL)->addHijo((yyvsp[0].VAL));

                }
#line 3516 "parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1302 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                    (yyval.VAL) = new Nodo("ARRSM", "", linea, columna, labelnodo++);
                    (yyval.VAL)->addHijo((yyvsp[0].VAL));
                }
#line 3525 "parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1309 "sintacticoProyecto2.y" /* yacc.c:1646  */
    {
                    (yyval.VAL) = new Nodo("ARREGLO", "", linea, columna, labelnodo++);
                    (yyval.VAL)->addHijo((yyvsp[-1].VAL));

                }
#line 3535 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3539 "parser.cpp" /* yacc.c:1646  */
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
#line 1319 "sintacticoProyecto2.y" /* yacc.c:1906  */


/********************
  Codigo C++ o C Adicional
**********************/
void yyerror(const char *s)
{
    cout << s <<" " << yytext << " columna" << to_string(columna) << " fila: "<< to_string(linea) << endl;
    string stdeserror = s;
    string stdeserror2 = yytext;

    QString eserror = QString::fromStdString(stdeserror) +" " +QString::fromStdString(stdeserror2) + " en linea: "+ QString::number(yylineno);
    listErr->append(eserror);
    columna = 0;
    linea = 0;
}

void listaError(QList<QString> *listE){
    listErr = listE;
}

void inicializar(QTextEdit *le){
  expresion = le;
}

