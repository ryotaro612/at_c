#include "abc218/d.cc"
#include <gtest/gtest.h>

TEST(abc218d, 1) {
    vector<ll> x = {0, 0, 1, 1, 2, 2}, y = {0, 1, 0, 1, 0, 1};
    EXPECT_EQ(3ll, solve(6, x, y));
}

TEST(abc218d, 2) {
    vector<ll> x = {0, 1, 2, 3}, y = {1, 2, 3, 4};
    EXPECT_EQ(0ll, solve(4, x, y));
}

TEST(abc218d, 3) {
    vector<ll> x = {0, 1, 2, 2, 2, 3, 3}, y = {1, 0, 0, 1, 2, 0, 2};
    EXPECT_EQ(1ll, solve(7, x, y));
}
