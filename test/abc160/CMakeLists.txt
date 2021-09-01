add_executable(testabc160e e.cc)
add_executable(TestLinePlusPlus test_line_plus_plus.cc)

target_link_libraries(testabc160e abc160e gtest_main)
target_link_libraries(TestLinePlusPlus LinePlusPlus gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestLinePlusPlus)
gtest_discover_tests(testabc160e)