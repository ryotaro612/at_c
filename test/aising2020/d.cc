#include "aising2020/d.cc"
#include <gtest/gtest.h>

TEST(aising2020d, 1) {
    vector<ll> ans = {2, 1, 1};
    string s = "011";
    EXPECT_EQ(ans, solve(3, s));
}

TEST(aising2020d, 2) {
    vector<ll> ans = {2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2,
                      2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 3};
    string s = "00110111001011011001110";
    EXPECT_EQ(ans, solve(23, s));
}
