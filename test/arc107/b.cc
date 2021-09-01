#include "arc107/b.cc"
#include "gtest/gtest.h"

TEST(arc107b, 1) { EXPECT_EQ(4ll, solve(2ll, 1ll)); }

TEST(arc107b, 2) { EXPECT_EQ(10314607400ll, solve(2525ll, -425ll)); }
