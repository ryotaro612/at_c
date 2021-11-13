#include "arc123/b.cc"
#include <gtest/gtest.h>

TEST(arc123, 1) {
    vector<ll> a = {9, 6, 14, 1, 8};
    vector<ll> b = {2, 10, 3, 12, 11};
    vector<ll> c = {15, 13, 5, 7, 4};

    EXPECT_EQ(3, solve(5, a, b, c));
}

TEST(arc123, 2) {
    vector<ll> a = {10};
    vector<ll> b = {20};
    vector<ll> c = {30};

    EXPECT_EQ(1, solve(1, a, b, c));
}

TEST(arc123, 3) {
    vector<ll> a = {1, 1, 1};
    vector<ll> b = {1, 1, 2};
    vector<ll> c = {2, 2, 2};

    EXPECT_EQ(0, solve(1, a, b, c));
}