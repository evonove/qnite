TEMPLATE = app
TARGET = example_lineplot

QT += qml quick

SOURCES += main.cpp

RESOURCES += lineplot.qrc

include(../deployment.pri)

QML_IMPORT_PATH += $$OUT_PWD/../../modules

OTHER_FILES += main.qml

