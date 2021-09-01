#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353ll;

ll solve(ll n, ll m, ll k, vector<ll> u, vector<ll> v) {
    vector<set<int>> ng(n);
    for(int i = 0; i < m; i++) {
        ng[--u[i]].insert(--v[i]);
        ng[v[i]].insert(u[i]);
    }
    for(int i = 0; i < n; i++)
        ng[i].insert(i);

    vector<vector<ll>> dp(k + 1, vector<ll>(n, 0ll));
    dp[0][0] = 1ll;
    for(int i = 1; i <= k; i++) {
        ll sum = 0ll;
        for(int j = 0; j < n; j++) {
            sum += dp[i - 1][j];
            sum %= MOD;
        }
        for(int j = 0; j < n; j++) {
            dp[i][j] = sum;

            for(auto node : ng[j]) {
                dp[i][j] -= dp[i - 1][node];
                if(dp[i][j] < 0)
                    dp[i][j] += MOD;
            }
        }
    }
    return dp[k][0];
}

#ifndef _debug
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> u(m), v(m);
    for(ll i = 0ll; i < m; i++)
        cin >> u[i] >> v[i];

    cout << solve(n, m, k, u, v) << endl;
    return 0;
}
#endif