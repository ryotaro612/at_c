add_executable(testarc113a a.cc)
add_executable(testarc113b b.cc)
target_link_libraries(testarc113a arc113a gtest_main)
target_link_libraries(testarc113b arc113b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc113a)
gtest_discover_tests(testarc113b)