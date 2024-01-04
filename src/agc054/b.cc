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
const ll MOD = 998244353ll;

vector<Mod<MOD>> count(vector<int> &wv, int target) {
  int n = wv.size();
  vector<vector<vector<Mod<MOD>>>> dp(
      n + 1, vector<vector<Mod<MOD>>>(target + 1, vector<Mod<MOD>>(n, 0)));
  dp[n][0][0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= target; j++) {
      for (int l = 0; l < n; l++) {
        if (j >= wv[i] && l >= 1)
          dp[i][j][l] += dp[i + 1][j - wv[i]][l - 1];
        dp[i][j][l] += dp[i + 1][j][l];
      }
    }
  }
  vector<Mod<MOD>> res(n, 0);
  rep(i, n) { res[i] = dp[0][target][i]; }
  return res;
}
Mod<MOD> fact(int k) {
  if (k == 0)
    return 1;
  Mod<MOD> res = k;
  return res * fact(k - 1);
}
int main() {
  int n;
  cin >> n;
  vector<int> wv(n);
  ll sum = 0;
  rep(i, n) {
    cin >> wv[i];
    sum += wv[i];
  }
  if (sum % 2) {
    cout << 0 << endl;
    return 0;
  }
  vector<Mod<MOD>> patterns = count(wv, sum / 2ll);
  dbg(sum / 2ll);
  // 2 8 4 7 5 3 1 2 4 1 2 5 4 3 3 8 1 7 8 2
  dbg(patterns);
  Mod<MOD> res = 0;
  for (int i = 1; i < n; i++) {
    res += patterns[i] * fact(i) * fact(n - i);
    // if (i == n - i) {
    //   Mod<MOD> snd = patterns[i] - 1ll;
    //   res += patterns[i] * snd * fact(i) * fact(i);
    // } else {
    //   res += patterns[i] * fact(i) * patterns[n - i] * fact(n - i);
    // }
  }
  cout << res << endl;

  return 0;
}
