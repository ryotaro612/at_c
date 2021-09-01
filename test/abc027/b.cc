#include "abc027/b.cc"
#include <gtest/gtest.h>

TEST(abc027b, 1) { EXPECT_EQ(2, solve(3, {1, 2, 3})); }

TEST(abc027b, 2) { EXPECT_EQ(3, solve(5, {2, 0, 0, 0, 3})); }

TEST(abc027b, 3) { EXPECT_EQ(-1, solve(2, {0, 99})); }

TEST(abc027b, 4) { EXPECT_EQ(0, solve(4, {0, 0, 0, 0})); }