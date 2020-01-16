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
    tst_qnitecircle
    tst_qnitecircle.cpp
)

target_link_libraries(
    tst_qnitecircle
PRIVATE
    qnite
    Qt5::QuickTest
)

target_compile_definitions(
    tst_qnitecircle
PRIVATE
    QUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
    # This is kept for compatibility with qbs, when it's
    # removed from the test main it can be removed here
    INSTALL_ROOT=""
)

add_test(
    tst_qnitecircle
    tst_qnitecircle
)
