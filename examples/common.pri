QT += qml quick
CONFIG += c++11

!isEmpty(DESTDIR) {
    DESTDIR = $$DESTDIR/examples
}

SOURCES += \
    $$PWD/main.cpp

QML_IMPORT_PATH += $$OUT_PWD/../../modules

OTHER_FILES += \
    $$PWD/main.qml
    $$PWD/BarPlot.qml
    $$PWD/FilledCurves.qml
