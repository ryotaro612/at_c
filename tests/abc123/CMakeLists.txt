add_executable(TestCake123 test_cake123.cc)
target_link_libraries(TestCake123 Cake123 gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestCake123)
