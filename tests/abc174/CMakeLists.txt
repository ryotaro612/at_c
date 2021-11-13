include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(TestAbc174d test_abc174d.cc)
target_link_libraries(TestAbc174d Abc174d gtest_main)
gtest_discover_tests(TestAbc174d)

add_executable(testabc174f f.cc)
target_link_libraries(testabc174f abc174f gtest_main)
gtest_discover_tests(testabc174f)