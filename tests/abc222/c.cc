#include "abc222/c.cc"
#include <gtest/gtest.h>

TEST(abc222c, 1) {
    vector<string> a = {"GCP", "PPP", "CCC", "PPC"};
    vector<int> ans = {3, 1, 2, 4};
    EXPECT_EQ(ans, solve(2, 3, a));
}
