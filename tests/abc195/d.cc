#include "abc195/d.cc"
#include "gtest/gtest.h"

TEST(abc195d, 1) {
    vector<int> ans = {20, 0, 9};
    EXPECT_EQ(ans, solve(3, 4, 3, {1, 5, 7}, {9, 3, 8}, {1, 8, 6, 9},
                         {make_pair(4, 4), make_pair(1, 4), make_pair(1, 3)}));
}
