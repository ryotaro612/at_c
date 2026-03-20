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

ll sub2(ll a, ll b) {
  if (b < a)
    return 0;

  if (a == b) {
    return a % 2 ? 0 : 1;
  }
  if (a % 2)
    a++;
  if (b % 2)
    b--;
  return (b - a) / 2ll + 1ll;
}

// xは絶対値
ll sub(ll d, ll u, ll x) {
  if (d > u)
    return 0;

  if (d == u)
    return max(abs(d), x) % 2 ? 0 : 1;
  // 以降は d < u
  if (u < 0) {
    return sub(-u, -d, x);
  }
  if (d <= 0) {
    return sub(0, -d, x) + sub(1ll, u, x);
  }
  // 以降は0 <= d <= u
  // xと比較する
  if (x <= d) {
    return sub2(d, u);
  }
  if (x <= u) {
    ll temp = 0;
    if (x % 2 == 0) {
      temp = x - d + 1ll;
    }

    return temp + sub2(x + 1ll, u);
  }

  if (x % 2)
    return 0;
  return u - d + 1ll;
}

int main() {

  ll l, r, d, u, res = 0;
  cin >> l >> r >> d >> u;
  for (ll x = l; x <= r; x++) {
    // d to u
    ll temp = sub(d, u, abs(x));
    res += temp;
    dbg(x, temp);
  }
  cout << res << endl;
  return 0;
}
