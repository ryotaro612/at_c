add_executable(testabc255d d.cc)
target_link_libraries(testabc255d abc255d gtest_main)
gtest_discover_tests(testabc255d)
