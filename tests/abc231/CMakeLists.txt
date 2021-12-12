
add_executable(testabc231e e.cc)
target_link_libraries(testabc231e abc231e gtest_main)
gtest_discover_tests(testabc231e)