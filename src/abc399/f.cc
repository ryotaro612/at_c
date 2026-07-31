#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
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

static const ll MOD = 998244353ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k;
  cin >> n >> k;
  vector<Mod<MOD>> av(n);
  rep(i, n) {
    ll a;
    cin >> a;
    av[i] = Mod<MOD>(a);
  }

  auto combi = ModCombi<MOD>(11);

  vector<vector<vector<Mod<MOD>>>> dp(
      n, vector<vector<Mod<MOD>>>(3, vector<Mod<MOD>>(k + 1, 0)));

  // 1つもみてない。しきりもない。間のを選んでもない。
  dp[0][0][0] = 1;
  rep(i, n) {
    dbg(i);
    // ここが間違い
    if (i) {
      rep(j, k) {
        for (int h = 1; h + j <= k; h++) {
          // このへん
          dp[i][1][j + h] += dp[i - 1][1][j] * av[i].pow(h) * combi.c(k - j, h);
        }
        // dp[i][1][j + 1] += av[i].pow(j + 1) * combi.c(k, j + 1);
      }
    }
    rep(j, k + 1) { dp[i][1][j] += combi.c(k, j) * av[i].pow(j); }

    rep(j, k + 1) { dp[i][2][j] += dp[i][1][j]; }

    rep(h, 3) {
      rep(j, k + 1) {
        if (i < n - 1) {
          dp[i + 1][h][j] += dp[i][h][j];
        }
      }
    }
  }

  cout << dp[n - 1][2][k] << endl;

  return 0;
}
