add_executable(testabc251d d.cc)
target_link_libraries(testabc251d abc251d gtest_main)
gtest_discover_tests(testabc251d)
