#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <queue>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

struct Edge {
  ll cost;
  int index;
};

vector<int> solve(int n, int m, vector<int> &av, vector<int> &bv,
                  vector<ll> &cv) {
  const ll inf = 10000000000000000ll;
  vector<ll> d(n, inf);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      que;
  vector<vector<pair<Edge, int>>> g(n);
  rep(i, m) {
    g[av[i] - 1].push_back({{cv[i], i + 1}, bv[i] - 1});
    g[bv[i] - 1].push_back({{cv[i], i + 1}, av[i] - 1});
  }
  d[0] = 0ll;
  que.push({0ll, 0});
  while (!que.empty()) {
    pair<ll, int> item = que.top();
    ll cost = item.first;
    int node = item.second;
    que.pop();
    if (d[node] < cost)
      continue;

    for (auto [edge, neighbor] : g[node]) {
      if (d[node] + edge.cost < d[neighbor]) {
        d[neighbor] = d[node] + edge.cost;
        que.push({d[neighbor], neighbor});
      }
    }
  }
  vector<bool> done(n, false);
  queue<int> bfs;
  done[0] = true;
  bfs.push(0);
  vector<int> res;
  while (!bfs.empty()) {
    int node = bfs.front();
    bfs.pop();
    for (auto [edge, neighbor] : g[node]) {
      if (!done[neighbor]) {
        if (d[node] + edge.cost == d[neighbor]) {
          done[neighbor] = true;
          bfs.push(neighbor);
          res.push_back(edge.index);
        }
      }
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> av(m), bv(m);
  vector<ll> cv(m);
  rep(i, m) cin >> av[i] >> bv[i] >> cv[i];
  vector<int> res = solve(n, m, av, bv, cv);
  rep(i, res.size()) {
    cout << res[i];
    if (i < (int)res.size() - 1)
      cout << " ";
    else
      cout << endl;
  }
  return 0;
}
#endif
