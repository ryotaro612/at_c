#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void rec(vector<vector<int>> &g, vector<int> &cycle, unordered_set<int> &nodes,
         int node) {
  if (0 <= cycle[node])
    return;
  if (nodes.find(node) != nodes.end()) {
    cycle[node] = 1;
    return;
  }
  if (static_cast<int>(g[node].size()) == 0) {
    cycle[node] = 0;
    return;
  }
  nodes.insert(node);
  int result = 0;
  for (int neighbor : g[node]) {
    rec(g, cycle, nodes, neighbor);
    if (cycle[neighbor])
      result = 1;
  }
  cycle[node] = result;
  nodes.erase(node);
}

int solve(int n, int m, vector<int> &uv, vector<int> &vv) {
  vector<vector<int>> g(n);
  rep(i, m) { g[--uv[i]].push_back(--vv[i]); }
  vector<int> cycle(n, -1);
  rep(i, n) {
    if (cycle[i] < 0) {
      unordered_set<int> nodes;
      rec(g, cycle, nodes, i);
    }
  }
  int res = 0;
  rep(i, n) if (0 < cycle[i]) res++;
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> uv(m), vv(m);
  rep(i, m) { cin >> uv[i] >> vv[i]; }
  cout << solve(n, m, uv, vv) << endl;
  return 0;
}
#endif
