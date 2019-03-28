import qbs

CppApplication {
    name: "tst_qnitelinearticker"
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
        "tst_qnitelinearticker.cpp",
    ]
}
