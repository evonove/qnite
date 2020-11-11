project(qnanopainter)

find_package(
    Qt5
COMPONENTS
    Quick
REQUIRED
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(
    qnanopainter
STATIC
    qnanopainter/libqnanopainter/qnanopainter.cpp
    qnanopainter/libqnanopainter/qnanocolor.cpp
    qnanopainter/libqnanopainter/qnanolineargradient.cpp
    qnanopainter/libqnanopainter/qnanoimagepattern.cpp
    qnanopainter/libqnanopainter/qnanoimage.cpp
    qnanopainter/libqnanopainter/qnanofont.cpp
    qnanopainter/libqnanopainter/qnanoradialgradient.cpp
    qnanopainter/libqnanopainter/qnanoboxgradient.cpp
    qnanopainter/libqnanopainter/qnanowindow.cpp
    qnanopainter/libqnanopainter/private/qnanodebug.cpp
    qnanopainter/libqnanopainter/qnanoquickitem.cpp
    qnanopainter/libqnanopainter/qnanoquickitempainter.cpp
    qnanopainter/libqnanopainter/nanovg/nanovg.c
    $<$<OR:$<BOOL:${ANDROID}>,$<BOOL:${IOS}>,$<BOOL:${WIN32}>>:qnanopainter/libqnanopainter/private/qnanobackendgles2.cpp>
    $<$<OR:$<BOOL:${ANDROID}>,$<BOOL:${IOS}>,$<BOOL:${WIN32}>>:qnanopainter/libqnanopainter/private/qnanobackendgles3.cpp>
    $<$<NOT:$<BOOL:${ANDROID}>>:qnanopainter/libqnanopainter/private/qnanobackendgl2.cpp>
    $<$<NOT:$<BOOL:${ANDROID}>>:qnanopainter/libqnanopainter/private/qnanobackendgl3.cpp>
    
    qnanopainter/libqnanopainter/libqnanopainterdata.qrc
)

target_compile_features(
    qnanopainter
PUBLIC
    cxx_std_14
)

target_compile_definitions(
    qnanopainter
PRIVATE
    QNANO_QT_GL_INCLUDE
    QNANO_ENABLE_GLES3
)

target_link_libraries(
    qnanopainter
PRIVATE
    Qt5::Quick
    $<$<BOOL:${WIN32}>:Qt5::Gui_GLESv2>
    $<$<NOT:$<BOOL:${WIN32}>>:GL>
)

target_include_directories(
    qnanopainter
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/qnanopainter/libqnanopainter
)
