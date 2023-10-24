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
vector<ll> dijkstra(int start, vector<vector<ll>> dm) {
  const ll inf = 100000000000000ll;
  int n = dm.size();
  vector<ll> dp(n, inf);
  dp[start] = 0;
  multiset<pair<ll, int>> que = {{0, start}};
  while (que.size()) {
    auto [dist, node] = *begin(que);
    que.erase(begin(que));
    if (dp[node] < dist)
      continue;

    rep(i, n) {
      ll cand = dp[node] + dm[node][i];
      if (cand < dp[i]) {
        dp[i] = cand;
        que.insert({dp[i], i});
      }
    }
  }
  return dp;
}
int main() {
  int n;
  ll a, b, c;
  cin >> n >> a >> b >> c;
  vector<vector<ll>> dm(n, vector<ll>(n));
  rep(i, n) { rep(j, n) cin >> dm[i][j]; }
  vector<vector<ll>> train(n, vector<ll>(n)), car(n, vector<ll>(n));
  rep(i, n) {
    rep(j, n) {
      train[i][j] = dm[i][j] * b + c;
      car[i][j] = dm[i][j] * a;
    }
  }
  auto car_dist = dijkstra(0, car);
  auto train_dist = dijkstra(n - 1, train);
  ll res = car_dist[n - 1];
  rep(i, n) { res = min(res, car_dist[i] + train_dist[i]); }
  cout << res << endl;

  return 0;
}
