import qbs

CppApplication {
    name: "tst_qniteticker"
    type: "application"

    Depends { name: "Qt.qmltest" }
    Depends {
        name: "qnite"
        Properties {
            withTests: false
            withExamples: false
        }
    }

    cpp.defines: [
        "QUICK_TEST_SOURCE_DIR=\"" + path + "\"",
        "INSTALL_ROOT=\"" + qbs.installRoot + "\""
    ]

    files: [
        "tst_qniteticker.cpp",
    ]
}
