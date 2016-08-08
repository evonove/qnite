TEMPLATE = app
TARGET = tst_qnite
CONFIG += qmltestcase

SOURCES += \
    $$PWD/tst_qnite.cpp

IMPORTPATH = \
    "qrc:/qml"

TESTDATA += \
    $$PWD/data/tst_*

include($$PWD/../../src/qnite.pri)
