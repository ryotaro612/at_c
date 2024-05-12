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
  ll l, r;
  cin >> l >> r;
  vector<pair<ll, ll>> res;
  while (l < r) {
    dbg(l, r);
    ll i = 0, j = l;
    for (ll k = 0; k <= 60; k++) {
      if (l % (1ll << k) == 0) {
        ll cand_j = l / (1ll << k);
        if ((1ll << k) * (cand_j + 1ll) <= r) {
          i = k;
          j = cand_j;
        }
      }
    }
    dbg(i, j);
    res.push_back({(1ll << i) * j, (1ll << i) * (j + 1ll)});
    l = (1ll << i) * (j + 1ll);
  }
  cout << res.size() << endl;
  for (auto &[a, b] : res) {
    cout << a << " " << b << endl;
  }

  return 0;
}
