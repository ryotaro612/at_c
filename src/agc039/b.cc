#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void warshall_floyd(vector<vector<int>> &d) {
  int n = d.size();
  rep(k, n) {
    rep(i, n) {
      rep(j, n) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    }
  }
}

bool is_bipartitle(vector<vector<int>> &g) {

  vector<int> colors(g.size(), -1);
  queue<int> que;
  rep(i, g.size()) {
    if (colors[i] == -1) {
      colors[i] = 0;
      que.push(i);
    }

    while (que.size()) {
      int node = que.front();
      que.pop();
      for (int neighbor : g[node]) {
        if (colors[neighbor] == -1) {
          colors[neighbor] = !colors[node];
          que.push(neighbor);
        } else if (colors[node] == colors[neighbor]) {
          return false;
        }
      }
    }
  }
  return true;
}

// #ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<string> sm(n);

  rep(i, n) { cin >> sm[i]; }
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      if (sm[i][j] == '1') {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  // rep(i, n) {
  //   cout << i << " -> ";
  //   for (auto e : g[i])
  //     cout << e << " ";
  //   cout << endl;
  // }
  if (!is_bipartitle(g)) {
    cout << -1 << endl;
    return 0;
  }
  vector<vector<int>> d(n, vector<int>(n, 1 << 28));
  rep(i, n) {
    d[i][i] = 0;
    for (auto j : g[i]) {
      d[i][j] = d[j][i] = 1;
    }
  }
  warshall_floyd(d);
  int res = 0;

  rep(i, n) {
    rep(j, n) {
      // cout << i << " " << j << "->" << d[i][j] << endl;
      if (d[i][j] < 255)
        res = max(res, d[i][j]);
    }
  }
  cout << res + 1 << endl;
  return 0;
}
// #endif
