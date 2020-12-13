# https://atcoder.jp/contests/abc062
add_executable(testabc062d d.cc)
target_link_libraries(testabc062d abc062d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc062d)