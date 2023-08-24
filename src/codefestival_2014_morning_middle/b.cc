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
  int n, m;
  cin >> n >> m;
  vector<int> xv(n), yv(n), av(m);
  rep(i, n) cin >> xv[i] >> yv[i];
  rep(i, m) cin >> av[i];

  sort(begin(av), end(av));
  vector<pair<int, int>> xy(n);
  rep(i, n) xy[i] = {xv[i], yv[i]};
  sort(begin(xy), end(xy));

  int res = 0;
  int i = 0;
  multiset<pair<int, int>> yx;
  for (auto a : av) {
    for (; i < n;) {
      auto [x, y] = xy[i];
      if (x <= a) {
        yx.insert({y, x});
        i++;
      } else // a < x
        break;
    }
    while (yx.size()) {
      auto iter = begin(yx);
      auto [y, x] = *iter;
      yx.erase(iter);
      if (a <= y) {
        res++;
        break;
      }
    }
  }

  cout << res << endl;
  return 0;
}
