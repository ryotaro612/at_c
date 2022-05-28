add_executable(testabc253d d.cc)
target_link_libraries(testabc253d abc253d gtest_main)
gtest_discover_tests(testabc253d)
