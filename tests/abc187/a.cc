#include "abc187/a.cc"
#include "gtest/gtest.h"

TEST(abc187a, 1) { EXPECT_EQ(9, solve("123", "234")); }

TEST(abc187a, 2) { EXPECT_EQ(17, solve("593", "953")); }

TEST(abc187a, 3) { EXPECT_EQ(27, solve("100", "999")); }