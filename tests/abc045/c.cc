#include "abc045/c.cc"
#include <gtest/gtest.h>

TEST(abc045c, 1) { EXPECT_EQ(176, solve("125")); }

TEST(abc045c, 2) { EXPECT_EQ(12656242944, solve("9999999999")); }