add_executable(testabc024c c.cc)
target_link_libraries(testabc024c abc024c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc024c)