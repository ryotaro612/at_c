#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll const MOD = 998244353ll;

ll solve(int n, ll a, ll b, ll c, ll d, ll e, ll f,
         unordered_map<ll, unordered_map<ll, bool>> &obstacles) {
  vector<vector<vector<ll>>> dp = vector<vector<vector<ll>>>(
      n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0ll)));
  dp[0][0][0] = 1ll;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= i - j; k++) {
        ll x = a * j + c * k + e * (i - j - k);
        ll y = b * j + d * k + f * (i - j - k);
        if (obstacles[x][y])
          continue;
        if (0 < j && 0 <= i - 1 - (j - 1) - k) {
          dp[i][j][k] += dp[i - 1][j - 1][k];
          dp[i][j][k] %= MOD;
        }
        if (0 < k && 0 <= (i - 1) - j - (k - 1)) {
          dp[i][j][k] += dp[i - 1][j][k - 1];
          dp[i][j][k] %= MOD;
        }
        if (0 <= (i - 1) - j - k) {
          dp[i][j][k] += dp[i - 1][j][k];
          dp[i][j][k] %= MOD;
        }
      }
    }
  }
  // rep(i, n + 1) {
  //   rep(j, n + 1) {
  //     rep(k, n + 1) {
  //       cout << i << " , " << j << ", " << k << "->" << dp[i][j][k] << endl;
  //     }
  //   }
  // }
  ll res = 0ll;
  rep(i, n + 1) {
    rep(j, n + 1) {
      if (0 <= n - i - j) {
        res += dp[n][i][j];
        res %= MOD;
      }
    }
  }
  return res;
}

//#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  // vector<ll> xv(m), yv(m);
  unordered_map<ll, unordered_map<ll, bool>> obstacles;
  // rep(i, m) obstacles[xv[i]][yv[i]] = true;
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    obstacles[x][y] = true;
    // cin >> xv[i] >> yv[i];
  }
  cout << solve(n, a, b, c, d, e, f, obstacles) << endl;
  return 0;
}
//#endif
