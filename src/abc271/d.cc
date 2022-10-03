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
  int n, s;
  cin >> n >> s;
  vector<int> av(n), bv(n);
  rep(i, n) cin >> av[i] >> bv[i];

  vector<vector<bool>> dp(n + 1, vector<bool>(10001, false));
  dp[0][0] = true;

  for (int i = 1; i <= n; i++) {
    rep(j, s + 1) {
      if (dp[i - 1][j]) {
        dp[i][j + av[i - 1]] = dp[i][j + bv[i - 1]] = true;
      }
    }
  }
  if (dp[n][s]) {
    cout << "Yes" << endl;
    vector<char> res;
    for (int i = n, current = s; i > 0; i--) {
      if (current - av[i - 1] >= 0 && dp[i - 1][current - av[i - 1]]) {
        res.push_back('H');
        current -= av[i - 1];
      } else if (current - bv[i - 1] >= 0 && dp[i - 1][current - bv[i - 1]]) {
        res.push_back('T');
        current -= bv[i - 1];
      } else
        assert(false);
    }
    reverse(res.begin(), res.end());
    rep(i, res.size()) { cout << res[i]; }
  } else
    cout << "No";
  cout << endl;

  return 0;
}
#endif
