#include "abc188/c.cc"
#include "gtest/gtest.h"

TEST(abc188c, 1) { EXPECT_EQ(2ll, solve(2, {1, 4, 2, 5})); }

TEST(abc188c, 2) { EXPECT_EQ(1ll, solve(2, {3, 1, 5, 4})); }

TEST(abc188c, 3) {
    EXPECT_EQ(
        2ll, solve(4, {6, 13, 12, 5, 3, 7, 10, 11, 16, 9, 8, 15, 2, 1, 14, 4}));
}
