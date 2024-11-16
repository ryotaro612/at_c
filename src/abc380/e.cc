#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__       \
       << " = ";                                                               \
  debug_(__VA_ARGS__);
#else
#define dbg(...)
#endif
template <typename Os, typename... Ts>
Os &operator<<(Os &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Os, typename T>
typename enable_if<is_same<Os, ostream>::value, Os &>::type
operator<<(Os &os, const T &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

void debug_() { cerr << "\e[39m" << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cerr << H << " ";
  debug_(T...);
}
class UnionFind {
public:
  vector<int> par;
  /**
   *  グループの総数
   */
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

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  vector<int> color_count(n, 0);
  vector<int> left(n), right(n);
  vector<int> color(n);
  rep(i, n) {
    color[i] = left[i] = right[i] = i;
    color_count[i] = 1;
  }

  rep(_, q) {
    dbg("hi");
    int type;
    cin >> type;
    int c;
    if (type == 1) {
      int x;
      cin >> x >> c;
      x--;
      c--;
      dbg(x, c);
      set<int> bound;
      int root = uf.find_root(x);
      bound.insert(left[root]);
      bound.insert(right[root]);
      color_count[color[root]] -= uf.group_size(root);

      color[root] = c;
      color_count[c]+= uf.group_size(root);
      if (left[root] && c == color[uf.find_root(left[root] - 1)]) {
        int a = uf.find_root(left[root] - 1);
        bound.insert(left[a]);
        bound.insert(right[a]);
        uf.unite(x, a);
      }
      if (right[root] < n - 1 && c == color[uf.find_root(right[root] + 1)]) {
        int a = uf.find_root(right[root] + 1);
        bound.insert(left[a]);
        bound.insert(right[a]);
        uf.unite(x, a);
      }
      root = uf.find_root(x);;
      left[root] = *begin(bound);
      right[root] = *prev(end(bound));
    } else {
      cin >> c;
      dbg("type2", c);
      c--;
      int res = color_count[c];
      cout << res << endl;
    }
  }
  return 0;
}
