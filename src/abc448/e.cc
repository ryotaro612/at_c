#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
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

ll pow_mod(ll x, ll n, ll mod) {
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
int main() {
  int k, m;
  cin >> k >> m;
  vector<ll> cv(k), lv(k);
  rep(i, k) cin >> cv[i] >> lv[i];

  ll mod = 10007ll * m;
  // pow10[0] = 10; pow10[1] = 10^2, pow10[2] = 10^4...

  vector<ll> pow10(30), pow1(30);
  pow10[0] = 10;
  for (int i = 1; i < 30; i++) {
    pow10[i] = pow10[i - 1] * pow10[i - 1] % mod;
  }
  pow1[0] = 1;
  for (int i = 1; i < 30; i++) {
    pow1[i] = (pow10[i - 1] * pow1[i - 1] % mod + pow1[i - 1]) % mod;
  }
  ll res = 0, dst = 0;
  for (int i = k - 1; i >= 0; i--) {
    ll temp = cv[i] * pow_mod(10, dst, mod) % mod;

    ll temp2 = 0;
    for (int j = 29; j >= 0; j--) {
      if (lv[i] & (1 << j)) {
        temp2 = (temp2 * pow10[j] % mod + pow1[j]) % mod;
      }
    }
    res += temp * temp2 % mod;
    res %= mod;
    dst += lv[i];
  }

  res /= m;
  cout << res << endl;

  return 0;
}
