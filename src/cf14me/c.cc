#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <queue>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  if (v.size() == 0) {
    os << "]";
    return os;
  }
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}

void debug_() { cout << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &g) {
  int n = g.size();
  vector<int> d(n, 1 << 28);
  d[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      que;
  que.push({0, start});
  while (que.size()) {
    auto [dist, node] = que.top();
    que.pop();
    if (d[node] < dist)
      continue;
    for (auto [edge, ne] : g[node]) {
      if (d[ne] > edge + d[node]) {
        d[ne] = edge + d[node];
        que.push({d[ne], ne});
      }
    }
  }
  return d;
}

// #ifdef ONLINE_JUDGE
int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<pair<int, int>>> g(n);
  --s, --t;
  rep(i, m) {
    int x, y, d;
    cin >> x >> y >> d;
    g[--x].push_back({d, --y});
    g[y].push_back({d, x});
  }
  vector<int> start = dijkstra(s, g), goal = dijkstra(t, g);
  rep(i, n) {
    if (start[i] < (1 << 28) && start[i] == goal[i]) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
// #endif
