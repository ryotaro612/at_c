#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <iomanip>
#include <limits>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ld solve(int s, int v, int n, int m, vector<ld> &xv, vector<ld> &yv,
         vector<vector<ld>> &dp) {
  if (dp[s][v] >= 0)
    return dp[s][v];

  if (((s & ((1 << n) - 1)) == ((1 << n) - 1)) && (v == 0)) {
    return dp[s][v] = 0;
  }

  ld speed = 1L;
  for (int i = 0; i < m; i++) {
    if (s >> (i + n) & 1)
      speed *= 2L;
  }
  ld res = numeric_limits<ld>::max();
  rep(i, n + m) {
    if ((s & (1 << i)) == 0) {
      ld dist = sqrt((xv[i] - xv[v]) * (xv[i] - xv[v]) +
                     (yv[i] - yv[v]) * (yv[i] - yv[v]));
      res = min(solve(s | (1 << i), i, n, m, xv, yv, dp) + dist / speed, res);
    }
  }
  return dp[s][v] = res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  n++;
  vector<ld> xv(n + m + 1), yv(n + m + 1);
  xv[0] = yv[0] = 0ll;
  rep(i, n + m) cin >> xv[i + 1] >> yv[i + 1];

  vector<vector<ld>> dp(1 << (n + m), vector<ld>(n + m, -1));
  // ld res = numeric_limits<ld>::max();
  // rep(i, 1 << (n + m)) {
  //   if ((((1 << n) - 1) & i) == ((1 << n) - 1)) {
  //     res = min(solve(i, 0, n, m, xv, yv, dp), res);
  //   }
  // }

  cout << fixed << setprecision(12) << solve(0, 0, n, m, xv, yv, dp) << endl;
  return 0;
}
#endif
