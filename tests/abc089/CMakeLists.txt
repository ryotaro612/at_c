# https://atcoder.jp/contests/abc089
add_executable(testabc089d d.cc)
target_link_libraries(testabc089d abc089d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc089d)