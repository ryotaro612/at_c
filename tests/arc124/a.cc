#include "arc124/a.cc"
#include <gtest/gtest.h>

TEST(arc124a, 1) {
    vector<char> c = {'L', 'R'};
    vector<int> k = {1, 2};
    EXPECT_EQ(1ll, solve(3, 2, c, k));
}

TEST(arc124a, 2) {
    vector<char> c = {'R', 'R', 'R', 'R', 'L', 'L', 'R', 'L', 'L', 'R'};
    vector<int> k = {6, 8, 7, 25, 26, 13, 14, 11, 23, 30};
    EXPECT_EQ(343921442ll, solve(30, 10, c, k));
}


