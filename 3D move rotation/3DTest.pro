QT       += core gui datavisualization qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3DTest
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

RESOURCES += \
    resource.qrc
