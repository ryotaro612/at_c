# https://atcoder.jp/contests/abc107
add_executable(TestCandles test_candles.cc)
target_link_libraries(TestCandles Candles gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestCandles)
