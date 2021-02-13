add_executable(testarc112a a.cc)
target_link_libraries(testarc112a arc112a gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc112a)