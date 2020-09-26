# https://atcoder.jp/contests/abc107
add_executable(TestCandles test_candles.cc)
add_executable(testabc107d d.cc)
target_link_libraries(testabc107d abc107d gtest_main)
target_link_libraries(TestCandles Candles gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestCandles)
gtest_discover_tests(testabc107d)
