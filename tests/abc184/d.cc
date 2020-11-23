#include "abc184/d.cc"
#include "gtest/gtest.h"

TEST(abc184d, 1) { EXPECT_DOUBLE_EQ(1.000000000, solve(99, 99, 99)); }

TEST(abc184d, 2) { EXPECT_NEAR(1.331081081, solve(98, 99, 99), 0.001); }

TEST(abc184d, 3) { EXPECT_DOUBLE_EQ(99.000000000, solve(0, 0, 1)); }

TEST(abc184d, 4) { EXPECT_NEAR(91.835008202, solve(31, 41, 59), 0.001); }