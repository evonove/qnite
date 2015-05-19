TEMPLATE = aux

uri = Qnite

# qmldir file
qmldir_file.files = $$PWD/qmldir

# qml source files
qml_files.files = $$PWD/*.qml

OTHER_FILES = \
    $$qml_files.files \
    $$qmldir_file.files

isEmpty(DESTDIR) {
    DESTDIR = $$OUT_PWD
} else {
    DESTDIR = $$DESTDIR/Qnite
}

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_modules.target = qnite_copy_module
    copy_modules.commands = $(COPY_FILE) $$qml_files.files $$qmldir_file.files $$DESTDIR
    QMAKE_EXTRA_TARGETS += copy_modules
    POST_TARGETDEPS += $$copy_modules.target
}

unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qml_files.path = $$installPath
    qmldir_file.path = $$installPath
    INSTALLS += qml_files qmldir_file
}
