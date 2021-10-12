#include "abc222/e.cc"
#include <gtest/gtest.h>

TEST(abc222e, 1) {
    vector<int> a = {2, 3, 2, 1, 4};
    vector<int> u = {1, 2, 3};
    vector<int> v = {2, 3, 4};
    EXPECT_EQ(2ll, solve(4, 5, 0, a, u, v));
}

TEST(abc222e, 2) {
    vector<int> a = {1, 2, 1, 2, 1, 2, 2, 1, 1, 2};
    vector<int> u = {1, 1};
    vector<int> v = {2, 3};
    EXPECT_EQ(0ll, solve(3, 10, 10000, a, u, v));
}

TEST(abc222e, 3) {
    vector<int> a = {1, 10};
    vector<int> u = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(126ll, solve(10, 2, -1, a, u, v));
}

TEST(abc222e, 4) {
    vector<int> a = {1, 4, 1, 4, 2, 1, 3, 5};
    vector<int> u = {1, 4, 3, 1};
    vector<int> v = {2, 1, 1, 5};

    EXPECT_EQ(2ll, solve(5, 8, -1, a, u, v));
}