add_executable(testabc267d d.cc)
target_link_libraries(testabc267d abc267d gtest_main)
gtest_discover_tests(testabc267d)
