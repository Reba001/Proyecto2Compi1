%{

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

%}

//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%error-verbose

%union{
//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
struct Nodo * VAL;
}
//PRODUCCION INICIAL
%start INICIO

//TERMINALES DE TIPO TEXT, SON STRINGS
%token<TEXT>  tImport
%token<TEXT>  tPublico
%token<TEXT>  tPrivado
%token<TEXT>  tClase
%token<TEXT>  tVar
%token<TEXT>  tString
%token<TEXT>  tInt
%token<TEXT>  tDouble
%token<TEXT>  tBool
%token<TEXT>  tChar
%token<TEXT>  tArreglo
%token<TEXT>  tSi
%token<TEXT>  tSino
%token<TEXT>  tPara
%token<TEXT>  tMientras
%token<TEXT>  tHacer
%token<TEXT>  tSalir
%token<TEXT>  tRetorna
%token<TEXT>  tVoid
%token<TEXT>  tConservar
%token<TEXT>  tGraficar
%token<TEXT>  tPintarC
%token<TEXT>  tMain
%token<TEXT>  tTrue
%token<TEXT>  tFalse
%token<TEXT>  tId
%token<TEXT>  tNumero
%token<TEXT>  tDecimal
%token<TEXT>  tCadena
%token<TEXT>  tCaracter
%token<TEXT>  tSalto
%token<TEXT>  tTab
%token<TEXT>  tPot
%token<TEXT>  tApostrofe
%token<TEXT>  tAnd
%token<TEXT>  tOr
%token<TEXT>  tNand
%token<TEXT>  tNor
%token<TEXT>  tXor
%token<TEXT>  tInterrC
%token<TEXT>  tInterrA
%token<TEXT>  tDolar
%token<TEXT>  tComa
%token<TEXT>  tIgual
%token<TEXT>  tSuma
%token<TEXT>  tResta
%token<TEXT>  tMultiplicacion 
%token<TEXT>  tDivision
%token<TEXT>  tPotenciacion
%token<TEXT>  tNegacion
%token<TEXT>  tIgualacion
%token<TEXT>  tMayorIgual
%token<TEXT>  tMenorIgual
%token<TEXT>  tMenor
%token<TEXT>  tMayor
%token<TEXT>  tDiferenciacion
%token<TEXT>  tParentesisA
%token<TEXT>  tParentesisC
%token<TEXT>  tCA
%token<TEXT>  tCC
%token<TEXT>  tLLA
%token<TEXT>  tLLC
%token<TEXT>  tPtoComa
%token<TEXT>  tMasMas
%token<TEXT>  tMenosMenos
//NO TERMINALES DE TIPO VAL, POSEEN ATRIBUTOS INT VALOR, Y QSTRING TEXTO
%type<VAL>  S
%type<VAL>  IMPORTACION
%type<VAL>  LIMPORTACION
%type<VAL>  VISIBILIDAD
%type<VAL>  CLASE
%type<VAL>  CUERPOS
%type<VAL>  CUERPO
%type<VAL>  VARIABLES
%type<VAL>  METODOS
%type<VAL>  TIPO
%type<VAL>  LIDS
%type<VAL>  MET
%type<VAL>  NOMBRES
%type<VAL>  LNOMBRES
%type<VAL>  COND
%type<VAL>  EXPRESION
%type<VAL>  ASIGN
%type<VAL>  PARAMETROS
%type<VAL>  ARREGLOS
%type<VAL>  DIMENSIONES
%type<VAL>  ARREGLO
%type<VAL>  DIMENSION
%type<VAL>  CARR
%type<VAL>  LEXPS
%type<VAL>  ASIGNARR
%type<VAL>  INICIO
%type<VAL>  PARAMETRO
%type<VAL>  PFS
%type<VAL>  PF
%type<VAL>  CUERPOFUNS
%type<VAL>  CUERPOVOIDS
%type<VAL>  CUERPOMAIN
%type<VAL>  CUERPOF
%type<VAL>  CUERPOV
%type<VAL>  CUERPOM
%type<VAL>  RETORNAR
%type<VAL>  SI
%type<VAL>  SINO
%type<VAL>  MIENTRAS
%type<VAL>  PARA
%type<VAL>  CPARA
%type<VAL>  SIV
%type<VAL>  SINOV
%type<VAL>  MIENTRASV
%type<VAL>  PARAV
%type<VAL>  CPARAV
%type<VAL>  SIF
%type<VAL>  SINOF
%type<VAL>  MIENTRASF
%type<VAL>  PARAF
%type<VAL>  CPARAF
%type<VAL>  PARMET
%type<VAL>  ARRSM
%type<VAL>  PARARRM
//DEFINIMOS LA PRECEDENCIA

%left tSuma tResta
%left tMultiplicacion tDivision
%left tPotenciacion
%left tMayorIgual tMenorIgual tMayor tMenor
%left tIgualacion tDiferenciacion
%left tOr tNor
%left tXor
%left tAnd tNand
%right tNegacion

