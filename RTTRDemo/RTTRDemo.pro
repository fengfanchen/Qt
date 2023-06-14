QT += core
QT -= gui

CONFIG += c++11

TARGET = RTTRDemo
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp


INCLUDEPATH += /xxxx/xxxx/CFFPro/rttr-0.9.5-src/src
LIBS += -L/xxxx/xxxx/CFFPro/rttr-0.9.5-src/bin -lrttr_core
