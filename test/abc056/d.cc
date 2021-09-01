#include "abc056/d.cc"
#include <gtest/gtest.h>

TEST(abc056d, 1) { EXPECT_EQ(1, solve(3, 6, {1, 4, 3})); }

TEST(abc056d, 2) { EXPECT_EQ(5, solve(5, 400, {3, 1, 4, 1, 5})); }

TEST(abc056d, 3) { EXPECT_EQ(3, solve(6, 20, {10, 4, 3, 10, 25, 2})); }
