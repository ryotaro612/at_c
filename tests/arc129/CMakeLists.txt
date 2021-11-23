include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testarc129a a.cc)
target_link_libraries(testarc129a arc129a gtest_main)
gtest_discover_tests(testarc129a)