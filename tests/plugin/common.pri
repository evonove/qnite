TEMPLATE = app
QT += testlib
CONFIG += testcase c++11

INCLUDEPATH += $$PWD/../../modules/Qnite/plugin/

isEmpty(DESTDIR) {
    DESTDIR = ../bin
    LIBS += -L$$OUT_PWD/../../../modules/Qnite/ -lqnite
    QMAKE_RPATHDIR += $$OUT_PWD/../bin/

    plugin_testdeps.target = qnite_plugin_testdeps
    plugin_testdeps.commands = $(COPY_FILE) $$OUT_PWD/../../modules/Qnite/libqnite.so $$OUT_PWD/../plugin/bin
    QMAKE_EXTRA_TARGETS += plugin_testdeps
    PRE_TARGETDEPS += $$plugin_testdeps.target

} else {
    LIBS += -L$$DESTDIR/Qnite -lqnite
    QMAKE_RPATHDIR += $$DESTDIR/Qnite
    DESTDIR = $$DESTDIR/tests
}

