#include "abc186/d.cc"
#include "gtest/gtest.h"

TEST(abc186d, 1) { EXPECT_EQ(8, solve(3, {5, 1, 2})); }

TEST(abc186d, 2) { EXPECT_EQ(176, solve(5, {31, 41, 59, 26, 53})); }