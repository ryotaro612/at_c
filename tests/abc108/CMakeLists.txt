# https://atcoder.jp/contests/abc108
add_executable(TestTriangularRelationship test_triangular_relationship.cc)
add_executable(TestAbc108d d.cc)
target_link_libraries(TestTriangularRelationship TriangularRelationship gtest_main)
target_link_libraries(TestAbc108d Abc108d gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestTriangularRelationship)
gtest_discover_tests(TestAbc108d)
