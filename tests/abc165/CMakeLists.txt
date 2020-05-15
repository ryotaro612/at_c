add_executable(TestFloorFunction test_floor_function.cc)
target_link_libraries(TestFloorFunction FloorFunction gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestFloorFunction)
