#include "abc232/c.cc"
#include <gtest/gtest.h>

TEST(abc232c, 1) {
    vector<int> a = {1, 1, 1, 3};
    vector<int> b = {2, 3, 4, 4};
    vector<int> c = {1, 1, 2, 3};
    vector<int> d = {3, 4, 3, 4};
    EXPECT_EQ("Yes", solve(4, 4, a, b, c, d));
    
}
