#include "arc115/b.cc"
#include "gtest/gtest.h"

TEST(arc115b, 1) {
    Res res = solve(3, {{4, 3, 5}, {2, 1, 3}, {3, 2, 4}});
    EXPECT_EQ("Yes", res.yn);
    /*
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            EXPECT_EQ();
    }
    */
    vector<ll> a = {2, 0, 1};
    EXPECT_EQ(a, res.a);
    vector<ll> b = {2, 1, 3};

    EXPECT_EQ(b, res.b);
}

TEST(arc115b, 2) {
    Res res = solve(3, {{4, 3, 5}, {2, 2, 3}, {3, 2, 4}});
    EXPECT_EQ("No", res.yn);
}