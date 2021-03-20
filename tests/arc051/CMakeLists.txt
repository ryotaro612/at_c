add_executable(testarc051b b.cc)

target_link_libraries(testarc051b arc051b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc051b)