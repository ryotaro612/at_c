#include "abc016/c.cc"
#include <gtest/gtest.h>

TEST(abc016c, 1) {
    vector<int> ans = {1, 0, 1};
    EXPECT_EQ(ans, solve(3, 2, {1, 2}, {2, 3}));
}

TEST(abc016c, 2) {
    vector<int> ans = {0, 0, 0};
    EXPECT_EQ(ans, solve(3, 3, {1, 1, 2}, {2, 3, 3}));
}

TEST(abc016c, 3) {
    vector<int> ans = {4, 4, 4, 5, 2, 3, 4, 2};
    EXPECT_EQ(ans, solve(8, 12, {1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 7},
                         {6, 7, 8, 5, 6, 5, 6, 5, 8, 6, 7, 8}));
}
