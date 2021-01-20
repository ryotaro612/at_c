#include "abc074/c.cc"
#include <gtest/gtest.h>

TEST(abc074c, 1) {
    pair<int, int> res = solve(1, 2, 10, 20, 15, 200);
    double ans = ((double)10 / (double)110);
    double density = ((double)res.second / (double)res.first);
    EXPECT_NEAR(ans, density, 0.01);
}

TEST(abc074c, 2) {
    pair<int, int> res = solve(1, 2, 1, 2, 100, 1000);
    double ans = ((double)100 / (double)200);
    double density = ((double)res.second / (double)res.first);
    EXPECT_NEAR(ans, density, 0.01);
}

TEST(abc074c, 3) {
    pair<int, int> res = solve(17, 19, 22, 26, 55, 2802);
    double ans = ((double)934 / (double)2634);
    double density = ((double)res.second / (double)res.first);
    EXPECT_NEAR(ans, density, 0.01);
}