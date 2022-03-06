add_executable(testabc242a a.cc)
target_link_libraries(testabc242a abc242a gtest_main)
gtest_discover_tests(testabc242a)

add_executable(testabc242b b.cc)
target_link_libraries(testabc242b abc242b gtest_main)
gtest_discover_tests(testabc242b)

add_executable(testabc242d d.cc)
target_link_libraries(testabc242d abc242d gtest_main)
gtest_discover_tests(testabc242d)

add_executable(testabc242e e.cc)
target_link_libraries(testabc242e abc242e gtest_main)
gtest_discover_tests(testabc242e)
