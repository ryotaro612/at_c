add_executable(testarc116a a.cc)
add_executable(testarc116b b.cc)

target_link_libraries(testarc116a arc116a gtest_main)
target_link_libraries(testarc116b arc116b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc116a)
gtest_discover_tests(testarc116b)