########################################################
##Title: Examing Interface for Blackbox
##Author: Bowen Nie
##Date completed: August 7th
##Version 1.0.0.0807_beta
########################################################

TEMPLATE = app
TARGET = Blackbox
DEPENDPATH += .
INCLUDEPATH += .
QT += network

HEADERS += dialog.h training.h
SOURCES += dialog.cpp main.cpp training.cpp
