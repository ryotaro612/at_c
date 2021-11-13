#include "abc224/d.cc"
#include <gtest/gtest.h>

TEST(abc224d, 1) {
    vector<int> u = {1, 1, 1, 2, 3};
    vector<int> v = {2, 3, 9, 9, 9};
    vector<int> p = {3, 9, 2, 4, 5, 6, 7, 8};

    EXPECT_EQ(5ll, solve(5, u, v, p));
}

TEST(abc224d, 2) {
    vector<int> u = {1, 1, 1, 2, 3};
    vector<int> v = {2, 3, 9, 9, 9};
    vector<int> p = {1, 2, 3, 4, 5, 6, 7, 8};

    EXPECT_EQ(0, solve(5, u, v, p));
}

TEST(abc224d, 3) {
    vector<int> u = {8, 9, 4, 4, 2, 8, 2, 3, 8, 6, 7, 2};
    vector<int> v = {5, 6, 5, 1, 5, 9, 1, 6, 7, 5, 4, 3};
    vector<int> p = {1, 2, 3, 4, 5, 6, 8, 7};
    EXPECT_EQ(-1, solve(12, u, v, p));
}

TEST(abc224d, 4) {
    vector<int> u = {6, 5, 4, 4, 8, 2, 2, 6, 3, 9, 8, 3};
    vector<int> v = {5, 4, 1, 7, 5, 1, 5, 9, 6, 8, 7, 2};
    vector<int> p = {2, 3, 4, 6, 1, 9, 7, 8};
    EXPECT_EQ(16, solve(12, u, v, p));
}