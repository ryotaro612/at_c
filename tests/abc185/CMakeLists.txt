add_executable(testabc185d d.cc)
target_link_libraries(testabc185d abc185d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc185d)