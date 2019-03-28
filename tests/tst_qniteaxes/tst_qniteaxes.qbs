import qbs

CppApplication {
    name: "tst_qniteaxes"
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
        "tst_qniteaxes.cpp",
    ]
}
