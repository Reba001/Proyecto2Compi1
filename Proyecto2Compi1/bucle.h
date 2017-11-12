#ifndef BUCLE_H
#define BUCLE_H
#include "qstring.h"
#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "stdio.h"
#include "variables.h"
#include <metodos.h>
#include <condicional.h>
using namespace std;
class Condicional;
class Metodos;

class Bucle
{
public:
    Bucle();

    Bucle(Variables *varInicio, double operacion, QString &nombre);

    Variables *getVarInicio();
    void setVarInicio(Variables *value);

    double getOperacion() const;
    void setOperacion(double value);

    bool getOperacion2() const;
    void setOperacion2(bool value);

    QString getNombre() const;
    void setNombre(const QString &value);

    QList<Variables*> *listVar;
    QList<Bucle*> *listBucle;
    QList<Metodos *> *listMetodologico;
    QList<Condicional*> *listCond;


    void procedimiento();

private:
    Variables *varInicio;
    double operacion;
    bool operacion2;
    QString nombre;

};

#endif // BUCLE_H
