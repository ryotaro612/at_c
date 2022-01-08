add_executable(testabc234f f.cc)
target_link_libraries(testabc234f abc234f gtest_main)
gtest_discover_tests(testabc234f)
