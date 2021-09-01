#include "arc043/a.cc"
#include "gtest/gtest.h"

TEST(arc043a, 1) {
    pair<ld, ld> res = solve(5, 2, 4, {2, 4, 6, 8, 10});
    EXPECT_NEAR(0.5, res.first, 0.000001);
    EXPECT_NEAR(-1, res.second, 0.000001);
}

TEST(arc043a, 2) {
    pair<ld, ld> res =
        solve(13, 29, 31, {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9});
    EXPECT_NEAR(3.875, res.first, 0.000001);
    EXPECT_NEAR(10.8173076, res.second, 0.000001);
}
TEST(arc043a, 3) {
    pair<ld, ld> res = solve(5, 1, 2, {34, 34, 34, 34, 34});
    EXPECT_NEAR(-1, res.first, 0.000001);
    EXPECT_NEAR(-1, res.second, 0.000001);
}
