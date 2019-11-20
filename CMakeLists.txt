cmake_minimum_required(VERSION 3.8)

project(
    qnite
    DESCRIPTION "A Qt/QML charting library"
    HOMEPAGE_URL "https://github.com/evonove/qnite"
)

add_subdirectory(src)
add_subdirectory(3rdparty)

# Examples must be compiled explicitly by specifying the examples target
add_subdirectory(examples EXCLUDE_FROM_ALL)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    include(CTest)
    add_subdirectory(tests)
endif()

