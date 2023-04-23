#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  int k;
  cin >> k;
  vector<vector<int>> dist(n, vector<int>(n, -1));
  vector<int> pv(n), dv(n);
  string res(n, '1');
  rep(i, k) {
    cin >> pv[i] >> dv[i];
    pv[i]--;
    dist[pv[i]][pv[i]] = 0;
    queue<int> que;
    que.push(pv[i]);
    while (que.size()) {
      int node = que.front();
      que.pop();
      for (auto neighbor : g[node]) {
        if (dist[pv[i]][neighbor] == -1) {
          dist[pv[i]][neighbor] = dist[pv[i]][node] + 1;
          que.push(neighbor);
        }
      }
    }
    rep(j, n) {
      if (dist[pv[i]][j] < dv[i])
        res[j] = '0';
    }
  }
  // rep(i, n) {
  //   cout << i << "-> ";
  //   rep(j, n) { cout << dist[i][j] << " "; }
  //   cout << endl;
  // }
  rep(i, k) {
    bool ok = false;
    rep(j, n) {
      if (dist[pv[i]][j] == dv[i] && res[j] == '1')
        ok = true;
    }
    if (ok == false) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n" << res << endl;
  return 0;
}
#endif
