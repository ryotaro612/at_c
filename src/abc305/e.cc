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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  // cout << "doge" << endl;
  priority_queue<pair<int, int>> que;
  vector<int> d(n, -1);

  rep(i, k) {
    int p, h;
    cin >> p >> h;
    d[--p] = h;
    que.push({h, p});
  }
  // cout << "doge2" << endl;
  while (que.size()) {
    auto [h, node] = que.top();
    que.pop();
    if (d[node] < h)
      continue;
    for (int ne : g[node]) {
      if (h >= 1 && d[ne] < h - 1) {
        d[ne] = h - 1;
        que.push({h - 1, ne});
      }
    }
  }
  vector<int> res;
  // cout << "doge3" << endl;
  rep(i, n) {
    if (d[i] >= 0)
      res.push_back(i + 1);
  }
  cout << res.size() << endl;
  rep(i, res.size()) { cout << res[i] << " \n"[int(res.size()) - 1 == i]; }

  return 0;
}
#endif
