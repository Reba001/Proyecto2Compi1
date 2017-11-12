#include "metodos.h"

Metodos::Metodos()
{

    this->listaVariablesLocales = new QList<Variables*>();
    this->listBucle = new QList<Bucle*>();
    this->listCond = new QList<Condicional*>();
    this->listMetodos = new QList<Metodos*>();
    this->listaParametros = new QList<Variables*>();
    this->valRetorno = new Variables();
    this->cuerpoM = nullptr;
}

Metodos::Metodos(QString tipo, QString nombre, QString valor, int col, int fila)
{
    this->tipo = tipo;
    this->nombre = nombre;
    this->valor = valor;
    this->col = col;
    this->fila = fila;
    this->listaVariablesLocales = new QList<Variables*>();
    this->listBucle = new QList<Bucle*>();
    this->listCond = new QList<Condicional*>();
    this->listMetodos = new QList<Metodos*>();
    this->listaParametros = new QList<Variables*>();
    this->valRetorno = new Variables();
    this->cuerpoM = nullptr;

}

Metodos::Metodos(QString tipo, QString nombre, int valor2, int col, int fila)
{
    this->tipo = tipo;
    this->nombre = nombre;
    this->valor2 = valor2;
    this->col = col;
    this->fila = fila;
    this->listaVariablesLocales = new QList<Variables*>();
    this->listBucle = new QList<Bucle*>();
    this->listCond = new QList<Condicional*>();
    this->listMetodos = new QList<Metodos*>();
    this->listaParametros = new QList<Variables*>();
    this->valRetorno = new Variables();
    this->cuerpoM = nullptr;
}

Metodos::Metodos(QString tipo, QString nombre, double valor3, int col, int fila)
{
    this->tipo = tipo;
    this->nombre = nombre;
    this->valor3 = valor3;
    this->col = col;
    this->fila = fila;
    this->listaVariablesLocales = new QList<Variables*>();
    this->listBucle = new QList<Bucle*>();
    this->listCond = new QList<Condicional*>();
    this->listMetodos = new QList<Metodos*>();
    this->listaParametros = new QList<Variables*>();
    this->valRetorno = new Variables();
    this->cuerpoM = nullptr;
}

Metodos::Metodos(QString tipo, QString nombre, bool valor4, int col, int fila)
{
    this->tipo = tipo;
    this->nombre= nombre;
    this->valor4 = valor4;
    this->col = col;
    this->fila = fila;
    this->listaVariablesLocales = new QList<Variables*>();
    this->listBucle = new QList<Bucle*>();
    this->listCond = new QList<Condicional*>();
    this->listMetodos = new QList<Metodos*>();
    this->listaParametros = new QList<Variables*>();
    this->valRetorno = new Variables();
    this->cuerpoM = nullptr;
}

Metodos::Metodos(QString tipo, QString nombre, char valor5, int col, int fila)
{
    this->tipo = tipo;
    this->nombre = nombre;
    this->valor5 = valor5;
    this->col = col;
    this->fila = fila;
    this->listaVariablesLocales = new QList<Variables*>();
    this->listBucle = new QList<Bucle*>();
    this->listCond = new QList<Condicional*>();
    this->listMetodos = new QList<Metodos*>();
    this->listaParametros = new QList<Variables*>();
    this->valRetorno = new Variables();
    this->cuerpoM = nullptr;
}

void Metodos::setVariables(Variables *var)
{
    if(var->getNombre() == "salir"){
        qInfo() << "Error Semantico declaracion salir fuera de un bucle";

    }else{

        QString nombre = var->getNombre();
        Variables * vaBusq = this->buscarVar(nombre);
        Variables * varBus2 = this->buscarParametro(nombre);
        if (vaBusq == nullptr && varBus2 == nullptr){
            this->listaVariablesLocales->append(var);
            if (listaVariablesLocales->count() > 1 && var->getValor2() != -1){
                for(int i = listaVariablesLocales->count()-2; i >= 0 ; i--){
                    if (this->listaVariablesLocales->at(i)->getValor2() == -1 && this->listaVariablesLocales->at(i)->getFila() == var->getFila()){
                        if (this->listaVariablesLocales->at(i)->getTipo() == "string"){
                            this->listaVariablesLocales->at(i)->setValor(var->getValor());
                        }else if (this->listaVariablesLocales->at(i)->getTipo() == "int" || this->listaVariablesLocales->at(i)->getTipo() == "double"){
                            this->listaVariablesLocales->at(i)->setValor3(var->getValor3());
                        }else if (this->listaVariablesLocales->at(i)->getTipo() == "bool"){
                            this->listaVariablesLocales->at(i)->setValor4(var->getValor4());
                        }else{
                            this->listaVariablesLocales->at(i)->setValor5(var->getValor5());
                        }

                    }else {
                        return;
                    }
                }
            }
            return;
        }
        QMessageBox msgBox;
        msgBox.setText("ERROR Semantico: Variable Tipo: "+ var->getTipo() +" Nombre: "+var->getNombre()+ " ya declarada" );
        msgBox.exec();
        vaBusq = nullptr;
        delete vaBusq;
        var = nullptr;
        delete var;
    }

}

QString Metodos::getTipo() const
{
    return tipo;
}

void Metodos::setTipo(const QString &value)
{
    tipo = value;
}

QString Metodos::getNombre() const
{
    return nombre;
}

void Metodos::setNombre(const QString &value)
{
    nombre = value;
}

QString Metodos::getValor() const
{
    return valor;
}

void Metodos::setValor(const QString &value)
{
    valor = value;
}

int Metodos::getValor2() const
{
    return valor2;
}

void Metodos::setValor2(int value)
{
    valor2 = value;
}

double Metodos::getValor3() const
{
    return valor3;
}

