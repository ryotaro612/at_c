#include "abc222/d.cc"
#include <gtest/gtest.h>

TEST(abc222d, 1) {
    vector<ll> a = {1, 1};
    vector<ll> b = {2, 3};
    EXPECT_EQ(5ll, solve(2, a, b));
}

TEST(abc222d, 2) {
    vector<ll> a = {2, 2, 2};
    vector<ll> b = {2, 2, 2};
    EXPECT_EQ(1ll, solve(3, a, b));
}

TEST(abc222d, 3) {
    vector<ll> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<ll> b = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
    EXPECT_EQ(978222082ll, solve(10, a, b));
}
