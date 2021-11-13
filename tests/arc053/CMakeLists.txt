add_executable(testarc053b b.cc)

target_link_libraries(testarc053b arc053b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc053b)