#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353ll;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
const ll MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k) {
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll fact(ll n) {
  ll res = 1ll;
  for (ll i = 1ll; i <= n; i++) {
    res *= i;
    res %= MOD;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n;
  cin >> n;
  COMinit();
  ll res = fact(n * n);
  ll diff = n * n % MOD;
  diff *= COM(n * n, 2ll * n - 1ll);
  diff %= MOD;
  diff *= fact(n - 1ll);
  diff %= MOD;
  diff *= fact(n - 1ll);
  diff %= MOD;
  diff *= fact((n - 1ll) * (n - 1ll) % MOD);
  diff %= MOD;
  res = (res + MOD - diff) % MOD;
  cout << res << endl;
  return 0;
}
#endif
