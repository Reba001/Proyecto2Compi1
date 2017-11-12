#include "variables.h"

Variables::Variables()
{

}

QString Variables::to_string()
{

    return "vacio";
}

QString Variables::getTipo() const
{
    return tipo;
}

QString Variables::getNombre() const
{
    return nombre;
}

QString Variables::getValor() const
{
    return valor;
}

int Variables::getValor2() const
{
    return valor2;
}

double Variables::getValor3() const
{
    return valor3;
}

bool Variables::getValor4() const
{
    return valor4;
}

char Variables::getValor5() const
{
    return valor5;
}

int Variables::getCol() const
{
    return col;
}

int Variables::getFila() const
{
    return this->fila;
}

void Variables::setFila(int value)
{
    this->fila = value;
}

void Variables::setCol(int value)
{
    col = value;
}

void Variables::setValor5(char value)
{
    valor5 = value;
}

void Variables::setValor4(bool value)
{
    valor4 = value;
}

void Variables::setValor3(double value)
{
    valor3 = value;
}

void Variables::setValor2(int value)
{
    valor2 = value;
}

void Variables::setValor(const QString &value)
{
    valor = value;
}

void Variables::setNombre(const QString &value)
{
    nombre = value;
}

void Variables::setTipo(const QString &value)
{
    tipo = value;
}

bool Variables::getVisibilidad() const
{
    return visibilidad;
}

void Variables::setVisibilidad(bool value)
{
    visibilidad = value;
}

QString Variables::getAmbMetodo() const
{
    return ambMetodo;
}

void Variables::setAmbMetodo(const QString &value)
{
    ambMetodo = value;
}

Variables::Variables(QString tipo, QString nombre, QString valor, int col, int fila)
{
    this->tipo= tipo;
    this->nombre = nombre;
    this->valor = valor;
    this->col = col;
    this->fila = fila;

}

Variables::Variables(QString tipo, QString nombre, int valor2, int col, int fila)
{
    this->tipo = tipo;
    this->nombre = nombre;
    this->valor2 = valor2;
    this->col = col;
    this->fila = fila;
}

Variables::Variables(QString tipo, QString nombre, double valor3, int col, int fila)
{
    this->tipo = tipo;
    this->nombre = nombre;
    this->valor3 = valor3;
    this->col = col;
    this->fila = fila;

}

Variables::Variables(QString tipo, QString nombre, bool valor4, int col, int fila)
{
    this->tipo = tipo;
    this->nombre = nombre;
    this->valor4 = valor4;
    this->col = col;
    this->fila = fila;

}

Variables::Variables(QString tipo, QString nombre, char valor5, int col, int fila)
{
    this->tipo = tipo;
    this->nombre = nombre;
    this->valor5 = valor5;
    this->col = col;
    this->fila = fila;
}
