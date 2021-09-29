#include "abc220/e.cc"
#include <gtest/gtest.h>

TEST(abc220e, 1) { EXPECT_EQ(14ll, solve(3ll, 2ll)); }

TEST(abc220e, 2) { EXPECT_EQ(11284501ll, solve(14142ll, 17320ll)); }
