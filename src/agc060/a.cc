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
const ll mod = 998244353ll;
Mod<mod> dp[5001][26][26];

ll count() {
  ll res = 0ll;
  rep(i, 26) {
    rep(j, 26) {
      rep(k, 26) {
        rep(l, 26) {
          if (!(i == j || j == k || i == k || j == l || k == l))
            res++;
        }
      }
    }
  }
  cout << res << endl;
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s;
  cin >> n >> s;
  if (s[0] == '?') {
    if (s[1] == '?') {
      rep(i, 26) {
        rep(j, 26) {
          if (i != j)
            dp[1][i][j] = 1;
        }
      }
    } else {
      rep(i, 26) {
        if (s[1] - 'a' != i)
          dp[1][s[1] - 'a'][i] = 1;
      }
    }
  } else {
    if (s[1] == '?') {
      rep(i, 26) {
        if (s[0] - 'a' != i)
          dp[1][i][s[0] - 'a'] = 1;
      }
    } else if (s[1] - 'a' != s[0] - 'a')
      dp[1][s[1] - 'a'][s[0] - 'a'] = 1;
  }

  for (int i = 2; i < n; i++) {
    if (s[i] == '?') {
      rep(j, 26) {
        rep(k, 26) {
          rep(l, 26) {
            if (j != l && j != k && k != l) {
              dp[i][j][k] += dp[i - 1][k][l];
            }
          }
        }
      }
    } else {
      rep(j, 26) {
        rep(k, 26) {
          int c = s[i] - 'a';
          if (c != j && c != k && j != k)
            dp[i][c][j] += dp[i - 1][j][k];
        }
      }
    }
  }
  Mod<mod> res;
  rep(i, 26) {
    rep(j, 26) { res += dp[n - 1][i][j]; }
  }
  cout << res << endl;
  return 0;
}
#endif
