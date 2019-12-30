QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QWindowBase
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp \
    window.cpp \
    widget.cpp

HEADERS  += \
    window.h \
    widget.h

FORMS    += \
    widget.ui
