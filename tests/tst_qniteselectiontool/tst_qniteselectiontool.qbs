import qbs

CppApplication {
    name: "tst_qniteselectiontool"
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
        "tst_qniteselectiontool.cpp",
    ]
}
