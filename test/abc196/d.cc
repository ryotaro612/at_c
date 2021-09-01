#include "abc196/d.cc"
#include "gtest/gtest.h"

TEST(abc196d, 1) { EXPECT_EQ(4, solve(2, 2, 1, 2)); }

TEST(abc196d, 2) { EXPECT_EQ(18, solve(3, 3, 4, 1)); }

TEST(abc196d, 3) { EXPECT_EQ(36, solve(4, 4, 8, 0)); }
