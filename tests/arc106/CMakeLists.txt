add_executable(testarc106a a.cc)
target_link_libraries(testarc106a arc106a gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc106a)