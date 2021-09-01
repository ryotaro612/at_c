add_executable(TestAbc174d test_abc174d.cc)
target_link_libraries(TestAbc174d Abc174d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAbc174d)
