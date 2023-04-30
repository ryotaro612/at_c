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
  friend Mod<P> operator*(const Mod<P> &lhs, const Mod<P> &rhs) {
    return Mod<P>(lhs.v * rhs.v % P);
  }
  friend Mod<P> operator/(const Mod<P> &lhs, const Mod<P> &rhs) {
    ll b = P, u = 1, v = 0, a = rhs.v;
    while (b) {
      ll t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    u %= P;
    if (u < 0)
      u += P;
    return lhs.v * u % P;
  }
  Mod<P> &operator=(const ll &number) {
    v = number;
    return *this;
  }
  Mod<P> &operator+=(const Mod &rhs) {
    v += rhs.v;
    v %= P;
    return *this;
  }
  Mod<P> &operator-=(const Mod &rhs) {
    v -= rhs.v;
    if (v < 0)
      v += P;
    return *this;
  }
  Mod<P> &operator*=(const Mod &rhs) {
    v *= rhs.v;
    v %= P;
    return *this;
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

  Mod<P> pow(ll n) {
    ll res = 1ll;
    ll x = v;
    while (n) {
      if (n & 1) {
        res *= x;
        res %= P;
      }
      n >>= 1;
      x *= x;
      x %= P;
    }
    return res;
  }
};

bool is_zero(ll n) {
  while (true) {
    bool ok = false;
    for (auto e : {2, 3, 5}) {
      if (n % e == 0) {
        n /= e;
        ok = true;
      }
    }
    if (!ok)
      break;
  }
  return n != 1;
}

const ll mod = 998244353ll;
Mod<mod> probs[61][64][39][27];
// #ifdef ONLINE_JUDGE
int main() {
  ll n;
  cin >> n;
  if (is_zero(n)) {
    cout << "0\n";
    return 0;
  }
  map<int, int> primes;
  while (n > 1) {
    for (auto e : {2, 3, 5}) {
      if (n % e == 0) {
        primes[e]++;
        n /= e;
      }
    }
  }
  probs[0][0][0][0] = 1;
  Mod<mod> p = 1 / Mod<mod>(5);
  rep(i, 60) {
    rep(a, 60) {
      rep(b, 38) {
        rep(c, 26) {
          probs[i + 1][a + 1][b][c] += probs[i][a][b][c] * p;

          probs[i + 1][a][b + 1][c] += probs[i][a][b][c] * p;

          probs[i + 1][a + 2][b][c] += probs[i][a][b][c] * p;

          probs[i + 1][a][b][c + 1] += probs[i][a][b][c] * p;

          probs[i + 1][a + 1][b + 1][c] += probs[i][a][b][c] * p;
        }
      }
    }
  }
  Mod<mod> res = 0ll;
  // cout << "doge" << endl;
  rep(i, 61) { res += probs[i][primes[2]][primes[3]][primes[5]]; }
  // cout << primes[2] << " " << primes[3] << " " << primes[5] << endl;
  cout << res << endl;
  return 0;
}
// #endif

/**

 */
