TEMPLATE = app
TARGET = tst_qnitecircle
CONFIG += qmltestcase

SOURCES += \
    $$PWD/tst_qnitecircle.cpp

TESTDATA += \
    $$PWD/data/tst_qnitecircle.qml

IMPORTPATH += \
    $$PWD/../../../src/ \
    $$PWD/../../../src/qml/ \
    $$PWD/../../../src/tools/ \
    $$PWD/../../../src/items

include($$PWD/../../../src/qnite.pri)
