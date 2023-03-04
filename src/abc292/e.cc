#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <unordered_set>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

void traverse(int node, unordered_set<int> &passed, vector<vector<int>> &g) {
  for (auto neighbor : g[node]) {
    if (passed.find(neighbor) == passed.end()) {
      passed.insert(neighbor);
      traverse(neighbor, passed, g);
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
  }
  int res = 0;
  rep(i, n) {
    unordered_set<int> passed = {i};
    traverse(i, passed, g);
    res += passed.size() - 1 - g[i].size();
  }
  cout << res << endl;

  return 0;
}
#endif
