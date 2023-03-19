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
  int n;
  cin >> n;
  vector<int> av(n - 1), bv(n - 1), cv(n);
  vector<vector<int>> g(n);
  vector<int> rev(n, 0);
  rep(i, n - 1) {
    cin >> av[i] >> bv[i];
    g[--av[i]].push_back(--bv[i]);
    g[bv[i]].push_back(av[i]);
    rev[av[i]]++;
    rev[bv[i]]++;
  }
  priority_queue<int, vector<int>, greater<int>> c_que;
  rep(i, n) {
    cin >> cv[i];
    c_que.push(cv[i]);
  }
  queue<int> que;
  rep(i, n) {
    if (rev[i] <= 1)
      que.push(i);
  }
  vector<int> res(n, -1);
  while (que.size()) {
    int node = que.front();
    que.pop();
    if (res[node] != -1)
      continue;
    res[node] = c_que.top();
    c_que.pop();
    rev[node]--;
    // cout << node << " res " << res[node] << endl;
    for (int neighbor : g[node]) {
      if (--rev[neighbor] <= 1 && res[neighbor] == -1) {
        // cout << " find " << neighbor << endl;
        que.push(neighbor);
      }
    }
  }
  int cost = 0;
  rep(i, n - 1) cost += min(res[av[i]], res[bv[i]]);
  cout << cost << endl;
  rep(i, n) cout << res[i] << " \n"[i == n - 1];

  return 0;
}
#endif
