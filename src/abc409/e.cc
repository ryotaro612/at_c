#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> xv(n);
  rep(i, n) cin >> xv[i];

  vector<set<pair<int, ll>>> g(n);
  rep(i, n - 1) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    g[u].insert({v, w});
    g[v].insert({u, w});
  }
  queue<int> que;
  rep(node, n) {
    if (g[node].size() == 1) {
      que.push(node);
    }
  }
  ll res = 0;
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    dbg(node);
    int succ = g[node].begin()->first;
    if (xv[node]) {
      xv[succ] += xv[node];
      dbg("inc", g[node].begin()->second);
      res += g[node].begin()->second * abs(xv[node]);
      xv[node] = 0;
    }
    g[succ].erase({node, g[node].begin()->second});
    if (g[succ].size() == 1) {
      que.push(succ);
    }
  }
  cout << res << endl;

  return 0;
}
