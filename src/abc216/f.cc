#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const ll MOD = 998244353ll;
const int bound = 5000; // 5000

ll solve(int n, vector<ll> &a, vector<ll> &b) {
    vector<pair<ll, ll>> ab(n);
    rep(i, n) ab[i] = {a[i], b[i]};
    sort(ab.begin(), ab.end());
    rep(i, n) {
        a[i] = ab[i].first;
        b[i] = ab[i].second;
    }

    vector<vector<ll>> dp(bound + 1, vector<ll>(bound + 1, 0));
    ll ans = 0ll;
    dp[0][0] = 1ll;
    rep(i, n) {
        rep(j, bound + 1) {
            if(j - b[i] >= 0 && bound >= j - b[i]) {
                dp[i + 1][j] += dp[i][j - b[i]];
                dp[i + 1][j] %= MOD;
            }
        }
        for(int j = 1; j <= bound; j++) {
            if(a[i] >= j) {
                ans += dp[i + 1][j];
                ans %= MOD;
            }
        }
        rep(j, bound + 1) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
        }
    }
    return ans;
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
