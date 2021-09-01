#include "abc082/d.cc"
#include <gtest/gtest.h>

TEST(abc082d, 1) { EXPECT_EQ("Yes", solve("FTFFTFFF", 4, 2)); }

TEST(abc082d, 2) { EXPECT_EQ("Yes", solve("FTFFTFFF", -2, -2)); }

TEST(abc082d, 3) { EXPECT_EQ("No", solve("FF", 1, 0)); }

TEST(abc082d, 4) { EXPECT_EQ("No", solve("TF", 1, 0)); }

TEST(abc082d, 5) { EXPECT_EQ("Yes", solve("FFTTFF", 0, 0)); }

TEST(abc082d, 6) { EXPECT_EQ("No", solve("TTTT", 1, 0)); }
