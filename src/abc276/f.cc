#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
const ll MOD = 998244353ll;

long long modinv(long long a) {
  ll m = MOD;
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

void add(int i, int v, vector<int> &bit) {
  int n = bit.size();
  while (i < n) {
    bit[i] += v;
    bit[i] %= MOD;
    i += i & -i;
  }
}

ll sum(int i, vector<int> &bit) {
  ll result = 0;
  while (i > 0) {
    result += bit[i];
    result %= MOD;
    i -= i & -i;
  }
  return result;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<ll> dp(n + 1, 0ll);

  vector<int> bit_count(200001, 0);
  vector<int> bit_sum(200001, 0);

  for (ll i = 0; i < n; i++) {
    // ll temp = av[i] + av[i] % MOD;
    ll temp = sum(av[i], bit_count) * av[i] % MOD;
    ll sub = sum(200000, bit_sum) - sum(av[i], bit_sum);
    if (sub < 0)
      sub += MOD;
    temp += sub;
    temp %= MOD;
    temp *= 2ll;
    temp %= MOD;
    dp[i + 1] = ((dp[i] + temp) % MOD + av[i]) % MOD;
    cout << dp[i + 1] * modinv(i + 1ll) % MOD * modinv(i + 1ll) % MOD << endl;
    add(av[i], 1, bit_count);
    add(av[i], av[i], bit_sum);
  }
  return 0;
}
#endif
