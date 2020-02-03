add_executable(TestPartition test_partition.cc)
target_link_libraries(TestPartition Partition gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestPartition)
