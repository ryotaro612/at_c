add_executable(testtenka1_2017c c.cc)

target_link_libraries(testtenka1_2017c tenka1_2017c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testtenka1_2017c)