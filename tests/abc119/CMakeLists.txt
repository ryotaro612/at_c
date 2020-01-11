add_executable(TestLazyFaith test_lazy_faith.cc)
target_link_libraries(TestLazyFaith LazyFaith gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestLazyFaith)
