add_executable(TestSumOfDivisors test_sum_of_divisors.cc)
target_link_libraries(TestSumOfDivisors SumOfDivisors gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestSumOfDivisors)
