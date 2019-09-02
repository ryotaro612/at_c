#include "gtest/gtest.h"
#include "abc132/hopscotch_addict.h"

TEST(TestHopscotchAddict, First) {
    int u[] = {1, 2, 3, 4};
    int v[] = {2, 3, 4, 1};
    int ans = solve_hopscotch_addict(4, 4, u, v, 1, 3);
    EXPECT_EQ(2, ans);
}

TEST(TestHopscotchAddict, Second) {
    int u[] = {1, 2, 3};
    int v[] = {2, 3, 1};
    int ans = solve_hopscotch_addict(3, 3, u, v, 1, 2);
    EXPECT_EQ(-1, ans);
}

TEST(TestHopscotchAddict, Third) {
    int u[] = {};
    int v[] = {};
    int ans = solve_hopscotch_addict(2, 0, u, v, 1, 2);
    EXPECT_EQ(-1, ans);
}

TEST(TestHopscotchAddict, Fourth) {
    int u[] = {1,2,3,4,5,1,1,4};
    int v[] = {2,3,4,5,1,4,5,6};
    int ans = solve_hopscotch_addict(6, 8, u, v, 1, 6);
    EXPECT_EQ(2, ans);
}
