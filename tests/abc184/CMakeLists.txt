include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabc184d d.cc)
target_link_libraries(testabc184d abc184d gtest_main)
gtest_discover_tests(testabc184d)

add_executable(testabc184f f.cc)
target_link_libraries(testabc184f abc184f gtest_main)
gtest_discover_tests(testabc184f)