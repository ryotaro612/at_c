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
  int n, q;
  cin >> n >> q;
  vector<int> par(n, -1), chd(n, 0);
  rep(i, n - 1) {
    int p;
    cin >> p;
    par[i + 1] = p - 1;
  }
  for (int i = 1; i < n; i++) {
    chd[par[i]]++;
  }
  // cout << " === =" << endl;
  rep(i, q) {
    int m, res = 0;
    cin >> m;
    set<int> vs;
    vector<int> vv(m);
    // cout << "doge" << endl;
    rep(j, m) {
      int v;
      cin >> v;
      v--;
      vv[j] = v;
      vs.insert(v);
    }
    // cout << " foobar " << endl;
    rep(j, m) {
      res += chd[vv[j]];
      if (vs.find(par[vv[j]]) == vs.end()) {
        res++;
      } else {
        res--;
      }
    }
    cout << res << endl;
  }
  return 0;
}
#endif
