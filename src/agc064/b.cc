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

void print_res(set<int> &res) {
  cout << "Yes\n";
  int i = 0;
  for (auto e : res) {
    cout << e + 1 << " \n"[i++ == (int)res.size() - 1];
  }
}

struct Edge {
  int i, to;
  char c;
};
int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  vector<vector<Edge>> g(n);
  rep(i, m) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    --a;
    --b;
    g[a].push_back({i, b, c});
    g[b].push_back({i, a, c});
  }
  string s;
  cin >> s;
  set<int> res;
  vector<bool> ok(n, false);
  set<int> added;
  //int x;
  rep(start, n) {
    for (auto &[i, to, c] : g[start]) {
      if (s[start] == c && s[to] == c && !uf.is_same_group(start, to)) {
        res.insert(i);
        ok[start] = ok[to] = true;
        uf.unite(start, to);
        added.insert(to);
        added.insert(start);
        //x = to;
      }
    }
  }
  while (added.size()) {
    set<int> next_added;
    for (auto node : added) {
      for (auto &[i, to, c] : g[node]) {
        if (!uf.is_same_group(node, to) && s[to] == c) {
          ok[to] = true;
          res.insert(i);
          uf.unite(to, node);
          next_added.insert(to);
        }
      }
    }
    added = next_added;
  }

  for (auto e : ok) {
    if (!e) {
      cout << "No\n";
      return 0;
    }
  }

  rep(start, n) {
    for (auto &[i, to, c] : g[start]) {
      if (!uf.is_same_group(start, to)) {
        res.insert(i);
        uf.unite(start, to);
      }
    }
  }
  print_res(res);
  return 0;
}
