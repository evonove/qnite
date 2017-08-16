QT += qml quick
CONFIG += c++14

INCLUDEPATH += \
    $$PWD/ \
    $$PWD/tools \
    $$PWD/items

# Input
SOURCES += \
    $$PWD/qniteartist.cpp \
    $$PWD/qnitexyartist.cpp \
    $$PWD/qniteaxis.cpp \
    $$PWD/qnitelinearaxis.cpp \
    $$PWD/qnitecategoryaxis.cpp \
    $$PWD/qniteaxistick.cpp \
    $$PWD/qniteaxes.cpp \
    $$PWD/qniteclipper.cpp \
    $$PWD/qnitemapper.cpp \
    $$PWD/qnitelinearmapper.cpp \
    $$PWD/qniteticker.cpp \
    $$PWD/qnitelinearticker.cpp \
    $$PWD/items/qnitebar.cpp \
    $$PWD/items/qnitebarpainter.cpp \
    $$PWD/items/qnitecircle.cpp \
    $$PWD/items/qnitecirclepainter.cpp \
    $$PWD/items/qnitegrid.cpp \
    $$PWD/items/qnitegridpainter.cpp \
    $$PWD/items/qniteline.cpp \
    $$PWD/items/qnitelinepainter.cpp \
    $$PWD/items/qnitepen.cpp \
    $$PWD/items/qnitespline.cpp \
    $$PWD/tools/qnitetool.cpp \
    $$PWD/tools/qniteselectiontool.cpp \
    $$PWD/tools/qnitepointselectiontool.cpp \
    $$PWD/tools/qnitepathselectiontool.cpp \
    $$PWD/tools/qnitepathpainter.cpp

HEADERS += \
    $$PWD/qnite.h \
    $$PWD/qniteartist.h \
    $$PWD/qnitexyartist.h \
    $$PWD/qniteaxis.h \
    $$PWD/qnitelinearaxis.h \
    $$PWD/qnitecategoryaxis.h \
    $$PWD/qniteaxistick.h \
    $$PWD/qniteaxes.h \
    $$PWD/qniteclipper.h \
    $$PWD/qnitemapper.h \
    $$PWD/qnitelinearmapper.h \
    $$PWD/qniteticker.h \
    $$PWD/qnitelinearticker.h \
    $$PWD/items/qnitebar.h \
    $$PWD/items/qnitebarpainter.h \
    $$PWD/items/qnitecircle.h \
    $$PWD/items/qnitecirclepainter.h \
    $$PWD/items/qniteline.h \
    $$PWD/items/qnitegrid.h \
    $$PWD/items/qnitegridpainter.h \
    $$PWD/items/qnitelinepainter.h \
    $$PWD/items/qnitespline.h \
    $$PWD/items/qnitepen.h \
    $$PWD/tools/qnitetool.h \
    $$PWD/tools/qniteselectiontool.h \
    $$PWD/tools/qnitepointselectiontool.h \
    $$PWD/tools/qnitepathselectiontool.h \
    $$PWD/tools/qnitepathpainter.h

RESOURCES += \
    $$PWD/qnite.qrc

# including qnanopainter
include($$PWD/../3rdparty/qnanopainter/libqnanopainter/include.pri)
