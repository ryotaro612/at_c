add_executable(testabc003c c.cc)
target_link_libraries(testabc003c abc003c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc003c)