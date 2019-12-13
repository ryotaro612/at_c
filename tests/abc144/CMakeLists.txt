add_executable(TestWaterBottle test_water_bottle.cc)
target_link_libraries(TestWaterBottle WaterBottle gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestWaterBottle)
