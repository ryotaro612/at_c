#include "arc114/a.cc"
#include "gtest/gtest.h"

TEST(arc114a, 1) { EXPECT_EQ(6, solve(2, {4, 3})); }

TEST(arc114a, 2) { EXPECT_EQ(47, solve(1, {47})); }

TEST(arc114a, 3) { EXPECT_EQ(42, solve(7, {3, 4, 6, 7, 8, 9, 10})); }