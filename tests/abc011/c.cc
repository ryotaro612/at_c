#include "abc011/c.cc"
#include <gtest/gtest.h>

TEST(abc011c, 1) { EXPECT_EQ("YES", solve(2, {1, 7, 15})); }

TEST(abc011c, 2) { EXPECT_EQ("YES", solve(5, {1, 4, 2})); }

TEST(abc011c, 3) { EXPECT_EQ("NO", solve(300, {57, 121, 244})); }
