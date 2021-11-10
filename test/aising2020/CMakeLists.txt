include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testaising2020d d.cc)
target_link_libraries(testaising2020d aising2020d gtest_main)
gtest_discover_tests(testaising2020d)