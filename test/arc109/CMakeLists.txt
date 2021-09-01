add_executable(testarc109a a.cc)
add_executable(testarc109b b.cc)
target_link_libraries(testarc109a arc109a gtest_main)
target_link_libraries(testarc109b arc109b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc109a)
gtest_discover_tests(testarc109b)