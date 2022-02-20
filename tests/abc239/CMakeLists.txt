add_executable(testabc239e e.cc)
target_link_libraries(testabc239e abc239e gtest_main)
gtest_discover_tests(testabc239e)
