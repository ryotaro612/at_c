add_executable(testarc106a a.cc)
add_executable(testarc106b b.cc)

target_link_libraries(testarc106a arc106a gtest_main)
target_link_libraries(testarc106b arc106b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc106a)
gtest_discover_tests(testarc106b)