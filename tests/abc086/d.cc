#include "abc086/d.cc"
#include <gtest/gtest.h>

TEST(abc086d, 1) {
    ll n = 4, k = 3;
    vector<ll> x = {0, 1, 5, 5};
    vector<ll> y = {1, 2, 3, 4};
    vector<char> c = {'W', 'W', 'B', 'B'};
    EXPECT_EQ(4, solve(n, k, x, y, c));
}

TEST(abc086d, 2) {
    ll n = 2, k = 1000;
    vector<ll> x = {0, 0};
    vector<ll> y = {0, 1};
    vector<char> c = {'B', 'W'};
    EXPECT_EQ(2, solve(n, k, x, y, c));
}

TEST(abc086d, 3) {
    ll n = 6, k = 2;
    vector<ll> x = {1, 2, 2, 1, 0, 4};
    vector<ll> y = {2, 1, 2, 0, 6, 5};
    vector<char> c = {'B', 'W', 'B', 'B', 'W', 'W'};
    EXPECT_EQ(4, solve(n, k, x, y, c));
}
