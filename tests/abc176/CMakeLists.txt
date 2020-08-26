add_executable(TestAbc176d d.cc)
target_link_libraries(TestAbc176d Abc176d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAbc176d)
