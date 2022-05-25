QT += core
QT -= gui

TARGET = RSAEncryptionAndDecryption
CONFIG += console
CONFIG -= app_bundle

QMAKE_CFLAGS = -fpermissive
QMAKE_CXXFLAGS = -fpermissive
QMAKE_LFLAGS = -fpermissive

INCLUDEPATH += /usr/local/ssl/include
LIBS += -L /usr/local/ssl/lib/ -lssl -lcrypto


TEMPLATE = app

SOURCES += main.cpp

