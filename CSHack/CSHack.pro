#-------------------------------------------------
#
# Project created by QtCreator 2019-11-24T16:18:34
#
#-------------------------------------------------

QT       += core gui
CONFIG   += C++11

include(qxtglobalshortcut5/qxt.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CSHack
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    windowhand.cpp

HEADERS  += widget.h \
    windowhand.h

FORMS    += widget.ui
