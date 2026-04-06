#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
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
  int n;
  cin >> n;

  vector<vector<int>> edges(n, vector<int>(n));
  set<tuple<int, int, int>> s;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int a;
      cin >> a;
      s.insert({a, i, j});
      edges[i][j] = edges[j][i] = a;
    }
  }

  UnionFind uf(n);
  vector<set<int>> g(n);
  rep(i, n) g[i].insert(i);

  while (s.size()) {
    auto t = s.begin();
    int length = get<0>(*t);
    int a = get<1>(*t);
    int b = get<2>(*t);
    s.erase(t);
    if (uf.is_same_group(a, b))
      continue;

    dbg(length, a, b);
    set<int> group_a = g[uf.find_root(a)];
    set<int> group_b = g[uf.find_root(b)];
    for (int ae : group_a) {
      for (int be : group_b) {
        dbg(ae, be, edges[ae][be]);
        if (edges[ae][be] != edges[ae][a] + edges[b][be] + length) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
    set<int> new_group;
    for (int ae : group_a) {
      new_group.insert(ae);
    }
    for (int be : group_b) {
      new_group.insert(be);
    }
    dbg(group_a, group_b);
    uf.unite(a, b);
    g[uf.find_root(a)] = new_group;
  }
  cout << "Yes" << endl;

  return 0;
}
