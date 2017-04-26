########################################################
#Title: Training Interface for SLAT2000
#Author: Bowen Nie
#Date completed: April 26th
#Version 1.0.0.0426_beta
########################################################

TEMPLATE = app
TARGET = Training
DEPENDPATH += .
INCLUDEPATH += .
QT += network

HEADERS += dialog.h training.h
SOURCES += dialog.cpp main.cpp training.cpp
