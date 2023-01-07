#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int threshold = 1000000;

void count(int pos, int &res, set<int> &passed, vector<vector<int>> &g) {
  res++;
  if (res >= threshold)
    return;
  for (int neighbor : g[pos]) {
    if (passed.find(neighbor) == passed.end()) {
      passed.insert(pos);
      count(neighbor, res, passed, g);
      passed.erase(pos);
    }
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  int res = 0;
  set<int> passed;
  count(0, res, passed, g);
  cout << min(res, threshold) << endl;
  return 0;
}
#endif
