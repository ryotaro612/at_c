#include "abc059/c.cc"
#include <gtest/gtest.h>

TEST(abc059c, 1) { EXPECT_EQ(4, solve(4, {1, -3, 1, 0})); }

TEST(abc059c, 2) { EXPECT_EQ(0, solve(5, {3, -6, 4, -5, 7})); }

TEST(abc059c, 3) { EXPECT_EQ(8, solve(6, {-1, 4, 3, 2, -5, 4})); }
