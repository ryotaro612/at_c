add_executable(TestReplacing test_replacing.cc)
add_executable(testabc171c c.cc)
target_link_libraries(TestReplacing Replacing gtest_main)
target_link_libraries(testabc171c abc171c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestReplacing)
gtest_discover_tests(testabc171c)
