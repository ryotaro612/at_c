add_executable(testsumitrust2019d d.cc)
add_executable(testsumitrust2019e e.cc)

target_link_libraries(testsumitrust2019d sumitrust2019d gtest_main)
target_link_libraries(testsumitrust2019e sumitrust2019e gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(testsumitrust2019d)
gtest_discover_tests(testsumitrust2019e)