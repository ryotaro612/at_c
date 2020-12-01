#include "abc072/d.cc"
#include <gtest/gtest.h>

TEST(abc072d, 1) { EXPECT_EQ(2, solve(5, {1, 4, 3, 5, 2})); }

TEST(abc072d, 2) { EXPECT_EQ(1, solve(2, {1, 2})); }

TEST(abc072d, 3) { EXPECT_EQ(0, solve(2, {2, 1})); }

TEST(abc072d, 4) { EXPECT_EQ(3, solve(9, {1, 2, 4, 9, 5, 8, 7, 3, 6})); }
