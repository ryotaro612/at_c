# https://atcoder.jp/contests/abc098
add_executable(testabc097d d.cc)
target_link_libraries(testabc097d abc097d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc097d)
