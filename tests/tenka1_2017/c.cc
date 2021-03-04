#include "tenka1_2017/c.cc"
#include "gtest/gtest.h"

TEST(tenka1_2017c, 1) {
    Res res = solve(2);
    EXPECT_EQ(1, res.h);
    EXPECT_EQ(2, res.n);
    EXPECT_EQ(2, res.w);
}

