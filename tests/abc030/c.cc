#include "abc030/c.cc"
#include <gtest/gtest.h>

TEST(abc030c, 1) { EXPECT_EQ(2, solve(3, 4, 2, 3, {1, 5, 7}, {3, 8, 12, 13})); }

TEST(abc030c, 2) { EXPECT_EQ(0, solve(1, 1, 1, 1, {1}, {1})); }

TEST(abc030c, 3) {
    EXPECT_EQ(3, solve(6, 7, 5, 3, {1, 7, 12, 19, 20, 26},
                       {4, 9, 15, 23, 24, 31, 33}));
}
