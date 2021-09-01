# https://atcoder.jp/contests/abc063
add_executable(testabc063d d.cc)
target_link_libraries(testabc063d abc063d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc063d)