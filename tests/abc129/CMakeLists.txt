include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(TestLamp test_lamp.cc)
target_link_libraries(TestLamp Lamp gtest_main)
gtest_discover_tests(TestLamp)

add_executable(testabc129e e.cc)
target_link_libraries(testabc129e abc129e gtest_main)
gtest_discover_tests(testabc129e)