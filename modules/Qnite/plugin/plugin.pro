TEMPLATE = lib
TARGET = qnite
QT += qml quick
CONFIG += qt plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = Qnite

INCLUDEPATH += \
    tools

# Input
SOURCES += \
    plugin.cpp \
    qniteartist.cpp \
    qnitexyartist.cpp \
    qniteaxis.cpp \
    qniteaxes.cpp \
    qnitebar.cpp \
    qnitebarnode.cpp \
    qnitecircle.cpp \
    qnitecirclenode.cpp \
    qnitefillnode.cpp \
    qnitelinenode.cpp \
    qniteclipper.cpp \
    qniteline.cpp \
    qnitespline.cpp \
    qnitemapper.cpp \
    qnitelinearmapper.cpp \
    qniteticker.cpp \
    qnitelinearticker.cpp \
    tools/qnitetool.cpp \
    tools/qniteselectiontool.cpp \
    tools/qnitepointselectiontool.cpp \
    tools/qnitepathselectiontool.cpp

HEADERS += \
    plugin.h \
    qniteartist.h \
    qnitexyartist.h \
    qniteaxis.h \
    qniteaxes.h \
    qnitebar.h \
    qnitebarnode.h \
    qnitecircle.h \
    qnitecirclenode.h \
    qnitefillnode.h \
    qnitelinenode.h \
    qniteclipper.h \
    qniteline.h \
    qnitespline.h \
    qnitemapper.h \
    qnitelinearmapper.h \
    qniteticker.h \
    qnitelinearticker.h \
    tools/qnitetool.h \
    tools/qniteselectiontool.h \
    tools/qnitepointselectiontool.h \
    tools/qnitepathselectiontool.h

isEmpty(DESTDIR) {
    DESTDIR = ..
} else {
    DESTDIR = $$DESTDIR/Qnite
}

unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    target.path = $$installPath
    INSTALLS += target
}

QMAKE_MOC_OPTIONS += -Muri=$$uri
