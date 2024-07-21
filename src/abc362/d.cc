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
const ll inf = 10000000000000000ll;
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }

  vector<vector<pair<ll, int>>> g(n);
  rep(i, m) {
    int u, v;
    ll b;
    cin >> u >> v >> b;
    u--;
    v--;
    g[u].push_back({b, v});
    g[v].push_back({b, u});
  }

  vector<ll> dist(2 * n, inf);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      que;
  dist[0] = 0;
  que.push({dist[0], 0});
  while (que.size()) {
    auto [d, node] = que.top();
    que.pop();
    if (dist[node] < d)
      continue;

    if (node < n) {
      if (dist[node] + av[node] < dist[node + n]) {
        dist[node + n] = dist[node] + av[node];
        dbg(node + n, dist[node + n]);
        que.push({dist[node + n], node + n});
      }
      continue;
    }

    for (auto [next_d, neighbor] : g[node - n]) {
      if (dist[node] + next_d < dist[neighbor]) {
        dist[neighbor] = dist[node] + next_d;
        que.push({dist[neighbor], neighbor});
      }
    }
  }
  dbg(dist);
  rep(i, n - 1) { cout << dist[n + 1 + i] << " \n"[i == n - 2]; }

  return 0;
}
