add_executable(testjsc2021d d.cc)

target_link_libraries(testjsc2021d jsc2021d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testjsc2021d)