add_executable(TestNotDivisible test_not_divisible.cc)
target_link_libraries(TestNotDivisible NotDivisible gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestNotDivisible)
