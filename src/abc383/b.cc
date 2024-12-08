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
  int h, w, d;
  cin >> h >> w >> d;
  vector<string> grid(h);
  rep(i, h) { cin >> grid[i]; }
  vector<pair<int, int>> vacant;
  rep(r, h) {
    rep(c, w) {
      if (grid[r][c] == '.') {
        vacant.push_back({r, c});
      }
    }
  }
  int res = 0;
  rep(i, vacant.size()) {
    for (int j = i + 1; j < (int)vacant.size(); j++) {
      int cand = 0;
      rep(r, h) {
        rep(c, w) {
          if (grid[r][c] != '.') {
            continue;
          }
          int dist = abs(r - vacant[i].first) + abs(c - vacant[i].second);
          dist =
              min(dist, abs(r - vacant[j].first) + abs(c - vacant[j].second));
          if (dist <= d)
            cand++;
        }
      }
	  res = max(res, cand);
    }
  }
  cout << res << endl;
  return 0;
}
