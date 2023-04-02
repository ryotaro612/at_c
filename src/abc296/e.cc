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
  vector<int> av(n);
  vector<int> indeg(n, 0);
  rep(i, n) {
    cin >> av[i];
    indeg[--av[i]]++;
  }
  queue<int> que;
  rep(i, n) {
    if (indeg[i] == 0)
      que.push(i);
  }
  // rep(i, n) { cout << indeg[i] << " "; }
  // cout << endl;
  while (que.size()) {
    int node = que.front();
    que.pop();
    indeg[av[node]]--;
    if (indeg[av[node]] == 0) {
      que.push(av[node]);
    }
  }
  // rep(i, n) { cout << indeg[i] << " "; }
  // cout << endl;
  int res = 0;
  rep(i, n) {
    if (indeg[i])
      res++;
  }

  cout << res << endl;
  return 0;
}
#endif
