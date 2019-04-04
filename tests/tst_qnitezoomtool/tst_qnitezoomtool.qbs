import qbs

CppApplication {
    name: "tst_qnitezoomtool"

    cpp.defines: [
        "QUICK_TEST_SOURCE_DIR=\"" + path + "\"",
        "INSTALL_ROOT=\"" + qbs.installRoot + "\""
    ]

    Depends { name: "Qt.qmltest" }
    Depends {
        name: "qnite"
        Properties {
            withTests: false
            withExamples: false
        }
    }

    files: [
        "tst_qnitezoomtool.cpp",
    ]
}

