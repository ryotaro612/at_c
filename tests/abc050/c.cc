#include "abc050/c.cc"
#include <gtest/gtest.h>

TEST(abc050c, 1) { EXPECT_EQ(4, solve(5, {2, 4, 4, 0, 2})); }

TEST(abc050c, 2) { EXPECT_EQ(0, solve(7, {6, 4, 0, 2, 4, 0, 2})); }

TEST(abc050c, 3) { EXPECT_EQ(16, solve(8, {7, 5, 1, 1, 7, 3, 5, 3})); }
