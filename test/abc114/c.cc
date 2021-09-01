#include "abc114/c.cc"
#include "gtest/gtest.h"

TEST(abc114c, 1) { EXPECT_EQ(4ll, solve("575")); }

TEST(abc114c, 2) { EXPECT_EQ(13ll, solve("3600")); }

TEST(abc114c, 3) { EXPECT_EQ(26484ll, solve("999999999")); }