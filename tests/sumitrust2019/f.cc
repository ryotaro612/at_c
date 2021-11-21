#include "sumitrust2019/f.cc"
#include <gtest/gtest.h>

TEST(sumitrust2019f, 1) { EXPECT_EQ(1ll, solve(1, 2, 10, 10, 12, 4)); }

TEST(sumitrust2019f, 2) {
    EXPECT_EQ(-1ll, 
    solve(100ll, 1ll, 101ll, 101ll, 102ll, 1ll));
}

TEST(sumitrust2019f, 3) {
    ll t1 = 12000ll, t2 = 15700ll, a1 = 3390000000ll, a2 = 3810000000ll,
       b1 = 5550000000ll, b2 = 2130000000ll;
    EXPECT_EQ(113ll, solve(t1, t2, a1, a2, b1, b2));
}

TEST(sumitrust2019f, 4) { 
    EXPECT_EQ(0ll, solve(1, 2, 10, 10, 2, 2)); }

TEST(sumitrust2019f, 5) { 
    EXPECT_EQ(0ll, solve(1, 2, 2, 2, 10, 10)); }

TEST(sumitrust2019f, 6) {
    EXPECT_EQ(0ll, solve(1, 1, 1, 2, 10, 1));
}