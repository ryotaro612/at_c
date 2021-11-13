#include "abc190/f.cc"
#include <gtest/gtest.h>

TEST(abc190f, 1) {
    vector<int> a = {0, 1, 2, 3};
    vector<ll> ans = {0, 3, 4, 3};
    EXPECT_EQ(ans, solve(a.size(), a));
}

TEST(abc190f, 2) {
    vector<int> a = {0, 3, 1, 5, 4, 2, 9, 6, 8, 7};
    vector<ll> ans = {9, 18, 21, 28, 27, 28, 33, 24, 21, 14};
    EXPECT_EQ(ans, solve(a.size(), a));
}
