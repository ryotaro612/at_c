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
  int t;
  cin >> t;
  rep(_, t) {
    vector<ll> av(5), pv(5);
    rep(i, 5) cin >> av[i];
    rep(i, 5) cin >> pv[i];
    ll target = 2ll * av[0] + av[1] - av[3] - 2ll * av[4];
    if (target <= 0) {
      cout << 0 << endl;
    } else if (2ll * pv[3] <= pv[4]) {
      cout << pv[3] * target << endl;
    } else {
      ll cost = target / 2ll * pv[4];
      if (target % 2ll) {
        cost += min(pv[3], pv[4]);
      }
      cout << cost << endl;
    }
  }
  return 0;
}
