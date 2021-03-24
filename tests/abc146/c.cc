#include "abc146/c.cc"
#include "gtest/gtest.h"

TEST(abc146c, 1) { EXPECT_EQ(9ll, solve(10ll, 7ll, 100ll)); }

TEST(abc146c, 2) { EXPECT_EQ(1000000000ll, solve(2ll, 1ll, 100000000000ll)); }

TEST(abc146c, 3) { EXPECT_EQ(0ll, solve(1000000000ll, 1000000000ll, 100ll)); }

TEST(abc146c, 4) { EXPECT_EQ(254309ll, solve(1234ll, 56789ll, 314159265ll)); }
