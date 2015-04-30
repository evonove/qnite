TEMPLATE = aux

plugin_testdeps.target = qnite_plugin_testdeps
plugin_testdeps.commands = $(COPY_FILE) $$OUT_PWD/../../modules/Qnite/libqnite.so $$OUT_PWD/../plugin/bin
QMAKE_EXTRA_TARGETS += plugin_testdeps
PRE_TARGETDEPS += $$plugin_testdeps.target
