add_executable(testabc019c c.cc)
target_link_libraries(testabc019c abc019c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc019c)