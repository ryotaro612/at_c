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

ll sub(int node, map<int, map<int, ll>> &g, vector<ll> &dp) {
  //dbg(node);
  if (dp[node] >= 0)
    return dp[node];

  vector<int> cands;
  int n  = size(g);
  for (int i = 0; i < n; i++) {
    if ((node & (1 << i)) == 0)
      cands.push_back(i);
  }
  ll res = 0;
  rep(i, cands.size()) {
    for (int j = i + 1; j < (int)cands.size(); j++) {
      res = max(res, g[cands[i]][cands[j]] +
                         sub(node | 1 << cands[i] | 1 << cands[j], g, dp));
    }
  }
  return dp[node] = res;
}
int main() {
  int n;
  cin >> n;
  map<int, map<int, ll>> g;
  rep(i, n - 1) {
    for (int j = i + 1; j < n; j++) {
      cin >> g[i][j];
      g[j][i] = g[i][j];
    }
  }
  vector<ll> dp(1 << n, -1ll);
  cout << sub(0, g, dp) << endl;
  return 0;
}
