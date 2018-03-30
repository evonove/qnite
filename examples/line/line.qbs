import qbs


Project {
    CppApplication {
        Depends { name: "qnite" }
        Depends { name: "Qt.quick" }

        files: [
            "line.qrc",
            "main.cpp",
        ]
    }
}
