# https://atcoder.jp/contests/abc106
add_executable(TestCandyDistribution test_candy_distribution.cc)
target_link_libraries(TestCandyDistribution CandyDistribution gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestCandyDistribution)
