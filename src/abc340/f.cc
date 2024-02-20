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

pair<ll, ll> ext_gcd(ll a, ll b) {
  if (a < 0) {
    auto [x, y] = ext_gcd(-a, b);
    return {-x, y};
  }
  if (b < 0) {
    auto [x, y] = ext_gcd(a, -b);
    return {x, -y};
  }
  if (a < b) {
    auto [x, y] = ext_gcd(b, a);
    return {y, x};
  }
  if (b == 0)
    return {1, 0};
  auto [x, y] = ext_gcd(b, a % b);
  return {y, x - a / b * y};
}
bool is_ok(ll a) { return -1e18 <= a && a <= 1e18; }
bool is_ok(ll a, ll b) { return is_ok(a) && is_ok(b); }

bool output(ll a, ll b) {
  if (is_ok(a, b)) {
    cout << a << " " << b << endl;
    return true;
  }
  return false;
}
int main() {
  ll x, y;
  cin >> x >> y;
  auto [c, d] = ext_gcd(x, -y);
  ll g = gcd(x, -y);
  dbg(x, -y, c, d);
  if (g == 1ll) {
    if (output(d * 2ll, c * 2ll)) {
      return 0;
    }
    if (output(d * -2ll, c * -2ll)) {
      return 0;
    }
  } else if (g == 2ll) {
    if (output(d, c)) {
      return 0;
    }
    if (output(d * -1ll, c * -1ll)) {
      return 0;
    }
  } else if (g % 2ll == 0) {
    ll div = g / 2ll;
    if (c % div == 0 && d % div == 0) {
      if (output(d / div, c / div))
        return 0;
      if (output(-d / div, -c / div))
        return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
