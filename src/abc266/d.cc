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
  vector<int> tv(n), xv(n);
  vector<ll> av(n);
  rep(i, n) { cin >> tv[i] >> xv[i] >> av[i]; }
  map<int, map<int, ll>> sunuke;
  rep(i, n) { sunuke[tv[i]][xv[i]] += av[i]; }

  ll last_time = *max_element(tv.begin(), tv.end());
  vector<vector<ll>> dp(last_time + 1ll, vector<ll>(5, -1000000000000000ll));
  dp[0][0] = 0ll;
  for (int i = 1; i <= last_time; i++) {
    rep(j, 5) {
      if (j == 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][1]) + sunuke[i][j];
      } else if (j == 4) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][3]) + sunuke[i][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i - 1][j + 1])) +
                   sunuke[i][j];
      }
    }
  }
  // rep(i, last_time + 1) {
  //   rep(j, 5) { cout << i << " " << j << " -> " << dp[i][j] << endl; }
  // }
  cout << *max_element(dp[last_time].begin(), dp[last_time].end()) << endl;
  return 0;
}
#endif
