#include "abc228/d.cc"
#include <gtest/gtest.h>

TEST(abc228d, 1) {
    vector<int> t = {1, 1, 2, 2};
    vector<ll> x = {1048577ll, 1ll, 2097153ll, 3ll};
    vector<ll> ans = {1048577ll, -1ll};
    EXPECT_EQ(ans, solve(4, t, x));
}

TEST(abc228d, 2) {
    vector<int> t = {1, 1, 1, 2};
    vector<ll> x = {1, 1ll, 1, 5ll};
    vector<ll> ans = {-1ll};
    EXPECT_EQ(ans, solve(4, t, x));
}

TEST(abc228d, 3) {
    vector<int> t = {1, 1, 1, 1, 1, 2};
    vector<ll> x = {4, 1, 1, 1, 1, 4};
    vector<ll> ans = {4ll};
    EXPECT_EQ(ans, solve(t.size(), t, x));
}