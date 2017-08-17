TEMPLATE = app
QT += qml quick
CONFIG += c++11

RESOURCES += example_include.qrc

SOURCES += \
    $$PWD/main.cpp

OTHER_FILES += \
    $$PWD/main.qml

include($$QNITE_SOURCE_TREE/src/qnite.pri)
include(deployment.pri)
