#include "abc193/d.cc"
#include "gtest/gtest.h"

TEST(abc193d, 1) {
    EXPECT_NEAR(0.4444444444444444, solve(2ll, "1144#", "2233#"), 0.00001);
}

TEST(abc193d, 2) { EXPECT_NEAR(1.0, solve(2ll, "9988#", "1122#"), 0.00001); }

TEST(abc193d, 3) {
    EXPECT_NEAR(0.001932367149758454, solve(6ll, "1122#", "2228#"), 0.00001);
}

TEST(abc193d, 4) {
    EXPECT_NEAR(0.6296297942426154, solve(100000ll, "3226#", "3597#"), 0.00001);
}

