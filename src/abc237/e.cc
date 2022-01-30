#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll solve(int n, int m, vector<ll> &hv, vector<int> &uv, vector<int> &vv) {
  rep(i, m) {
    uv[i]--;
    vv[i]--;
  }
  vector<vector<pair<ll, int>>> g(n);
  rep(i, m) {
    if (hv[uv[i]] <= hv[vv[i]]) {
      g[vv[i]].push_back({0, uv[i]});
      g[uv[i]].push_back({hv[vv[i]] - hv[uv[i]], vv[i]});

    } else { //  hv[vv[i]] < hv[uv[i]]
      g[vv[i]].push_back({hv[uv[i]] - hv[vv[i]], uv[i]});
      g[uv[i]].push_back({0ll, vv[i]});
    }
  }
  ll inf = 1000000000000ll;
  vector<ll> d(n, inf);
  d[0] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      que;
  que.push({d[0], 0});
  while (!que.empty()) {
    ll cost = que.top().first;
    int node = que.top().second;
    que.pop();

    if (d[node] < cost)
      continue;

    for (int i = 0; i < (int)g[node].size(); i++) {
      pair<ll, int> edge = g[node][i];
      if (d[edge.second] > d[node] + edge.first) {
        d[edge.second] = d[node] + edge.first;
        que.push({d[edge.second], edge.second});
      }
    }
  }
  // rep(i, n) { cout << d[i] << endl; }
  ll res = 0ll;
  rep(i, n) { res = max(hv[0] - (d[i] + hv[i]), res); }

  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> hv(n);
  rep(i, n) cin >> hv[i];
  vector<int> uv(m), vv(m);
  rep(i, m) { cin >> uv[i] >> vv[i]; }
  cout << solve(n, m, hv, uv, vv) << endl;
}
#endif
