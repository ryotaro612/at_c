add_executable(testabc181d d.cc)
target_link_libraries(testabc181d abc181d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc181d)