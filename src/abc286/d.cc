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
  int n, x;
  cin >> n >> x;
  vector<int> av(n), bv(n);
  rep(i, n) cin >> av[i] >> bv[i];

  vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
  dp[0][0] = true;
  rep(i, n) {
    rep(j, x + 1) {
      rep(k, bv[i] + 1) {
        if (j + k * av[i] <= x) {
          dp[i + 1][j + k * av[i]] = dp[i][j] || dp[i + 1][j + k * av[i]];
        }
      }
    }
  }
  // rep(i, n + 1) {
  //   rep(j, x + 1) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }
  if (dp[n][x])
    cout << "Yes";
  else
    cout << "No";
  cout << endl;

  return 0;
}
#endif
