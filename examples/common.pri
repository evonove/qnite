QT += qml quick
CONFIG += c++11

SOURCES += \
    $$PWD/main.cpp

OTHER_FILES += \
    $$PWD/main.qml
    $$PWD/BarPlot.qml
    $$PWD/FilledCurves.qml

include($$PWD/../src/qnite.pri)
