#include "abc148/f.cc"
#include <gtest/gtest.h>

TEST(abc148f, 1) {
    vector<int> a = {1, 2, 3, 3}, b = {2, 3, 4, 5};
    EXPECT_EQ(2, solve(5, 4, 1, a, b));
}

TEST(abc148f, 2) {
    vector<int> a = {1, 1, 1, 1};
    vector<int> b = {2, 3, 4, 5};
    EXPECT_EQ(1, solve(5, 4, 5, a, b));
}

TEST(abc148f, 3) {
    vector<int> a = {1};
    vector<int> b = {2};
    EXPECT_EQ(0, solve(2, 1, 2, a, b));
}

TEST(abc148f, 4) {
    vector<int> a = {1, 2, 3, 4, 5, 4, 7, 8};
    vector<int> b = {2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(5, solve(9, 6, 1, a, b));
}
