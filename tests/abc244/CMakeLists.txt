add_executable(testabc244d d.cc)
target_link_libraries(testabc244d abc244d gtest_main)
gtest_discover_tests(testabc244d)
