# https://atcoder.jp/contests/abc108
add_executable(TestTriangularRelationship test_triangular_relationship.cc)
target_link_libraries(TestTriangularRelationship TriangularRelationship gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestTriangularRelationship)
