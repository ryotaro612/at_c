#include "abc219/d.cc"
#include <gtest/gtest.h>

TEST(abc219d, 1) {
    vector<int> a = {2, 3, 2}, b = {1, 4, 3};
    int res = solve(3, 5, 6, a, b);
    EXPECT_EQ(2, res);
}

TEST(abc219d, 2) {
    vector<int> a = {3, 2, 2}, b = {4, 3, 1};
    int res = solve(3, 8, 8, a, b);
    EXPECT_EQ(-1, res);
}