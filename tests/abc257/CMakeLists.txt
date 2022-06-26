add_executable(testabc257d d.cc)
target_link_libraries(testabc256d abc257d gtest_main)
gtest_discover_tests(testabc257d)
