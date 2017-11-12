#include "condicional.h"

Condicional::Condicional()
{
    this->listBucles = new QList<Bucle *>();
    this->listCondition = new QList<Condicional*>();
    this->listMetodos = new QList<Metodos *>();
    this->listVar = new QList<Variables*>();
}

QString Condicional::getNombre() const
{
    return nombre;
}

void Condicional::setNombre(const QString &value)
{
    nombre = value;
}

Variables *Condicional::getVarCond()
{
    return this->varCond;
}

void Condicional::setVarCond(Variables *value)
{
    this->varCond = value;
}
