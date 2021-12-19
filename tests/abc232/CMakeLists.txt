
add_executable(testabc232c c.cc)
target_link_libraries(testabc232c abc232c gtest_main)
gtest_discover_tests(testabc232c)
