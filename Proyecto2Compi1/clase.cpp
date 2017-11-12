#include "clase.h"

Clase::Clase()
{
    this->imports = new QList<QString>();
    this->listMet = new QList<Metodos*>();
    this->listVar = new QList<Variables*>();
    this->varC = new Variables();
    this->metC = new Metodos();

}

QString Clase::getNombre() const
{
    return this->nombre;
}

void Clase::setNombre(const QString &value)
{
    this->nombre = value;
}

QList<Variables*> *Clase::getListVar() const
{
    return this->listVar;
}

void Clase::setListVar(Variables *value)
{
    QString nombre = value->getNombre();
    Variables * vaBusq = this->buscarVar(nombre);
    if (vaBusq == nullptr){
        this->listVar->append(value);
        if (listVar->count() > 1 && value->getValor2() != -1){
            for(int i = listVar->count()-2; i >= 0 ; i--){
                if (this->listVar->at(i)->getValor2() == -1 && this->listVar->at(i)->getFila() == value->getFila()){
                    if (this->listVar->at(i)->getTipo() == "string"){
                        this->listVar->at(i)->setValor(value->getValor());
                    }else if (this->listVar->at(i)->getTipo() == "int" || this->listVar->at(i)->getTipo() == "double"){
                        this->listVar->at(i)->setValor3(value->getValor3());
                    }else if (this->listVar->at(i)->getTipo() == "bool"){
                        this->listVar->at(i)->setValor4(value->getValor4());
                    }else{
                        this->listVar->at(i)->setValor5(value->getValor5());
                    }

                }else {
                    return;
                }
            }
        }
        return;
    }
    QMessageBox msgBox;
    msgBox.setText("ERROR Semantico: Variable Tipo: "+ value->getTipo() +" Nombre: "+value->getNombre()+ " ya declarada" );
    msgBox.exec();
    vaBusq = nullptr;
    delete vaBusq;
    value = nullptr;
    delete value;
}

QList<Metodos*> *Clase::getListMet() const
{
    return this->listMet;
}

void Clase::setListMet(Metodos *value)
{
    Metodos *varMet = this->buscarMetodo(value->getNombre());
    if (varMet == nullptr){
        this->listMet->append(value);
        return;
    }
    QMessageBox msgBox;
    msgBox.setText("ERROR Semantico: Metodo ya declarado");
    msgBox.exec();
}

Variables *Clase::getVarC() const
{
    return this->varC;
}

void Clase::setVarC(Variables *value)
{
    this->varC = value;
}

QString Clase::imprimirVariables()
{
    QString resultado("Variables G");
    if (!this->listVar->empty()){
        for(int i = 0; i < this->listVar->count() ; i++ ){
            QString tipo = this->listVar->at(i)->getTipo();
            QString nombre = this->listVar->at(i)->getNombre();
            QString valor;
            if (tipo == "string"){
                valor.append(this->listVar->at(i)->getValor());
            }else if (tipo == "int" || tipo == "double"){
                double numero = this->listVar->at(i)->getValor3();
                valor.append(QString::number(numero));
            }else if (tipo == "bool"){
                if (this->listVar->at(i)->getValor4()){
                    valor.append("true");
                }else {
                    valor.append("false");
                }
            }else{
                valor.append(this->listVar->at(i)->getValor5());
            }
            QString fila = QString::number(this->listVar->at(i)->getFila());
            QString col = QString::number(this->listVar->at(i)->getCol());
            resultado.append("tipo: ");
            resultado.append(tipo);
            resultado.append(" ");
            resultado.append("nombre: ");
            resultado.append(nombre);
            resultado.append(" ");
            resultado.append("valor: ");
            resultado.append(valor);
            resultado.append(" ");
            resultado.append("fila: ");
            resultado.append(fila);
            resultado.append(" ");
            resultado.append("columna: ");
            resultado.append(col);
            resultado.append("\n");
        }
    }

    qInfo() << resultado;
    return resultado;
}

Variables *Clase::buscarOp(int linea)
{
    for (int i = 0; i < this->listVar->count() ; i++){
        if (this->listVar->at(i)->getFila() == linea){
            return this->listVar->at(i);
        }
    }
    return nullptr;
}

Variables *Clase::buscarVar(QString nombre)
{
    for (int i = 0; i < this->listVar->count() ; i++){
        int comparacion = QString::compare(this->listVar->at(i)->getNombre(), nombre);
        if (comparacion == 0){
            return this->listVar->at(i);
        }
    }
    return nullptr;
}

bool Clase::getVisibilidad() const
{
    return visibilidad;
}

void Clase::setVisibilidad(bool value)
{
    visibilidad = value;
}

Metodos *Clase::getMetC() const
{
    return metC;
}

void Clase::setMetC(Metodos *value)
{
    metC = value;
}

QString Clase::imprimirMetodos()
{
    QString resultado("METODO ");
    if (!this->listMet->empty()){
        for (int i = 0; i < listMet->count() ; i++){
            QString tipo = this->listMet->at(i)->getTipo();
            QString nombre = this->listMet->at(i)->getNombre();
            QString valor;
            if (tipo == "string"){
                valor.append(this->listMet->at(i)->getValor());
            }else if (tipo == "double" || tipo == "int"){
                valor.append(QString::number(this->listMet->at(i)->getValor3()));
            }else if (tipo == "bool"){
                if (this->listMet->at(i)->getValor4()){
                    valor.append("true");
                }else
                    valor.append("false");
            }else if (tipo == "char"){
                valor.append(this->listMet->at(i)->getValor5());
            }else {
                valor.append("-1");
            }
            QString columna = QString::number(this->listMet->at(i)->getCol());
            QString fila = QString::number(this->listMet->at(i)->getFila());
            resultado.append("tipo: "+tipo+ " nombre: "+nombre+" valor: "+valor+ " columna: "+ columna+" fila: "+fila);
            QString s1 = this->listMet->at(i)->imprimirParametros();
            QString s2 = this->listMet->at(i)->imprimirVariablesL();
            this->listMet->at(i)->imprimirValRets();

        }
        qInfo() << resultado;
        return resultado;
    }

    return resultado;
}

Metodos *Clase::buscarMetodo(QString nombre)
{
    for (int i = 0; i < this->listMet->count() ; i++){
        int comparacion = QString::compare(this->listMet->at(i)->getNombre(), nombre);
        if(comparacion == 0){
            return this->listMet->at(i);
        }
    }
    return nullptr;
}

Metodos *Clase::getCMain() const
{
    return cMain;
}

void Clase::setCMain(Metodos *value)
{
    cMain = value;
}
