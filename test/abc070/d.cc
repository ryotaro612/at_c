#include "abc070/d.cc"
#include <gtest/gtest.h>

TEST(abc070d, 1) {
    vector<ll> res = solve(5, {1, 1, 2, 3}, {2, 3, 4, 5}, {1, 1, 1, 1}, 3, 1,
                           {2, 2, 4}, {4, 3, 5});
    vector<ll> ans = {3, 2, 4};
    EXPECT_EQ(ans, res);
}

TEST(abc070d, 2) {
    vector<ll> res = solve(7, {1, 1, 1, 1, 1, 1}, {2, 3, 4, 5, 6, 7},
                           {1, 3, 5, 7, 9, 11}, 3, 2, {1, 4, 6}, {3, 5, 7});
    vector<ll> ans = {5, 14, 22};
    EXPECT_EQ(ans, res);
}

TEST(abc070d, 3) {
    vector<ll> res =
        solve(10, {1, 2, 3, 4, 5, 6, 7, 8, 9}, {2, 3, 4, 5, 6, 7, 8, 9, 10},
              {1000000000, 1000000000, 1000000000, 1000000000, 1000000000,
               1000000000, 1000000000, 1000000000, 1000000000},
              1, 1, {9}, {10});
    vector<ll> ans = {17000000000};
    EXPECT_EQ(ans, res);
}
