#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <vector>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

int solve() {
  int n, m;
  cin >> n >> m;
  vector<int> cv(n);
  rep(i, n) cin >> cv[i];
  vector<vector<vector<int>>> g(n, vector<vector<int>>(2, vector<int>()));
  rep(j, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u][cv[v]].push_back(v);
    g[v][cv[u]].push_back(u);
  }
  if (cv[0] == cv[n - 1]) {
    return -1;
  }
  const ll inf = 100000000000ll;
  vector<vector<ll>> d(n, vector<ll>(n, inf));
  d[0][n - 1] = 0;
  queue<pair<ll, pair<int, int>>> que;
  que.push({0, {0, n - 1}});
  while (que.size()) {
    auto item = que.front();
    que.pop();
    ll cost = item.first;
    int takahashi = item.second.first, aoki = item.second.second;
    if (d[takahashi][aoki] < cost)
      continue;
    vector<pair<vector<int>, vector<int>>> neighbors = {
        {g[takahashi][0], g[aoki][1]}, {g[takahashi][1], g[aoki][0]}};
    for (auto &[takahashi_neighbors, aoki_neighbors] : neighbors) {
      for (auto &takahashi_neighbor : takahashi_neighbors) {
        for (auto &aoki_neighbor : aoki_neighbors) {
          if (cost + 1 < d[takahashi_neighbor][aoki_neighbor]) {
            d[takahashi_neighbor][aoki_neighbor] = cost + 1ll;
            que.push({cost + 1ll, {takahashi_neighbor, aoki_neighbor}});
          }
        }
      }
    }
  }
  if (d[n - 1][0] < inf)
    return d[n - 1][0];
  else
    return -1;
}

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  rep(i, t) { cout << solve() << endl; }
  return 0;
}
#endif
