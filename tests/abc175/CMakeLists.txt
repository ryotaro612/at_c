add_executable(TestAbc175c c.cc)
add_executable(TestAbc175d test_abc175d.cc)
target_link_libraries(TestAbc175d Abc175d gtest_main)
target_link_libraries(TestAbc175c Abc175c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAbc175d)
gtest_discover_tests(TestAbc175c)
