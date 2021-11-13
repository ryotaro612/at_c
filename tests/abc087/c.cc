#include "abc087/c.cc"
#include <gtest/gtest.h>

TEST(abc087c, 1) {
    vector<vector<int>> a = {{3, 2, 2, 4, 1}, {1, 2, 2, 2, 1}};
    EXPECT_EQ(14, solve(5, a));
}