include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

add_executable(testabld d.cc)
target_link_libraries(testabld abld gtest_main)
gtest_discover_tests(testabld)