#include "caddi2018b/d.cc"
#include "gtest/gtest.h"

TEST(caddi2018bd, 1) { EXPECT_EQ("first", solve(2, {1, 2})); }

TEST(caddi2018bd, 2) { EXPECT_EQ("second", solve(3, {100000, 30000, 20000})); }
