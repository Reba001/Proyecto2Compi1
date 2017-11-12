#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <parser.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "qfiledialog.h"
#include "qfile.h"
#include <QDebug>
#include <QIODevice>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->listadeError = new QList<QString>();
    this->listTextbox = new QList<QTextEdit *>();
    this->listTextbox->append(this->ui->textEdit);
    this->listTextbox->append(this->ui->textEdit_2);
    this->dirmodel = new QFileSystemModel(this);
    this->dirmodel->setRootPath("/home/reba/Escritorio");

    this->ui->treeView->setModel(dirmodel);
    QModelIndex index = dirmodel->index("/home/reba/Escritorio");
    this->ui->treeView->expand(index);
    this->ui->treeView->scrollTo(index);
    this->ui->treeView->setCurrentIndex(index);
    this->ui->treeView->resizeColumnToContents(0);

    this->filemode = new QFileSystemModel(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    try{
        listadeError->clear();

        QFile file("temp.txt"); //SE CREA UN ARCHIVO TEMPORAL PARA COMPILARLO
        if ( file.open( file.WriteOnly ) ) { //BUFFER PARA EL TEXTO QUE SE DESEA COMPILAR
            QTextStream stream1( &file );
            stream1 << this->listTextbox->at(0)->toPlainText() ;
        }
        listaError(listadeError);
        const char* x = "temp.txt";
        FILE* input = fopen(x, "r" );
        yyrestart(input);//SE PASA LA CADENA DE ENTRADA A FLEX
        yyparse();//SE INICIA LA COMPILACION
        if (raiz != nullptr && listadeError->count() == 0 ){
            QMessageBox msgBox;
            msgBox.setText("FIN DEL ANALISIS");
            msgBox.exec();
            raiz->GraficarArbol(raiz);
            Clase *clas1 = new Clase();
            recorrido(raiz, clas1);
            if (clas1->getCMain() != nullptr){
                this->metodo(clas1->getCMain()->getCuerpoM(), clas1->getCMain(), clas1);
            }else{
                QMessageBox msgBox;
                msgBox.setText("ERROR NO HAY MAIN AL CUAL EJECUTARSE");
                msgBox.exec();

            }
            QString imprime = clas1->imprimirVariables();
            QString imprime2 = clas1->imprimirMetodos();


        }else{
            QMessageBox msgBox;
            msgBox.setText("ERROR REVISE LA TABLA DE ERRORES");
            msgBox.exec();
        }



    }catch (exception * e){
        QMessageBox msgBox1;
        string eror = e->what();
        msgBox1.setText("ERROR " + QString::fromStdString(eror));
        msgBox1.exec();
    }
}

void MainWindow::on_actionCrear_nueva_pesta_a_triggered()
{
    this->crearPestania();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    this->ui->tabWidget->removeTab(index);
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QByteArray contenido;
    QString entrada = this->dirmodel->fileInfo(index).absoluteFilePath();
    qInfo() << entrada;

    QFile archivo(entrada);
    if (!archivo.exists()){
        qInfo() << "Archivo no existe";
        return;

    }
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!archivo.isOpen()){
        qInfo() << "Archivo no Abrio";
        return;
    }

    contenido = archivo.readAll();
    if(!this->listTextbox->empty()){//donde se guardan todos los textbox de los tab


        if(this->listTextbox->at(0)->toPlainText() == ""){// en un principio hay dos tab
            this->listTextbox->at(0)->setText(contenido);
        }else{
            if (this->listTextbox->count() == 2){//el segundo tab
                if(this->listTextbox->at(1)->toPlainText() == ""){// si esta vacio que lo llene de texto
                    this->listTextbox->at(1)->setText(contenido);
                    return;
                }
            }
            this->crearPestania();// crea nuevos tab
            this->listTextbox->at(this->ui->tabWidget->count()-1)->setText(contenido);// luego imprime el texto en el tab
        }

    }else{// si todas las pestañas han sido eliminadas
        this->crearPestania();
        this->listTextbox->at(0)->setText(contenido);
    }
}

void MainWindow::crearPestania()
{
    try{
        QTextEdit * cuadroTexto = new QTextEdit();// crea un nuevo cuadro de texto
        this->listTextbox->append(cuadroTexto);// lo agrega a la lista de cuadro de texto
        this->ui->tabWidget->addTab(cuadroTexto,QString("Tab %0").arg(this->ui->tabWidget->count()+1));// crea un tab con cuadro de texto y le un nombre

    }catch(exception ex){// si hay algun error
        QMessageBox msgbox;
        msgbox.setText("Error: "+ QString::fromStdString(ex.what()));
        msgbox.exec();
    }
}

