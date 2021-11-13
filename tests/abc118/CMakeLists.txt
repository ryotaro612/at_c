add_executable(TestMatchMatching test_match_matching.cc)
target_link_libraries(TestMatchMatching MatchMatching gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestMatchMatching)
