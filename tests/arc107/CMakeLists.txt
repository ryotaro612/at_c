add_executable(testarc107a a.cc)
add_executable(testarc107b b.cc)

target_link_libraries(testarc107a arc107a gtest_main)
target_link_libraries(testarc107b arc107b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc107a)
gtest_discover_tests(testarc107b)