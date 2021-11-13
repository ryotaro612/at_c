include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(TestBrickBreak test_brick_break.cc)
target_link_libraries(TestBrickBreak BrickBreak gtest_main)
gtest_discover_tests(TestBrickBreak)

add_executable(testabc148f f.cc)
target_link_libraries(testabc148f abc148f gtest_main)
gtest_discover_tests(testabc148f)