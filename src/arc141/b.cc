#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
const ll MOD = 998244353ll;

ll solve(ll n, ll m) {
  if (n > 60)
    return 0ll;

  vector<vector<ll>> dp(60, vector<ll>(60, 0ll));
  // 2^60よりちいさいのは、1 - 1<<60-1の間
  for (ll i = 0; i < 60ll; i++) {
    if (((1ll << (i + 1ll)) - 1ll) <= m) {
      dp[0][i] += 1ll << i;
      dp[0][i] %= MOD;
    } else if ((1ll << i) <= m) {
      dp[0][i] += m - (1ll << i) + 1ll;
      dp[0][i] %= MOD;
    }
  }

  for (ll i = 1ll; i < 60ll; i++) {
    for (ll j = 0ll; j < 60ll; j++) {
      for (ll k = 0ll; k < j; k++) {
        dp[i][j] += (dp[0][j] * dp[i - 1][k]) % MOD;
        dp[i][j] %= MOD;
      }
    }
  }

  ll res = 0ll;
  for (int i = 0; i < 60; i++) {
    res += dp[n - 1][i];
    res %= MOD;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, m;
  cin >> n >> m;
  cout << solve(n, m) << endl;
  return 0;
}
#endif
