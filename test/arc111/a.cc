#include "arc111/a.cc"
#include "gtest/gtest.h"

TEST(arc111a, 1) { EXPECT_EQ(1ll, solve(1ll, 2ll)); }

TEST(arc111a, 2) { EXPECT_EQ(0ll, solve(2ll, 7ll)); }

TEST(arc111a, 3) { EXPECT_EQ(9015ll, solve(1000000000000000000ll, 9997ll)); }
