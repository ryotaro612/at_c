add_executable(testarc114a a.cc)

target_link_libraries(testarc114a arc114a gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc114a)