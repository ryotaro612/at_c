#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }
  vector<vector<ll>> dp(n + 1, vector<ll>(n, -100000000000000ll));
  dp[0][0] = 0ll;

  vector<ll> bv(n + 1, 0);
  for (int i = 1; i < as_int(bv.size()); i++) {
    if (i % 2)
      bv[i] += av[i / 2] + bv[i - 1];
    else
      bv[i] += av[i / 2 - 1] + bv[i - 1];
  }
  // rep(i, bv.size()) { cout << bv[i] << " "; }
  // cout << endl;

  rep(i, n - 1) {

    rep(j, n - 1) {
      dp[i + 1][j + 1] = max(dp[i][j], dp[i + 1][j + 1]);
      dp[i + 1][0] = max(dp[i][j] + bv[j], dp[i + 1][0]);
    }
  }
  ll res = 0ll;
  rep(i, n) { res = max(dp[n - 1][i] + bv[i], res); }
  cout << res << endl;

  return 0;
}
#endif
