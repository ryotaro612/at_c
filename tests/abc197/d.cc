#include "abc197/d.cc"
#include "gtest/gtest.h"

TEST(abc197d, 1) {
    pair<ld, ld> ans = solve(4, 1, 1, 2, 2);
    EXPECT_NEAR(2.00000000000, ans.first, 0.0001);
    EXPECT_NEAR(1.00000000000, ans.second, 0.0001);
}

TEST(abc197d, 2) {
    pair<ld, ld> ans = solve(6, 5, 3, 7, 4);
    EXPECT_NEAR(5.93301270189, ans.first, 0.0001);
    EXPECT_NEAR(2.38397459622, ans.second, 0.0001);
}
