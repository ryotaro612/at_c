#include "gtest/gtest.h"
#include<vector>
#include "abc132/blue_and_red_balls.h"

TEST(TestBlueAndRedBalls, First) {
    std::vector<int>  ans {3, 6, 1};
    EXPECT_EQ(ans, solve_blue_and_red_balls(5, 3));
}

TEST(TestBlueAndRedBalls, Second) {
    std::vector<int>  ans {1998,3990006,327341989};
    EXPECT_EQ(ans, solve_blue_and_red_balls(2000, 3));
}