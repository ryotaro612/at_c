#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
  /**
   * グループの総数を返す。
   */
  int count_groups() {
    unordered_set<int> groups;
    rep(i, par.size()) { groups.insert(find_root(i)); }
    return groups.size();
  }
};

#ifdef ONLINE_JUDGE
int main() {
  int n, m, k, q;
  cin >> n >> m;
  vector<int> uv(m), vv(m);
  UnionFind uf(n);
  rep(i, m) {
    cin >> uv[i] >> vv[i];
    uf.unite(--uv[i], --vv[i]);
  }
  map<pair<int, int>, bool> ngs;
  cin >> k;
  vector<int> xv(k), yv(k);
  rep(i, k) {
    cin >> xv[i] >> yv[i];
    int left = uf.find_root(--xv[i]), right = uf.find_root(--yv[i]);
    if (left > right)
      swap(left, right);
    ngs[{left, right}] = true;
  }
  cin >> q;
  vector<int> pv(q), qv(q);
  rep(i, q) {
    cin >> pv[i] >> qv[i];
    int left = uf.find_root(--pv[i]), right = uf.find_root(--qv[i]);
    if (left > right)
      swap(left, right);
    if (ngs[{left, right}]) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }

  return 0;
}
#endif
