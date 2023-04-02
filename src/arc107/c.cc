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

template <ll N> class Mod {
public:
  Mod(ll v) : v(v) {}
  ll get() { return v; }
  Mod operator*(Mod &a) { return Mod<N>(v * a.v % N); }
  Mod operator*(ll &b) { return Mod<N>(v * b % N); }
  Mod &operator*=(const Mod &rhs) {
    v *= rhs.v;
    v %= N;
    return *this;
  }
  Mod &operator=(const ll &number) {
    v = number;
    return this;
  }
  friend ostream &operator<<(ostream &os, Mod &mod) {
    os << mod.v;
    return os;
  }

private:
  ll v;
};

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> am(n, vector<int>(n));
  rep(i, n) {
    rep(j, n) { cin >> am[i][j]; }
  }

  UnionFind uf_row(n);
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      bool ok = true;
      rep(c, n) {
        if (am[i][c] + am[j][c] > k)
          ok = false;
      }
      if (ok)
        uf_row.unite(i, j);
    }
  }
  Mod<998244353ll> res = 1ll;
  rep(i, n) {
    if (uf_row.find_root(i) == i) {
      for (ll j = 1ll; j <= uf_row.group_size(i); j++) {
        res *= j;
      }
    }
  }

  UnionFind uf_col(n);
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      bool ok = true;
      rep(r, n) {
        if (am[r][i] + am[r][j] > k)
          ok = false;
      }
      if (ok)
        uf_col.unite(i, j);
    }
  }
  rep(i, n) {
    if (uf_col.find_root(i) == i) {
      for (ll j = 1ll; j <= uf_col.group_size(i); j++) {
        res *= j;
      }
    }
  }
  cout << res << endl;
  return 0;
}
#endif
