add_executable(TestLinePlusPlus test_line_plus_plus.cc)
target_link_libraries(TestLinePlusPlus LinePlusPlus gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestLinePlusPlus)
