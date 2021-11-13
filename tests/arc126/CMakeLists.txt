include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testarc126a a.cc)
target_link_libraries(testarc126a arc126a gtest_main)
gtest_discover_tests(testarc126a)

add_executable(testarc126b b.cc)
target_link_libraries(testarc126b arc126b gtest_main)
gtest_discover_tests(testarc126b)