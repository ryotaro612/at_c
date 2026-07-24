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

void count(int node, int parent, int dist, vector<pair<int, int>> &path,
           vector<vector<int>> &g) {

  for (auto succ : g[node]) {
    if (succ == parent)
      continue;
    path.push_back({succ, dist + 1});
    count(succ, node, dist + 1, path, g);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dbg(g);

  set<pair<int, int>> edges;
  rep(node, n) {
    vector<pair<int, int>> temp;
    temp.push_back({node, 0});
    count(node, -1, 0, temp, g);
    for (auto [x, dist] : temp) {
      if (dist >= 3 && dist % 2 == 1) {
        edges.insert({min(node, x), max(node, x)});
      }
    }
  }
  bool turn = true;
  if (edges.size() % 2) {
    cout << "First" << endl << flush;
  } else {
    cout << "Second" << endl << flush;
    turn = false;
  }
  while (true) {
    if (turn) {
      auto edge = *edges.begin();
      cout << edge.first + 1 << " " << edge.second + 1 << endl << flush;
      dbg("ho");
      edges.erase(edge);
      dbg("hi");
    } else {
      dbg("wait");
      int a, b;
      cin >> a >> b;
      dbg(a, b);
      if (a == -1 && b == -1) {
        return 0;
      }
      edges.erase({min(a - 1, b - 1), max(a - 1, b - 1)});
    }
    turn = !turn;
  }
  return 0;
}
