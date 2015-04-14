TEMPLATE = lib
TARGET = ../qnite
QT += qml quick
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = Qnite

# Input
SOURCES += \
    qnite_plugin.cpp \
    myitem.cpp

HEADERS += \
    qnite_plugin.h \
    myitem.h

unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    target.path = $$installPath
    INSTALLS += target
}

