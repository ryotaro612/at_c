#include <bits/stdc++.h>
#include <queue>
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
int main() {
  int n;
  cin >> n;
  vector<vector<pair<ll, int>>> g(n);
  rep(i, n - 1) {
    ll a, b, x;
    cin >> a >> b >> x;
    g[i].push_back({a, i + 1});
    g[i].push_back({b, x-1});
  }
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      que;
  const ll inf = 1e15;
  vector<ll> d(n, inf);
  d[0] = 0;
  que.push({d[0], 0});
  while (que.size()) {
    dbg(d);
    auto [cost, node] = que.top();
    que.pop();
    dbg(node);
    if (d[node] < cost)
      continue;
    for (auto [n_cost, neighbor] : g[node]) {
      dbg(neighbor);
      if (d[neighbor] > d[node] + n_cost) {
        d[neighbor] = d[node] + n_cost;
        que.push({d[neighbor], neighbor});
      }
    }
  }
  dbg(d);
  cout << d[n - 1] << endl;
  return 0;
}
