/*****************
  Definiciones
                Se colocan las cabeceras, variables y expresiones regulares

********************/
%option noyywrap
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "parser.h"
  int linea = 0;
  int columna = 0;
%}
/*
	Creamos todas las expresiones regulares
	Creamos la definición llamada id, podemos acceder esta definición
	usando {tId}
*/

tApostrofe "'^''"("++"|"--")?
tPot "'^^'"("++"|"--")?
SALTO "'#n'"("++"|"--")?
TAB "'#t'"("++"|"--")?
DIGITO [0-9]
CARACTER [^\r\t\n\^]  
tId [A-Za-z]([A-Za-z0-9"_"])*("++"|"--")?
tNumero ("-")?{DIGITO}+("++"|"--")?
tDecimal ("-")?{DIGITO}+"."{DIGITO}+("++"|"--")?
tCadena "\""([^\n\r\"])*"\""
tCaracter "'"{CARACTER}"'"("++"|"--")?
tComentarioLinea ">>" ([^\n\r])* "\n"
tComentarioMulti "<-" ([^\r])* "->" 

%%



"Import"        { strcpy(yylval.TEXT, yytext); columna++; return tImport; }
"publico"  		{ strcpy(yylval.TEXT, yytext); columna++; return tPublico; }
"privado"       { strcpy(yylval.TEXT, yytext); columna++; return tPrivado; }
"Clase"      	{ strcpy(yylval.TEXT, yytext); columna++; return tClase; }
"var"   		{ strcpy(yylval.TEXT, yytext); columna++; return tVar; }
"string"		{ strcpy(yylval.TEXT, yytext); columna++; return tString; }
"int"			{ strcpy(yylval.TEXT, yytext); columna++; return tInt; }
"double"		{ strcpy(yylval.TEXT, yytext); columna++; return tDouble; }
"bool"			{ strcpy(yylval.TEXT, yytext); columna++; return tBool; }
"char"			{ strcpy(yylval.TEXT, yytext); columna++; return tChar; }
"arreglo"		{ strcpy(yylval.TEXT, yytext); columna++; return tArreglo; }
"si"			{ strcpy(yylval.TEXT, yytext); columna++; return tSi; }
"sino"			{ strcpy(yylval.TEXT, yytext); columna++; return tSino; }
"para"			{ strcpy(yylval.TEXT, yytext); columna++; return tPara; }
"mientras"		{ strcpy(yylval.TEXT, yytext); columna++; return tMientras; }
"hacer"			{ strcpy(yylval.TEXT, yytext); columna++; return tHacer; }
"salir"			{ strcpy(yylval.TEXT, yytext); columna++; return tSalir; }
"retorna"		{ strcpy(yylval.TEXT, yytext); columna++; return tRetorna; }
"void"			{ strcpy(yylval.TEXT, yytext); columna++; return tVoid; }
"conservar"  	{ strcpy(yylval.TEXT, yytext); columna++; return tConservar; }
"Graficar"		{ strcpy(yylval.TEXT, yytext); columna++; return tGraficar; }
"Pintar_Con"	{ strcpy(yylval.TEXT, yytext); columna++; return tPintarC; }
"Main"			{ strcpy(yylval.TEXT, yytext); columna++; return tMain; }
"true"			{ strcpy(yylval.TEXT, yytext); columna++; return tTrue; }
"false"			{ strcpy(yylval.TEXT, yytext); columna++; return tFalse; }
{tId} 			{ strcpy(yylval.TEXT, yytext); columna++; return tId; }
{tNumero}		{ strcpy(yylval.TEXT, yytext); columna++; return tNumero; }
{tDecimal}		{ strcpy(yylval.TEXT, yytext); columna++; return tDecimal; }
{tCadena}		{ strcpy(yylval.TEXT, yytext); columna++; return tCadena; }
{tCaracter}		{ strcpy(yylval.TEXT, yytext); columna++; return tCaracter; }
{SALTO}     	{ strcpy(yylval.TEXT, yytext); columna++; return tSalto; }
{TAB}	    	{ strcpy(yylval.TEXT, yytext); columna++; return tTab; }
{tPot}      	{ strcpy(yylval.TEXT, yytext); columna++; return tPot; }
{tApostrofe}	{ strcpy(yylval.TEXT, yytext); columna++; return tApostrofe; }
"&&"			{ strcpy(yylval.TEXT, yytext); columna++; return tAnd; }
"||"			{ strcpy(yylval.TEXT, yytext); columna++; return tOr; }
"!&&"			{ strcpy(yylval.TEXT, yytext); columna++; return tNand; }
"!||"			{ strcpy(yylval.TEXT, yytext); columna++; return tNor; }
"&|"			{ strcpy(yylval.TEXT, yytext); columna++; return tXor; }
"?"	        	{ strcpy(yylval.TEXT, yytext); columna++; return tInterrC; }
"¿"         	{ strcpy(yylval.TEXT, yytext); columna++; return tInterrA; }
"$"         	{ strcpy(yylval.TEXT, yytext); columna++; return tDolar; }
","         	{ strcpy(yylval.TEXT, yytext); columna++; return tComa; }
"="         	{ strcpy(yylval.TEXT, yytext); columna++; return tIgual; }
"+"				{ strcpy(yylval.TEXT, yytext); columna++; return tSuma; }
"-"				{ strcpy(yylval.TEXT, yytext); columna++; return tResta; }
"*"				{ strcpy(yylval.TEXT, yytext); columna++; return tMultiplicacion; }
"/"				{ strcpy(yylval.TEXT, yytext); columna++; return tDivision; }
"^"				{ strcpy(yylval.TEXT, yytext); columna++; return tPotenciacion; }
"!"				{ strcpy(yylval.TEXT, yytext); columna++; return tNegacion; }
"=="			{ strcpy(yylval.TEXT, yytext); columna++; return tIgualacion; }
">="			{ strcpy(yylval.TEXT, yytext); columna++; return tMayorIgual;  }
"<="			{ strcpy(yylval.TEXT, yytext); columna++; return tMenorIgual; }
"<"				{ strcpy(yylval.TEXT, yytext); columna++; return tMenor; }
">"				{ strcpy(yylval.TEXT, yytext); columna++; return tMayor; }
"!="			{ strcpy(yylval.TEXT, yytext); columna++; return tDiferenciacion; }
"("			    { strcpy(yylval.TEXT, yytext); columna++; return tParentesisA; }
")"             { strcpy(yylval.TEXT, yytext); columna++; return tParentesisC; }
"["             { strcpy(yylval.TEXT, yytext); columna++; return tCA; }
"]"             { strcpy(yylval.TEXT, yytext); columna++; return tCC; }
"{"             { strcpy(yylval.TEXT, yytext); columna++; return tLLA; }
"}"             { strcpy(yylval.TEXT, yytext); columna++; return tLLC; }
";"             { strcpy(yylval.TEXT, yytext); columna++; return tPtoComa; }
"++"            { strcpy(yylval.TEXT, yytext); columna++; return tMasMas; }
"--"            { strcpy(yylval.TEXT, yytext); columna++; return tMenosMenos; }
"\n"        	{ linea++; columna = 0; }

[[:blank:]]     { /*Se ignoran*/ }


 /* Si en nuestra entrada tiene algún caracter que no pertenece a
   las reglas anteriores, se genera un error léxico */


.                              {

                                     printf("Error lexico en linea %d",linea);
                                     printf(" columna: %d", columna);
                                     columna = 0;
                                     linea = 0 ;
                               }



%%

/*
Código de Usuario

Aquí podemos realizar otras funciones, como por ejemplo ingresar
símbolos a nuestra tabal de símbolos o cualquier otra accione
del usuario. 
Todo lo que el usuario coloque en esta sección se copiara al
archvi lex.yy.c tal y como esta.
*/






