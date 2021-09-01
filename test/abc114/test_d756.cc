#include "gtest/gtest.h"
#include "abc114/d756.h"

using namespace std;

TEST(TestD756, First) {
  EXPECT_EQ(0, d756(9));
}

TEST(TestD756, Second) {
  EXPECT_EQ(1, d756(10));
}

TEST(TestD756, Third) {
  EXPECT_EQ(543, d756(100));
}
