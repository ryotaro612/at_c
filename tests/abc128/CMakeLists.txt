add_executable(TestEnqueue test_enqueue.cc)
target_link_libraries(TestEnqueue Enqueue gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestEnqueue)
