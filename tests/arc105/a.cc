#include "arc105/a.cc"
#include "gtest/gtest.h"

TEST(arc105a, 1) { EXPECT_EQ("Yes", solve(1, 2, 3, 4)); }

TEST(arc105a, 2) { EXPECT_EQ("No", solve(1, 2, 4, 8)); }
