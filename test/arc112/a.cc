#include "arc112/a.cc"
#include "gtest/gtest.h"

TEST(arc112a, 1) {
    vector<ll> ans = {6, 1, 0, 933184801, 500001500001};
    vector<ll> res =
        solve(5, {2, 0, 1000000, 12345, 0}, {6, 0, 1000000, 67890, 1000000});

    EXPECT_EQ(ans, res);
}
