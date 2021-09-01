#include "abc189/c.cc"
#include "gtest/gtest.h"

TEST(abc189c, 1) { EXPECT_EQ(20, solve(6, {2, 4, 4, 9, 4, 9})); }

TEST(abc189c, 2) { EXPECT_EQ(200, solve(6, {200, 4, 4, 9, 4, 9})); }
