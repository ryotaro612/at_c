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
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  int x = 0;
  rep(i, m) {
    int a, c;
    char b, d;
    cin >> a >> b >> c >> d;
    a--;
    c--;
    // cout << "Hi " << a << " " << c << endl;
    if (uf.is_same_group(a, c)) {
      x++;
    }
    uf.unite(a, c);
  }
  // cout << " dog e" << endl;
  int y = uf.count_groups() - x;
  cout << x << " " << y << endl;
  return 0;
}
#endif
