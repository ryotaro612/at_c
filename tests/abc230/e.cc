#include "abc230/e.cc"
#include <gtest/gtest.h>

ll answer(ll n) {
    ll res = 0ll;
    for(ll i = 1; i <= n; i++) {
        res += n / i;
    }
    return res;
}

TEST(abc230e, 1) { EXPECT_EQ(5ll, solve(3ll)); }

TEST(abc230e, 2) { EXPECT_EQ(231802823220ll, solve(10000000000ll)); }

TEST(abc230e, 3) { EXPECT_EQ(answer(1), solve(1)); }

TEST(abc230e, 4) { 
    EXPECT_EQ(answer(5), solve(5)); 
}

TEST(abc230e, 5) { 
    EXPECT_EQ(answer(6), solve(6)); 
}
/*
TEST(abc230e, 5) {

    for(int i = 0; i < 20; i++) {
        cout << i  << endl;
        EXPECT_EQ(answer(i), solve(i));
    }
}
*/