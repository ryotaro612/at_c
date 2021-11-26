include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testarc127a a.cc)
target_link_libraries(testarc127a arc127a gtest_main)
gtest_discover_tests(testarc127a)

add_executable(testarc127b b.cc)
target_link_libraries(testarc127b arc127b gtest_main)
gtest_discover_tests(testarc127b)