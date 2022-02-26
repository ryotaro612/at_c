add_executable(testabc241c c.cc)
target_link_libraries(testabc241c abc241c gtest_main)
gtest_discover_tests(testabc241c)
