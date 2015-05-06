TEMPLATE = app
TARGET = example_splineplot

QT += qml quick

SOURCES += main.cpp

RESOURCES += splineplot.qrc

include(../deployment.pri)

QML_IMPORT_PATH += $$OUT_PWD/../../modules

OTHER_FILES += main.qml

