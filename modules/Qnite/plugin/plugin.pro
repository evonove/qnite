TEMPLATE = lib
TARGET = ../qnite
QT += qml quick
CONFIG += qt plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = Qnite

# Input
SOURCES += \
    plugin.cpp \
    qnitecurve.cpp \
    qnitescalemap.cpp \
    qniteticker.cpp

HEADERS += \
    plugin.h \
    qnitecurve.h \
    qnitescalemap.h \
    qniteticker.h

unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    target.path = $$installPath
    INSTALLS += target
}

