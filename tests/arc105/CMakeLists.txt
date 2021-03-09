add_executable(testarc105a a.cc)
target_link_libraries(testarc105a arc105a gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc105a)