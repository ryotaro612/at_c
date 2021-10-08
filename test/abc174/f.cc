#include "abc174/f.cc"
#include <gtest/gtest.h>

TEST(abc174f, 1) {
    vector<int> c = {1, 2, 1, 3};
    vector<int> l = {1, 2, 3};
    vector<int> r = {3, 4, 3};
    vector<int> ans = {2, 3, 1};
    EXPECT_EQ(ans, solve(4, 3, c, l, r));
}

TEST(abc174f, 2) {
    vector<int> c = {2, 5, 6, 5, 2, 1, 7, 9, 7, 2};
    vector<int> l = {5, 2, 6, 2, 7, 7, 1, 6, 8, 6};
    vector<int> r = {5, 4, 7, 2, 8, 9, 8, 9, 10, 8};
    vector<int> ans = {1, 2, 2, 1, 2, 2, 6, 3, 3, 3};
    EXPECT_EQ(ans, solve(10, 10, c, l, r));
}
