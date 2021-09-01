add_executable(testabc113c c.cc)
add_executable(TestNumberOfAmidakuji test_number_of_amidakuji.cc)

target_link_libraries(testabc113c abc113c gtest_main)
target_link_libraries(TestNumberOfAmidakuji NumberOfAmidakuji gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc113c)
gtest_discover_tests(TestNumberOfAmidakuji)
