add_executable(testarc043a a.cc)

target_link_libraries(testarc043a arc043a gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc043a)