#include "gtest/gtest.h"
#include "abc143/triangles.h"

TEST(TestTriangles, First) {
  int l[] = {3, 4, 2, 1};
  EXPECT_EQ(1, triangles(4, l));
}

TEST(TestTriangles, Second) {
  int l[] = {1, 1000, 1};
  EXPECT_EQ(0, triangles(3, l));
}

TEST(TestTriangles, Third) {
  int l[] = {218, 786, 704, 233, 645, 728, 389};
  EXPECT_EQ(23, triangles(7, l));
}
