add_executable(testabc190c c.cc)
target_link_libraries(testabc190c abc190c gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testabc190c)