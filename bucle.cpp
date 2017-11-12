#include "bucle.h"

Bucle::Bucle()
{
    this->listMetodologico = new QList<Metodos *>();
    this->listVar = new QList<Variables *>();
    this->listBucle = new QList<Bucle*>();
    this->listCond = new QList<Condicional*>();
    this->varInicio = nullptr;


}

Bucle::Bucle(Variables *varInicio, double operacion, QString &nombre)
{
    this->varInicio = varInicio;
    this->operacion = operacion;
    this->nombre = nombre;
    this->listMetodologico = new QList<Metodos *>();
    this->listVar = new QList<Variables*>();
    this->listBucle = new QList<Bucle*>();
    this->listCond = new QList<Condicional*>();

}

void Bucle::procedimiento()
{
    if (this->nombre == "DO"){

    }else{

    }

}

Variables *Bucle::getVarInicio()
{
    return this->varInicio;
}

void Bucle::setVarInicio(Variables *value)
{
    this->varInicio = value;
}

double Bucle::getOperacion() const
{
    return operacion;
}

void Bucle::setOperacion(double value)
{
    operacion = value;
}

bool Bucle::getOperacion2() const
{
    return operacion2;
}

void Bucle::setOperacion2(bool value)
{
    operacion2 = value;
}

QString Bucle::getNombre() const
{
    return nombre;
}

void Bucle::setNombre(const QString &value)
{
    nombre = value;
}


