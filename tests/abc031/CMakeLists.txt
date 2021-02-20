add_executable(testabc031c c.cc)
target_link_libraries(testabc031c abc031c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc031c)