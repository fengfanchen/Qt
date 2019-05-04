#-------------------------------------------------
#
# Project created by QtCreator 2019-05-02T16:03:49
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = useQtWebAPP
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    httpserver/httpconnectionhandler.cpp \
    httpserver/httpconnectionhandlerpool.cpp \
    httpserver/httpcookie.cpp \
    httpserver/httpglobal.cpp \
    httpserver/httplistener.cpp \
    httpserver/httprequest.cpp \
    httpserver/httprequesthandler.cpp \
    httpserver/httpresponse.cpp \
    httpserver/httpsession.cpp \
    httpserver/httpsessionstore.cpp \
    httpserver/staticfilecontroller.cpp \
    myrequesthandler.cpp

HEADERS += \
        widget.h \
    httpserver/httpconnectionhandler.h \
    httpserver/httpconnectionhandlerpool.h \
    httpserver/httpcookie.h \
    httpserver/httpglobal.h \
    httpserver/httplistener.h \
    httpserver/httprequest.h \
    httpserver/httprequesthandler.h \
    httpserver/httpresponse.h \
    httpserver/httpsession.h \
    httpserver/httpsessionstore.h \
    httpserver/staticfilecontroller.h \
    myrequesthandler.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    httpserver/httpserver.pri

RESOURCES += \
    resources.qrc
