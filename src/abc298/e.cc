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
ll mod = 998244353ll;
long long modinv(long long a, long long m = mod) {
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

vector<vector<ll>> calc(int start, int n, int die) {
  vector<vector<ll>> res(n + 1, vector<ll>(n + 1, 0));
  res[0][start] = 1ll;
  ll prob = modinv(die);
  for (int round = 0; round < n; round++) {
    for (int pos = 1; pos <= n; pos++) {
      for (int deme = 1; deme <= die; deme++) {
        res[round + 1][min(n, pos + deme)] += prob * res[round][pos] % mod;
        res[round + 1][min(n, pos + deme)] %= mod;
      }
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  // 0 tugi takahasi, 1 tugi aoki
  vector<vector<vector<ll>>> dp(n + 1,
                                vector<vector<ll>>(n + 1, vector<ll>(2, 0)));

  for (int pos = 1; pos < n; pos++) {
    for (int turn = 0; turn < 2; turn++) {
      dp[n][pos][turn] = 1ll;
      dp[pos][n][turn] = 0;
    }
  }
  for (int t_pos = n - 1; t_pos > 0; t_pos--) {
    for (int a_pos = n - 1; a_pos > 0; a_pos--) {
      for (int deme = 1; deme <= p; deme++) {
        dp[t_pos][a_pos][0] +=
            dp[min(n, deme + t_pos)][a_pos][1] * modinv(p) % mod;
        dp[t_pos][a_pos][0] %= mod;
      }
      for (int deme = 1; deme <= q; deme++) {
        dp[t_pos][a_pos][1] +=
            dp[t_pos][min(n, a_pos + deme)][0] * modinv(q) % mod;
        dp[t_pos][a_pos][1] %= mod;
      }
    }
  }

  cout << dp[a][b][0] << endl;
  return 0;
}
#endif
// int main() {
//   int n, a, b, p, q;
//   cin >> n >> a >> b >> p >> q;
//   vector<vector<ll>> taka = calc(a, n, p), aoki = calc(b, n, q);
//   ll res = 0ll;
//   // rep(i, 101) { cout << i << " " << taka[i][n] << endl; }

//   for (int round = 1; round <= n - a + 1; round++) {
//     ll taka_prob = 1ll - taka[round - 1][n];
//     if (taka_prob < 0ll)
//       taka_prob += mod;
//     taka_prob *= taka[round][n];
//     taka_prob %= mod;

//     ll aoki_prob = 1ll - aoki[round - 1][n];
//     if (aoki_prob < 0ll)
//       aoki_prob += mod;
//     cout << round << " " << taka_prob << " , " << taka_prob * aoki_prob % mod
//          << endl;
//     res += taka_prob * aoki_prob % mod;
//     res %= mod;
//   }
//   cout << res << endl;
//   return 0;
// }
