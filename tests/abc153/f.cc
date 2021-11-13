#include "abc153/f.cc"
#include <gtest/gtest.h>

TEST(abc153f, 1) {
    vector<ll> x = {1, 5, 9}, h = {2, 4, 2};
    EXPECT_EQ(2, solve(3, 3, 2, x, h));
}

TEST(abc153f, 2) {
    vector<ll> x = {1, 2, 3, 4, 5, 6, 7, 8, 9}, h = {5, 4, 3, 2, 1, 2, 3, 4, 5};
    EXPECT_EQ(5, solve(9, 4, 1, x, h));
}

TEST(abc153f, 3) {
    vector<ll> x = {300000000ll, 100000000ll, 200000000ll},
               h = {1000000000ll, 1000000000ll, 1000000000ll};
    EXPECT_EQ(3000000000ll, solve(3, 0, 1, x, h));
}
