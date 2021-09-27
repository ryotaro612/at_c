include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc220c c.cc)
target_link_libraries(testabc220c abc220c gtest_main)
gtest_discover_tests(testabc220c)