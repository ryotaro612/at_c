include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testarc130b b.cc)
target_link_libraries(testarc130b arc130b gtest_main)
gtest_discover_tests(testarc130b)