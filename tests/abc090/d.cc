#include "abc090/d.cc"
#include <gtest/gtest.h>

TEST(abc090d, 1) {
  EXPECT_EQ(7, solve(5, 2));
}

TEST(abc090d, 2) {
  EXPECT_EQ(100, solve(10, 0));
}

TEST(abc090d, 3) {
  EXPECT_EQ(287927211, solve(31415, 9265));
}