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
    tst_qnitelinearticker
    tst_qnitelinearticker.cpp
)

target_link_libraries(
    tst_qnitelinearticker
PRIVATE
    qnite
    Qt5::Test
)

add_test(
    tst_qnitelinearticker
    tst_qnitelinearticker
)
