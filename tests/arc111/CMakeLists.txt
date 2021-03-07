add_executable(testarc111a a.cc)
target_link_libraries(testarc111a arc111a gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc111a)