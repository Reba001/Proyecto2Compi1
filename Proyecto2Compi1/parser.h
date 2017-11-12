/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 40 "sintacticoProyecto2.y" /* yacc.c:1909  */

//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
struct Nodo * VAL;

#line 128 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
