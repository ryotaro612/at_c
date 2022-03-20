// #ifndef ONLINE_JUDGE
// #define _GLIBCXX_DEBUG
// #endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll solve(ll n, ll m, ll k, ll s, ll t, ll x, vector<int> &uv, vector<int> &vv) {
  ll MOD = 998244353ll;
  s--;
  t--;
  x--;
  vector<vector<int>> g(n);
  rep(i, m) {
    uv[i]--;
    vv[i]--;
    g[uv[i]].push_back(vv[i]);
    g[vv[i]].push_back(uv[i]);
  }
  vector<vector<vector<ll>>> dp(2001,
                                vector<vector<ll>>(2001, vector<ll>(2, 0ll)));
  // dp[i回目][場所][xは偶数]
  dp[0][s][0] = 1ll;
  for (int i = 1; i <= k; i++) {
    rep(j, n) {
      for (int neighbor : g[j]) {
        if (j == x) {
          dp[i][j][0] += dp[i - 1][neighbor][1];
          dp[i][j][0] %= MOD;
          dp[i][j][1] += dp[i - 1][neighbor][0];
          dp[i][j][1] %= MOD;
        } else {
          dp[i][j][0] += dp[i - 1][neighbor][0];
          dp[i][j][0] %= MOD;
          dp[i][j][1] += dp[i - 1][neighbor][1];
          dp[i][j][1] %= MOD;
        }
      }
    }
  }
  return dp[k][t][0];
}
#ifdef ONLINE_JUDGE
int main() {
  ll n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  vector<int> uv(m), vv(m);
  rep(i, m) { cin >> uv[i] >> vv[i]; }
  cout << solve(n, m, k, s, t, x, uv, vv) << endl;
  return 0;
}
#endif
