#include "abc042/c.cc"
#include <gtest/gtest.h>

TEST(abc042c, 1) { EXPECT_EQ(2000, solve(1000, 8, {1, 3, 4, 5, 6, 7, 8, 9})); }

TEST(abc042c, 2) { EXPECT_EQ(9999, solve(9999, 1, {0})); }
