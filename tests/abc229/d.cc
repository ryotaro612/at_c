#include "abc229/d.cc"
#include <gtest/gtest.h>

TEST(abc229d, 1) {
    string s = "XX...X.X.X.";
    EXPECT_EQ(5, solve(s, 2));
}

TEST(abc229d, 2) {
    string s = "XXXX";
    EXPECT_EQ(4, solve(s, 200000));
}
