#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }

  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1000000000000000ll));
  rep(i, n + 1) { dp[i][0] = 0ll; }

  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      dp[i][j] = max(dp[i - 1][j - 1] + av[i - 1] * j, dp[i - 1][j]);
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
#endif
