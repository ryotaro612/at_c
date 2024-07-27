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
  int h, w, r, c;
  cin >> h >> w >> r >> c;
  r--;
  c--;
  vector<string> grid(h);
  rep(i, h) { cin >> grid[i]; }
  string x;
  cin >> x;
  map<char, pair<int, int>> mp;
  mp['U'] = {-1, 0};
  mp['R'] = {0, 1};
  mp['D'] = {1, 0};
  mp['L'] = {0, -1};
  for (auto xe : x) {
    int n_r = r + mp[xe].first, n_c = c + mp[xe].second;
    if (0 <= n_r && n_r < h && 0 <= n_c && n_c < w && grid[n_r][n_c] == '.') {
      r = n_r;
      c = n_c;
    }
  }
  cout << r + 1 << " " << c + 1 << endl;
  return 0;
}
