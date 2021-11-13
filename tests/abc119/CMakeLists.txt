add_executable(TestLazyFaith test_lazy_faith.cc)
add_executable(testabc119c c.cc)
target_link_libraries(TestLazyFaith LazyFaith gtest_main)
target_link_libraries(testabc119c abc119c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestLazyFaith)
gtest_discover_tests(testabc119c)
