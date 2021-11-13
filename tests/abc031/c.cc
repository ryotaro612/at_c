#include "abc031/c.cc"
#include <gtest/gtest.h>

TEST(abc031c, 1) { EXPECT_EQ(6, solve(6, {1, -3, 3, 9, 1, 6})); }

TEST(abc031c, 2) { EXPECT_EQ(10, solve(3, {5, 5, 5})); }

TEST(abc031c, 3) { EXPECT_EQ(-1, solve(8, {-1, 10, -1, 2, -1, 10, -1, 0})); }