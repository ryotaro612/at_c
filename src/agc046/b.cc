#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const ll mod = 998244353ll;
ll dp[3001][3001];
int a, b;
ll solve(ll c, ll d) {
  if (dp[c][d] != -1)
    return dp[c][d];
  if (c == a) {
    return dp[c][d] = c * solve(c, d - 1) % mod;
  } else if (d == b) {
    return dp[c][d] = b * solve(c - 1, d) % mod;
  }
  dp[c][d] = 0ll;
  dp[c][d] += solve(c - 1, d) * d % mod;
  dp[c][d] %= mod;
  dp[c][d] += solve(c, d - 1) * c % mod;
  dp[c][d] %= mod;
  ll temp = solve(c - 1, d - 1) * (c - 1ll) % mod * (d - 1ll) % mod;
  dp[c][d] -= temp;
  if (dp[c][d] < 0)
    dp[c][d] += mod;

  return dp[c][d];
}
#ifdef ONLINE_JUDGE
int main() {
  int c, d;
  cin >> a >> b >> c >> d;
  rep(i, 3001) { rep(j, 3001) dp[i][j] = -1; }
  dp[a][b] = 1ll;
  cout << solve(c, d) << endl;
  // rep(i, c + 1) {
  //   rep(j, d + 1) { cout << dp[i][j] << " \n"[j == d]; }
  // }
  return 0;
}
#endif
