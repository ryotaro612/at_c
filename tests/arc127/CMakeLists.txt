include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testarc127a a.cc)
target_link_libraries(testarc127a arc127a gtest_main)
gtest_discover_tests(testarc127a)
