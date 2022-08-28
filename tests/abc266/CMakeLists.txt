add_executable(testabc266d d.cc)
target_link_libraries(testabc266d abc266d gtest_main)
gtest_discover_tests(testabc266d)
