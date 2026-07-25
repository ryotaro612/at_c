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

void visit(int node, int cost, vector<vector<pair<int, int>>> &g,
           vector<set<int>> &dist) {

  for (auto [succ, w] : g[node]) {
    if (dist[succ].contains(w ^ cost))
      continue;
    dist[succ].insert(w ^ cost);
    visit(succ, w ^ cost, g, dist);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  rep(i, m) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    g[a].push_back({b, w});
  }
  vector<set<int>> dist(n);
  dist[0].insert(0);
  visit(0, 0, g, dist);
  if (dist[n - 1].size() == 0) {
    cout << -1 << endl;
  } else
    cout << *dist[n - 1].begin() << endl;
  return 0;
}
