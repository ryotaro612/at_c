add_executable(testabc258d d.cc)
target_link_libraries(testabc258d abc258d gtest_main)
gtest_discover_tests(testabc258d)
