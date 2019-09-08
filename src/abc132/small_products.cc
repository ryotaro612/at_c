#include <iostream>
#include "small_products.h"

// using namespace std;
/*
 * https://atcoder.jp/contests/abc132/tasks/abc132_f
 */
int solve_small_products(int n, int k) {
    int dp[k][n+1];

    for(int i=1;i<n+1;i++) {
        dp[0][i] = 1;
    }
    for(int i=1;i<k;i++) {
        for(int j=1;j<n+1;j++) {
            dp[i][j] = 0;
            int limit = n / j;
            for(int k=1;k<=limit;k++) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    int ans = 0;
    for(int i=1;i<n+1;i++) {
        ans += dp[k-1][i];
    }
    return ans;
}