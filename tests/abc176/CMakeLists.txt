add_executable(TestAbc176d d.cc)
add_executable(testabc176f f.cc)
target_link_libraries(TestAbc176d Abc176d gtest_main)
target_link_libraries(testabc176f abc176f gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAbc176d)
gtest_discover_tests(testabc176f)