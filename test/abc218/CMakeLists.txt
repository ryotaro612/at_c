include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc218c c.cc)
target_link_libraries(testabc218c abc218c gtest_main)
gtest_discover_tests(testabc218c)