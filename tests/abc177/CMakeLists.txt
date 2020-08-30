add_executable(TestAbc177d d.cc)
target_link_libraries(TestAbc177d Abc177d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAbc177d)
