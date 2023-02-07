#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <functional>
#include <queue>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      que;
  vector<vector<int>> d(h, vector<int>(w, 1 << 28));
  int goal_r, goal_c;
  rep(i, h) {
    rep(j, w) {
      if (grid[i][j] == 's') {
        d[i][j] = 0;
        que.push({0, {i, j}});
      }
      if (grid[i][j] == 'g') {
        goal_r = i;
        goal_c = j;
      }
    }
  }
  int mx = 500 * 500 + 1;
  while (que.size()) {
    auto [cost, pos] = que.top();
    que.pop();
    auto [row, col] = pos;
    if (d[row][col] < cost)
      continue;

    vector<pair<int, int>> neighbors = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto [d_row, d_col] : neighbors) {
      int next_row = row + d_row, next_col = col + d_col;

      if (0 <= next_row && next_row < h && 0 <= next_col && next_col < w) {
        int d_cost;
        if (grid[next_row][next_col] != '#')
          d_cost = 1;
        else
          d_cost = mx;

        if (cost + d_cost < d[next_row][next_col]) {
          d[next_row][next_col] = cost + d_cost;
          que.push({cost + d_cost, {next_row, next_col}});
        }
      }
    }
  }

  if (d[goal_r][goal_c] < mx * 3)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
  return 0;
}
#endif
