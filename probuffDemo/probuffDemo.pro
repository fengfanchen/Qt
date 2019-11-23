QT += core
QT -= gui

CONFIG += c++11



TARGET = probuffDemo
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    TestProtocStruMsg.pb.cc

DEFINES += QT_DEPRECATED_WARNINGS

LIBS += -L/usr/local/lib -lprotobuf -lprotobuf-lite -lprotoc

HEADERS += \
    TestProtocStruMsg.pb.h

