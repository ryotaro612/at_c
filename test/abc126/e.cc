#include "abc126/e.cc"
#include <gtest/gtest.h>

TEST(abc126e, 1) {
    vector<int> x = {1}, y = {2}, z = {1};
    EXPECT_EQ(2, solve(3, 1, x, y, z));
}