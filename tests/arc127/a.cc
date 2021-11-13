#include "arc127/a.cc"
#include <gtest/gtest.h>

TEST(arc127a, 1) { EXPECT_EQ(4ll, solve(11ll)); }

TEST(arc127a, 2) { EXPECT_EQ(44ll, solve(120ll)); }

TEST(arc127a, 3) { EXPECT_EQ(123456789ll, solve(987654321ll)); }

TEST(arc127a, 4) { EXPECT_EQ(1ll, solve(1ll)); }

TEST(arc127a, 5) { EXPECT_EQ(2ll, solve(10ll)); }

TEST(arc127a, 6) {
    // 1, 100, 10, 11 - 19
    // 1 1 10 1
    EXPECT_EQ(13ll, solve(100ll));
}

TEST(arc127a, 7) { EXPECT_EQ(14ll, solve(101ll)); }

TEST(arc127a, 8) { EXPECT_EQ(22ll, solve(109ll)); }