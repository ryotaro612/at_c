#include "abc146/f.cc"
#include <gtest/gtest.h>

TEST(abc146f, 1) {
    vector<int> ans = {1, 3, 2, 3};
    string s = "0001000100";
    EXPECT_EQ(ans, solve(9, 3, s));
}

TEST(abc146f, 2) {
    vector<int> ans = {-1};
    string s = "011110";
    EXPECT_EQ(ans, solve(5, 4, s));
}

TEST(abc146f, 3) {
    vector<int> ans = {6};
    string s = "0101010";
    EXPECT_EQ(ans, solve(6, 6, s));
}