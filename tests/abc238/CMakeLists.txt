add_executable(testabc238c c.cc)
target_link_libraries(testabc238c abc238c gtest_main)
gtest_discover_tests(testabc238c)
