# https://atcoder.jp/contests/abc106
add_executable(TestCandyDistribution test_candy_distribution.cc)
add_executable(testabc105c c.cc)
target_link_libraries(TestCandyDistribution CandyDistribution gtest_main)
target_link_libraries(testabc105c abc105c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestCandyDistribution)
gtest_discover_tests(testabc105c)
