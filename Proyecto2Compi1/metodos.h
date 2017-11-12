#ifndef METODOS_H
#define METODOS_H
#include "qstring.h"
#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "stdio.h"
#include "qlist.h"
#include "variables.h"
#include "bucle.h"
#include <condicional.h>
#include "errorsemantico.h"
#include "qdebug.h"
#include "qmessagebox.h"
#include "nodo.h"
using namespace std;

class Bucle;
class Condicional;
class Metodos
{
public:
    Metodos();
    Metodos(QString tipo, QString nombre, QString valor, int col, int fila);
    Metodos(QString tipo, QString nombre, int valor2, int col, int fila);
    Metodos(QString tipo, QString nombre, double valor3, int col, int fila);
    Metodos(QString tipo, QString nombre, bool valor4, int col, int fila);
    Metodos(QString tipo, QString nombre, char valor5, int col, int fila);

    QString getTipo() const;
    void setTipo(const QString &value);

    QString getNombre() const;
    void setNombre(const QString &value);

    QString getValor() const;
    void setValor(const QString &value);

    int getValor2() const;
    void setValor2(int value);

    double getValor3() const;
    void setValor3(double value);

    bool getValor4() const;
    void setValor4(bool value);

    char getValor5() const;
    void setValor5(char value);

    int getCol() const;

    void setCol(int value);

    int getFila() const;
    void setFila(int value);


    QList<Bucle*> * listBucle;
    QList<Metodos*> * listMetodos;
    QList<Condicional*> * listCond;
    void setVariables(Variables *var);
    void setParametros(Variables *var);

    bool getAccesibilidad() const;
    void setAccesibilidad(bool value);
    QString imprimirParametros();

    QList<Variables *> *getListaParametros() const;
    void setListaParametros(QList<Variables *> *value);

    QString imprimirVariablesL();
    Variables * buscarVar(QString nombre);

    void setRetorno(Variables *value);
    void imprimirValRets();
    Variables *buscarParametro(QString nombre);

    Nodo *getCuerpoM() const;
    void setCuerpoM(Nodo *value);
    Variables *getPopParametro();


private:
    QString tipo;
    QString nombre;
    QString valor;
    int valor2;
    double valor3;
    bool valor4;
    char valor5;
    int col;
    int fila;
    bool accesibilidad;
    QList<Variables*> * listaVariablesLocales;
    QList<Variables*> * listaParametros;
    Variables * valRetorno;
    Nodo *cuerpoM;
}

;

#endif // METODOS_H
