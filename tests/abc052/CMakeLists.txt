add_executable(testabc052c c.cc)
add_executable(testabc052d d.cc)
target_link_libraries(testabc052c abc052c gtest_main)
target_link_libraries(testabc052d abc052d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc052c)
gtest_discover_tests(testabc052d)