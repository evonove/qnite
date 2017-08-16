TEMPLATE = lib
TARGET = qnite
CONFIG += qt static

uri = Qnite

include($$PWD/qnite.pri)

QMAKE_MOC_OPTIONS += -Muri=$$uri
