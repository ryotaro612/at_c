#include "abc062/d.cc"
#include <gtest/gtest.h>

TEST(abc062d, 1) { EXPECT_EQ(1, solve(2, {3, 1, 4, 1, 5, 9})); }

TEST(abc062d, 2) { EXPECT_EQ(-1, solve(1, {1, 2, 3})); }

TEST(abc062d, 3) { EXPECT_EQ(5, solve(3, {8, 2, 2, 7, 4, 6, 5, 3, 8})); }