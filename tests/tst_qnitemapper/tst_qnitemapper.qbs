import qbs

CppApplication {
    name: "tst_qnitemapper"
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
        "tst_qnitemapper.cpp",
    ]
}
