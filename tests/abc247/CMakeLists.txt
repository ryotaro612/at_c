add_executable(testabc247d d.cc)
target_link_libraries(testabc247d abc247d gtest_main)
gtest_discover_tests(testabc247d)

