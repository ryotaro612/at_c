add_executable(testabc052c c.cc)
target_link_libraries(testabc052c abc052c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc052c)