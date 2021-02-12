add_executable(testabc002d d.cc)
target_link_libraries(testabc002d abc002d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc002d)