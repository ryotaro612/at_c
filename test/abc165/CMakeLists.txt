add_executable(TestFloorFunction test_floor_function.cc)
add_executable(testabc165c c.cc)
target_link_libraries(TestFloorFunction FloorFunction gtest_main)
target_link_libraries(testabc165c abc165c gtest_main)
include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc165c)
gtest_discover_tests(TestFloorFunction)
