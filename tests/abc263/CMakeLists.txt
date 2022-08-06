add_executable(testabc263d d.cc)
target_link_libraries(testabc263d abc263d gtest_main)
gtest_discover_tests(testabc263d)
