add_executable(testarc124a a.cc)

target_link_libraries(testarc124a arc124a gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc124a)