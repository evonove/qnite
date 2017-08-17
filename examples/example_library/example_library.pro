TEMPLATE = app
QT += qml quick
CONFIG += c++11

RESOURCES += example_library.qrc

SOURCES += \
    $$PWD/main.cpp

INCLUDEPATH += \
    $$QNITE_SOURCE_TREE/src \
    $$QNITE_SOURCE_TREE/src/items \
    $$QNITE_SOURCE_TREE/src/tools \
    $$QNITE_SOURCE_TREE/3rdparty/qnanopainter/libqnanopainter

LIBS += \
    -L$$shadowed($$PWD)/../qnitelib -lqnite

include(deployment.pri)
