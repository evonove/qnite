TEMPLATE = lib
TARGET = ../qnite
QT += qml quick
CONFIG += qt plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = Qnite

# Input
SOURCES += \
    plugin.cpp \
    qniteartist.cpp \
    qniteaxis.cpp \
    qniteaxes.cpp \
    qnitecircle.cpp \
    qnitecirclenode.cpp \
    qnitecurve.cpp \
    qnitemapper.cpp \
    qnitelinearmapper.cpp \
    qniteticker.cpp \
    qnitelinearticker.cpp

HEADERS += \
    plugin.h \
    qniteartist.h \
    qniteaxis.h \
    qniteaxes.h \
    qnitecircle.h \
    qnitecirclenode.h \
    qnitecurve.h \
    qnitemapper.h \
    qnitelinearmapper.h \
    qniteticker.h \
    qnitelinearticker.h

unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    target.path = $$installPath
    INSTALLS += target
}

