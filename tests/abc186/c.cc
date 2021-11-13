#include "abc186/c.cc"
#include "gtest/gtest.h"

TEST(abc186c, 1) { EXPECT_EQ(17, solve(20)); }

TEST(abc186c, 2) { EXPECT_EQ(30555, solve(100000)); }
