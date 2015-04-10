TEMPLATE = app
TARGET = example_plot

QT += qml quick widgets

SOURCES += main.cpp

RESOURCES += plot.qrc

include(../deployment.pri)

QML_IMPORT_PATH += $$OUT_PWD/../../modules

OTHER_FILES += main.qml

