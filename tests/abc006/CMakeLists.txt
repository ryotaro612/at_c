add_executable(testabc006c c.cc)
target_link_libraries(testabc006c abc006c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc006c)