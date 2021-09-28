#include "abc220/f.cc"
#include <gtest/gtest.h>

TEST(abc220f, 1) {
    vector<ll> u = {1, 2}, v = {2, 3};
    vector<ll> ans = {3, 2, 3};
    EXPECT_EQ(ans, solve(3, u, v));
}

TEST(abc220f, 2) {
    vector<ll> u = {1}, v = {2};
    vector<ll> ans = {1, 1};
    EXPECT_EQ(ans, solve(2, u, v));
}

TEST(abc220f, 3) {
    vector<ll> u = {1, 1, 1, 1, 1}, v = {6, 5, 3, 4, 2};
    vector<ll> ans = {5, 9, 9, 9, 9, 9};
    EXPECT_EQ(ans, solve(6, u, v));
}