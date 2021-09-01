#include "abc157/c.cc"
#include "gtest/gtest.h"

TEST(abc157c, 1) { EXPECT_EQ(702, solve(3, 3, {1, 3, 1}, {'7', '2', '7'})); }

TEST(abc157c, 2) { EXPECT_EQ(-1, solve(3, 2, {2, 2}, {'1', '3'})); }

TEST(abc157c, 3) { EXPECT_EQ(-1, solve(3, 1, {1}, {'0'})); }