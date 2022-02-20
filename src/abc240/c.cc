#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string solve(int n, int x, vector<int> &av, vector<int> &bv) {
  vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
  dp[0][0] = true;
  rep(i, n) {
    rep(j, x + 1) {
      if (dp[i][j]) {
        if (j + av[i] <= x)
          dp[i + 1][j + av[i]] = true;
        if (j + bv[i] <= x)
          dp[i + 1][j + bv[i]] = true;
      }
    }
  }
  if (dp[n][x])
    return "Yes";
  else
    return "No";
}

#ifdef ONLINE_JUDGE
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> av(n), bv(n);
  rep(i, n) cin >> av[i] >> bv[i];
  cout << solve(n, x, av, bv) << endl;
  return 0;
}
#endif
