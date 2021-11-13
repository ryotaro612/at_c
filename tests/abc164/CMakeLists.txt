add_executable(TestMultipleOf2019 test_multiple_of_2019.cc)
target_link_libraries(TestMultipleOf2019 MultipleOf2019 gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestMultipleOf2019)
