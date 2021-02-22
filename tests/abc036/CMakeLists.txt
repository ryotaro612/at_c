add_executable(testabc036c c.cc)
target_link_libraries(testabc036c abc036c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc036c)