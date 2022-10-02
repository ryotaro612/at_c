#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  x--;
  y--;
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }

  queue<pair<int, int>> que;
  vector<int> d(n, 1 << 30);
  d[x] = 0;
  que.push({0, x});
  while (que.size()) {
    pair<int, int> p = que.front();
    que.pop();
    int dist = p.first;
    int node = p.second;

    if (d[node] < dist)
      continue;

    for (auto e : g[node]) {
      if (dist + 1 < d[e]) {
        d[e] = dist + 1;
        que.push({dist + 1, e});
      }
    }
  }
  // cout << "doge" << endl;
  // rep(i, n) { cout << i << " - > " << d[i] << endl; }
  vector<int> res = {y + 1};
  while (res.back() != x + 1) {
    for (auto e : g[res.back() - 1]) {
      if (d[e] == d[res.back() - 1] - 1) {
        res.push_back(e + 1);
      }
    }
  }
  reverse(res.begin(), res.end());
  rep(i, res.size()) {
    cout << res[i];
    if (i == (int)res.size() - 1)
      cout << endl;
    else
      cout << " ";
  }

  return 0;
}
//#endif
