import qbs


StaticLibrary {
    name: "qnite"

    Depends { name: "cpp" }
    cpp.includePaths: [
        ".",
        "tools",
        "items",
        "../3rdparty/qnanopainter/libqnanopainter",
    ]
    cpp.cxxLanguageVersion: "c++14"
    cpp.defines: ["QNANO_QT_GL_INCLUDE"]
    cpp.dynamicLibraries: {
        if (qbs.targetOS.contains("windows")) {
            if (qbs.debugInformation) {
                return ["libGLESV2d"];
            } else {
                return ["libGLESV2"];
            }
        } else {
            return ["GL"];
        }
    }

    Depends { name: "Qt.qml" }
    Depends { name: "Qt.quick" }

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
        "qnite.qrc",

        // libqnanopainter
        "../3rdparty/qnanopainter/libqnanopainter/qnanoquickitem.cpp",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoquickitempainter.cpp",
        "../3rdparty/qnanopainter/libqnanopainter/qnanopainter.cpp",
        "../3rdparty/qnanopainter/libqnanopainter/qnanocolor.cpp",
        "../3rdparty/qnanopainter/libqnanopainter/qnanolineargradient.cpp",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoimagepattern.cpp",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoimage.cpp",
        "../3rdparty/qnanopainter/libqnanopainter/qnanofont.cpp",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoradialgradient.cpp",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoboxgradient.cpp",
        "../3rdparty/qnanopainter/libqnanopainter/private/qnanobrush.h",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoquickitem.h",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoquickitempainter.h",
        "../3rdparty/qnanopainter/libqnanopainter/qnanopainter.h",
        "../3rdparty/qnanopainter/libqnanopainter/qnanocolor.h",
        "../3rdparty/qnanopainter/libqnanopainter/qnanolineargradient.h",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoimagepattern.h",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoimage.h",
        "../3rdparty/qnanopainter/libqnanopainter/qnanofont.h",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoradialgradient.h",
        "../3rdparty/qnanopainter/libqnanopainter/qnanoboxgradient.h",
        "../3rdparty/qnanopainter/libqnanopainter/private/qnanodataelement.h",
        "../3rdparty/qnanopainter/libqnanopainter/nanovg/nanovg.c",
        "../3rdparty/qnanopainter/libqnanopainter/nanovg/nanovg.h",
        "../3rdparty/qnanopainter/libqnanopainter/libqnanopainterdata.qrc",
    ]

    Export {
        Depends { name: "cpp" }
        cpp.includePaths: [
            ".",
            "tools",
            "items",
            "../3rdparty/qnanopainter/libqnanopainter",
        ]
    }
}
