add_executable(testabc018c c.cc)
target_link_libraries(testabc018c abc018c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc018c)