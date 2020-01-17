import qbs


Project {

    StaticLibrary {
        name: "qnanopainter"

        Depends { name: "Qt.quick" }
        Depends { name: "cpp" }
        cpp.includePaths: [
            "qnanopainter/libqnanopainter",
        ]
        cpp.cxxLanguageVersion: "c++14"
        cpp.defines: [
            "QNANO_QT_GL_INCLUDE",
            "QNANO_ENABLE_GLES3",
        ]
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

        Group {
            files: [
                "qnanopainter.cpp",
                "qnanocolor.cpp",
                "qnanolineargradient.cpp",
                "qnanoimagepattern.cpp",
                "qnanoimage.cpp",
                "qnanofont.cpp",
                "qnanoradialgradient.cpp",
                "qnanoboxgradient.cpp",
                "qnanowindow.cpp",
                "private/qnanodebug.cpp",
                "private/qnanobrush.h",
                "qnanopainter.h",
                "qnanocolor.h",
                "qnanolineargradient.h",
                "qnanoimagepattern.h",
                "qnanoimage.h",
                "qnanofont.h",
                "qnanoradialgradient.h",
                "qnanoboxgradient.h",
                "private/qnanodataelement.h",
                "private/qnanobackend.h",
                "private/qnanobackendfactory.h",
                "qnanowindow.h",
                "private/qnanodebug.h",

                // qt quick only dependency
                "qnanoquickitem.cpp",
                "qnanoquickitempainter.cpp",
                "qnanoquickitem.h",
                "qnanoquickitempainter.h",

                // nanovg
                "nanovg/nanovg.c",
                "nanovg/nanovg.h",

                // qrc font file
                "libqnanopainterdata.qrc"
            ]
            prefix: "qnanopainter/libqnanopainter/"
        }

        Group {
            condition: qbs.targetOS.containsAny(["android", "ios", "windows"])
            files: [
                "private/qnanobackendgles2.h",
                "private/qnanobackendgles3.h",
                "private/qnanobackendgles2.cpp",
                "private/qnanobackendgles3.cpp",
            ]
            prefix: "qnanopainter/libqnanopainter/"
        }

        Group {
            condition: qbs.targetOS.containsAny(["osx", "linux", "windows"]) &&
                       !qbs.targetOS.contains("android")
            files: [
                "private/qnanobackendgl2.h",
                "private/qnanobackendgl3.h",
                "private/qnanobackendgl2.cpp",
                "private/qnanobackendgl3.cpp",
            ]
            prefix: "qnanopainter/libqnanopainter/"
        }

        Export {
            Depends { name: "Qt.quick" }
            Depends { name: "cpp" }
            cpp.includePaths: [ "qnanopainter/libqnanopainter" ]
        }
    }
}
