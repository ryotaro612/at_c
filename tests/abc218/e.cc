#include "abc218/e.cc"
#include <gtest/gtest.h>

TEST(abc218e, 1) {
    vector<int> a = {1, 1, 1, 3, 4}, b = {2, 3, 4, 2, 2};
    vector<ll> c = {1ll, 1ll, 1ll, 2ll, 2ll};
    EXPECT_EQ(4, solve(4, 5, a, b, c));
}

TEST(abc218e, 2) {
    vector<int> a = {1, 2, 3}, b = {2, 3, 1};
    vector<ll> c = {1ll, 0ll, -1ll};
    EXPECT_EQ(1, solve(3, 3, a, b, c));
}

TEST(abc218e, 3) {
    vector<int> a = {1, 1, 1}, b = {2, 2, 1};
    vector<ll> c = {-1ll, 2ll, 3ll};
    EXPECT_EQ(5, solve(2, 3, a, b, c));
}