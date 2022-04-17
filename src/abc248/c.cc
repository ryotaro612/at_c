#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll MOD = 998244353ll;

ll solve(int n, int m, int k) {
  // dp[i][j] 長さiで値がjの数
  vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0ll));
  dp[0][0] = 1ll;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int a = 0; a <= k; a++) {
        if (a - j >= 0) {
          dp[i][a] += dp[i - 1][a - j];
          dp[i][a] %= MOD;
        }
      }
    }
  }
  // rep(i, n + 1) {
  //   rep(j, k + 1) { cout << "(" << i << "," << j << "->" << dp[i][j] << endl;
  //   }
  // }

  ll res = 0ll;
  rep(i, k + 1) {
    res += dp[n][i];
    res %= MOD;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  cout << solve(n, m, k) << endl;
  return 0;
}
#endif
