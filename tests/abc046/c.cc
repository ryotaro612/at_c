#include "abc046/c.cc"
#include <gtest/gtest.h>

TEST(abc046c, 1) { EXPECT_EQ(10, solve(3, {2, 1, 3}, {3, 1, 2})); }

TEST(abc046c, 2) { EXPECT_EQ(101, solve(4, {1, 1, 1, 1}, {1, 1, 5, 100})); }

TEST(abc046c, 3) {
    EXPECT_EQ(6930, solve(5, {3, 48, 31, 231, 3}, {10, 17, 199, 23, 2}));
}
