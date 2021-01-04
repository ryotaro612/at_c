#include "abc020/d.cc"
#include <gtest/gtest.h>

TEST(abc020d, 1) { EXPECT_EQ(14, solve(4, 2)); }

TEST(abc020d, 2) { EXPECT_EQ(865504986, solve(10000, 100)); }

TEST(abc020d, 3) { EXPECT_EQ(50001213, solve(1000000000, 90)); }

TEST(abc020d, 4) { EXPECT_EQ(231285006, solve(1000000000, 999999900)); }