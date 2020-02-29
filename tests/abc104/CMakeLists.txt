# https://atcoder.jp/contests/abc105
add_executable(TestWeLoveABC test_we_love_abc.cc)
target_link_libraries(TestWeLoveABC WeLoveABC gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestWeLoveABC)
