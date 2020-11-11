#include "abc084/d.cc"
#include <gtest/gtest.h>
TEST(abc084d, 1) {
    vector<ll> ans = {2};
    EXPECT_EQ(ans, solve(1, {3}, {7}));
}

TEST(abc084d, 2) {
    vector<ll> ans = {1, 0, 0, 1};
    EXPECT_EQ(ans, solve(4, {13, 7, 7, 2017}, {13, 11, 11, 2017}));
}

TEST(abc084d, 3) {
    vector<ll> ans = {4, 4, 1, 1, 1, 2};
    EXPECT_EQ(ans, solve(6, {1, 13, 37, 19, 73, 13}, {53, 91, 55, 51, 91, 49}));
}