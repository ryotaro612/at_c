#include "abc038/c.cc"
#include <gtest/gtest.h>

TEST(abc038c, 1) { EXPECT_EQ(8, solve(5, {1, 2, 3, 2, 1})); }

TEST(abc038c, 2) { EXPECT_EQ(10, solve(4, {1, 2, 3, 4})); }

TEST(abc038c, 3) { EXPECT_EQ(8, solve(6, {3, 3, 4, 1, 2, 2})); }

TEST(abc038c, 4) { EXPECT_EQ(10, solve(6, {1, 5, 2, 3, 4, 2})); }
