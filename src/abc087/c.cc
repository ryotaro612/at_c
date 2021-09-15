#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, vector<vector<int>> &a) {

    vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    for(int i = 0; i < n; i++) {
        dp[0][i + 1] = a[0][i] + dp[0][i];
        dp[1][i + 1] = a[1][i] + max(dp[0][i + 1], dp[1][i]);
    }

    return dp[1][n];
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    rep(i, n) cin >> a[0][i];
    rep(i, n) cin >> a[1][i];

    cout << solve(n, a) << endl;
    return 0;
}
#endif