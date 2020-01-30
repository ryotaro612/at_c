add_executable(TestD756 test_d756.cc)
target_link_libraries(TestD756 D756 gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestD756)
