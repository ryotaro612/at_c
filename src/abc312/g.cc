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
void count_children(vector<vector<int>> &g, vector<int> &n_nodes, int parent,
                    int node) {
  for (auto child : g[node]) {
    if (child != parent) {
      count_children(g, n_nodes, node, child);
      n_nodes[node] += n_nodes[child];
    }
  }
}
void reduce(vector<vector<int>> &g, vector<int> &n_nodes, int parent, int node,
            ll &res) {
  int n = g.size();

  ll p_ptn = (ll)(n - n_nodes[node]) * (ll)(n_nodes[node] - 1);
  res -= p_ptn;
  ll child_ptn = 0;
  for (int child : g[node]) {
    if (child != parent) {
      ll n_child = n_nodes[child];
      child_ptn += n_child * (ll)(n_nodes[node] - n_child - 1);
      reduce(g, n_nodes, node, child, res);
    }
  }
  child_ptn /= 2ll;
  dbg(node, p_ptn, child_ptn);
  res -= child_ptn;
}
int main() {
  ll n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  vector<int> n_nodes(n, 1);
  count_children(g, n_nodes, -1, 0);
  ll res = n * (n - 1ll) * (n - 2ll) / 6ll;
  reduce(g, n_nodes, -1, 0, res);

  cout << res << endl;
  return 0;
}
