#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
const ll inf = 100000000000000ll;
ll solve(int n, int m, vector<ll> &xv, vector<int> &cv, vector<ll> &yv) {
  // dp[i][j] i回目にカウンタがjのときの最大
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -inf));
  dp[0][0] = 0ll;
  unordered_map<int, ll> bonus;
  rep(i, m) { bonus[cv[i]] = yv[i]; }

  for (int i = 1; i <= n; i++) {
    // 裏
    for (int j = 0; j <= i; j++) {
      dp[i][0] = max(dp[i][0], dp[i - 1][j]);
    }
    // 表
    for (int j = 1; j <= i; j++) {
      ll temp = dp[i - 1][j - 1] + xv[i - 1];
      if (bonus.find(j) != bonus.end()) {
        temp += bonus[j];
      }
      dp[i][j] = max(dp[i][j], temp);
    }
  }
  ll res = 0ll;
  rep(i, n + 1) { res = max(res, dp[n][i]); }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> xv(n);
  rep(i, n) cin >> xv[i];
  vector<int> cv(m);
  vector<ll> yv(m);
  rep(i, m) { cin >> cv[i] >> yv[i]; }
  cout << solve(n, m, xv, cv, yv) << endl;
  return 0;
}
#endif
