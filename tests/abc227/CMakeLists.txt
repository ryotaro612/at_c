include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc227d d.cc)
target_link_libraries(testabc227d abc227d gtest_main)
gtest_discover_tests(testabc227d)

