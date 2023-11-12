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

struct Edge {
  int a, b;
  ll w;
};

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

void traverse(int node, vector<vector<int>> &g, set<int> &found) {

  for (auto neighbor : g[node]) {
    if (found.count(neighbor) == 0) {
      found.insert(neighbor);
      traverse(neighbor, g, found);
    }
  }
}

void rec(int i, int n, vector<Edge> &edges, vector<int> &temp, ll k, ll &res) {
  // dbg(i, n);
  if ((int)temp.size() == n) {
    vector<vector<int>> g(n + 1);

    ll cand = 0;
    for (auto e : temp) {
      g[edges[e].a].push_back(edges[e].b);
      g[edges[e].b].push_back(edges[e].a);
      cand += edges[e].w;
      cand %= k;
    }
    set<int> found = {0};
    traverse(0, g, found);
    //dbg("doge", temp);
    //dbg(g, found.size());
    if ((int)found.size() == n + 1) {
      res = min(res, cand);
    }
    return;
  }
  if (i == (int)edges.size())
    return;
  temp.push_back(i);
  rec(i + 1, n, edges, temp, k, res);
  temp.pop_back();
  rec(i + 1, n, edges, temp, k, res);
}

int main() {
  ll k;
  int n, m;
  cin >> n >> m >> k;
  vector<Edge> edges;
  rep(_, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    edges.push_back({--u, --v, w});
  }
  vector<int> temp;
  ll res = k - 1ll;
  rec(0, n - 1, edges, temp, k, res);

  cout << res << endl;
  return 0;
}
