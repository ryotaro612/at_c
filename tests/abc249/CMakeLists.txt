add_executable(testabc249d d.cc)
target_link_libraries(testabc249d abc249d gtest_main)
gtest_discover_tests(testabc249d)
