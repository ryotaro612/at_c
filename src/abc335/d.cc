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
  vector<vector<string>> grid(n, vector<string>(n, ""));
  grid[n / 2][n / 2] = "T";
  vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int r = 0, c = 0;
  int pos = 0;
  for (int i = 1; i < n * n; i++) {
    grid[r][c] = to_string(i);
    dbg(r, c, i);
    while (true) {
      int n_r = r + delta[pos].first;
      int n_c = c + delta[pos].second;
      if(i == n*n-1)
	break;
      if (0 <= n_r && n_r < n && 0 <= n_c && n_c < n && grid[n_r][n_c].size() == 0) {
        r = n_r;
        c = n_c;
	dbg("next", r, c);
        break;
      } else {
        pos = (pos + 1) % 4;
      }
    }
  }
  rep(i, n) {
    rep(j, n) {
      cout << grid[i][j] << " \n"[j == n-1];
    }
  }
  return 0;
}
