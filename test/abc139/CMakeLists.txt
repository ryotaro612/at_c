add_executable(TestModSum test_mod_sum.cc)
target_link_libraries(TestModSum ModSum gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestModSum)
