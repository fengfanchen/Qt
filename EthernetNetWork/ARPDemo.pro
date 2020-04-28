QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += D:/winscp/WpdPack/Include
LIBS += -L D:/winscp/WpdPack/Lib/libpacket.a \
        -L D:/winscp/WpdPack/Lib/libwpcap.a
