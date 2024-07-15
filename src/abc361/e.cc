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

void count_total_cost(vector<vector<pair<int, ll>>> &g, int node, int parent,
                      ll &acc) {
  for (auto [child, cost] : g[node]) {
    if (child == parent)
      continue;
    acc += cost;
    count_total_cost(g, child, node, acc);
  }
  return;
}

ll find_longest(vector<vector<pair<int, ll>>> &g, int node, int parent,
                map<pair<int, int>, ll> &cache) {
  if (cache.count({parent, node})) {
    return cache[{parent, node}];
  }
  ll res = 0;
  for (auto [child, cost] : g[node]) {
    if (child == parent)
      continue;
    res = max(res, cost + find_longest(g, child, node, cache));
  }
  cache[{parent, node}] = res;
  return res;
}

pair<ll, int> find_cost(int node, int parent,
                        vector<vector<pair<int, ll>>> &g) {
  ll res = 0;
  int res_c = node;
  for (auto [child, cost] : g[node]) {
    if (parent == child)
      continue;
    auto [sub, sub_c] = find_cost(child, node, g);
    if (sub + cost > res) {
      res = sub + cost;
      res_c = sub_c;
    }
  }
  return {res, res_c};
}
int main() {
  int n;
  cin >> n;
  vector<ll> av(n - 1), bv(n - 1), cv(n - 1);

  vector<vector<pair<int, ll>>> g(n);
  rep(i, n - 1) {
    cin >> av[i] >> bv[i] >> cv[i];
    av[i]--;
    bv[i]--;
    g[av[i]].push_back({bv[i], cv[i]});
    g[bv[i]].push_back({av[i], cv[i]});
  }
  ll total_cost = 0;
  count_total_cost(g, 0, -1, total_cost);

  map<pair<int, int>, ll> cache;

  auto [x, sub] = find_cost(0, -1, g);
  dbg(x, sub);
  auto [max_width, y] = find_cost(sub, -1, g);
  dbg(max_width, y);

  cout << total_cost * 2ll - max_width << endl;

  return 0;
}
