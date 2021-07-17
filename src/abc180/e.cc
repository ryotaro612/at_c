// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> dp;
const ll INF = 100000000000000ll;

ll rec(int s, int v, int n, vector<ll> &x, vector<ll> &y, vector<ll> &z) {
    if(dp[s][v] >= 0)
        return dp[s][v];
    if(s == (1 << n) - 1 && v == 0)
        return dp[s][v] = 0ll;

    ll res = INF;
    for(int u = 0; u < n; u++) {
        if(!(s >> u & 1)) {
            ll d = abs(x[u] - x[v]) + abs(y[u] - y[v]) + max(0ll, z[u] - z[v]);
            res = min(res, rec(s | 1 << u, u, n, x, y, z) + d);
        }
    }

    return dp[s][v] = res;
}

ll solve(int n, vector<ll> x, vector<ll> y, vector<ll> z) {
    dp.resize(1 << n);
    fill(dp.begin(), dp.end(), vector<ll>(n, -1ll));
    return rec(0, 0, n, x, y, z);
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n), z(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> z[i];

    cout << solve(n, x, y, z) << endl;
    return 0;
}
#endif