%%
INICIO: S{
            $$ = new Nodo("INICIO", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            raiz = $$;
        }
        ;

S:	LIMPORTACION CLASE{

        $$ = new Nodo("S", "", linea, columna, labelnodo++);
        $$->addHijo($1);
        $$->addHijo($2);


    }
    | CLASE{
        $$ = new Nodo("S", "", linea, columna, labelnodo++);
        $$->addHijo($1);

    }
    ;

LIMPORTACION: LIMPORTACION IMPORTACION{
            $$ = new Nodo("LIMPORTACION", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            $$->addHijo($2);
        }
        | IMPORTACION{
            $$ = new Nodo("LIMPORTACION", "", linea, columna, labelnodo++);
            $$->addHijo($1);
        }
        ;

IMPORTACION: tImport LIDS tDolar {
        $$ = new Nodo("IMPORTACION", "", linea, columna, labelnodo++);
        Nodo * nImport = new Nodo("tImport", "Import", linea, columna, labelnodo++);
        $$->addHijo(nImport);
        $$->addHijo($2);
    }
    ;

LIDS: LIDS tComa tId{
        $$= new Nodo("LIDS", "", linea, columna, labelnodo++);
        $$->addHijo($1);
        QString id1 = $3;
        Nodo * nId = new Nodo("tId", id1, linea, columna, labelnodo++);
        $$->addHijo(nId);

    }
    |   tId{
        $$= new Nodo("LIDS", "",linea, columna, labelnodo++);
        QString id = $1;
        Nodo * identificador = new Nodo("tId", id, linea, columna, labelnodo++);
        $$->addHijo(identificador);
    }
    ;

VISIBILIDAD: {
            $$ = new Nodo("VISIBILIDAD", "", linea, columna, labelnodo++);
            Nodo * nVacio = new Nodo("tVacio", "", linea, columna, labelnodo++);
            $$->addHijo(nVacio);

        }
        | tPublico{
            $$= new Nodo("VISIBILIDAD", "",linea, columna, labelnodo++);
            Nodo * publico = new Nodo("tPublico", "publico", linea, columna, labelnodo++);
            $$->addHijo(publico);


        }
        | tPrivado{
            $$= new Nodo("VISIBILIDAD", "",linea, columna, labelnodo++);
            Nodo * privado = new Nodo("tPublico", "privado", linea, columna, labelnodo++);
            $$->addHijo(privado);


        };

CLASE:  VISIBILIDAD tClase tId tInterrA CUERPOS tInterrC {
            $$= new Nodo("CLASE", "",linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * clase = new Nodo("tClase", "Clase", linea, columna, labelnodo++);
            $$->addHijo(clase);
            QString id2 = $3;
            Nodo * identificador = new Nodo("tId", id2, linea, columna, labelnodo++);
            $$->addHijo(identificador);
            $$->addHijo($5);
        }
        ;

CUERPOS: CUERPOS CUERPO{
            $$ = new Nodo("CUERPOS", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            $$->addHijo($2);
        }
        | CUERPO{
            $$ = new Nodo("CUERPOS", "", linea, columna, labelnodo++);
            $$->addHijo($1);

        }
        ;

CUERPO:   VARIABLES{
            $$= new Nodo("CUERPO", "",linea, columna, labelnodo++);
            $$->addHijo($1);
        }
        | METODOS {

            $$= new Nodo("CUERPO", "",linea, columna, labelnodo++);
            $$->addHijo($1);
        }
        ;

TIPO:   tString{
            $$= new Nodo("TIPO", "",linea, columna, labelnodo++);
            Nodo * cadena = new Nodo("tString", "string", linea, columna, labelnodo++);
            $$->addHijo(cadena);
        }
        | tInt{
            $$= new Nodo("TIPO", "",linea, columna, labelnodo++);
            Nodo * integer = new Nodo("tInt", "int", linea, columna, labelnodo++);
            $$->addHijo(integer);

        }
        | tDouble{

            $$= new Nodo("TIPO", "",linea, columna, labelnodo++);
            Nodo * doble = new Nodo("tDouble", "double", linea, columna, labelnodo++);
            $$->addHijo(doble);

        }
        | tBool{

            $$= new Nodo("TIPO", "",linea, columna, labelnodo++);
            Nodo * buleano = new Nodo("tBool", "bool", linea, columna, labelnodo++);
            $$->addHijo(buleano);

        }
        | tChar{

            $$= new Nodo("TIPO", "",linea, columna, labelnodo++);
            Nodo * caracter = new Nodo("tChar", "char", linea, columna, labelnodo++);
            $$->addHijo(caracter);
        }
        ;

VARIABLES:  VISIBILIDAD tVar TIPO DIMENSIONES tDolar{
            $$ = new Nodo("VARIABLES", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nvar = new Nodo("tVar", "var", linea, columna, labelnodo++);
            $$->addHijo(nvar);
            $$->addHijo($3);
            $$->addHijo($4);
        }
        | error tDolar{

        }
        ;

DIMENSIONES: tArreglo LIDS ARREGLOS{
            $$ = new Nodo("DIMENSIONES", "", linea, columna, labelnodo++);
            Nodo * nArreglo = new Nodo("tArreglo", "arreglo", linea, columna, labelnodo++);
            $$->addHijo(nArreglo);
            $$->addHijo($2);
            $$->addHijo($3);

        }
        |    LNOMBRES{
            $$ = new Nodo("DIMENSIONES", "", linea, columna, labelnodo++);
            $$->addHijo($1);
        }
        ;

ARREGLOS: ARREGLOS ARREGLO{
            $$ = new Nodo("ARREGLOS", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            $$->addHijo($2);

        }
        | ARREGLO{
            $$ = new Nodo("ARREGLOS", "", linea, columna, labelnodo++);
            $$->addHijo($1);
        }
        ;

ARREGLO: tCA EXPRESION tCC{
            $$ = new Nodo("ARREGLO", "", linea, columna, labelnodo++);
            $$->addHijo($2);

        }
        | tCA EXPRESION tCC tIgual DIMENSION{
            $$ = new Nodo("ARREGLO", "", linea, columna, labelnodo++);
            $$->addHijo($2);
            $$->addHijo($5);
        }
        ;


DIMENSION: tLLA ASIGNARR{
            $$ = new Nodo("DIMENSION", "", linea, columna, labelnodo++);
            $$->addHijo($2);

        }
        ;

ASIGNARR: CARR tLLC{
            $$ = new Nodo("ASIGNARR", "", linea, columna, labelnodo++);
            $$->addHijo($1);

        }
        | LEXPS tLLC{
            $$ = new Nodo("ASIGNARR", "", linea, columna, labelnodo++);
            $$->addHijo($1);
        }
        ;

CARR: CARR tComa tLLA LEXPS tLLC{
            $$ = new Nodo("CARR", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            $$->addHijo($4);

        }
        | tLLA LEXPS tLLC{
            $$ = new Nodo("CARR", "", linea, columna, labelnodo++);
            $$->addHijo($2);
        }
        | error tLLC{

        }
        ;

LEXPS: LEXPS tComa ASIGN{
            $$ = new Nodo("LEXPS", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            $$->addHijo($3);
        }
        | ASIGN{
            $$ = new Nodo("LEXPS", "", linea, columna, labelnodo++);
            $$->addHijo($1);
        }
        ;

LNOMBRES: LNOMBRES tComa NOMBRES {
            $$ = new Nodo("LNOMBRES", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            $$->addHijo($3);

        }
        | NOMBRES{
            $$ = new Nodo("LNOMBRES", "", linea, columna, labelnodo++);
            $$->addHijo($1);
        }
        ;

NOMBRES: tId{
            $$ = new Nodo("NOMBRES", "", linea, columna, labelnodo++);
            QString ident = $1;
            Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
            $$->addHijo(nId);

        }
        | tId tIgual ASIGN{
            $$ = new Nodo("NOMBRES", "", linea, columna, labelnodo++);
            QString ident = $1;
            Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
            $$->addHijo(nId);
            $$->addHijo($3);
        }
        ;




METODOS: VISIBILIDAD MET{
            $$ = new Nodo("METODOS", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            $$->addHijo($2);
        }
        ;


MET:    TIPO PFS tId tParentesisA PARAMETROS tParentesisC tInterrA CUERPOFUNS tInterrC{
            $$ = new Nodo("MET", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            $$->addHijo($2);
            QString nId = $3;
            Nodo * nIdentificador = new Nodo("tId", nId, linea, columna, labelnodo++);
            $$->addHijo(nIdentificador);
            $$->addHijo($5);
            $$->addHijo($8);

        }
            | tVoid tId tParentesisA PARAMETROS tParentesisC tInterrA CUERPOVOIDS tInterrC{
                $$ = new Nodo("MET", "", linea, columna, labelnodo++);
                Nodo * nVoid = new Nodo("tVoid", "void", linea, columna, labelnodo++);
                $$->addHijo(nVoid);
                QString nId = $2;
                Nodo * nIdentificador = new Nodo("tId", nId, linea, columna, labelnodo++);
                $$->addHijo(nIdentificador);
                $$->addHijo($4);
                $$->addHijo($7);
            }
            | tMain tParentesisA  tParentesisC tInterrA CUERPOMAIN tInterrC{
                $$ = new Nodo("MET", "", linea, columna, labelnodo++);
                Nodo * nMain = new Nodo("tMain", "Main", linea, columna, labelnodo++);
                $$->addHijo(nMain);
                $$->addHijo($5);
            }
        ;


CUERPOFUNS: CUERPOFUNS CUERPOF{
                $$ = new Nodo("CUERPOFUNS", "", linea, columna, labelnodo++);
                $$->addHijo($1);
                $$->addHijo($2);
            }
            | CUERPOF{
                $$ = new Nodo("CUERPOFUNS", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            ;


CUERPOF: VARIABLES{
                $$ = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | RETORNAR{
                $$ = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | SIF{
                $$ = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                $$->addHijo($1);

            }
            | MIENTRASF{
                $$ = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | PARAF{
                $$ = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | NOMBRES tDolar{
                $$ = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                $$->addHijo($1);

            }
            | tId PARMET tIgual ASIGN tDolar{
                $$ = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                QString ident  = $1;
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                $$->addHijo(nId);
                $$->addHijo($2);
                $$->addHijo($4);
            }
            | tId PARMET tDolar{
                $$ = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                QString ident  = $1;
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                $$->addHijo(nId);
                $$->addHijo($2);
            }
            | tGraficar tParentesisA tId tParentesisC tDolar{
                $$ = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                Nodo *nGraf = new Nodo("Graficar", "Graficar", linea, columna, labelnodo++);
                $$->addHijo(nGraf);
                Nodo *nId = new Nodo("tId", $3, linea, columna, labelnodo++);
                $$->addHijo(nId);
            }
            | tPintarC tParentesisA EXPRESION tParentesisC tDolar{
                $$ = new Nodo("CUERPOF", "", linea, columna, labelnodo++);
                Nodo *nPintarC = new Nodo("tPintarC", "Pintar_Con", linea, columna, labelnodo++);
                $$->addHijo(nPintarC);
                $$->addHijo($3);
            }
            ;


RETORNAR: tRetorna COND tDolar{
                $$ = new Nodo("RETORNAR", "", linea, columna, labelnodo++);
                Nodo * nRetorna = new Nodo("tRetorna", "retorna", linea, columna, labelnodo++);
                $$->addHijo(nRetorna);
                $$->addHijo($2);

            }
            | tSalir tDolar{
                $$ = new Nodo("RETORNAR", "", linea, columna, labelnodo++);
                Nodo * nSalir = new Nodo("tSalir", "salir", linea, columna, labelnodo++);
                $$->addHijo(nSalir);
            }
            ;


CUERPOVOIDS: CUERPOVOIDS CUERPOV{
                $$ = new Nodo("CUERPOVOIDS", "", linea, columna, labelnodo++);
                $$->addHijo($1);
                $$->addHijo($2);

            }
            | CUERPOV{
                $$ = new Nodo("CUERPOVOIDS", "", linea, columna, labelnodo++);
                $$->addHijo($1);

            }
            ;


CUERPOV: VARIABLES{
                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | tRetorna tDolar{

                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                Nodo * nRetorna = new Nodo("tRetorna", "retorna", linea, columna, labelnodo++);
                $$->addHijo(nRetorna);

            }
            | tSalir tDolar{

                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                Nodo * nSalir = new Nodo("tSalir", "salir", linea, columna, labelnodo++);
                $$->addHijo(nSalir);
            }
            | SIV{
                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                $$->addHijo($1);

            }
            | MIENTRASV{
                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | PARAV{

                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | NOMBRES tDolar{
                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | tId PARMET tDolar{
                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                QString ident  = $1;
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                $$->addHijo(nId);
                $$->addHijo($2);
            }
            | tId PARMET tIgual ASIGN tDolar{
                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                QString ident  = $1;
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                $$->addHijo(nId);
                $$->addHijo($2);
                $$->addHijo($4);
            }
            | tGraficar tParentesisA tId tParentesisC tDolar{
                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                Nodo *nGraf = new Nodo("tGraficar", "Graficar", linea, columna, labelnodo++);
                $$->addHijo(nGraf);
                Nodo *nId = new Nodo("tId", $3, linea, columna, labelnodo++);
                $$->addHijo(nId);
            }
            | tPintarC tParentesisA EXPRESION tParentesisC tDolar{
                $$ = new Nodo("CUERPOV", "", linea, columna, labelnodo++);
                Nodo *nPintarC = new Nodo("tPintarC", "Pintar_Con", linea, columna, labelnodo++);
                $$->addHijo(nPintarC);
                $$->addHijo($3);
            }
            ;


CUERPOMAIN: CUERPOMAIN CUERPOM{
                $$ = new Nodo("CUERPOMAIN", "", linea, columna, labelnodo++);
                $$->addHijo($1);
                $$->addHijo($2);
            }
            | CUERPOM{
                $$ = new Nodo("CUERPOMAIN", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            ;


CUERPOM: VARIABLES{
                $$ = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                $$->addHijo($1);

            }
            | SI{
                $$ = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                $$->addHijo($1);

            }
            | MIENTRAS{
                $$ = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | PARA{

                $$ = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | tSalir tDolar{

                $$ = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                Nodo * nSalir = new Nodo("tSalir", "salir", linea, columna, labelnodo++);
                $$->addHijo(nSalir);
            }
            | NOMBRES tDolar{
                $$ = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
            | tId PARMET tDolar{
                $$ = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                QString ident  = $1;
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                $$->addHijo(nId);
                $$->addHijo($2);
            }
            | tId PARMET tIgual ASIGN tDolar{
                $$ = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                QString ident  = $1;
                Nodo * nId = new Nodo("tId", ident, linea, columna, labelnodo++);
                $$->addHijo(nId);
                $$->addHijo($2);
                $$->addHijo($4);
            }
            | tGraficar tParentesisA tId tParentesisC tDolar{
                $$ = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                Nodo *nGraf = new Nodo("tGraficar", "Graficar", linea, columna, labelnodo++);
                $$->addHijo(nGraf);
                Nodo *nId = new Nodo("tId", $3, linea, columna, labelnodo++);
                $$->addHijo(nId);
            }
            | tPintarC tParentesisA EXPRESION tParentesisC tDolar{
                $$ = new Nodo("CUERPOM", "", linea, columna, labelnodo++);
                Nodo *nPintarC = new Nodo("tPintarC", "Pintar_Con", linea, columna, labelnodo++);
                $$->addHijo(nPintarC);
                $$->addHijo($3);
            }
            ;


SI: tSi COND tInterrA CUERPOMAIN tInterrC{
                $$ = new Nodo("SI", "", linea, columna, labelnodo++);
                Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                $$->addHijo(nSi);
                $$->addHijo($2);
                $$->addHijo($4);
            }
            | tSi COND tInterrA CUERPOMAIN tInterrC SINO {
                $$ = new Nodo("SI", "", linea, columna, labelnodo++);
                Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                $$->addHijo(nSi);
                $$->addHijo($2);
                $$->addHijo($4);
                $$->addHijo($6);
            }
            ;

MIENTRAS: tHacer tInterrA CUERPOMAIN tInterrC tMientras COND tDolar{
                $$ = new Nodo ("MIENTRAS", "", linea, columna, labelnodo++);
                Nodo * nHacer = new Nodo("tHacer", "hacer", 0 ,0, labelnodo++ );
                $$->addHijo(nHacer);
                $$->addHijo($3);
                Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                $$->addHijo(nMientras);
                $$->addHijo($6);
            }
            | tMientras COND tInterrA CUERPOMAIN tInterrC{
                $$ = new Nodo("MIENTRAS", "", linea, columna, labelnodo++);
                Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                $$->addHijo(nMientras);
                $$->addHijo($2);
                $$->addHijo($4);
            }
            ;



SINO: tSino SI{
                $$ = new Nodo("SINO", "", linea, columna, labelnodo++);
                Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                $$->addHijo(nSino);
                $$->addHijo($2);

            }
            | tSino tInterrA CUERPOMAIN tInterrC{
                $$ = new Nodo("SINO", "", linea, columna, labelnodo++);
                Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                $$->addHijo(nSino);
                $$->addHijo($3);
            }
            ;

PARA:       tPara tParentesisA CPARA tParentesisC tInterrA CUERPOMAIN tInterrC{
                $$ = new Nodo("PARA", "", linea, columna, labelnodo++);
                Nodo * nPara = new Nodo("tPara", "para", linea, columna, labelnodo++);
                $$->addHijo(nPara);
                $$->addHijo($3);
                $$->addHijo($6);
                
            }
            ;

CPARA:      tInt tId tIgual EXPRESION tPtoComa COND tPtoComa EXPRESION{
                $$ = new Nodo("CPARA", "", linea, columna, labelnodo++);
                Nodo * nInt = new Nodo("tInt", "int", linea, columna, labelnodo++);
                $$->addHijo(nInt);
                QString identificador = $2;
                Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                $$->addHijo(nId);
                $$->addHijo($4);
                $$->addHijo($6);
                $$->addHijo($8);

            }
            | tId tIgual EXPRESION tPtoComa COND tPtoComa EXPRESION{
                $$ = new Nodo("CPARA", "", linea, columna, labelnodo++);
                QString identificador = $1;
                Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                $$->addHijo(nId);
                $$->addHijo($3);
                $$->addHijo($5);
                $$->addHijo($7);
            }
            ;

SIF: tSi COND tInterrA CUERPOFUNS tInterrC{
                            $$ = new Nodo("SIF", "", linea, columna, labelnodo++);
                            Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                            $$->addHijo(nSi);
                            $$->addHijo($2);
                            $$->addHijo($4);
                        }
                        | tSi COND tInterrA CUERPOFUNS tInterrC SINOF {
                            $$ = new Nodo("SIF", "", linea, columna, labelnodo++);
                            Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                            $$->addHijo(nSi);
                            $$->addHijo($2);
                            $$->addHijo($4);
                            $$->addHijo($6);
                        }
                        ;

            MIENTRASF: tHacer tInterrA CUERPOFUNS tInterrC tMientras COND tDolar{
                            $$ = new Nodo ("MIENTRASF", "", linea, columna, labelnodo++);
                            Nodo * nHacer = new Nodo("tHacer", "hacer", 0 ,0, labelnodo++ );
                            $$->addHijo(nHacer);
                            $$->addHijo($3);
                            Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                            $$->addHijo(nMientras);
                            $$->addHijo($6);
                        }
                        | tMientras COND tInterrA CUERPOFUNS tInterrC{
                            $$ = new Nodo("MIENTRAS", "", linea, columna, labelnodo++);
                            Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                            $$->addHijo(nMientras);
                            $$->addHijo($2);
                            $$->addHijo($4);
                        }
                        ;



            SINOF: tSino SIF{
                            $$ = new Nodo("SINOF", "", linea, columna, labelnodo++);
                            Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                            $$->addHijo(nSino);
                            $$->addHijo($2);

                        }
                        | tSino tInterrA CUERPOFUNS tInterrC{
                            $$ = new Nodo("SINOF", "", linea, columna, labelnodo++);
                            Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                            $$->addHijo(nSino);
                            $$->addHijo($3);
                        }
                        ;

            PARAF:       tPara tParentesisA CPARAF tParentesisC tInterrA CUERPOFUNS tInterrC{
                            $$ = new Nodo("PARAF", "", linea, columna, labelnodo++);
                            Nodo * nPara = new Nodo("tPara", "para", linea, columna, labelnodo++);
                            $$->addHijo(nPara);
                            $$->addHijo($3);
                            $$->addHijo($6);

                        }
                        ;

            CPARAF:      tInt tId tIgual EXPRESION tPtoComa COND tPtoComa EXPRESION{
                            $$ = new Nodo("CPARAF", "", linea, columna, labelnodo++);
                            Nodo * nInt = new Nodo("tInt", "int", linea, columna, labelnodo++);
                            $$->addHijo(nInt);
                            QString identificador = $2;
                            Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                            $$->addHijo(nId);
                            $$->addHijo($4);
                            $$->addHijo($6);
                            $$->addHijo($8);

                        }
                        | tId tIgual EXPRESION tPtoComa COND tPtoComa EXPRESION{
                            $$ = new Nodo("CPARAF", "", linea, columna, labelnodo++);
                            QString identificador = $1;
                            Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                            $$->addHijo(nId);
                            $$->addHijo($3);
                            $$->addHijo($5);
                            $$->addHijo($7);
                        }
                        ;


            SIV: tSi COND tInterrA CUERPOVOIDS tInterrC{
                            $$ = new Nodo("SIV", "", linea, columna, labelnodo++);
                            Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                            $$->addHijo(nSi);
                            $$->addHijo($2);
                            $$->addHijo($4);
                        }
                        | tSi COND tInterrA CUERPOVOIDS tInterrC SINOV {
                            $$ = new Nodo("SIV", "", linea, columna, labelnodo++);
                            Nodo * nSi = new Nodo("tSi", "si", linea, columna, labelnodo++);
                            $$->addHijo(nSi);
                            $$->addHijo($2);
                            $$->addHijo($4);
                            $$->addHijo($6);
                        }
                        ;

            MIENTRASV: tHacer tInterrA CUERPOVOIDS tInterrC tMientras COND tDolar{
                            $$ = new Nodo ("MIENTRASV", "", linea, columna, labelnodo++);
                            Nodo * nHacer = new Nodo("tHacer", "hacer", 0 ,0, labelnodo++ );
                            $$->addHijo(nHacer);
                            $$->addHijo($3);
                            Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                            $$->addHijo(nMientras);
                            $$->addHijo($6);
                        }
                        | tMientras COND tInterrA CUERPOVOIDS tInterrC{
                            $$ = new Nodo("MIENTRASV", "", linea, columna, labelnodo++);
                            Nodo * nMientras = new Nodo("tMientras", "mientras", linea, columna, labelnodo++);
                            $$->addHijo(nMientras);
                            $$->addHijo($2);
                            $$->addHijo($4);
                        }
                        ;



            SINOV: tSino SIV{
                            $$ = new Nodo("SINOV", "", linea, columna, labelnodo++);
                            Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                            $$->addHijo(nSino);
                            $$->addHijo($2);

                        }
                        | tSino tInterrA CUERPOVOIDS tInterrC{
                            $$ = new Nodo("SINOV", "", linea, columna, labelnodo++);
                            Nodo * nSino = new Nodo("tSino", "sino", linea, columna, labelnodo++);
                            $$->addHijo(nSino);
                            $$->addHijo($3);
                        }
                        ;

            PARAV:       tPara tParentesisA CPARAV tParentesisC tInterrA CUERPOVOIDS tInterrC{
                            $$ = new Nodo("PARAV", "", linea, columna, labelnodo++);
                            Nodo * nPara = new Nodo("tPara", "para", linea, columna, labelnodo++);
                            $$->addHijo(nPara);
                            $$->addHijo($3);
                            $$->addHijo($6);

                        }
                        ;

            CPARAV:      tInt tId tIgual EXPRESION tPtoComa COND tPtoComa EXPRESION{
                            $$ = new Nodo("CPARAV", "", linea, columna, labelnodo++);
                            Nodo * nInt = new Nodo("tInt", "int", linea, columna, labelnodo++);
                            $$->addHijo(nInt);
                            QString identificador = $2;
                            Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                            $$->addHijo(nId);
                            $$->addHijo($4);
                            $$->addHijo($6);
                            $$->addHijo($8);

                        }
                        | tId tIgual EXPRESION tPtoComa COND tPtoComa EXPRESION{
                            $$ = new Nodo("CPARAV", "", linea, columna, labelnodo++);
                            QString identificador = $1;
                            Nodo * nId = new Nodo("tId", identificador, linea, columna, labelnodo++);
                            $$->addHijo(nId);
                            $$->addHijo($3);
                            $$->addHijo($5);
                            $$->addHijo($7);
                        }
                        ;


PFS:        {

                $$ = new Nodo("PFS", "", linea, columna, labelnodo++);
                Nodo * nVacio = new Nodo("tVacio", "", linea, columna, labelnodo++);
                $$->addHijo(nVacio);
            }
            | PF{
                $$ = new Nodo("PFS", "", linea, columna, labelnodo++);
                $$->addHijo($1);

            }
            ;

PF:         PF tCA tCC{
                $$ = new Nodo("PF", "", linea, columna, labelnodo++);
                $$->addHijo($1);
                Nodo * nCA = new Nodo("tCA", "[" , linea, columna, labelnodo++);
                $$->addHijo(nCA);
                Nodo * nCC = new Nodo("tCC", "]" , linea, columna, labelnodo++);
                $$->addHijo(nCC);


            }
            | tCA tCC{
                $$ = new Nodo("PF", "", linea, columna, labelnodo++);
                Nodo * nCA = new Nodo("tCA", "[" , linea, columna, labelnodo++);
                $$->addHijo(nCA);
                Nodo * nCC = new Nodo("tCC", "]" , linea, columna, labelnodo++);
                $$->addHijo(nCC);

            }
            ;



PARAMETROS:{
                $$ = new Nodo("PARAMETROS", "", linea, columna, labelnodo++);
                Nodo * nVacio = new Nodo("tVacio", "", linea, columna, labelnodo++);
                $$->addHijo(nVacio);
           }
            | PARAMETRO{
                $$ = new Nodo("PARAMETROS", "", linea, columna, labelnodo++);
                $$->addHijo($1);
            }
        ;

PARAMETRO:  PARAMETRO tComa TIPO tId{
                $$ = new Nodo("PARAMETRO", "", linea, columna, labelnodo++);
                $$->addHijo($1);
                $$->addHijo($3);
                QString id = $4;
                Nodo * nId = new Nodo("tId", id, linea, columna, labelnodo++);
                $$->addHijo(nId);

            }
            | TIPO tId{
                $$ = new Nodo("PARAMETRO", "", linea, columna, labelnodo++);
                $$->addHijo($1);
                QString id = $2;
                Nodo * nId = new Nodo("tId", id, linea, columna, labelnodo++);
                $$->addHijo(nId);

            }
            ;

ASIGN: COND{
            $$ = new Nodo("ASIGN", "", linea, columna, labelnodo++);
            $$->addHijo($1);

        }
        ;

COND:   COND tOr COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nOr = new Nodo("tOr", "||" ,linea, columna, labelnodo++);
            $$->addHijo(nOr);
            $$->addHijo($3);

        }
        | COND tAnd COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nAnd = new Nodo("tAnd", "&&" ,linea, columna, labelnodo++);
            $$->addHijo(nAnd);
            $$->addHijo($3);
        }
        | COND tXor COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nXor = new Nodo("tXor", "&|" ,linea, columna, labelnodo++);
            $$->addHijo(nXor);
            $$->addHijo($3);
        }
        | COND tNand COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nNand = new Nodo("tNand", "!&&" ,linea, columna, labelnodo++);
            $$->addHijo(nNand);
            $$->addHijo($3);
        }
        | COND tNor COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nNor = new Nodo("tNor", "!||" ,linea, columna, labelnodo++);
            $$->addHijo(nNor);
            $$->addHijo($3);
        }
        | tNegacion COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            Nodo * nNegacion = new Nodo("tNegacion", "!" ,linea, columna, labelnodo++);
            $$->addHijo(nNegacion);
            $$->addHijo($2);
        }
        | COND tMayorIgual COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nMayorIgual = new Nodo("tMayorIgual", ">=" ,linea, columna, labelnodo++);
            $$->addHijo(nMayorIgual);
            $$->addHijo($3);
        }
        | COND tMenorIgual COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nMenorIgual = new Nodo("tMenorIgual", "<=" ,linea, columna, labelnodo++);
            $$->addHijo(nMenorIgual);
            $$->addHijo($3);
        }
        | COND tMenor COND {
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nMenor = new Nodo("tMenor", "<" ,linea, columna, labelnodo++);
            $$->addHijo(nMenor);
            $$->addHijo($3);
        }
        | COND tMayor COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nMayor = new Nodo("tMayor", ">" ,linea, columna, labelnodo++);
            $$->addHijo(nMayor);
            $$->addHijo($3);
        }
        | COND tIgualacion COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nIgualacion = new Nodo("tIgualacion", "==" ,linea, columna, labelnodo++);
            $$->addHijo(nIgualacion);
            $$->addHijo($3);
        }
        | COND tDiferenciacion COND{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nDiferenciacion = new Nodo("tDiferenciacion", "!=" ,linea, columna, labelnodo++);
            $$->addHijo(nDiferenciacion);
            $$->addHijo($3);
        }
        | EXPRESION{
            $$ = new Nodo("COND", "", linea, columna, labelnodo++);
            $$->addHijo($1);
        }
        ;



EXPRESION: EXPRESION tSuma EXPRESION{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nMas = new Nodo("tSuma", "+" ,linea, columna, labelnodo++);
            $$->addHijo(nMas);
            $$->addHijo($3);
        }
        | EXPRESION tResta EXPRESION{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nMenos = new Nodo("tResta", "-" ,linea, columna, labelnodo++);
            $$->addHijo(nMenos);
            $$->addHijo($3);
        }
        | EXPRESION tMultiplicacion EXPRESION{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nMultiplicacion = new Nodo("tMultiplicacion", "*" ,linea, columna, labelnodo++);
            $$->addHijo(nMultiplicacion);
            $$->addHijo($3);
        }
        | EXPRESION tDivision EXPRESION{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nDivision = new Nodo("tDivision", "/" ,linea, columna, labelnodo++);
            $$->addHijo(nDivision);
            $$->addHijo($3);
        }
        | EXPRESION tPotenciacion EXPRESION{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            $$->addHijo($1);
            Nodo * nPotenciacion = new Nodo("tPotenciacion", "^" ,linea, columna, labelnodo++);
            $$->addHijo(nPotenciacion);
            $$->addHijo($3);
        }
        | tParentesisA COND tParentesisC{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            Nodo * nPA = new Nodo("tParentesisA", "(" ,linea, columna, labelnodo++);
            $$->addHijo(nPA);
            $$->addHijo($2);
            Nodo * nPC = new Nodo("tParentesisC", ")" ,linea, columna, labelnodo++);
            $$->addHijo(nPC);

        }
        | tNumero{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString number = $1;
            Nodo * nNumero = new Nodo("tNumero", number, linea, columna, labelnodo++);
            $$->addHijo(nNumero);
        }
        | tDecimal{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString decimal = $1;
            Nodo * nDecimal = new Nodo("tDecimal", decimal, linea, columna, labelnodo++);
            $$->addHijo(nDecimal);
        }
        | tCadena{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString cadena = $1;
            Nodo * nCadena = new Nodo("tCadena", cadena, linea, columna, labelnodo++);
            $$->addHijo(nCadena);

        }
        | tCaracter{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString caracter = $1;
            Nodo * nCaracter = new Nodo("tCaracter", caracter, linea, columna, labelnodo++);
            $$->addHijo(nCaracter);
        }
        | tSalto{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString salto = $1;
            Nodo * nSalto = new Nodo("tSalto", salto, linea, columna, labelnodo++);
            $$->addHijo(nSalto);
        }
        | tTab{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString salto = $1;
            Nodo * nSalto = new Nodo("tSalto", salto, linea, columna, labelnodo++);
            $$->addHijo(nSalto);
        }
        | tPot{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString pot = $1;
            Nodo * nPot = new Nodo("tPot", pot, linea, columna, labelnodo++);
            $$->addHijo(nPot);
        }
        | tApostrofe{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            QString apostrofe = $1;
            Nodo * nApostrofe = new Nodo("tApostrofe", apostrofe, linea, columna, labelnodo++);
            $$->addHijo(nApostrofe);
        }
        | tTrue{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            Nodo * nTrue = new Nodo("tTrue", "true", linea, columna, labelnodo++);
            $$->addHijo(nTrue);

        }
        | tFalse{
            $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
            Nodo * nFalse = new Nodo("tFalse", "false", linea, columna, labelnodo++);
            $$->addHijo(nFalse);

        }
        | tId {
                    $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
                    QString id = $1;
                    Nodo * nIdentificador = new Nodo("tId", id, linea, columna, labelnodo++);
                    $$->addHijo(nIdentificador);
                }
                |
                tId PARMET {
                    $$ = new Nodo("EXPRESION", "", linea, columna, labelnodo++);
                    QString id = $1;
                    Nodo * nIdentificador = new Nodo("tId", id, linea, columna, labelnodo++);
                    $$->addHijo(nIdentificador);
                    $$->addHijo($2);
                }
                ;






PARMET:         tParentesisA LEXPS tParentesisC{
                    $$ = new Nodo("PARMET", "", linea, columna, labelnodo++);
                    $$->addHijo($2);

                }
                | tParentesisA ARRSM tParentesisC{
                    $$ = new Nodo("PARMET", "", linea, columna, labelnodo++);
                    $$->addHijo($2);

                }
                | tParentesisA tParentesisC{
                    $$ = new Nodo("PARMET", "", linea, columna, labelnodo++);

                }
                | ARRSM{
                    $$ = new Nodo("PARMET", "", linea, columna, labelnodo++);
                    $$->addHijo($1);
                }
                ;

ARRSM: ARRSM PARARRM{
                    $$ = new Nodo("ARRSM", "", linea, columna, labelnodo++);
                    $$->addHijo($1);
                    $$->addHijo($2);

                }
                | PARARRM{
                    $$ = new Nodo("ARRSM", "", linea, columna, labelnodo++);
                    $$->addHijo($1);
                }
                ;


PARARRM: tCA EXPRESION tCC{
                    $$ = new Nodo("ARREGLO", "", linea, columna, labelnodo++);
                    $$->addHijo($2);

                }
                ;




%%

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

