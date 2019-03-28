import qbs

CppApplication {
    name: "tst_qnitelinearmapper"
    type: "application"

    Depends { name: "Qt.testlib" }
    Depends {
        name: "qnite"
        Properties {
            withTests: false
            withExamples: false
        }
    }

    files: [
        "tst_qnitelinearmapper.cpp",
    ]
}
