#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> g(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].insert(v);
    g[v].insert(u);
  }
  int res = 0;
  for (int a = 0; a < n - 2; a++) {
    for (int b = a + 1; b < n - 1; b++) {
      for (int c = b + 1; c < n; c++) {
        if (g[a].find(b) != g[a].end() && g[b].find(c) != g[b].end() &&
            g[c].find(a) != g[c].end()) {
          res++;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
#endif
