#include <bits/stdc++.h>
#include <iomanip>
#include <limits>
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
  int node;
  ld beauty, cost;
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n);
  rep(_, m) {
    int u, v;
    ld b, c;
    cin >> u >> v >> b >> c;
    g[u - 1].push_back({v - 1, b, c});
  }
  ld lb = 0, ub = 10000000000ll;

  while (ub - lb > 0.0000000001) {
    ld mid = (lb + ub) / (ld)2.0;
    const ld mini = -1000000000ll;
    vector<ld> dp(n, mini);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
      ld temp = mini;
      for (auto edge : g[i]) {
        if (dp[edge.node] > mini) {
          temp = max(temp, edge.beauty - mid * edge.cost + dp[edge.node]);
        }
      }
      dp[i] = temp;
    }

    if (dp[0] > 0)
      lb = mid;
    else
      ub = mid;

    // rep(i, n)
    //   cout << fixed << setprecision(12) << dp[i]<< " ";
    // cout << endl;
  }
  cout << fixed << setprecision(12) << ub << endl;

  return 0;
}
