QT += core
QT -= gui

TARGET = OpenSSLDemo
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += /usr/local/ssl/include
LIBS += -L /usr/local/ssl/lib/ -lssl -lcrypto

TEMPLATE = app

SOURCES += main.cpp

