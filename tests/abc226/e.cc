#include "abc226/e.cc"
#include <gtest/gtest.h>

TEST(abc226e, 1) {
    vector<int> u = {1, 1, 2};
    vector<int> v = {2, 3, 3};
    EXPECT_EQ(2, solve(3, 3, u, v));
}

TEST(abc226e, 2) {
    vector<int> u = {1};
    vector<int> v = {2};
    EXPECT_EQ(0, solve(2, 1, u, v));
}

TEST(abc226e, 3) {
    vector<int> u = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v = {2, 3, 4, 2, 6, 7, 5};
    EXPECT_EQ(4, solve(7, 7, u, v));
}
