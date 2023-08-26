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

void warshall_floyd(vector<vector<ll>> &d) {
  int n = d.size();
  rep(k, n) {
    rep(i, n) {
      rep(j, n) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    }
  }
}
void dig(int current, int node, vector<vector<pair<int, ll>>> &g, ll &res,
         set<int> &used) {

  for (auto [neighbor, cost] : g[node]) {
    if (used.count(neighbor) == 0) {
      used.insert(neighbor);
      res = max(res, current + cost);
      dig(current + cost, neighbor, g, res, used);
      used.erase(neighbor);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n);
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  ll res = 0;
  rep(i, n) {
    set<int> used = {i};
    dig(0, i, g, res, used);
  }
  cout << res << endl;
  return 0;
}
