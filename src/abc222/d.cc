#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const ll MOD = 998244353ll;

ll solve(int n, vector<ll> &a, vector<ll> &b) {
    // const int mx = 3001;
    const int mx = 3001;
    vector<vector<ll>> dp(n + 1, vector<ll>(mx, 0ll));
    // rep(i, mx) dp[0][i] = 1ll;
    for(int i = a[0]; i < mx; i++) {
        if(i == a[0])
            dp[1][i] = 1;
        else if(i <= b[0])
            dp[1][i] = dp[1][i - 1] + 1;
        else
            dp[1][i] = dp[1][b[0]];
    }

    rep(i, n) {
        if(i < 1)
            continue;
        rep(j, mx) {
            if(j < a[i])
                continue;
            if(b[i] < j) {
                dp[i + 1][j] = dp[i + 1][j - 1];
                continue;
            }
            if(j == a[i])
                dp[i + 1][j] = dp[i][j];
            else { // a[i] < j <= b[i]
                dp[i + 1][j] = dp[i + 1][j - 1];
                dp[i + 1][j] %= MOD;
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
        }
    }
    return dp[n][mx - 1];
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    cout << solve(n, a, b) << endl;
    return 0;
}
#endif
