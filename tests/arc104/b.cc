#include "arc104/b.cc"
#include "gtest/gtest.h"

TEST(arc104b, 1) { EXPECT_EQ(2ll, solve(4, "AGCT")); }

TEST(arc104b, 2) { EXPECT_EQ(4ll, solve(4, "ATAT")); }

TEST(arc104b, 3) { EXPECT_EQ(6ll, solve(10, "AAATACCGCG")); }