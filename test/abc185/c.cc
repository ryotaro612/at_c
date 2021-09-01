#include "abc185/c.cc"
#include "gtest/gtest.h"

TEST(abc185c, 1) { EXPECT_EQ(1, solve(12)); }

TEST(abc185c, 2) { EXPECT_EQ(12, solve(13)); }

TEST(abc185c, 3) { EXPECT_EQ(4368, solve(17)); }
