TEMPLATE = app
TARGET = example_scatterplot

QT += qml quick

SOURCES += main.cpp

RESOURCES += scatterplot.qrc

include(../deployment.pri)

QML_IMPORT_PATH += $$OUT_PWD/../../modules

OTHER_FILES += main.qml

