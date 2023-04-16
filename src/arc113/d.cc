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

template <ll P> class Mod {
public:
  ll v;
  Mod<P>() : v(0) {}
  Mod<P>(ll v) : v(v % P) {}
  ll get() { return v; }
  Mod<P> operator*(Mod<P> &a) { return Mod<P>(v * a.v % P); }
  Mod<P> operator*(ll &b) { return Mod<P>(v * b % P); }
  friend Mod<P> operator+(const Mod<P> &lhs, const ll &rhs) {
    return Mod(lhs.v + rhs % P);
  }
  friend Mod<P> operator-(const Mod<P> &lhs, const Mod<P> &rhs) {
    ll res = lhs.v - rhs.v;
    if (res < 0)
      res += P;
    return Mod<P>(res);
  }
  friend bool operator<(const Mod<P> &lhs, const int &rhs) {
    return lhs.v < rhs;
  }

  Mod<P> &operator*=(const Mod &rhs) {
    v *= rhs.v;
    v %= P;
    return *this;
  }
  Mod<P> &operator+=(const Mod &rhs) {
    v += rhs.v;
    v %= P;
    return *this;
  }
  Mod<P> &operator=(const ll &number) {
    v = number;
    return this;
  }
  Mod<P> &operator++() {
    v++;
    v %= P;
    return *this;
  }

  friend bool operator==(const Mod<P> &lhs, const int &rhs) {
    return lhs.v == rhs;
  }
  friend ostream &operator<<(ostream &os, Mod<P> &mod) {
    os << mod.v;
    return os;
  }
  friend istream &operator>>(istream &is, Mod<P> &mod) {
    is >> mod.v;
    return is;
  }
};
// template<ll P> inline bool operator==(const Mod<P> &lhs, const int &rhs) {
//   return lhs.v == rhs;
// }

#ifdef ONLINE_JUDGE
int main() {
  Mod<mod> n, m, k, res = 0ll;
  cin >> n >> m >> k;
  if (n == 1) {
    cout << mypow(k.v, m.v) << endl;
    return 0;
  } else if (m == 1) {
    cout << mypow(k.v, n.v) << endl;
    return 0;
  }
  for (ll i = 1ll; i <= k.v; i++) {
    Mod<mod> row = Mod<mod>(mypow(i, n.v)) - Mod<mod>(mypow(i - 1ll, n.v));
    if (row < 0)
      row += mod;
    Mod<mod> col = mypow((k - i + 1ll).v, m.v);
    res += row * col;
  }
  cout << res << endl;

  return 0;
}
#endif
