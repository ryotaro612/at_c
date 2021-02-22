#include "abc036/c.cc"
#include <gtest/gtest.h>

TEST(abc036c, 1) {
    vector<ll> ans = {1, 1, 0, 2, 0};
    EXPECT_EQ(ans, solve(5, {3, 3, 1, 6, 1}));
}
