add_executable(testarc109a a.cc)
target_link_libraries(testarc109a arc109a gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc109a)