#include "arc114/b.cc"
#include "gtest/gtest.h"

TEST(arc114b, 1) { EXPECT_EQ(1, solve(2, {2, 1})); }

TEST(arc114b, 2) { EXPECT_EQ(1, solve(2, {1, 1})); }

TEST(arc114b, 3) { EXPECT_EQ(7, solve(3, {1, 2, 3})); }