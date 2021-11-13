#include "abc049/c.cc"
#include <gtest/gtest.h>

TEST(abc049c, 1) { EXPECT_EQ("YES", solve("erasedream")); }

TEST(abc049c, 2) { EXPECT_EQ("YES", solve("dreameraser")); }

TEST(abc049c, 3) { EXPECT_EQ("NO", solve("dreamerer")); }
