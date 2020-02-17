add_executable(TestPairs test_pairs.cc)
target_link_libraries(TestPairs Pairs gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestPairs)
