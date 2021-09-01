add_executable(testarc114a a.cc)
add_executable(testarc114b b.cc)

target_link_libraries(testarc114a arc114a gtest_main)
target_link_libraries(testarc114b arc114b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc114a)
gtest_discover_tests(testarc114b)