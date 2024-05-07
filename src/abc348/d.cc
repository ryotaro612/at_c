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

vector<int> calc_dist(int start_r, int start_c, vector<string> &grid) {
  int h = grid.size();
  int w = grid[0].size();
  vector<int> d(h * w, 1 << 28);
  int cell = start_r * w + start_c;
  d[cell] = 0;
  queue<int> que;
  que.push(cell);
  while (que.size()) {
    cell = que.front();
    que.pop();
    int r = cell / w, c = cell % w;
    vector<pair<int, int>> neighbors = {
        {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1}};
    for (auto &[n_r, n_c] : neighbors) {
      int neighbor = n_r * w + n_c;
      if (0 <= n_r && n_r < h && 0 <= n_c && n_c < w && grid[n_r][n_c] != '#' &&
          d[neighbor] > d[cell] + 1) {
        d[neighbor] = d[cell] + 1;
        que.push(neighbor);
      }
    }
  }
  return d;
}

int main() {
  int h, w, n;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  cin >> n;
  vector<int> rv(n), cv(n), ev(n);
  queue<int> que;
  vector<bool> visit(n, false);
  int goal;
  rep(i, n) {
    cin >> rv[i] >> cv[i] >> ev[i];
    rv[i]--;
    cv[i]--;
    if (grid[rv[i]][cv[i]] == 'S') {
      que.push(i);
      visit[i] = true;
    }
  }
  rep(r, h) {
    rep(c, w) {
      if (grid[r][c] == 'T')
        goal = r * w + c;
    }
  }

  while (que.size()) {
    int medicine_i = que.front();
    que.pop();
    vector<int> d = calc_dist(rv[medicine_i], cv[medicine_i], grid);

    if (d[goal] <= ev[medicine_i]) {
      cout << "Yes\n";
      return 0;
    }

    rep(i, n) {
      if (d[rv[i] * w + cv[i]] <= ev[medicine_i] && !visit[i]) {
        visit[i] = true;
        que.push(i);
        dbg(medicine_i, i);
      }
    }
  }
  cout << "No\n";
  return 0;
}
