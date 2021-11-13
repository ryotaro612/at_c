add_executable(testpanasonic2020d d.cc)

target_link_libraries(testpanasonic2020d panasonic2020d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testpanasonic2020d)