#include "arc109/b.cc"
#include "gtest/gtest.h"

TEST(arc109b, 1) { EXPECT_EQ(3ll, solve(4ll)); }

TEST(arc109b, 2) {
    EXPECT_EQ(109109108641970782ll, solve(109109109109109109ll));
}
