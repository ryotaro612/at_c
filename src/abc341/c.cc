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
  int h, w, n;
  string t;
  cin >> h >> w >> n >> t;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  map<char, pair<int, int>> dir = {
      {'U', {-1, 0}}, {'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}};
  int res = 0;
  rep(r, h) {
    rep(c, w) {
      if (grid[r][c] == '#')
        continue;
      int i = r, j = c;
      for (auto a : t) {
        i += dir[a].first;
        j += dir[a].second;
        if (!(0 <= i && i < h && 0 <= j && j < w) || grid[i][j] == '#')
          break;
      }
      if (0 <= i && i < h && 0 <= j && j < w && grid[i][j] == '.') {
        res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
