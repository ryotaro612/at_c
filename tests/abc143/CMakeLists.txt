add_executable(TestTriangles test_triangles.cc)
target_link_libraries(TestTriangles Triangles gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestTriangles)
