TEMPLATE = app
TARGET = tst_qnite
CONFIG += qmltestcase
SOURCES += tst_qnite.cpp

QML_IMPORT_PATH += $$OUT_PWD/../../modules

OTHER_FILES += \
    tst_foo.qml
