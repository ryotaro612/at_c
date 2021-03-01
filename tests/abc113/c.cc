#include "abc113/c.cc"
#include "gtest/gtest.h"

TEST(abc113c, 1) {
    vector<string> ans = {"000001000002", "000002000001", "000001000001"};
    EXPECT_EQ(ans, solve(2, 3, {1, 2, 1}, {32, 63, 12}));
}

TEST(abc113c, 2) {
    vector<string> ans = {"000002000001", "000002000002", "000002000003"};
    EXPECT_EQ(ans, solve(2, 3, {2, 2, 2}, {55, 77, 99}));
}
