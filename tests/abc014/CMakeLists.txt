add_executable(testabc014c c.cc)
target_link_libraries(testabc014c abc014c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc014c)