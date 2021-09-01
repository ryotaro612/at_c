#include "abc076/c.cc"
#include <gtest/gtest.h>

TEST(abc076c, 1) {
    EXPECT_EQ("atcoder", solve("?tc????", "coder"));
}

TEST(abc076c, 2) {
    EXPECT_EQ("UNRESTORABLE", solve("??p??d??", "abc"));
}