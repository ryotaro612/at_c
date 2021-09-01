add_executable(testabc008c c.cc)
target_link_libraries(testabc008c abc008c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc008c)