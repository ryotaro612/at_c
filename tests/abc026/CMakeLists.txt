add_executable(testabc026c c.cc)
target_link_libraries(testabc026c abc026c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc026c)