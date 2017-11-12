#-------------------------------------------------
#
# Project created by QtCreator 2017-10-23T17:31:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto2Compi1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    nodo.cpp \
    parser.cpp \
    scanner.cpp \
    variables.cpp \
    metodos.cpp \
    clase.cpp \
    bucle.cpp \
    errorsemantico.cpp \
    condicional.cpp \
    consola.cpp

HEADERS  += mainwindow.h \
    nodo.h \
    lexicoProyecto2.l \
    parser.h \
    scanner.h \
    sintacticoProyecto2.y \
    variables.h \
    metodos.h \
    clase.h \
    bucle.h \
    errorsemantico.h \
    condicional.h \
    consola.h

FORMS    += mainwindow.ui \
    consola.ui
