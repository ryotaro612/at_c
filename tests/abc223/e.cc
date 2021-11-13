#include "abc223/e.cc"
#include <gtest/gtest.h>

TEST(abc223e, 1) { EXPECT_EQ(true, solve(3, 3, 2, 2, 3)); }

TEST(abc223e, 2) { EXPECT_EQ(false, solve(3, 3, 4, 4, 1)); }

TEST(abc223e, 3) {
    EXPECT_EQ(false, solve(1000000000ll, 1000000000ll, 1000000000000000000ll,
                           1000000000000000000ll, 1000000000000000000ll));
}
