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

void traverse(int node, vector<int> &hv, vector<vector<int>> &g,
              set<pair<int, int>> &passed, set<pair<int, int>> &required) {

  if (hv[node]) {
    for (auto path : passed) {
      required.insert(path);
    }
  }
  for (int neighbor : g[node]) {
    pair<int, int> path = {min(node, neighbor), max(node, neighbor)};
    if (passed.find(path) == passed.end()) {
      passed.insert(path);
      traverse(neighbor, hv, g, passed, required);
      passed.erase(path);
    }
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> hv(n);
  rep(i, n) cin >> hv[i];
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  set<pair<int, int>> passed, required;
  traverse(--x, hv, g, passed, required);

  cout << required.size() * 2 << endl;

  return 0;
}
#endif
