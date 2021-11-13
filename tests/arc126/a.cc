#include "arc126/a.cc"
#include <gtest/gtest.h>

TEST(arc126a, 1) {
    vector<ll> a = {3, 7, 0, 0, 1000000000000000ll},
               b = {4, 0, 0, 0, 1000000000000000ll},
               c = {1, 0, 7, 0, 1000000000000000ll};
    vector<ll> ans = {2, 1, 0, 0, 900000000000000ll};
    EXPECT_EQ(ans, solve(5, a, b, c));
}

TEST(arc126a, 2) {
    vector<ll> a = {10ll}, b = {10ll}, c = {10ll};
    vector<ll> ans = {9ll};
    EXPECT_EQ(ans, solve(1, a, b, c));
}