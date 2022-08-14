add_executable(testabc264d d.cc)
target_link_libraries(testabc264d abc264d gtest_main)
gtest_discover_tests(testabc264d)
