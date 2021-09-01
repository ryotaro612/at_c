#include "abc048/c.cc"
#include <gtest/gtest.h>

TEST(abc048c, 1) { EXPECT_EQ(1, solve(3, 3, {2, 2, 2})); }

TEST(abc048c, 2) { EXPECT_EQ(11, solve(6, 1, {1, 6, 1, 2, 0, 4})); }

TEST(abc048c, 3) { EXPECT_EQ(0, solve(5, 9, {3, 1, 4, 1, 5})); }

TEST(abc048c, 4) { EXPECT_EQ(10, solve(2, 0, {5, 5})); }