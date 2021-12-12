
add_executable(testabc231e e.cc)
target_link_libraries(testabc231e abc231e gtest_main)
gtest_discover_tests(testabc231e)

add_executable(testabc231f f.cc)
target_link_libraries(testabc231f abc231f gtest_main)
gtest_discover_tests(testabc231f)