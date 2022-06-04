add_executable(testabc254d d.cc)
target_link_libraries(testabc254d abc254d gtest_main)
gtest_discover_tests(testabc254d)
