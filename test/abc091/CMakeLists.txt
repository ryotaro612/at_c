# https://atcoder.jp/contests/abc091
add_executable(testabc091d d.cc)
target_link_libraries(testabc091d abc091d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc091d)