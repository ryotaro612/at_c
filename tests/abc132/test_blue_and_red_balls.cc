#include "gtest/gtest.h"
#include<vector>
#include "abc132/blue_and_red_balls.h"

TEST(abc132d, 1) {
    std::vector<long long>  ans {3, 6, 1};
    EXPECT_EQ(ans, solve_blue_and_red_balls(5, 3));
}

TEST(abc132d, 2) {
    std::vector<long long>  ans {1998,3990006,327341989};
    EXPECT_EQ(ans, solve_blue_and_red_balls(2000, 3));
}
