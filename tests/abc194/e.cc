#include "abc194/e.cc"
#include "gtest/gtest.h"

TEST(abc194e, 1) { EXPECT_EQ(1, solve(3, 2, {0, 0, 1})); }

TEST(abc194e, 2) { EXPECT_EQ(0, solve(3, 2, {1, 1, 1})); }

TEST(abc194e, 3) { EXPECT_EQ(2, solve(3, 2, {0, 1, 0})); }

TEST(abc194e, 4) { EXPECT_EQ(2, solve(7, 3, {0, 0, 1, 2, 0, 1, 0})); }

TEST(abc194e, 5) { EXPECT_EQ(3, solve(3, 3, {0, 1, 2})); }
