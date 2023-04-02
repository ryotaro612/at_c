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

void sub(vector<int> &x, vector<int> &y, UnionFind &uf) {
  int n = x.size();
  vector<tuple<int, int, int>> xyi(n);
  rep(i, n) { xyi[i] = {x[i], y[i], i}; }
  sort(xyi.begin(), xyi.end());
  vector<int> y_to_pos(n), pos_i(n);
  rep(i, n) {
    int y = get<1>(xyi[i]);
    y_to_pos[y] = i;
    pos_i[i] = get<2>(xyi[i]);
  }
  set<int> s;
  rep(y, n) {
    int pos = y_to_pos[y];
    int town = pos_i[pos];
    s.insert(pos);
    auto found = s.lower_bound(pos);
    if (found != s.begin()) {
      int neighbor = *prev(found);
      // cout << "town " << town << " " << pos_i[neighbor] << '\n';
      uf.unite(town, pos_i[neighbor]);
    }
  }
  s = set<int>();
  // cout << " --- " << endl;
  for (int y = n - 1; y >= 0; y--) {
    int pos = y_to_pos[y];
    int town = pos_i[pos];
    auto found = s.upper_bound(pos);
    if (found != s.end()) {
      int neighbor = *found;
      // cout << "town " << town << " " << pos_i[neighbor] << '\n';
      uf.unite(town, pos_i[neighbor]);
    }
    s.insert(pos);
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> xv(n), yv(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xv[i] = --x;
    yv[i] = --y;
  }
  UnionFind uf(n);
  sub(xv, yv, uf);
  sub(yv, xv, uf);

  rep(i, n) cout << uf.group_size(i) << endl;

  return 0;
}
#endif
