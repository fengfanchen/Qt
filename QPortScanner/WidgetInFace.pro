#-------------------------------------------------
#
# Project created by QtCreator 2018-07-09T23:35:34
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WidgetInFace
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mylabel.cpp \
    mynetwork.cpp

HEADERS  += widget.h \
    mylabel.h \
    mynetwork.h

FORMS    += widget.ui


RC_FILE = version.rc


RESOURCES += \
    resources.qrc
