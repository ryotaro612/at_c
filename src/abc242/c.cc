#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll MOD = 998244353ll;
ll solve(int n) {
  vector<vector<ll>> dp(n + 1, vector<ll>(9, 0));
  rep(i, 9) { dp[0][i] = 1; }

  rep(i, n - 1) {
    rep(j, 9) {
      if (0 < j) {
        dp[i + 1][j] += dp[i][j - 1];
        dp[i + 1][j] %= MOD;
      }

      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
      if (j < 8) {
        dp[i + 1][j] += dp[i][j + 1];
        dp[i + 1][j] %= MOD;
      }
    }
  }
  ll res = 0ll;
  rep(i, 9) {
    res += dp[n - 1][i];
    res %= MOD;
  }
  // rep(i, n) {
  //   rep(j, 9) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {

  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
#endif
