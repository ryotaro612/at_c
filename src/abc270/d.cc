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
  int n, k;
  cin >> n >> k;
  vector<int> av(k);
  rep(i, k) cin >> av[i];
  // dp[i][j] 山にi個の石があり、j個の石をとりのぞくときのベスト
  vector<pair<int, int>> dp(n + 1, {-100000, 0});
  dp[0] = {0, -1};
  rep(i, n + 1) {
    rep(j, k) {
      if (i - av[j] < 0)
        continue;
      else if (i == av[j]) {
        dp[i] = max(dp[i], {av[j], j});
      } else {
        auto [n_stones, idx] = dp[i - av[j]];

        dp[i] = max(dp[i], {av[j] + dp[i - av[j] - av[idx]].first, j});
      }
    }
  }
  cout << dp[n].first << endl;

  return 0;
}
#endif
