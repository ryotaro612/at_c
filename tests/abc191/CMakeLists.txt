add_executable(testabc191d d.cc)
target_link_libraries(testabc191d abc191d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc191d)