add_executable(testabc261d d.cc)
target_link_libraries(testabc261d abc261d gtest_main)
gtest_discover_tests(testabc261d)
