#include "arc106/a.cc"
#include "gtest/gtest.h"

TEST(arc106a, 1) {
    pair<ll, ll> res = solve(106ll);
    EXPECT_EQ(4ll, res.first);
    EXPECT_EQ(2ll, res.second);
}

TEST(arc106a, 2) {
    pair<ll, ll> res = solve(1024ll);
    EXPECT_EQ(-1ll, res.first);
    EXPECT_EQ(-1ll, res.second);
}

TEST(arc106a, 3) {
    pair<ll, ll> res = solve(10460353208ll);
    EXPECT_EQ(21ll, res.first);
    EXPECT_EQ(1ll, res.second);
}
TEST(arc106a, 4) {
    pair<ll, ll> res = solve(748307129767950488ll);
    EXPECT_EQ(37ll, res.first);
    EXPECT_EQ(25ll, res.second);
}