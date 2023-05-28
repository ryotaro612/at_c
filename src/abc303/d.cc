#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ll x, y, z;
  string s;
  cin >> x >> y >> z >> s;
  int n = s.size();
  vector<vector<ll>> dp(s.size() + 1, vector<ll>(2, 10e15));
  dp[0][0] = 0;
  dp[0][1] = z;
  rep(i, s.size()) {
    if (s[i] == 'a') {
      dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + x);
      dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + y);
    } else {
      dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + x);
      dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + y);
    }
    dp[i + 1][0] = min(dp[i + 1][0], dp[i + 1][1] + z);
    dp[i + 1][1] = min(dp[i + 1][1], dp[i + 1][0] + z);
  }
  // rep(i, n + 1) { cout << dp[i][0] << " "; }
  // cout << endl;
  // rep(i, n + 1) { cout << dp[i][1] << " "; }
  // cout << endl;
  cout << min(dp[n][0], dp[n][1]) << endl;
  return 0;
}
#endif
