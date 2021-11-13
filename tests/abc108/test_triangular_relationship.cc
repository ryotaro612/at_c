#include <gtest/gtest.h>
#include "abc108/triangular_relationship.h"
using namespace std;

TEST(TestTriangularRelationship, First) {
  EXPECT_EQ(9, triangular_relationship(3, 2));
}

TEST(TestTriangularRelationship, Second) {
  EXPECT_EQ(1, triangular_relationship(5, 3));
}

TEST(TestTriangularRelationship, Third) {
  EXPECT_EQ(27, triangular_relationship(31415, 9265));
}

TEST(TestTriangularRelationship, Fourth) {
  EXPECT_EQ(114191, triangular_relationship(35897, 932));
}
