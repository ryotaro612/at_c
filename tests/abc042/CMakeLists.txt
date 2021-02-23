add_executable(testabc042c c.cc)
target_link_libraries(testabc042c abc042c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc042c)