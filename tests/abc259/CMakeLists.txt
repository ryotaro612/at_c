add_executable(testabc259d d.cc)
target_link_libraries(testabc259d abc259d gtest_main)
gtest_discover_tests(testabc259d)
