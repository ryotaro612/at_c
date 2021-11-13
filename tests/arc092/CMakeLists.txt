add_executable(testarc092c c.cc)

target_link_libraries(testarc092c arc092c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc092c)