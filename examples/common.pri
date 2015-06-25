QT += qml quick
CONFIG += c++11

isEmpty(DESTDIR) {
    DESTDIR = $$OUT_PWD/..
} else {
    DESTDIR = $$DESTDIR/examples
}

SOURCES += ../main.cpp

QML_IMPORT_PATH += $$OUT_PWD/../../modules

OTHER_FILES += main.qml
