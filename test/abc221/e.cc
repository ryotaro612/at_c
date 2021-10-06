#include "abc221/e.cc"
#include <gtest/gtest.h>

TEST(abc221e, 1) {
    vector<ll> a = {1, 2, 1};
    EXPECT_EQ(3ll, solve(3, a));
}

TEST(abc221e, 2) {
    vector<ll> a = {1, 2, 2};
    EXPECT_EQ(4ll, solve(3, a));
}

TEST(abc221e, 3) {
    vector<ll> a = {3, 2, 1};
    EXPECT_EQ(0ll, solve(3, a));
}

TEST(abc221e, 4) {
    vector<ll> a = {198495780, 28463047,  859606611, 212983738, 946249513,
                    789612890, 782044670, 700201033, 367981604, 302538501};
    EXPECT_EQ(830ll, solve(10, a));
}