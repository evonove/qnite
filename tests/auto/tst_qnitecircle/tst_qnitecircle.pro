TEMPLATE = app
TARGET = tst_qnitecircle
CONFIG += qmltestcase

SOURCES += \
    $$PWD/tst_qnitecircle.cpp

TESTDATA += \
    $$PWD/data/tst_qnitecircle.qml

IMPORTPATH += \
    $$QNITE_SOURCE_TREE/src/ \
    $$QNITE_SOURCE_TREE/src/qml/ \
    $$QNITE_SOURCE_TREE/src/tools/ \
    $$QNITE_SOURCE_TREE/src/items

include($$QNITE_SOURCE_TREE/src/qnite.pri)
