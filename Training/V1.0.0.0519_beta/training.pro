########################################################
#Title: Training Interface for SLAT2000
#Author: Bowen Nie
#Date completed: May 3rd
#Version 1.0.0.0503_beta
########################################################

TEMPLATE = app
TARGET = training
DEPENDPATH += .
INCLUDEPATH += .
QT += network

HEADERS += dialog.h training.h
SOURCES += dialog.cpp main.cpp training.cpp
