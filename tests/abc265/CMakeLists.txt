add_executable(testabc265d d.cc)
target_link_libraries(testabc265d abc265d gtest_main)
gtest_discover_tests(testabc265d)
