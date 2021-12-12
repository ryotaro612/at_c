#include "abc231/e.cc"
#include <gtest/gtest.h>

TEST(abc231e, 1) {
    ll x = 87ll;
    vector<ll> a = {1, 10, 100};
    EXPECT_EQ(5, solve(3, x, a));
}

TEST(abc231e, 2) {
    vector<ll> a = {1, 7};
    EXPECT_EQ(7, solve(2, 49, a));
}

TEST(abc231e, 3) {
    vector<ll> a = {1,
                    100,
                    10000,
                    1000000,
                    100000000,
                    10000000000,
                    1000000000000,
                    100000000000000,
                    10000000000000000,
                    1000000000000000000};
    EXPECT_EQ(233, solve(10, 123456789012345678ll, a));
}