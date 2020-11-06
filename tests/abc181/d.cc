#include "abc181/d.cc"
#include "gtest/gtest.h"

TEST(abc181d, 1) { EXPECT_EQ("Yes", solve("1234")); }

TEST(abc181d, 2) { EXPECT_EQ("No", solve("1333")); }

TEST(abc181d, 3) { EXPECT_EQ("Yes", solve("8")); }

TEST(abc181d, 4) { EXPECT_EQ("Yes", solve("256")); }

TEST(abc181d, 5) { EXPECT_EQ("No", solve("12")); }

TEST(abc181d, 6) { EXPECT_EQ("Yes", solve("265")); }
