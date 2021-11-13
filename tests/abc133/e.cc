#include "abc133/e.cc"
#include <gtest/gtest.h>

TEST(abc133e, 1) {
    vector<int> a = {1, 2, 3}, b = {2, 3, 4};
    EXPECT_EQ(6, solve(4, 3, a, b));
}

TEST(abc133e, 2) {
    vector<int> a = {1, 1, 1, 4}, b = {2, 3, 4, 5};
    EXPECT_EQ(48, solve(5, 4, a, b));
}

TEST(abc133e, 3) {
    vector<int> a = {12, 3, 4, 7, 6, 2, 5, 14, 10, 3, 3, 8, 16, 9, 4},
                b = {1, 1, 16, 12, 2, 15, 16, 16, 11, 10, 13, 6, 8, 12, 3};
    EXPECT_EQ(271414432ll, solve(16, 22, a, b));
}
