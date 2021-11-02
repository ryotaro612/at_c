#include "zone2021/c.cc"
#include <gtest/gtest.h>

TEST(zone2021c, 1) {
    vector<vector<ll>> av = {{3, 9, 6, 4, 6}, {6, 9, 3, 1, 1}, {8, 8, 9, 3, 7}};
    EXPECT_EQ(4ll, solve(3, av));
}

TEST(zone2021c, 2) {
    vector<vector<ll>> av = {{6, 13, 6, 19, 11},
                             {4, 4, 12, 11, 18},
                             {20, 7, 19, 2, 5},
                             {15, 5, 12, 20, 7},
                             {8, 7, 6, 18, 5}};
    EXPECT_EQ(13ll, solve(5, av));
}

TEST(zone2021c, 3) {
    vector<vector<ll>> av = {
{6,7,5,18,2},
{3,8,1,6,3},
{7,2,8,7,7},
{6,3,3,4,7},
{12,8,9,15,9},
{9,8,6,1,10},
{12,9,7,8,2},
{10,3,17,4,10},
{3,1,3,19,3},
{3,14,7,13,1}
	};
    EXPECT_EQ(10ll, solve(10, av));
}