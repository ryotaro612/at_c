add_executable(testabc188d d.cc)
add_executable(testabc188c c.cc)

target_link_libraries(testabc188c abc188c gtest_main)
target_link_libraries(testabc188d abc188d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc188c)
gtest_discover_tests(testabc188d)