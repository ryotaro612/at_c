#include "abc182/e.cc"
#include "gtest/gtest.h"

TEST(abc182e, 1) { EXPECT_EQ(7, solve(3, 3, 2, 1, {1, 2}, {1, 3}, {2}, {2})); }

TEST(abc182e, 2) {
    EXPECT_EQ(8, solve(4, 4, 3, 3, {1, 1, 3}, {2, 3, 4}, {2, 2, 3}, {3, 4, 2}));
}

TEST(abc182e, 3) {
    EXPECT_EQ(24,
              solve(5, 5, 5, 1, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {4}, {2}));
}
