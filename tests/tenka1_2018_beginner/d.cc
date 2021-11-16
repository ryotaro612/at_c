#include "tenka1_2018_beginner/d.cc"
#include <gtest/gtest.h>

TEST(tenka1_2018_beginnerd, 1) {
    vector<vector<int>> res = solve(3);
    vector<vector<int>> ans = {
        {1, 2},
        {1, 3},
        {2, 3},
    };
    EXPECT_EQ(ans, res);
}

TEST(tenka1_2018_beginnerd, 2) {
    vector<vector<int>> res = solve(4);
    vector<vector<int>> ans = {};
    EXPECT_EQ(ans, res);
}

TEST(tenka1_2018_beginnerd, 3) {
    vector<vector<int>> res = solve(1);
    vector<vector<int>> ans = {{1}, {1}};
    EXPECT_EQ(ans, res);
}