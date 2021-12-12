#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<ll> calc_keta(ll x, vector<ll> &av) {
    vector<ll> res(av.size());
    for(int i = (int)av.size() - 1; i >= 0; i--) {
        ll div = x / av[i];
        res[i] = div;
        x -= div * av[i];
    }
    return res;
}

ll solve(int n, ll x, vector<ll> &av) {
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    vector<ll> keta = calc_keta(x, av);
    // dp[i][0] 0は余分に支払っていない。
    // dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        ll d = keta[n - 1 - i];
        //前の桁が余分に払っていない
        // 今回も余分に払わない
        dp[i + 1][0] += d + dp[i][0];
        // 今回は余分にはらう
        dp[i + 1][1] += d + 1 + dp[i][0];
        //前の桁が余分に払った
        // 今回は余分に払わない
        if(i > 0) {
            ll change =
                (av[n - 1 - (i - 1)] - d * av[n - 1 - i]) / av[n - 1 - i];
            ll temp = change + dp[i][1];
            dp[i + 1][0] = min(temp, dp[i + 1][0]);
            if(change > 0) {
                temp = change - 1 + dp[i][1];
                dp[i + 1][1] = min(temp, dp[i + 1][1]);
            }
        }
    }
    return dp[n][0];
}

#ifndef _debug
int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> av(n);
    rep(i, n) cin >> av[i];
    cout << solve(n, x, av) << endl;
    return 0;
}
#endif