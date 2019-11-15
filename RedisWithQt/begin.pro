QT += core
QT -= gui

CONFIG += c++11

TARGET = begin
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp


LIBS += -L/home/ngsgcc/test_kf/MyRedis/hiredis-master -lhiredis
INCLUDEPATH += /home/ngsgcc/test_kf/MyRedis/hiredis-master

HEADERS += \
    ../../hiredis-master/adapters/qt.h

