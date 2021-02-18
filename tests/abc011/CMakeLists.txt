add_executable(testabc011c c.cc)
target_link_libraries(testabc011c abc011c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc011c)