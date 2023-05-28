#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<set<int>> g(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    g[--u].insert(--v);
    g[v].insert(u);
  }
  set<int> roots;
  vector<int> res;
  rep(i, n) {
    if (g[i].size() == 1) {
      roots.insert(*g[i].begin());
    }
  }
  while (roots.size()) {
    int root = *roots.begin();
    roots.erase(root);

    res.push_back(g[root].size());
    // cout << "root " << root << endl;
    set<int> bounds;
    for (int child : g[root]) {
      // cout << "child " << child << endl;
      for (int b : g[child]) {
        if (b == root) {
          continue;
        }
        bounds.insert(b);
        // cout << " b  " << b << endl;
        if (g[b].count(child))
          g[b].erase(child);
      }
    }
    // cout << "clearing" << endl;
    g[root].clear();
    for (int child : g[root]) {
      g[child].clear();
    }

    for (int bound : bounds) {
      // cout << "bound " << bound << endl;
      if (g[bound].size() == 1) {
        roots.insert(*g[bound].begin());
      }
    }
  }
  sort(res.begin(), res.end());
  rep(i, res.size()) { cout << res[i] << " \n"[i == int(res.size()) - 1]; }
  return 0;
}
#endif
