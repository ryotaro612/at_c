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
int main() {

  vector<pair<ll, ll>> xy;
  for (ll a = 0; a < 10ll; a++) {
    for (ll b = 0; b < 10ll; b++) {
      for (ll c = 0; c < 10ll; c++) {
        xy.push_back({2 * a + 101 * b, 101 * b + 1013 * c});
      }
    }
  }

  cout << xy.size() << endl;
  for (auto [x, y] : xy) {
    cout << x << " " << y << endl;
  }
  // set<ll> a, b, c, d;
  // for (auto [x, y] : xy) {
  //   a.insert(y);
  //   b.insert(x - y);
  //   c.insert(x);
  //   d.insert(x + y);
  // }
  // cout << a.size() << " " << b.size() << " " << c.size() << " " << d.size()
  //      << endl;

  return 0;
}
