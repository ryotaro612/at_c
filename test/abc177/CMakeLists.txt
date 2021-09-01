add_executable(TestAbc177d d.cc)
add_executable(testabc177e e.cc)

target_link_libraries(TestAbc177d Abc177d gtest_main)
target_link_libraries(testabc177e abc177e gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAbc177d)
gtest_discover_tests(testabc177e)
