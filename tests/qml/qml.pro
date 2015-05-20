TEMPLATE = app
TARGET = tst_qnite
CONFIG += qmltestcase
SOURCES += tst_qnite.cpp

IMPORTPATH += $$OUT_PWD/../../modules

DISTFILES += \
    tst_selecttool.qml \
    tst_foo.qml
