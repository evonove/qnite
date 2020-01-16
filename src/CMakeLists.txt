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
    qnite
STATIC
    qniteartist.cpp
    qnitexyartist.cpp
    qniteaxis.cpp
    qnitelinearaxis.cpp
    qnitecategoryaxis.cpp
    qniteaxistick.cpp
    qniteaxes.cpp
    qniteclipper.cpp
    qnitemapper.cpp
    qnitelinearmapper.cpp
    qniteticker.cpp
    qnitelinearticker.cpp
    items/qnitebar.cpp
    items/qnitebarpainter.cpp
    items/qnitecircle.cpp
    items/qnitecirclepainter.cpp
    items/qnitegrid.cpp
    items/qnitegridpainter.cpp
    items/qniteline.cpp
    items/qnitelinepainter.cpp
    items/qnitepen.cpp
    items/qnitespline.cpp
    tools/qnitetool.cpp
    tools/qniteselectiontool.cpp
    tools/qnitepointselectiontool.cpp
    tools/qnitepathselectiontool.cpp
    tools/qnitepathpainter.cpp
    tools/qnitezoomtool.cpp
    tools/qnitezoompainter.cpp

    qnite.qrc
)

target_link_libraries(
    qnite
PUBLIC
    Qt5::Quick
    qnanopainter
)

target_compile_features(
    qnite
PUBLIC
    cxx_std_14
)

target_include_directories(
    qnite
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/tools
    ${CMAKE_CURRENT_SOURCE_DIR}/items
)