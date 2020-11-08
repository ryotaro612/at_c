#include "abc085/d.cc"
#include <gtest/gtest.h>

TEST(abc085d, 1) {
    ll n = 1, h = 10;
    vector<ll> a = {3};
    vector<ll> b = {5};
    EXPECT_EQ(3, solve(n, h, a, b));
}

TEST(abc085d, 2) {
    ll n = 2, h = 10;
    vector<ll> a = {3, 2};
    vector<ll> b = {5, 6};
    EXPECT_EQ(2, solve(n, h, a, b));
}

TEST(abc085d, 3) {
    ll n = 4, h = 1000000000;
    vector<ll> a = {1, 1, 1, 1};
    vector<ll> b = {1, 10000000, 30000000, 99999999};
    EXPECT_EQ(860000004, solve(n, h, a, b));
}

TEST(abc085d, 4) {
    ll n = 5, h = 500;
    vector<ll> a = {35, 28, 46, 31, 40};
    vector<ll> b = {44, 83, 62, 79, 43};
    EXPECT_EQ(9, solve(n, h, a, b));
}