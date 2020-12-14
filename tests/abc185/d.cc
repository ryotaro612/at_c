#include "abc185/d.cc"
#include "gtest/gtest.h"

TEST(abc185d, 1) { EXPECT_EQ(3, solve(5, 2, {1, 3})); }

TEST(abc185d, 2) { EXPECT_EQ(6, solve(13, 3, {13, 3, 9})); }

TEST(abc185d, 3) { EXPECT_EQ(0, solve(5, 5, {5, 2, 1, 4, 3})); }

TEST(abc185d, 4) { EXPECT_EQ(1, solve(1, 0, {})); }
