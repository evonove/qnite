find_package(
    Qt5
COMPONENTS
    QuickTest
REQUIRED
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(
    tst_qnitezoomtool
    tst_qnitezoomtool.cpp
)

target_link_libraries(
    tst_qnitezoomtool
PRIVATE
    qnite
    Qt5::QuickTest
)

target_compile_definitions(
    tst_qnitezoomtool
PRIVATE
    QUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
    # This is kept for compatibility with qbs, when it's
    # removed from the test main it can be removed here
    INSTALL_ROOT=""
)

add_test(
    tst_qnitezoomtool
    tst_qnitezoomtool
)
