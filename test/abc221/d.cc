#include "abc221/d.cc"
#include <gtest/gtest.h>

TEST(abc221d, 1) {
    vector<ll> a = {1, 2, 3}, b = {2, 3, 1};
    vector<ll> ans = {2, 2, 0};
    EXPECT_EQ(ans, solve(3, a, b));
}

TEST(abc221d, 2) {
    vector<ll> a = {1000000000, 1000000000}, b = {1000000000, 1000000000};
    vector<ll> ans = {0, 1000000000};
    EXPECT_EQ(ans, solve(2, a, b));
}
