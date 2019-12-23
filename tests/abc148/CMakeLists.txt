add_executable(TestBrickBreak test_brick_break.cc)
target_link_libraries(TestBrickBreak BrickBreak gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestBrickBreak)
