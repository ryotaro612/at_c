#include "abc006/c.cc"
#include <gtest/gtest.h>

TEST(abc006c, 1) {
    vector<int> res = solve(3, 9);
    EXPECT_EQ(9, res[0] * 2 + res[1] * 3 + res[2]*4);
}

TEST(abc006c, 2) {
    vector<int> res = solve(7, 23);
    EXPECT_EQ(23, res[0] * 2 + res[1] * 3 + res[2]*4);
}

TEST(abc006c, 3) {
    vector<int> res = solve(10, 41);
    EXPECT_EQ(-1, res[0]);
    EXPECT_EQ(-1, res[1]);
    EXPECT_EQ(-1, res[2]);
}