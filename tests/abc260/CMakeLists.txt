add_executable(testabc260d d.cc)
target_link_libraries(testabc260d abc260d gtest_main)
gtest_discover_tests(testabc260d)
