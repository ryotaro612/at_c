#include "abc005/d.cc"
#include <gtest/gtest.h>

TEST(abc005d, 1) {
    vector<int> res = solve(3, {{3, 2, 1}, {2, 2, 1}, {1, 1, 1}}, 3, {1, 4, 9});
    vector<int> ans = {3, 9, 14};
    EXPECT_EQ(ans, res);
}
TEST(abc005d, 2) {
    vector<int> ans = {27};
    vector<int> res = solve(3, {{1, 1, 1}, {1, 1, 1}, {9, 9, 9}}, 1, {4});
    EXPECT_EQ(ans, res);
}