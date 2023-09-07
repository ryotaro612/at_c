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
  int to, cap, rev;
  Edge(int t, int c, size_t r) : to(t), cap(c), rev((int)r){};
};
int ford_fulkerson(int node, int dest, int res, vector<bool> &used,
                   vector<vector<Edge>> &g) {
  if (node == dest)
    return res;
  used[node] = true;
  for (auto &[to, cap, rev] : g[node]) {
    if (!used[to] && cap) {
      int d = ford_fulkerson(to, dest, min(cap, res), used, g);
      if (d) {
        cap -= d;
        g[to][rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}
int main() {
  int n, g, e;
  cin >> n >> g >> e;
  if (g == 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<vector<Edge>> graph(n + 1);
  rep(i, g) {
    int p;
    cin >> p;
    graph[p].push_back({n, 1, graph[n].size()});
    graph[n].push_back({p, 0, graph[p].size() - 1});
  }

  rep(i, e) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back({b, 1, graph[b].size()});
    graph[b].push_back({a, 0, graph[a].size() - 1});

    graph[b].push_back({a, 1, graph[a].size()});
    graph[a].push_back({b, 0, graph[b].size() - 1});
  }

  int res = 0;
  while (true) {
    vector<bool> used(n + 1, false);
    int delta = ford_fulkerson(0, n, 1000000, used, graph);

    if (delta)
      res += delta;
    else {
      cout << res << endl;
      return 0;
    }
  }
}
