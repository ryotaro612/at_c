add_executable(TestChristmas test_christmas.cc)
target_link_libraries(TestChristmas Christmas gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestChristmas)