void MainWindow::operacion(Nodo *asign, Variables *var, Clase * clas1)
{
    if (asign != nullptr){
        QString padre = asign->getToken();
        //ASIGN: COND
        if (padre == "ASIGN"){
            operacion(asign->hijos->at(0), var, clas1);
            return;
        }
        //COND
        else if(padre == "COND"){

            if (asign->hijos->count() == 3){// inicio if COND COUNT == 3
                Variables *var1 = new Variables();
                var1->setTipo(var->getTipo());
                var1->setAmbMetodo(var->getAmbMetodo());
                operacion(asign->hijos->at(0), var1, clas1);
                Variables *var2  = new Variables() ;
                var2->setTipo(var->getTipo());
                var2->setAmbMetodo(var->getAmbMetodo());
                operacion(asign->hijos->at(2), var2, clas1);
                //COND:   COND tOr COND
                if (var1->getTipo() == "bool" && var2->getTipo()  == "bool"){

                    if (asign->hijos->at(1)->getToken() == "tOr"){
                        bool resultado = var1->getValor4() || var2->getValor4();
                        var->setTipo("bool");
                        var->setValor4(resultado);
                        return;


                    }
                    //COND:   COND tAnd COND
                    else if (asign->hijos->at(1)->getToken() == "tAnd"){
                        bool resultado = var1->getValor4() && var2->getValor4();
                        var->setTipo("bool");
                        var->setValor4(resultado);
                        return;

                    }
                    //COND:   COND tXor COND
                    else if (asign->hijos->at(1)->getToken() == "tXor"){
                        bool resultado = var1->getValor4() xor var2->getValor4();
                        var->setTipo("bool");
                        var->setValor4(resultado);
                        return;

                    }
                    //COND:   COND tNand COND
                    else if (asign->hijos->at(1)->getToken() == "tNand"){
                        bool resultado = var1->getValor4() && var2->getValor4();
                        var->setTipo("bool");
                        var->setValor4(!resultado);
                        return;

                    }
                    //COND:   COND tNor COND
                    else if (asign->hijos->at(1)->getToken() == "tNor"){
                        bool resultado = var1->getValor4() || var2->getValor4();
                        var->setTipo("bool");
                        var->setValor4(!resultado);
                        return;
                    }


                }else if ((var1->getTipo() == "int" || var1->getTipo() == "double") && (var2->getTipo() == "double" || var2->getTipo() == "int")){
                    //COND:  COND tMayorIgual COND
                    if (asign->hijos->at(1)->getToken() == "tMayorIgual"){
                        bool resultado = var1->getValor3() >= var2->getValor3();
                        var->setTipo("bool");
                        var->setValor4(resultado);
                        return;
                    }
                    //COND:  COND tMenorIgual COND
                    else if (asign->hijos->at(1)->getToken() == "tMenorIgual"){
                        bool resultado = var1->getValor3() <= var2->getValor3();
                        var->setTipo("bool");
                        var->setValor4(resultado);
                        return;

                    }
                    //COND:  COND tMenor COND
                    else if (asign->hijos->at(1)->getToken() == "tMenor"){
                        bool resultado = var1->getValor3() < var2->getValor3();
                        var->setTipo("bool");
                        var->setValor4(resultado);
                        return;
                    }
                    //COND:  COND tMayor COND
                    else if (asign->hijos->at(1)->getToken() == "tMayor"){
                        bool resultado = var1->getValor3() > var2->getValor3();
                        var->setTipo("bool");
                        var->setValor4(resultado);
                        return;
                    }
                    //COND:  COND tIgualacion COND
                    else if (asign->hijos->at(1)->getToken() == "tIgualacion"){
                        bool resultado = var1->getValor3() == var2->getValor3();
                        var->setTipo("bool");
                        var->setValor4(resultado);
                        return;
                    }//COND:  COND tDiferenciacion COND
                    else if (asign->hijos->at(1)->getToken() == "tDiferenciacion"){
                        bool resultado = var1->getValor3() != var2->getValor3();
                        var->setTipo("bool");
                        var->setValor4(resultado);
                        return;
                    }
                }
                else if ((var1->getTipo() == "string" || var1->getTipo() == "char") && (var2->getTipo() == "string" || var2->getTipo() == "char")){
                    if (var1->getTipo() == "char" && var2->getTipo() == "char"){
                        if (asign->hijos->at(1)->getToken() == "tMayorIgual"){
                            bool resultado = var1->getValor5() >= var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tMenorIgual COND
                        else if (asign->hijos->at(1)->getToken() == "tMenorIgual"){
                            bool resultado = var1->getValor5() <= var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;

                        }
                        //COND:  COND tMenor COND
                        else if (asign->hijos->at(1)->getToken() == "tMenor"){
                            bool resultado = var1->getValor5() < var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tMayor COND
                        else if (asign->hijos->at(1)->getToken() == "tMayor"){
                            bool resultado = var1->getValor5() > var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tIgualacion COND
                        else if (asign->hijos->at(1)->getToken() == "tIgualacion"){
                            bool resultado = var1->getValor5() == var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }//COND:  COND tDiferenciacion COND
                        else if (asign->hijos->at(1)->getToken() == "tDiferenciacion"){
                            bool resultado = var1->getValor5() != var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                    }else{
                        QString var22;
                        int comparacion;
                        // por si uno es char y el otro es cadena
                        if (var1->getTipo() == "char"){
                            var22.append(var1->getValor5());
                            comparacion =QString::compare(var22, var2->getValor() , Qt::CaseSensitive);
                        }else if (var2->getTipo() == "char"){
                            var22.append(var2->getValor5());
                            comparacion  =QString::compare(var1->getValor(), var22 , Qt::CaseSensitive);
                        }else {
                            comparacion  =QString::compare(var1->getValor(), var2->getValor() , Qt::CaseSensitive);
                        }
                        //COND:  COND tMayorIgual COND
                        if (asign->hijos->at(1)->getToken() == "tMayorIgual"){

                            bool resultado = comparacion >= 0;
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tMenorIgual COND
                        else if (asign->hijos->at(1)->getToken() == "tMenorIgual"){
                            bool resultado = comparacion <= 0;
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;

                        }
                        //COND:  COND tMenor COND
                        else if (asign->hijos->at(1)->getToken() == "tMenor"){
                            bool resultado = comparacion < 0;
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tMayor COND
                        else if (asign->hijos->at(1)->getToken() == "tMayor"){
                            bool resultado = comparacion > 0;
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tIgualacion COND
                        else if (asign->hijos->at(1)->getToken() == "tIgualacion"){
                            bool resultado = comparacion == 0;
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }//COND:  COND tDiferenciacion COND
                        else if (asign->hijos->at(1)->getToken() == "tDiferenciacion"){
                            bool resultado = comparacion != 0;
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }

                    }
                }// end else if para char e int y double
                else if ((var1->getTipo() == "char" || var1->getTipo() == "int" || var1->getTipo() == "double") && (var2->getTipo() == "char" || var2->getTipo() == "int" || var2->getTipo() == "double")){
                    if (var1->getTipo() == "char" && (var2->getTipo() == "double" || var2->getTipo() == "int")){
                        //COND:  COND tMayorIgual COND
                        if (asign->hijos->at(1)->getToken() == "tMayorIgual"){
                            bool resultado = var1->getValor5() >= var2->getValor3();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tMenorIgual COND
                        else if (asign->hijos->at(1)->getToken() == "tMenorIgual"){
                            bool resultado = var1->getValor5() <= var2->getValor3();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;

                        }
                        //COND:  COND tMenor COND
                        else if (asign->hijos->at(1)->getToken() == "tMenor"){
                            bool resultado = var1->getValor5() < var2->getValor3();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tMayor COND
                        else if (asign->hijos->at(1)->getToken() == "tMayor"){
                            bool resultado = var1->getValor5() > var2->getValor3();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tIgualacion COND
                        else if (asign->hijos->at(1)->getToken() == "tIgualacion"){
                            bool resultado = var1->getValor5() == var2->getValor3();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }//COND:  COND tDiferenciacion COND
                        else if (asign->hijos->at(1)->getToken() == "tDiferenciacion"){
                            bool resultado = var1->getValor5() != var2->getValor3();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                    }else{
                        //COND:  COND tMayorIgual COND
                        if (asign->hijos->at(1)->getToken() == "tMayorIgual"){
                            bool resultado = var1->getValor3() >= var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tMenorIgual COND
                        else if (asign->hijos->at(1)->getToken() == "tMenorIgual"){
                            bool resultado = var1->getValor3() <= var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;

                        }
                        //COND:  COND tMenor COND
                        else if (asign->hijos->at(1)->getToken() == "tMenor"){
                            bool resultado = var1->getValor3() < var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tMayor COND
                        else if (asign->hijos->at(1)->getToken() == "tMayor"){
                            bool resultado = var1->getValor3() > var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                        //COND:  COND tIgualacion COND
                        else if (asign->hijos->at(1)->getToken() == "tIgualacion"){
                            bool resultado = var1->getValor3() == var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }//COND:  COND tDiferenciacion COND
                        else if (asign->hijos->at(1)->getToken() == "tDiferenciacion"){
                            bool resultado = var1->getValor3() != var2->getValor5();
                            var->setTipo("bool");
                            var->setValor4(resultado);
                            return;
                        }
                    }// end else if char e int y double

                }
                // else error semantico
                else {

                    var->setTipo("error");
                    return;
                }


            }// end if si count == 3
            else if (asign->hijos->count() == 2){
                //COND:  tNegacion COND
                Variables *var3 = new Variables();
                var3->setTipo(var->getTipo());
                var3->setAmbMetodo(var->getAmbMetodo());
                operacion(asign->hijos->at(1), var3, clas1);

                bool resultado = !var3->getValor4();
                var3->setTipo("bool");
                var3->setValor4(resultado);
                return;
            }//end if tipo bool
            //COND: EXPRESION
            else{
                operacion(asign->hijos->at(0), var, clas1);
                return;
            }// end if cond


        }// end if si padre == COND
        // EXPRESION
        else if (padre == "EXPRESION"){
            if (asign->hijos->count() == 3){


                //EXPRESION: EXPRESION tSuma EXPRESION
                if (asign->hijos->at(1)->getToken() == "tSuma"){
                    Variables *var1 =  new Variables();
                    var1->setTipo(var->getTipo());
                    var1->setAmbMetodo(var->getAmbMetodo());
                    this->operacion(asign->hijos->at(0), var1, clas1);

                    Variables *var2 = new Variables();
                    var2->setTipo(var->getTipo());
                    var2->setAmbMetodo(var->getAmbMetodo());
                    this->operacion(asign->hijos->at(2), var2, clas1);

                    if ((var1->getTipo() == "double" || var1->getTipo() == "int") && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        double resultado = var1->getValor3() + var2->getValor3();
                        if (var1->getTipo() == "int" && var2->getTipo() == "int")
                        {
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;

                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "string" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        QString resultado ;
                        resultado.append(var1->getValor());
                        resultado.append(QString::number(var2->getValor3()));
                        var->setTipo("string");
                        var->setValor(resultado);
                        return;


                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double" ) && var2->getTipo() == "string"){
                        QString resultado;
                        resultado.append(QString::number(var1->getValor3()));
                        resultado.append(var2->getValor());
                        var->setTipo("string");
                        var->setValor(resultado);
                        return;

                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double" ) && var2->getTipo() == "char"){
                        double resultado = var1->getValor3() + var2->getValor5();
                        if (var1->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "char" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        double resultado = var1->getValor5() + var2->getValor3();
                        if (var2->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "bool" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        if (var1->getValor4()){
                            double resultado = 1 + var2->getValor3();
                            if (var2->getTipo() == "int"){
                                var->setTipo("int");
                                var->setValor3(resultado);
                                return;
                            }

                            var->setTipo("double");
                            var->setValor3(resultado);
                            return;
                        }

                        if (var2->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(var2->getValor3());
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(var2->getValor3());
                        return;

                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double" ) && var2->getTipo() == "bool"){
                        if (var2->getValor4()){
                            double resultado =  var1->getValor3() + 1;
                            if (var1->getTipo() == "int"){
                                var->setTipo("int");
                                var->setValor3(resultado);
                                return;
                            }
                            var->setTipo("double");
                            var->setValor3(resultado);
                            return;
                        }

                        if (var1->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(var1->getValor3());
                            return ;
                        }
                        var->setTipo("double");
                        var->setValor3(var1->getValor3());
                        return;

                    }else if((var1->getTipo() == "char" || var1->getTipo() == "string") && (var2->getTipo() == "char" || var2->getTipo() == "string")){
                        QString result;
                        if (var1->getTipo() == "char" && var2->getTipo() == "char"){
                            result.append(var1->getValor5());
                            result.append(var2->getValor5());
                        }else if (var1->getTipo() == "char" && var2->getTipo() == "string"){
                            result.append(var1->getValor5());
                            result.append(var2->getValor());
                        }else if (var1->getTipo() == "string" && var2->getTipo() == "char"){
                            result.append(var1->getValor());
                            result.append(var2->getValor5());
                        }else{
                            result.append(var1->getValor());
                            result.append(var2->getValor());
                        }

                        var->setTipo("string");
                        var->setValor(result);
                        return;

                    }else if (var1->getTipo() == "bool" && var2->getTipo() == "bool"){
                        bool result = var1->getValor4() || var2->getValor4();
                        var->setTipo("bool");
                        var->setValor4(result);
                        return;

                    }else{
                        // error semantico aqui va..
                        QMessageBox msgBox;
                        msgBox.setText("ERROR Semantico: Variable Tipo: "+ var1->getTipo() +" y : "+ var2->getTipo()+" Operacion Suma imposible" );
                        msgBox.exec();
                        var->setTipo("error");
                        return;
                    }

                }
                //EXPRESION: EXPRESION tResta EXPRESION
                else if(asign->hijos->at(1)->getToken() == "tResta") {
                    Variables *var1 =  new Variables();
                    var1->setTipo(var->getTipo());
                    var1->setAmbMetodo(var->getAmbMetodo());
                    this->operacion(asign->hijos->at(0), var1, clas1);

                    Variables *var2 = new Variables();
                    var2->setTipo(var->getTipo());
                    var2->setAmbMetodo(var->getAmbMetodo());
                    this->operacion(asign->hijos->at(2), var2, clas1);

                    if ((var1->getTipo() == "double" || var1->getTipo() == "int") && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        double resultado = var1->getValor3() - var2->getValor3();
                        if (var1->getTipo() == "int" && var2->getTipo() == "int")
                        {
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;

                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double" ) && var2->getTipo() == "char"){
                        double resultado = var1->getValor3() - var2->getValor5();
                        if (var1->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "char" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        double resultado = var1->getValor5() - var2->getValor3();
                        if (var2->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "bool" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        if (var1->getValor4()){
                            double resultado = 1 - var2->getValor3();
                            if (var2->getTipo() == "int"){
                                var->setTipo("int");
                                var->setValor3(resultado);
                                return;
                            }
                            var->setTipo("double");
                            var->setValor3(resultado);
                            return;
                        }

                        if (var2->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(-var2->getValor3());
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(-var2->getValor3());
                        return;

                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double" ) && var2->getTipo() == "bool"){
                        if (var2->getValor4()){
                            double resultado =  var1->getValor3() - 1;
                            if (var1->getTipo() == "int"){
                                var->setTipo("int");
                                var->setValor3(resultado);
                                return;
                            }
                            var->setTipo("double");
                            var->setValor3(resultado);
                            return;
                        }

                        if (var1->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(var1->getValor3());
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(var1->getValor3());
                        return;

                    }else { // error semantico
                        QMessageBox msgBox;
                        msgBox.setText("ERROR Semantico: Variable Tipo: "+ var1->getTipo() +" y : "+ var2->getTipo()+" Operacion Resta imposible" );
                        msgBox.exec();
                        var->setTipo("error");
                        return;
                    }

                }
                //EXPRESION: EXPRESION tMultiplicacion EXPRESION
                else if(asign->hijos->at(1)->getToken() == "tMultiplicacion"){
                    Variables *var1 =  new Variables();
                    var1->setTipo(var->getTipo());
                    var1->setAmbMetodo(var->getAmbMetodo());
                    this->operacion(asign->hijos->at(0), var1, clas1);

                    Variables *var2 = new Variables();
                    var2->setTipo(var->getTipo());
                    var2->setAmbMetodo(var->getAmbMetodo());
                    this->operacion(asign->hijos->at(2), var2, clas1);

                    if ((var1->getTipo() == "double" || var1->getTipo() == "int") && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        double resultado = var1->getValor3() * var2->getValor3();
                        if (var1->getTipo() == "int" && var2->getTipo() == "int")
                        {
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;

                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double" ) && var2->getTipo() == "char"){
                        double resultado = var1->getValor3() * var2->getValor5();
                        if (var1->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "char" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        double resultado = var1->getValor5() * var2->getValor3();
                        if (var2->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "bool" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        if (var1->getValor4()){
                            double resultado = var2->getValor3();
                            if (var2->getTipo() == "int"){
                                var->setTipo("int");
                                var->setValor3(resultado);
                                return;
                            }
                            var->setTipo("double");
                            var->setValor3(resultado);
                            return;
                        }

                        if (var2->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(0);
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(0);
                        return;

                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double" ) && var2->getTipo() == "bool"){
                        if (var2->getValor4()){
                            double resultado =  var1->getValor3();
                            if (var1->getTipo() == "int"){
                                var->setTipo("int");
                                var->setValor3(resultado);
                                return;
                            }
                            var->setTipo("double");
                            var->setValor3(resultado);
                            return;
                        }

                        if (var1->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(0);
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(0);
                        return;

                    }else if (var1->getTipo() == "bool" && var2->getTipo() == "bool"){
                        bool result = var1->getValor4() && var2->getValor4();
                        var->setTipo("int");
                        var->setValor4(result);
                        return;

                    }else{// error semantico
                        /** aqui todos los errores papu **/
                        QMessageBox msgBox;
                        msgBox.setText("ERROR Semantico: Variable Tipo: "+ var1->getTipo() +" y : "+ var2->getTipo()+" Operacion Multiplicacion imposible" );
                        msgBox.exec();
                        var->setTipo("Error");
                        return;

                    }
                    

                }
                //EXPRESION: EXPRESION tDivision EXPRESION
                else if(asign->hijos->at(1)->getToken() == "tDivision") {
                    Variables *var1 =  new Variables();
                    var1->setTipo(var->getTipo());
                    var1->setAmbMetodo(var->getAmbMetodo());
                    this->operacion(asign->hijos->at(0), var1, clas1);

                    Variables *var2 = new Variables();
                    var2->setTipo(var->getTipo());
                    var2->setAmbMetodo(var->getAmbMetodo());
                    this->operacion(asign->hijos->at(2), var2, clas1);

                    if ((var1->getTipo() == "double" || var1->getTipo() == "int") && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        double resultado = var1->getValor3() / var2->getValor3();
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double" ) && var2->getTipo() == "char"){
                        double resultado = var1->getValor3() / var2->getValor5();
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "char" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        double resultado = var1->getValor5() / var2->getValor3();
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "bool" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        if (var1->getValor4()){
                            double resultado = 1 / var2->getValor3();
                            var->setTipo("double");
                            var->setValor3(resultado);
                            return;
                        }

                        var->setTipo("int");
                        var->setValor3(0);
                        return;

                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double") && var2->getTipo() == "bool"){
                        if (var2->getValor4()){
                            if (var1->getTipo() == "int"){
                                var->setTipo("int");
                            }
                            else {
                                var->setTipo("double");
                            }
                            var->setValor3(var1->getValor3());
                            return;
                        }
                        // aqui va un error despues de esta linea

                        var->setTipo("string");
                        var->setValor("error");
                        return;


                    }else{// error semantico
                        /** aqui todos los errores papu **/
                        QMessageBox msgBox;
                        msgBox.setText("ERROR Semantico: Variable Tipo: "+ var1->getTipo() +" y : "+ var2->getTipo()+" Operacion Division imposible" );
                        msgBox.exec();
                        var->setTipo("error");
                        return;
                    }

                }
                //EXPRESION: EXPRESION tPotenciacion EXPRESION
                else if(asign->hijos->at(1)->getToken() == "tPotenciacion") {
                    Variables *var1 =  new Variables();
                    var1->setTipo(var->getTipo());
                    var1->setAmbMetodo(var->getAmbMetodo());
                    this->operacion(asign->hijos->at(0), var1, clas1);

                    Variables *var2 = new Variables();
                    var2->setTipo(var->getTipo());
                    var2->setAmbMetodo(var->getAmbMetodo());
                    this->operacion(asign->hijos->at(2), var2, clas1);

                    if ((var1->getTipo() == "double" || var1->getTipo() == "int") && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        double resultado = pow(var1->getValor3(), var2->getValor3());
                        if (var1->getTipo() == "int" && var2->getTipo() == "int")
                        {
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;

                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double" ) && var2->getTipo() == "char"){
                        double resultado = pow(var1->getValor3(), var2->getValor5());
                        if (var1->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "char" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        double resultado = pow(var1->getValor5(), var2->getValor3());
                        if (var2->getTipo() == "int"){
                            var->setTipo("int");
                            var->setValor3(resultado);
                            return;
                        }
                        var->setTipo("double");
                        var->setValor3(resultado);
                        return;

                    }else if (var1->getTipo() == "bool" && (var2->getTipo() == "int" || var2->getTipo() == "double")){
                        if (var1->getValor4()){
                            var->setTipo("int");
                            var->setValor3(1);
                            return;
                        }

                        var->setTipo("double");
                        var->setValor3(0);
                        return;

                    }else if ((var1->getTipo() == "int" || var1->getTipo() == "double" ) && var2->getTipo() == "bool"){
                        if (var2->getValor4()){
                            double resultado =  var1->getValor3();
                            if (var1->getTipo() == "int"){
                                var->setTipo("int");
                                var->setValor3(resultado);
                                return;
                            }
                            var->setTipo("double");
                            var->setValor3(resultado);
                            return;
                        }


                        var->setTipo("int");
                        var->setValor3(1);
                        return;


                    }else{// error semantico
                        /** aqui todos los errores papu **/
                        QMessageBox msgBox;
                        msgBox.setText("ERROR Semantico: Variable Tipo: "+ var1->getTipo() +" y : "+ var2->getTipo()+" Operacion Potenciacion imposible" );
                        msgBox.exec();
                        var->setTipo("error");
                        return;
                    }


                }
                //EXPRESION: tParentesisA COND tParentesisC
                else{
                    operacion(asign->hijos->at(1), var, clas1);
                    return ;
                }

            }else if (asign->hijos->count() == 2){
                // esto se obtiene si la llama es hacia un metodo
                //iniciar recorrido de metodos para poder obtener el valor
                //|tId PARMET
                QString idMet = asign->hijos->at(0)->getLexema();
                Metodos * nMets = clas1->buscarMetodo(idMet);
                if (nMets != nullptr){
                    int i = nMets->getListaParametros()->count()-1;
                    // esto para que guarde los paraametros
                    this->lexps(asign->hijos->at(1), nMets, clas1->getCMain(), clas1, i);
                    // el procedimiento de la funcion para que se ejecute
                    this->metodo(nMets->getCuerpoM(), nMets, clas1);
                    if (nMets->getTipo() != "void" && nMets->getTipo() != "Main"){
                        var->setTipo(nMets->getTipo());
                        if(nMets->getTipo() == "string"){
                            var->setValor(nMets->getValor());
                        }else if (nMets->getTipo() == "int" || nMets->getTipo() == "double"){
                            var->setValor3(nMets->getValor3());
                        }else if (nMets->getTipo() == "bool"){
                            var->setValor4(nMets->getValor4());
                        }else {
                            var->setValor5(nMets->getValor5());
                        }
                    }
                    return;
                }

                /*** error de Semantica ***/
                QMessageBox msgBox;
                msgBox.setText("ERROR Semantico: Metodo no Encontrado" );
                msgBox.exec();
                var->setTipo("error");
                return;


            }else{
                //| tNumero
                if(asign->hijos->at(0)->getToken() == "tNumero"){

                    if (var->getTipo() == "bool"){
                        if (asign->hijos->at(0)->getLexema() == "1"){
                            var->setValor4(true);
                            var->setTipo("bool");
                            return;
                        }else if (asign->hijos->at(0)->getLexema() == "0"){

                            var->setValor4(false);
                            var->setTipo("bool");
                            return;
                        }
                    }

                    if (var->getTipo() == "char"){
                        int acar = asign->hijos->at(0)->getLexema().toInt();
                        if (acar >= 0 && acar <= 255){
                            char caracter = acar;
                            var->setValor5(caracter);
                            var->setTipo("char");
                            return;
                        }

                    }

                    if (asign->hijos->at(0)->getLexema().endsWith("++")){
                        QString nuevo  = asign->hijos->at(0)->getLexema() ;
                        nuevo.replace(nuevo.size()-2 , 2, "");
                        double num = nuevo.toDouble();
                        var->setValor3(num+1);
                        if (var->getTipo() == "int")var->setTipo("int");
                        else var->setTipo("double");
                        return;
                    }

                    if (asign->hijos->at(0)->getLexema().endsWith("--")){
                        QString nuevo  = asign->hijos->at(0)->getLexema();
                        nuevo.replace(nuevo.size()-2 , 2, "");
                        double num = nuevo.toDouble();
                        var->setValor3(num-1);
                        if (var->getTipo() == "int")var->setTipo("int");
                        else var->setTipo("double");
                        return;
                    }


                    double num = asign->hijos->at(0)->getLexema().toDouble();
                    var->setValor3(num);
                    if (var->getTipo() == "int")var->setTipo("int");
                    else var->setTipo("double");
                    return;
                }
                //| tDecimal
                else if (asign->hijos->at(0)->getToken() == "tDecimal"){
                    if (asign->hijos->at(0)->getLexema().endsWith("++")){
                        QString nuevo  = asign->hijos->at(0)->getLexema() ;
                        nuevo.replace(nuevo.size()-2 , 2, "");
                        double num = nuevo.toDouble();
                        var->setValor3(num+1);//cambiar se tiene que sumar decimales
                        var->setTipo("double");
                        return;
                    }

                    if (asign->hijos->at(0)->getLexema().endsWith("--")){
                        QString nuevo  = asign->hijos->at(0)->getLexema();
                        nuevo.replace(nuevo.size()-2 , 2, "");
                        double num = nuevo.toDouble();
                        var->setValor3(num-1);//cambiar se sitene que restar decimales
                        var->setTipo("double");
                        return;
                    }
                    double num = asign->hijos->at(0)->getLexema().toDouble();
                    var->setValor3(num);
                    var->setTipo("double");
                    return;
                }
                //| tCadena
                else if (asign->hijos->at(0)->getToken() == "tCadena"){
                    QString nuevo = asign->hijos->at(0)->getLexema();
                    nuevo.replace(0, 1, "");
                    nuevo.replace(nuevo.size()-1, 1, "");
                    var->setValor(nuevo);
                    var->setTipo("string");
                    return;
                }
                //| tCaracter
                else if (asign->hijos->at(0)->getToken() == "tCaracter"){


                    if (asign->hijos->at(0)->getLexema().endsWith("++")){
                        QString nuevo  = asign->hijos->at(0)->getLexema() ;
                        nuevo.replace(nuevo.size()-2 , 2, "");
                        std::string stdstring = nuevo.toStdString();
                        if (var->getTipo() == "int"){
                            char car = stdstring[1]+1;
                            var->setValor3(car);
                            var->setTipo("int");
                            return;
                        }

                        char car = stdstring[1]+1;
                        var->setValor5(car);
                        var->setTipo("char");
                        return;
                    }

                    if (asign->hijos->at(0)->getLexema().endsWith("--")){
                        QString nuevo  = asign->hijos->at(0)->getLexema();
                        nuevo.replace(nuevo.size()-2 , 2, "");
                        std::string stdnuevo = nuevo.toStdString();

                        if (var->getTipo() == "int"){
                            char car = stdnuevo[1]-1;
                            var->setValor3(car);
                            var->setTipo("int");
                            return;
                        }
                        char car = stdnuevo[1]-1;
                        var->setValor5(car);
                        var->setTipo("char");
                        return;
                    }
                    QString nuevo = asign->hijos->at(0)->getLexema();
                    string stdnuevo = nuevo.toStdString();
                    if (var->getTipo() == "int"){
                        char car = stdnuevo[1];
                        var->setValor3(car);
                        var->setTipo("int");
                        return;
                    }

                    char car = stdnuevo[1];
                    var->setValor5(car);
                    var->setTipo("char");
                    return;

                }
                //| tSalto
                else if (asign->hijos->at(0)->getToken() == "tSalto"){
                    if (asign->hijos->at(0)->getLexema().endsWith("++")){
                        if (var->getTipo() == "int"){
                            var->setValor3(11);
                            var->setTipo("int");
                            return;
                        }
                        char car = 11;
                        var->setValor5(car);
                        var->setTipo("char");
                        return;
                    }

                    if (asign->hijos->at(0)->getLexema().endsWith("--")){

                        if (var->getTipo() == "int"){
                            var->setValor3(9);
                            var->setTipo("int");
                            return;
                        }
                        char car = 9;
                        var->setValor5(car);
                        var->setTipo("char");
                        return;
                    }

                    if (var->getTipo() == "int"){
                        var->setValor3(10);
                        var->setTipo("int");
                        return;
                    }

                    char car = 10;
                    var->setValor5(car);
                    var->setTipo("char");
                    return;

                }
                //| tTab
                else if (asign->hijos->at(0)->getToken() == "tTab"){
                    if (asign->hijos->at(0)->getLexema().endsWith("++")){
                        if (var->getTipo() == "int"){
                            var->setValor3(10);
                            var->setTipo("int");
                            return;
                        }
                        char car = 10;
                        var->setValor5(car);
                        var->setTipo("char");
                        return;
                    }

                    if (asign->hijos->at(0)->getLexema().endsWith("--")){

                        if (var->getTipo() == "int"){
                            var->setValor3(8);
                            var->setTipo("int");
                            return;
                        }
                        char car = 8;
                        var->setValor5(car);
                        var->setTipo("char");
                        return;
                    }

                    if (var->getTipo() == "int"){
                        var->setValor3(9);
                        var->setTipo("int");
                        return;
                    }
                    char car = 9;
                    var->setValor5(car);
                    var->setTipo("char");
                    return;
                }
                //| tPot
                else if (asign->hijos->at(0)->getToken() == "tPot"){
                    if (asign->hijos->at(0)->getLexema().endsWith("++")){

                        if (var->getTipo() == "int"){
                            var->setValor3(95);
                            var->setTipo("int");
                            return;
                        }
                        char car = 95;
                        var->setValor5(car);
                        var->setTipo("char");
                        return;
                    }

                    if (asign->hijos->at(0)->getLexema().endsWith("--")){
                        if (var->getTipo() == "int"){
                            var->setValor3(93);
                            var->setTipo("int");
                            return;
                        }
                        char car = 93;
                        var->setValor5(car);
                        var->setTipo("char");
                        return;
                    }

                    if (var->getTipo() == "int"){
                        var->setValor3(94);
                        var->setTipo("int");
                        return;
                    }
                    char car = 94;
                    var->setValor5(car);
                    var->setTipo("char");
                    return;
                }
                //| tApostrofe
                else if (asign->hijos->at(0)->getToken() == "tApostrofe"){
                    if (asign->hijos->at(0)->getLexema().endsWith("++")){
                        if (var->getTipo() == "int"){
                            var->setValor3(40);
                            var->setTipo("int");
                            return;
                        }
                        char car = 40;
                        var->setValor5(car);
                        var->setTipo("char");
                        return;
                    }

                    if (asign->hijos->at(0)->getLexema().endsWith("--")){
                        if (var->getTipo() == "int"){
                            var->setValor3(38);
                            var->setTipo("int");
                            return;
                        }
                        char car = 38;
                        var->setValor5(car);
                        var->setTipo("char");
                        return;
                    }

                    if (var->getTipo() == "int"){
                        var->setValor3(39);
                        var->setTipo("int");
                        return;
                    }
                    char car = 39;
                    var->setValor5(car);
                    var->setTipo("char");
                    return;
                }
                //| tTrue
                else if (asign->hijos->at(0)->getToken() == "tTrue"){
                    var->setValor4(true);
                    var->setTipo("bool");
                    return;
                }
                //| tFalse
                else if (asign->hijos->at(0)->getToken() == "tFalse"){
                    var->setValor4(false);
                    var->setTipo("bool");
                    return;
                }
                //| tId
                else if (asign->hijos->at(0)->getToken() == "tId"){
                    //iniciar recorrido para buscar el id con el valor de variable
                    QString id = asign->hijos->at(0)->getLexema();
                    Variables *varId = clas1->buscarVar(id);


                    if (varId != nullptr){
                        var->setTipo(varId->getTipo());
                        if (varId->getTipo() == "string"){
                            var->setValor(varId->getValor());
                        }else if (varId->getTipo() == "double" || varId->getTipo() == "int"){
                            var->setValor3(varId->getValor3());
                        }else if (varId->getTipo() == "bool"){
                            var->setValor4(varId->getValor4());
                        }else{
                            var->setValor5(varId->getValor5());
                        }
                        return;
                    }

                    QString ambmet2 = var->getAmbMetodo();
                    Metodos *varMetodo = clas1->buscarMetodo(ambmet2);
                    qInfo() << "Ambito de variable: "<< var->getAmbMetodo();

                    if (varMetodo != nullptr){
                        qInfo() << "Ambito de variable2: "<< varMetodo->getNombre();
                        Variables *varlocal = varMetodo->buscarVar(id);
                        if (varlocal != nullptr){
                            qInfo() << "Ambito de variable local: "<< varlocal->getNombre();
                            qInfo() << "Ambito de variable local: "<< varlocal->getTipo();

                            var->setTipo(varlocal->getTipo());
                            if (varlocal->getTipo() == "string"){
                                var->setValor(varlocal->getValor());
                            }else if (varlocal->getTipo() == "double" || varlocal->getTipo() == "int"){
                                var->setValor3(varlocal->getValor3());
                            }else if (varlocal->getTipo() == "bool"){
                                var->setValor4(varlocal->getValor4());
                            }else{
                                var->setValor5(varlocal->getValor5());
                            }
                            return;

                        }
                        Variables *varPar = varMetodo->buscarParametro(id);
                        if (varPar != nullptr){
                            var->setTipo(varPar->getTipo());
                            if (varPar->getTipo() == "string"){
                                var->setValor(varPar->getValor());
                            }else if ((varPar->getTipo() == "double" || varPar->getTipo() == "int") ){
                                var->setValor3(varPar->getValor3());
                            }else if (varPar->getTipo() == "bool"){
                                var->setValor4(varPar->getValor4());
                            }else{
                                var->setValor5(varPar->getValor5());
                            }
                            return;

                        }
                    }

                    //error semantico
                    QMessageBox msgBox;
                    msgBox.setText("ERROR Semantico: Variable "+id +" No declarada" );
                    msgBox.exec();
                    var->setTipo("error");
                    return;
                }
            }
            // end if EXPRESION count == 1

        }//END IF EXPRESION

    }// end if asig != nullptr

    return;
}

void MainWindow::recorrido(Nodo *padre, Clase *clas1)
{
    if (padre != nullptr){
        QString noterminal= padre->getToken();
        //INICIO: S
        if (noterminal == "INICIO"){
            recorrido(padre->hijos->at(0), clas1);

            return;

        }// end if INICIO
        //S:	LIMPORTACION CLASE
        else if (noterminal == "S"){
            if (padre->hijos->count() == 2){
                recorrido(padre->hijos->at(0), clas1);
                recorrido(padre->hijos->at(1), clas1);

                return;
            }
        //| CLASE
            recorrido(padre->hijos->at(0), clas1);

            return;
        }//end else if S
        //LIMPORTACION: LIMPORTACION IMPORTACION
        else if (noterminal == "LIMPORTACION"){
            if (padre->hijos->count() == 2){
                recorrido(padre->hijos->at(0), clas1);
                recorrido(padre->hijos->at(1), clas1);

                return;
            }
       //| IMPORTACION
            recorrido(padre->hijos->at(0), clas1);

            return;
        }//end else if LIMPORTACION
        //IMPORTACION: tImport LIDS tDolar
        else if (noterminal == "IMPORTACION"){
            recorrido(padre->hijos->at(1), clas1);
            clas1->imports->append(padre->hijos->at(1)->hijos->at(0)->getLexema());

            return;

        }// END ELSE IF IMPORTACION
        //LIDS: LIDS tComa tId talvez hacer un metodo aparte
        else if (noterminal == "LIDS"){
            if (padre->hijos->count() == 2){

                return;
            }

            //| tId

            return;


        }//ELSE IF LIDS
        //VISIBILIDAD
        else if (noterminal == "VISIBILIDAD"){
            /**aqui puede ir codigo pero este espacio es por si tira error porque
               aqui van terminales
            **/

            return;

        }// END ELSE IF VISIBILIDAD
        //CLASE:  VISIBILIDAD tClase tId tInterrA CUERPOS tInterrC
        else if (noterminal == "CLASE"){
            QString vis = visibilidad(padre->hijos->at(0));
            if (vis == "" || vis == "publico"){
                clas1->setVisibilidad(true);
            }else {
                clas1->setVisibilidad(false);
            }

            QString nombre = padre->hijos->at(2)->getLexema();
            clas1->setNombre(nombre);

            recorrido(padre->hijos->at(3), clas1);

            return;
        }//END IF CLASE
        //CUERPOS: CUERPOS CUERPO
        else if (noterminal == "CUERPOS"){
            if (padre->hijos->count() == 2){
                recorrido(padre->hijos->at(0), clas1);
                recorrido(padre->hijos->at(1), clas1);

                return;
            }
        //| CUERPO
            recorrido(padre->hijos->at(0), clas1);

            return;
        }//END IF CUERPOS
        //CUERPO: VARIABLES | METODOS
        else if (noterminal == "CUERPO"){
            recorrido(padre->hijos->at(0), clas1);

            return;
        }//END IF CUERPO
        //TIPO: tString | tInt | tDouble | tBool | tChar | tId
        else if (noterminal == "TIPO"){
            /** AQUI VA CODIGO
             * SOLO DECLARACIONES DE TERMINALES
            **/
            return;
        }// END IF TIPO
        // VARIABLES: VISIBILIDAD tVar TIPO DIMENSIONES tDolar
        else if (noterminal == "VARIABLES"){
            if (padre->hijos->count() == 4){
                QString vis = this->visibilidad(padre->hijos->at(0));
                if (vis == "" || vis == "publico"){
                    clas1->getVarC()->setVisibilidad(true);
                }else {
                    clas1->getVarC()->setVisibilidad(false);
                }
                QString tipo = this->visibilidad(padre->hijos->at(2));
                clas1->getVarC()->setTipo(tipo);
                recorrido(padre->hijos->at(3), clas1);

                return;

            }
            return;

        }// END ELSE IF VARIABLES
        //DIMENSIONES: tArreglo LIDS ARREGLOS
        else if (noterminal == "DIMENSIONES"){
            // if de arreglos
            if (padre->hijos->count() == 3){

                return;
            }
            //| LNOMBRES

            recorrido(padre->hijos->at(0), clas1);

            return;

        }//END IF DIMENSIONES
        /** este espacio es donde va la declaracion
         * semantica de los arreglos
         *
         * */
        //LNOMBRES: LNOMBRES tComa NOMBRES
        else if (noterminal == "LNOMBRES"){
            if (padre->hijos->count()== 2){
                recorrido(padre->hijos->at(0), clas1);
                recorrido(padre->hijos->at(1), clas1);

                return;
            }
        //| NOMBRES
            recorrido(padre->hijos->at(0), clas1);

            return;
        }//END ELSE IF LNOMBRES
        //NOMBRES: tId tIgual ASIGN
        else if (noterminal == "NOMBRES"){
            if (padre->hijos->count() == 2){
                QString tipo = clas1->getVarC()->getTipo();
                QString nombre = padre->hijos->at(0)->getLexema();

                int fila = padre->hijos->at(0)->getFila();
                int col = padre->hijos->at(0)->getColumna();
                bool visibility = clas1->getVarC()->getVisibilidad();
                Variables *var = new Variables(tipo, nombre, 0.0, col, fila);
                var->setVisibilidad(visibility);
                operacion(padre->hijos->at(1), var, clas1);

                if (var->getTipo() == tipo){
                    clas1->setListVar(var);
                }else {
                    QMessageBox msgBox;
                    msgBox.setText("ERROR Semantico: Variable Tipo: "+ tipo +" Resultado de tipo: "+ var->getTipo());
                    msgBox.exec();
                }
                var = nullptr;
                delete var;
                return;

            }
        //| tId
            QString tipo = clas1->getVarC()->getTipo();
            QString nombre = padre->hijos->at(0)->getLexema();
            int fila = padre->hijos->at(0)->getFila();
            int col = padre->hijos->at(0)->getColumna();
            int variablevacia = -1;
            bool visibility = clas1->getVarC()->getVisibilidad();
            Variables *var = new Variables(tipo, nombre, variablevacia, col, fila);
            clas1->getVarC()->setVisibilidad(visibility);
            clas1->setListVar(var);
            var = nullptr;
            delete var;
            return;
        }//END ELSE IF NOMBRES
        // METODOS: VISIBILIDAD MET
        else if (noterminal == "METODOS"){
            /** aqui va procedimientos
                recordar ponerlos
            **/
            QString accesibilidad = this->visibilidad(padre->hijos->at(0));
            if (accesibilidad == "" || accesibilidad == "publico"){
                clas1->getMetC()->setAccesibilidad(true);
            }else {
                clas1->getMetC()->setAccesibilidad(false);
            }
            this->recorrido(padre->hijos->at(1), clas1);
            qInfo() << "METODOS";
            return;
        }//end if METODOS
        //MET:    TIPO PFS tId tParentesisA PARAMETROS tParentesisC tInterrA CUERPOFUNS tInterrC
        else if (noterminal == "MET"){
            //TIPO PFS tId tParentesisA PARAMETROS tParentesisC tInterrA CUERPOFUNS tInterrC
            if (padre->hijos->count() == 5){
                QString tipo = this->visibilidad(padre->hijos->at(0));
                QString nombre = padre->hijos->at(2)->getLexema();
                int valorvacio = -1;
                int columna = padre->hijos->at(2)->getColumna();
                int fila = padre->hijos->at(2)->getFila();

                Metodos *nuevoMet = new Metodos(tipo , nombre, valorvacio, columna, fila);
                nuevoMet->setAccesibilidad(clas1->getMetC()->getAccesibilidad());
                nuevoMet->setCuerpoM(padre->hijos->at(4));
                clas1->setListMet(nuevoMet);
                // este ya es para los parametros lo dejamos asi ya que no se ejecuta el cuerpo
                this->metodo(padre->hijos->at(3), nuevoMet, clas1);
                /**** se comenta porque vamos a hacer que se ejecute en el main ***/
                //this->metodo(padre->hijos->at(4), nuevoMet, clas1);


                qInfo() << "MET";
                return;

            }
            //| tVoid tId tParentesisA PARAMETROS tParentesisC tInterrA CUERPOVOIDS tInterrC
            else if (padre->hijos->count() == 4){
                QString nombre = padre->hijos->at(1)->getLexema();
                int valorvacio = -1;
                int columna = padre->hijos->at(2)->getColumna();
                int fila = padre->hijos->at(2)->getFila();

                Metodos *nuevoMet = new Metodos("void" , nombre, valorvacio, columna, fila);
                nuevoMet->setAccesibilidad(clas1->getMetC()->getAccesibilidad());
                nuevoMet->setCuerpoM(padre->hijos->at(3));
                clas1->setListMet(nuevoMet);
                /** metodo para extraer los parametros **/
                metodo(padre->hijos->at(2), nuevoMet, clas1);

                //metodo(padre->hijos->at(3), nuevoMet, clas1);

                qInfo() << "MET";
                return;
            }
            //| tMain tParentesisA  tParentesisC tInterrA CUERPOMAIN tInterrC
            // entro al main se ejecuta el codigo

            int col = padre->hijos->at(0)->getColumna();
            int fila = padre->hijos->at(0)->getFila();
            int valorCero = -1;
            Metodos * mMain = new Metodos("Main" , "Main", valorCero, col, fila);
            mMain->setCuerpoM(padre->hijos->at(1));
            clas1->setCMain(mMain);
            clas1->setListMet(mMain);
            //this->metodo(padre->hijos->at(1), mMain, clas1);

            qInfo() << "MET";

            return;
        }//ELSE IF MET
        /***
         * DEJO ESTO PARA EL CUEPO DE LAS FUNCIONES Y METODOS Y MAIN
         * **/
        // PARAMETROS
    }
    return;
}

void MainWindow::metodo(Nodo *asign, Metodos *met, Clase *clas1)
{
    if (asign != nullptr){
        QString padre = asign->getToken();
        //CUERPOFUNS: CUERPOFUNS CUERPOF
        if (padre == "CUERPOFUNS"){
            if (asign->hijos->count() == 2){
                this->metodo(asign->hijos->at(0), met, clas1);
                this->metodo(asign->hijos->at(1), met, clas1);
                qInfo() << "CUERPOFUNS";
                return;
            }
            //| CUERPOF
            this->metodo(asign->hijos->at(0), met, clas1);
            qInfo() << "CUERPOFUNS";
            return;
        }// END IF CUERPOFUNS
        /*** CUERPOF: VARIABLES
         *  | RETORNAR
         *  | SIF
         *  | MIENTRAF
         *  | PARAF
         *  | NOMBRES tDolar tDola no se añadio
        ****/
        else if (padre == "CUERPOF"){
            if(asign->hijos->count() == 1){
                if (asign->hijos->at(0)->getToken() == "NOMBRES"){
                    this->varMets(asign->hijos->at(0), met, clas1);
                    return;
                }
                this->metodo(asign->hijos->at(0), met, clas1);
                qInfo() << "CUERPOF";
                return;
            }
            /***
             *  | tId PARMET tDolar
             *  | tGraficar tParentesisA tId tParentesisC tDolar
             *  | tPintarC tParentesisA EXPRESION tParentesisC tDolar
            ***/
            else if (asign->hijos->count() == 2){
                if (asign->hijos->at(0)->getToken() == "tId"){
                    QString nombreMet = asign->hijos->at(0)->getLexema();
                    Metodos * busqMet = clas1->buscarMetodo(nombreMet);
                    if (busqMet != nullptr){
                        /** aqui va para poder hacer el procedimiento de las funciones o metodos**/
                        int i = busqMet->getListaParametros()->count()-1;
                        this->lexps(asign->hijos->at(1), busqMet, met, clas1, i);

                        // el procedimiento de la funcion para que se ejecute
                        this->metodo(busqMet->getCuerpoM(), busqMet, clas1);
                        return;
                    }
                    qInfo() << "Metodo no encontrado";
                    return;
                }else if (asign->hijos->at(0)->getToken() == "tGraficar"){
                    return;
                }
                // tPintarC
                return;

            }
            //| tId PARMET tIgual ASIGN tDolar
            return;

        }//END IF CUERPOF
        // PARAMETROS
        else if (padre == "PARAMETROS"){
            if (asign->hijos->at(0)->getToken() == "tVacio"){

                qInfo() << "PARAMETROS";
                return;
            }
            // | PARAMETRO
            this->metodo(asign->hijos->at(0), met, clas1);
            qInfo() << "PARAMETROS";
            return;

        }// END IF PARAMETROS
        //PARAMETRO:  PARAMETRO tComa TIPO tId
        else if (padre == "PARAMETRO"){
            if (asign->hijos->count() == 3){
                this->metodo(asign->hijos->at(0), met, clas1);
                QString tipo = this->visibilidad(asign->hijos->at(1));
                QString nombrePar = asign->hijos->at(2)->getLexema();
                int valorVacio = -1;
                int columna = asign->hijos->at(2)->getColumna();
                int fila = asign->hijos->at(2)->getFila();
                Variables *varPar = new Variables(tipo, nombrePar, valorVacio, columna, fila);
                met->setParametros(varPar);
                qInfo() << "PARAMETRO";
                return;
            }
            //| TIPO tId
            QString tipo = this->visibilidad(asign->hijos->at(0));
            QString nombre = asign->hijos->at(1)->getLexema();
            int varVacia = -1;
            int columna = asign->hijos->at(1)->getColumna();
            int fila = asign->hijos->at(1)->getFila();
            Variables * varPar = new Variables(tipo, nombre, varVacia, columna, fila);
            met->setParametros(varPar);
            qInfo() << "PARAMETRO";
            return;

        }
        // VARIABLES: VISIBILIDAD tVar TIPO DIMENSIONES tDolar
        if (padre == "VARIABLES"){
            if (asign->hijos->count() == 4){
                QString vis = this->visibilidad(asign->hijos->at(0));
                if (vis == "" || vis == "publico"){
                    clas1->getVarC()->setVisibilidad(true);
                }else {
                    clas1->getVarC()->setVisibilidad(false);
                }
                QString tipo = this->visibilidad(asign->hijos->at(2));
                clas1->getVarC()->setTipo(tipo);
                metodo(asign->hijos->at(3), met, clas1);
                qInfo() << "VARIABLES";
                return;

            }

            return;

        }// END ELSE IF VARIABLES
        //DIMENSIONES: tArreglo LIDS ARREGLOS
        else if (padre == "DIMENSIONES"){
            // if de arreglos
            if (asign->hijos->count() == 3){

                return;
            }
            //| LNOMBRES

            metodo(asign->hijos->at(0), met, clas1);
            qInfo() << "DIMENSIONES";
            return;

        }//END IF DIMENSIONES
        /** este espacio es donde va la declaracion
         * semantica de los arreglos
         *
         * */
        //LNOMBRES: LNOMBRES tComa NOMBRES
        else if (padre == "LNOMBRES"){
            if (asign->hijos->count()== 2){
                metodo(asign->hijos->at(0), met, clas1);
                metodo(asign->hijos->at(1), met, clas1);
                qInfo() << "LNOMBRES";

                return;
            }
        //| NOMBRES
            metodo(asign->hijos->at(0), met, clas1);
            return;
        }//END ELSE IF LNOMBRES
        //NOMBRES: tId tIgual ASIGN
        else if (padre == "NOMBRES"){
            if (asign->hijos->count() == 2){
                QString tipo = clas1->getVarC()->getTipo();
                QString nombre = asign->hijos->at(0)->getLexema();
                Variables *varBusq = clas1->buscarVar(nombre);
                int fila = asign->hijos->at(0)->getFila();
                int col = asign->hijos->at(0)->getColumna();
                bool visibility = clas1->getVarC()->getVisibilidad();
                Variables *var = new Variables(tipo, nombre, 0.0, col, fila);
                var->setVisibilidad(visibility);
                var->setAmbMetodo(met->getNombre());
                operacion(asign->hijos->at(1), var, clas1);

                if (var->getTipo() == tipo){

                    if (varBusq ==nullptr){
                        met->setVariables(var);
                    }
                    else {
                        QMessageBox msgBox;
                        msgBox.setText("ERROR Semantico: Variable Tipo: "+ tipo  +" Nombre: "+ nombre + " ya declarada como variable global de tipo: "+varBusq->getTipo());
                        msgBox.exec();
                    }

                }else {
                    QMessageBox msgBox;
                    msgBox.setText("ERROR Semantico: Variable Tipo: "+ tipo +" Resultado de tipo: "+ var->getTipo());
                    msgBox.exec();
                }

                qInfo() << "NOMBRES";
                return;

            }
        //| tId
            QString tipo = clas1->getVarC()->getTipo();
            QString nombre = asign->hijos->at(0)->getLexema();
            int fila = asign->hijos->at(0)->getFila();
            int col = asign->hijos->at(0)->getColumna();
            int variablevacia = -1;
            bool visibility = clas1->getVarC()->getVisibilidad();
            Variables *var = new Variables(tipo, nombre, variablevacia, col, fila);
            var->setVisibilidad(visibility);
            var->setAmbMetodo(met->getNombre());
            met->setVariables(var);
            qInfo() << "NOMBRES";
            return;
        }//END ELSE IF NOMBRES
        // RETORNAR : tRetorna COND tDolar
        else if (padre == "RETORNAR"){
            if (asign->hijos->count() == 2){
                int columna = asign->hijos->at(0)->getColumna();
                int fila = asign->hijos->at(0)->getColumna();
                int valorVacio = -1;
                Variables *varRet = new Variables("", "retornar",valorVacio , columna, fila);
                varRet->setAmbMetodo(met->getNombre());
                operacion(asign->hijos->at(1), varRet, clas1);
                if (met->getTipo() == varRet->getTipo()){
                    met->setRetorno(varRet);
                    if(varRet->getTipo() == "string"){
                        met->setValor(varRet->getValor());
                    }else if (varRet->getTipo() == "int" || varRet->getTipo() == "double"){
                        met->setValor3(varRet->getValor3());
                    }else if (varRet->getTipo() == "bool"){
                        met->setValor4(varRet->getValor4());
                    }else {
                        met->setValor5(varRet->getValor5());
                    }
                }
                return;
            }

            qInfo() << "Error de Semantica: Declaracion salir fuera de Contexto";
            return;
        }// ELSE IF RETORNAR
        // CUERPOVOIDS: CUERPOVOIDS CUERPOV
        else if (padre == "CUERPOVOIDS"){
            if (asign->hijos->count() == 2){
                this->metodo(asign->hijos->at(0), met, clas1);
                this->metodo(asign->hijos->at(1), met, clas1);
                return;
            }
            // | CUERPOV
            this->metodo(asign->hijos->at(0), met, clas1);
            return;
        }// END IF CUERPOVOIDS
        /***
         * CUERPOV: VARIABLES
         *         | tRetorna
         *         | tSalir
         *         | SIV
         *         | MIENTRASV
         *         | PARAV
         *         | NOMBRES
        ****/
        else if (padre == "CUERPOV"){
            if (asign->hijos->count() == 1){
                if(asign->hijos->at(0)->getToken() == "NOMBRES"){
                    this->varMets(asign->hijos->at(0), met, clas1);
                    return;
                }else if (asign->hijos->at(0)->getToken() == "tRetorna"){
                    /*** de alguna manera hacer que finalice :V **/
                    return;
                }else if (asign->hijos->at(0)->getToken() == "tSalir"){
                    /** error fuera de contexto***/
                    return;
                }else if (asign->hijos->at(0)->getToken() == "VARIABLES"){

                    this->metodo(asign->hijos->at(0), met , clas1);
                    return;
                }
                /**** bucles ***/

                return;

            }/***
             *  | tId PARMET tDolar
             *  | tGraficar tParentesisA tId tParentesisC tDolar
             *  | tPintarC tParentesisA EXPRESION tParentesisC tDolar
            ***/
            else if (asign->hijos->count() == 2){
                if (asign->hijos->at(0)->getToken() == "tId"){
                    QString nombreMet = asign->hijos->at(0)->getLexema();
                    Metodos * busqMet = clas1->buscarMetodo(nombreMet);
                    if (busqMet != nullptr){
                        /** aqui va para poder hacer el procedimiento de las funciones o metodos**/
                        int i = busqMet->getListaParametros()->count()-1;
                        this->lexps(asign->hijos->at(1), busqMet, met, clas1, i);

                        // el procedimiento de la funcion para que se ejecute
                        this->metodo(busqMet->getCuerpoM(), busqMet, clas1);
                        return;
                    }
                    qInfo() << "Metodo no encontrado";
                    return;
                }else if (asign->hijos->at(0)->getToken() == "tGraficar"){
                    return;
                }
                // tPintarC
                return;

            }
            /*** aqui los de tres tId PARMET tIgual ASIGN :v****/
            return;

        }// end if cuerpov
        /****
         * CUERPOMAINS: CUERPOMAINS CUERPOM
         * | CUERPOM
         * no se te olvide CUERPOMAIN
         * ****/
        else if (padre == "CUERPOMAIN"){
             if (asign->hijos->count() == 2){
                 this->metodo(asign->hijos->at(0), met, clas1);
                 this->metodo(asign->hijos->at(1), met, clas1);
                 return;
             }
            // CUERPOM
             this->metodo(asign->hijos->at(0), met, clas1);
             return;
        }// END IF CUERPOM
        // CUERPOM:VARIABLES
        //         | SI
        //         | MIENTRAS
        //         | PARA
        //         | tSalir
        //         | NOMBRES
        else if (padre == "CUERPOM"){
            if (asign->hijos->count() == 1){

                if(asign->hijos->at(0)->getToken() == "NOMBRES"){
                    this->varMets(asign->hijos->at(0), met, clas1);
                    return;
                }else if (asign->hijos->at(0)->getToken() == "tSalir"){
                    /** error fuera de contexto***/
                    return;
                }

                this->metodo(asign->hijos->at(0), met, clas1);
                return;
                /***  ESTE ESPACIO ES PARA LOS BUCLES ***/

            }
            /***
             *  | tId PARMET tDolar
             *  | tGraficar tParentesisA tId tParentesisC tDolar
             *  | tPintarC tParentesisA EXPRESION tParentesisC tDolar
            ***/
            else if (asign->hijos->count() == 2){
                if (asign->hijos->at(0)->getToken() == "tId"){
                    QString nombreMet = asign->hijos->at(0)->getLexema();
                    Metodos * busqMet = clas1->buscarMetodo(nombreMet);
                    if (busqMet != nullptr){
                        /** aqui va para poder hacer el procedimiento de las funciones o metodos**/
                        int i = busqMet->getListaParametros()->count()-1;
                        this->lexps(asign->hijos->at(1), busqMet, met, clas1, i);

                        // el procedimiento de la funcion para que se ejecute
                        this->metodo(busqMet->getCuerpoM(), busqMet, clas1);
                        return;
                    }
                    qInfo() << "Metodo no encontrado";
                    return;
                }else if (asign->hijos->at(0)->getToken() == "tGraficar"){
                    return;
                }
                // tPintarC
                return;

            }
            //| tId PARMET tIgual ASIGN tDolar
            return;

        }


    }
}

void MainWindow::varMets(Nodo *variable, Metodos *met, Clase *clas1)
{
    if (variable != nullptr){
        QString padre = variable->getToken();
        //NOMBRES: tId tIgual ASIGN
        if (padre == "NOMBRES"){
            if (variable->hijos->count() == 2){
                QString nombre = variable->hijos->at(0)->getLexema();
                qInfo() << "Nombre variable declarada despues: " << nombre;
                Variables *varBusq = met->buscarVar(nombre);
                if (varBusq != nullptr){
                    operacion(variable->hijos->at(1), varBusq, clas1);
                }else{
                    varBusq = met->buscarParametro(nombre);
                    if (varBusq != nullptr){
                        operacion(variable->hijos->at(1), varBusq, clas1);
                        return;
                    }else {
                        varBusq = clas1->buscarVar(nombre);
                        if (varBusq != nullptr){
                            operacion(variable->hijos->at(1), varBusq, clas1);
                            return;
                        }

                    }
                }

                QMessageBox msgBox;
                msgBox.setText("ERROR Semantico: Variable Nombre: "+ nombre + " no declarada");
                msgBox.exec();
                qInfo() << "NOMBRES";
                return;

            }
        //| tId
            QString nombre = variable->hijos->at(0)->getLexema();
            if (nombre.endsWith("++")){
                nombre.replace(nombre.size() -2 , 2, "");
                Variables *varBusq = met->buscarVar(nombre);
                if (varBusq != nullptr){
                    if (varBusq->getValor2() != -1){
                        if (varBusq->getTipo() == "int" || varBusq->getTipo() == "double"){
                            double valor = varBusq->getValor3();
                            varBusq->setValor3(valor+1);
                        }else {
                            int valor = varBusq->getValor5();
                            varBusq->setValor5(valor+1);
                        }
                        return;
                    }
                }else{
                    varBusq = met->buscarParametro(nombre);
                    if (varBusq != nullptr){
                        if (varBusq->getValor() != -1){
                            if (varBusq->getTipo() == "int" || varBusq->getTipo() == "double"){
                                double valor = varBusq->getValor3();
                                varBusq->setValor3(valor+1);
                            }else {
                                int valor = varBusq->getValor5();
                                varBusq->setValor5(valor+1);
                            }
                            return;
                        }
                    }else{
                        varBusq = clas1->buscarVar(nombre);
                        if (varBusq != nullptr){
                            if (varBusq->getValor2() != -1){
                                if (varBusq->getTipo() == "int" || varBusq->getTipo() == "double"){
                                    double valor = varBusq->getValor3();
                                    varBusq->setValor3(valor+1);
                                }else {
                                    int valor = varBusq->getValor5();
                                    varBusq->setValor5(valor+1);
                                }
                                return;
                            }
                        }
                    }
                }
            }else if (nombre.endsWith("--")){
                nombre.replace(nombre.size() -2 , 2, "");
                Variables *varBusq = met->buscarVar(nombre);
                if (varBusq != nullptr){
                    if (varBusq->getValor2() != -1){
                        if (varBusq->getTipo() == "int" || varBusq->getTipo() == "double"){
                            double valor = varBusq->getValor3();
                            varBusq->setValor3(valor-1);
                        }else {
                            int valor = varBusq->getValor5();
                            varBusq->setValor5(valor-1);
                        }
                        return;
                    }
                }else{

                    varBusq = met->buscarParametro(nombre);
                    if (varBusq != nullptr){
                        if (varBusq->getValor2() != -1){
                            if (varBusq->getTipo() == "int" || varBusq->getTipo() == "double"){
                                double valor = varBusq->getValor3();
                                varBusq->setValor3(valor-1);
                            }else {
                                int valor = varBusq->getValor5();
                                varBusq->setValor5(valor+1);
                            }
                            return;
                        }
                    }else{
                        varBusq = clas1->buscarVar(nombre);
                        if (varBusq != nullptr){
                            if (varBusq->getValor2() != -1){
                                if (varBusq->getTipo() == "int" || varBusq->getTipo() == "double"){
                                    double valor = varBusq->getValor3();
                                    varBusq->setValor3(valor-1);
                                }else {
                                    int valor = varBusq->getValor5();
                                    varBusq->setValor5(valor-1);
                                }
                                return;
                            }
                        }
                    }
                }
            }
            QMessageBox msgBox;
            msgBox.setText("ERROR Semantico: Variable Nombre: "+ nombre);
            msgBox.exec();
            qInfo() << "NOMBRES";
            return;
        }//END ELSE IF NOMBRES
        // RETORNAR : tRetorna COND tDolar
        else if (padre == "RETORNAR"){
            if (variable->hijos->count() == 2){
                int columna = variable->hijos->at(0)->getColumna();
                int fila = variable->hijos->at(0)->getColumna();
                int valorVacio = -1;
                Variables *varRet = new Variables("", "retornar",valorVacio , columna, fila);
                varRet->setAmbMetodo(met->getNombre());
                operacion(variable->hijos->at(1), varRet, clas1);
                met->setRetorno(varRet);
                return;
            }

            qInfo() << "Error de Semantica: Declaracion salir fuera de Contexto";
            return;
        }

    }
}

QString MainWindow::visibilidad(Nodo *padre)
{
    if (padre != nullptr){
        // VISIBILIDAD
        if (padre->getToken() == "VISIBILIDAD"){
            return padre->hijos->at(0)->getLexema();
        // TIPO
        }else if (padre->getToken() == "TIPO"){
            return padre->hijos->at(0)->getLexema();

        }
    }
    return "";
}

void MainWindow::lexps(Nodo *lex, Metodos *met, Metodos *metEncontrado, Clase *clas1, int i)
{
    if (lex != nullptr){
        QString padre = lex->getToken();
        /********
         * PARMET: tParentesisA LEXPS tParentesisC
         *  | tParentesisA ARRSM tParentesisC
         *  | tParentesisA tParentesisC
         *  | ARRSM
         * **/
        if (padre == "PARMET"){
            if (lex->hijos->count() == 1){
                // por el momento parametros solo de tipo expresion
                this->lexps(lex->hijos->at(0), met, metEncontrado, clas1, i);
                return;
            }
            // tParentesisA tParentesisC
            // aqui va la ejecucion del metodo
            return;
        }
        /******
         * ARRSM QUE ES PARA LOS ARREGLOS
         * **/
        /***
         *   LEXPS: LEXPS tComa ASIGN
         *          | ASIGN
         * */
        else if (padre == "LEXPS"){
            if (lex->hijos->count() == 2){
                this->lexps(lex->hijos->at(0), met, metEncontrado, clas1, i-1);
                Variables *varPar = met->getPopParametro();
                varPar->setAmbMetodo(metEncontrado->getNombre());
                QString tipo = varPar->getTipo();
                this->operacion(lex->hijos->at(1), varPar, clas1);
                varPar->setAmbMetodo(met->getNombre());
                if (tipo != varPar->getTipo()){
                    qInfo() << "Error de Semantica: Variables de PArametros no tienen mismo Tipo";
                }else {
                    met->setParametros(varPar);
                }
                return;
            }
            //| ASIGN
            Variables *varPar = met->getPopParametro();
            varPar->setAmbMetodo(metEncontrado->getNombre());
            QString tipo = varPar->getTipo();
            this->operacion(lex->hijos->at(0), varPar, clas1);
            varPar->setAmbMetodo(met->getNombre());
            if (tipo != varPar->getTipo()){
                qInfo() << "Error de Semantica: Variables de PArametros no tienen mismo Tipo";
            }else {
                met->setParametros(varPar);
            }
            return;
        }

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    try{
        listadeError->clear();
        for (int i = 0; i < listTextbox->count() ; i++) {
            QFile file("temp.txt"); //SE CREA UN ARCHIVO TEMPORAL PARA COMPILARLO
            if ( file.open( file.WriteOnly ) ) { //BUFFER PARA EL TEXTO QUE SE DESEA COMPILAR
                QTextStream stream1( &file );
                stream1 << listTextbox->at(i)->toPlainText();
            }
            listaError(listadeError);
            const char* x = "temp.txt";
            FILE* input = fopen(x, "r" );
            yyrestart(input);//SE PASA LA CADENA DE ENTRADA A FLEX
            yyparse();//SE INICIA LA COMPILACION
            if (raiz != nullptr && listadeError->count() == 0 ){

            }else{
                QMessageBox msgBox;
                msgBox.setText("ERROR REVISE LA TABLA DE ERRORES");
                msgBox.exec();
                return;
            }


        }
        QMessageBox msgBox;
        msgBox.setText("FIN DEL ANALISIS");
        msgBox.exec();

    }catch (exception * e){
        QMessageBox msgBox1;
        string eror = e->what();
        msgBox1.setText("ERROR " + QString::fromStdString(eror));
        msgBox1.exec();
    }


}

void MainWindow::on_actionCerrar_todas_las_pesta_as_triggered()
{
    this->ui->tabWidget->clear();
    this->listTextbox->clear();
}
