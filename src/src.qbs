import qbs


StaticLibrary {
    name: "qnite"

    Depends { name: "qnanopainter" }

    Depends { name: "cpp" }
    cpp.includePaths: [ ".", "tools", "items" ]
    cpp.cxxLanguageVersion: "c++14"

    files: [
        "qniteartist.cpp",
        "qnitexyartist.cpp",
        "qniteaxis.cpp",
        "qnitelinearaxis.cpp",
        "qnitecategoryaxis.cpp",
        "qniteaxistick.cpp",
        "qniteaxes.cpp",
        "qniteclipper.cpp",
        "qnitemapper.cpp",
        "qnitelinearmapper.cpp",
        "qniteticker.cpp",
        "qnitelinearticker.cpp",
        "items/qnitebar.cpp",
        "items/qnitebarpainter.cpp",
        "items/qnitecircle.cpp",
        "items/qnitecirclepainter.cpp",
        "items/qnitegrid.cpp",
        "items/qnitegridpainter.cpp",
        "items/qniteline.cpp",
        "items/qnitelinepainter.cpp",
        "items/qnitepen.cpp",
        "items/qnitespline.cpp",
        "tools/qnitetool.cpp",
        "tools/qniteselectiontool.cpp",
        "tools/qnitepointselectiontool.cpp",
        "tools/qnitepathselectiontool.cpp",
        "tools/qnitepathpainter.cpp",
        "tools/qnitezoomtool.cpp",
        "tools/qnitezoompainter.cpp",
        "qnite.h",
        "qniteartist.h",
        "qnitexyartist.h",
        "qniteaxis.h",
        "qnitelinearaxis.h",
        "qnitecategoryaxis.h",
        "qniteaxistick.h",
        "qniteaxes.h",
        "qniteclipper.h",
        "qnitemapper.h",
        "qnitelinearmapper.h",
        "qniteticker.h",
        "qnitelinearticker.h",
        "items/qnitebar.h",
        "items/qnitebarpainter.h",
        "items/qnitecircle.h",
        "items/qnitecirclepainter.h",
        "items/qniteline.h",
        "items/qnitegrid.h",
        "items/qnitegridpainter.h",
        "items/qnitelinepainter.h",
        "items/qnitespline.h",
        "items/qnitepen.h",
        "tools/qnitetool.h",
        "tools/qniteselectiontool.h",
        "tools/qnitepointselectiontool.h",
        "tools/qnitepathselectiontool.h",
        "tools/qnitepathpainter.h",
        "tools/qnitezoomtool.h",
        "tools/qnitezoompainter.h",
        "qnite.qrc",
    ]

    Export {
        Depends { name: "qnanopainter" }
        Depends { name: "Qt.quick" }
        Depends { name: "cpp" }
        cpp.includePaths: [ ".", "tools", "items" ]
    }
}
