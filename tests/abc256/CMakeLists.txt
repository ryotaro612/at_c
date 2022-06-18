add_executable(testabc256d d.cc)
target_link_libraries(testabc256d abc256d gtest_main)
gtest_discover_tests(testabc256d)
