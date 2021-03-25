#include "abc051/b.cc"
#include <gtest/gtest.h>

TEST(abc051b, 1) { EXPECT_EQ(6ll, solve(2ll, 2ll)); }

TEST(abc051b, 2) { EXPECT_EQ(1ll, solve(5ll, 15ll)); }
