add_executable(testarc105a a.cc)
add_executable(testarc105b b.cc)

target_link_libraries(testarc105a arc105a gtest_main)
target_link_libraries(testarc105b arc105b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc105a)
gtest_discover_tests(testarc105b)