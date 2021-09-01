#include "abc160/e.cc"
#include "gtest/gtest.h"

TEST(abc160e, 1) { EXPECT_EQ(12, solve(1, 2, 2, 2, 1, {2, 4}, {5, 1}, {3})); }

TEST(abc160e, 2) {
    EXPECT_EQ(25, solve(2, 2, 2, 2, 2, {8, 6}, {9, 1}, {2, 1}));
}

TEST(abc160e, 3) {
    EXPECT_EQ(74, solve(2, 2, 4, 4, 4, {11, 12, 13, 14}, {21, 22, 23, 24},
                        {1, 2, 3, 4}));
}
