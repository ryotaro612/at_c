include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc223e e.cc)
target_link_libraries(testabc223e abc223e gtest_main)
gtest_discover_tests(testabc223e)