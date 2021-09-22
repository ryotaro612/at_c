#include "abc129/e.cc"
#include <gtest/gtest.h>

TEST(abc129e, 1) { EXPECT_EQ(5ll, solve("10")); }
TEST(abc129e, 2) { EXPECT_EQ(162261460ll, solve("1111111111111111111")); }
