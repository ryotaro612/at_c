#include "arc051/b.cc"
#include "gtest/gtest.h"

int counter = 0;
int gcd(int a, int b) {
    if(b == 0)
        return a;
    counter++;
    return gcd(b, a % b);
}

TEST(arc051b, 1) {
    auto res = solve(1);
    counter = 0;
    gcd(res.first, res.second);
    EXPECT_EQ(counter, 1);
}

TEST(arc051b, 2) {
    auto res = solve(3);
    counter = 0;
    gcd(res.first, res.second);
    EXPECT_EQ(counter, 3);
}

TEST(arc051b, 3) {
    auto res = solve(12);
    counter = 0;
    gcd(res.first, res.second);
    EXPECT_EQ(counter, 12);
}
