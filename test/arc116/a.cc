#include "arc116/a.cc"
#include "gtest/gtest.h"

TEST(arc116a, 1) {
    vector<string> ans = {"Same", "Odd", "Even"};
    EXPECT_EQ(ans, solve(3, {2ll, 998244353ll, 1000000000000000000ll}));
}
