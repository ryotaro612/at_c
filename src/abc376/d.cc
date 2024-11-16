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
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
  }
  vector<ll> d(n, 1000000000000ll);
  d[0] = 0;
  queue<int> que;
  que.push(0);
  ll res = 100000000000000ll;
  while (que.size()) {
    int node = que.front();
    que.pop();
    for (auto neighbor : g[node]) {
      if (neighbor == 0) {
        res = min(res, d[node] + 1ll);
      }
      if (d[neighbor] > 1ll + d[node]) {
        d[neighbor] = d[node] + 1ll;
        que.push(neighbor);
      }
    }
  }
  if (res < 100000000000ll) {
    cout << res << endl;
  } else
    cout << -1 << endl;

  return 0;
}
