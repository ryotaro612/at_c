#include "arc053/b.cc"
#include "gtest/gtest.h"

TEST(arc053b, 1) { EXPECT_EQ(3, solve("rokovoko")); }

TEST(arc053b, 2) { EXPECT_EQ(6, solve("tomtom")); }

TEST(arc053b, 3) { EXPECT_EQ(1, solve("vwxyz")); }

TEST(arc053b, 4) { EXPECT_EQ(3, solve("succeeded")); }

