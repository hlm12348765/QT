########################################################
#Title: Training Interface for SLAT2000
#Author: Bowen Nie
#Date completed: May 3rd
#Version 1.0.0.0503_beta
########################################################

TEMPLATE = app
TARGET = Training
DEPENDPATH += .
INCLUDEPATH += .
QT += network

HEADERS += dialog.h training.h \
    form.h
SOURCES += dialog.cpp main.cpp training.cpp \
    form.cpp

FORMS += \
    form.ui
