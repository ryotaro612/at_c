add_executable(testarc125a a.cc)
target_link_libraries(testarc125a arc125a gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testarc125a)