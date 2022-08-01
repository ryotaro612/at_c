add_executable(testabc262d d.cc)
target_link_libraries(testabc262d abc262d gtest_main)
gtest_discover_tests(testabc262d)
