#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sub(ll h, ll w, ll c, vector<vector<ll>> a) {
    // dp[i][j]は(i, j)にいて1つめの駅の設置を終了
    ll INF = 1000000000000000ll;
    vector<vector<ll>> dp(h + 1, vector<ll>(w + 1, INF));
    for(ll i = 1ll; i <= h; i++) {
        for(ll j = 1ll; j <= w; j++) {
            dp[i][j] =
                min(a[i - 1][j - 1], min(dp[i - 1][j] + c, dp[i][j - 1] + c));
        }
    }
    vector<vector<ll>> dp2(h + 1, vector<ll>(w + 1, INF));
    for(ll i = 1ll; i <= h; i++) {
        for(ll j = 1ll; j <= w; j++) {
            dp2[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + c + a[i - 1][j - 1];
        }
    }
    ll res = INF;
    for(ll i = 1ll; i <= h; i++)
        for(ll j = 1ll; j <= w; j++)
            res = min(res, dp2[i][j]);
    return res;
}

ll solve(ll h, ll w, ll c, vector<vector<ll>> a) {
    ll ans = sub(h, w, c, a);
    vector<vector<ll>> aa(h, vector<ll>(w));
    for(ll i = 0ll; i < h; i++) {
        for(ll j = 0ll; w % 2ll == 0ll ? (j < w / 2ll) : (j <= w / 2ll); j++) {
            aa[i][j] = a[i][w - 1 - j];
            aa[i][w - 1 - j] = a[i][j];
        }
    }
    return min(ans, sub(h, w, c, aa));
}

#ifndef _debug
int main() {
    ll h, w, c;
    cin >> h >> w >> c;
    vector<vector<ll>> a(h, vector<ll>(w));
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> a[i][j];

    cout << solve(h, w, c, a) << endl;
    return 0;
}
#endif