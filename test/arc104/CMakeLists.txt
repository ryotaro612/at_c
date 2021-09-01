add_executable(testarc104b b.cc)

target_link_libraries(testarc104b arc104b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc104b)