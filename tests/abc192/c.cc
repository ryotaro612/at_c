#include "abc192/c.cc"
#include "gtest/gtest.h"

TEST(abc192c, 1) { EXPECT_EQ(693, solve(314, 2)); }

TEST(abc192c, 2) { EXPECT_EQ(0, solve(1000000000, 100)); }

TEST(abc192c, 3) { EXPECT_EQ(6174, solve(6174, 100000)); }