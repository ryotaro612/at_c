add_executable(TestReplacing test_replacing.cc)
target_link_libraries(TestReplacing Replacing gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestReplacing)
