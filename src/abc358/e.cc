#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__       \
       << " = ";                                                               \
  debug_(__VA_ARGS__);
#else
#define dbg(...)
#endif
template <typename Os, typename... Ts>
Os &operator<<(Os &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Os, typename T>
typename enable_if<is_same<Os, ostream>::value, Os &>::type
operator<<(Os &os, const T &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

void debug_() { cerr << "\e[39m" << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cerr << H << " ";
  debug_(T...);
}
template <ll P> class Mod {
public:
  Mod() : v(0) {}
  Mod(ll v_) : v((v_ % P + P) % P) {}
  ll get() { return v; }
  Mod<P> operator*(Mod<P> &a) { return Mod<P>(v * a.v % P); }
  Mod<P> operator*(ll &b) { return Mod<P>(v * b % P); }
  friend Mod<P> operator+(const Mod<P> &lhs, const ll &rhs) {
    return Mod((lhs.v + rhs) % P);
  }
  friend Mod<P> operator+(const Mod<P> &lhs, const Mod<P> &rhs) {
    return Mod((lhs.v + rhs.v) % P);
  }
  friend Mod<P> operator-(const Mod<P> &lhs, const Mod<P> &rhs) {
    ll res = lhs.v - rhs.v;
    if (res < 0)
      res += P;
    return Mod<P>(res);
  }
  Mod<P> operator-() { return (-v + P) % P; }
  friend Mod<P> operator*(const Mod<P> &lhs, const Mod<P> &rhs) {
    return Mod<P>(lhs.v * rhs.v % P);
  }
  friend Mod<P> operator/(const Mod<P> &lhs, const Mod<P> &rhs) {
    ll b = P, u = 1, vv = 0, a = rhs.v;
    while (b) {
      ll t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * vv;
      swap(u, vv);
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
  friend bool operator==(const Mod<P> &lhs, const Mod<P> &rhs) {
    return lhs.v == rhs.v;
  }
  friend ostream &operator<<(ostream &os, const Mod<P> &mod) {
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

private:
  ll v;
};

template <ll P> class ModCombi {
public:
  /** [0, right)内のi, jについてiCjを計算できる。
   */
  ModCombi(int right) {
    fact.resize(right);
    inv_fact.resize(right);
    for (ll i = 0; i < right; i++) {
      if (i == 0) {
        fact[0] = 1;
        inv_fact[0] = modinv(1);
      } else {
        fact[i] = i * fact[i - 1] % P;
        inv_fact[i] = modinv(i) * inv_fact[i - 1] % P;
      }
    }
  }
  /**
   * nCr
   */
  ll c(int n, int r) {
    if (n < r)
      return 0;
    return fact[n] * inv_fact[n - r] % P * inv_fact[r] % P;
  }

private:
  vector<ll> fact, inv_fact;

private:
  ll modinv(ll a) { return (P + extgcd(a, P).first % P) % P; }
  pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0)
      return {1, 0};
    auto [x, y] = extgcd(b, a % b);
    return {y, x - a / b * y};
  }
};

const ll MOD = 998244353ll;
int main() {
  ll k;
  cin >> k;
  vector<ll> cv(26);
  rep(i, 26) {
    ll c;
    cin >> c;
    cv[i] = c;
  }
  ModCombi<MOD> combi(100000ll);
  vector<vector<Mod<MOD>>> dp(26, vector<Mod<MOD>>(k + 1, 0));

  for (int i = 0; i <= min(k, cv[0]); i++) {
    dp[0][i] = 1;
  }
  for (int i = 1; i < 26; i++) {

    for (int j = 0; j <= k; j++) {
	  dp[i][j] += dp[i-1][j];
      for (int l = 1; l <= cv[i] && j + l <= k; l++) {
        dp[i][j+l] += dp[i-1][j] * combi.c(j+l, l);
      }
    }
	dbg(i, dp[i]);
  }


  Mod<MOD> res = 0;
  for (int i = 1; i <= k; i++) {
	dbg(dp[25][i]);
    res += dp[25][i];
  }
  cout << res << endl;

  return 0;
}
