add_executable(testabc245d d.cc)
target_link_libraries(testabc245d abc245d gtest_main)
gtest_discover_tests(testabc245d)
