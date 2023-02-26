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
const ll MOD = 998244353ll;
#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n), bv(n);
  rep(i, n) { cin >> av[i] >> bv[i]; }
  vector<vector<ll>> dp(n, vector<ll>(2, 0));
  dp[0][0] = dp[0][1] = 1;
  for (int i = 1; i < n; i++) {
    if (av[i] != av[i - 1]) {
      dp[i][0] += dp[i - 1][0];
      dp[i][0] %= MOD;
    }
    if (av[i] != bv[i - 1]) {
      dp[i][0] += dp[i - 1][1];
      dp[i][0] %= MOD;
    }
    if (bv[i] != av[i - 1]) {
      dp[i][1] += dp[i - 1][0];
      dp[i][1] %= MOD;
    }
    if (bv[i] != bv[i - 1]) {
      dp[i][1] += dp[i - 1][1];
      dp[i][1] %= MOD;
    }
  }
  // rep(i, n) { cout << dp[i][0] << " " << dp[i][1] << endl; }
  cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
  return 0;
}
#endif
