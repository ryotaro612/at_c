add_executable(testabc245f f.cc)
target_link_libraries(testabc245f abc245f gtest_main)
gtest_discover_tests(testabc245f)
