#include "arc129/a.cc"
#include <gtest/gtest.h>

TEST(arc129a, 1) { EXPECT_EQ(1, solve(2, 1, 2)); }

TEST(arc129a, 2) { EXPECT_EQ(10, solve(10, 2, 19)); }

TEST(arc129a, 3) {

    EXPECT_EQ(847078495393153025ll,
              solve(1000000000000000000ll, 1ll, 1000000000000000000ll));
}
