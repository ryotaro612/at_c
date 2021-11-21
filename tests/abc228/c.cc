#include "abc228/c.cc"
#include <gtest/gtest.h>

TEST(abc228c, 1) {
    vector<string> ans = {"Yes", "Yes", "No"};
    vector<vector<int>> p = {{178, 205, 132}, {112, 220, 96}, {36, 64, 20}};
    EXPECT_EQ(ans, solve(3, 1, p));
}

TEST(abc228c, 3) {
    vector<string> ans = {"Yes", "Yes", "No", "Yes"};
    vector<vector<int>> p = {
        {127, 235, 78}, {192, 134, 298}, {28, 56, 42}, {96, 120, 250}};
    EXPECT_EQ(ans, solve(4, 2, p));
}