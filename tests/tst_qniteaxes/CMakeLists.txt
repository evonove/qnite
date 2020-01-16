find_package(
    Qt5
COMPONENTS
    Test
REQUIRED
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(
    tst_qniteaxes
    tst_qniteaxes.cpp
)

target_link_libraries(
    tst_qniteaxes
PRIVATE
    qnite
    Qt5::Test
)

add_test(
    tst_qniteaxes
    tst_qniteaxes
)
