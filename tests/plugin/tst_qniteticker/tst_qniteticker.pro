TEMPLATE = app
QT += testlib
CONFIG += testcase

TARGET = tst_qniteticker

SOURCES +=\
  tst_qniteticker.cpp \
  tst_qnitelinearticker.cpp


LIBS += -L../../../modules/Qnite/ -lqnite
