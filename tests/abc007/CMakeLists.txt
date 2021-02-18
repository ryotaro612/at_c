add_executable(testabc007c c.cc)
target_link_libraries(testabc007c abc007c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc007c)