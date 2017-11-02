import qbs


StaticLibrary {
    name: "qnite"

    Depends { name: "cpp" }
    cpp.includePaths: [
        product.sourceDirectory + "/src/",
        product.sourceDirectory + "/src/tools/",
        product.sourceDirectory + "/src/items/",
        product.sourceDirectory + "/3rdparty/qnanopainter/libqnanopainter/",
    ]
    cpp.cxxLanguageVersion: "c++14"
    cpp.defines: ["QNANO_QT_GL_INCLUDE"]
    cpp.dynamicLibraries: ["GL"]

    Depends { name: "Qt.qml" }
    Depends { name: "Qt.quick" }

    files: [
        "src/qniteartist.cpp",
        "src/qnitexyartist.cpp",
        "src/qniteaxis.cpp",
        "src/qnitelinearaxis.cpp",
        "src/qnitecategoryaxis.cpp",
        "src/qniteaxistick.cpp",
        "src/qniteaxes.cpp",
        "src/qniteclipper.cpp",
        "src/qnitemapper.cpp",
        "src/qnitelinearmapper.cpp",
        "src/qniteticker.cpp",
        "src/qnitelinearticker.cpp",
        "src/items/qnitebar.cpp",
        "src/items/qnitebarpainter.cpp",
        "src/items/qnitecircle.cpp",
        "src/items/qnitecirclepainter.cpp",
        "src/items/qnitegrid.cpp",
        "src/items/qnitegridpainter.cpp",
        "src/items/qniteline.cpp",
        "src/items/qnitelinepainter.cpp",
        "src/items/qnitepen.cpp",
        "src/items/qnitespline.cpp",
        "src/tools/qnitetool.cpp",
        "src/tools/qniteselectiontool.cpp",
        "src/tools/qnitepointselectiontool.cpp",
        "src/tools/qnitepathselectiontool.cpp",
        "src/tools/qnitepathpainter.cpp",
        "src/qnite.h",
        "src/qniteartist.h",
        "src/qnitexyartist.h",
        "src/qniteaxis.h",
        "src/qnitelinearaxis.h",
        "src/qnitecategoryaxis.h",
        "src/qniteaxistick.h",
        "src/qniteaxes.h",
        "src/qniteclipper.h",
        "src/qnitemapper.h",
        "src/qnitelinearmapper.h",
        "src/qniteticker.h",
        "src/qnitelinearticker.h",
        "src/items/qnitebar.h",
        "src/items/qnitebarpainter.h",
        "src/items/qnitecircle.h",
        "src/items/qnitecirclepainter.h",
        "src/items/qniteline.h",
        "src/items/qnitegrid.h",
        "src/items/qnitegridpainter.h",
        "src/items/qnitelinepainter.h",
        "src/items/qnitespline.h",
        "src/items/qnitepen.h",
        "src/tools/qnitetool.h",
        "src/tools/qniteselectiontool.h",
        "src/tools/qnitepointselectiontool.h",
        "src/tools/qnitepathselectiontool.h",
        "src/tools/qnitepathpainter.h",
        "src/qnite.qrc",

        // libqnanopainter
        "3rdparty/qnanopainter/libqnanopainter/qnanoquickitem.cpp",
        "3rdparty/qnanopainter/libqnanopainter/qnanoquickitempainter.cpp",
        "3rdparty/qnanopainter/libqnanopainter/qnanopainter.cpp",
        "3rdparty/qnanopainter/libqnanopainter/qnanocolor.cpp",
        "3rdparty/qnanopainter/libqnanopainter/qnanolineargradient.cpp",
        "3rdparty/qnanopainter/libqnanopainter/qnanoimagepattern.cpp",
        "3rdparty/qnanopainter/libqnanopainter/qnanoimage.cpp",
        "3rdparty/qnanopainter/libqnanopainter/qnanofont.cpp",
        "3rdparty/qnanopainter/libqnanopainter/qnanoradialgradient.cpp",
        "3rdparty/qnanopainter/libqnanopainter/qnanoboxgradient.cpp",
        "3rdparty/qnanopainter/libqnanopainter/private/qnanobrush.h",
        "3rdparty/qnanopainter/libqnanopainter/qnanoquickitem.h",
        "3rdparty/qnanopainter/libqnanopainter/qnanoquickitempainter.h",
        "3rdparty/qnanopainter/libqnanopainter/qnanopainter.h",
        "3rdparty/qnanopainter/libqnanopainter/qnanocolor.h",
        "3rdparty/qnanopainter/libqnanopainter/qnanolineargradient.h",
        "3rdparty/qnanopainter/libqnanopainter/qnanoimagepattern.h",
        "3rdparty/qnanopainter/libqnanopainter/qnanoimage.h",
        "3rdparty/qnanopainter/libqnanopainter/qnanofont.h",
        "3rdparty/qnanopainter/libqnanopainter/qnanoradialgradient.h",
        "3rdparty/qnanopainter/libqnanopainter/qnanoboxgradient.h",
        "3rdparty/qnanopainter/libqnanopainter/private/qnanodataelement.h",
        "3rdparty/qnanopainter/libqnanopainter/nanovg/nanovg.c",
        "3rdparty/qnanopainter/libqnanopainter/nanovg/nanovg.h",
        "3rdparty/qnanopainter/libqnanopainter/libqnanopainterdata.qrc",
    ]

    Export {
        Depends { name: "cpp" }
        cpp.includePaths: [
            product.sourceDirectory + "/src/",
            product.sourceDirectory + "/src/tools/",
            product.sourceDirectory + "/src/items/",
            product.sourceDirectory + "/3rdparty/qnanopainter/libqnanopainter/",
        ]
    }
}
