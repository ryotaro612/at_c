add_executable(TestRGBTriplets test_rgb_triplets.cc)
target_link_libraries(TestRGBTriplets RGBTriplets gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestRGBTriplets)