void Metodos::setValor3(double value)
{
    valor3 = value;
}

bool Metodos::getValor4() const
{
    return valor4;
}

void Metodos::setValor4(bool value)
{
    valor4 = value;
}

char Metodos::getValor5() const
{
    return valor5;
}

void Metodos::setValor5(char value)
{
    valor5 = value;
}

int Metodos::getCol() const
{
    return col;
}

void Metodos::setCol(int value)
{
    col = value;
}

int Metodos::getFila() const
{
    return fila;
}

void Metodos::setFila(int value)
{
    fila = value;
}

void Metodos::setParametros(Variables *var)
{
    Variables *varPar = this->buscarParametro(var->getNombre());
    if (varPar == nullptr){
        this->listaParametros->append(var);
    }else {
        qInfo() << "Error Semantico: Nombre de Parametro ya utilizado";
    }
}

bool Metodos::getAccesibilidad() const
{
    return accesibilidad;
}

void Metodos::setAccesibilidad(bool value)
{
    accesibilidad = value;
}

QString Metodos::imprimirParametros()
{
    QString resultado("PARAMETROS de: "+ this->nombre);
    if(!this->listaParametros->empty()){
        for (int i = 0; i < listaParametros->count() ; i++){
            QString tipo = this->listaParametros->at(i)->getTipo();
            QString nombre = this->listaParametros->at(i)->getNombre();
            QString valor;
            if (tipo == "string"){
                valor.append(this->listaParametros->at(i)->getValor());
            }else if (tipo == "int" || tipo == "double"){
                valor.append(QString::number(this->listaParametros->at(i)->getValor3()));
            }else if (tipo == "bool"){
                if (this->listaParametros->at(i)->getValor4()){
                    valor.append("true");
                }else{
                    valor.append("false");
                }
            }else{
                valor.append(this->listaParametros->at(i)->getValor5());
            }
            QString columna = QString::number(this->listaParametros->at(i)->getCol());
            QString fila = QString::number(this->listaParametros->at(i)->getFila());

            resultado.append("tipo: ");
            resultado.append(tipo);
            resultado.append(" nombre: ");
            resultado.append(nombre);
            resultado.append(" valor: ");
            resultado.append(valor);
            resultado.append(" columna: ");
            resultado.append(columna);
            resultado.append(" fila: ");
            resultado.append(fila);
        }
        qInfo() << resultado;
        return resultado;

    }
    return "nuay nada";
}

QList<Variables *> *Metodos::getListaParametros() const
{
    return this->listaParametros;
}

void Metodos::setListaParametros(QList<Variables *> *value)
{
    listaParametros = value;
}

QString Metodos::imprimirVariablesL()
{
    QString resultado("Variables Locales de: "+ this->nombre);
    if (!this->listaVariablesLocales->empty()){
        for(int i = 0; i < this->listaVariablesLocales->count() ; i++ ){
            QString tipo = this->listaVariablesLocales->at(i)->getTipo();
            QString nombre = this->listaVariablesLocales->at(i)->getNombre();
            QString valor;
            if (tipo == "string"){
                valor.append(this->listaVariablesLocales->at(i)->getValor());
            }else if (tipo == "int" || tipo == "double"){
                double numero = this->listaVariablesLocales->at(i)->getValor3();
                valor.append(QString::number(numero));
            }else if (tipo == "bool"){
                if (this->listaVariablesLocales->at(i)->getValor4()){
                    valor.append("true");
                }else {
                    valor.append("false");
                }
            }else{
                valor.append(this->listaVariablesLocales->at(i)->getValor5());
            }
            QString fila = QString::number(this->listaVariablesLocales->at(i)->getFila());
            QString col = QString::number(this->listaVariablesLocales->at(i)->getCol());
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
        qInfo() << resultado;
        return resultado;
    }

    return "nuay ningun valor :'v tu codigo es basura como tu vida";
}

Variables *Metodos::buscarVar(QString nombre)
{
    for (int i = 0; i < this->listaVariablesLocales->count() ; i++){
        int comparacion = QString::compare(this->listaVariablesLocales->at(i)->getNombre(), nombre);
        if (comparacion == 0){
            return this->listaVariablesLocales->at(i);
        }
    }
    return nullptr;
}

void Metodos::setRetorno(Variables *value)
{

    this->valRetorno = value;

}

void Metodos::imprimirValRets()
{
    QString rS;
    if(!this->valRetorno->getNombre().isEmpty()){
        rS.append("tipo: "+ this->tipo+ " nombre: retorno valor: ");
        if ( this->tipo == "string"){
            rS.append(this->valRetorno->getValor());
        }else if (this->tipo == "int" || this->tipo == "double"){
            rS.append(QString::number(this->valRetorno->getValor3()));
        }else if (this->tipo == "bool"){
            if (this->valRetorno->getValor4()){
                rS.append("true");
            }else{
                rS.append("false");
            }
        }else {
            rS.append(this->valRetorno->getValor5());
        }
    }
    qInfo() << rS;
}

Variables *Metodos::buscarParametro(QString nombre)
{
    if (!this->listaParametros->empty()){
        for (int i = 0; i < this->listaParametros->count() ; i++){
            int comparacion = QString::compare(this->listaParametros->at(i)->getNombre(), nombre);
            if (comparacion == 0){
                return this->listaParametros->at(i);
            }
        }
    }
    return nullptr;
}

Nodo *Metodos::getCuerpoM() const
{
    return cuerpoM;
}

void Metodos::setCuerpoM(Nodo *value)
{
    cuerpoM = value;
}

Variables *Metodos::getPopParametro()
{
    if (!this->listaParametros->empty()){
        Variables *parVar = this->listaParametros->at(0);
        this->listaParametros->pop_front();
        return parVar;
    }
    return nullptr;
}

