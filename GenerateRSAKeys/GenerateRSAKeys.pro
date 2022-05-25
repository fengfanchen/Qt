QT += core
QT -= gui

TARGET = GenerateRSAKeys
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

QMAKE_CFLAGS = -fpermissive
QMAKE_CXXFLAGS = -fpermissive
QMAKE_LFLAGS = -fpermissive

INCLUDEPATH += /usr/local/ssl/include
LIBS += -L /usr/local/ssl/lib/ -lssl -lcrypto

TEMPLATE = app

SOURCES += main.cpp

