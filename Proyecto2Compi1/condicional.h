#ifndef CONDICIONAL_H
#define CONDICIONAL_H
#include "variables.h"
#include <metodos.h>
#include <bucle.h>
#include "qlist.h"
#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "stdio.h"


using namespace std;
class Metodos;
class Bucle;

class Condicional
{
public:
    Condicional();
    QString getNombre() const;
    void setNombre(const QString &value);

    Variables *getVarCond() ;
    void setVarCond(Variables *value);


    QList<Variables *> *listVar;
    QList<Condicional *> *listCondition;
    QList<Metodos *> *listMetodos;
    QList<Bucle *> *listBucles;
private:
    QString nombre;
    Variables *varCond;
};

#endif // CONDICIONAL_H
