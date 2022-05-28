#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
const ll MOD = 998244353ll;

ll solve(ll n, ll m, ll k) {
  // MはAの値の上限
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0ll));
  for (int i = 1; i <= m; i++) {
    dp[1][i] = 1ll;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (k == 0) {
        dp[i + 1][1] += dp[i][j];
        continue;
      }
      if (j - k >= 1) {
        dp[i + 1][1] += dp[i][j];
        dp[i + 1][1] %= MOD;
        if (j - k + 1 <= m) {
          dp[i + 1][j - k + 1] -= dp[i][j];
          if (dp[i + 1][j - k + 1] < 0ll)
            dp[i + 1][j - k + 1] += MOD;
        }
      }
      if (j + k <= m) {
        dp[i + 1][j + k] += dp[i][j];
        dp[i + 1][j + k] %= MOD;
      }
    }
    for (int j = 1; j <= m; j++) {
      dp[i + 1][j] += dp[i + 1][j - 1];
      dp[i + 1][j] %= MOD;
    }
  }
  // 下はOK
  ll res = 0ll;
  for (int i = 1; i <= m; i++) {
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
