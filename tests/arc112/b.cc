#include "arc112/b.cc"
#include "gtest/gtest.h"

TEST(arc112b, 1) { EXPECT_EQ(3ll, solve(11ll, 2ll)); }
TEST(arc112b, 2) { EXPECT_EQ(4, solve(0, 4)); }

TEST(arc112b, 3) { EXPECT_EQ(20210436, solve(112, 20210213)); }
TEST(arc112b, 4) {
    EXPECT_EQ(1000000000000000422, solve(-211, 1000000000000000000));
}
