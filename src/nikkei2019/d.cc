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
  vector<int> av(n - 1 + m), bv(n - 1 + m);
  vector<vector<int>> g(n);
  vector<int> rev(n, 0);
  rep(i, n - 1 + m) {
    cin >> av[i] >> bv[i];
    g[--av[i]].push_back(--bv[i]);
    rev[bv[i]]++;
  }
  queue<int> que;
  vector<int> res(n);
  rep(i, n) {
    if (rev[i] == 0) {
      que.push(i);
      res[i] = 0;
    }
  }
  assert(que.size() == 1);
  while (que.size()) {
    int node = que.front();
    que.pop();
    for (int neighbor : g[node]) {
      rev[neighbor]--;
      if (rev[neighbor] == 0) {
        res[neighbor] = node + 1;
        que.push(neighbor);
      }
    }
  }
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
