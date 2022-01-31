add_executable(testarc134b b.cc)
target_link_libraries(testarc134b arc134b gtest_main)
gtest_discover_tests(testarc134b)
