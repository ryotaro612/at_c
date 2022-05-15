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
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  //
  const ll inf = 10e15;
  vector<vector<ll>> dp(n, vector<ll>(2, inf));
  dp[0][1] = av[0];
  for (int i = 1; i < n; i++) {
    if (i == n - 1) {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = av[i] + dp[i - 1][0];
    } else {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = av[i] + min(dp[i - 1][1], dp[i - 1][0]);
    }
  }
  ll res = min(dp[n - 1][0], dp[n - 1][1]);
  dp = vector(n, vector<ll>(2, inf));
  dp[0][0] = 0ll;
  for (int i = 1; i < n; i++) {
    if (i == n - 1) {
      dp[i][0] = inf;
      dp[i][1] = av[i] + min(dp[i - 1][0], dp[i - 1][1]);
    } else {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = av[i] + min(dp[i - 1][1], dp[i - 1][0]);
    }
  }
  res = min(res, min(dp[n - 1][1], dp[n - 1][0]));
  cout << res << endl;
  return 0;
}
#endif
