#include "abc150/b.cc"
#include "gtest/gtest.h"

TEST(abc150b, 1) { EXPECT_EQ(3, solve(3, {1, 3, 2}, {3, 1, 2})); }

TEST(abc150b, 2) {
    EXPECT_EQ(17517,
              solve(8, {7, 3, 5, 4, 2, 1, 6, 8}, {3, 8, 2, 5, 4, 6, 7, 1}));
}

TEST(abc150b, 3) { EXPECT_EQ(0, solve(3, {1, 2, 3}, {1, 2, 3})); }