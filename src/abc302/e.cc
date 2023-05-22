#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
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
  int n, q;
  cin >> n >> q;
  vector<set<int>> g(n);
  int res = n;
  rep(_, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      if (g[u].size() == 0)
        res--;
      if (g[v].size() == 0)
        res--;
      g[u].insert(v);
      g[v].insert(u);
      cout << res << endl;
    } else {
      int v;
      cin >> v;
      v--;
      for (auto o : g[v]) {
        g[o].erase(v);
        if (g[o].size() == 0)
          res++;
      }
      if (g[v].size()) {
        g[v] = set<int>();
        res++;
      }
      cout << res << endl;
    }
  }
  return 0;
}
#endif
