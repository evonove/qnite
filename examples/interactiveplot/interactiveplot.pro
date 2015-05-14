TEMPLATE = app
TARGET = example_interactiveplot

QT += qml quick

SOURCES += main.cpp

RESOURCES += interactiveplot.qrc

include(../deployment.pri)

QML_IMPORT_PATH += $$OUT_PWD/../../modules

OTHER_FILES += main.qml

