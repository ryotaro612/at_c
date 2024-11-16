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
  int n;
  cin >> n;
  vector<string> grid(n);
  rep(i, n) { cin >> grid[i]; }
  vector<string> res(n, string(n, ' '));
  rep(r, n) {
	rep(c, n) {
	  int times = min({r, c, n-1-r, n-1-c});
	  vector<pair<int, int>> pos = {{r, c}, {c, n-1-r}, {n-1-r, n-1-c}, {n-1-c, r}};
	  int pos_i = (times + 1) % 4;
	  res[pos[pos_i].first][pos[pos_i].second] = grid[r][c];
	}
  }

  rep(i, n) cout << res[i] << endl;
  return 0;
}
