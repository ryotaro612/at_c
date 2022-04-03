add_executable(testabc245e e.cc)
target_link_libraries(testabc245e abc245e gtest_main)
gtest_discover_tests(testabc245e)
