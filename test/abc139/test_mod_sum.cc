#include "gtest/gtest.h"
#include "abc139/mod_sum.h"

TEST(TestModSum, First) {
  EXPECT_EQ(1, mod_sum(2));
}

TEST(TestModSum, Second) {
  EXPECT_EQ(78, mod_sum(13));
}

TEST(TestModSum, Third) {
  EXPECT_EQ(0, mod_sum(1));
}
