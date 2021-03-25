add_executable(testabc051b b.cc)

target_link_libraries(testabc051b abc051b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc051b)