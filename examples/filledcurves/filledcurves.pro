TEMPLATE = app
TARGET = example_filledcurves

QT += qml quick

SOURCES += main.cpp

RESOURCES += filledcurves.qrc

include(../deployment.pri)

QML_IMPORT_PATH += $$OUT_PWD/../../modules

OTHER_FILES += main.qml

