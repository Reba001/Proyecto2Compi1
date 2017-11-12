#ifndef CLASE_H
#define CLASE_H
#include "qstring.h"
#include "qlist.h"
#include "qdebug.h"
#include "variables.h"
#include "metodos.h"
#include "qmessagebox.h"
class Clase
{
public:
    Clase();

    QString getNombre() const;
    void setNombre(const QString &value);

    QList<Variables*> *getListVar() const;
    void setListVar(Variables *value);

    QList<Metodos*> *getListMet() const;
    void setListMet(Metodos *value);

    QList<QString> *imports;
    Variables *getVarC() const;
    void setVarC(Variables *value);
    QString imprimirVariables();

    Variables * buscarOp(int linea);
    Variables * buscarVar(QString nombre);

    void aregrarValor();
    bool getVisibilidad() const;
    void setVisibilidad(bool value);

    Metodos *getMetC() const;
    void setMetC(Metodos *value);

    QString imprimirMetodos();
    Metodos * buscarMetodo(QString nombre);

    Metodos *getCMain() const;
    void setCMain(Metodos *value);

private:
    Variables *varC;
    QString nombre;
    bool visibilidad;
    QList<Variables*> *listVar;
    QList<Metodos*> *listMet;
    Metodos * metC;
    Metodos * cMain;


};

#endif // CLASE_H
