#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353ll;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

long long modinv(ll a) {
  long long b = MOD, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= MOD;
  if (u < 0)
    u += MOD;
  return u;
}

/ #ifdef ONLINE_JUDGE int main() {
  int n;
  ll p;
  cin >> n >> p;
  vector<ll> dp(n + 1);
  dp[0] = 0ll;
  dp[1] = 1ll;
  dp[2] = 1ll * p % MOD * modinv(100ll) % MOD +
          2ll * (100ll - p) % MOD * modinv(100ll) % MOD;

  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i - 2] + 1ll) % MOD * p % MOD * modinv(100ll) % MOD;
    dp[i] += (dp[i - 1] + 1ll) % MOD * (100ll - p) % MOD * modinv(100ll) % MOD;
    dp[i] %= MOD;
  }
  cout << dp[n] << endl;
  return 0;
}
#endif
