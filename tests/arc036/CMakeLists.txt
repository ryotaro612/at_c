add_executable(testarc036b b.cc)

target_link_libraries(testarc036b arc036b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc036b)