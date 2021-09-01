add_executable(testarc031b b.cc)

target_link_libraries(testarc031b arc031b gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc031b)