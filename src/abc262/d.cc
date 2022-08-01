#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
const ll MOD = 998244353ll;

ll solve(ll n, vector<ll> &av) {

  ll res = 0ll;
  for (ll i = 1ll; i <= n; i++) {
    vector<vector<vector<ll>>> dp(
        n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0ll)));
    dp[0][0][0] = 1ll;
    for (ll j = 1ll; j <= n; j++) {
      dp[j][0][0] = 1ll;
      for (int k = 1ll; k <= i; k++) {
        // 全部でi個選ぶ。 j[1,n]番目までにk個選んだ
        for (ll b = 0; b <= n; b++) {
          dp[j][k][b] += dp[j - 1][k][b];
          dp[j][k][b] %= MOD;
          dp[j][k][(b + av[j - 1]) % i] += dp[j - 1][k - 1][b];
          dp[j][k][(b + av[j - 1]) % i] %= MOD;
        }
      }
    }
    res += dp[n][i][0];
    res %= MOD;
  }

  return res;
}
#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, av) << endl;

  return 0;
}
#endif
