add_executable(testarc115a a.cc)

target_link_libraries(testarc115a arc115a gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc115a)