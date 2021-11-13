add_executable(TestKnight test_knight.cc)
target_link_libraries(TestKnight Knight gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestKnight)
