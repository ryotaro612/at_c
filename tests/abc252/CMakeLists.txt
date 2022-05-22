add_executable(testabc252d d.cc)
target_link_libraries(testabc252d abc252d gtest_main)
gtest_discover_tests(testabc252d)
