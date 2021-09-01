add_executable(testabc184d d.cc)
target_link_libraries(testabc184d abc184d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc184d)