TEMPLATE = app
QT += testlib
CONFIG += testcase
TARGET = tst_qnitelinearticker
SOURCES = tst_qnitelinearticker.cpp
LIBS += -L../../../modules/Qnite/ -lqnite
