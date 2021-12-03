#include "arc130/b.cc"
#include <gtest/gtest.h>

TEST(arc130b, 1) {
    vector<ll> t = {1, 1, 2, 2, 1};
    vector<ll> n = {1, 3, 2, 4, 1};
    vector<ll> c = {6, 3, 4, 2, 2};
    vector<ll> ans = {0, 8, 3, 3, 0, 0};
    EXPECT_EQ(ans, solve(4, 5, 6, 5, t, n, c));
}
