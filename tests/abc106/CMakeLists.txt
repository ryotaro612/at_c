# https://atcoder.jp/contests/abc106
add_executable(TestAtCoderExpress2 test_at_coder_express2.cc)
target_link_libraries(TestAtCoderExpress2 AtCoderExpress2 gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestAtCoderExpress2)
