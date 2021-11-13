#include "abc194/c.cc"
#include "gtest/gtest.h"

TEST(abc194c, 1) { EXPECT_EQ(56ll, solve(3ll, {2, 8, 4})); }

TEST(abc194c, 2) { EXPECT_EQ(950ll, solve(5ll, {-5, 8, 9, -4, -3})); }