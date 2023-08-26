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
  int h, w;
  cin >> h >> w;
  vector<string> grid(h), alter(h);
  int start_r = 0, start_c = 0, goal_r = 0, goal_c = 0;
  rep(i, h) {
    cin >> grid[i];
    alter[i] = string(grid[i]);
    rep(j, w) {
      if (grid[i][j] == 'S') {
        start_r = i;
        start_c = j;
      } else if (grid[i][j] == 'G') {
        goal_r = i;
        goal_c = j;
      }
    }
  }
  dbg("doge");
  rep(r, h) {
    rep(c, w) {
      if (c && (grid[r][c - 1] == '>' || alter[r][c - 1] == '>') &&
          grid[r][c] == '.')
        alter[r][c] = '>';
    }
    for (int c = w - 1; c >= 0; c--) {
      if (c < w - 1 && (grid[r][c + 1] == '<' || alter[r][c + 1] == '<') &&
          grid[r][c] == '.')
        alter[r][c] = '<';
    }
  }
  rep(c, w) {
    rep(r, h) {
      if (r && (grid[r - 1][c] == 'v' || alter[r - 1][c] == 'v') &&
          grid[r][c] == '.')
        alter[r][c] = 'v';
    }
    for (int r = h - 1; r >= 0; r--) {
      if (r < h - 1 && (grid[r + 1][c] == '^' || alter[r + 1][c] == '^') &&
          grid[r][c] == '.')
        alter[r][c] = '^';
    }
  }
  rep(i, h) { dbg(alter[i]); }
  ll inf = 1000000000ll;
  vector<vector<ll>> d(h, vector<ll>(w, inf));
  queue<pair<int, int>> que;
  que.push({start_r, start_c});
  d[start_r][start_c] = 0;
  while (que.size()) {
    auto [r, c] = que.front();
    que.pop();

    vector<pair<int, int>> neighbors = {
        {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1}};
    for (auto [n_r, n_c] : neighbors) {
      if (0 <= n_r && n_r < h && 0 <= n_c && n_c < w &&
          (alter[n_r][n_c] == '.' || alter[n_r][n_c] == 'G') && d[n_r][n_c] > d[r][c] + 1) {
        d[n_r][n_c] = d[r][c] + 1;
        que.push({n_r, n_c});
      }
    }
  }
  dbg(d);
    
  if (d[goal_r][goal_c] == inf)
    cout << -1 << endl;
  else
    cout << d[goal_r][goal_c] << endl;

  return 0;
}
