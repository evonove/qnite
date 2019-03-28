import qbs

CppApplication {
    name: "tst_qniteclipper"
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
        "tst_qniteclipper.cpp",
    ]
}
