#include "arc113/b.cc"
#include "gtest/gtest.h"

TEST(arc113b, 1) { EXPECT_EQ(4ll, solve(4ll, 3ll, 2ll)); }

TEST(arc113b, 2) { EXPECT_EQ(1ll, solve(1ll, 2ll, 3ll)); }

TEST(arc113b, 3) { EXPECT_EQ(2ll, solve(3141592ll, 6535897ll, 9323846ll)); }
