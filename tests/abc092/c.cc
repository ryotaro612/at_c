#include "abc092/c.cc"
#include <gtest/gtest.h>

TEST(abc092c, 1) {
    EXPECT_EQ(2, solve(3, {2, 3, 1}, {0, 1, 3}, {4, 0, 5}, {2, 4, 5}));
}

TEST(abc092c, 2) {
    EXPECT_EQ(2, solve(3, {0, 1, 5}, {0, 1, 2}, {2, 3, 4}, {3, 4, 5}));
}

TEST(abc092c, 3) { EXPECT_EQ(0, solve(2, {2, 3}, {2, 3}, {0, 1}, {0, 1})); }

TEST(abc092c, 4) {
    EXPECT_EQ(5, solve(5, {0, 7, 2, 4, 1}, {0, 3, 2, 8, 6}, {8, 6, 5, 9, 3},
                       {5, 9, 4, 1, 7}));
}

TEST(abc092c, 5) {
    EXPECT_EQ(4, solve(5, {0, 1, 5, 6, 7}, {0, 1, 5, 6, 7}, {2, 3, 4, 8, 9},
                       {2, 3, 4, 8, 9}));
}
