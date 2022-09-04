#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll solve(int n, int m, vector<ll> &av, vector<int> &uv, vector<int> &vv) {
  vector<set<int>> g(n);
  rep(i, m) {
    g[--uv[i]].insert(--vv[i]);
    g[vv[i]].insert(uv[i]);
  }
  vector<ll> costs(n);
  rep(i, n) {
    for (int other : g[i]) {
      costs[i] += av[other];
    }
  }
  set<pair<ll, int>> order;
  rep(i, n) { order.insert({costs[i], i}); }
  ll result = 0ll;
  rep(i, n) {
    // 消す頂点
    pair<ll, int> a = *order.begin();
    order.erase(a);
    int node = a.second;
    // cout << "erase " << node + 1 << endl;
    result = max(result, costs[node]);
    costs[node] = 0ll;
    set<int> connect_nodes = g[node];
    g[node] = set<int>();

    for (int neighbor : connect_nodes) {
      order.erase({costs[neighbor], neighbor});
      costs[neighbor] -= av[node];
      order.insert({costs[neighbor], neighbor});
      g[neighbor].erase(node);
    }
  }
  return result;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<int> uv(m), vv(m);
  rep(i, m) cin >> uv[i] >> vv[i];
  cout << solve(n, m, av, uv, vv) << endl;
  return 0;
}
#endif
