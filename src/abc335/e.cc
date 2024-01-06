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

int rec(int node, vector<vector<int>> &g, vector<int> &depths,
        vector<bool> &visited) {
  if (visited[node])
    return depths[node];
  if (node == (int)g.size() - 1) {
    visited[node] = true;
    return depths[node] = 1;
  }
  for (auto &child : g[node]) {
    int temp = rec(child, g, depths, visited);
    if (temp)
      depths[node] = max(depths[node], temp + 1);
  }
  visited[node] = true;
  return depths[node];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<int> uv(m), vv(m);
  UnionFind uf(n);
  rep(i, m) {
    cin >> uv[i] >> vv[i];
    uv[i]--;
    vv[i]--;
    if (av[uv[i]] == av[vv[i]])
      uf.unite(vv[i], uv[i]);
  }
  rep(i, n) uf.find_root(i);
  vector<vector<int>> g(n);
  rep(i, m) {
    int u = uf.find_root(uv[i]);
    int v = uf.find_root(vv[i]);
    if (u == v)
      continue;
    if (av[u] > av[v])
      g[v].push_back(u);
    else if (av[u] < av[v])
      g[u].push_back(v);
    else
      assert(false);
  }
  rep(i, n) {
    sort(begin(g[i]), end(g[i]), [&](int a, int b) {
      return av[a] < av[b];
    });
  }
  vector<ll> depths(n, -1000000ll);
  depths[uf.find_root(0)] = 1;
  priority_queue<tuple<ll, ll, int>> que;
  que.push({-av[0], 1, uf.find_root(0)});
  while (que.size()) {
    auto [neg, cost, node] = que.top();
    que.pop();
    if (cost < depths[node])
      continue;

    for (auto neighbor : g[node]) {
      if (depths[neighbor] < depths[node] + 1) {
        depths[neighbor] = depths[node] + 1;
        que.push({-av[neighbor], depths[neighbor], neighbor});
      }
    }
  }
  cout << max(0ll, depths[uf.find_root(n - 1)]) << endl;

  return 0;
}
