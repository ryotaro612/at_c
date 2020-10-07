#include <gtest/gtest.h>
#include "abc093/d.cc"

TEST(abc093d, 1)
{
    vector<ll> a = {1, 10, 3, 4, 8, 22, 8, 314159265};
    vector<ll> b = {4, 5, 3, 11, 9, 40, 36, 358979323};
    auto res = solve(8, a, b);
    vector<ll> ans = {1, 12, 4, 11, 14, 57, 31, 671644785};
    EXPECT_EQ(ans, res);
}