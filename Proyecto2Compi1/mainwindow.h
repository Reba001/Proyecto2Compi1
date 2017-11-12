#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileSystemModel>
#include <QMainWindow>
#include <QTextEdit>


#include <parser.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "nodo.h"
#include <QList>
#include <math.h>
#include "variables.h"
#include "clase.h"
extern int yyrestart(FILE* archivo);//METODO QUE PASA EL ARCHIVO A FLEX
extern int yyparse(); //METODO QUE INICIA EL ANALISIS SINTACTICO
extern Nodo * raiz;
extern void listaError(QList<QString> *listE);


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionCrear_nueva_pesta_a_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_actionCerrar_todas_las_pesta_as_triggered();

private:
    Ui::MainWindow *ui;
    QTextEdit * expresion;
    QList<QString> *listadeError;
    QList<QTextEdit *> *listTextbox;
    QFileSystemModel * dirmodel;
    QFileSystemModel * filemode;
    void crearPestania();
    void operacion(Nodo *asign, Variables *var, Clase * clas1);
    void recorrido(Nodo *padre, Clase *clas1);
    void metodo(Nodo * asign, Metodos *met, Clase *clas1);
    void varMets(Nodo * variable, Metodos *met, Clase * clas1);
    QString visibilidad(Nodo *padre);
    void lexps(Nodo *lex, Metodos * met, Metodos *metEncontrado, Clase *clas1 , int i);

};

#endif // MAINWINDOW_H
