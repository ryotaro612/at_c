#include "arc126/b.cc"
#include <gtest/gtest.h>

// TEST(arc126b, 1) {
//     vector<int> a = {1, 2, 3}, b = {2, 3, 1};
//     EXPECT_EQ(2, solve(3, 3, a, b));
// }

TEST(arc126b, 2) {
    vector<int> a = {1, 2, 2, 3, 3}, b = {1, 1, 2, 2, 3};
    EXPECT_EQ(3, solve(3, 5, a, b));
}

TEST(arc126b, 3) {
    vector<int> a = {1, 7, 3, 2, 5}, b = {7, 1, 4, 6, 2};
    EXPECT_EQ(1, solve(7, 5, a, b));
}