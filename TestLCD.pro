#-------------------------------------------------
#
# Project created by QtCreator 2015-05-22T00:11:03
#
#-------------------------------------------------

QT       += core gui
QT       += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestLCD
TEMPLATE = app


SOURCES += main.cpp\
        qduino.cpp

HEADERS  += qduino.h

FORMS    += qduino.ui
