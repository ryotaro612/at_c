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
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> xy;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    xy.insert({--x, --y});
  }
  m = xy.size();

  vector<int> pointed(n, 0);
  vector<vector<int>> g(n, vector<int>());
  for (auto [x, y] : xy) {
    pointed[y]++;
    g[x].push_back(y);
  }
  // rep(i, n) { cout << " pointer" << pointed[i] << endl; }
  queue<int> que;
  rep(i, n) {
    if (pointed[i] == 0)
      que.push(i);
  }
  vector<int> order;
  // cout << que.size() << endl;
  while (que.size()) {
    if (que.size() != 1) {
      // cout << que.front() << "!!" << endl;
      cout << "No" << endl;
      return 0;
    }
    int node = que.front();
    que.pop();
    order.push_back(node);
    for (auto dest : g[node]) {
      pointed[dest]--;
      if (pointed[dest] == 0) {
        que.push(dest);
      }
    }
  }
  if (as_int(order.size()) != n) {
    cout << "No" << endl;
    return 0;
  }
  vector<int> res(n);
  rep(i, n) { res[order[i]] = i + 1; }
  cout << "Yes" << endl;
  rep(i, n) { cout << res[i] << " \n"[i == n - 1]; }

  return 0;
}
#endif
