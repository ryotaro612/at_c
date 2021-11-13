#include "abc225/d.cc"
#include <gtest/gtest.h>

TEST(abc225d, 1) {
    vector<vector<int>> queries = {
        {1, 6, 3}, {1, 4, 1}, {1, 5, 2}, {1, 2, 7}, {1, 3, 5}, {3, 2}, {3, 4},
        {3, 6},    {2, 3, 5}, {2, 4, 1}, {1, 1, 5}, {3, 2},    {3, 4}, {3, 6}};
    vector<vector<int>> res = solve(7, 14, queries);
    vector<vector<int>> ans = {
        {5, 6, 3, 5, 2, 7}, {2, 4, 1}, {5, 6, 3, 5, 2, 7},
        {4, 1, 5, 2, 7},    {1, 4},    {2, 6, 3}};
    EXPECT_EQ(ans, res);
}
