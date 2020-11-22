#include "abc078/d.cc"
#include <gtest/gtest.h>

TEST(abc078d, 1) { EXPECT_EQ(900, solve(3, 100, 100, {10, 1000, 100})); }

TEST(abc078d, 2) { EXPECT_EQ(900, solve(3, 100, 1000, {10, 100, 100})); }

TEST(abc078d, 3) { EXPECT_EQ(0, solve(5, 1, 1, {1, 1, 1, 1, 1})); }

TEST(abc078d, 4) { EXPECT_EQ(999999999, solve(1, 1, 1, {1000000000})); }