#include <algorithm>
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

void init(int r, int c, vector<vector<ll>> &grid, vector<vector<bool>> &exist) {
  ll z = grid[r][c] + exist[r][c];
  vector<pair<int, int>> neighbors = {{
                                          r - 1,
                                          c,
                                      },
                                      {r, c + 1},
                                      {r + 1, c},
                                      {r, c - 1}};
  int n = grid.size();
  for (auto [n_r, n_c] : neighbors) {
    if (0 <= n_r && n_r < n && 0 <= n_c && n_c < n && z < grid[n_r][n_c]) {
      grid[n_r][n_c] = z;
      init(n_r, n_c, grid, exist);
    }
  }
}
int main() {
  int n;
  cin >> n;
  vector<vector<ll>> grid(n, vector<ll>(n, 1e18));
  vector<vector<bool>> exist(n, vector<bool>(n, true));
  rep(r, n) {
    rep(c, n) {
      vector<ll> a = {r, c, n - 1 - r, n - 1 - c};
      grid[r][c] = *min_element(begin(a), end(a));
    }
  }

  ll res = 0;
  dbg(grid);
  rep(i, n * n) {
    ll p;
    cin >> p;
    p--;
    int r = p / n;
    int c = p % n;
    res += grid[r][c];
    exist[r][c] = false;
    init(r, c, grid, exist);
  }
  cout << res << endl;

  return 0;
}
