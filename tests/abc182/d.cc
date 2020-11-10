#include "abc182/d.cc"
#include "gtest/gtest.h"

TEST(abc182d, 1) { EXPECT_EQ(5, solve(3, {2, -1, -2})); }

TEST(abc182d, 2) { EXPECT_EQ(2, solve(5, {-2, 1, 3, -1, -1})); }

TEST(abc182d, 3) {
    EXPECT_EQ(0, solve(5, {-1000, -1000, -1000, -1000, -1000}));
}