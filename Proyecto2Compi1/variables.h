#ifndef VARIABLES_H
#define VARIABLES_H
#include "qstring.h"
#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "stdio.h"

using namespace std;
class Variables
{
public:

    Variables(QString tipo, QString nombre, QString valor, int col, int fila);
    Variables(QString tipo, QString nombre, int valor2, int col, int fila);
    Variables(QString tipo, QString nombre, double valor3, int col, int fila);
    Variables(QString tipo, QString nombre, bool valor4, int col, int fila);
    Variables(QString tipo, QString nombre, char valor5, int col, int fila);
    Variables();
    QString to_string();

    QString getTipo() const;

    QString getNombre() const;

    QString getValor() const;

    int getValor2() const;

    double getValor3() const;

    bool getValor4() const;

    char getValor5() const;

    int getCol() const;

    int getFila() const;

    void setFila(int value);

    void setCol(int value);

    void setValor5(char value);

    void setValor4(bool value);

    void setValor3(double value);

    void setValor2(int value);

    void setValor(const QString &value);

    void setNombre(const QString &value);

    void setTipo(const QString &value);

    bool getVisibilidad() const;
    void setVisibilidad(bool value);

    QString getAmbMetodo() const;
    void setAmbMetodo(const QString &value);

private:
    bool visibilidad;
    QString tipo;
    QString nombre;
    QString valor;
    int valor2;
    double valor3;
    bool valor4;
    char valor5;
    int col;
    int fila;
    QString ambMetodo;


};

#endif // VARIABLES_H
