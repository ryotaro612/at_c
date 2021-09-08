#include "arc123/a.cc"
#include <gtest/gtest.h>

TEST(arc123a, 1) {
    vector<ll> a = {4, 8, 10};
    EXPECT_EQ(2, solve(a));
}

TEST(arc123a, 2) {
    vector<ll> a = {10, 3, 4};
    EXPECT_EQ(4, solve(a));
}

TEST(arc123a, 3) {
    vector<ll> a = {1, 2, 3};
    EXPECT_EQ(0, solve(a));
}

TEST(arc123a, 4) {
    vector<ll> a = {1000000000000000ll, 1ll, 1000000000000000ll};
    EXPECT_EQ(999999999999999ll, solve(a));
}