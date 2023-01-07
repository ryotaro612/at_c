/**
3
cbaabc
abc
0
==
 */
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
const ll B = 100000007;

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a) {
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

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  string t;
  cin >> t;
  vector<ll> base(n, 1);
  for (int i = 1; i < n; i++) {
    base[i] = B * base[i - 1];
    base[i] %= MOD;
  }
  ll h = 0, h_rev = 0;
  rep(i, n) {
    h += (ll)t[2 * n - 1 - i] * base[i] % MOD;
    h %= MOD;
    h_rev += (ll)t[i] * base[i] % MOD;
    h_rev %= MOD;
  }
  rep(i, n + 1) {
    if (h == h_rev) {
      string res(t.begin() + i, t.begin() + i + n);
      reverse(res.begin(), res.end());
      cout << res << endl << i << endl;
      return 0;
    } else if (i < n) {
      h -= (ll)t[n + i] * base[n - 1 - i] % MOD;
      if (h < 0)
        h += MOD;
      h += (ll)t[i] * base[n - 1 - i] % MOD;
      h %= MOD;
      h_rev -= (ll)t[i];
      if (h_rev < 0)
        h_rev += MOD;
      h_rev = h_rev * modinv(B) % MOD;
      h_rev += (ll)t[n + i] * base[n - 1] % MOD;
      h_rev %= MOD;
    }
  }
  cout << -1 << endl;
  return 0;
}
#endif
