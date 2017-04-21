#-------------------------------------------------
#
# Project created by QtCreator 2017-04-10T15:12:10
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InterfaceChange
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    training.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    training.h

FORMS    += mainwindow.ui \
    dialog.ui \
    training.ui
