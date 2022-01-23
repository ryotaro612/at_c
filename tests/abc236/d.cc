#include "abc236/d.cc"
#include <gtest/gtest.h>

TEST(abc236d, 1) {
    int n = 2;
    vector<vector<int>> am = {{4, 0, 1}, {5, 3}, {2}};
    EXPECT_EQ(6, solve(n, am));
}
