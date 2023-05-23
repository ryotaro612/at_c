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
  vector<vector<int>> sm(n);
  vector<set<pair<int, int>>> g(n + m);

  rep(i, n) {
    int a;
    cin >> a;
    sm[i] = vector<int>(a);
    rep(j, a) {
      int b;
      cin >> b;
      sm[i][j] = --b;
      g[b].insert({1, i + m});
      g[i + m].insert({1, b});
    }
  }
  // rep(i, n + m) {
  //   cout << i << " -> ";
  //   for (auto [_, p] : g[i]) {
  //     cout << p << ", ";
  //   }
  //   cout << endl;
  // }
  vector<int> d(n + m, 1 << 28);
  d[0] = 0;
  queue<int> que;
  que.push(0);
  while (que.size()) {
    int node = que.front();
    que.pop();
    for (auto [path, neighbor] : g[node]) {
      if (path + d[node] < d[neighbor]) {
        d[neighbor] = path + d[node];
        que.push(neighbor);
      }
    }
  }
  if (d[m - 1] < (1 << 28)) {
    cout << d[m - 1] / 2 - 1;
  } else
    cout << "-1";
  cout << endl;

  return 0;
}
#endif
