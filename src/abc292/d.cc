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

class UnionFind {
public:
  vector<int> par;
  UnionFind(int n) { par = vector<int>(n, -1); }

  int find_root(int a) {
    if (par[a] < 0)
      return a;
    return par[a] = find_root(par[a]);
  }

  int is_same_group(int a, int b) { return find_root(a) == find_root(b); }

  void unite(int a, int b) {
    if (is_same_group(a, b))
      return;
    int root_a = find_root(a), root_b = find_root(b);
    if (group_size(root_a) > group_size(b)) {
      par[root_a] += par[root_b];
      par[root_b] = root_a;
    } else {
      par[root_b] += par[root_a];
      par[root_a] = root_b;
    }
  }
  int group_size(int a) { return -par[find_root(a)]; }
};

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  vector<pair<int, int>> edges;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    edges.push_back({--u, --v});
    uf.unite(u, v);
  }
  map<int, int> mp;
  for (auto [left, right] : edges) {
    mp[uf.find_root(left)]++;
  }
  rep(i, n) {
    int n_nodes = uf.group_size(i);
    // cout << i << " " << n_nodes << " " << mp[uf.find_root(i)] << endl;
    if (n_nodes != mp[uf.find_root(i)]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
#endif
