import qbs


Project {
    minimumQbsVersion: "1.7.1"

    property bool withTests: true

    property bool withExamples: true

    SubProject {
        filePath: "src/src.qbs"
    }

    SubProject {
        filePath: "3rdparty/qnanopainter.qbs"
    }

    SubProject {
        filePath: "tests/tests.qbs"
        Properties {
            condition: parent.withTests
        }
    }

    SubProject {
        filePath: "examples/examples.qbs"
        Properties {
            condition: parent.withExamples
        }
    }
}
