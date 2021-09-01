#include "abc017/c.cc"
#include <gtest/gtest.h>

TEST(abc017c, 1) {
    EXPECT_EQ(80, solve(4, 6, {1, 2, 3, 6}, {3, 3, 6, 6}, {30, 40, 25, 10}));
}

TEST(abc017c, 2) { EXPECT_EQ(180, solve(2, 7, {1, 5}, {3, 7}, {90, 90})); }

TEST(abc017c, 3) { EXPECT_EQ(0, solve(1, 4, {1}, {4}, {70})); }