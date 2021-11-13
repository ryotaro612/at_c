# https://atcoder.jp/contests/abc103
add_executable(TestIslandsWar test_islands_war.cc)
target_link_libraries(TestIslandsWar IslandsWar gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestIslandsWar)
