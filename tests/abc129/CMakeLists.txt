add_executable(TestLamp test_lamp.cc)
target_link_libraries(TestLamp Lamp gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestLamp)
