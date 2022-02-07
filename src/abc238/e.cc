#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string solve(int n, int q, vector<int> &lv, vector<int> &rv) {
  n++;
  int inf = 1 << 30;
  vector<vector<int>> g(n);
  rep(i, q) {
    lv[i]--;
    g[lv[i]].push_back(rv[i]);
    g[rv[i]].push_back(lv[i]);
  }
  queue<pair<int, int>> que;
  vector<int> d(n, inf);
  d[0] = 0;
  que.push({0, 0});
  while (!que.empty()) {
    int node = que.front().first;
    int cost = que.front().second;
    que.pop();
    if (d[node] < cost)
      continue;
    for (auto next : g[node]) {
      if (cost + 1 < d[next]) {
        d[next] = cost + 1;
        que.push({next, d[next]});
      }
    }
  }

  if (d[n - 1] < inf)
    return "Yes";
  else
    return "No";
}

#ifdef ONLINE_JUDGE
int main() {
  int n, q;
  cin >> n >> q;
  vector<int> lv(q), rv(q);
  rep(i, q) cin >> lv[i] >> rv[i];
  cout << solve(n, q, lv, rv) << endl;
  return 0;
}
#endif
