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

bool rec(int node, vector<int> &res, vector<map<int, int>> &g) {
  for (auto [neighbor, w] : g[node]) {
    if (res[neighbor] != -1)
      continue;
    if (res[node] == w) {
      if (w == 1)
        res[neighbor] = 2;
      else
        res[neighbor] = 1;
    } else {
      res[neighbor] = w;
    }
    rec(neighbor, res, g);
  }
  return true;
}

//#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> uv(m), vv(m), cv(m);
  vector<map<int, int>> g(n);
  rep(i, m) {
    cin >> uv[i] >> vv[i] >> cv[i];
    g[--uv[i]][--vv[i]] = cv[i];
    g[vv[i]][uv[i]] = cv[i];
  }
  vector<int> res(n, -1);
  res[0] = 1;
  if (rec(0, res, g)) {
    rep(i, n) cout << res[i] << endl;
  } else {
    assert(false);
    cout << "No" << endl;
  }

  return 0;
}
//#endif
