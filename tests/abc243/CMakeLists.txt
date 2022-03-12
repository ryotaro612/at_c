add_executable(testabc243d d.cc)
target_link_libraries(testabc243d abc243d gtest_main)
gtest_discover_tests(testabc243d)
