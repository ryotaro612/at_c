#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  if (v.size() == 0) {
    os << "]";
    return os;
  }
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}

void debug_() { cout << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

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
vector<vector<int>> g;

bool rec(int node, vector<int> &path, set<int> &visit) {
  if (g[node].size()) {
    for (int neighbor : g[node]) {
      if (visit.count(neighbor) == 0) {
        path.push_back(neighbor);
        visit.insert(neighbor);
        if (rec(neighbor, path, visit)) {
          return true;
        } else {
          path.pop_back();
          visit.erase(neighbor);
        }
      } else {
	return true;
      }
    }
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  g.resize(n);
  UnionFind uf(n);
  int start;
  rep(i, n) {
    int a;
    cin >> a;
    g[i].push_back(--a);
    if (uf.is_same_group(i, a))
      start = a;
    else
      uf.unite(i, a);
  }
  vector<int> path;
  set<int> visit;
  debug(start);
  rec(start, path, visit);
  cout << path.size() << endl;
  rep(i, path.size()) { cout << path[i]+1 << " \n"[(int)path.size() - 1 == i]; }

  return 0;
}
