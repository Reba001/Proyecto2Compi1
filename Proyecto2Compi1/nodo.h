#ifndef NODO_H
#define NODO_H
#include <stdio.h>
#include <stdlib.h>
#include <QString>
#include <iostream>
#include "nodo.h"
#include <QList>
#include <fstream>

using namespace std;
typedef struct Nodo Nodo;
struct Nodo
{
private:
    QString token ;
    QString lexema ;
    int fila ;
    int columna;
    int idNodo;

public:

    QList<Nodo*> *hijos;
    Nodo();
    int getIdNodo();
    Nodo(QString token, QString lexema, int fila, int columna, int idNodo);
    void addHijo(Nodo *hijo);
    QString getToken();
    QString getLexema();
    void GraficarArbol(Nodo *raiz);
    void graphArbol(Nodo *actual, QString &graph);

    int getFila() const;
    void setFila(int value);
    int getColumna() const;
    void setColumna(int value);
};
#endif // NODO_H
