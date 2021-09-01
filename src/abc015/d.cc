#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[51][51][10001];
ll solve(ll w, ll n, ll k, vector<ll> a, vector<ll> b) {

    // dp[i][j][k] 0 - i-1 番目の要素からj個選んだときに幅kに収まる最大の重要度
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) { //
            for(int l = 1; l <= w; l++) {
                if(a[i - 1] <= l) {
                    dp[i][j][l] = max(dp[i - 1][j - 1][l - a[i - 1]] + b[i - 1],
                                      dp[i - 1][j][l]);
                } else {
                    dp[i][j][l] = dp[i - 1][j][l];
                }
            }
        }
    }

    ll ans = 0ll;
    for(int i = 1; i <= k; i++)
        ans = max(ans, dp[n][i][w]);
    return ans;
}

#ifndef _debug
int main() {
    ll w, n, k;
    cin >> w >> n >> k;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    cout << solve(w, n, k, a, b) << endl;
    return 0;
}
#endif