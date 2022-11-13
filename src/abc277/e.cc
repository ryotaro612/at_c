#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <queue>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> uv(m), vv(m), av(m);
  vector<vector<pair<int, int>>> g(n * 2);
  rep(i, m) {
    cin >> uv[i] >> vv[i] >> av[i];
    uv[i]--;
    vv[i]--;
    if (av[i]) {
      g[uv[i]].push_back({vv[i], 1});
      g[vv[i]].push_back({uv[i], 1});
    } else {
      g[uv[i] + n].push_back({vv[i] + n, 1});
      g[vv[i] + n].push_back({uv[i] + n, 1});
    }
  }
  vector<int> sv(k);
  rep(i, k) {
    cin >> sv[i];
    sv[i]--;
    g[sv[i]].push_back({sv[i] + n, 0});
    g[sv[i] + n].push_back({sv[i], 0});
  }
  const ll inf = 1000000000000000ll;
  vector<ll> d(n * 2, inf);
  d[0] = 0ll;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      que;
  que.push({d[0], 0});
  while (que.size()) {
    auto [dist, node] = que.top();
    que.pop();
    if (d[node] < dist)
      continue;

    for (auto neighbor : g[node]) {
      ll cand = dist + neighbor.second;
      if (cand < d[neighbor.first]) {
        d[neighbor.first] = cand;
        que.push({d[neighbor.first], neighbor.first});
      }
    }
  }
  ll result = min(d[n - 1], d[n * 2 - 1]);

  if (inf <= result)
    cout << -1 << endl;
  else
    cout << result << endl;

  return 0;
}
#endif
