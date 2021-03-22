add_executable(testarc115a a.cc)
add_executable(testarc115b b.cc)

target_link_libraries(testarc115a arc115a gtest_main)
target_link_libraries(testarc115b arc115b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc115a)
gtest_discover_tests(testarc115b)