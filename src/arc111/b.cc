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
  /**
   * グループの総数を返す。
   */
  int count_groups() {
    unordered_set<int> groups;
    rep(i, par.size()) { groups.insert(find_root(i)); }
    return groups.size();
  }
};

void remap(vector<int> &av, vector<int> &bv) {
  set<int> st;
  for (auto a : av)
    st.insert(a);
  for (auto b : bv)
    st.insert(b);
  map<int, int> mp;
  int i = 0;
  for (auto node : st)
    mp[node] = i++;
  // cout << " hi " << endl;
  rep(i, av.size()) av[i] = mp[av[i]];
  rep(i, bv.size()) bv[i] = mp[bv[i]];
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n), bv(n);

  rep(i, n) { cin >> av[i] >> bv[i]; }

  remap(av, bv);
  int m = 0;
  rep(i, av.size()) m = max(m, av[i] + 1);
  rep(i, bv.size()) m = max(m, bv[i] + 1);
  UnionFind uf(m);
  rep(i, n) { uf.unite(av[i], bv[i]); }

  map<int, int> edge_per_group;
  set<int> group;

  rep(i, n) {
    int root = uf.find_root(av[i]);
    edge_per_group[root]++;
    group.insert(root);
  }

  int res = 0;
  for (auto root : group) {
    int n_edge = edge_per_group[root];
    int n_node = uf.group_size(root);
    if (n_edge < n_node)
      res += n_node - 1;
    else
      res += n_node;
  }
  cout << res << endl;
  return 0;
}
#endif
