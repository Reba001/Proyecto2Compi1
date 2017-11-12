#include "nodo.h"
#include "qdebug.h"

int Nodo::getFila() const
{
    return fila;
}

void Nodo::setFila(int value)
{
    fila = value;
}

int Nodo::getColumna() const
{
    return columna;
}

void Nodo::setColumna(int value)
{
    columna = value;
}

Nodo::Nodo()
{

}



Nodo::Nodo(QString token, QString lexema, int fila, int columna, int idNodo)
{
    this->token = token;
    this->lexema = lexema;
    this->fila = fila;
    this->columna = columna;
    this->hijos = new QList<Nodo*>();
    this->idNodo = idNodo;
}

void Nodo::addHijo(Nodo *hijo){
    this->hijos->append(hijo);

}

QString Nodo::getToken()
{
    return this->token;

}

QString Nodo::getLexema()
{
    return this->lexema;
}

void Nodo::GraficarArbol(Nodo *raiz)
{
    if (raiz != nullptr){
        QString grafo = "digraph g{\n";
        this->graphArbol(raiz, grafo);
        grafo.append("}\n");
        ofstream archivo("grafo.dot");
        string stdgrafo = grafo.toStdString();
        archivo << stdgrafo;
        archivo.close();
        int i = system("dot -Tpng grafo.dot -o grafo.png");
    }

}

void Nodo::graphArbol(Nodo *actual, QString &graph)
{
    if(actual != nullptr){


        for (int i = 0; i < actual->hijos->count() ; i++) {
            if (i == 0){
                graph.append("\t"+QString::number(actual->getIdNodo())+"[label=\""+actual->getToken()+"\"];\n");
            }

            if (actual->hijos->at(i)->getLexema() == ""){
                graph.append("\t"+QString::number(actual->getIdNodo())+" -> "+QString::number(actual->hijos->at(i)->getIdNodo())+";\n");
                graph.append("\t"+QString::number(actual->hijos->at(i)->getIdNodo())+"[label=\""+actual->hijos->at(i)->getToken()+"\"];\n");


            }else{
                graph.append("\t"+QString::number(actual->getIdNodo())+" -> "+QString::number(actual->hijos->at(i)->getIdNodo())+";\n");
                graph.append("\t"+QString::number(actual->hijos->at(i)->getIdNodo())+"[label=\""+actual->hijos->at(i)->getLexema()+"\"];\n");

            }


            this->graphArbol(actual->hijos->at(i), graph);
        }



    }
}



int Nodo::getIdNodo()
{
    return this->idNodo;

}
