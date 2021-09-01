add_executable(testabc015c c.cc)
target_link_libraries(testabc015c abc015c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc015c)