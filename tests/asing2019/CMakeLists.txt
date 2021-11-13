include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testaising2019c c.cc)
target_link_libraries(testaising2019c aising2019c gtest_main)
gtest_discover_tests(testaising2019c)