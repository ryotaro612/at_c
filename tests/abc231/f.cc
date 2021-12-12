#include "abc231/f.cc"
#include <gtest/gtest.h>

TEST(abc231e, 1) {
    vector<ll> a = {50, 100, 150};
    vector<ll> b = {1, 3, 2};
    EXPECT_EQ(4, solve(3, a, b));
}

TEST(abc231e, 2) {
    vector<ll> a = {123456789, 123456, 123};
    vector<ll> b = {987, 987654, 987654321};
    EXPECT_EQ(6, solve(3, a, b));
}

TEST(abc231e, 3) {
    vector<ll> a = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    vector<ll> b = {2, 7, 1, 8, 2, 8, 1, 8, 2, 8};
    EXPECT_EQ(37, solve(10, a, b));
}