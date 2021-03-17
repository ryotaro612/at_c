add_executable(testarc110b b.cc)
target_link_libraries(testarc110b arc110b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc110b)