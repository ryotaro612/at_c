#include "arc108/b.cc"
#include "gtest/gtest.h"

TEST(arc108b, 1) { EXPECT_EQ(3, solve(6, "icefox")); }

TEST(arc108b, 2) { EXPECT_EQ(7, solve(7, "firebox")); }

TEST(arc108b, 3) { EXPECT_EQ(27, solve(48, "ffoxoxuvgjyzmehmopfohrupffoxoxfofofoxffoxoxejffo")); }
