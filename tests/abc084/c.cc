#include "abc084/c.cc"
#include <gtest/gtest.h>

TEST(abc084c, 1) {
    vector<int> ans = {12, 11, 0};
    EXPECT_EQ(ans, solve(3, {6, 1}, {5, 10}, {1, 1}));
}

TEST(abc084c, 2) {
    vector<int> ans = {187, 167, 101, 0};
    EXPECT_EQ(ans, solve(4, {12, 52, 99}, {24, 16, 2}, {6, 4, 2}));
}

TEST(abc084c, 3) {
    vector<int> ans = {4162, 4162, 4162, 0};
    EXPECT_EQ(ans, solve(4, {12, 44, 66}, {13, 17, 4096}, {1, 17, 64}));
}
