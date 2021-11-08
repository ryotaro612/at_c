#include "abc226/d.cc"
#include <gtest/gtest.h>

TEST(abc226d, 1) {
    vector<ll> x = {1, 3, 7};
    vector<ll> y = {2, 6, 4};
    EXPECT_EQ(6, solve(3, x, y));
}

TEST(abc226d, 2) {
    vector<ll> x = {1, 2, 4};
    vector<ll> y = {2, 2, 2};
    EXPECT_EQ(2, solve(3, x, y));
}

TEST(abc226d, 3) {
    vector<ll> x = {0, 0, 1000000000ll, 1000000000ll};
    vector<ll> y = {0, 1000000000ll, 0, 1000000000ll};
    EXPECT_EQ(8, solve(4, x, y));
}

