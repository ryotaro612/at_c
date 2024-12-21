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
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--;
  y--;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  string t;
  cin >> t;
  set<pair<int, int>> passed;

  rep(i, h) { dbg(grid[i]); }

  for (auto a : t) {
    dbg(x, y);
    if (a == 'U') {
      if (x && grid[x - 1][y] != '#') {
        x--;
      }
    } else if (a == 'D') {
      if (x < h && grid[x + 1][y] != '#') {
        x++;
      }
    } else if (a == 'L') {
      if (y && grid[x][y - 1] != '#') {
        y--;
      }
    } else {
      if (y < w - 1 && grid[x][y + 1] != '#') {
        y++;
      }
    }
    if (grid[x][y] == '@')
      passed.insert({x, y});
  }
  cout << x + 1 << " " << y + 1 << " " << passed.size() << "\n";
  return 0;
}
