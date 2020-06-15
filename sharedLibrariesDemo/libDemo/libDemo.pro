QT += widgets

TEMPLATE = lib
DEFINES += LIBDEMO_LIBRARY

CONFIG += c++11

SOURCES += \
    LibDemo.cpp

HEADERS += \
    libDemo_global.h \
    LibDemo.h

unix {
    target.path = /usr/lib
}

!isEmpty(target.path): INSTALLS += target
