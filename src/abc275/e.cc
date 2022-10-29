#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
ll const MOD = 998244353ll;
ll dp[1001][1001];

long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0)
    u += m;
  return u;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  // dp[i][j] i回目のルーレット後にマスjにいる場合の数
  dp[0][0] = 1ll;
  rep(i, k) {
    rep(j, n) {
      for (int a = 1; a <= m; a++) {
        int pos;
        if (j + a <= n) {
          pos = j + a;
        } else {
          pos = n - (j + a - n);
        }
        dp[i + 1][pos] += dp[i][j] * modinv(m, MOD);
        dp[i + 1][pos] %= MOD;
      }
    }
    dp[i + 1][n] += dp[i][n];
    dp[i + 1][n] %= MOD;
  }
  cout << dp[k][n] << endl;

  return 0;
}
#endif
