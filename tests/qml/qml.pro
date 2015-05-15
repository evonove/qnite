TEMPLATE = app
TARGET = tst_qnite
CONFIG += qmltestcase
SOURCES += tst_qnite.cpp

IMPORTPATH += $$OUT_PWD/../../modules

OTHER_FILES += \
    tst_foo.qml \
    tst_selectool.qml
