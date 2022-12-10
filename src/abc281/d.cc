#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
ll dp[101][101][101];
#ifdef ONLINE_JUDGE
int main() {
  ll n, k, d;
  cin >> n >> k >> d;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  rep(i, 101) {
    rep(j, 101) {
      rep(l, 101) { dp[i][j][l] = -1000000000000000ll; }
    }
  }
  dp[0][0][0] = 0ll;

  rep(i, n) {
    rep(j, k + 1) {
      rep(l, d) {
        dp[i + 1][j][l] = max(dp[i][j][l], dp[i + 1][j][l]);
        if (j < k) {
          int dd = (dp[i][j][l] + av[i]) % d;
          dp[i + 1][j + 1][dd] = max(dp[i + 1][j + 1][dd], av[i] + dp[i][j][l]);
        }
      }
    }
  }
  if (dp[n][k][0] < 0)
    cout << -1 << endl;
  else
    cout << dp[n][k][0] << endl;
  return 0;
}
#endif
