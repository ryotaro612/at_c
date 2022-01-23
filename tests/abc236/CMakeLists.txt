add_executable(testabc236d d.cc)
target_link_libraries(testabc236d abc236d gtest_main)
gtest_discover_tests(testabc236d)
