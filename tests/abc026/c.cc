#include "abc026/c.cc"
#include <gtest/gtest.h>

TEST(abc026c, 1) { EXPECT_EQ(3, solve(5, {1, 1, 1, 1})); }

TEST(abc026c, 2) { EXPECT_EQ(7, solve(7, {1, 1, 2, 2, 3, 3})); }

TEST(abc026c, 3) { EXPECT_EQ(11, solve(6, {1, 2, 3, 3, 2})); }

TEST(abc026c, 4) { EXPECT_EQ(1023, solve(10, {1, 2, 3, 4, 5, 6, 7, 8, 9})); }

TEST(abc026c, 5) { EXPECT_EQ(1, solve(1, {})); }

TEST(abc026c, 6) { EXPECT_EQ(3, solve(2, {1})); }
