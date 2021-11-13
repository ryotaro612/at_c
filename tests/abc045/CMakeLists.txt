add_executable(testabc045c c.cc)
target_link_libraries(testabc045c abc045c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc045c)