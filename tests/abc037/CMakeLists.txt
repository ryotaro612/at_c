add_executable(testabc037c c.cc)
target_link_libraries(testabc037c abc037c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc037c)