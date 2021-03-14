add_executable(testabc195c c.cc)
target_link_libraries(testabc195c abc195c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc195c)