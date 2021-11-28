#include "abc229/e.cc"
#include <gtest/gtest.h>

TEST(abc229e, 1) {
    vector<int> a = {1, 1, 1, 2, 2, 3, 3};
    vector<int> b = {2, 4, 5, 4, 3, 5, 6};
    vector<int> ans = {1, 2, 3, 2, 1, 0};
    EXPECT_EQ(ans, solve(6, 7, a, b));
}

TEST(abc229e, 2) {
    vector<int> a = {7, 3, 5, 5, 5, 6, 6};
    vector<int> b = {8, 4, 6, 7, 8, 7, 8};
    vector<int> ans = {3, 2, 2, 1, 1, 1, 1, 0};
    EXPECT_EQ(ans, solve(8, 7, a, b));
}
