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

const ll mod = 998244353ll;

ll mypow(ll x, ll n) {
  ll res = 1ll;
  while (n) {
    if (n & 1) {
      res *= x;
      res %= mod;
    }
    n >>= 1;
    x *= x;
    x %= mod;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, m, k, res = 0ll;
  cin >> n >> m >> k;
  if (n == 1) {
    cout << mypow(k, m) << endl;
    return 0;
  } else if (m == 1) {
    cout << mypow(k, n) << endl;
    return 0;
  }
  for (ll i = 1ll; i <= k; i++) {
    ll row = mypow(i, n) - mypow(i - 1ll, n);
    if (row < 0)
      row += mod;
    ll col = mypow(k - i + 1ll, m);
    res += row * col % mod;
    res %= mod;
  }
  cout << res << endl;

  return 0;
}
#endif
