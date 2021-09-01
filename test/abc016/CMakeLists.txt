add_executable(testabc016c c.cc)
target_link_libraries(testabc016c abc016c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc016c)