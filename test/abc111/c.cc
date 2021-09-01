#include "abc111/c.cc"
#include "gtest/gtest.h"

TEST(abc111c, 1) { EXPECT_EQ(1, solve(4, {3, 1, 3, 2})); }

TEST(abc111c, 2) { EXPECT_EQ(0, solve(6, {105, 119, 105, 119, 105, 119})); }

TEST(abc111c, 3) { EXPECT_EQ(2, solve(4, {1, 1, 1, 1})); }

TEST(abc111c, 4) { EXPECT_EQ(0, solve(4, {1, 2, 1, 2})); }

TEST(abc111c, 5) { EXPECT_EQ(3, solve(6, {1, 1, 1, 1, 3, 3})); }
