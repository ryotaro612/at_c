#include "hhkb2020/e.cc"
#include <gtest/gtest.h>

TEST(hhkb2020e, 1) {
    vector<string> s = {"..#.."};
    EXPECT_EQ(48ll, solve(1, 5, s));
}

TEST(hhkb2020e, 2) {
    vector<string> s = {"..#", "#.."};
    EXPECT_EQ(52ll, solve(2, 3, s));
}