#include "abc184/f.cc"
#include <gtest/gtest.h>

TEST(abc184f, 1) {
    vector<ll> a = {2, 3, 5, 7, 11};
    EXPECT_EQ(17, solve(5, 17, a));
}

TEST(abc184f, 2) {
    vector<ll> a = {1, 2, 7, 5, 8, 10};
    EXPECT_EQ(33ll, solve(6, 100, a));
}

TEST(abc184f, 3) {
    vector<ll> a = {101, 102, 103, 104, 105, 106};
    EXPECT_EQ(0ll, solve(6, 100, a));
}

TEST(abc184f, 4) {
    vector<ll> a = {6706927ll,  91566569ll, 89131517ll, 71069699ll,
                    75200339ll, 98298649ll, 92857057ll};
    EXPECT_EQ(273555143ll, solve(7, 273599681ll, a));
}
