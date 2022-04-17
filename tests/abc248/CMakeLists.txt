add_executable(testabc248d d.cc)
target_link_libraries(testabc248d abc248d gtest_main)
gtest_discover_tests(testabc248d)
