#include "abc128/b.cc"
#include "gtest/gtest.h"

TEST(abc128b, 1) {
    vector<int> ans = {3, 4, 6, 1, 5, 2};
    EXPECT_EQ(ans, solve(6,
                         {"khabarovsk", "moscow", "kazan", "kazan", "moscow",
                          "khabarovsk"},
                         {20, 10, 50, 35, 60, 40}));
}

TEST(abc128b, 2) {
    vector<int> ans = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    EXPECT_EQ(ans,
              solve(10,
                    {"yakutsk", "yakutsk", "yakutsk", "yakutsk", "yakutsk",
                     "yakutsk", "yakutsk", "yakutsk", "yakutsk", "yakutsk"},
                    {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}));
}
